#ifndef GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_AI_SCRIPT_COMMANDS_H

// return values for BattleAI_ChooseMoveOrAction
// 0 - 3 are move idx
#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5
#define AI_CHOICE_SWITCH 7

s32 AI_CalcDamage(u16 move, u8 battlerAtk, u8 battlerDef);
s32 AI_CalcPartyMonDamage(u16 move, u8 battlerAtk, u8 battlerDef, struct Pokemon *mon);
u16 AI_GetTypeEffectiveness(u16 move, u8 battlerAtk, u8 battlerDef);
void BattleAI_SetupItems(void);
void BattleAI_SetupFlags(void);
void BattleAI_SetupAIData(u8 defaultScoreMoves);
u8 BattleAI_ChooseMoveOrAction(void);
bool32 IsTruantMonVulnerable(u32 battlerAI, u32 opposingBattler);
bool32 IsBattlerAIControlled(u32 battlerId);
void ClearBattlerMoveHistory(u8 battlerId);
void RecordLastUsedMoveBy(u32 battlerId, u32 move);
void RecordKnownMove(u8 battlerId, u32 move);
void RecordAbilityBattle(u8 battlerId, u16 abilityId);
void ClearBattlerAbilityHistory(u8 battlerId);
void RecordItemEffectBattle(u8 battlerId, u8 itemEffect);
void ClearBattlerItemEffectHistory(u8 battlerId);
bool32 IsSpeciesOneOf(u16 specie, const u16 *species);
bool32 IsItemOneOf(u16 item, const u16 *item1);
extern const u16 gRuthlashLine[];
extern const u16 gMechobraLine[];
extern const u16 gRiptorypsLine[];
extern const u16 gMegaBosses[];
extern const u16 gLevitateMons[];
extern const u16 gSelfInflictingItems[];
extern const u16 gCheetoSecondaryItems[];
extern const u16 gAriadosBossSecondaryItems[];
extern const u16 gNonStealItems[];
extern const u16 gWildPokemonDropItems[];
extern const u16 gWildPokemonRareDropItems[];
extern const u16 gNonOrganicItems[];
extern const u16 gMetagrossMetamorphForms[];
extern const u16 gMovePoolTypeCheck[];


#endif // GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
