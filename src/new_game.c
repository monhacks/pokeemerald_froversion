#include "global.h"
#include "new_game.h"
#include "random.h"
#include "pokemon.h"
#include "roamer.h"
#include "pokemon_size_record.h"
#include "script.h"
#include "lottery_corner.h"
#include "play_time.h"
#include "mauville_old_man.h"
#include "match_call.h"
#include "lilycove_lady.h"
#include "load_save.h"
#include "pokeblock.h"
#include "dewford_trend.h"
#include "berry.h"
#include "rtc.h"
#include "easy_chat.h"
#include "event_data.h"
#include "money.h"
#include "trainer_hill.h"
#include "tv.h"
#include "coins.h"
#include "text.h"
#include "overworld.h"
#include "mail.h"
#include "battle_records.h"
#include "item.h"
#include "pokedex.h"
#include "apprentice.h"
#include "frontier_util.h"
#include "constants/maps.h"
#include "pokedex.h"
#include "save.h"
#include "link_rfu.h"
#include "main.h"
#include "contest.h"
#include "item_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_jump.h"
#include "decoration_inventory.h"
#include "secret_base.h"
#include "player_pc.h"
#include "field_specials.h"
#include "berry_powder.h"
#include "mevent.h"
#include "union_room_chat.h"
#include "field_player_avatar.h"
#include "outfit_menu.h"

extern const u8 EventScript_ResetAllMapFlags[];
extern const u8 EventScript_ClearDiaryFlags[];

// this file's functions
static void ClearFrontierRecord(void);
static void WarpToTruck(void);
static void ResetMiniGamesResults(void);
static void ResetOutfitData(void);

// EWRAM vars
EWRAM_DATA bool8 gDifferentSaveFile = FALSE;
EWRAM_DATA bool8 gEnableContestDebugging = FALSE;

// const rom data
static const struct ContestWinner sContestWinnerPicDummy =
{
    .monName = _(""),
    .trainerName = _("")
};

// code
void SetTrainerId(u32 trainerId, u8 *dst)
{
    dst[0] = trainerId;
    dst[1] = trainerId >> 8;
    dst[2] = trainerId >> 16;
    dst[3] = trainerId >> 24;
}

u32 GetTrainerId(u8 *trainerId)
{
    return (trainerId[3] << 24) | (trainerId[2] << 16) | (trainerId[1] << 8) | (trainerId[0]);
}

void CopyTrainerId(u8 *dst, u8 *src)
{
    s32 i;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        dst[i] = src[i];
}

static void InitPlayerTrainerId(void)
{
    u32 trainerId = (Random() << 0x10) | GetGeneratedTrainerIdLower();
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
}

// L=A isnt set here for some reason.
static void SetDefaultOptions(void)
{
    gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_FAST;
    gSaveBlock2Ptr->optionsWindowFrameType = 0;
    gSaveBlock2Ptr->optionsSound = OPTIONS_SOUND_MONO;
    gSaveBlock2Ptr->optionsBattleStyle = OPTIONS_BATTLE_STYLE_SHIFT;
    gSaveBlock2Ptr->optionsBattleSceneOff = FALSE;
    gSaveBlock2Ptr->regionMapZoom = FALSE;
    gSaveBlock2Ptr->optionsWindowDifficulty = OPTIONS_DIFFICULTY_NORMAL;
}

static void ClearPokedexFlags(void)
{
    gUnusedPokedexU8 = 0;
    memset(&gSaveBlock2Ptr->pokedex.owned, 0, sizeof(gSaveBlock2Ptr->pokedex.owned));
    memset(&gSaveBlock2Ptr->pokedex.seen, 0, sizeof(gSaveBlock2Ptr->pokedex.seen));
}

void ClearAllContestWinnerPics(void)
{
    s32 i;

    ClearContestWinnerPicsInContestHall();
    for (i = 8; i < 13; i++)
        gSaveBlock1Ptr->contestWinners[i] = sContestWinnerPicDummy;
}

static void ClearFrontierRecord(void)
{
    CpuFill32(0, &gSaveBlock2Ptr->frontier, sizeof(gSaveBlock2Ptr->frontier));

    gSaveBlock2Ptr->frontier.opponentNames[0][0] = EOS;
    gSaveBlock2Ptr->frontier.opponentNames[1][0] = EOS;
}

