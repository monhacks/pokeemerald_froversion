MAGM8ForestTownPostInfection_MapScripts::
	.byte 0


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
