CinnabarIslandHouse2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_House_2_OnLoad
	.byte 0

CinnabarIsland_House_2_OnLoad:
	goto_if_defeated TRAINER_SUMMIT_CAVERNS_LATTKA_2, CinnabarIslandWarehouse_EventScript_SetDynamicWarpPreSleep
	compare VAR_ROUTE101_STATE, 3
	call_if_ge CinnabarIsland_House_2_EventScript_SetDynamicWarpPostSleep
	call_if_lt CinnabarIsland_House_2_EventScript_SetDynamicWarpPreSleep
	end

CinnabarIsland_House_2_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 46, 45
end

CinnabarIsland_House_2_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 46, 45
end

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIslandHouse2_EventScript_Man::
	msgbox CinnabarIslandHouse2_Text_Man, MSGBOX_DEFAULT
	closemessage
end

CinnabarIslandHouse2_EventScript_Woman::
	msgbox CinnabarIslandHouse2_Text_Woman, MSGBOX_NPC
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]

CinnabarIslandHouse2_Text_Man:
	.string "ZZZzzz... November November Charlie\n"
	.string "...please standby... ZZZzzz...\p"

	.string "...not allowed... ZZZzzz...\n"
	.string "...basement elevator...ZZzzz...$"

CinnabarIslandHouse2_Text_Woman:
	.string "My husband works the night shift at\n"
	.string "the NCC. He always tells me how\p"

	.string "important his work is. Without him\n"
	.string "there would be chaos at night.$"
