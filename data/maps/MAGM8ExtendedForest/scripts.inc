MAGM8ExtendedForest_MapScripts::
	.byte 0

MAGM8ExtendedForest_Eventscript_GiveUp::
	lock
	setvar VAR_TEMP_0, 1
	msgbox MAGM8ExtendedForest_Text_GiveUp, MSGBOX_DEFAULT
	waitmessage
	fadescreen FADE_TO_BLACK
	delay 16
	special GameClear
	waitstate
	releaseall
	end

MAGM8ExtendedForest_Text_GiveUp::
	.string "You hear Professor Gooseberry's\n"
	.string "voice in the distance...\p"
	.string "The forest will absorb anything.$"

Movement_Delay:
	delay_16
	step_end