VerdanturfTown_House_MapScripts:: @ 820335E
	.byte 0

VerdanturfTown_House_EventScript_Woman1:: @ 820335F
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_Woman2:: @ 8203368
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_NPC
	end

VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague: @ 8203371
	.string "Far away, deep in Scranton,\n"
	.string "is the Pokémon League.\p"
	.string "The Trainers who gather there are\n"
	.string "all frighteningly well skilled.$"

VerdanturfTown_House_Text_DefeatEliteFourInARow: @ 82033EE
	.string "In the Pokémon League, I think the\n"
	.string "rules say that you have to battle the\l"
	.string "Elite Four all in a row.\p"
	.string "If you lose to any of them, you have\n"
	.string "to begin your challenge again from the\l"
	.string "first one.$"

VerdanturfTown_House_EventScript_Trader:: @ 8264FED
	lock
	faceplayer
	goto_if_set FLAG_VERDANTURF_TRADE_DONE, VerdanturfTown_House_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_CHANSEY
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox VerdanturfTown_House_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VerdanturfTown_House_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq VerdanturfTown_House_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne VerdanturfTown_House_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox VerdanturfTown_House_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_VERDANTURF_TRADE_DONE
	release
	end

VerdanturfTown_House_EventScript_TradeCompleted:: @ 8265083
	msgbox VerdanturfTown_House_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_House_EventScript_DeclineTrade:: @ 826506B
	msgbox VerdanturfTown_House_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_House_EventScript_NotRequestedMon:: @ 8265075
	bufferspeciesname 0, VAR_0x8009
	msgbox VerdanturfTown_House_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_House_Text_WouldYouLikeToTrade:
	.string "I am a big Yu-Gi-Oh fan!\p"
	.string "Do you happen to have a Cloclock?\n"
	.string "If you do I could trade you this\l"
	.string "Chansey and a Yu-Gi-Oh card!$"

VerdanturfTown_House_Text_SkittySoMuchCuterThanImagined:
	.string "Hot tits! This Cloclock is off\n"
	.string "the chain!$"

VerdanturfTown_House_Text_WellThatsFineToo:
	.string "Whatever, jerk!$"

VerdanturfTown_House_Text_DontTradeForAnythingButMon:
	.string "That isn't a Cloclock!$"


VerdanturfTown_House_Text_PromiseIllBeGoodToIt:
	.string "Take good care of my Healy!!!$"
	
