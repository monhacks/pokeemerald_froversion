#include "global.h"
#include "item_use.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "berry.h"
#include "berry_powder.h"
#include "bike.h"
#include "coins.h"
#include "data.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "item.h"
#include "item_menu.h"
#include "item_use.h"
#include "mail.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "follow_me.h"
#include "constants/event_bg.h"
#include "constants/event_objects.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "outfit_menu.h"

static void SetUpItemUseCallback(u8 taskId);
static void FieldCB_UseItemOnField(void);
static void Task_CallItemUseOnFieldCallback(u8 taskId);
static void Task_UseItemfinder(u8 taskId);
static void Task_CloseItemfinderMessage(u8 taskId);
static void Task_HiddenItemNearby(u8 taskId);
static void Task_StandingOnHiddenItem(u8 taskId);
static bool8 ItemfinderCheckForHiddenItems(const struct MapEvents *, u8);
static u8 GetDirectionToHiddenItem(s16 distanceX, s16 distanceY);
static void PlayerFaceHiddenItem(u8 a);
static void CheckForHiddenItemsInMapConnection(u8 taskId);
static void Task_OpenRegisteredPokeblockCase(u8 taskId);
static void ItemUseOnFieldCB_Bike(u8 taskId);
static void ItemUseOnFieldCB_Rod(u8);
static void ItemUseOnFieldCB_Itemfinder(u8);
static void ItemUseOnFieldCB_Berry(u8 taskId);
static void ItemUseOnFieldCB_WailmerPailBerry(u8 taskId);
static void ItemUseOnFieldCB_WailmerPailSudowoodo(u8 taskId);
static bool8 TryToWaterSudowoodo(void);
static void BootUpSoundTMHM(u8 taskId);
static void Task_ShowTMHMContainedMessage(u8 taskId);
static void UseTMHMYesNo(u8 taskId);
static void UseTMHM(u8 taskId);
static void Task_StartUseRepel(u8 taskId);
static void Task_UseRepel(u8 taskId);
static void Task_CloseCantUseKeyItemMessage(u8 taskId);
static void SetDistanceOfClosestHiddenItem(u8 taskId, s16 x, s16 y);
static void CB2_OpenPokeblockFromBag(void);
static void CB2_OpenOutfitBoxFromBag(void);
static void Task_OpenRegisteredOutfitBox(u8 taskId);

// EWRAM variables
EWRAM_DATA static void(*sItemUseOnFieldCB)(u8 taskId) = NULL;

// Below is set TRUE by UseRegisteredKeyItemOnField
#define tUsingRegisteredKeyItem  data[3]

// UB here if an item with type ITEM_USE_MAIL or ITEM_USE_BAG_MENU uses SetUpItemUseCallback
// Never occurs in vanilla, but can occur with improperly created items
static const MainCallback sItemUseCallbacks[] =
{
    [ITEM_USE_PARTY_MENU - 1]  = CB2_ShowPartyMenuForItemUse,
    [ITEM_USE_FIELD - 1]       = CB2_ReturnToField,
    [ITEM_USE_PBLOCK_CASE - 1] = NULL,
};

static const u8 sClockwiseDirections[] = {DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST};

static const struct YesNoFuncTable sUseTMHMYesNoFuncTable =
{
    .yesFunc = UseTMHM,
    .noFunc = BagMenu_InitListsMenu,
};

#define tEnigmaBerryType data[4]
static void SetUpItemUseCallback(u8 taskId)
{
    u8 type;
    if (gSpecialVar_ItemId == ITEM_ENIGMA_BERRY)
        type = gTasks[taskId].tEnigmaBerryType - 1;
    else
        type = ItemId_GetType(gSpecialVar_ItemId) - 1;
    if (!InBattlePyramid())
    {
        gBagMenu->exitCallback = sItemUseCallbacks[type];
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        gPyramidBagResources->callback2 = sItemUseCallbacks[type];
        CloseBattlePyramidBagAndSetCallback(taskId);
    }
}

static void SetUpItemUseOnFieldCallback(u8 taskId)
{
    if (gTasks[taskId].tUsingRegisteredKeyItem != TRUE)
    {
        gFieldCallback = FieldCB_UseItemOnField;
        SetUpItemUseCallback(taskId);
    }
    else
        sItemUseOnFieldCB(taskId);
}

static void FieldCB_UseItemOnField(void)
{
    FadeInFromBlack();
    CreateTask(Task_CallItemUseOnFieldCallback, 8);
}

static void Task_CallItemUseOnFieldCallback(u8 taskId)
{
    if (IsWeatherNotFadingIn() == 1)
        sItemUseOnFieldCB(taskId);
}

static void DisplayCannotUseItemMessage(u8 taskId, bool8 isUsingRegisteredKeyItemOnField, const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    if (!isUsingRegisteredKeyItemOnField)
    {
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, gText_DadsAdvice, Task_CloseBattlePyramidBagMessage);
    }
    else
        DisplayItemMessageOnField(taskId, gStringVar4, Task_CloseCantUseKeyItemMessage);
}

static void DisplayDadsAdviceCannotUseItemMessage(u8 taskId, bool8 isUsingRegisteredKeyItemOnField)
{
    DisplayCannotUseItemMessage(taskId, isUsingRegisteredKeyItemOnField, gText_DadsAdvice);
}

static void DisplayCannotDismountBikeMessage(u8 taskId, bool8 isUsingRegisteredKeyItemOnField)
{
    DisplayCannotUseItemMessage(taskId, isUsingRegisteredKeyItemOnField, gText_CantDismountBike);
}

static void Task_CloseCantUseKeyItemMessage(u8 taskId)
{
    ClearDialogWindowAndFrame(0, 1);
    DestroyTask(taskId);
    ScriptUnfreezeObjectEvents();
    ScriptContext2_Disable();
}

u8 CheckIfItemIsTMHMOrEvolutionStone(u16 itemId)
{
    if (ItemId_GetFieldFunc(itemId) == ItemUseOutOfBattle_TMHM)
        return 1;
    else if (ItemId_GetFieldFunc(itemId) == ItemUseOutOfBattle_EvolutionStone)
        return 2;
    else
        return 0;
}

// Mail in the bag menu can't have a message but it can be checked (view the mail background, no message)
static void CB2_CheckMail(void)
{
    struct MailStruct mail;
    mail.itemId = gSpecialVar_ItemId;
    ReadMail(&mail, CB2_ReturnToBagMenuPocket, 0);
}

void ItemUseOutOfBattle_Mail(u8 taskId)
{
    gBagMenu->exitCallback = CB2_CheckMail;
    Task_FadeAndCloseBagMenu(taskId);
}

void ItemUseOutOfBattle_ExpShare(u8 taskId)
{
	if (!gSaveBlock2Ptr->expShare)
	{
		PlaySE(SE_EXP_MAX);
		if (!gTasks[taskId].data[2]) // to account for pressing select in the overworld
			DisplayItemMessageOnField(taskId, gOtherText_ExpShareOn, Task_CloseCantUseKeyItemMessage);
		else
			DisplayItemMessage(taskId, 1, gOtherText_ExpShareOn, BagMenu_InitListsMenu);
	}
	else
	{
		PlaySE(SE_PC_OFF);
		if (!gTasks[taskId].data[2]) // to account for pressing select in the overworld
			DisplayItemMessageOnField(taskId, gOtherText_ExpShareOff, Task_CloseCantUseKeyItemMessage);
		else
			DisplayItemMessage(taskId, 1, gOtherText_ExpShareOff, BagMenu_InitListsMenu);
	}
	gSaveBlock2Ptr->expShare = !gSaveBlock2Ptr->expShare;
}

