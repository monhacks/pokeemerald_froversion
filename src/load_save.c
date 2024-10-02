#include "global.h"
#include "malloc.h"
#include "berry_powder.h"
#include "item.h"
#include "load_save.h"
#include "main.h"
#include "overworld.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "save_location.h"
#include "trainer_hill.h"
#include "gba/flash_internal.h"
#include "decoration_inventory.h"
#include "agb_flash.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "string_util.h"
#include "event_data.h"
#include "constants/items.h"
#include "field_player_avatar.h"
static void ApplyNewEncryptionKeyToAllEncryptedData(u32 encryptionKey);

#define SAVEBLOCK_MOVE_RANGE    128

struct LoadedSaveData
{
    struct Bag bag;
    struct MailStruct mail[MAIL_COUNT];
};

// EWRAM DATA
EWRAM_DATA struct SaveBlock2 gSaveblock2 = {0};
EWRAM_DATA u8 gSaveblock2_DMA[SAVEBLOCK_MOVE_RANGE] = {0};

EWRAM_DATA struct SaveBlock1 gSaveblock1 = {0};
EWRAM_DATA u8 gSaveblock1_DMA[SAVEBLOCK_MOVE_RANGE] = {0};

EWRAM_DATA struct PokemonStorage gPokemonStorage = {0};
EWRAM_DATA u8 gSaveblock3_DMA[SAVEBLOCK_MOVE_RANGE] = {0};

EWRAM_DATA struct LoadedSaveData gLoadedSaveData = {0};
EWRAM_DATA u32 gLastEncryptionKey = 0;

// IWRAM common
bool32 gFlashMemoryPresent;
struct SaveBlock1 *gSaveBlock1Ptr;
struct SaveBlock2 *gSaveBlock2Ptr;
struct PokemonStorage *gPokemonStoragePtr;

// code
void CheckForFlashMemory(void)
{
    if (!IdentifyFlash())
    {
        gFlashMemoryPresent = TRUE;
        InitFlashTimer();
    }
    else
    {
        gFlashMemoryPresent = FALSE;
    }
}

void ClearSav2(void)
{
    CpuFill16(0, &gSaveblock2, sizeof(struct SaveBlock2) + sizeof(gSaveblock2_DMA));
}

void ClearSav1(void)
{
    CpuFill16(0, &gSaveblock1, sizeof(struct SaveBlock1) + sizeof(gSaveblock1_DMA));
}

void SetSaveBlocksPointers(u16 offset)
{
    struct SaveBlock1** sav1_LocalVar = &gSaveBlock1Ptr;

    offset = (offset + Random()) & (SAVEBLOCK_MOVE_RANGE - 4);

    gSaveBlock2Ptr = (void*)(&gSaveblock2) + offset;
    *sav1_LocalVar = (void*)(&gSaveblock1) + offset;
    gPokemonStoragePtr = (void*)(&gPokemonStorage) + offset;

    SetDecorationInventoriesPointers();
}

