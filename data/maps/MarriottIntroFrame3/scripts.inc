MarriottIntroFrame3_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MarriottIntroFrame3_OnFrame
	.byte 0

MarriottIntroFrame3_OnFrame:
	map_script_2 VAR_TEMP_0, 0, MarriottIntroFrame3_EventScript_MarriottStudies
	.2byte 0

MarriottIntroFrame3_EventScript_MarriottStudies:
	lock
	delay 16
	msgbox MarriottIntroFrame3_Text_MarriottStudies, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	warpsilent MAP_MARRIOTT_INTRO_FRAME4, 255, 7, 5 
	release
end

MarriottIntroFrame3_Text_MarriottStudies:
	.string "Test Text!$"
