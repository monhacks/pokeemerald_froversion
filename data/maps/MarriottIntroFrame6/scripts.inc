MarriottIntroFrame6_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MarriottIntroFrame6_OnFrame
	.byte 0

MarriottIntroFrame6_OnFrame:
	map_script_2 VAR_TEMP_0, 0, MarriottIntroFrame6_EventScript_MarriottStudies
	.2byte 0

MarriottIntroFrame6_EventScript_MarriottStudies:
	lock
	delay 16
	msgbox MarriottIntroFrame6_Text_MarriottStudies, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	warpsilent MAP_DEWFORD_TOWN, 255, 8, 3 
	release
end

MarriottIntroFrame6_Text_MarriottStudies:
	.string "Test Text!$"
