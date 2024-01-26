#include "global.h"
#include "cable_club.h"
#include "event_data.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_door.h"
#include "field_effect.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_special_scene.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "io_reg.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "map_preview.h"
#include "menu.h"
#include "mirage_tower.h"
#include "metatile_behavior.h"
#include "palette.h"
#include "overworld.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "start_menu.h"
#include "task.h"
#include "text.h"
#include "follow_me.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "trainer_hill.h"
#include "fldeff.h"

// This file's functions.
static void Task_ExitNonAnimDoor(u8);
static void Task_ExitNonDoor(u8);
//static void Task_DoContestHallWarp(u8);
static void FillPalBufferWhite(void);
static void Task_ExitDoor(u8);
static void Task_TeleportTileWarpExit(u8 taskId);
//static bool32 WaitForWeatherFadeIn(void);
static void Task_SpinEnterWarp(u8 taskId);
static void Task_WarpAndLoadMap(u8 taskId);
//static void Task_DoDoorWarp(u8 taskId);
static void Task_EnableScriptAfterMusicFade(u8 taskId);

// data[0] is used universally by tasks in this file as a state for switches
#define tState       data[0]

// const
static const u16 sFlashLevelPixelRadii[] = { 200, 72, 64, 56, 48, 40, 32, 24, 0 };
const s32 gMaxFlashLevel = ARRAY_COUNT(sFlashLevelPixelRadii) - 1;

const struct ScanlineEffectParams sFlashEffectParams =
{
    (void *)REG_ADDR_WIN0H,
    ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
    1
};

// code
static void FillPalBufferWhite(void)
{
    CpuFastFill16(RGB_WHITE, gPlttBufferFaded, PLTT_SIZE);
}

void FillPalBufferBlack(void)
{
    CpuFastFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);
}

void WarpFadeInScreen(void)
{
    u8 previousMapType = GetLastUsedWarpMapType();
    switch (GetMapPairFadeFromType(previousMapType, GetCurrentMapType()))
    {
    case 0:
        FillPalBufferBlack();
        FadeScreen(FADE_FROM_BLACK, 0);
        break;
    case 1:
        FillPalBufferWhite();
        FadeScreen(FADE_FROM_WHITE, 0);
    }
}

void FadeInFromWhite(void)
{
    FillPalBufferWhite();
    FadeScreen(FADE_FROM_WHITE, 8);
}

void FadeInFromBlack(void)
{
    FillPalBufferBlack();
    FadeScreen(FADE_FROM_BLACK, 0);
}

void WarpFadeOutScreen(void)
{
    const struct MapHeader *header = GetDestinationWarpMapHeader();
    
    if (header->regionMapSectionId != gMapHeader.regionMapSectionId && MapHasPreviewScreen(header->regionMapSectionId, MPS_TYPE_CAVE))
    {
        FadeScreen(FADE_TO_BLACK, 0);
    }
    else
    {
        switch (GetMapPairFadeToType(GetCurrentMapType(), header->mapType))
        {
        case 0:
            FadeScreen(FADE_TO_BLACK, 0);
            break;
        case 1:
            FadeScreen(FADE_TO_WHITE, 0);
        }
    }
}

void SetPlayerVisibility(bool8 visible)
{
    SetPlayerInvisibility(!visible);
}

static void Task_WaitForUnionRoomFade(u8 taskId)
{
    if (WaitForWeatherFadeIn() == TRUE)
        DestroyTask(taskId);
}

void FieldCB_ContinueScriptUnionRoom(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    CreateTask(Task_WaitForUnionRoomFade, 10);
}

static void Task_WaitForFadeAndEnableScriptCtx(u8 taskID)
{
    if (WaitForWeatherFadeIn() == TRUE)
    {
        DestroyTask(taskID);
        EnableBothScriptContexts();
    }
}

void FieldCB_ContinueScriptHandleMusic(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    CreateTask(Task_WaitForFadeAndEnableScriptCtx, 10);
}

void FieldCB_ContinueScript(void)
{
    ScriptContext2_Enable();
    FadeInFromBlack();
    CreateTask(Task_WaitForFadeAndEnableScriptCtx, 10);
}

static void Task_ReturnToFieldCableLink(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->data[1] = CreateTask_ReestablishCableClubLink();
        task->tState++;
        break;
    case 1:
        if (gTasks[task->data[1]].isActive != TRUE)
        {
            WarpFadeInScreen();
            task->tState++;
        }
        break;
    case 2:
        if (WaitForWeatherFadeIn() == TRUE)
        {
            ScriptContext2_Disable();
            DestroyTask(taskId);
        }
        break;
    }
}

void FieldCB_ReturnToFieldCableLink(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FillPalBufferBlack();
    CreateTask(Task_ReturnToFieldCableLink, 10);
}

static void Task_ReturnToFieldWirelessLink(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        SetLinkStandbyCallback();
        task->tState++;
        break;
    case 1:
        if (!IsLinkTaskFinished())
        {
            if (++task->data[1] > 1800)
                GetLinkmanErrorParams(0x6000);
        }
        else
        {
            WarpFadeInScreen();
            task->tState++;
        }
        break;
    case 2:
        if (WaitForWeatherFadeIn() == TRUE)
        {
            StartSendingKeysToLink();
            ScriptContext2_Disable();
            DestroyTask(taskId);
        }
        break;
    }
}

void Task_ReturnToFieldRecordMixing(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        SetLinkStandbyCallback();
        task->tState++;
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            task->tState++;
        }
        break;
    case 2:
        StartSendingKeysToLink();
        ResetAllMultiplayerState();
        ScriptContext2_Disable();
        DestroyTask(taskId);
        break;
    }
}

void FieldCB_ReturnToFieldWirelessLink(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FillPalBufferBlack();
    CreateTask(Task_ReturnToFieldWirelessLink, 10);
}

static void SetUpWarpExitTask(void)
{
    s16 x, y;
    u8 behavior;
    TaskFunc func;

    PlayerGetDestCoords(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);
    if (MetatileBehavior_IsDoor(behavior) == TRUE)
        func = Task_ExitDoor;
    else if (MetatileBehavior_IsNonAnimDoor(behavior) == TRUE)
        func = Task_ExitNonAnimDoor;
    else
        func = Task_ExitNonDoor;
    CreateTask(func, 10);
}

void FieldCB_DefaultWarpExit(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    SetUpWarpExitTask();
    
    FollowMe_WarpSetEnd();
    
    ScriptContext2_Enable();
}

void FieldCB_WarpExitFadeFromWhite(void)
{
    Overworld_PlaySpecialMapMusic();
    FadeInFromWhite();
    SetUpWarpExitTask();
    ScriptContext2_Enable();
}

void FieldCB_WarpExitFadeFromBlack(void)
{
    if (!OnTrainerHillEReaderChallengeFloor()) // always false
        Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    SetUpWarpExitTask();
    ScriptContext2_Enable();
}

static void FieldCB_SpinEnterWarp(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    PlaySE(SE_WARP_OUT);
    CreateTask(Task_SpinEnterWarp, 10);
    ScriptContext2_Enable();
}

