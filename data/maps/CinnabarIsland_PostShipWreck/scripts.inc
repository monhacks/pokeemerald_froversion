.set LOCAL_ID_SAILOR_1, 6
.set LOCAL_ID_SAILOR_2, 7
.set LOCAL_ID_VOLCANO_GUY, 10

CinnabarIsland_PostShipWreck_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PostShipWreck_OnTransition
	.byte 0

CinnabarIsland_PostShipWreck_OnTransition: @ 81FC52E
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND_POST_SHIP_WRECK
	end


@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIsland_PostShipwreck_EventScript_DiscoverShipDamageLowerTile::
	lockall
		applymovement LOCAL_ID_SAILOR_1, Common_Movement_FacePlayer
		waitmovement LOCAL_ID_SAILOR_1
		playse SE_PIN
		applymovement LOCAL_ID_SAILOR_1, Common_Movement_ExclamationMark
		waitmovement LOCAL_ID_SAILOR_1
		msgbox CinnabarIsland_PostShipwreck_Text_SailorBeckonsPlayer, MSGBOX_DEFAULT
		closemessage
		applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_PostShipwreck_Movement_MoveToInspectShip2
		waitmovement OBJ_EVENT_ID_PLAYER
		goto CinnabarIsland_PostShipwreck_EventScript_DiscoverShipDamage

CinnabarIsland_PostShipwreck_EventScript_DiscoverShipDamageUpperTile::
	lockall
		applymovement LOCAL_ID_SAILOR_1, Common_Movement_FacePlayer
		waitmovement LOCAL_ID_SAILOR_1
		playse SE_PIN
		applymovement LOCAL_ID_SAILOR_1, Common_Movement_ExclamationMark
		waitmovement LOCAL_ID_SAILOR_1
		msgbox CinnabarIsland_PostShipwreck_Text_SailorBeckonsPlayer, MSGBOX_DEFAULT
		closemessage
		applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_PostShipwreck_Movement_MoveToInspectShip
		waitmovement OBJ_EVENT_ID_PLAYER
		goto CinnabarIsland_PostShipwreck_EventScript_DiscoverShipDamage

CinnabarIsland_PostShipwreck_EventScript_DiscoverShipDamage:
		applymovement LOCAL_ID_SAILOR_1, Common_Movement_FaceOriginalDirection
		waitmovement LOCAL_ID_SAILOR_1
		delay 30
		msgbox CinnabarIsland_PostShipwreck_Text_ThisIsSomeSeriousDamage, MSGBOX_DEFAULT
		closemessage
		applymovement LOCAL_ID_SAILOR_2, Common_Movement_FacePlayer
		waitmovement LOCAL_ID_SAILOR_2
		playse SE_PIN
		applymovement LOCAL_ID_SAILOR_2, Common_Movement_ExclamationMark
		waitmovement LOCAL_ID_SAILOR_2
		msgbox CinnabarIsland_PostShipwreck_Text_AndCheckThisOut, MSGBOX_DEFAULT
		applymovement LOCAL_ID_SAILOR_2, CinnabarIsland_PostShipwreck_Movement_ShowPlayerFur
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
		waitmovement LOCAL_ID_SAILOR_2
		msgbox CinnabarIsland_PostShipwreck_Text_LooksLikeFur, MSGBOX_DEFAULT
		closemessage
		applymovement LOCAL_ID_SAILOR_2, CinnabarIsland_PostShipwreck_Movement_ReturnSailor2Position
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
		waitmovement LOCAL_ID_SAILOR_2
		applymovement LOCAL_ID_SAILOR_1, Common_Movement_FacePlayer
		waitmovement LOCAL_ID_SAILOR_1
		playse SE_PIN
		applymovement LOCAL_ID_SAILOR_1, Common_Movement_ExclamationMark
		waitmovement LOCAL_ID_SAILOR_1
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
		waitmovement OBJ_EVENT_ID_PLAYER
		msgbox CinnabarIsland_PostShipwreck_Text_AreYouGoingToInvestigate, MSGBOX_DEFAULT
		//scrollingmultichoice 10, 2, 3, 3, TRUE
		//switch VAR_RESULT
		//	case 0, CinnabarIsland_EventScript_GiveAggron
		//	case 1, CinnabarIsland_EventScript_GiveSteelix
		//	case 2, CinnabarIsland_EventScript_GiveScizor
		//	case MULTI_B_PRESSED, CinnabarIsland_PostShipwreck_Eventscript_YouNeedToTakeAPokemon
		setvar VAR_ROUTE101_STATE, 5
		hideobjectat LOCAL_ID_VOLCANO_GUY, MAP_CINNABAR_ISLAND_POST_SHIP_WRECK
		setflag FLAG_HIDE_VOLCANO_GUY
	releaseall
	end

