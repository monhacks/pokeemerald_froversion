LavaridgeTown_Mart_MapScripts:: @ 81FF9CD
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeTown_Mart_OnLoad
	.byte 0


LavaridgeTown_Mart_OnLoad:
	call_if_set FLAG_MARRIOTT_VERSION, LavaridgeTown_Mart_EventScript_SetDynamicWarpMarriottVersion
	call_if_unset FLAG_MARRIOTT_VERSION, LavaridgeTown_Mart_EventScript_SetDynamicWarpFroVersion
end

LavaridgeTown_Mart_EventScript_SetDynamicWarpMarriottVersion:
	setdynamicwarp MAP_LAVARIDIGE_TOWN_MARRIOTT_LAYOUT, 255, 15, 5
end

LavaridgeTown_Mart_EventScript_SetDynamicWarpFroVersion:
	setdynamicwarp MAP_LAVARIDGE_TOWN, 255, 15, 5
end

LavaridgeTown_Mart_EventScript_Clerk:: @ 81FF9CE
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	call_if_set FLAG_MARRIOTT_VERSION, LavaridgeTown_Mart_Pokemart_MarriottVersionScript
	call_if_unset FLAG_MARRIOTT_VERSION, LavaridgeTown_Mart_Pokemart_FroVersionScript

LavaridgeTown_Mart_Pokemart_FroVersionScript:
	pokemart LavaridgeTown_Mart_Pokemart_FroVersion
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart_FroVersion: @ 81FF9E8
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_Mart_Pokemart_MarriottVersionScript:
	pokemart LavaridgeTown_Mart_Pokemart_MarriottVersion
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart_MarriottVersion: @ 81FF9E8
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_Mart_EventScript_ExpertM:: @ 81FF9FE
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman:: @ 81FFA07
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike: @ 81FFA10
	.string "Use X Speed to add to a Pokémon's\n"
	.string "Speed in battle.\p"
	.string "That will help it get in the first\n"
	.string "strike--a decided advantage!$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney: @ 81FFA83
	.string "On Mt. Lancelot's peak, there's a local\n"
	.string "specialty that you can buy only there.\p"
	.string "Give it to a Pokémon--it will be elated.$"

