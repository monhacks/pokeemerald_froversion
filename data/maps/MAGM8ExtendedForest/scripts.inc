MAGM8ExtendedForest_MapScripts::
	.byte 0

MAGM8ExtendedForest_Eventscript_GiveUp::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Delay
	waitmovement OBJ_EVENT_ID_PLAYER
	warpsilent MAP_MARRIOTT_INTRO_FRAME1, 255, 7, 5 
	end

MAGM8ExtendedForest_Text_GiveUp::
	.string "You hear Professor Gooseberry's\n"
	.string "voice in the distance...\p"
	.string "The forest will absorb anything.$"

Movement_Delay:
	delay_16
	step_end