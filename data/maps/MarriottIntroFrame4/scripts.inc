MarriottIntroFrame4_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MarriottIntroFrame4_OnFrame
	.byte 0

MarriottIntroFrame4_OnFrame:
	map_script_2 VAR_TEMP_0, 0, MarriottIntroFrame4_EventScript_MarriottStudies
	.2byte 0

MarriottIntroFrame4_EventScript_MarriottStudies:
	lock
	delay 16
	msgbox MarriottIntroFrame4_Text_MarriottStudies, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	warpsilent MAP_MARRIOTT_INTRO_FRAME5, 255, 7, 5 
	release
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''
MarriottIntroFrame4_Text_MarriottStudies:
	.string "Marriott and Ottdorble trained and\n"
	.string "grew stronger together, battling wild\l"
	.string "Pokemon and trainers alike.$"
