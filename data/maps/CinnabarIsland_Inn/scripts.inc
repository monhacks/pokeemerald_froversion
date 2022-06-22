.set LOCALID_INN_RECEPTIONIST, 1

CinnabarIsland_Inn_MapScripts::
	.byte 0


@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

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
		showmoneybox 0, 0, 0
		msgbox CinnabarIsland_Inn_Text_TheRoomIsReadyForYou, MSGBOX_YESNO
		switch VAR_RESULT
		case NO, CinnabarIsland_Inn_EventScript_ComeBackWhenReady
		case YES, CinnabarIsland_Inn_EventScript_CompleteCheckIn
		case MULTI_B_PRESSED, CinnabarIsland_Inn_EventScript_ComeBackWhenReady
	releaseall
	end

CinnabarIsland_Inn_EventScript_ComeBackWhenReady::
		msgbox CinnabarIsland_Inn_Text_ComeBackWhenReady, MSGBOX_DEFAULT
		hidemoneybox
	releaseall
	end

CinnabarIsland_Inn_EventScript_CompleteCheckIn::
		checkmoney 500, 0
		compare VAR_RESULT, FALSE
		goto_if_eq CinnabarIsland_Inn_EventScript_NotEnoughMoney
		removemoney 500, 0
		msgbox CinnabarIsland_Inn_Text_ThankYouForStayingWithUs, MSGBOX_DEFAULT
		setvar VAR_ROUTE101_STATE, 2
		hidemoneybox
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

CinnabarIsland_Inn_EventScript_StairsBlockedTrigger::
	lockall
		compare VAR_ROUTE101_STATE, 2
		goto_if_lt CinnabarIsland_Inn_EventScript_StopPlayerFromGoingUpstairs
	releaseall
	end

CinnabarIsland_Inn_EventScript_StopPlayerFromGoingUpstairs:
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_FacePlayer
		waitmovement LOCALID_INN_RECEPTIONIST
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_ExclamationMark
		waitmovement LOCALID_INN_RECEPTIONIST
		msgbox CinnabarIsland_Inn_Text_YouCantGoUpThere, MSGBOX_DEFAULT
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
		waitmovement OBJ_EVENT_ID_PLAYER
		applymovement LOCALID_INN_RECEPTIONIST, Common_Movement_FaceOriginalDirection
		waitmovement LOCALID_INN_RECEPTIONIST
	releaseall
	end


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
	.string "in for ¥500?$"

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

CinnabarIsland_Inn_Text_SomethingHappened:
	.string "I've been hearing complaints about\n"
	.string "boat vandals damaging boats overnight.\p"
	.string "I would go check on your ship if I were\n"
	.string "you.$"