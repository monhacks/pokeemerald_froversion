RaintreeIsland_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RaintreeIsland_Gym_OnLoad
	.byte 0

RaintreeIsland_Gym_OnLoad:
	call_if_set FLAG_BADGE02_GET , RaintreeIsland_Gym_EventScript_RemoveIceBlocks
	end

RaintreeIsland_Gym_EventScript_RemoveIceBlocks:
	setmetatile 11, 30, 0x20B, 0
	setmetatile 12, 30, 0x20C, 0
	setmetatile 13, 30, 0x20D, 0
	end
	
///////////////////////////////////////
///////////////Scripts/////////////////
//////////////////////////////////////

EventScript_RaintreeIsland_IceRoom_GymTrainer2::
	trainerbattle_single TRAINER_LILITH, RaintreeIsland_IceRoom_Text_GymTrainer2Intro, RaintreeIsland_IceRoom_Text_GymTrainer2Defeat, EventScript_RaintreeIsland_IceRoom_GymTrainer2PostBattle
	msgbox Text_RaintreeIsland_GymTrainer2Defeat, MSGBOX_DEFAULT
	release
	end

EventScript_RaintreeIsland_IceRoom_GymTrainer2PostBattle:
	msgbox Text_RaintreeIsland_GymTrainer2Defeat, MSGBOX_DEFAULT
	release
	end

	EventScript_RaintreeIsland_IceRoom_GymTrainer4::
	trainerbattle_single TRAINER_CRISTIAN, RaintreeIsland_IceRoom_Text_GymTrainer4Intro, RaintreeIsland_IceRoom_Text_GymTrainer4Defeat, EventScript_RaintreeIsland_IceRoom_GymTrainer4PostBattle
	msgbox Text_RaintreeIsland_GymTrainer4Defeat, MSGBOX_DEFAULT
	release
	end

EventScript_RaintreeIsland_IceRoom_GymTrainer4PostBattle:
	msgbox Text_RaintreeIsland_GymTrainer4Defeat, MSGBOX_DEFAULT
	release
	end

EventScript_RaintreeIsland_IceRoom_GymLeaderIce::
	lock
	goto_if_unset FLAG_DEFEATED_POISON, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	goto_if_unset FLAG_PICKED_STARTER, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	goto_if_unset FLAG_DEFEATED_NORMAL, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	goto_if_unset FLAG_UNUSED_0x028, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	goto_if_unset FLAG_UNUSED_0x029, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	setflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_BATTLE_RAIN
	setflag FLAG_FORCE_BATTLE_STYLE_SET
	msgbox RaintreeIsland_Allen_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, RaintreeIsland_Allen_Text_Defeat
	goto EventScript_RaintreeIsland_IceRoom_GymLeaderFire
	release
	end

EventScript_RaintreeIsland_IceRoom_GymLeaderFire::
	msgbox RaintreeIsland_Allen_Text_RematchWithFire, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_BATTLE_SUN
	trainerbattle_no_intro TRAINER_WINONA_1, RaintreeIsland_Allen_Text_Defeat2
	goto EventScript_RaintreeIsland_IceRoom_GymLeaderDefeated
	release
	end

EventScript_RaintreeIsland_IceRoom_GymLeaderDefeated:
	msgbox FortreeCity_Gym_Text_WinonaDefeat, MSGBOX_DEFAULT
	fadescreenspeed FADE_TO_BLACK, 24
    special GameClear
    waitstate
    releaseall
	end



EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts:
	msgbox RaintreeIsland_IceRoom_Text_HaventBeatenAllTrainers, MSGBOX_DEFAULT
	release
	end

///////////////////////////////////////
///////////////Texts///////////////////
//////////////////////////////////////

RaintreeIsland_IceRoom_Text_GymTrainer2Intro:
	.string "Who turned off the heat?$"

RaintreeIsland_IceRoom_Text_GymTrainer2Defeat:
	.string "I can't handle the heat!$"

RaintreeIsland_IceRoom_Text_GymTrainer4Intro:
	.string "I didn't dress for this weather!$"

RaintreeIsland_IceRoom_Text_GymTrainer4Defeat:
	.string "I need a vacation to someplace\n"
	.string "warm!$"

Text_RaintreeIsland_GymTrainer2Defeat:
	.string "Brrrrr!$"

Text_RaintreeIsland_GymTrainer4Defeat:
	.string "Brrrrr!$"

RaintreeIsland_IceRoom_Text_HaventBeatenAllTrainers:
	.string "Hello there!\p"
	.string "Unfortunately, I'm recieving reports\n"
	.string "that you haven't defeated all the\l"
	.string "trainers in the gym!\p"
	.string "Please come back and see me after you\n"
	.string "defeat all the trainers!$"

RaintreeIsland_Allen_Text_Defeat:
	.string "Woah, you're cool!$"

RaintreeIsland_Allen_Text_Defeat2:
	.string "You're a master of both elements!$"

RaintreeIsland_Allen_Text_RematchWithFire:
	.string "Yes, it's true you did win the battle.\p"
	.string "However, to truly beat me you must\n"
	.string "beat my Fire-Type team aswell!\p"
	.string "Get ready for a hot rematch!$"

RaintreeIsland_Allen_Text_Intro:
	.string "So you managed to beat all five\n"
	.string "trainers?\p"
	.string "Excellent work, I suppose you've earned\n"
	.string "a battle with me.\p"
	.string "It won't be easy. In this battle,\n"
	.string "neither of us can use our item bags.\p"
	.string "Let get Chilly!$"