void ItemUseOutOfBattle_Bike(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    s16 coordsY;
    s16 coordsX;
    u8 behavior;
    PlayerGetDestCoords(&coordsX, &coordsY);
    behavior = MapGridGetMetatileBehaviorAt(coordsX, coordsY);
    if (FlagGet(FLAG_SYS_CYCLING_ROAD) == TRUE || MetatileBehavior_IsVerticalRail(behavior) == TRUE || MetatileBehavior_IsHorizontalRail(behavior) == TRUE || MetatileBehavior_IsIsolatedVerticalRail(behavior) == TRUE || MetatileBehavior_IsIsolatedHorizontalRail(behavior) == TRUE)
        DisplayCannotDismountBikeMessage(taskId, tUsingRegisteredKeyItem);
    else
    {
        if (Overworld_IsBikingAllowed() == TRUE && IsBikingDisallowedByPlayer() == 0 && FollowerCanBike())
        {
            sItemUseOnFieldCB = ItemUseOnFieldCB_Bike;
            SetUpItemUseOnFieldCallback(taskId);
        }
        else
            DisplayDadsAdviceCannotUseItemMessage(taskId, tUsingRegisteredKeyItem);
    }
}

static void ItemUseOnFieldCB_Bike(u8 taskId)
{
    gUnusedBikeCameraAheadPanback = FALSE;

    gSaveBlock2Ptr->playerBike = MACH_BIKE;
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_BIKE)
    {
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
        Overworld_ClearSavedMusic();
        Overworld_PlaySpecialMapMusic();
    }
    else
    {
        gSaveBlock2Ptr->playerBike = ItemId_GetSecondaryId(gSpecialVar_ItemId);
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_BIKE);
        Overworld_SetSavedMusic(MUS_CYCLING);
        Overworld_ChangeMusicTo(MUS_CYCLING);
    }
    ScriptUnfreezeObjectEvents();
    ScriptContext2_Disable();
    DestroyTask(taskId);
}

static bool32 CanFish(void)
{
    s16 x, y;
    u16 tileBehavior;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);

    if (MetatileBehavior_IsWaterfall(tileBehavior))
        return FALSE;

    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_UNDERWATER))
        return FALSE;

    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        if (IsPlayerFacingSurfableFishableWater())
            return TRUE;
    }
    else
    {
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior) && !MapGridIsImpassableAt(x, y))
            return TRUE;
        if (MetatileBehavior_8089510(tileBehavior) == TRUE)
            return TRUE;
    }

    return FALSE;
}

void ItemUseOutOfBattle_Rod(u8 taskId)
{
    if (CanFish() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_Rod;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
}

static void ItemUseOnFieldCB_Rod(u8 taskId)
{
    StartFishing(ItemId_GetSecondaryId(gSpecialVar_ItemId));
    DestroyTask(taskId);
}

void ItemUseOutOfBattle_Itemfinder(u8 var)
{
    IncrementGameStat(GAME_STAT_USED_ITEMFINDER);
    sItemUseOnFieldCB = ItemUseOnFieldCB_Itemfinder;
    SetUpItemUseOnFieldCallback(var);
}

static void ItemUseOnFieldCB_Itemfinder(u8 taskId)
{
    if (ItemfinderCheckForHiddenItems(gMapHeader.events, taskId) == TRUE)
        gTasks[taskId].func = Task_UseItemfinder;
    else
        DisplayItemMessageOnField(taskId, gText_ItemFinderNothing, Task_CloseItemfinderMessage);
}

// Define itemfinder task data
#define tItemDistanceX    data[0]
#define tItemDistanceY    data[1]
#define tItemFound        data[2]
#define tCounter          data[3] // Used to count delay between beeps and rotations during player spin
#define tItemfinderBeeps  data[4]
#define tFacingDir        data[5]

static void Task_UseItemfinder(u8 taskId)
{
    u8 playerDir;
    u8 playerDirToItem;
    u8 i;
    s16* data = gTasks[taskId].data;
    if (tCounter == 0)
    {
        if (tItemfinderBeeps == 4)
        {
            playerDirToItem = GetDirectionToHiddenItem(tItemDistanceX, tItemDistanceY);
            if (playerDirToItem != DIR_NONE)
            {
                PlayerFaceHiddenItem(sClockwiseDirections[playerDirToItem - 1]);
                gTasks[taskId].func = Task_HiddenItemNearby;
            }
            else
            {
                // Player is standing on hidden item
                playerDir = GetPlayerFacingDirection();
                for (i = 0; i < ARRAY_COUNT(sClockwiseDirections); i++)
                {
                    if (playerDir == sClockwiseDirections[i])
                        tFacingDir = (i + 1) & 3;
                }
                gTasks[taskId].func = Task_StandingOnHiddenItem;
                tCounter = 0;
                tItemFound = 0;
            }
            return;
        }
        PlaySE(SE_ITEMFINDER);
        tItemfinderBeeps++;
    }
    tCounter = (tCounter + 1) & 0x1F;
}

static void Task_CloseItemfinderMessage(u8 taskId)
{
    ClearDialogWindowAndFrame(0, 1);
    ScriptUnfreezeObjectEvents();
    ScriptContext2_Disable();
    DestroyTask(taskId);
}

static bool8 ItemfinderCheckForHiddenItems(const struct MapEvents *events, u8 taskId)
{
    int itemX, itemY;
    s16 playerX, playerY, i, distanceX, distanceY;
    PlayerGetDestCoords(&playerX, &playerY);
    gTasks[taskId].tItemFound = FALSE;

    for (i = 0; i < events->bgEventCount; i++)
    {
        // Check if there are any hidden items on the current map that haven't been picked up
        if (events->bgEvents[i].kind == BG_EVENT_HIDDEN_ITEM && !FlagGet(events->bgEvents[i].bgUnion.hiddenItem.hiddenItemId + FLAG_HIDDEN_ITEMS_START))
        {
            itemX = (u16)events->bgEvents[i].x + 7;
            distanceX = itemX - playerX;
            itemY = (u16)events->bgEvents[i].y + 7;
            distanceY = itemY - playerY;

            if ((u16)(distanceX + 7) < 15 && (distanceY >= -5) && (distanceY < 6))
                SetDistanceOfClosestHiddenItem(taskId, distanceX, distanceY);
        }
    }

    CheckForHiddenItemsInMapConnection(taskId);
    if (gTasks[taskId].tItemFound == TRUE)
        return TRUE;
    else
        return FALSE;
}

static bool8 IsHiddenItemPresentAtCoords(const struct MapEvents *events, s16 x, s16 y)
{
    u8 bgEventCount = events->bgEventCount;
    struct BgEvent *bgEvent = events->bgEvents;
    int i;

    for (i = 0; i < bgEventCount; i++)
    {
        if (bgEvent[i].kind == BG_EVENT_HIDDEN_ITEM && x == (u16)bgEvent[i].x && y == (u16)bgEvent[i].y) // hidden item and coordinates matches x and y passed?
        {
            if (!FlagGet(bgEvent[i].bgUnion.hiddenItem.hiddenItemId + FLAG_HIDDEN_ITEMS_START))
                return TRUE;
            else
                return FALSE;
        }
    }
    return FALSE;
}

static bool8 IsHiddenItemPresentInConnection(struct MapConnection *connection, int x, int y)
{

    u16 localX, localY;
    u32 localOffset;
    s32 localLength;

    struct MapHeader const *const mapHeader = GetMapHeaderFromConnection(connection);

    switch (connection->direction)
    {
    // same weird temp variable behavior seen in IsHiddenItemPresentAtCoords
    case 2:
        localOffset = connection->offset + 7;
        localX = x - localOffset;
        localLength = mapHeader->mapLayout->height - 7;
        localY = localLength + y; // additions are reversed for some reason
        break;
    case 1:
        localOffset = connection->offset + 7;
        localX = x - localOffset;
        localLength = gMapHeader.mapLayout->height + 7;
        localY = y - localLength;
        break;
    case 3:
        localLength = mapHeader->mapLayout->width - 7;
        localX = localLength + x; // additions are reversed for some reason
        localOffset = connection->offset + 7;
        localY = y - localOffset;
        break;
    case 4:
        localLength = gMapHeader.mapLayout->width + 7;
        localX = x - localLength;
        localOffset = connection->offset + 7;
        localY = y - localOffset;
        break;
    default:
        return FALSE;
    }
    return IsHiddenItemPresentAtCoords(mapHeader->events, localX, localY);
}

static void CheckForHiddenItemsInMapConnection(u8 taskId)
{
    s16 playerX, playerY;
    s16 x, y;
    s16 width = gMapHeader.mapLayout->width + 7;
    s16 height = gMapHeader.mapLayout->height + 7;

    s16 var1 = 7;
    s16 var2 = 7;

    PlayerGetDestCoords(&playerX, &playerY);

    for (x = playerX - 7; x <= playerX + 7; x++)
    {
        for (y = playerY - 5; y <= playerY + 5; y++)
        {
            if (var1 > x
             || x >= width
             || var2 > y
             || y >= height)
            {
                struct MapConnection *conn = GetConnectionAtCoords(x, y);
                if (conn && IsHiddenItemPresentInConnection(conn, x, y) == TRUE)
                    SetDistanceOfClosestHiddenItem(taskId, x - playerX, y - playerY);
            }
        }
    }
}

static void SetDistanceOfClosestHiddenItem(u8 taskId, s16 itemDistanceX, s16 itemDistanceY)
{
    s16 *data = gTasks[taskId].data;
    s16 oldItemAbsX, oldItemAbsY, newItemAbsX, newItemAbsY;

    if (tItemFound == FALSE)
    {
        // No other items found yet, set this one
        tItemDistanceX = itemDistanceX;
        tItemDistanceY = itemDistanceY;
        tItemFound = TRUE;
    }
    else
    {
        // Other items have been found, check if this one is closer

        // Get absolute x distance of the already-found item
        if (tItemDistanceX < 0)
            oldItemAbsX = tItemDistanceX * -1; // WEST
        else
            oldItemAbsX = tItemDistanceX;      // EAST

        // Get absolute y distance of the already-found item
        if (tItemDistanceY < 0)
            oldItemAbsY = tItemDistanceY * -1; // NORTH
        else
            oldItemAbsY = tItemDistanceY;      // SOUTH

        // Get absolute x distance of the newly-found item
        if (itemDistanceX < 0)
            newItemAbsX = itemDistanceX * -1;
        else
            newItemAbsX = itemDistanceX;

        // Get absolute y distance of the newly-found item
        if (itemDistanceY < 0)
            newItemAbsY = itemDistanceY * -1;
        else
            newItemAbsY = itemDistanceY;


        if (oldItemAbsX + oldItemAbsY > newItemAbsX + newItemAbsY)
        {
            // New item is closer
            tItemDistanceX = itemDistanceX;
            tItemDistanceY = itemDistanceY;
        }
        else
        {
            if (oldItemAbsX + oldItemAbsY == newItemAbsX + newItemAbsY
            && (oldItemAbsY > newItemAbsY || (oldItemAbsY == newItemAbsY && tItemDistanceY < itemDistanceY)))
            {
                // If items are equal distance, use whichever is closer on the Y axis or further south
                tItemDistanceX = itemDistanceX;
                tItemDistanceY = itemDistanceY;
            }
        }
    }
}

static u8 GetDirectionToHiddenItem(s16 itemDistanceX, s16 itemDistanceY)
{
    s16 absX, absY;

    if (itemDistanceX == 0 && itemDistanceY == 0)
        return DIR_NONE; // player is standing on the item.

    // Get absolute X distance.
    if (itemDistanceX < 0)
        absX = itemDistanceX * -1;
    else
        absX = itemDistanceX;

    // Get absolute Y distance.
    if (itemDistanceY < 0)
        absY = itemDistanceY * -1;
    else
        absY = itemDistanceY;

    if (absX > absY)
    {
        if (itemDistanceX < 0)
            return DIR_EAST;
        else
            return DIR_NORTH;
    }
    else
    {
        if (absX < absY)
        {
            if (itemDistanceY < 0)
                return DIR_SOUTH;
            else
                return DIR_WEST;
        }
        if (absX == absY)
        {
            if (itemDistanceY < 0)
                return DIR_SOUTH;
            else
                return DIR_WEST;
        }
        return DIR_NONE; // Unreachable
    }
}

static void PlayerFaceHiddenItem(u8 direction)
{
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]);
    ObjectEventClearHeldMovement(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]);
    UnfreezeObjectEvent(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]);
    PlayerTurnInPlace(direction);
}

