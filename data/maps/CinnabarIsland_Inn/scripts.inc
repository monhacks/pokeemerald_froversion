.set LOCALID_INN_RECEPTIONIST, 1

CinnabarIsland_Inn_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CinnabarIsland_Inn_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_Inn_OnLoad
	.byte 0

CinnabarIsland_Inn_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 3, CinnabarIsland_Inn_EventScript_ReceptionistCallsPlayerOverToDesk
	.2byte 0

CinnabarIsland_Inn_OnLoad:
	goto_if_defeated TRAINER_SUMMIT_CAVERNS_LATTKA_2, CinnabarIslandWarehouse_EventScript_SetDynamicWarpPreSleep
	compare VAR_ROUTE101_STATE, 3
	call_if_ge CinnabarIsland_Inn_EventScript_SetDynamicWarpPostSleep
	call_if_lt CinnabarIsland_Inn_EventScript_SetDynamicWarpPreSleep
	end

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIsland_Inn_EventScript_InnSalesMan::
	message gText_HowMayIServeYou
	waitmessage
	pokemart CinnabarIsland_Inn_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CinnabarIsland_Inn_Pokemart: @ 81FFCD8
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_AIR_BALLOON
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_NONE
	release
	end

CinnabarIsland_Inn_EventScript_InnReceptionist::
	lockall
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_FacePlayer
		waitmovement LOCALID_INN_RECEPTIONIST
		compare VAR_ROUTE101_STATE, 2
		goto_if_eq CinnabarIsland_Inn_EventScript_AlreadyCheckedIn
		goto_if_gt CinnabarIsland_Inn_ItSeemsSomethingHasHappened
		goto_if_set FLAG_GAVE_NCC_PACKAGE, CinnabarIsland_Inn_EventScript_CheckIn
		msgbox CinnabarIsland_Inn_Text_WeAreStillCleaningRoom, MSGBOX_DEFAULT
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_FaceOriginalDirection
		waitmovement LOCALID_INN_RECEPTIONIST
	releaseall
	end

CinnabarIsland_Inn_EventScript_CheckIn::
		msgbox CinnabarIsland_Inn_Text_TheRoomIsReadyForYou, MSGBOX_YESNO
		switch VAR_RESULT
		case NO, CinnabarIsland_Inn_EventScript_ComeBackWhenReady
		case YES, CinnabarIsland_Inn_EventScript_CompleteCheckIn
		case MULTI_B_PRESSED, CinnabarIsland_Inn_EventScript_ComeBackWhenReady
	releaseall
	end

CinnabarIsland_Inn_EventScript_ComeBackWhenReady::
		msgbox CinnabarIsland_Inn_Text_ComeBackWhenReady, MSGBOX_DEFAULT
	releaseall
	end

CinnabarIsland_Inn_EventScript_CompleteCheckIn::
		msgbox CinnabarIsland_Inn_Text_ThankYouForStayingWithUs, MSGBOX_DEFAULT
		setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

CinnabarIsland_Inn_EventScript_NotEnoughMoney:: @ 822EF76
		msgbox CinnabarIsland_Inn_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
		hidemoneybox
	release
	end

CinnabarIsland_Inn_EventScript_AlreadyCheckedIn::
		msgbox CinnabarIsland_Inn_Text_ThankYouForStayingWithUs, MSGBOX_DEFAULT
	releaseall
	end

CinnabarIsland_Inn_ItSeemsSomethingHasHappened:
		msgbox CinnabarIsland_Inn_Text_SomethingHappened, MSGBOX_DEFAULT
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_FaceOriginalDirection
		waitmovement LOCALID_INN_RECEPTIONIST
	releaseall
	end

CinnabarIsland_Inn_EventScript_StairsTrigger::
	lockall
		compare VAR_ROUTE101_STATE, 3
		goto_if_eq CinnabarIsland_Inn_EventScript_ReceptionistCallsPlayerOverToDesk
		compare VAR_ROUTE101_STATE, 2
		goto_if_lt CinnabarIsland_Inn_EventScript_StopPlayerFromGoingUpstairs
	releaseall
	end

