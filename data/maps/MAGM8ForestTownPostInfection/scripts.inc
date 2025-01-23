MAGM8ForestTownPostInfection_MapScripts::
	.byte 0

MAGM8ForestTownPostInfection_EventScript_CaptainGreg::
	lockall
		msgbox MAGM8BlackForestPostInfection_Text_ThisPlaceSureIsSpooky, MSGBOX_NPC
	releaseall
	end



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
