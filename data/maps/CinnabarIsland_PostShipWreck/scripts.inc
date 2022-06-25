.set LOCAL_ID_SAILOR_1, 6
.set LOCAL_ID_SAILOR_2, 7

CinnabarIsland_PostShipWreck_MapScripts::
	.byte 0


@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIsland_PostShipwreck_EventScript_DiscoverShipDamage::
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
		setvar VAR_ROUTE101_STATE, 5
	releaseall
	end
		

CinnabarIsland_EventScript_StoneForRockSmash::
	goto_if_set FLAG_BADGE03_GET, CinnabarIsland_EventScript_DStoneForRockSmash
	giveitem ITEM_HM06_ROCK_SMASH, 1
	setflag FLAG_BADGE03_GET
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

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------


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
	.string "Even the Island residents had their\n"
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
	.string "be resposible for the damage.\p"
	.string "However, the attacks don't seem random.\n"
	.string "If a Pokemon is responsible, that is\l"
	.string "concerning.\p"
	.string "It's not typical for a Pokemon\n"
	.string "to act so aggressive and malicious.\p"
	.string "If we want to get home, I think we need\n"
	.string "to figure out the reason behind the\l"
	.string "attacks, and why a Pokemon would\l"
	.string "want to keep us here.$"


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

CinnabarIsland_PostShipwreck_Movement_ShowPlayerFur:
	walk_down
	face_left
	step_end

CinnabarIsland_PostShipwreck_Movement_ReturnSailor2Position:
	walk_up
	step_end