CinnabarIsland_Inn_EventScript_StopPlayerFromGoingUpstairs:
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_FacePlayer
		waitmovement LOCALID_INN_RECEPTIONIST
		playse SE_PIN
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_ExclamationMark
		waitmovement LOCALID_INN_RECEPTIONIST
		msgbox CinnabarIsland_Inn_Text_YouCantGoUpThere, MSGBOX_DEFAULT
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
		waitmovement OBJ_EVENT_ID_PLAYER
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_FaceOriginalDirection
		waitmovement LOCALID_INN_RECEPTIONIST
	releaseall
	end

CinnabarIsland_Inn_EventScript_ReceptionistCallsPlayerOverToDesk::
	lockall
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_FacePlayer
		waitmovement LOCALID_INN_RECEPTIONIST
		playse SE_PIN
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_ExclamationMark
		waitmovement LOCALID_INN_RECEPTIONIST
		msgbox CinnabarIsland_Inn_Text_ComeOverHere, MSGBOX_DEFAULT
		applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Inn_Movement_PlayerMovesToDesk
		waitmovement OBJ_EVENT_ID_PLAYER
		msgbox CinnabarIsland_Inn_Text_SomethingHappened
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_FaceOriginalDirection
		waitmovement LOCALID_INN_RECEPTIONIST
		setvar VAR_ROUTE101_STATE, 4
	releaseall
	end

CinnabarIsland_Inn_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 38, 44
end

CinnabarIsland_Inn_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 38, 44
end

@--------------------------------------------------------------------------------
@-----------------------------------Movement-------------------------------------
@--------------------------------------------------------------------------------

CinnabarIsland_Inn_Movement_PlayerMovesToDesk:
	walk_left
	walk_left
	walk_left
	walk_left
step_end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------

CinnabarIsland_Inn_Text_WeAreStillCleaningRoom:
	.string "We are still cleaning your room\n"
	.string "from our previous guest.\p"
	.string "Please come back to check in later.$"

CinnabarIsland_Inn_Text_TheRoomIsReadyForYou:
	.string "We have finished cleaning your\n"
	.string "room. Would you like to check\l"
	.string "in$"

CinnabarIsland_Inn_Text_ComeBackWhenReady:
	.string "Okay, come back whenever you're\n"
	.string "ready to check in!$"

CinnabarIsland_Inn_Text_ThankYouForStayingWithUs:
	.string "Thank you for staying with us! Your\n"
	.string "room is up the stairs to the right.$"

CinnabarIsland_Inn_Text_YouveNotGotTheMoney: @ 822FE5E
	.string "Sir, it looks like\n"
	.string "you've not got the money.$"

CinnabarIsland_Inn_Text_YouCantGoUpThere:
	.string "Hey! You can't go up there right\n"
	.string "now.$"

CinnabarIsland_Inn_Text_ComeOverHere:
	.string "Good morning {PLAYER}!\p"
	.string "Please step over to my desk,\n"
	.string "I have some news I think you\l"
	.string "should hear.$"

CinnabarIsland_Inn_Text_SomethingHappened:
	.string "I just wanted to give you a heads\n"
	.string "up that word around the island this\l"
	.string "morning is that vandals were damaging\l"
	.string "property at the harbor overnight.\p"
	.string "All the locals are in a panic because\n"
	.string "from what we can tell, all means of\l"
	.string "transportation have been destroyed.\p"
	.string "What will we do if we can't get off\n"
	.string "the island? How will we survive?\p"
	.string "We are completely cut off from the world.\p"
	.string "Can you go check your boat and see if it\n"
	.string "is in working condition. Maybe you can\l"
	.string "get word to our neighboring islands\l"
	.string "and see if they can offer assistance.$"