static void Task_HiddenItemNearby(u8 taskId)
{
    if (ObjectEventCheckHeldMovementStatus(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]) == TRUE)
        DisplayItemMessageOnField(taskId, gText_ItemFinderNearby, Task_CloseItemfinderMessage);
}

static void Task_StandingOnHiddenItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (ObjectEventCheckHeldMovementStatus(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]) == TRUE
    || tItemFound == FALSE)
    {
        // Spin player around on item
        PlayerFaceHiddenItem(sClockwiseDirections[tFacingDir]);
        tItemFound = TRUE;
        tFacingDir = (tFacingDir + 1) & 3;
        tCounter++;

        if (tCounter == 4)
            DisplayItemMessageOnField(taskId, gText_ItemFinderOnTop, Task_CloseItemfinderMessage);
    }
}

// Undefine itemfinder task data
#undef tItemDistanceX
#undef tItemDistanceY
#undef tItemFound
#undef tCounter
#undef tItemfinderBeeps
#undef tFacingDir

void ItemUseOutOfBattle_PokeblockCase(u8 taskId)
{
    if (MenuHelpers_LinkSomething() == TRUE) // link func
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
    else if (gTasks[taskId].tUsingRegisteredKeyItem != TRUE)
    {
        gBagMenu->exitCallback = CB2_OpenPokeblockFromBag;
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        gFieldCallback = FieldCB_ReturnToFieldNoScript;
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_OpenRegisteredPokeblockCase;
    }
}

static void CB2_OpenPokeblockFromBag(void)
{
    OpenPokeblockCase(PBLOCK_CASE_FIELD, CB2_ReturnToBagMenuPocket);
}

