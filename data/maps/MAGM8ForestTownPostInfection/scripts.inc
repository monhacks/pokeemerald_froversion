MAGM8ForestTownPostInfection_MapScripts::
	.byte 0

MAGM8ForestTownPostInfection_EventScript_CaptainGreg::
	lockall
		compare VAR_INFECTED_WOODS_STATE, 1
		goto_if_ge MAGM8ForestTownPostInfection_EventScript_SailorReturnToVermillion
		msgbox MAGM8BlackForestPostInfection_Text_ThisPlaceSureIsSpooky, MSGBOX_NPC
	releaseall
	end

MAGM8ForestTownPostInfection_EventScript_SailorReturnToVermillion:
	msgbox CinnabarIsland_Text_SailorReturnToVermillion, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MAGM8ForestTownPostInfection_EventScript_SailorReturnToVermillionNo
	case YES, MAGM8ForestTownPostInfection_EventScript_SailorReturnToVermillionYes
	case MULTI_B_PRESSED, MAGM8ForestTownPostInfection_EventScript_SailorReturnToVermillionNo

MAGM8ForestTownPostInfection_EventScript_SailorReturnToVermillionNo:
	msgbox CinnabarIsland_Text_OkayLetMeKnowWhen,MSGBOX_DEFAULT
	releaseall
	end

MAGM8ForestTownPostInfection_EventScript_SailorReturnToVermillionYes:
lockall
	msgbox Riverton_Text_AlrightLetsGo, MSGBOX_AUTOCLOSE
		applymovement 2, MAGM8ForestTownPostInfection_Movement_CaptainEnterBoat1
		waitmovement 2
		applymovement OBJ_EVENT_ID_PLAYER, MAGM8ForestTownPostInfection_Movement_PlayerEnterBoat
		waitmovement OBJ_EVENT_ID_PLAYER
		hideobjectat OBJ_EVENT_ID_PLAYER, 0
		applymovement 2, MAGM8ForestTownPostInfection_Movement_CaptainEnterBoat2
		waitmovement 2
		removeobject 2
		applymovement 1, Common_Movement_WalkLeft
		waitmovement 1
		warpsilent MAP_VERMILLION_CITY_HARBOR, 255, 56, 14
	releaseall
	end

MAGM8ForestTownPostInfection_Movement_CaptainEnterBoat1:
	walk_down
	walk_right
	face_left
	step_end
	
MAGM8ForestTownPostInfection_Movement_CaptainEnterBoat2:
	walk_left
	walk_down
	step_end


MAGM8ForestTownPostInfection_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	step_end


MAGM8ForestTownPostInfection_EventScript_StopPlayerFromLeaving::
	lockall
		msgbox MAGM8BlackForestPostInfection_Text_StopPlayerFromLeaving, MSGBOX_AUTOCLOSE
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
		waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

MAGM8BlackForestPostInfection_Text_StopPlayerFromLeaving:
	.string "This path leads back to the ocean\n"
	.string "and is not safe!$"

MAGM8BlackForestPostInfection_Text_ThisPlaceSureIsSpooky:	
	.string "Land ho! This place sure is spooky.\n"
	.string "I wonder what team MAGA is doing\l"
	.string "here.\p"
	.string "I don't see any of those filthy\n"
	.string "landlubbers around.\p"
	.string "In fact I don't see anyone around.\n"
	.string "Be careful out there, {PLAYER}.$"
