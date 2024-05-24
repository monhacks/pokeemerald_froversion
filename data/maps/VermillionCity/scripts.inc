.set LOCALID_BOY, 2

VermillionCity_MapScripts::
	.byte 0


VermillionCity_EventScript_BoyTellsPlayerAquaMemberIsAtHisShop1::
	lockall
		playse SE_PIN
		applymovement LOCALID_BOY, VermillionCity_Movement_ExclamationPoint
		waitmovement 0
		msgbox VermillionCity_Text_BoySaysHeyWait, MSGBOX_DEFAULT
		applymovement OBJ_EVENT_ID_PLAYER, VermillionCity_Movement_PlayerFacesBoy
		waitmovement 0
		msgbox VermillionCity_Text_BoyTellsPlayAquaMemberIsAtHisShop, MSGBOX_DEFAULT
		closemessage
		applymovement LOCALID_BOY, VermillionCity_Movement_BoyLeaves
		waitmovement 0
		removeobject LOCALID_BOY
		setflag FLAG_HIDE_VERMILLION_CITY_BOY
		addvar VAR_MAGEE_VERSION_INTRO_STATE, 1
	releaseall
	end

VermillionCity_EventScript_BoyTellsPlayerAquaMemberIsAtHisShop2::
	lockall
		playse SE_PIN
		applymovement LOCALID_BOY, VermillionCity_Movement_ExclamationPoint
		waitmovement 0
		msgbox VermillionCity_Text_BoySaysHeyWait, MSGBOX_DEFAULT
		applymovement LOCALID_BOY,VermillionCity_Movement_WalkOneRight
		waitmovement 0
		applymovement OBJ_EVENT_ID_PLAYER, VermillionCity_Movement_PlayerFacesBoy
		waitmovement 0
		msgbox VermillionCity_Text_BoyTellsPlayAquaMemberIsAtHisShop, MSGBOX_DEFAULT
		closemessage
		applymovement LOCALID_BOY, VermillionCity_Movement_BoyLeaves
		waitmovement 0
		removeobject LOCALID_BOY
		setflag FLAG_HIDE_VERMILLION_CITY_BOY
		addvar VAR_MAGEE_VERSION_INTRO_STATE, 1
	releaseall
	end

VermillionCity_EventScript_BoyTellsPlayerAquaMemberIsAtHisShop3::
	lockall
		playse SE_PIN
		applymovement LOCALID_BOY, VermillionCity_Movement_ExclamationPoint
		waitmovement 0
		msgbox VermillionCity_Text_BoySaysHeyWait, MSGBOX_DEFAULT
		applymovement LOCALID_BOY,VermillionCity_Movement_WalkTwoRight
		waitmovement 0
		applymovement OBJ_EVENT_ID_PLAYER, VermillionCity_Movement_PlayerFacesBoy
		waitmovement 0
		msgbox VermillionCity_Text_BoyTellsPlayAquaMemberIsAtHisShop, MSGBOX_DEFAULT
		closemessage
		applymovement LOCALID_BOY, VermillionCity_Movement_BoyLeaves
		waitmovement 0
		removeobject LOCALID_BOY
		setflag FLAG_HIDE_VERMILLION_CITY_BOY
		addvar VAR_MAGEE_VERSION_INTRO_STATE, 1
	releaseall
	end
	

VermillionCity_EventScript_BoyTellsPlayerAquaMemberIsAtHisShop4::
	lockall
		playse SE_PIN
		applymovement LOCALID_BOY, VermillionCity_Movement_ExclamationPoint
		waitmovement 0
		msgbox VermillionCity_Text_BoySaysHeyWait, MSGBOX_DEFAULT
		applymovement LOCALID_BOY,VermillionCity_Movement_WalkThreeRight
		waitmovement 0
		applymovement OBJ_EVENT_ID_PLAYER, VermillionCity_Movement_PlayerFacesBoy
		waitmovement 0
		msgbox VermillionCity_Text_BoyTellsPlayAquaMemberIsAtHisShop, MSGBOX_DEFAULT
		closemessage
		applymovement LOCALID_BOY, VermillionCity_Movement_BoyLeaves
		waitmovement 0
		removeobject LOCALID_BOY
		setflag FLAG_HIDE_VERMILLION_CITY_BOY
		addvar VAR_MAGEE_VERSION_INTRO_STATE, 1
	releaseall
	end

VermillionCity_EventScript_MageePleasureFactorySign::
	lock
		msgbox VermillionCity_Text_MageePleasureFactory, MSGBOX_SIGN
	release
	end

VermillionCity_EventScript_TownSign::
	lock
		msgbox VermillionCity_Text_TownSign, MSGBOX_SIGN
	release
	end

VermillionCity_EventScript_PokeCenterAndMartSign::
	lock
		msgbox gText_PokemonCenterSign, MSGBOX_SIGN
		closemessage
		msgbox gText_PokemartSign, MSGBOX_SIGN
		closemessage
	release
	end


////////////////////////////////////////////
///////////////MOVEMENT/////////////////////
////////////////////////////////////////////

VermillionCity_Movement_ExclamationPoint:
	emote_exclamation_mark
	step_end

VermillionCity_Movement_WalkOneRight:
	walk_right
	step_end

VermillionCity_Movement_WalkTwoRight:
	walk_right
	walk_right
	step_end

VermillionCity_Movement_WalkThreeRight:
	walk_right
	walk_right
	walk_right
	step_end

VermillionCity_Movement_PlayerFacesBoy:
	face_left
	step_end

VermillionCity_Movement_BoyLeaves:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

//////////////////////////////////////
///////////////TEXT///////////////////
//////////////////////////////////////

VermillionCity_Text_BoySaysHeyWait:
	.string "Hey!\p"
	.string "Wait!$"

VermillionCity_Text_BoyTellsPlayAquaMemberIsAtHisShop:
	.string "Mr. Magee, I'm glad I caught you!\p"
	.string "I wanted to warn you that some team\n"
	.string "Aqua Members have been looking for\l"
	.string "you.\p"
	.string "They seemed angry, and I think they\n"
	.string "are waiting for you at {COLOR RED}Magee's\l"
	.string "Pleasure Factory{COLOR DARK_GREY}.\p"
	.string "Please hurry, I am afraid to bring\n"
	.string "Chimchar in for his usual pedicure\l"
	.string "while Team Aqua is hanging around!$"

VermillionCity_Text_MageePleasureFactory:
	.string "Magee's Pleasure Factory$"

VermillionCity_Text_TownSign:
	.string "Sandy Beach Town$"