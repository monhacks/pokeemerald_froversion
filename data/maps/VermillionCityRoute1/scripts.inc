VermillionCityRoute1_MapScripts::
	.byte 0


VermillionCityRoute1_EventScript_StopPlayerFromGoingInRightGrassTriggerCheck::
		compare VAR_MAGEE_VERSION, 5
		goto_if_le VermillionCityRoute1_EventScript_StopPlayerFromGoingInRightGrass
		releaseall
	end
		
		
VermillionCityRoute1_EventScript_StopPlayerFromGoingInRightGrass:
	lockall
		msgbox VermillionCityRoute1_Text_IShouldntGoInTallGrass, MSGBOX_AUTOCLOSE
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
		waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

VermillionCityRoute1_EventScript_StopPlayerFromGoingInNorthGrassTriggerCheck::
		compare VAR_MAGEE_VERSION, 5
		goto_if_le VermillionCityRoute1_EventScript_StopPlayerFromGoingInNorthGrass
		releaseall
	end
		
		
VermillionCityRoute1_EventScript_StopPlayerFromGoingInNorthGrass:
	lockall
		msgbox VermillionCityRoute1_Text_IShouldntGoInTallGrass, MSGBOX_AUTOCLOSE
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
		waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

VermillionCityRoute1_Text_IShouldntGoInTallGrass:
	.string "{PLAYER}: I shouldn't go in the tall\n"
	.string "without a Pokémon.$"