static void Task_OpenRegisteredPokeblockCase(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        OpenPokeblockCase(PBLOCK_CASE_FIELD, CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

void ItemUseOutOfBattle_CoinCase(u8 taskId)
{
    ConvertIntToDecimalStringN(gStringVar1, GetCoins(), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_CoinCase);

    if (!gTasks[taskId].tUsingRegisteredKeyItem)
    {
        DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
    }
    else
    {
        DisplayItemMessageOnField(taskId, gStringVar4, Task_CloseCantUseKeyItemMessage);
    }
}

void ItemUseOutOfBattle_PowderJar(u8 taskId)
{
    ConvertIntToDecimalStringN(gStringVar1, GetBerryPowder(), STR_CONV_MODE_LEFT_ALIGN, 5);
    StringExpandPlaceholders(gStringVar4, gText_PowderQty);

    if (!gTasks[taskId].tUsingRegisteredKeyItem)
    {
        DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
    }
    else
    {
        DisplayItemMessageOnField(taskId, gStringVar4, Task_CloseCantUseKeyItemMessage);
    }
}

void ItemUseOutOfBattle_Berry(u8 taskId)
{
    if (IsPlayerFacingEmptyBerryTreePatch() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_Berry;
        gFieldCallback = FieldCB_UseItemOnField;
        gBagMenu->exitCallback = CB2_ReturnToField;
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        ItemId_GetFieldFunc(gSpecialVar_ItemId)(taskId);
    }
}

static void ItemUseOnFieldCB_Berry(u8 taskId)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(BerryTree_EventScript_ItemUsePlantBerry);
    DestroyTask(taskId);
}

void ItemUseOutOfBattle_WailmerPail(u8 taskId)
{
    if (TryToWaterSudowoodo() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_WailmerPailSudowoodo;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else if (TryToWaterBerryTree() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_WailmerPailBerry;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
}

static void ItemUseOnFieldCB_WailmerPailBerry(u8 taskId)
{
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(BerryTree_EventScript_ItemUseWailmerPail);
    DestroyTask(taskId);
}

static bool8 TryToWaterSudowoodo(void)
{
    u16 x, y;
    u8 z;
    u8 objId;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    z = PlayerGetZCoord();
    objId = GetObjectEventIdByXYZ(x, y, z);
    if (objId == OBJECT_EVENTS_COUNT || gObjectEvents[objId].graphicsId != OBJ_EVENT_GFX_SUDOWOODO)
        return FALSE;
    else
        return TRUE;
}

static void ItemUseOnFieldCB_WailmerPailSudowoodo(u8 taskId)
{
    ScriptContext2_Enable();
    ScriptContext1_SetupScript(BattleFrontier_OutsideEast_EventScript_WaterSudowoodo);
    DestroyTask(taskId);
}

void ItemUseOutOfBattle_Medicine(u8 taskId)
{
    gItemUseCB = ItemUseCB_Medicine;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_AbilityCapsule(u8 taskId)
{
    gItemUseCB = ItemUseCB_AbilityCapsule;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_ReduceEV(u8 taskId)
{
    gItemUseCB = ItemUseCB_ReduceEV;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_SacredAsh(u8 taskId)
{
    gItemUseCB = ItemUseCB_SacredAsh;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_PPRecovery(u8 taskId)
{
    gItemUseCB = ItemUseCB_PPRecovery;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_PPUp(u8 taskId)
{
    gItemUseCB = ItemUseCB_PPUp;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_RareCandy(u8 taskId)
{
    gItemUseCB = ItemUseCB_RareCandy;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_TMHM(u8 taskId)
{
    if (gSpecialVar_ItemId >= ITEM_HM01_CUT)
        DisplayItemMessage(taskId, 1, gText_BootedUpHM, BootUpSoundTMHM); // HM
    else
        DisplayItemMessage(taskId, 1, gText_BootedUpTM, BootUpSoundTMHM); // TM
}

static void BootUpSoundTMHM(u8 taskId)
{
    PlaySE(SE_PC_LOGIN);
    gTasks[taskId].func = Task_ShowTMHMContainedMessage;
}

static void Task_ShowTMHMContainedMessage(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        StringCopy(gStringVar1, gMoveNames[ItemIdToBattleMoveId(gSpecialVar_ItemId)]);
        StringExpandPlaceholders(gStringVar4, gText_TMHMContainedVar1);
        DisplayItemMessage(taskId, 1, gStringVar4, UseTMHMYesNo);
    }
}

static void UseTMHMYesNo(u8 taskId)
{
    BagMenu_YesNo(taskId, 6, &sUseTMHMYesNoFuncTable);
}

static void UseTMHM(u8 taskId)
{
    gItemUseCB = ItemUseCB_TMHM;
    SetUpItemUseCallback(taskId);
}

static void RemoveUsedItem(void)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    CopyItemName(gSpecialVar_ItemId, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_PlayerUsedVar2);
    if (!InBattlePyramid())
    {
        UpdatePocketItemList(ItemId_GetPocket(gSpecialVar_ItemId));
        SetInitialScrollAndCursorPositions(ItemId_GetPocket(gSpecialVar_ItemId));
    }
    else
    {
        sub_81C5924();
        sub_81C59BC();
    }
}

void ItemUseOutOfBattle_Repel(u8 taskId)
{
    if (VarGet(VAR_REPEL_STEP_COUNT) == 0)
        gTasks[taskId].func = Task_StartUseRepel;
    else if (!InBattlePyramid())
        DisplayItemMessage(taskId, 1, gText_RepelEffectsLingered, BagMenu_InitListsMenu);
    else
        DisplayItemMessageInBattlePyramid(taskId, gText_RepelEffectsLingered, Task_CloseBattlePyramidBagMessage);
}

static void Task_StartUseRepel(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (++data[8] > 7)
    {
        data[8] = 0;
        PlaySE(SE_REPEL);
        gTasks[taskId].func = Task_UseRepel;
    }
}

static void Task_UseRepel(u8 taskId)
{
    if (!IsSEPlaying())
    {
        VarSet(VAR_REPEL_STEP_COUNT, ItemId_GetHoldEffectParam(gSpecialVar_ItemId));
        RemoveUsedItem();
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, gStringVar4, Task_CloseBattlePyramidBagMessage);
    }
}

static void Task_UsedBlackWhiteFlute(u8 taskId)
{
    if(++gTasks[taskId].data[8] > 7)
    {
        PlaySE(SE_GLASS_FLUTE);
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, gStringVar4, BagMenu_InitListsMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, gStringVar4, Task_CloseBattlePyramidBagMessage);
    }
}

void ItemUseOutOfBattle_BlackWhiteFlute(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar2);
    if (gSpecialVar_ItemId == ITEM_WHITE_FLUTE)
    {
        FlagSet(FLAG_SYS_ENC_UP_ITEM);
        FlagClear(FLAG_SYS_ENC_DOWN_ITEM);
        StringExpandPlaceholders(gStringVar4, gText_UsedVar2WildLured);
    }
    else
    {
        FlagSet(FLAG_SYS_ENC_DOWN_ITEM);
        FlagClear(FLAG_SYS_ENC_UP_ITEM);
        StringExpandPlaceholders(gStringVar4, gText_UsedVar2WildRepelled);
    }
    gTasks[taskId].data[8] = 0;
    gTasks[taskId].func = Task_UsedBlackWhiteFlute;
}

void Task_UseDigEscapeRopeOnField(u8 taskId)
{
    ResetInitialPlayerAvatarState();
    StartEscapeRopeFieldEffect();
    DestroyTask(taskId);
}

static void ItemUseOnFieldCB_EscapeRope(u8 taskId)
{
    Overworld_ResetStateAfterDigEscRope();
    #if I_KEY_ESCAPE_ROPE < GEN_8
        RemoveUsedItem();
    #endif
    gTasks[taskId].data[0] = 0;
    DisplayItemMessageOnField(taskId, gStringVar4, Task_UseDigEscapeRopeOnField);
}

bool8 CanUseDigOrEscapeRopeOnCurMap(void)
{
    if (!CheckFollowerFlag(FOLLOWER_FLAG_CAN_LEAVE_ROUTE))
        return FALSE;
    
    if (gMapHeader.flags & MAP_ALLOW_ESCAPING)
        return TRUE;
    else
        return FALSE;
}

void ItemUseOutOfBattle_EscapeRope(u8 taskId)
{
    if (CanUseDigOrEscapeRopeOnCurMap() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_EscapeRope;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
}

void ItemUseOutOfBattle_EvolutionStone(u8 taskId)
{
    gItemUseCB = ItemUseCB_EvolutionStone;
    SetUpItemUseCallback(taskId);
}

void ItemUseInBattle_PokeBall(u8 taskId)
{
    if (FlagGet(FLAG_SYS_NO_CATCHING)){ //DEBUG
        static const u8 sText_BallsCannotBeUsed[] = _("Poké Balls cannot be used\nright now!\p");
        DisplayItemMessage(taskId, 1, sText_BallsCannotBeUsed, BagMenu_InitListsMenu);        
    } //
   
    else if (IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT))
        && IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))) // There are two present pokemon.
    {
        static const u8 textCantThrowPokeBall[] = _("Cannot throw a ball!\nThere are two pokemon out there!\p");

        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, textCantThrowPokeBall, BagMenu_InitListsMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, textCantThrowPokeBall, Task_CloseBattlePyramidBagMessage);
    }
    else if (gBattlerInMenuId == GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)
             && IsBattlerAlive(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT))) // Attempting to throw a ball with the second pokemon while both are alive.
    {
        static const u8 textCantThrowPokeBall[] = _("Cannot throw a ball!\p");

        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, textCantThrowPokeBall, BagMenu_InitListsMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, textCantThrowPokeBall, Task_CloseBattlePyramidBagMessage);
    }
    else if (IsPlayerPartyAndPokemonStorageFull() == FALSE) // have room for mon?
    {
        RemoveBagItem(gSpecialVar_ItemId, 1);
        if (!InBattlePyramid())
            Task_FadeAndCloseBagMenu(taskId);
        else
            CloseBattlePyramidBagAndSetCallback(taskId);
    }
    else
    {
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, gText_BoxFull, BagMenu_InitListsMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, gText_BoxFull, Task_CloseBattlePyramidBagMessage);
    }
}

