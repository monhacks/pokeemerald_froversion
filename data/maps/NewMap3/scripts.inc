MarriottIntroFrame1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MarriottIntroFrame1_OnFrame
	.byte 0

MarriottIntroFrame1_OnFrame:
	map_script_2 VAR_TEMP_0, 0, MarriottIntroFrame1_EventScript_MarriottStudies
	.2byte 0

MarriottIntroFrame1_EventScript_MarriottStudies:
	lock
	delay 16
	msgbox MarriottIntroFrame1_Text_MarriottStudies, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	warpsilent MAP_MARRIOTT_INTRO_FRAME2, 255, 7, 5 
	release
end

MarriottIntroFrame1_Text_MarriottStudies:
	.string "Test Text!$"