static void FieldCB_MossdeepGymWarpExit(void)
{
    Overworld_PlaySpecialMapMusic();
    WarpFadeInScreen();
    PlaySE(SE_WARP_OUT);
    CreateTask(Task_ExitNonDoor, 10);
    ScriptContext2_Enable();
    SetObjectEventLoadFlag((~SKIP_OBJECT_EVENT_LOAD) & 0xF);
}

static void Task_ExitDoor(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    s16 *x = &task->data[2];
    s16 *y = &task->data[3];

    switch (task->tState)
    {
    case 0:
        HideFollower();
        SetPlayerVisibility(FALSE);
        FreezeObjectEvents();
        PlayerGetDestCoords(x, y);
        FieldSetDoorOpened(*x, *y);
        task->tState = 1;
        break;
    case 1:
        if (WaitForWeatherFadeIn())
        {
            u8 objEventId;
            SetPlayerVisibility(TRUE);
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventSetHeldMovement(&gObjectEvents[objEventId], MOVEMENT_ACTION_WALK_NORMAL_DOWN);
            task->tState = 2;
        }
        break;
    case 2:
        if (IsPlayerStandingStill())
        {
            u8 objEventId;
            task->data[1] = FieldAnimateDoorClose(*x, *y);
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfFinished(&gObjectEvents[objEventId]);
            task->tState = 3;
        }
        break;
    case 3:
        if (task->data[1] < 0 || gTasks[task->data[1]].isActive != TRUE)
        {
            FollowMe_SetIndicatorToComeOutDoor();
            FollowMe_WarpSetEnd();
            
            UnfreezeObjectEvents();
            task->tState = 4;
        }
        break;
    case 4:
        ScriptContext2_Disable();
        DestroyTask(taskId);
        break;
    }
}

static void Task_ExitNonAnimDoor(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    s16 *x = &task->data[2];
    s16 *y = &task->data[3];

    switch (task->tState)
    {
    case 0:
        HideFollower();
        SetPlayerVisibility(FALSE);
        FreezeObjectEvents();
        PlayerGetDestCoords(x, y);
        task->tState = 1;
        break;
    case 1:
        if (WaitForWeatherFadeIn())
        {
            u8 objEventId;
            SetPlayerVisibility(TRUE);
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventSetHeldMovement(&gObjectEvents[objEventId], GetWalkNormalMovementAction(GetPlayerFacingDirection()));
            task->tState = 2;
        }
        break;
    case 2:
        if (IsPlayerStandingStill())
        {
            FollowMe_SetIndicatorToComeOutDoor();
            FollowMe_WarpSetEnd();
            
            UnfreezeObjectEvents();
            task->tState = 3;
        }
        break;
    case 3:
        ScriptContext2_Disable();
        DestroyTask(taskId);
        break;
    }
}

static void Task_ExitNonDoor(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        gTasks[taskId].tState++;
        break;
    case 1:
        if (WaitForWeatherFadeIn())
        {
            UnfreezeObjectEvents();
            ScriptContext2_Disable();
            DestroyTask(taskId);
        }
        break;
    }
}

static void Task_WaitForFadeShowStartMenu(u8 taskId)
{
    if (WaitForWeatherFadeIn() == TRUE)
    {
        DestroyTask(taskId);
        CreateTask(Task_ShowStartMenu, 80);
    }
}

void ReturnToFieldOpenStartMenu(void)
{
    FadeInFromBlack();
    CreateTask(Task_WaitForFadeShowStartMenu, 0x50);
    ScriptContext2_Enable();
}

bool8 FieldCB_ReturnToFieldOpenStartMenu(void)
{
    ShowReturnToFieldStartMenu();
    return FALSE;
}

static void Task_ReturnToFieldNoScript(u8 taskId)
{
    if (WaitForWeatherFadeIn() == 1)
    {
        ScriptContext2_Disable();
        DestroyTask(taskId);
        ScriptUnfreezeObjectEvents();
    }
}

void FieldCB_ReturnToFieldNoScript(void)
{
    ScriptContext2_Enable();
    FadeInFromBlack();
    CreateTask(Task_ReturnToFieldNoScript, 10);
}

void FieldCB_ReturnToFieldNoScriptCheckMusic(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    CreateTask(Task_ReturnToFieldNoScript, 10);
}

static bool32 PaletteFadeActive(void)
{
    return gPaletteFade.active;
}

bool32 WaitForWeatherFadeIn(void)
{
    if (IsWeatherNotFadingIn() == TRUE && ForestMapPreviewScreenIsRunning())
        return TRUE;
    else
        return FALSE;
}

void DoWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlayRainStoppingSoundEffect();
    PlaySE(SE_EXIT);
    gFieldCallback = FieldCB_DefaultWarpExit;
    CreateTask(Task_WarpAndLoadMap, 10);
}

void DoDiveWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlayRainStoppingSoundEffect();
    gFieldCallback = FieldCB_DefaultWarpExit;
    CreateTask(Task_WarpAndLoadMap, 10);
}

void DoSootopolisLegendWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    FadeScreen(FADE_TO_WHITE, 8);
    PlayRainStoppingSoundEffect();
    gFieldCallback = FieldCB_WarpExitFadeFromWhite;
    CreateTask(Task_WarpAndLoadMap, 10);
}

void DoDoorWarp(void)
{
    ScriptContext2_Enable();
    gFieldCallback = FieldCB_DefaultWarpExit;
    CreateTask(Task_DoDoorWarp, 10);
}

void DoFallWarp(void)
{
    DoDiveWarp();
    gFieldCallback = FieldCB_FallWarpExit;
}

void DoEscalatorWarp(u8 metatileBehavior)
{
    ScriptContext2_Enable();
    StartEscalatorWarp(metatileBehavior, 10);
}

void DoLavaridgeGymB1FWarp(void)
{
    ScriptContext2_Enable();
    StartLavaridgeGymB1FWarp(10);
}

void DoLavaridgeGym1FWarp(void)
{
    ScriptContext2_Enable();
    StartLavaridgeGym1FWarp(10);
}

// DoSpinEnterWarp but with a fade out
// Screen fades out to exit current map, player spins down from top to enter new map
// Used by teleporting tiles, e.g. in Aqua Hideout (For the move Teleport see FldEff_TeleportWarpOut)
void DoTeleportTileWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlaySE(SE_WARP_IN);
    CreateTask(Task_WarpAndLoadMap, 10);
    gFieldCallback = FieldCB_SpinEnterWarp;
}

void DoMossdeepGymWarp(void)
{
    SetObjectEventLoadFlag(SKIP_OBJECT_EVENT_LOAD);
    ScriptContext2_Enable();
    SaveObjectEvents();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlaySE(SE_WARP_IN);
    CreateTask(Task_WarpAndLoadMap, 10);
    gFieldCallback = FieldCB_MossdeepGymWarpExit;
}

void DoPortholeWarp(void)
{
    ScriptContext2_Enable();
    WarpFadeOutScreen();
    CreateTask(Task_WarpAndLoadMap, 10);
    gFieldCallback = FieldCB_ShowPortholeView;
}

static void Task_DoCableClubWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        ScriptContext2_Enable();
        task->tState++;
        break;
    case 1:
        if (!PaletteFadeActive() && BGMusicStopped())
            task->tState++;
        break;
    case 2:
        WarpIntoMap();
        SetMainCallback2(CB2_ReturnToFieldCableClub);
        DestroyTask(taskId);
        break;
    }
}

void DoCableClubWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlaySE(SE_EXIT);
    CreateTask(Task_DoCableClubWarp, 10);
}

static void Task_ReturnToWorldFromLinkRoom(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        ClearLinkCallback_2();
        FadeScreen(FADE_TO_BLACK, 0);
        TryFadeOutOldMapMusic();
        PlaySE(SE_EXIT);
        tState++;
        break;
    case 1:
        if (!PaletteFadeActive() && BGMusicStopped())
        {
            SetCloseLinkCallback();
            tState++;
        }
        break;
    case 2:
        if (!gReceivedRemoteLinkPlayers)
        {
            WarpIntoMap();
            SetMainCallback2(CB2_LoadMap);
            DestroyTask(taskId);
        }
        break;
    }
}

void ReturnFromLinkRoom(void)
{
    CreateTask(Task_ReturnToWorldFromLinkRoom, 10);
}

static void Task_WarpAndLoadMap(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        task->tState++;
        break;
    case 1:
        if (!PaletteFadeActive())
        {
            if (task->data[1] == 0)
            {
                ClearMirageTowerPulseBlendEffect();
                task->data[1] = 1;
            }
            if (BGMusicStopped())
                task->tState++;
        }
        break;
    case 2:
        WarpIntoMap();
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
        break;
    }
}

/*
static void Task_DoDoorWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    s16 *x = &task->data[2];
    s16 *y = &task->data[3];

    switch (task->tState)
    {
    case 0:
        FreezeObjectEvents();
        PlayerGetDestCoords(x, y);
        PlaySE(GetDoorSoundEffect(*x, *y - 1));
        task->data[1] = FieldAnimateDoorOpen(*x, *y - 1);
        task->tState = 1;
        break;
    case 1:
        if (task->data[1] < 0 || gTasks[task->data[1]].isActive != TRUE)
        {
            u8 objEventId;
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfActive(&gObjectEvents[objEventId]);
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventSetHeldMovement(&gObjectEvents[objEventId], MOVEMENT_ACTION_WALK_NORMAL_UP);
            task->tState = 2;
        }
        break;
    case 2:
        if (IsPlayerStandingStill())
        {
            u8 objEventId;
            task->data[1] = FieldAnimateDoorClose(*x, *y - 1);
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfFinished(&gObjectEvents[objEventId]);
            SetPlayerVisibility(FALSE);
            task->tState = 3;
        }
        break;
    case 3:
        if (task->data[1] < 0 || gTasks[task->data[1]].isActive != TRUE)
        {
            task->tState = 4;
        }
        break;
    case 4:
        TryFadeOutOldMapMusic();
        WarpFadeOutScreen();
        PlayRainStoppingSoundEffect();
        task->tState = 0;
        task->func = Task_WarpAndLoadMap;
        break;
    }
}
*/

void Task_DoContestHallWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        task->tState++;
        break;
    case 1:
        if (!PaletteFadeActive() && BGMusicStopped())
        {
            task->tState++;
        }
        break;
    case 2:
        WarpIntoMap();
        SetMainCallback2(CB2_ReturnToFieldContestHall);
        DestroyTask(taskId);
        break;
    }
}

void DoContestHallWarp(void)
{
    ScriptContext2_Enable();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlayRainStoppingSoundEffect();
    PlaySE(SE_EXIT);
    gFieldCallback = FieldCB_WarpExitFadeFromBlack;
    CreateTask(Task_DoContestHallWarp, 10);
}

static void SetFlashScanlineEffectWindowBoundary(u16 *dest, u32 y, s32 left, s32 right)
{
    if (y <= 160)
    {
        if (left < 0)
            left = 0;
        if (left > 255)
            left = 255;
        if (right < 0)
            right = 0;
        if (right > 255)
            right = 255;
        dest[y] = (left << 8) | right;
    }
}

static void SetFlashScanlineEffectWindowBoundaries(u16 *dest, s32 centerX, s32 centerY, s32 radius)
{
    s32 r = radius;
    s32 v2 = radius;
    s32 v3 = 0;
    while (r >= v3)
    {
        SetFlashScanlineEffectWindowBoundary(dest, centerY - v3, centerX - r, centerX + r);
        SetFlashScanlineEffectWindowBoundary(dest, centerY + v3, centerX - r, centerX + r);
        SetFlashScanlineEffectWindowBoundary(dest, centerY - r, centerX - v3, centerX + v3);
        SetFlashScanlineEffectWindowBoundary(dest, centerY + r, centerX - v3, centerX + v3);
        v2 -= (v3 * 2) - 1;
        v3++;
        if (v2 < 0)
        {
            v2 += 2 * (r - 1);
            r--;
        }
    }
}

static void SetOrbFlashScanlineEffectWindowBoundary(u16 *dest, u32 y, s32 left, s32 right)
{
    if (y <= 160)
    {
        if (left < 0)
            left = 0;
        if (left > 240)
            left = 240;
        if (right < 0)
            right = 0;
        if (right > 240)
            right = 240;
        dest[y] = (left << 8) | right;
    }
}

static void SetOrbFlashScanlineEffectWindowBoundaries(u16 *dest, s32 centerX, s32 centerY, s32 radius)
{
    s32 r = radius;
    s32 v2 = radius;
    s32 v3 = 0;
    while (r >= v3)
    {
        SetOrbFlashScanlineEffectWindowBoundary(dest, centerY - v3, centerX - r, centerX + r);
        SetOrbFlashScanlineEffectWindowBoundary(dest, centerY + v3, centerX - r, centerX + r);
        SetOrbFlashScanlineEffectWindowBoundary(dest, centerY - r, centerX - v3, centerX + v3);
        SetOrbFlashScanlineEffectWindowBoundary(dest, centerY + r, centerX - v3, centerX + v3);
        v2 -= (v3 * 2) - 1;
        v3++;
        if (v2 < 0)
        {
            v2 += 2 * (r - 1);
            r--;
        }
    }
}

#define tFlashCenterX        data[1]
#define tFlashCenterY        data[2]
#define tCurFlashRadius      data[3]
#define tDestFlashRadius     data[4]
#define tFlashRadiusDelta    data[5]
#define tClearScanlineEffect data[6]

static void UpdateFlashLevelEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        SetFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 1;
        break;
    case 1:
        SetFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 0;
        tCurFlashRadius += tFlashRadiusDelta;
        if (tCurFlashRadius > tDestFlashRadius)
        {
            if (tClearScanlineEffect == 1)
            {
                ScanlineEffect_Stop();
                tState = 2;
            }
            else
            {
                DestroyTask(taskId);
            }
        }
        break;
    case 2:
        ScanlineEffect_Clear();
        DestroyTask(taskId);
        break;
    }
}

static void UpdateOrbFlashEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        SetOrbFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 1;
        break;
    case 1:
        SetOrbFlashScanlineEffectWindowBoundaries(gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], tFlashCenterX, tFlashCenterY, tCurFlashRadius);
        tState = 0;
        tCurFlashRadius += tFlashRadiusDelta;
        if (tCurFlashRadius > tDestFlashRadius)
        {
            if (tClearScanlineEffect == 1)
            {
                ScanlineEffect_Stop();
                tState = 2;
            }
            else
            {
                DestroyTask(taskId);
            }
        }
        break;
    case 2:
        ScanlineEffect_Clear();
        DestroyTask(taskId);
        break;
    }
}

