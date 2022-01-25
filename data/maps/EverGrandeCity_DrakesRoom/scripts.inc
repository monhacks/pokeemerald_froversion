EverGrandeCity_DrakesRoom_MapScripts:: @ 822869C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp: @ 82286AC
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth:: @ 82286B6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame: @ 82286BB
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor:: @ 82286C5
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad: @ 82286D2
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	compare VAR_ELITE_4_STATE, 4
	call_if_eq EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom:: @ 82286E7
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor:: @ 82286ED
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake:: @ 82286F3
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_DrakesRoom_EventScript_DrakePostGame
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech:: @ 822871A
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated:: @ 8228724
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech: @ 822873E
	.string "I am the last of the Pokémon League\n"
	.string "Elite Four, Michael the Psychic master!\p"
	.string "In their natural state, Pokémon are\n"
	.string "wild living things. They are free.\p"
	.string "At times, they hinder us.\n"
	.string "At times, they help us.\p"
	.string "For us to battle with Pokémon as\n"
	.string "partners, do you know what it takes?\p"
	.string "Do you know what is needed?\p"
	.string "If you don't, then you will never\n"
	.string "prevail over me!$"

EverGrandeCity_DrakesRoom_Text_Defeat: @ 8228895
	.string "Superb, it should be said.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech: @ 82288B0
	.string "You deserve every credit for coming\n"
	.string "this far as a Trainer of Pokémon.\p"
	.string "You do seem to know what is needed.\p"
	.string "Yes, what a Trainer needs is a\n"
	.string "virtuous heart.\p"
	.string "Pokémon touch the good hearts of\n"
	.string "Trainers and learn good from wrong.\p"
	.string "They touch the good hearts of\n"
	.string "Trainers and grow strong.\p"
	.string "Go! Go onwards!\n"
	.string "The Champion is waiting!$"

EverGrandeCity_DrakesRoom_EventScript_DrakePostGame:
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeechPostGame, MSGBOX_DEFAULT
	setflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_FORCE_BATTLE_STYLE_SET
	compare VAR_ELITE_4_REMATCH_STATE, 1
	goto_if_eq EverGrandeCity_DrakesRoom_EventScript_DrakeBattle2
	compare VAR_ELITE_4_REMATCH_STATE, 2
	goto_if_eq EverGrandeCity_DrakesRoom_EventScript_DrakeBattle3
	compare VAR_ELITE_4_REMATCH_STATE, 2
	goto_if_gt EverGrandeCity_DrakesRoom_EventScript_DrakeBattle4
	trainerbattle_no_intro TRAINER_DRAKE_REMATCH, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedPostGame
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeBattle2:
	trainerbattle_no_intro TRAINER_DRAKE_REMATCH_2, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedPostGame
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeBattle3:
	trainerbattle_no_intro TRAINER_DRAKE_REMATCH_3, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedPostGame
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeBattle4:
	trainerbattle_no_intro TRAINER_DRAKE_REMATCH_4, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_DefeatedPostGame
	end

EverGrandeCity_DrakesRoom_EventScript_DefeatedPostGame:: @ 8227F95
	addvar VAR_ELITE_4_REMATCH_STATE, 1
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	goto_if_set FLAG_RECEIVED_LEFT_LEG, EverGrandeCity_DrakesRoom_EventScript_DefeatedPostGameNoPackage
	compare VAR_ELITE_4_REMATCH_STATE, 4
	goto_if_lt EverGrandeCity_DrakesRoom_EventScript_DefeatedPostGameNoPackage
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeechPostGamePackage, MSGBOX_DEFAULT
	giveitem ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE, 1
	setflag FLAG_RECEIVED_LEFT_LEG
	fadescreen FADE_TO_BLACK
	warpsilent MAP_LAKE_MEAD_VILLAGE, 255, 11, 14
	release
	end

EverGrandeCity_DrakesRoom_EventScript_DefeatedPostGameNoPackage::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeechPostGameNoPackage, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	warpsilent MAP_LAKE_MEAD_VILLAGE, 255, 11, 14
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeechPostGame: @ 8227FA7
	.string "Welcome, champion!\n"
	.string "You miss 100 percent of the\l"
	.string "Shots you don't take!$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeechPostGamePackage: @ 82280EC
	.string "My motivational words work\n"
	.string "wonders!\p"
	.string "You are a true Champion!\p"
	.string "Come back anytime you want to\n"
	.string "battle for fun!\p"
	.string "Oh yea, I almost forgot,\n"
	.string "you recieved a package!$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeechPostGameNoPackage: @ 82280EC
	.string "My motivational words work\n"
	.string "wonders!\p"
	.string "You are a true Champion!\p"
	.string "Come back anytime you want to\n"
	.string "battle for fun!$"