void MoveSaveBlocks_ResetHeap(void)
{
    void *vblankCB, *hblankCB;
    u32 encryptionKey;
    struct SaveBlock2 *saveBlock2Copy;
    struct SaveBlock1 *saveBlock1Copy;
    struct PokemonStorage *pokemonStorageCopy;

    // save interrupt functions and turn them off
    vblankCB = gMain.vblankCallback;
    hblankCB = gMain.hblankCallback;
    gMain.vblankCallback = NULL;
    gMain.hblankCallback = NULL;
    gTrainerHillVBlankCounter = NULL;

    saveBlock2Copy = (struct SaveBlock2 *)(gHeap);
    saveBlock1Copy = (struct SaveBlock1 *)(gHeap + sizeof(struct SaveBlock2));
    pokemonStorageCopy = (struct PokemonStorage *)(gHeap + sizeof(struct SaveBlock2) + sizeof(struct SaveBlock1));

    // backup the saves.
    *saveBlock2Copy = *gSaveBlock2Ptr;
    *saveBlock1Copy = *gSaveBlock1Ptr;
    *pokemonStorageCopy = *gPokemonStoragePtr;

    // change saveblocks' pointers
    // argument is a sum of the individual trainerId bytes
    SetSaveBlocksPointers(
      saveBlock2Copy->playerTrainerId[0] +
      saveBlock2Copy->playerTrainerId[1] +
      saveBlock2Copy->playerTrainerId[2] +
      saveBlock2Copy->playerTrainerId[3]);

    // restore saveblock data since the pointers changed
    *gSaveBlock2Ptr = *saveBlock2Copy;
    *gSaveBlock1Ptr = *saveBlock1Copy;
    *gPokemonStoragePtr = *pokemonStorageCopy;

    // SetBagItemsPointers references 'gSaveBlock1Ptr->activeChar' so
    // wait until the saveblock has been restored rather than calling it
    // in 'SetSaveBlocksPointers'.
    SetBagItemsPointers();

    // heap was destroyed in the copying process, so reset it
    InitHeap(gHeap, HEAP_SIZE);

    // restore interrupt functions
    gMain.hblankCallback = hblankCB;
    gMain.vblankCallback = vblankCB;

    // create a new encryption key
    encryptionKey = (Random() << 0x10) + (Random());
    ApplyNewEncryptionKeyToAllEncryptedData(encryptionKey);
    gSaveBlock2Ptr->encryptionKey = encryptionKey;
}

u32 UseContinueGameWarp(void)
{
    return gSaveBlock2Ptr->specialSaveWarpFlags & CONTINUE_GAME_WARP;
}

void ClearContinueGameWarpStatus(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags &= ~CONTINUE_GAME_WARP;
}

void SetContinueGameWarpStatus(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags |= CONTINUE_GAME_WARP;
}

void SetContinueGameWarpStatusToDynamicWarp(void)
{
    SetContinueGameWarpToDynamicWarp(0);
    gSaveBlock2Ptr->specialSaveWarpFlags |= CONTINUE_GAME_WARP;
}

void ClearContinueGameWarpStatus2(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags &= ~CONTINUE_GAME_WARP;
}

void SavePlayerParty(void)
{
    int i;

    gSaveBlock1Ptr->playerPartyCount = gPlayerPartyCount;
    switch (gSaveBlock1Ptr->activeChar)
    {
    case 0:
        for (i = 0; i < PARTY_SIZE; i++)
        gSaveBlock1Ptr->playerParty[i] = gPlayerParty[i];
        break;
    
    case 1:
        for (i = 0; i < PARTY_SIZE; i++)
        gSaveBlock1Ptr->playerPartyChar2[i] = gPlayerParty[i];
        break;

    case 2:
        for (i = 0; i < PARTY_SIZE; i++)
        gSaveBlock1Ptr->playerPartyChar3[i] = gPlayerParty[i];
        break;

    default:
        break;
    }
}

void LoadPlayerParty(void)
{
    int i;

    gPlayerPartyCount = gSaveBlock1Ptr->playerPartyCount;

    switch (gSaveBlock1Ptr->activeChar)
    {
    case 0:
        for (i = 0; i < PARTY_SIZE; i++)
        gPlayerParty[i] = gSaveBlock1Ptr->playerParty[i];
        break;
    
    case 1:
    for (i = 0; i < PARTY_SIZE; i++)
        gPlayerParty[i] = gSaveBlock1Ptr->playerPartyChar2[i];
        break;

    case 2:
    for (i = 0; i < PARTY_SIZE; i++)
        gPlayerParty[i] = gSaveBlock1Ptr->playerPartyChar3[i];
        break;

    default:
        break;
    }
}

void SaveObjectEvents(void)
{
    int i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        gSaveBlock1Ptr->objectEvents[i] = gObjectEvents[i];
}

void LoadObjectEvents(void)
{
    int i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        gObjectEvents[i] = gSaveBlock1Ptr->objectEvents[i];
}

void SaveSerializedGame(void)
{
    SavePlayerParty();
    SaveObjectEvents();
}

void LoadSerializedGame(void)
{
    LoadPlayerParty();
    LoadObjectEvents();
}

