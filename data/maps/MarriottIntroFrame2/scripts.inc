MarriottIntroFrame2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MarriottIntroFrame2_OnFrame
	.byte 0

MarriottIntroFrame2_OnFrame:
	map_script_2 VAR_TEMP_0, 0, MarriottIntroFrame2_EventScript_MarriottStudies
	.2byte 0

MarriottIntroFrame2_EventScript_MarriottStudies:
	lock
	delay 16
	msgbox MarriottIntroFrame2_Text_MarriottStudies, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	warpsilent MAP_MARRIOTT_INTRO_FRAME3, 255, 7, 5 
	release
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''
MarriottIntroFrame2_Text_MarriottStudies:
	.string "Everything changed when president\n"
	.string "Trump, the great American leader\l"
	.string "discovered the Worlds first Pokemon.$\p"
	.string "Marriott realized his true calling was\n"
	.string "to become a Pokemon Trainer and travel\l"
	.string "the world.\p"
	.string "Without a second thought he walked out\n"
	.string "the door and gave up his dream of being\l"
	.string "a lawyer.$"