static void Task_WaitForFlashUpdate(u8 taskId)
{
    if (!FuncIsActiveTask(UpdateFlashLevelEffect))
    {
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}

static void StartWaitForFlashUpdate(void)
{
    if (!FuncIsActiveTask(Task_WaitForFlashUpdate))
        CreateTask(Task_WaitForFlashUpdate, 80);
}

static u8 StartUpdateFlashLevelEffect(s32 centerX, s32 centerY, s32 initialFlashRadius, s32 destFlashRadius, s32 clearScanlineEffect, u8 delta)
{
    u8 taskId = CreateTask(UpdateFlashLevelEffect, 80);
    s16 *data = gTasks[taskId].data;

    tCurFlashRadius = initialFlashRadius;
    tDestFlashRadius = destFlashRadius;
    tFlashCenterX = centerX;
    tFlashCenterY = centerY;
    tClearScanlineEffect = clearScanlineEffect;

    if (initialFlashRadius < destFlashRadius)
        tFlashRadiusDelta = delta;
    else
        tFlashRadiusDelta = -delta;

    return taskId;
}

static u8 StartUpdateOrbFlashEffect(s32 centerX, s32 centerY, s32 initialFlashRadius, s32 destFlashRadius, s32 clearScanlineEffect, u8 delta)
{
    u8 taskId = CreateTask(UpdateOrbFlashEffect, 80);
    s16 *data = gTasks[taskId].data;

    tCurFlashRadius = initialFlashRadius;
    tDestFlashRadius = destFlashRadius;
    tFlashCenterX = centerX;
    tFlashCenterY = centerY;
    tClearScanlineEffect = clearScanlineEffect;

    if (initialFlashRadius < destFlashRadius)
        tFlashRadiusDelta = delta;
    else
        tFlashRadiusDelta = -delta;

    return taskId;
}

#undef tCurFlashRadius
#undef tDestFlashRadius
#undef tFlashRadiusDelta
#undef tClearScanlineEffect

// A higher flashLevel value is a smaller flash radius (more darkness). 0 is full brightness
void AnimateFlash(u8 flashLevel)
{
    u8 curFlashLevel = Overworld_GetFlashLevel();
    bool8 fullBrightness = FALSE;
    if (!flashLevel)
        fullBrightness = TRUE;
    StartUpdateFlashLevelEffect(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, sFlashLevelPixelRadii[curFlashLevel], sFlashLevelPixelRadii[flashLevel], fullBrightness, 1);
    StartWaitForFlashUpdate();
    ScriptContext2_Enable();
}

void WriteFlashScanlineEffectBuffer(u8 flashLevel)
{
    if (flashLevel)
    {
        SetFlashScanlineEffectWindowBoundaries(&gScanlineEffectRegBuffers[0][0], DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, sFlashLevelPixelRadii[flashLevel]);
        CpuFastSet(&gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 480);
    }
}

void WriteBattlePyramidViewScanlineEffectBuffer(void)
{
    SetFlashScanlineEffectWindowBoundaries(&gScanlineEffectRegBuffers[0][0], DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, gSaveBlock2Ptr->frontier.pyramidLightRadius);
    CpuFastSet(&gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 480);
}

static void Task_SpinEnterWarp(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        DoPlayerSpinEntrance();
        gTasks[taskId].tState++;
        break;
    case 1:
        if (WaitForWeatherFadeIn() && IsPlayerSpinEntranceActive() != TRUE)
        {
            FollowMe_WarpSetEnd();
            
            UnfreezeObjectEvents();
            ScriptContext2_Disable();
            DestroyTask(taskId);
        }
        break;
    }
}

static void Task_SpinExitWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        FreezeObjectEvents();
        ScriptContext2_Enable();
        PlaySE(SE_WARP_IN);
        DoPlayerSpinExit();
        task->tState++;
        break;
    case 1:
        if (!IsPlayerSpinExitActive())
        {
            WarpFadeOutScreen();
            task->tState++;
        }
        break;
    case 2:
        if (!PaletteFadeActive() && BGMusicStopped())
            task->tState++;
        break;
    case 3:
        WarpIntoMap();
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
        break;
    }
}

// Only called by an unused function
// DoTeleportTileWarp is used instead
void DoSpinEnterWarp(void)
{
    ScriptContext2_Enable();
    CreateTask(Task_WarpAndLoadMap, 10);
    gFieldCallback = FieldCB_SpinEnterWarp;
}

// Opposite of DoSpinEnterWarp / DoTeleportTileWarp
// Player exits current map by spinning up offscreen, enters new map with a fade in
void DoSpinExitWarp(void)
{
    ScriptContext2_Enable();
    gFieldCallback = FieldCB_DefaultWarpExit;
    CreateTask(Task_SpinExitWarp, 10);
}

static void LoadOrbEffectPalette(bool8 blueOrb)
{
    int i;
    u16 color[1];

    if (!blueOrb)
        color[0] = RGB_RED;
    else
        color[0] = RGB_BLUE;

    for (i = 0; i < 16; i++)
    {
        LoadPalette(color, 0xF0 + i, 2);
    }
}

static bool8 sub_80B02C8(u16 shakeDir)
{
    u8 lo = REG_BLDALPHA & 0xFF;
    u8 hi = REG_BLDALPHA >> 8;

    if (shakeDir != 0)
    {
        if (lo)
        {
            lo--;
        }
    }
    else
    {
        if (hi < 0x10)
        {
            hi++;
        }
    }

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(lo, hi));

    if (lo == 0 && hi == 0x10)
        return TRUE;
    else
        return FALSE;
}

#define tBlueOrb     data[1]
#define tCenterX     data[2]
#define tCenterY     data[3]
#define tShakeDelay  data[4]
#define tShakeDir    data[5]
#define tDispCnt     data[6]
#define tBldCnt      data[7]
#define tBldAlpha    data[8]
#define tWinIn       data[9]
#define tWinOut      data[10]