void LoadPlayerBag(void)
{
    int i;

    gLoadedSaveData.bag = gSaveBlock1Ptr->bags[gSaveBlock1Ptr->activeChar];

    // load mail.
    for (i = 0; i < MAIL_COUNT; i++)
        gLoadedSaveData.mail[i] = gSaveBlock1Ptr->mail[i];

    gLastEncryptionKey = gSaveBlock2Ptr->encryptionKey;
}

static void SetBagItemQuantity(u16 *quantity, u16 newValue)
{
    *quantity =  newValue ^ gSaveBlock2Ptr->encryptionKey;
}

// TODO: Should this apply to all characters?
void ResetPlayerBag(void)
{
    u8 pocket, slot;
    struct BagPocket *itemPocket;

    // Iterate through each pocket in the bag
    for (pocket = 0; pocket < POCKETS_COUNT; pocket++)
    {
        itemPocket = &gBagPockets[pocket];

        // Iterate through each slot in the current pocket
        for (slot = 0; slot < itemPocket->capacity; slot++)
        {
            // Set the item ID to ITEM_NONE and quantity to 0
            itemPocket->itemSlots[slot].itemId = ITEM_NONE;
            SetBagItemQuantity(&itemPocket->itemSlots[slot].quantity, 0);
        }
    }
}

void SavePlayerBag(void)
{
    int i;
    u32 encryptionKeyBackup;

    gSaveBlock1Ptr->bags[gSaveBlock1Ptr->activeChar] = gLoadedSaveData.bag;

    // save mail.
    for (i = 0; i < MAIL_COUNT; i++)
        gSaveBlock1Ptr->mail[i] = gLoadedSaveData.mail[i];

    encryptionKeyBackup = gSaveBlock2Ptr->encryptionKey;
    gSaveBlock2Ptr->encryptionKey = gLastEncryptionKey;
    ApplyNewEncryptionKeyToBagItems(encryptionKeyBackup);
    gSaveBlock2Ptr->encryptionKey = encryptionKeyBackup; // updated twice?
}

void ApplyNewEncryptionKeyToHword(u16 *hWord, u32 newKey)
{
    *hWord ^= gSaveBlock2Ptr->encryptionKey;
    *hWord ^= newKey;
}

void ApplyNewEncryptionKeyToWord(u32 *word, u32 newKey)
{
    *word ^= gSaveBlock2Ptr->encryptionKey;
    *word ^= newKey;
}

static void ApplyNewEncryptionKeyToAllEncryptedData(u32 encryptionKey)
{
    ApplyNewEncryptionKeyToGameStats(encryptionKey);
    ApplyNewEncryptionKeyToBagItems_(encryptionKey);
    ApplyNewEncryptionKeyToBerryPowder(encryptionKey);
    ApplyNewEncryptionKeyToWord(&gSaveBlock1Ptr->money, encryptionKey);
    ApplyNewEncryptionKeyToHword(&gSaveBlock1Ptr->coins, encryptionKey);
}

void SaveCharLocation(void)
{
    s16 x;
    s16 y;
    s32 z;

    u16 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u16 mapNum = gSaveBlock1Ptr->location.mapNum;

    x = gSaveBlock1Ptr->pos.x;
    y = gSaveBlock1Ptr->pos.y;
    z = PlayerGetZCoord();

switch (gSaveBlock1Ptr->activeChar)
{
    case 0:
        gSaveBlock1Ptr->mapLocChar1.mapGroup = mapGroup;
        gSaveBlock1Ptr->mapLocChar1.mapNum = mapNum;
        gSaveBlock1Ptr->mapLocChar1.x = x;
        gSaveBlock1Ptr->mapLocChar1.y = y;
        break;

    case 1:
        gSaveBlock1Ptr->mapLocChar2.mapGroup = mapGroup;
        gSaveBlock1Ptr->mapLocChar2.mapNum = mapNum;
        gSaveBlock1Ptr->mapLocChar2.x = x;
        gSaveBlock1Ptr->mapLocChar2.y = y;
        break;

    case 2:
        gSaveBlock1Ptr->mapLocChar3.mapGroup = mapGroup;
        gSaveBlock1Ptr->mapLocChar3.mapNum = mapNum;
        gSaveBlock1Ptr->mapLocChar3.x = x;
        gSaveBlock1Ptr->mapLocChar3.y = y;
        break;

    default:
        break;
}

}

