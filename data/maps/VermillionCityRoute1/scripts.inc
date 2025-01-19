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

VermillionCityRoute1_EventScript_TrainerEvan::
	msgbox VermillionCityRoute1_Text_TrainerEvan, MSGBOX_NPC
	end

VermillionCityRoute1_EventScript_PicnickerLila::
	msgbox VermillionCityRoute1_Text_PicnickerLila, MSGBOX_NPC
	end

VermillionCityRoute1_Text_TrainerEvan:
	.string "This route is so peaceful!\n"
	.string "The salty breeze from Salt Lake City\l"
	.string "makes it a nice place to relax.\p"
	.string "Have you seen the wild Pokémon here?\n"
	.string "They're quite friendly and fun to watch!$"

VermillionCityRoute1_Text_PicnickerLila:
	.string "I love having picnics on this route!\n"
	.string "The scenery is just so beautiful.\p"
	.string "Sometimes, I spot wild Pokémon\n"
	.string "playing near the trees. It's magical!$"

VermillionCityRoute1_Text_IShouldntGoInTallGrass:
	.string "{PLAYER}: I shouldn't go in the tall\n"
	.string "without a Pokémon.$"