CinnabarIsland_PostShipwreck_Eventscript_YouNeedToTakeAPokemon:
	msgbox MountCinnabar_Summit_Text_YouNeedToTakeAPokemon, MSGBOX_DEFAULT
		scrollingmultichoice 10, 2, 3, 3, TRUE
		switch VAR_RESULT
			case 0, CinnabarIsland_EventScript_GiveAggron
			case 1, CinnabarIsland_EventScript_GiveSteelix
			case 2, CinnabarIsland_EventScript_GiveScizor
			case MULTI_B_PRESSED, CinnabarIsland_PostShipwreck_Eventscript_YouNeedToTakeAPokemon
		releaseall
	end


CinnabarIsland_EventScript_GiveAggron::
		playmoncry SPECIES_AGGRON, 2
		waitmoncry
		msgbox CinnabarIsland_PostShipwreck_Text_YouTookAggron, MSGBOX_DEFAULT
		givecustommon SPECIES_AGGRON ,50, ITEM_QUICK_CLAW, ITEM_ULTRA_BALL, NATURE_CAREFUL,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_HEAVY_SLAM, MOVE_CURSE, MOVE_REST, MOVE_SLEEP_TALK, 0
		msgbox CinnabarIsland_PostShipwreck_Text_AbilityPartyMenu, MSGBOX_DEFAULT
		msgbox CinnabarIsland_PostShipwreck_Text_TakeGoodCareOfPokemon, MSGBOX_DEFAULT
		setvar VAR_ROUTE101_STATE, 5
		hideobjectat LOCAL_ID_VOLCANO_GUY, MAP_CINNABAR_ISLAND_POST_SHIP_WRECK
		setflag FLAG_HIDE_VOLCANO_GUY
	releaseall
	end

CinnabarIsland_EventScript_GiveSteelix::
		playmoncry SPECIES_STEELIX, 0
		waitmoncry
		msgbox CinnabarIsland_PostShipwreck_Text_YouTookSteelix, MSGBOX_DEFAULT
		givecustommon SPECIES_STEELIX ,50, ITEM_LEFTOVERS, ITEM_ULTRA_BALL, NATURE_HARDY,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_HEAD_SMASH, MOVE_CURSE, MOVE_EARTHQUAKE, MOVE_HEAVY_SLAM, 0
		msgbox CinnabarIsland_PostShipwreck_Text_AbilityPartyMenu, MSGBOX_DEFAULT
		msgbox CinnabarIsland_PostShipwreck_Text_TakeGoodCareOfPokemon, MSGBOX_DEFAULT
		setvar VAR_ROUTE101_STATE, 5
		hideobjectat LOCAL_ID_VOLCANO_GUY, MAP_CINNABAR_ISLAND_POST_SHIP_WRECK
		setflag FLAG_HIDE_VOLCANO_GUY
	releaseall
	end

CinnabarIsland_EventScript_GiveScizor::
		playmoncry SPECIES_SCIZOR, 0
		waitmoncry
		msgbox CinnabarIsland_PostShipwreck_Text_YouTookScizor, MSGBOX_DEFAULT
		givecustommon SPECIES_SCIZOR ,50, ITEM_QUICK_CLAW, ITEM_ULTRA_BALL, NATURE_HARDY,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_SWORDS_DANCE, MOVE_DUAL_WINGBEAT, MOVE_ROOST, MOVE_BULLET_PUNCH, 0
		msgbox CinnabarIsland_PostShipwreck_Text_AbilityPartyMenu, MSGBOX_DEFAULT
		msgbox CinnabarIsland_PostShipwreck_Text_TakeGoodCareOfPokemon, MSGBOX_DEFAULT
		setvar VAR_ROUTE101_STATE, 5
		hideobjectat LOCAL_ID_VOLCANO_GUY, MAP_CINNABAR_ISLAND_POST_SHIP_WRECK
		setflag FLAG_HIDE_VOLCANO_GUY
	releaseall
	end
	
		

CinnabarIsland_EventScript_StoneForRockSmash::
	goto_if_set FLAG_BADGE03_GET, CinnabarIsland_EventScript_DStoneForRockSmash
	giveitem ITEM_HM06_ROCK_SMASH, 1
	setflag FLAG_BADGE03_GET
	giveitem ITEM_OLD_ROD
	warp MAP_MOUNT_CINNABAR_SUMMIT, 255, 19, 12
	goto CinnabarIsland_EventScript_DStoneForRockSmash

CinnabarIsland_EventScript_DStoneForRockSmash::
end

CinnabarIsland_PostShipwreck_EventScript_Sailor::
	msgbox CinnabarIsland_PostShipwreck_Text_Sailor, MSGBOX_NPC
	end

CinnabarIsland_PostShipwreck_EventScript_Sailor2::
	msgbox CinnabarIsland_PostShipwreck_Text_Sailor2, MSGBOX_NPC
	end

CinnabarIsland_PostShipwreck_EventScript_Guy::
msgbox CinnabarIsland_PostShipwreck_Text_Guy_GotUp, MSGBOX_NPC
end

CinnabarIsland_PostShipwreck_ManAtWarehouse::
msgbox CinnabarIsland_PostShipwreck_Text_ManAtWarehouse, MSGBOX_NPC
end

CinnabarIsland_PostShipwreck_Scientist::
msgbox CinnabarIsland_PostShipwreck_Text_LookingForFur, MSGBOX_NPC
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

