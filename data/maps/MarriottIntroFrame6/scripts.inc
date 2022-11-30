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
	warpsilent MAP_LAVARIDIGE_TOWN_MARRIOTT_LAYOUT, 255, 12, 8 
	release
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''
MarriottIntroFrame6_Text_MarriottStudies:
	.string "As he was walking through town he\n"
	.string "noticed a flyer on the ground.\p"
	.string "“Grand Island Gym: Now accepting\n"
	.string "applications for leader position.\p"
	.string "Responsibilities include facing any\n"
	.string "challengers that present themselves\l"
	.string "and determining worthiness of trainer\l"
	.string "to advance to the Elite Four.\p"
	.string "Also must keep Gym Tidy”$"
