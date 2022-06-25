CinnabarIslandWarehouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIslandWarehouse_OnLoad
	.byte 0

CinnabarIslandWarehouse_OnLoad:
	compare VAR_ROUTE101_STATE, 3
	call_if_ge CinnabarIslandWarehouse_EventScript_SetDynamicWarpPostSleep
	call_if_lt CinnabarIslandWarehouse_EventScript_SetDynamicWarpPreSleep
end

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIslandWarehouse_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 64, 42
end

CinnabarIslandWarehouse_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 64, 42
end

CinnabarIslandWarehouse_EventScript_Worker1::
	msgbox CinnabarIslandWarehouse_Text_Worker1, MSGBOX_NPC
end

CinnabarIslandWarehouse_EventScript_Worker2::
	msgbox CinnabarIslandWarehouse_Text_Worker2, MSGBOX_NPC
end

CinnabarIslandWarehouse_EventScript_Sengo::
	msgbox CinnabarIslandWarehouse_Text_Sengo, MSGBOX_NPC
end
@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]

CinnabarIslandWarehouse_Text_Worker1:
	.string "I swear to Arceus if one of those\n"
	.string "boxes lands on any part of my body\p"

	.string "i quit! They should supply us with\n"
	.string "way better equipment!$"

CinnabarIslandWarehouse_Text_Worker2:
	.string "Oops... I hope this label reading\n"
	.string "'fragile' was applied to the wrong box.\p"

	.string "Otherwise someone will have a bad day\n"
	.string "unboxing this.$"

CinnabarIslandWarehouse_Text_Sengo:
	.string "Zaaaan Zaaaangoooooooose!\n"
	.string "Zangoose!$"