static void Task_CloseStatIncreaseMessage(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        if (!InBattlePyramid())
            Task_FadeAndCloseBagMenu(taskId);
        else
            CloseBattlePyramidBagAndSetCallback(taskId);
    }
}

static void Task_UseStatIncreaseItem(u8 taskId)
{
    if(++gTasks[taskId].data[8] > 7)
    {
        PlaySE(SE_USE_ITEM);
        RemoveBagItem(gSpecialVar_ItemId, 1);
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, UseStatIncreaseItem(gSpecialVar_ItemId), Task_CloseStatIncreaseMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, UseStatIncreaseItem(gSpecialVar_ItemId), Task_CloseStatIncreaseMessage);
    }
}

// e.g. X Attack, Guard Spec
void ItemUseInBattle_StatIncrease(u8 taskId)
{
    u16 partyId = gBattlerPartyIndexes[gBattlerInMenuId];

    if (ExecuteTableBasedItemEffect(&gPlayerParty[partyId], gSpecialVar_ItemId, partyId, 0) != FALSE)
    {
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, gText_WontHaveEffect, BagMenu_InitListsMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, gText_WontHaveEffect, Task_CloseBattlePyramidBagMessage);
    }
    else
    {
        gTasks[taskId].func = Task_UseStatIncreaseItem;
        gTasks[taskId].data[8] = 0;
    }
}

static void ItemUseInBattle_ShowPartyMenu(u8 taskId)
{
    if (!InBattlePyramid())
    {
        gBagMenu->exitCallback = ChooseMonForInBattleItem;
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        gPyramidBagResources->callback2 = ChooseMonForInBattleItem;
        CloseBattlePyramidBagAndSetCallback(taskId);
    }
}

void ItemUseInBattle_Medicine(u8 taskId)
{
    gItemUseCB = ItemUseCB_Medicine;
    ItemUseInBattle_ShowPartyMenu(taskId);
}

// Unused. Sacred Ash cannot be used in battle
void ItemUseInBattle_SacredAsh(u8 taskId)
{
    gItemUseCB = ItemUseCB_SacredAsh;
    ItemUseInBattle_ShowPartyMenu(taskId);
}

void ItemUseInBattle_PPRecovery(u8 taskId)
{
    gItemUseCB = ItemUseCB_PPRecovery;
    ItemUseInBattle_ShowPartyMenu(taskId);
}

// Fluffy Tail / Poke Doll
void ItemUseInBattle_Escape(u8 taskId)
{

    if((gBattleTypeFlags & BATTLE_TYPE_TRAINER) == FALSE)
    {
        RemoveUsedItem();
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, 1, gStringVar4, Task_FadeAndCloseBagMenu);
        else
            DisplayItemMessageInBattlePyramid(taskId, gStringVar4, CloseBattlePyramidBagAndSetCallback);
    }
    else
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
}

void ItemUseOutOfBattle_EnigmaBerry(u8 taskId)
{
    switch (GetItemEffectType(gSpecialVar_ItemId))
    {
    case ITEM_EFFECT_HEAL_HP:
    case ITEM_EFFECT_CURE_POISON:
    case ITEM_EFFECT_CURE_SLEEP:
    case ITEM_EFFECT_CURE_BURN:
    case ITEM_EFFECT_CURE_FREEZE:
    case ITEM_EFFECT_CURE_PARALYSIS:
    case ITEM_EFFECT_CURE_ALL_STATUS:
    case ITEM_EFFECT_ATK_EV:
    case ITEM_EFFECT_HP_EV:
    case ITEM_EFFECT_SPATK_EV:
    case ITEM_EFFECT_SPDEF_EV:
    case ITEM_EFFECT_SPEED_EV:
    case ITEM_EFFECT_DEF_EV:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_Medicine(taskId);
        break;
    case ITEM_EFFECT_SACRED_ASH:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_SacredAsh(taskId);
        break;
    case ITEM_EFFECT_RAISE_LEVEL:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_RareCandy(taskId);
        break;
    case ITEM_EFFECT_PP_UP:
    case ITEM_EFFECT_PP_MAX:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_PPUp(taskId);
        break;
    case ITEM_EFFECT_HEAL_PP:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_PPRecovery(taskId);
        break;
    default:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_BAG_MENU;
        ItemUseOutOfBattle_CannotUse(taskId);
        break;
    }
}

void ItemUseInBattle_EnigmaBerry(u8 taskId)
{
    switch (GetItemEffectType(gSpecialVar_ItemId))
    {
    case ITEM_EFFECT_X_ITEM:
        ItemUseInBattle_StatIncrease(taskId);
        break;
    case ITEM_EFFECT_HEAL_HP:
    case ITEM_EFFECT_CURE_POISON:
    case ITEM_EFFECT_CURE_SLEEP:
    case ITEM_EFFECT_CURE_BURN:
    case ITEM_EFFECT_CURE_FREEZE:
    case ITEM_EFFECT_CURE_PARALYSIS:
    case ITEM_EFFECT_CURE_ALL_STATUS:
    case ITEM_EFFECT_CURE_CONFUSION:
    case ITEM_EFFECT_CURE_INFATUATION:
        ItemUseInBattle_Medicine(taskId);
        break;
    case ITEM_EFFECT_HEAL_PP:
        ItemUseInBattle_PPRecovery(taskId);
        break;
    default:
        ItemUseOutOfBattle_CannotUse(taskId);
        break;
    }
}

void ItemUseOutOfBattle_CannotUse(u8 taskId)
{
    DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
}

void ItemUseOutOfBattle_Mints(u8 taskId)
{
    gItemUseCB = ItemUseCB_Mints;
    SetUpItemUseCallback(taskId);
}

#define tListMenuWindowId data[0]
#define tListMenuTaskId data[1]
#define tListMenuArrowTaskId data[2]
#define tListMenuItems 4
#define tListMenuScrollOffset data[6]
#define tListMenuSelectedRow data[7]

static const u8 sText_OpenedTheDiary[] = _("{PLAYER} opened the diary.\nWhich entry?");

struct DiaryEntry
{
    const u8 *title;
    const u8 *encodedMessage;
    const u8 *englishMessage;
};