static void Task_OrbEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        tDispCnt = REG_DISPCNT;
        tBldCnt = REG_BLDCNT;
        tBldAlpha = REG_BLDALPHA;
        tWinIn = REG_WININ;
        tWinOut = REG_WINOUT;
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
        SetGpuRegBits(REG_OFFSET_BLDCNT, gOrbEffectBackgroundLayerFlags[0]);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(12, 7));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
        SetBgTilemapPalette(0, 0, 0, 0x1E, 0x14, 0xF);
        ScheduleBgCopyTilemapToVram(0);
        SetOrbFlashScanlineEffectWindowBoundaries(&gScanlineEffectRegBuffers[0][0], tCenterX, tCenterY, 1);
        CpuFastSet(&gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 480);
        ScanlineEffect_SetParams(sFlashEffectParams);
        tState = 1;
        break;
    case 1:
        sub_8199DF0(0, PIXEL_FILL(1), 0, 1);
        LoadOrbEffectPalette(tBlueOrb);
        StartUpdateOrbFlashEffect(tCenterX, tCenterY, 1, 160, 1, 2);
        tState = 2;
        break;
    case 2:
        if (!FuncIsActiveTask(UpdateOrbFlashEffect))
        {
            EnableBothScriptContexts();
            tState = 3;
        }
        break;
    case 3:
        InstallCameraPanAheadCallback();
        SetCameraPanningCallback(NULL);
        tShakeDir = 0;
        tShakeDelay = 4;
        tState = 4;
        break;
    case 4:
        if (--tShakeDelay == 0)
        {
            s32 panning;
            tShakeDelay = 4;
            tShakeDir ^= 1;
            if (tShakeDir)
                panning = 4;
            else
                panning = -4;
            SetCameraPanning(0, panning);
        }
        break;
    case 6:
        InstallCameraPanAheadCallback();
        tShakeDelay = 8;
        tState = 7;
        break;
    case 7:
        if (--tShakeDelay == 0)
        {
            tShakeDelay = 8;
            tShakeDir ^= 1;
            if (sub_80B02C8(tShakeDir) == TRUE)
            {
                tState = 5;
                sub_8199DF0(0, PIXEL_FILL(0), 0, 1);
            }
        }
        break;
    case 5:
        SetGpuReg(REG_OFFSET_WIN0H, 255);
        SetGpuReg(REG_OFFSET_DISPCNT, tDispCnt);
        SetGpuReg(REG_OFFSET_BLDCNT, tBldCnt);
        SetGpuReg(REG_OFFSET_BLDALPHA, tBldAlpha);
        SetGpuReg(REG_OFFSET_WININ, tWinIn);
        SetGpuReg(REG_OFFSET_WINOUT, tWinOut);
        EnableBothScriptContexts();
        DestroyTask(taskId);
        break;
    }
}

void DoOrbEffect(void)
{
    u8 taskId = CreateTask(Task_OrbEffect, 80);
    s16 *data = gTasks[taskId].data;

    if (gSpecialVar_Result == 0)
    {
        tBlueOrb = FALSE;
        tCenterX = 104;
    }
    else if (gSpecialVar_Result == 1)
    {
        tBlueOrb = TRUE;
        tCenterX = 136;
    }
    else if (gSpecialVar_Result == 2)
    {
        tBlueOrb = FALSE;
        tCenterX = 120;
    }
    else
    {
        tBlueOrb = TRUE;
        tCenterX = 120;
    }

    tCenterY = 80;
}

void FadeOutOrbEffect(void)
{
    u8 taskId = FindTaskIdByFunc(Task_OrbEffect);
    gTasks[taskId].tState = 6;
}

#undef tBlueOrb
#undef tCenterX
#undef tCenterY
#undef tShakeDelay
#undef tShakeDir
#undef tDispCnt
#undef tBldCnt
#undef tBldAlpha
#undef tWinIn
#undef tWinOut

void Script_FadeOutMapMusic(void)
{
    Overworld_FadeOutMapMusic();
    CreateTask(Task_EnableScriptAfterMusicFade, 80);
}

