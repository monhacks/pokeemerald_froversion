MarriottIntroFrame1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MarriottIntroFrame1_OnFrame
	.byte 0

MarriottIntroFrame1_OnFrame:
	map_script_2 VAR_TEMP_0, 0, MAGM8ExtendedForest_Eventscript_GiveUpClear
	.2byte 0

MarriottIntroFrame1_EventScript_MarriottStudies:
	lock
	delay 16
	msgbox MarriottIntroFrame1_Text_MarriottStudies, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	warpsilent MAP_MARRIOTT_INTRO_FRAME2, 255, 7, 5 
	release
end

MAGM8ExtendedForest_Eventscript_GiveUpClear::
lock
	delay 16
	setvar VAR_TEMP_0, 1
	msgbox MAGM8ExtendedForest_Text_GiveUp, MSGBOX_DEFAULT
	waitmessage
	special GameClear
	waitstate
	releaseall
	end


@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''
MarriottIntroFrame1_Text_MarriottStudies:
	.string "Since he was little, Marriot Dreamed\n"
	.string "of being a successful lawyer.\p"
	.string "At the ripe age of 10, while his\n"
	.string "friends were busy playing he was\l"
	.string "hard at work, studying for the Bar\l"
	.string "exams!$"

