CinnabarIslandHouse1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_House_1_OnLoad
	.byte 0
CinnabarIsland_House_1_OnLoad:
	compare VAR_ROUTE101_STATE, 3
	call_if_ge CinnabarIsland_House_1_EventScript_SetDynamicWarpPostSleep
	call_if_lt CinnabarIsland_House_1_EventScript_SetDynamicWarpPreSleep
	end

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------
CinnabarIsland_House_1_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 33, 47
end

CinnabarIsland_House_1_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 33, 47
end

CinnabarIslandHouse1_EventScript_Man::
	msgbox CinnabarIslandHouse1_Text_Man, MSGBOX_NPC
	end

CinnabarIslandHouse1_EventScript_Woman::
	msgbox CinnabarIslandHouse1_Text_Woman, MSGBOX_NPC
	end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]

CinnabarIslandHouse1_Text_Woman:
	.string "My husband works the night shift at\n"
	.string "the NCC. He always tells me how\p"
	
	
	.string "important his work is. Without him\n"
	.string "there would be chaos at night.$"

CinnabarIslandHouse1_Text_Man:
	.string "ZZZzzz... November November Charlie\n"
	.string "...please standby... ZZZzzz...\p$"

	.string "...not allowed... ZZZzzz...\n"
	.string "...basement elevator...ZZzzz...$"

