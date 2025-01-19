.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_GRUNT_3, 3
.set LOCALID_WILD_POKEMON_1, 4

VermillionCityRoute2_MapScripts::
	.byte 0

VermillionCityRoute2_EventScript_WildPokemonAttacks::
	lockall
		playbgm MUS_FV_TEAM_MAGA, 0
		call VermillionCityRoute2_EventScript_SetWildPokemonXY
		msgbox VermillionCityRoute2_Text_ReturnToHQ MSGBOX_DEFAULT
		applymovement LOCALID_GRUNT_2, VermillionCityRoute2_Movement_GruntsLeave
		applymovement LOCALID_GRUNT_3, VermillionCityRoute2_Movement_GruntsLeave
		waitmovement LOCALID_GRUNT_2
		removeobject LOCALID_GRUNT_2
		removeobject LOCALID_GRUNT_3
		setflag FLAG_HIDE_ROUTE_2_MAGA_GRUNT_2
		applymovement OBJ_EVENT_ID_PLAYER, VermillionCityRoute2_Movement_PlayerAttemptsToFollow
		waitmovement OBJ_EVENT_ID_PLAYER
		addobject LOCALID_WILD_POKEMON_1
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
		waitmovement OBJ_EVENT_ID_PLAYER
		playse SE_WALL_HIT
		waitse
		msgbox VermillionCityRoute2_Text_OuchThatHurt, MSGBOX_AUTOCLOSE
		applymovement LOCALID_WILD_POKEMON_1, Common_Movement_WalkInPlaceFastestLeft
		waitmovement LOCALID_WILD_POKEMON_1
		playse SE_WALL_HIT
		waitse
		applymovement LOCALID_WILD_POKEMON_1, Common_Movement_WalkInPlaceFastestLeft
		waitmovement LOCALID_WILD_POKEMON_1
		playse SE_WALL_HIT
		waitse
		msgbox VermillionCityRoute2_Text_StopThat, MSGBOX_AUTOCLOSE
		setvar VAR_MAGEE_VERSION, 4
		warpsilent MAP_VERMILLION_CITY_MATTS_HOUSE, 255, 1, 4												
	releaseall
	end 


VermillionCityRoute2_EventScript_SetWildPokemonXY:
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	setobjectxyperm LOCALID_WILD_POKEMON_1, 11, VAR_TEMP_2
	return

VermillionCityRoute2_EventScript_GruntStopsPlayerFromLeaving::
	lockall
		compare VAR_MAGEE_VERSION, 3
		goto_if_ge	VermillionCityRoute2_EventScript_GruntStopsPlayerFromLeavingEnd
		applymovement LOCALID_GRUNT_1, Common_Movement_ExclamationMark
		waitmovement LOCALID_GRUNT_1
		msgbox VermillionCityRoute2_Text_TeamMAGAIsWaitingAtPleasureFactory, MSGBOX_DEFAULT
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
		waitmovement OBJ_EVENT_ID_PLAYER
			VermillionCityRoute2_EventScript_GruntStopsPlayerFromLeavingEnd:
				compare VAR_MAGEE_VERSION, 3
				goto_if_ne VermillionCityRoute2_EventScript_NoPokemonInParty
	releaseall
	end
	
VermillionCityRoute2_EventScript_NoPokemonInParty:
	compare VAR_MAGEE_VERSION, 6
	goto_if_ge VermillionCityRoute2_EventScript_NoPokemonInPartyEnd
	msgbox VermillionCityRoute1_Text_IShouldntGoInTallGrass, MSGBOX_AUTOCLOSE
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
		waitmovement OBJ_EVENT_ID_PLAYER
	VermillionCityRoute2_EventScript_NoPokemonInPartyEnd:
	releaseall
	end
	

VermillionCityRoute2_EventScript_Grunt::
	lockall
		msgbox VermillionCityRoute2_Text_TeamMAGAIsWaitingAtPleasureFactory, MSGBOX_NPC
	releaseall
	end

VermillionCityRoute2_EventScript_Barb::
	trainerbattle_single TRAINER_BARB, Route2_Text_BarbIntro, Route102_Text_BarbDefeated
	msgbox Route2_Text_BarbPostBattle, MSGBOX_AUTOCLOSE
	end


RivertonVermillionCityRoute2_EventScript_Finn::
	trainerbattle_single TRAINER_FINN, VermillionCityRoute2_Text_FinnIntro, VermillionCityRoute2_Text_FinnDefeated
	msgbox VermillionCityRoute2_Text_FinnPostBattle, MSGBOX_AUTOCLOSE
	end



VermillionCityRoute2_Movement_GruntsLeave:
	walk_right
	walk_right
	walk_right
	step_end


VermillionCityRoute2_Movement_PlayerAttemptsToFollow:
	walk_right
	step_end

VermillionCityRoute2_Text_TeamMAGAIsWaitingAtPleasureFactory:
	.string "Hey!\p"
	.string "You need to go back to your Pleasure\n"
	.string "Factory at once!\p"
	.string "We are waiting for you there!$"

VermillionCityRoute2_Text_ReturnToHQ:
	.string "Grunt 1: We need to return to\n"
	.string "headquarters at once.\p"
	.string "The boss is waiting for us to\n"
	.string "begin the experiments on Metagross!\p"
	.string "Grunt 2: I know, better get moving!\n"
	.string "The equipment for Metagross is\l"
	.string "already prepped and ready to go!$"

VermillionCityRoute2_Text_OuchThatHurt:
	.string "{PLAYER}: Ouch!\p"
	.string "That hurt!$"

VermillionCityRoute2_Text_StopThat:
	.string "Stop that. I need...\p"
	.string "to get...\p"
	.string "Meta...\p"
	.string "...\p"
	.string "...gross\p"
	.string "...\p"
	.string "...\p"
	.string "The wild Azumarill knocked {PLAYER}\n"
	.string "out.$"

VermillionCityRoute2_Text_FinnIntro:
	.string "Hey, landlubber! Think you can\n"
	.string "handle a battle on the high seas?\p"
	.string "The salty breeze and crashing\n"
	.string "waves are my home! Let's fight!$"

VermillionCityRoute2_Text_FinnDefeated:
	.string "Argh, looks like I got swept away!$"

VermillionCityRoute2_Text_FinnPostBattle:
	.string "You're tough, landlubber. Maybe\n"
	.string "you'll sail far on your journey.$"
