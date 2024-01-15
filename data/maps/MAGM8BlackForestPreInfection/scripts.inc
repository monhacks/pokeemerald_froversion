MAGM8BlackForestPreInfection_MapScripts::
	.byte 0


MAGM8BlackForestPreInfection_EventScript_PreventLeaving::
	lock
	msgbox MAGM8BlackForestPreInfection_Text_PreventLeaving, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	release
	end

MAGM8BlackForestPreInfection_Text_PreventLeaving:
	.string "{PLAYER} is feeling tired.\p"
	.string "Let's call it a night.$"
	