void SwitchCharacter(void)
{
    struct Pokemon *recvpokemon = &gEnemyParty[0];
    struct Pokemon *storepokemon = &gEnemyParty[1];
    struct BoxPokemon *storeboxmon = &storepokemon->box;

    SaveCharLocation();

    switch(gSaveBlock1Ptr->activeChar)
    {
        case 0:
            ZeroBoxMonAt(0, 0);
            ZeroBoxMonAt(0, 1);
            CopyMon(storepokemon, &gPlayerParty[0], sizeof(*storepokemon));
            SetBoxMonAt(0, 0, &storepokemon->box);
            CopyMon(storepokemon, &gPlayerParty[1], sizeof(*storepokemon));
            SetBoxMonAt(0, 1, &storepokemon->box);
            ZeroPlayerPartyMons();
            BoxMonAtToMon(0, 2, recvpokemon);
            CopyMon(&gPlayerParty[0], recvpokemon, sizeof(gPlayerParty[0]));  
            BoxMonAtToMon(0, 3, recvpokemon);
            CopyMon(&gPlayerParty[1], recvpokemon, sizeof(gPlayerParty[1]));            
            ZeroBoxMonAt(0, 2);
            ZeroBoxMonAt(0, 3);
            gSaveBlock1Ptr->activeChar = 1;
            gSaveBlock2Ptr->currOutfitId = 2;
            break;

        case 1:
            ZeroBoxMonAt(0, 2);
            ZeroBoxMonAt(0, 3);
            CopyMon(storepokemon, &gPlayerParty[0], sizeof(*storepokemon));
            SetBoxMonAt(0, 2, &storepokemon->box);
            CopyMon(storepokemon, &gPlayerParty[1], sizeof(*storepokemon));
            SetBoxMonAt(0, 3, &storepokemon->box);
            ZeroPlayerPartyMons();
            BoxMonAtToMon(0, 4, recvpokemon);
            CopyMon(&gPlayerParty[0], recvpokemon, sizeof(gPlayerParty[0]));  
            BoxMonAtToMon(0, 5, recvpokemon);
            CopyMon(&gPlayerParty[1], recvpokemon, sizeof(gPlayerParty[1]));            
            ZeroBoxMonAt(0, 4);
            ZeroBoxMonAt(0, 5);
            gSaveBlock1Ptr->activeChar = 2;
            break;

        case 2:
            ZeroBoxMonAt(0, 4);
            ZeroBoxMonAt(0, 5);
            CopyMon(storepokemon, &gPlayerParty[0], sizeof(*storepokemon));
            SetBoxMonAt(0, 4, &storepokemon->box);
            CopyMon(storepokemon, &gPlayerParty[1], sizeof(*storepokemon));
            SetBoxMonAt(0, 5, &storepokemon->box);
            ZeroPlayerPartyMons();
            BoxMonAtToMon(0, 0, recvpokemon);
            CopyMon(&gPlayerParty[0], recvpokemon, sizeof(gPlayerParty[0]));  
            BoxMonAtToMon(0, 1, recvpokemon);
            CopyMon(&gPlayerParty[1], recvpokemon, sizeof(gPlayerParty[1]));            
            ZeroBoxMonAt(0, 0);
            ZeroBoxMonAt(0, 1);
            gSaveBlock1Ptr->activeChar = 0;
            gSaveBlock2Ptr->currOutfitId = 1;
            break;

        default:
            gSaveBlock1Ptr->activeChar = 0;
            break;
    }

    SetBagItemsPointers();
    ConvertIntToDecimalStringN(gStringVar1, gSaveBlock1Ptr->activeChar, STR_CONV_MODE_LEADING_ZEROS, 2);        //TODO Replace with name at some point
    SetWarpDestinationToCharLocation();    
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
}

void GetActiveChar(void)
{
    gSpecialVar_Result = gSaveBlock1Ptr->activeChar;
}