static const u8 sText_DiaryEntryFirst_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}tHirty&7");
static const u8 sText_DiaryEntryFirst_EncodedMessage[] = _("E naymmo haat du Vulic.\pE lyh'd caas du veht so fyo drnuikr\ndraca fuutc.\pEd vaamc mega y Bihlr eh dra kid.\pE kiacc E zicd ryja du gaab so rayt\nIb yht gaab sujehk.");
static const u8 sText_DiaryEntryFirst_EnglishMessage[] = _("I really need to Focus.\pI can't seem to find my way through\nthese woods.\pIt feels like a Punch in the gut.\pI guess I just have to keep my head\nUp and keep moving.");
static const u8 sText_DiaryEntrySecond_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ExIsT");
static const u8 sText_DiaryEntrySecond_EncodedMessage[] = _("Drana yna mudc uv tevvanahd Bugésuh\ndra taaban E kad ehdu draca fuutc.\pE drehg E ajah cyf y Tnykuh doba\nBugésuh Lmyf ed'c fyo uid uv y\ldnaa dnihg Ib yrayt.");
static const u8 sText_DiaryEntrySecond_EnglishMessage[] = _("There are lots of different Pokémon\nthe deeper I get into these woods.\pI think I even saw a Dragon type\nPokémon Claw it's way out of a\ltree trunk Up ahead.");
static const u8 sText_DiaryEntryThird_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}oCeaN");
static const u8 sText_DiaryEntryThird_EncodedMessage[] = _("Ed'c paah y vaf tyoc cehla E'ja ryt\nFydan.\pSo Bimca ec faygahehk. E cruimt ryja\nbnabynat vun drec paddan.\pE lyh'd keja Ib.\nHud huf.");
static const u8 sText_DiaryEntryThird_EnglishMessage[] = _("It's been a few days since I've had\nWater.\pMy Pulse is weakening. I should have\nprepared for this better.\pI can't give Up.\nNot now.");
static const u8 sText_DiaryEntryFourth_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}wHite");
static const u8 sText_DiaryEntryFourth_EncodedMessage[] = _("E nyh ehdu y fydan-doba Bugésuh.\nEd fyc geht ahuikr du ramb rotnyda\lsa.\pE vaam paddan.\nSo Seht ec Lyms.\pE's vaamehk ymm Nekrd.\nE lyh tu drec.");
static const u8 sText_DiaryEntryFourth_EnglishMessage[] = _("I ran into a water-type Pokémon.\nIt was kind enough to help hydrate\lme.\pI feel better.\nMy Mind is Calm.\pI'm feeling all Right.\nI can do this.");
static const u8 sText_DiaryEntryFifth_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}MariaNa");
static const u8 sText_DiaryEntryFifth_EncodedMessage[] = _("Yc E kad taaban ehdu dra fuutc dra\ncdnyhkan drehkc caas.\pE raynt y muit Nuyn, yht E's hud.\ncina frana ed lysa vnus.\pEd cruug sa taab Tufh du so luna.");
static const u8 sText_DiaryEntryFifth_EnglishMessage[] = _("As I get deeper into the woods the\nstranger things seem.\pI heard a loud Roar, and I'm not.\nsure where it came from.\pIt shook me deep Down to my core.");
static const u8 sText_DiaryEntrySixth_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}esCApe");
static const u8 sText_DiaryEntrySixth_EncodedMessage[] = _("Yc E kad taaban ehdu dra fuutc dra\ncdnyhkan drehkc caas.\pE raynt y muit Nuyn, yht E's hud.\ncina frana ed lysa vnus.\pEd cruug sa taab Tufh du so luna.");
static const u8 sText_DiaryEntrySixth_EnglishMessage[] = _("There are so many cute little Spinarak\nin this area of the woods!\pI just hope I don't get bit. There is\nno one Up here and the wound could\lcould be infected with Toxic poison.");
static const u8 sText_DiaryEntrySeventh_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ndonEsia");
static const u8 sText_DiaryEntrySeventh_EncodedMessage[] = _("Famm dryd ec ehdanacdehk. Ed cdyndat\ndu Ryem! Ed'c naymmo lusehk Tufh!\pDrec bmyla cina ec cdnyhka. E ryja\nmucd dnylg uv desa, pid drana ec hu\lfyo ed luimt pa fehdan oad.");
static const u8 sText_DiaryEntrySeventh_EnglishMessage[] = _("Well that is interesting. It started\nto Hail! It's really coming Down!\pThis place sure is strange. I have\nlost track of time, but there is no\lway it could be winter yet.");
static const u8 sText_DiaryEntryEighth_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}pAradox");
static const u8 sText_DiaryEntryEighth_EncodedMessage[] = _("Dra femt Bugésuh caas du pa vaf\nyht vyn padfaah.\pDra uhac dryd E tu caa yna eh Pimg\ncaycuh! Jano raymdro muugehk!\pEh vyld E cyf y Cdyhdman Tufh po dra\nnejan fru muugat cdnuhkan dryh\lyho E ryja ajan caah pavuna!");
static const u8 sText_DiaryEntryEighth_EnglishMessage[] = _("The wild Pokémon seem to be few\nand far between.\pThe ones that I do see are in Bulk\nseason! Very healthy looking!\pIn fact I saw a Stantler Down by the\nriver who looked stronger than\lany I have ever seen before!");
static const u8 sText_DiaryEntryNinth_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}meridian");
static const u8 sText_DiaryEntryNinth_EncodedMessage[] = _("Yc E fyc dnyjancehk drnuikr dra\ndrelg pnicr E cyf cusadrehk web\lpo sa vnus Ypuja\pEd fyc cu vycd! Mega y Pimmad!\pE'ja ymcu caah cusa ehdanacdehk\nCaatc eh drec ynay dryd E tuh'd\lnalukhewa.\pUhla E kad cusafrana cyva E femm\nbmyhd dras yht caa fryd knufc!");
static const u8 sText_DiaryEntryNinth_EnglishMessage[] = _("As I was traversing through the\nthick brush I saw something zip\lby me from Above\pIt was so fast! Like a Bullet!\pI've also seen some interesting\nSeeds in this area that I don't\lrecognize.\pOnce I get somewhere safe I will\nplant them and see what grows!");
static const u8 sText_DiaryEntryTenth_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ratIon");
static const u8 sText_DiaryEntryTenth_EncodedMessage[] = _("Drana ec cu silr Rettah eh draca\ndnaac.\pE lyh vaam y cdnyhka Bufan asyhydehk\nvnus dras.\pPid E vayn ed ec hud yc cdnuhk yc ed\nuhla fyc.\pSyopa fa lyh cusauha rynhacc fryd ec\nMavd uv dra dnaac ahanko.");
static const u8 sText_DiaryEntryTenth_EnglishMessage[] = _("There is so much Hidden in these\ntrees.\pI can feel a strange Power emanating\nfrom them.\pBut I fear it is not as strong as it\nonce was.\pMaybe we can someone harness what is\nLeft of the trees energy.");
static const u8 sText_DiaryEntryEleventh_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}meddLer");
static const u8 sText_DiaryEntryEleventh_EncodedMessage[] = _("Dra faydran kuac vnus chuf du Cihho,\ndu vukko yht tysb.\pNekrd frah E drehg E ghuf fryd du\naqbald, aylr Tyo pnehkc haf cinbnecac.");
static const u8 sText_DiaryEntryEleventh_EnglishMessage[] = _("The weather goes from snow to Sunny,\nto foggy and damp.\pRight when I think I know what to\nexpect, each Day brings new surprises.");
static const u8 sText_DiaryEntryTwelveth_Title[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}crusade");
static const u8 sText_DiaryEntryTwelveth_EncodedMessage[] = _("E's cu lmuca du dra aht, E lyh vaam\ndra fuutc Dyihdehk sa.\pPid E lyh'd vaam Tufh ypuid ed,\nE zicd ryja y vaamehk ed ec ymsucd\lujan.");
static const u8 sText_DiaryEntryTwelveth_EnglishMessage[] = _("I'm so close to the end, I can feel\nthe woods Taunting me.\pBut I can't feel Down about it,\nI just have a feeling it is almost\lover.");
static const u8 sText_DiaryEntryThirteenth_Title[] = _("{COLOR RED}{SHADOW LIGHT_RED}11/06/1958");
static const u8 sText_DiaryEntryThirteenth_EncodedMessage[] = _("I have made it through the Lost\nWoods after years of research.\pIt is even more magnificent than I\nimagined.");
static const u8 sText_DiaryEntryThirteenth_EnglishMessage[] = _("I have made it through the Lost\nWoods after years of research.\pIt is even more magnificent than I\nimagined.");
static const u8 sText_DiaryEntryFourteenth_Title[] = _("{COLOR RED}{SHADOW LIGHT_RED}11/07/1958");
static const u8 sText_DiaryEntryFourteenth_EncodedMessage[] = _("I have set up camp here. It is so\nincredible I do not want to leave.\pI will continue to study the ecosystem\nand Pokémon here.");
static const u8 sText_DiaryEntryFourteenth_EnglishMessage[] = _("I have set up camp here. It is so\nincredible I do not want to leave.\pI will continue to study the ecosystem\nand Pokémon here.");
static const u8 sText_DiaryEntryFifteenth_Title[] = _("{COLOR RED}{SHADOW LIGHT_RED}11/09/1958");
static const u8 sText_DiaryEntryFifteenth_EncodedMessage[] = _("Last night I heard something strange.\pIt didn't sound like any Pokémon \nI've ever heard before.");
static const u8 sText_DiaryEntryFifteenth_EnglishMessage[] = _("Last night I heard something strange.\pIt didn't sound like any Pokémon \nI've ever heard before.");
static const u8 sText_DiaryEntrySixteenth_Title[] = _("{COLOR RED}{SHADOW LIGHT_RED}11/16/1958");
static const u8 sText_DiaryEntrySixteenth_EncodedMessage[] = _("I think I'm starting to go crazy.\nI feel like an outsider.\pLike all the Pokémon are avoiding me.\nStaring at me.\pIt's made my study extremely\ndifficult.");
static const u8 sText_DiaryEntrySixteenth_EnglishMessage[] = _("I think I'm starting to go crazy.\nI feel like an outsider.\pLike all the Pokémon are avoiding me.\nStaring at me.\pIt's made my study extremely\ndifficult.");
static const u8 sText_DiaryEntrySeventeenth_Title[] = _("{COLOR RED}{SHADOW LIGHT_RED}11/18/1958");
static const u8 sText_DiaryEntrySeventeenth_EncodedMessage[] = _("Things have seemed normal the past\nfew days.\pI think maybe I've been paranoid\nbecause I haven't had any human\lcontact.\pI think I'm going to head back home\nsoon.\pI just want to continue to study\nthese Pokémon in their natural\lhabitat then I will head back to town\land report my findings.\pMaybe we can bring a bigger team out\nhere.");
static const u8 sText_DiaryEntrySeventeenth_EnglishMessage[] = _("Things have seemed normal the past\nfew days.\pI think maybe I've been paranoid\nbecause I haven't had any human\lcontact.\pI think I'm going to head back home\nsoon.\pI just want to continue to study\nthese Pokémon in their natural\lhabitat then I will head back to town\land report my findings.\pMaybe we can bring a bigger team out\nhere.");
static const u8 sText_DiaryEntryEighteenth_Title[] = _("{COLOR RED}{SHADOW LIGHT_RED}11/19/1958");
static const u8 sText_DiaryEntryEighteenth_EncodedMessage[] = _("I can't stay any longer. I must be\ngoing crazy.\pI feel like I can understand the\nPokémon dymgehk du aylr udran, and\lthey tavehedamo aren't happy I'm\lhere.");
static const u8 sText_DiaryEntryEighteenth_EnglishMessage[] = _("I can't stay any longer. I must be\ngoing crazy.\pI feel like I can understand the\nPokémon talking to each other, and\lthey definitely aren't happy I'm\lhere.");
static const u8 sText_DiaryEntryNineteenth_Title[] = _("{COLOR RED}{SHADOW LIGHT_RED}11/20/1958");
static const u8 sText_DiaryEntryNineteenth_EncodedMessage[] = _("I have cbahd dra past day hiding\neh so dahd.\pAjano desa E syta y move to leave I\nvamd yc ev I would be attacked.\pI don't know what I'm going to do.");
static const u8 sText_DiaryEntryNineteenth_EnglishMessage[] = _("I have spent the past day hiding\nin my tent.\pEvery time I made a move to leave I\nfelt as if I would be attacked.\pI don't know what I'm going to do.");
static const u8 sText_DiaryEntryTwentieth_Title[] = _("{COLOR RED}{SHADOW LIGHT_RED}11/21/1958");
static const u8 sText_DiaryEntryTwentieth_EncodedMessage[] = _("I ryja syta a run for it.\nI made ed out of the Lost Woods pid\lE fear I've been followed.\pI don't have much time.\pI ryja left myself clues du\nnavigate the Lost Woods in my Diary.\pEv anyone finds drec, ghuf dryd E\ntuh'd cikkacd yhouha traverse the\lLost Woods, vun ed luhdyehc yh\lunspeakable evil.\pOh gosh, the Spinarak tet follow me.\pI can see them now.\pE tuh'd think my hiding spot in\nthese mushrooms is luhlaymehk me well\lahuikr.\pEv you find Spinarak hayn a hidden\npatch of mushrooms, please look for\lme.\pPlease help.\p...The entries end here, but there\nappears to be some pages missing.\p{PLAYER} counts twelve missing pages...");
static const u8 sText_DiaryEntryTwentieth_EnglishMessage[] = _("I have made a run for it.\nI made it out of the Lost Woods but\lI fear I've been followed.\pI don't have much time.\pI have left myself clues to\nnavigate the Lost Woods in my Diary.\pIf anyone finds this, know that I\ndon't suggest anyone traverse the\lLost Woods, for it contains an\lunspeakable evil.\pOh gosh, the Spinarak did follow me.\pI can see them now.\pI don't think my hiding spot in\nthese mushrooms is concealing me well\lenough.\pIf you find Spinarak near a hidden\npatch of mushrooms, please look for\lme.\pPlease help.\p...The entries end here, but there\nappears to be some pages missing.\p{PLAYER} counts twelve missing pages...");

