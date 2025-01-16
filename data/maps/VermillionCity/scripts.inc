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

VermillionCity_EventScript_NPC1::
	lockall
		switch VAR_MAGEE_VERSION
			case 3, VermillionCity_EventScript_DialogueSawTeamMAGAHeadingTowardsRoute2
		msgbox VermillionCity_Text_WavesNeverGetOld, MSGBOX_NPC
	releaseall
	end

VermillionCity_EventScript_NPC2::
	lockall
		switch VAR_MAGEE_VERSION
			case 3, VermillionCity_EventScript_DialogueInABigHurry
		msgbox VermillionCity_Text_FarmersMarketHeart, MSGBOX_NPC
	releaseall
	end

VermillionCity_EventScript_NPC3::
	lockall
		switch VAR_MAGEE_VERSION
			case 3, VermillionCity_EventScript_DialougeCausingMischief
		msgbox VermillionCity_Text_ThrivingTown, MSGBOX_NPC
	releaseall
	end

VermillionCity_EventScript_NPC4::
	lockall
		switch VAR_MAGEE_VERSION
			case 3, VermillionCity_EventScript_DialougeTeamMAGALastSeen
		msgbox VermillionCity_Text_MageesPleasureFactory, MSGBOX_NPC
	releaseall
	end

VermillionCity_EventScript_NPC5::
	lockall
		switch VAR_MAGEE_VERSION
			case 3, VermillionCity_EventScript_DialougeMovingFast
		msgbox VermillionCity_Text_WelcomeToSandyBeach, MSGBOX_NPC
	releaseall
	end

VermillionCity_EventScript_DialogueSawTeamMAGAHeadingTowardsRoute2:
		msgbox VermillionCity_Text_TeamMAGASighting, MSGBOX_NPC
	releaseall
	end

VermillionCity_EventScript_DialogueInABigHurry:
		msgbox VermillionCity_Text_InABigHurry, MSGBOX_NPC
	releaseall
	end

VermillionCity_EventScript_DialougeCausingMischief:
		msgbox VermillionCity_Text_CausingMischief, MSGBOX_NPC
	releaseall
	end

VermillionCity_EventScript_DialougeTeamMAGALastSeen:
		msgbox VermillionCity_Text_TeamMAGALastSeen, MSGBOX_NPC
	releaseall
	end
	
VermillionCity_EventScript_DialougeMovingFast:
		msgbox VermillionCity_Text_MovingFast, MSGBOX_NPC
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
	.string "MAGA Members have been looking for\l"
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

VermillionCity_Text_TeamMAGASighting:
.string "I saw Team MAGA heading toward Route\n"
.string "2. They didn't look like they were\l"
.string "up to any good!$"

VermillionCity_Text_ThoseScaryPeopleWithTeamMAGA:
.string "Those scary people with 'Team MAGA'\n"
.string "on their jackets? They went to\l"
.string "Route 2!$"

VermillionCity_Text_TeamMAGALastSeen:
.string "Team MAGA was just here. If you're\n"
.string "looking for them, they took off\l"
.string "toward Route 2.$"

VermillionCity_Text_WatchYourBack:
.string "Yeah, I saw Team MAGA alright. They\n"
.string "went straight down Route 2.\l"
.string "Watch your back with that lot.$"

VermillionCity_Text_MovingFast:
.string "Team MAGA, huh? They went toward\n"
.string "Route 2, moving fast. Trouble\l"
.string "always follows them.$"

VermillionCity_Text_GruntsHeadingToRoute2:
.string "A bunch of Team MAGA grunts was seen\n"
.string "heading to Route 2. Stay alert\l"
.string "if you're going after them.$"

VermillionCity_Text_InABigHurry:
.string "Team MAGA? Yeah, I saw them. They\n"
.string "were running toward Route 2 like\l"
.string "they were in a big hurry!$"

VermillionCity_Text_CausingMischief:
.string "Team MAGA is always causing\n"
.string "mischief. They went toward Route 2\l"
.string "not long ago.$"

VermillionCity_Text_SuspiciousBehavior:
.string "Team MAGA was discussing something\n"
.string "suspicious before they left for\l"
.string "Route 2. You might find them there.$"

VermillionCity_Text_StraightToRoute2:
.string "Those Team MAGA folks went straight\n"
.string "toward Route 2. I'd steer clear\l"
.string "if I were you!$"

VermillionCity_Text_ThrivingTown:
.string "Sandy Beach Town has been thriving\n"
.string "lately. Our markets are bustling\l"
.string "and the beaches are full of life!$"

VermillionCity_Text_WelcomeToSandyBeach:
.string "Welcome to Sandy Beach Town! It's a\n"
.string "calm place by the ocean where you\l"
.string "can truly relax and unwind!$"

VermillionCity_Text_FarmersMarketHeart:
.string "Our farmers' market is the heart of\n"
.string "Sandy Beach Town. Fresh produce and\l"
.string "local goods await you every day!$"

VermillionCity_Text_MageesPleasureFactory:
.string "Have you visited Magee's Pleasure\n"
.string "Factory yet? It's the best spa in\l"
.string "town for ultimate relaxation!$"

VermillionCity_Text_WavesNeverGetOld:
.string "Life here in Sandy Beach Town is\n"
.string "simple and peaceful. The sound of\l"
.string "the waves never gets old!$"
