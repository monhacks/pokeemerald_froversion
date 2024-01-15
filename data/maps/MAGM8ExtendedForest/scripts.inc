MAGM8ExtendedForest_MapScripts::
	.byte 0

MAGM8ExtendedForest_Eventscript_GiveUp::
	msgbox MAGM8ExtendedForest_Text_GiveUp, MSGBOX_DEFAULT
	waitmessage
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	waitstate
	releaseall
	end

MAGM8ExtendedForest_Text_GiveUp::
.string "Welcome to LILYCOVE DEPARTMENT STORE.\p"
	.string "You hear Professor Gooseberry's\n"
	.string "voice in the distance...\p"
	.string "The forest will absorb anything.$"