static const struct DiaryEntry sDiaryEntries[NUM_DIARY_ENTRIES] =
{
    [DIARY_ENTRY_FIRST] = { sText_DiaryEntryFirst_Title, sText_DiaryEntryFirst_EncodedMessage, sText_DiaryEntryFirst_EnglishMessage },
    [DIARY_ENTRY_SECOND] = { sText_DiaryEntrySecond_Title, sText_DiaryEntrySecond_EncodedMessage, sText_DiaryEntrySecond_EnglishMessage },
    [DIARY_ENTRY_THIRD] = { sText_DiaryEntryThird_Title, sText_DiaryEntryThird_EncodedMessage, sText_DiaryEntryThird_EnglishMessage },
    [DIARY_ENTRY_FOURTH] = { sText_DiaryEntryFourth_Title, sText_DiaryEntryFourth_EncodedMessage, sText_DiaryEntryFourth_EnglishMessage },
    [DIARY_ENTRY_FIFTH] = { sText_DiaryEntryFifth_Title, sText_DiaryEntryFifth_EncodedMessage, sText_DiaryEntryFifth_EnglishMessage },
    [DIARY_ENTRY_SIXTH] = { sText_DiaryEntrySixth_Title, sText_DiaryEntrySixth_EncodedMessage, sText_DiaryEntrySixth_EnglishMessage },
    [DIARY_ENTRY_SEVENTH] = { sText_DiaryEntrySeventh_Title, sText_DiaryEntrySeventh_EncodedMessage, sText_DiaryEntrySeventh_EnglishMessage },
    [DIARY_ENTRY_EIGHTH] = { sText_DiaryEntryEighth_Title, sText_DiaryEntryEighth_EncodedMessage, sText_DiaryEntryEighth_EnglishMessage },
    [DIARY_ENTRY_NINTH] = { sText_DiaryEntryNinth_Title, sText_DiaryEntryNinth_EncodedMessage, sText_DiaryEntryNinth_EnglishMessage },
    [DIARY_ENTRY_TENTH] = { sText_DiaryEntryTenth_Title, sText_DiaryEntryTenth_EncodedMessage, sText_DiaryEntryTenth_EnglishMessage },
    [DIARY_ENTRY_ELEVENTH] = { sText_DiaryEntryEleventh_Title, sText_DiaryEntryEleventh_EncodedMessage, sText_DiaryEntryEleventh_EnglishMessage },
    [DIARY_ENTRY_TWELVETH] = { sText_DiaryEntryTwelveth_Title, sText_DiaryEntryTwelveth_EncodedMessage, sText_DiaryEntryTwelveth_EnglishMessage },
    [DIARY_ENTRY_THIRTEENTH] = { sText_DiaryEntryThirteenth_Title, sText_DiaryEntryThirteenth_EncodedMessage, sText_DiaryEntryThirteenth_EnglishMessage },
    [DIARY_ENTRY_FOURTEENTH] = { sText_DiaryEntryFourteenth_Title, sText_DiaryEntryFourteenth_EncodedMessage, sText_DiaryEntryFourteenth_EnglishMessage },
    [DIARY_ENTRY_FIFTEENTH] = { sText_DiaryEntryFifteenth_Title, sText_DiaryEntryFifteenth_EncodedMessage, sText_DiaryEntryFifteenth_EnglishMessage },
    [DIARY_ENTRY_SIXTEENTH] = { sText_DiaryEntrySixteenth_Title, sText_DiaryEntrySixteenth_EncodedMessage, sText_DiaryEntrySixteenth_EnglishMessage },
    [DIARY_ENTRY_SEVENTEENTH] = { sText_DiaryEntrySeventeenth_Title, sText_DiaryEntrySeventeenth_EncodedMessage, sText_DiaryEntrySeventeenth_EnglishMessage },
    [DIARY_ENTRY_EIGHTEENTH] = { sText_DiaryEntryEighteenth_Title, sText_DiaryEntryEighteenth_EncodedMessage, sText_DiaryEntryEighteenth_EnglishMessage },
    [DIARY_ENTRY_NINETEENTH] = { sText_DiaryEntryNineteenth_Title, sText_DiaryEntryNineteenth_EncodedMessage, sText_DiaryEntryNineteenth_EnglishMessage },
    [DIARY_ENTRY_TWENTIETH] = { sText_DiaryEntryTwentieth_Title, sText_DiaryEntryTwentieth_EncodedMessage, sText_DiaryEntryTwentieth_EnglishMessage },
};

