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

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''
MarriottIntroFrame3_Text_MarriottStudies:
	.string "To be a Pokemon Trainer, he would need\n"
	.string "to find a companion Pokemon.\p"
	.string "While in the fields he found a new\n"
	.string "species of Pokemon, Ottdorble.\p"
	.string "Ottdorble took to Marriott right away\n"
	.string "and just like that, they were\l"
	.string "inseperable.$"
