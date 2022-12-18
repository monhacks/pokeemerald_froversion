LavaridgeTown_House_MapScripts:: @ 81FF911
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeTown_House_OnLoad
	.byte 0

LavaridgeTown_House_OnLoad:
	call_if_set FLAG_MARRIOTT_VERSION, LavaridgeTown_House_EventScript_SetDynamicWarpMarriottVersion
	call_if_unset FLAG_MARRIOTT_VERSION, LavaridgeTown_House_EventScript_SetDynamicWarpFroVersion
end

LavaridgeTown_House_EventScript_SetDynamicWarpMarriottVersion:
	setdynamicwarp MAP_LAVARIDIGE_TOWN_MARRIOTT_LAYOUT, 255, 16, 15
end

LavaridgeTown_House_EventScript_SetDynamicWarpFroVersion:
	setdynamicwarp MAP_LAVARIDGE_TOWN, 255, 16, 15
end

LavaridgeTown_House_EventScript_OldMan:: @ 81FF912
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon:: @ 81FF91B
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings: @ 81FF92E
	.string "My wife's warming an Egg in the hot\n"
	.string "springs. This is what she told me.\p"
	.string "She left two Pokémon with the Day Care.\n"
	.string "And they discovered that Egg!$"

LavaridgeTown_House_Text_Zigzagoon: @ 81FF9BB
	.string "Zigzagoon: Pshoo!$"