static void Task_EnableScriptAfterMusicFade(u8 taskId)
{
    if (BGMusicStopped() == TRUE)
    {
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

static const u32 sPortal_Gfx[] = INCBIN_U32("graphics/misc/portal.4bpp");
static const u16 sPortal_Pal[] = INCBIN_U16("graphics/misc/portal.gbapal");

#define TAG_PORTAL 0x0100

static const struct SpritePalette sSpritePalette_Portal =
{
    sPortal_Pal, TAG_PORTAL
};

static const struct OamData sOam_Portal =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 3,
};

static const struct SubspriteTable sSubspriteTable_Portal_NorthEastWest =
{
    .subspriteCount = 2,
    .subsprites = (const struct Subsprite[]) {
        {
            .x = 0,
            .y = -16,
            .shape = SPRITE_SHAPE(16x16),
            .size = SPRITE_SIZE(16x16),
            .tileOffset = 0,
            .priority = 1,
        },
        {
            .x = 0,
            .y = 0,
            .shape = SPRITE_SHAPE(16x16),
            .size = SPRITE_SIZE(16x16),
            .tileOffset = 4,
            .priority = 2,
        },
    },
};

static const struct SubspriteTable sSubspriteTable_Portal_South =
{
    .subspriteCount = 2,
    .subsprites = (const struct Subsprite[]) {
        {
            .x = 0,
            .y = -16,
            .shape = SPRITE_SHAPE(16x16),
            .size = SPRITE_SIZE(16x16),
            .tileOffset = 0,
            .priority = 2,
        },
        {
            .x = 0,
            .y = 0,
            .shape = SPRITE_SHAPE(16x16),
            .size = SPRITE_SIZE(16x16),
            .tileOffset = 4,
            .priority = 3,
        },
    },
};

static const struct SpriteFrameImage sPicTable_Portal[] =
{
    overworld_frame(sPortal_Gfx, 2, 4, 0),
    overworld_frame(sPortal_Gfx, 2, 4, 1),
};

static const union AnimCmd sAnim_Portal_OrangeNorth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Portal_BlueNorth[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

enum
{
    ANIM_PORTAL_ORANGE_NORTH,
    ANIM_PORTAL_BLUE_NORTH,
};

static const union AnimCmd *const sAnims_Portal[] =
{
    [ANIM_PORTAL_BLUE_NORTH] = sAnim_Portal_BlueNorth,
    [ANIM_PORTAL_ORANGE_NORTH] = sAnim_Portal_OrangeNorth,
};

static const union AffineAnimCmd sAffineAnim_Portal_0[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Portal_1[] =
{
    AFFINEANIMCMD_FRAME( 0x200,  0x080, 0, 0),
    AFFINEANIMCMD_FRAME(-0x080, +0x040, 0, 2),
    AFFINEANIMCMD_FRAME(-0x040, +0x020, 0, 2),
    AFFINEANIMCMD_FRAME(+0x040, -0x020, 0, 2),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_Portal[] =
{
    sAffineAnim_Portal_0,
    sAffineAnim_Portal_1,
};

static void SpriteCallback_Portal(struct Sprite *sprite);

static const struct SpriteTemplate sSpriteTemplate_Portal =
{
    .tileTag = 0xFFFF,
    .paletteTag = TAG_PORTAL,
    .oam = &sOam_Portal,
    .anims = sAnims_Portal,
    .images = sPicTable_Portal,
    .affineAnims = sAffineAnims_Portal,
    .callback = SpriteCallback_Portal,
};

static void DestroyPortalSprite(struct Sprite *sprite);

struct PixelReader
{
    u32 buffer;
    u32 remaining;
    const u8 *stream;
};

static inline void MakePixelReader(struct PixelReader *pr, const u8 *stream)
{
    pr->buffer = T1_READ_32(stream);
    pr->remaining = 8;
    pr->stream = stream + 4;
}

static inline u32 PopPixelReader(struct PixelReader *pr)
{
    u32 pop = pr->buffer & 0xF;
    pr->buffer >>= 4;
    pr->remaining--;
    return pop;
}

static inline void BufferPixelReader(struct PixelReader *pr, u32 remaining)
{
    while (pr->remaining < remaining)
    {
        pr->buffer |= *pr->stream++ << (4 * pr->remaining);
        pr->remaining += 2;
    }
}

static void SpriteCallback_Portal(struct Sprite *sprite)
{
    s32 left =   gSaveBlock1Ptr->pos.x - 2;
    s32 right =  gSaveBlock1Ptr->pos.x + 17;
    s32 top =    gSaveBlock1Ptr->pos.y;
    s32 bottom = gSaveBlock1Ptr->pos.y + 16;

    if (sprite->data[0] < left
     || sprite->data[0] > right
     || sprite->data[1] < top
     || sprite->data[1] > bottom
     || !gSaveBlock1Ptr->portals[sprite->data[2]].active)
    {
        DestroyPortalSprite(sprite);
    }
    else
    {
        SetSpritePosToMapCoords(sprite->data[0], sprite->data[1], &sprite->pos1.x, &sprite->pos1.y);

        // Update the portal pixels.
        if (!sprite->data[3] && sprite->animEnded)
        {
            s32 i;
            const u16 *rom4s = (const u16 *)((uintptr_t)sPicTable_Portal[sprite->data[2]].data + TILE_OFFSET_4BPP(2));
            u16 *vram4s = (u16 *)(OBJ_VRAM0 + TILE_OFFSET_4BPP(sprite->oam.tileNum + 2));
            u16 rom4, vram4;
            struct PixelReader pr;
            MakePixelReader(&pr, gSaveBlock1Ptr->portals[1 - sprite->data[2]].pixels);
            for (i = 0; i < 6 * TILE_SIZE_4BPP / 2; i++)
            {
                BufferPixelReader(&pr, 4);
                rom4 = rom4s[i];

                if ((rom4 & 0x000F) == 0x000F)
                    vram4 = PopPixelReader(&pr);
                else
                    vram4 = rom4 & 0x000F;

                if ((rom4 & 0x00F0) == 0x00F0)
                    vram4 |= PopPixelReader(&pr) << 4;
                else
                    vram4 |= rom4 & 0x00F0;

                if ((rom4 & 0x0F00) == 0x0F00)
                    vram4 |= PopPixelReader(&pr) << 8;
                else
                    vram4 |= rom4 & 0x0F00;

                if ((rom4 & 0xF000) == 0xF000)
                    vram4 |= PopPixelReader(&pr) << 12;
                else
                    vram4 |= rom4 & 0xF000;

                vram4s[i] = vram4;
            }
            sprite->data[3] = TRUE;
        }
    }
}

static void DestroyPortalSprite(struct Sprite *sprite)
{
    s32 i, n;
    for (i = n = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].callback == SpriteCallback_Portal)
        {
            n++;
            if (n > 1)
            {
                DestroySprite(sprite);
                return;
            }
        }
    }
    DestroySpriteAndFreeResources(sprite);
}

static u32 CreatePortalSprite(u32 id, s32 x, s32 y)
{
    const struct Portal *portal;
    u32 spriteId;
    struct Sprite *sprite;

    portal = &gSaveBlock1Ptr->portals[id];

    for (spriteId = 0; spriteId < MAX_SPRITES; spriteId++)
    {
        if (gSprites[spriteId].callback == SpriteCallback_Portal
         && gSprites[spriteId].data[2] == id)
        {
            sprite = &gSprites[spriteId];
            break;
        }
    }

    if (spriteId == MAX_SPRITES)
    {
        LoadSpritePalette(&sSpritePalette_Portal);
        spriteId = CreateSprite(&sSpriteTemplate_Portal, 0, 0, 255);
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        SetSpritePosToMapCoords(x, y, &sprite->pos1.x, &sprite->pos1.y);
        sprite->pos2.x = -8;
        sprite->pos2.y = -8;

        // TODO: Graphics/animation for each direction.
        StartSpriteAnimIfDifferent(sprite, ANIM_PORTAL_ORANGE_NORTH + id);

        switch (gSaveBlock1Ptr->portals[id].direction)
        {
        case DIR_NORTH:
        default:
            SetSubspriteTables(sprite, &sSubspriteTable_Portal_NorthEastWest);
            break;
        case DIR_SOUTH:
            SetSubspriteTables(sprite, &sSubspriteTable_Portal_South);
            break;
        }

        sprite->data[2] = id;
    }

    sprite->data[0] = x;
    sprite->data[1] = y;

    return spriteId;
}

void CreatePortalSprites(void)
{
    s32 i, j;
    s32 left =   gSaveBlock1Ptr->pos.x - 2;
    s32 right =  gSaveBlock1Ptr->pos.x + 17;
    s32 top =    gSaveBlock1Ptr->pos.y;
    s32 bottom = gSaveBlock1Ptr->pos.y + 16;

    for (i = 0; i < PORTAL_COUNT; i++)
    {
        s32 x = INT_MAX, y = INT_MAX;

        const struct Portal *portal = &gSaveBlock1Ptr->portals[i];
        if (!portal->active)
            continue;

        if (portal->mapGroup == gSaveBlock1Ptr->location.mapGroup
         && portal->mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            x = portal->x;
            y = portal->y;
        }

        for (j = 0; j < gMapHeader.connections->count; j++)
        {
            const struct MapConnection *connection = &gMapHeader.connections->connections[j];
            if (portal->mapGroup == connection->mapGroup
             && portal->mapNum == connection->mapNum)
            {
                const struct MapLayout *connectedLayout = GetMapHeaderFromConnection(connection)->mapLayout;
                if (connection->direction == CONNECTION_SOUTH)
                {
                    x = connection->offset + portal->x;
                    y = gMapHeader.mapLayout->height + portal->y;
                }
                else if (connection->direction == CONNECTION_NORTH)
                {
                    x = connection->offset + portal->x;
                    y = -connectedLayout->height + portal->y;
                }
                else if (connection->direction == CONNECTION_WEST)
                {
                    x = -connectedLayout->width + portal->x;
                    y = connection->offset + portal->y;
                }
                else if (connection->direction == CONNECTION_EAST)
                {
                    x = gMapHeader.mapLayout->width + portal->x;
                    y = connection->offset + portal->y;
                }
            }
        }

        if (left <= x && x <= right && top <= y && y <= bottom)
            CreatePortalSprite(i, x, y);
    }
}

struct PixelWriter
{
    bool8 buffered;
    u8 *stream;
};

static inline void MakePixelWriter(struct PixelWriter *pw, u8 *stream)
{
    pw->buffered = FALSE;
    pw->stream = stream;
}

static inline void PushPixelWriter(struct PixelWriter *pw, u32 push)
{
    if (pw->buffered)
    {
        *pw->stream |= push << 4;
        pw->stream++;
        pw->buffered = FALSE;
    }
    else
    {
        *pw->stream = push;
        pw->buffered = TRUE;
    }
}

struct LumaPalettes
{
    u8 offset;
    u16 cached;
    u8 palettes[256];
};

static inline void MakeLumaPalettes(struct LumaPalettes *lp, u32 offset)
{
    lp->offset = offset;
    lp->cached = 0;
}

static const u8 *GetLumaPalette(struct LumaPalettes *lp, u32 palette)
{
    if (!(lp->cached & (1 << palette)))
    {
        s32 i;
        lp->cached |= (1 << palette);
        for (i = 1; i < 16; i++)
        {
            u32 color = gPlttBufferUnfaded[palette * 16 + i];
            u32 r, g, b, l;
            r = GET_R(color);
            g = GET_G(color);
            b = GET_B(color);
            // TODO: There's probably a faster formula for this given we
            // only have 7 steps.
            l = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;
            l = min(l >> 2, 6);
            lp->palettes[palette * 16 + i] = lp->offset + l;
        }
    }

    return &lp->palettes[palette * 16];
}

static void GetMetatileEntriesAt(u16 *entries, s32 x, s32 y)
{
    s32 i;
    u32 metatileId = MapGridGetMetatileIdAt(x, y);
    const u16 *metatileEntries;

    if (metatileId < NUM_METATILES_IN_PRIMARY)
        metatileEntries = gMapHeader.mapLayout->primaryTileset->metatiles + metatileId * 3 * 4;
    else
        metatileEntries = gMapHeader.mapLayout->secondaryTileset->metatiles + (metatileId - NUM_METATILES_IN_PRIMARY) * 3 * 4;

    entries[0] = metatileEntries[0];
    entries[3] = metatileEntries[1];
    entries[6] = metatileEntries[2];
    entries[9] = metatileEntries[3];

    entries[1] = metatileEntries[4];
    entries[4] = metatileEntries[5];
    entries[7] = metatileEntries[6];
    entries[10] = metatileEntries[7];

    entries[2] = metatileEntries[8];
    entries[5] = metatileEntries[9];
    entries[8] = metatileEntries[10];
    entries[11] = metatileEntries[11];
}

static inline u16 hFlip(const u16 *_4s, u32 i, bool32 hFlip)
{
    if (!hFlip)
    {
        return _4s[i];
    }
    else
    {
        u16 _4 = _4s[i ^ 1];
        return ((_4 & 0x000F) << 12)
             | ((_4 & 0x00F0) << 4)
             | ((_4 & 0x0F00) >> 4)
             | (_4 >> 12);
    }
}

// XXX: Assumes triple-layer metatiles.
static void DoCapturePortalSprite(u32 id, s32 x, s32 y, bool32 capture)
{
    s32 i, j;

    if (capture)
    {
        // Fill active portals with the pixels underneath, shifted to
        // their color.
        struct PixelWriter pw;
        struct LumaPalettes lp;
        u16 entries[2 * 3 * 4];
        GetMetatileEntriesAt(&entries[0], x, y - 1);
        GetMetatileEntriesAt(&entries[12], x, y);
        MakePixelWriter(&pw, gSaveBlock1Ptr->portals[id].pixels);
        MakeLumaPalettes(&lp, id == PORTAL_ORANGE ? 0x8 : 0x1);
        for (i = 2; i < 8; i++)
        {
            const u16 *rom4s = (const u16 *)((uintptr_t)sPicTable_Portal[id].data + TILE_OFFSET_4BPP(i));
            const u8 *botLuma = GetLumaPalette(&lp, entries[i * 3] >> 12);
            const u16 *bot4s = (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(entries[i * 3] & 0x03FF));
            bool32 botH = !!(entries[i * 3] & 0x0400);
            const u8 *midLuma = GetLumaPalette(&lp, entries[i * 3 + 1] >> 12);
            const u16 *mid4s = (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(entries[i * 3 + 1] & 0x03FF));
            bool32 midH = !!(entries[i * 3 + 1] & 0x0400);
            const u8 *topLuma = GetLumaPalette(&lp, entries[i * 3 + 2] >> 12);
            const u16 *top4s = (u16 *)(BG_VRAM + TILE_OFFSET_4BPP(entries[i * 3 + 2] & 0x03FF));
            bool32 topH = !!(entries[i * 3 + 2] & 0x0400);
            u16 rom4, bot4, mid4, top4;

            for (j = 0; j < TILE_SIZE_4BPP / 2; j++)
            {
                rom4 = rom4s[j];
                bot4 = hFlip(bot4s, j, botH);
                mid4 = hFlip(mid4s, j, midH);
                top4 = hFlip(top4s, j, topH);
                if ((rom4 & 0x000F) == 0x000F)
                {
                    if (top4 & 0x000F)
                        PushPixelWriter(&pw, topLuma[top4 & 0x000F]);
                    else if (mid4 & 0x000F)
                        PushPixelWriter(&pw, midLuma[mid4 & 0x000F]);
                    else
                        PushPixelWriter(&pw, botLuma[bot4 & 0x000F]);
                }

                if (((rom4 >> 4) & 0x000F) == 0x000F)
                {
                    if ((top4 >> 4) & 0x000F)
                        PushPixelWriter(&pw, topLuma[(top4 >> 4) & 0x000F]);
                    else if ((mid4 >> 4) & 0x000F)
                        PushPixelWriter(&pw, midLuma[(mid4 >> 4) & 0x000F]);
                    else
                        PushPixelWriter(&pw, botLuma[(bot4 >> 4) & 0x000F]);
                }

                if (((rom4 >> 8) & 0x000F) == 0x000F)
                {
                    if ((top4 >> 8) & 0x000F)
                        PushPixelWriter(&pw, topLuma[(top4 >> 8) & 0x000F]);
                    else if ((mid4 >> 8) & 0x000F)
                        PushPixelWriter(&pw, midLuma[(mid4 >> 8) & 0x000F]);
                    else
                        PushPixelWriter(&pw, botLuma[(bot4 >> 8) & 0x000F]);
                }

                if (((rom4 >> 12) & 0x000F) == 0x000F)
                {
                    if ((top4 >> 12) & 0x000F)
                        PushPixelWriter(&pw, topLuma[(top4 >> 12) & 0x000F]);
                    else if ((mid4 >> 12) & 0x000F)
                        PushPixelWriter(&pw, midLuma[(mid4 >> 12) & 0x000F]);
                    else
                        PushPixelWriter(&pw, botLuma[(bot4 >> 12) & 0x000F]);
                }
            }
        }
    }
    else
    {
        // Fill inactive portals with the opposite's darkest color.
        memset(gSaveBlock1Ptr->portals[id].pixels, id == PORTAL_ORANGE ? 0x11 : 0x88, sizeof(gSaveBlock1Ptr->portals[id].pixels));
    }

    // Trigger the other portal to update (if necessary).
    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].callback == SpriteCallback_Portal
         && gSprites[i].data[2] != id)
        {
            gSprites[i].data[3] = FALSE;
        }
    }
}