static void Task_UseDiary2(u8 taskId);

static void Task_UseDiary4(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        extern u8 AddItemMessageWindow(u8);
        u32 messageWindowId = AddItemMessageWindow(4);
        FillWindowPixelBuffer(messageWindowId, PIXEL_FILL(1));
        StringExpandPlaceholders(gStringVar4, sText_OpenedTheDiary);
        AddTextPrinterParameterized2(messageWindowId, 1, gStringVar4, 0xFF, NULL, TEXT_COLOR_DARK_GREY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GREY);
        CopyWindowToVram(messageWindowId, 3);
        gTasks[taskId].func = Task_UseDiary2;
    }
}

static void UseDiary_Destroy(u8 taskId, bool32 copyToVram)
{
    s16 *data = gTasks[taskId].data;
    if (gSaveBlock1Ptr->diaryEntriesFound >= 2)
        RemoveScrollIndicatorArrowPair(tListMenuArrowTaskId);
    DestroyListMenuTask(tListMenuTaskId, (u16 *)&tListMenuScrollOffset, (u16 *)&tListMenuSelectedRow);
    Free((void *)GetWordTaskArg(taskId, tListMenuItems));
    ClearStdWindowAndFrameToTransparent(tListMenuWindowId, copyToVram);
    RemoveWindow(tListMenuWindowId);
}

static void Task_UseDiary3(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s32 selected = ListMenu_ProcessInput(tListMenuTaskId);
    if (selected == LIST_CANCEL)
    {
        UseDiary_Destroy(taskId, FALSE);
        PlaySE(SE_SELECT);
        gTasks[taskId].func = BagMenu_InitListsMenu;
    }
    else if (selected != LIST_NOTHING_CHOSEN)
    {
        UseDiary_Destroy(taskId, TRUE);
        PlaySE(SE_SELECT);
        if (FlagGet(FLAG_FOUND_CIPHER))
            DisplayItemMessage(taskId, 1, sDiaryEntries[selected].englishMessage, Task_UseDiary4);
        else
            DisplayItemMessage(taskId, 1, sDiaryEntries[selected].encodedMessage, Task_UseDiary4);
    }
}

static const struct ScrollArrowsTemplate sDiaryScrollArrowsTemplate = {
    .firstArrowType = SCROLL_ARROW_UP,
    .firstX = 188,
    .firstY = 52,
    .secondArrowType = SCROLL_ARROW_DOWN,
    .secondX = 188,
    .secondY = 108,
    .fullyUpThreshold = -1,
    .fullyDownThreshold = -1,
    .tileTag = 112,
    .palTag = 112,
    .palNum = 0,
};

static void Task_UseDiary2(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct WindowTemplate windowTemplate = {};
    struct ListMenuTemplate listMenuTemplate = {};
    struct ListMenuItem *items;
    u32 i;

    windowTemplate.bg = 1;
    windowTemplate.tilemapLeft = 20;
    windowTemplate.tilemapTop = 13 - min(3, gSaveBlock1Ptr->diaryEntriesFound + 1) * 2;
    windowTemplate.width = 7;
    windowTemplate.height = min(3, gSaveBlock1Ptr->diaryEntriesFound + 1) * 2;
    windowTemplate.paletteNum = 15;
    windowTemplate.baseBlock = 0x21D;

    tListMenuWindowId = AddWindow(&windowTemplate);
    DrawStdFrameWithCustomTileAndPalette(tListMenuWindowId, TRUE, 1, 14);

    listMenuTemplate.items = items = Alloc(sizeof(*items) * (gSaveBlock1Ptr->diaryEntriesFound + 1));
    SetWordTaskArg(taskId, tListMenuItems, (uintptr_t)items);
    for (i = 0; i < gSaveBlock1Ptr->diaryEntriesFound; i++)
    {
        u32 index = gSaveBlock1Ptr->diaryEntriesOrder[gSaveBlock1Ptr->diaryEntriesFound - i - 1];
        items[i].name = sDiaryEntries[index].title;
        items[i].id = index;
    }
    items[i].name = gText_Cancel;
    items[i].id = LIST_CANCEL;
    listMenuTemplate.moveCursorFunc = ListMenuDefaultCursorMoveFunc;
    listMenuTemplate.totalItems = gSaveBlock1Ptr->diaryEntriesFound + 1;
    listMenuTemplate.maxShowed = 3;
    listMenuTemplate.windowId = tListMenuWindowId;
    listMenuTemplate.item_X = 8;
    listMenuTemplate.cursor_X = 0;
    listMenuTemplate.upText_Y = 1;
    listMenuTemplate.cursorPal = TEXT_COLOR_DARK_GREY;
    listMenuTemplate.fillValue = TEXT_COLOR_WHITE;
    listMenuTemplate.cursorShadowPal = TEXT_COLOR_LIGHT_GREY;
    listMenuTemplate.lettersSpacing = 1;
    listMenuTemplate.itemVerticalPadding = 0;
    listMenuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    listMenuTemplate.fontId = 1;
    listMenuTemplate.cursorKind = 0;
    tListMenuTaskId = ListMenuInit(&listMenuTemplate, tListMenuScrollOffset, tListMenuSelectedRow);
    if (gSaveBlock1Ptr->diaryEntriesFound >= 2)
        tListMenuArrowTaskId = AddScrollIndicatorArrowPair(&sDiaryScrollArrowsTemplate, NULL);

    gTasks[taskId].func = Task_UseDiary3;
}

static void Task_UseDiary1(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (InBattlePyramid())
        DisplayItemMessageInBattlePyramid(taskId, gText_DadsAdvice, Task_CloseBattlePyramidBagMessage);
    else if (tUsingRegisteredKeyItem)
        DisplayItemMessageOnField(taskId, gText_DadsAdvice, Task_CloseCantUseKeyItemMessage);
    else
        DisplayItemMessage(taskId, 1, sText_OpenedTheDiary, Task_UseDiary2);
}

void ItemUseOutOfBattle_Diary(u8 taskId)
{
    gTasks[taskId].func = Task_UseDiary1;
}

void ItemUseOutOfBattle_OutfitBox(u8 taskId)
{
    if (MenuHelpers_LinkSomething() == TRUE)
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
    else if (gTasks[taskId].tUsingRegisteredKeyItem != TRUE)
    {
        gBagMenu->exitCallback = CB2_OpenOutfitBoxFromBag;
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        gFieldCallback = FieldCB_ReturnToFieldNoScript;
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_OpenRegisteredOutfitBox;
    }
}

static void CB2_OpenOutfitBoxFromBag(void)
{
    OpenOutfitMenu(CB2_ReturnToBagMenuPocket);
}

static void Task_OpenRegisteredOutfitBox(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        OpenOutfitMenu(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

#undef tListMenuWindowId
#undef tListMenuTaskId
#undef tListMenuArrowTaskId
#undef tListMenuItems
#undef tListMenuScrollOffset
#undef tListMenuSelectedRow

#undef tUsingRegisteredKeyItem
