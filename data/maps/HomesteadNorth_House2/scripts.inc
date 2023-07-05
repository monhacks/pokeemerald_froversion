HomesteadNorth_House2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Script_HomesteadNorth_House2_OnLoad
	.byte 0

Script_HomesteadNorth_House2_OnLoad:
	goto_if_set FLAG_MAGEE_VERSION, Script_HomesteadNorth_House2_SetDynamicWarpMageeVersion
	setdynamicwarp MAP_HOMESTEAD_NORTH, 255, 27, 28
	end

Script_HomesteadNorth_House2_SetDynamicWarpMageeVersion:
	setdynamicwarp MAP_MAGEE_VERSION_HOMESTEAD_TOWN_NORTH, 255, 27, 28
	end

HomesteadNorth_EventScript_GameBoyKid::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_TopThreeGifts, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_TopThreeGifts:
	.string "My top three gifts on my wishlist\n"
	.string "this year are gold, frankinsence,\l"
	.string "and myrrh.\p"
	.string "Last year, all I got was a lump\n"
	.string "of coal...$"

HomesteadNorth_EventScript_House2Woman::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_NicksTurn, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_NicksTurn:
	.string "Everyone in town takes turn playing\n"
	.string "Santa.\p"
	.string "This year, it's Nick's turn.\n"
	.string "Imagine that! Haha!$"