static void Task_WaitForPortalAnim(u8 taskId);

void DoCreatePortal(const struct MapPosition *position, u8 direction, u32 id)
{
    s32 i, x, y, dx, dy;
    struct Portal *portal = &gSaveBlock1Ptr->portals[id];
    const struct MapConnection *connection;

    x = position->x;
    y = position->y;
    switch (direction)
    {
    case DIR_NORTH: dx =  0; dy = -1; break;
    case DIR_EAST:  dx =  1; dy =  0; break;
    case DIR_SOUTH: dx =  0; dy =  1; break;
    case DIR_WEST:  dx = -1; dy =  0; break;
    }

    portal->active = FALSE;
    for (i = 0; i < 7; i++)
    {
        x += dx;
        y += dy;
        if (MapGridIsImpassableAt(x, y))
        {
            portal->active = TRUE;
            portal->direction = direction;
            if ((connection = GetConnectionAtCoords(x, y)))
            {
                const struct MapLayout *connectedLayout = GetMapHeaderFromConnection(connection)->mapLayout;
                portal->mapGroup = connection->mapGroup;
                portal->mapNum = connection->mapNum;
                switch (connection->direction)
                {
                case CONNECTION_SOUTH:
                    portal->x = -connection->offset + x;
                    portal->y = -gMapHeader.mapLayout->height + y;
                    break;
                case CONNECTION_NORTH:
                    portal->x = -connection->offset + x;
                    portal->y = connectedLayout->height + y;
                    break;
                case CONNECTION_WEST:
                    portal->x = connectedLayout->width + portal->x;
                    portal->y = -connection->offset + portal->y;
                    break;
                case CONNECTION_EAST:
                    portal->x = -gMapHeader.mapLayout->width + x;
                    portal->y = -connection->offset + y;
                    break;
                }
            }
            else
            {
                portal->mapGroup = gSaveBlock1Ptr->location.mapGroup;
                portal->mapNum = gSaveBlock1Ptr->location.mapNum;
                portal->x = x;
                portal->y = y;
            }
            break;
        }
    }

    if (portal->active)
    {
        for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->portals); i++)
        {
            if (i != id
             && gSaveBlock1Ptr->portals[i].active
             && portal->mapGroup == gSaveBlock1Ptr->portals[i].mapGroup
             && portal->mapNum == gSaveBlock1Ptr->portals[i].mapNum
             && portal->x == gSaveBlock1Ptr->portals[i].x
             && portal->y == gSaveBlock1Ptr->portals[i].y)
            {
                portal->active = FALSE;
                break;
            }
        }
    }

    // HINT: Could 'x - dx, y - dy' to capture the metatile that will be
    // walked on, but that doesn't look very good.
    DoCapturePortalSprite(id, x, y, portal->active);
    if (portal->active)
    {
        u32 taskId, spriteId;
        spriteId = CreatePortalSprite(id, x, y);
        StartSpriteAffineAnim(&gSprites[spriteId], 1);
        PlaySE(SE_PIN);
        taskId = CreateTask(Task_WaitForPortalAnim, 0);
        gTasks[taskId].data[0] = spriteId;
    }
    else
    {
        PlaySE(SE_BOO);
        EnableBothScriptContexts();
    }
}

