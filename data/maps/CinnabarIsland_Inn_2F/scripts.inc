CinnabarIsland_Inn_2F_MapScripts::
	.byte 0

CinnabarIsland_Inn_2F_WouldYouLikeToSleep::
	lock
		msgbox Text_LakeMeadVillageFrosHouseBasement_WouldYouLikeToSleep, MSGBOX_YESNO
		switch VAR_RESULT
			case NO, CinnabarIsland_Inn_EventScript_NoToSleep
			case MULTI_B_PRESSED, CinnabarIsland_Inn_EventScript_NoToSleep
		closemessage
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
		call Common_EventScript_OutOfCenterPartyHeal
		setvar VAR_ROUTE101_STATE, 3
	release
	end

CinnabarIsland_Inn_EventScript_NoToSleep::
	release
	end
