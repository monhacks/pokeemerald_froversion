LavaridgeTown_HerbShop_MapScripts:: @ 81FE4D6
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeTown_HerbShop_OnLoad
	.byte 0

LavaridgeTown_HerbShop_OnLoad:
	call_if_set FLAG_MARRIOTT_VERSION, LavaridgeTown_HerbShop_EventScript_SetDynamicWarpMarriottVersion
	call_if_unset FLAG_MARRIOTT_VERSION, LavaridgeTown_HerbShop_EventScript_SetDynamicWarpFroVersion
end

LavaridgeTown_HerbShop_EventScript_SetDynamicWarpMarriottVersion:
	setdynamicwarp MAP_LAVARIDIGE_TOWN_MARRIOTT_LAYOUT, 255, 12, 15
end

LavaridgeTown_HerbShop_EventScript_SetDynamicWarpFroVersion:
	setdynamicwarp MAP_LAVARIDGE_TOWN, 255, 12, 15
end

LavaridgeTown_HerbShop_EventScript_Clerk:: @ 81FE4D7
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	call_if_set FLAG_MARRIOTT_VERSION, LavaridgeTown_HerbShop_Pokemart_MarriottVersionScript
	call_if_unset FLAG_MARRIOTT_VERSION, LavaridgeTown_HerbShop_Pokemart_FroVersionScript

LavaridgeTown_HerbShop_Pokemart_MarriottVersionScript:
	pokemart LavaridgeTown_HerbShop_Pokemart_MarriottVersion
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Pokemart_FroVersionScript:
	pokemart LavaridgeTown_HerbShop_Pokemart_FroVersion
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart_FroVersion: @ 81FE4F0
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end
.align 2
LavaridgeTown_HerbShop_Pokemart_MarriottVersion: @ 81FE4F0
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_ExpertM:: @ 81FE4FC
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan:: @ 81FE505
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal:: @ 81FE534
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop: @ 81FE53E
	.string "Welcome to the Herb Shop, home of\n"
	.string "effective and inexpensive medicine!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine: @ 81FE584
	.string "You've come to look at herbal medicine\n"
	.string "in Grand Island?\p"
	.string "That's rather commendable.\p"
	.string "I like you! Take this!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal: @ 81FE5EB
	.string "That Charcoal I gave you, it's used\n"
	.string "for making herbal medicine.\p"
	.string "It also does wonders when held by\n"
	.string "a Pokémon.\p"
	.string "It intensifies the power of Fire-type\n"
	.string "moves.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike: @ 81FE685
	.string "Herbal medicine works impressively well.\n"
	.string "But your Pokémon will dislike you for it.\l"
	.string "It must be horribly bitter!$"