static void Task_WaitForPortalAnim(u8 taskId)
{
    struct Sprite *sprite = &gSprites[gTasks[taskId].data[0]];
    if (sprite->affineAnimEnded)
    {
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}

static void FieldCB_PortalWarpExit(void);

static void Task_DoPortalWarp(u8 taskId)
{
    s32 i;
    struct Task *task = &gTasks[taskId];
    const struct Portal *from = &gSaveBlock1Ptr->portals[task->data[1]];
    const struct Portal *to = &gSaveBlock1Ptr->portals[task->data[2]];
    u32 objEventId;
    switch (task->tState)
    {
    case 0:
        FreezeObjectEvents();
        objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
        switch (from->direction)
        {
        case DIR_NORTH:
        case DIR_EAST:
        case DIR_WEST:
            gObjectEvents[objEventId].fixedPriority = TRUE;
            gSprites[gObjectEvents[objEventId].spriteId].oam.priority = 1;
            break;
        }
        gSprites[gObjectEvents[objEventId].spriteId].subspriteTableNum = 0;
        ObjectEventClearHeldMovementIfActive(&gObjectEvents[objEventId]);
        ObjectEventSetHeldMovement(&gObjectEvents[objEventId], GetWalkNormalMovementAction(from->direction));
        task->data[3] = 16;
        task->tState = 1;
    case 1:
        if (--task->data[3] == 0)
        {
            UnfreezeObjectEvents();
            task->tState = 2;
        }
        break;
    case 2:
        // TODO: Different warp if in range.
        SetDynamicWarpWithCoords(0x7F, to->mapGroup, to->mapNum, -1, to->x - 7, to->y - 7);
        SetWarpDestinationToDynamicWarp(0x7F);
        TryFadeOutOldMapMusic();
        FadeScreen(FADE_TO_WHITE, 8);
        PlayRainStoppingSoundEffect();
        gFieldCallback = FieldCB_PortalWarpExit;
        for (i = 0; i < MAX_SPRITES; i++)
        {
            // Prevent portal sprites from moving during the warp
            // sequence.
            if (gSprites[i].callback == SpriteCallback_Portal)
                gSprites[i].callback = SpriteCallbackDummy;
        }
        task->func = Task_WarpAndLoadMap;
        break;
    }
}

void DoPortalWarp(u32 from, u32 to)
{
    u8 taskId;

    taskId = CreateTask(Task_DoPortalWarp, 10);
    gTasks[taskId].data[1] = from;
    gTasks[taskId].data[2] = to;
}

static void Task_ExitPortal(u8 taskId)
{
    s32 i;
    u32 objEventId;
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
        PlayerGetDestCoords(&task->data[1], &task->data[2]);
        for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->portals); i++)
        {
            if (gSaveBlock1Ptr->portals[i].active
             && gSaveBlock1Ptr->portals[i].mapGroup == gSaveBlock1Ptr->location.mapGroup
             && gSaveBlock1Ptr->portals[i].mapNum == gSaveBlock1Ptr->location.mapNum
             && gSaveBlock1Ptr->portals[i].x == task->data[1]
             && gSaveBlock1Ptr->portals[i].y == task->data[2])
            {
                task->data[3] = GetOppositeDirection(gSaveBlock1Ptr->portals[i].direction);
                break;
            }
        }
        switch (gSaveBlock1Ptr->portals[i].direction)
        {
        case DIR_NORTH:
        case DIR_EAST:
        case DIR_WEST:
            gObjectEvents[objEventId].fixedPriority = TRUE;
            gSprites[gObjectEvents[objEventId].spriteId].oam.priority = 1;
            break;
        }
        gSprites[gObjectEvents[objEventId].spriteId].subspriteTableNum = 0;
        SetPlayerVisibility(TRUE);
        FreezeObjectEvents();
        PlayerFaceDirection(task->data[3]);
        task->tState = 1;
        break;
    case 1:
        if (WaitForWeatherFadeIn())
        {
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfActive(&gObjectEvents[objEventId]);
            ObjectEventSetHeldMovement(&gObjectEvents[objEventId], GetWalkNormalMovementAction(task->data[3]));
            task->tState = 2;
        }
        break;
    case 2:
        if (IsPlayerStandingStill())
        {
            objEventId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            gObjectEvents[objEventId].fixedPriority = FALSE;
            SetObjectSubpriorityByZCoord(gObjectEvents[objEventId].previousElevation, &gSprites[gObjectEvents[objEventId].spriteId], 1);
            UnfreezeObjectEvents();
            task->tState = 3;
        }
        break;
    case 3:
        ScriptContext2_Disable();
        DestroyTask(taskId);
        break;
    }
}

static void FieldCB_PortalWarpExit(void)
{
    Overworld_PlaySpecialMapMusic();
    FadeInFromWhite();
    CreateTask(Task_ExitPortal, 10);
    PlaySE(SE_WARP_IN);
    ScriptContext2_Enable();
}

void ClearPortalSprites(void)
{
    DoCapturePortalSprite(PORTAL_ORANGE, 0, 0, FALSE);
    DoCapturePortalSprite(PORTAL_BLUE, 0, 0, FALSE);
}