static void WarpToTruck(void)
{
    if(B_VERSION_FRO)
    {
        SetWarpDestination(MAP_GROUP(LAKE_MEAD_VILLAGE_FROS_HOUSE_1F), MAP_NUM(LAKE_MEAD_VILLAGE_FROS_HOUSE_1F), -1, 4, 5);
        WarpIntoMap();
    }
    if(B_VERSION_MAGM6)
    {
        //u16 i;
        // AddBagItem(ITEM_HYPER_POTION, 10);
        // AddBagItem(ITEM_REVIVE, 20);
        // AddBagItem(ITEM_MAX_REVIVE, 10);
        // AddBagItem(ITEM_SUPER_POTION, 20);
        // AddBagItem(ITEM_X_ATTACK, 7);
        // AddBagItem(ITEM_X_SP_ATK, 7);
        // AddBagItem(ITEM_X_SP_DEF, 7);
        // AddBagItem(ITEM_X_DEFENSE, 7);
        // AddBagItem(ITEM_DIRE_HIT, 7);
        // AddBagItem(ITEM_FULL_RESTORE, 5);
        // AddBagItem(ITEM_LEFTOVERS, 5);
        // AddBagItem(ITEM_SITRUS_BERRY, 5);
        // AddBagItem(ITEM_WEAKNESS_POLICY, 1);
        // AddBagItem(ITEM_ASSAULT_VEST, 1);
        // AddBagItem(ITEM_DRAGON_CAMOUFLAGE, 1);
        // AddBagItem(ITEM_LIFE_ORB, 1);
        // AddBagItem(ITEM_CHOICE_BAND, 1);
        // AddBagItem(ITEM_CHOICE_SPECS, 1);
        // for (i = ITEM_TM01; i <= ITEM_TM50; i++)
        //     {
        //         if(!CheckBagHasItem(i, 1))
        //         AddBagItem(i, 1);
        //     }
        SetWarpDestination(MAP_GROUP(CINNIBAR_ISLAND), MAP_NUM(CINNIBAR_ISLAND), -1, 62, 53);
        WarpIntoMap();
    }
    if(B_VERSION_MARRIOTT)
        {
            SetWarpDestination(MAP_GROUP(MARRIOTT_INTRO_FRAME1), MAP_NUM(MARRIOTT_INTRO_FRAME1), -1, 7, 5);
            WarpIntoMap();
        }
    if(B_VERSION_MAGEE)
        {
            FlagSet(FLAG_MAGEE_VERSION);
            VarSet(VAR_MAGEE_VERSION, 1);
            SetWarpDestination(MAP_GROUP(MAGM8PROTAGONISTS_HOUSE), MAP_NUM(MAGM8PROTAGONISTS_HOUSE), -1, 5, 6);
            WarpIntoMap();
            gSaveBlock1Ptr->mapLocChar1 = gSaveBlock1Ptr->location;
            gSaveBlock1Ptr->mapLocChar2 = gSaveBlock1Ptr->location;
            gSaveBlock1Ptr->mapLocChar3 = gSaveBlock1Ptr->location;
        }
}

static void ResetOutfitData(void)
{
    memset(gSaveBlock2Ptr->outfits, 0, sizeof(gSaveBlock2Ptr->outfits));
    UnlockOutfit(DEFAULT_OUTFIT);
    gSaveBlock2Ptr->currOutfitId = DEFAULT_OUTFIT;
}

void Sav2_ClearSetDefault(void)
{
    ClearSav2();
    SetDefaultOptions();
    ResetOutfitData();
}

void ResetMenuAndMonGlobals(void)
{
    gDifferentSaveFile = 0;
    ResetPokedexScrollPositions();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetBagScrollPositions();
    ResetPokeblockScrollPositions();
}

void NewGameInitData(void)
{
    if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
        RtcReset();

    gDifferentSaveFile = 1;
    gSaveBlock2Ptr->encryptionKey = 0;
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetPokedex();
    ClearFrontierRecord();
    ClearSav1();
    ClearMailData();
    gSaveBlock2Ptr->specialSaveWarpFlags = 0;
    gSaveBlock2Ptr->gcnLinkFlags = 0;
    InitPlayerTrainerId();
    PlayTimeCounter_Reset();
    ClearPokedexFlags();
    InitEventData();
    ClearTVShowData();
    ResetGabbyAndTy();
    ClearSecretBases();
    ClearBerryTrees();
    if(B_VERSION_MARRIOTT)
        SetMoney(&gSaveBlock1Ptr->money, 50000);
    if(B_VERSION_MAGEE)
        SetMoney(&gSaveBlock1Ptr->money, 100);
    else
        SetMoney(&gSaveBlock1Ptr->money, 3000);
    SetCoins(0);
    ResetLinkContestBoolean();
    ResetGameStats();
    ClearAllContestWinnerPics();
    ClearPlayerLinkBattleRecords();
    InitSeedotSizeRecord();
    InitLotadSizeRecord();
    gPlayerPartyCount = 0;
    ZeroPlayerPartyMons();
    ResetPokemonStorageSystem();
    ClearRoamerData();
    ClearRoamerLocationData();
    gSaveBlock1Ptr->registeredItem = 0;
    ClearBag();
    NewGameInitPCItems();
    ClearPokeblocks();
    ClearDecorationInventories();
    InitEasyChatPhrases();
    SetMauvilleOldMan();
    InitDewfordTrend();
    ResetFanClub();
    ResetLotteryCorner();
    WarpToTruck();
    ScriptContext2_RunNewScript(EventScript_ResetAllMapFlags);
    if (B_VERSION_MAGEE)
        ScriptContext2_RunNewScript(EventScript_ClearDiaryFlags);
    ResetMiniGamesResults();
    InitUnionRoomChatRegisteredTexts();
    InitLilycoveLady();
    ResetAllApprenticeData();
    ClearRankingHallRecords();
    InitMatchCallCounters();
    sub_801AFD8();
    WipeTrainerNameRecords();
    ResetTrainerHillResults();
    ResetContestLinkResults();
    ResetOutfitData();

    memset(&gSaveBlock2Ptr->itemFlags, 0, sizeof(gSaveBlock2Ptr->itemFlags));
    gSaveBlock1Ptr->activeChar = 0;
    if(B_VERSION_MARRIOTT)
        gSaveBlock2Ptr->expShare = 1;
    else
        gSaveBlock2Ptr->expShare = 0;
    memset(&gSaveBlock2Ptr->follower, 0, sizeof(gSaveBlock2Ptr->follower));
}

static void ResetMiniGamesResults(void)
{
    CpuFill16(0, &gSaveBlock2Ptr->berryCrush, sizeof(struct BerryCrush));
    SetBerryPowder(&gSaveBlock2Ptr->berryCrush.berryPowderAmount, 0);
    ResetPokeJumpResults();
    CpuFill16(0, &gSaveBlock2Ptr->berryPick, sizeof(struct BerryPickingResults));
}
