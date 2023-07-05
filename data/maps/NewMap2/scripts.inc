NewMap2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Script_NewMap2_OnLoad
	.byte 0

Script_NewMap2_OnLoad:
	goto_if_set FLAG_MAGEE_VERSION, Script_NewMap2_SetDynamicWarpMageeVersion
	setdynamicwarp MAP_HOMESTEAD_NORTH, 255, 47, 27
	end

Script_NewMap2_SetDynamicWarpMageeVersion:
	setdynamicwarp MAP_MAGEE_VERSION_HOMESTEAD_TOWN_NORTH, 255, 47, 27
	end


HomesteadNorth_Mart_EventScript_Clerk:: @ 81FC240
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Homestead_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Mart_EventScript_Man1::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_LetItSnow, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Mart_EventScript_Woman1::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_FavoritePartOfYear, MSGBOX_DEFAULT
	release
end

.align 2
Homestead_Mart_Pokemart: @ 81FC260
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

HomesteadNorth_Text_LetItSnow:
	.string "Let it snow, let it snow, let it\n snow!!!\p"
	.string "I love this time of year!$"

HomesteadNorth_Text_FavoritePartOfYear:
	.string "My favorite part about December 26?\n"
	.string "Only 364 days until Christmas!$"