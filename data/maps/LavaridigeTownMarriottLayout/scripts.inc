LavaridigeTownMarriottLayout_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridigeTownMarriottLayout_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridigeTownMarriottLayout_OnFrame
	.byte 0

LavaridigeTownMarriottLayout_OnTransition:
	setflag FLAG_MARRIOTT_VERSION
	end

LavaridigeTownMarriottLayout_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, LavaridigeTownMarriottLayout_EventScript_GiveOtdorble
	.2byte 0

LavaridigeTownMarriottLayout_EventScript_GiveOtdorble:
	givecustommon SPECIES_OTDORBLE ,50, ITEM_EVIOLITE, ITEM_ULTRA_BALL, NATURE_CAREFUL,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_ICE_PUNCH, MOVE_BRICK_BREAK, MOVE_SWORDS_DANCE, MOVE_AQUA_TAIL, 0
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY
	setflag FLAG_HIDE_FREDERIC_2
	setflag FLAG_HIDE_FLANNERY_WESTERN_APPROACH
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setrespawn HEAL_LOCATION_LAVARIDIGE_TOWN_MARRIOTT_LAYOUT
	end	 

LavaridgeTownMarriottVersion_EventScript_ExpertF::
	lock
	goto_if_set FLAG_HIDE_LAKE_MEAD_VILLAGE_ISIAH, LavaridgeTownMarriottVersion_EventScript_ExpertF_2
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, TRUE
	goto_if_eq LavaridgeTownMarriottVersion_EventScript_GiveWaterStone
	msgbox LavaridgeTownMarriottVersion_Text_ExpertF_IveAlwaysWantedToSeeAllThePokemonInTheArea, MSGBOX_NPC
	release
end

LavaridgeTownMarriottVersion_EventScript_GiveWaterStone:
	msgbox LavaridgeTownMarriottVersion_Text_ExpertF_YouCompletedPokedex, MSGBOX_NPC
	giveitem ITEM_WATER_STONE, 1
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_ISIAH
	release
end

LavaridgeTownMarriottVersion_EventScript_ExpertF_2:
	msgbox LavaridgeTownMarriottVersion_Text_ExpertF_ThankYouForMakingDreamsComeTrue, MSGBOX_NPC
	release
end

LavaridigeTownMarriottLayout_EventScript_GymLeaderSignOnDoor::
	msgbox	LavaridigeTownMarriottLayout_Text_GymLeaderSignOnDoor, MSGBOX_SIGN
	end

LavaridigeTownMarriottLayout_Text_GymLeaderSignOnDoor:
	.string "There is a sign on the door.\p"
	.string "“GYM CLOSED: Leader Flannery is\n"
	.string "investigating some strange activity\l"
	.string "in the Western Approach.\p"
	.string "He will be reviewing all applications\n"
	.string "to fill his position once he returns.\p"
	.string "Thank you for you interest and\n"
	.string "understanding in the matter.”$"

LavaridgeTownMarriottVersion_Text_ExpertF_IveAlwaysWantedToSeeAllThePokemonInTheArea:
	.string "I've always wanted to see all\n"
	.string "the Pokémon that live in the\l"
	.string "Western Approach.\p"
	.string "Too bad this old lady can't\n"
	.string "make the journey herself.\p"
	.string "Oh well, guess it just wasn't\n"
	.string "meant to be.$"

LavaridgeTownMarriottVersion_Text_ExpertF_ThankYouForMakingDreamsComeTrue:
	.string "Thank you for making this old\n"
	.string "lady's dreams come true.$"

LavaridgeTownMarriottVersion_Text_ExpertF_YouCompletedPokedex:
	.string "Butter my biscuits and call\n"
	.string "me Sally, did you catch all\l"
	.string "the Pokémon in the Western\l"
	.string "Approach?\p"
	.string "You did!\p"
	.string "Thank you for making this old\n"
	.string "lady's dreams come true.\p"
	.string "Please, take this as a token\n"
	.string "of my appreciation!$"