CinnabarIsland_PostShipwreck_Text_LookingForFur:
	.string "There has to be more fur. Where did\n"
	.string "you go 057? This is really bad...$"

CinnabarIsland_PostShipwreck_Text_ManAtWarehouse:
	.string "There is a lot of confusion going on\n"
	.string "this morning. A lot of freight was\l"
	.string "still on your ship so I guess that's\l"
	.string "dealt with now.$"		

CinnabarIsland_PostShipwreck_Text_Sailor:
	.string "Our ship... Who would do\n"
	.string "this?\p"
	.string "How are we going to get home now?\n"
	.string "I knew staying overnight was a bad\l"
	.string "idea.$"

CinnabarIsland_PostShipwreck_Text_Sailor2:
	.string "I really need to get home to\n"
	.string "my family.\p"
	.string "I don't want them to worry about\n"
	.string "me. Not again.$"

CinnabarIsland_PostShipwreck_Text_SailorBeckonsPlayer:
	.string "{PLAYER}! Come here quickly, you have\n"
	.string "to see this!$"

CinnabarIsland_PostShipwreck_Text_ThisIsSomeSeriousDamage:
	.string "I can't believe someone would do this\n"
	.string "to our ship.\p"
	.string "This is some serious damage. And it's not\n"
	.string "just our ship...\p"
	.string "Even the island residents had their\n"
	.string "ships destroyed.\p"
	.string "It's almost as if someone is\n"
	.string "trying to stop everyone from\l"
	.string "leaving the island.$"

CinnabarIsland_PostShipwreck_Text_AndCheckThisOut:
	.string "I don't think it was a someone.\n"
	.string "Check this out.$"

CinnabarIsland_PostShipwreck_Text_LooksLikeFur:
	.string "This looks like fur from a Pokemon,\n"
	.string "though I can't say which.\p"
	.string "It looks to me like a Pokemon may\n"
	.string "be responsible for the damage.\p"
	.string "However, the attacks don't seem random.\n"
	.string "If a Pokemon is responsible, that is\l"
	.string "concerning.\p"
	.string "It's not typical for a Pokemon\n"
	.string "to act so aggressive and malicious.\p"
	.string "If we want to get home, I think we need\n"
	.string "to figure out the reason behind the\l"
	.string "attacks, and why a Pokemon would\l"
	.string "want to keep us here.$"

CinnabarIsland_PostShipwreck_Text_AreYouGoingToInvestigate:
	.string "{PLAYER}, are you going to investigate?\p"
	.string "Oh you are? Good. I think you should\n"
	.string "look for more traces of the Pokemon\l"
	.string "and see what you can find.\p"
	//.string "Oh, you know what? I brought three\n"
	//.string "Pokemon along with me, why don't you\l"
	//.string "take one in case things get\l"
	//.string "dangerous.\p"
	//.string "Which one would you like?$"

CinnabarIsland_PostShipwreck_Text_Guy_GotUp:
	.string "I got up tonight because I heard loud\n"
	.string "noises outside, but the only thing I\l"
	.string "saw was the lady in the house next to\l"
	.string "the NCC locking the door from the\l"
	.string "inside.\p"
	.string "I would actually leave if my boat\l"
	.string "wasn't on the bottom of the sea.$"

CinnabarIsland_PostShipwreck_Text_TakeGoodCareOfPokemon:
	.string "Take good care of my Pokemon! Good\n"
	.string "luck out there!$"

CinnabarIsland_PostShipwreck_Text_YouTookAggron:
	.string "Aggron was added to your party.$"

CinnabarIsland_PostShipwreck_Text_YouTookSteelix:
	.string "Steelix was added to your party.$"

CinnabarIsland_PostShipwreck_Text_YouTookScizor:
	.string "Scizor was added to your party.$"

CinnabarIsland_PostShipwreck_Text_AbilityPartyMenu:
	.string "I'm not an expert Pokémon Trainer,\n"
	.string "so I don't always know what Ability\l"
	.string "is best.\p"
	.string "If you're not happy with my Pokémon's\n"
	.string "Ability, don't forget you can change\l"
	.string "all your Pokémon's abilities right in\l"
	.string "the Pokémon Party Menu.$"

CinnabarIsland_PostShipwreck_Text_YouNeedToTakeAPokemon:
	.string "{PLAYER}, I've been your crew member for\n"
	.string "5 years now, I think we both know I'm not\l"
	.string "in good enough shape to go hunting for\l"
	.string "this Pokémon all over the island.\p"
	.string "Please, take one of my Pokémon.$"

@--------------------------------------------------------------------------------
@---------------------------------Movements--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIsland_PostShipwreck_Movement_MoveToInspectShip:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

CinnabarIsland_PostShipwreck_Movement_MoveToInspectShip2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

CinnabarIsland_PostShipwreck_Movement_ShowPlayerFur:
	walk_down
	face_left
	step_end

CinnabarIsland_PostShipwreck_Movement_ReturnSailor2Position:
	walk_up
	step_end

