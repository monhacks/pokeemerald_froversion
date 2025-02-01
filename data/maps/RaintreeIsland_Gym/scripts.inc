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
	setmetatile 21, 10, 0x22E, 0
	setmetatile 21, 11, 0x22E, 0
	setmetatile 9, 2, 0x225, 0
	setmetatile 9, 3, 0x22D, 0
	setmetatile 8, 4, 0x22D, 0
	setmetatile 8, 5, 0x234, 0
	end
	
///////////////////////////////////////
///////////////Scripts/////////////////
//////////////////////////////////////

EventScript_RaintreeIsland_IceRoom_GymTrainer2::
	trainerbattle_single TRAINER_LILITH, RaintreeIsland_IceRoom_Text_GymTrainer2Intro, RaintreeIsland_IceRoom_Text_GymTrainer2Defeat, EventScript_RaintreeIsland_IceRoom_GymTrainer2PostBattle
	msgbox Text_RaintreeIsland_GymTrainer2Defeat, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM_FIRE_ROOM, 255, 7, 16
	release
	end

EventScript_RaintreeIsland_IceRoom_GymTrainer2PostBattle:
	msgbox Text_RaintreeIsland_GymTrainer2Defeat, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM_FIRE_ROOM, 255, 7, 16
	release
	end

	EventScript_RaintreeIsland_IceRoom_GymTrainer4::
	trainerbattle_single TRAINER_CRISTIAN, RaintreeIsland_IceRoom_Text_GymTrainer4Intro, RaintreeIsland_IceRoom_Text_GymTrainer4Defeat, EventScript_RaintreeIsland_IceRoom_GymTrainer4PostBattle
	msgbox Text_RaintreeIsland_GymTrainer4Defeat, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM_FIRE_ROOM, 255, 19, 31
	release
	end

EventScript_RaintreeIsland_IceRoom_GymTrainer4PostBattle:
	msgbox Text_RaintreeIsland_GymTrainer4Defeat, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM_FIRE_ROOM, 255, 19, 31
	release
	end

EventScript_RaintreeIsland_IceRoom_GymLeaderIce_Prelude:
	msgbox RaintreeIsland_Allen_Text_Prelude, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	return

EventScript_RaintreeIsland_IceRoom_GymLeaderIce::
	lock
	goto_if_defeated TRAINER_BRAWLY_1, EventScript_RaintreeIsland_IceRoom_GymLeaderPostBattle
	playbgm MUS_ENCOUNTER_INTENSE, 0
	@@ goto_if_unset FLAG_UNUSED_0x025, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	@@ goto_if_unset FLAG_UNUSED_0x026, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	@@ goto_if_unset FLAG_UNUSED_0x027, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	@@ goto_if_unset FLAG_UNUSED_0x028, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	@@ goto_if_unset FLAG_UNUSED_0x029, EventScript_RaintreeIsland_IceRoom_HaventBeatedAllGrunts
	setflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_BATTLE_TYPE_WEATHER
	setflag FLAG_FORCE_BATTLE_STYLE_SET
	goto_if_unset FLAG_TEMP_1, EventScript_RaintreeIsland_IceRoom_GymLeaderIce_Prelude
	setvar VAR_MUGSHOT_ID, MUGSHOT_JERETT
	msgbox RaintreeIsland_Allen_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRAWLY_1, RaintreeIsland_Allen_Text_Defeat
	setflag FLAG_BADGE02_GET
	clearflag FLAG_SYS_NO_BAG_USE
	clearflag FLAG_BATTLE_TYPE_WEATHER
	clearflag FLAG_FORCE_BATTLE_STYLE_SET
	msgbox RaintreeIsland_Leader_Text_PostBattle, MSGBOX_DEFAULT
	msgbox RaintreeIsland_Leader_Text_GiveIceBeam, MSGBOX_DEFAULT
	giveitem ITEM_TM13, 1
	msgbox RaintreeIsland_Leader_Text_ExplainIceBeam, MSGBOX_DEFAULT
	giveitem ITEM_TM35, 1
	msgbox RaintreeIsland_Leader_Text_ExplainFlamethrower, MSGBOX_DEFAULT
	goto EventScript_RaintreeIsland_IceRoom_GymLeaderPostBattle
	release
	end

RaintreeIsland_Gym_EventScript_ChooseAPokemon::
	msgbox RaintreeIsland_Gym_Text_YouNeedToTakeAPokemon
	scrollingmultichoice 12, 2, 3, 3, TRUE
	switch VAR_RESULT
		case 0, RaintreeIsland_Gym_EventScript_GiveChansey
		case 1, RaintreeIsland_Gym_EventScript_GiveUmbreon
		case 2, RaintreeIsland_Gym_EventScript_GiveMilotic
		case MULTI_B_PRESSED, RaintreeIsland_Gym_EventScript_ChooseAPokemon
	end

RaintreeIsland_Gym_EventScript_GiveChansey::
		playmoncry SPECIES_CHANSEY, 2
		waitmoncry
		msgbox RaintreeIsland_Gym_Text_YouTookChansey, MSGBOX_DEFAULT
		givecustommon SPECIES_CHANSEY ,50, ITEM_EVIOLITE, ITEM_ULTRA_BALL, NATURE_HARDY,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_SOFT_BOILED, MOVE_SEISMIC_TOSS, MOVE_CHARM, MOVE_MINIMIZE, 0
		goto EventScript_RaintreeIsland_IceRoom_GymLeaderPostBattle
	releaseall
	end

RaintreeIsland_Gym_EventScript_GiveUmbreon::
		playmoncry SPECIES_UMBREON, 2
		waitmoncry
		msgbox RaintreeIsland_Gym_Text_YouTookUmbreon, MSGBOX_DEFAULT
		givecustommon SPECIES_UMBREON ,50, ITEM_SITRUS_BERRY, ITEM_DUSK_BALL, NATURE_RASH,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_CURSE, MOVE_ASSURANCE, MOVE_MOONLIGHT, MOVE_YAWN, 0
		goto EventScript_RaintreeIsland_IceRoom_GymLeaderPostBattle
	releaseall
	end

RaintreeIsland_Gym_EventScript_GiveMilotic::
		playmoncry SPECIES_MILOTIC, 2
		waitmoncry
		msgbox RaintreeIsland_Gym_Text_YouTookUmbreon, MSGBOX_DEFAULT
		givecustommon SPECIES_MILOTIC ,50, ITEM_SITRUS_BERRY, ITEM_DUSK_BALL, NATURE_RASH,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_MUDDY_WATER, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_COIL, 0
		goto EventScript_RaintreeIsland_IceRoom_GymLeaderPostBattle
	releaseall
	end

EventScript_RaintreeIsland_IceRoom_GymLeaderPostBattle:
	msgbox RaintreeIsland_Leader_Text_PostTM, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 7, 3
	fadescreen FADE_FROM_BLACK
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
	goto_if_unset FLAG_TEMP_1, EventScript_RaintreeIsland_IceRoom_GymLeaderIce_Prelude
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

RaintreeIsland_Allen_Text_Prelude:
	.string "You know, living on a tropical Island\n"
	.string "like Cinnabar is great. But being hot\l"
	.string "all the time is no fun.\p"
	.string "That's why I train both Fire and Ice\n"
	.string "Type Pokémon.$"


RaintreeIsland_Leader_Text_PostBattle:
	.string "Wow, you are a master of both\n"
	.string "Fire and Ice.\p"
	.string "As evidence of your victory here\n"
	.string "I present you with the Elemental\l"
	.string "Badge.$"

RaintreeIsland_Leader_Text_GiveIceBeam:
	.string "I also have this for you.$"

RaintreeIsland_Leader_Text_ExplainIceBeam:
	.string "That TM contains Ice Beam.\p"
	.string "Not only is it powerful, but\n"
	.string "also has a chance to freeze\l"
	.string "your Opponent in their tracks.\n"
	.string "...\p"
	.string "You didnt think I was going to only\n"
	.string "give you an Ice Type TM, did you?\p"
	.string "Please take this as well.$"

RaintreeIsland_Leader_Text_ExplainFlamethrower:
	.string "This TM contains Flamethrower.\p"
	.string "Teach it to a Fire Type Pokemon and\n"
	.string "you'll be burning the competition\l"
	.string "up.$"

RaintreeIsland_Leader_Text_PostTM:
	.string "You really are a strong Trainer.\p"
	.string "I can't believe this is your first\n"
	.string "badge.\p"
	.string "Oh, you don't care about being champion?\p"
	.string "You just challenged me for fun?\p"
	.string "Well that's embarassing. I think I know\n"
	.string "how to improve. In the future my family\l"
	.string "will only train Fire Type Pokémon.\p"
	.string "No more Ice for my son Blaine!$"

RaintreeIsland_Gym_Text_TakeAPokemon:
	.string "Oh, and one more thing. I'm feeling\n"
	.string "extra generous. I have some extra\l"
	.string "Pokémon that I've been looking\l"
	.string "to find a home for, why don't\l"
	.string "you choose one?\p"
	.string "I can sense your love and devotion\n"
	.string "to your Pokémon, so I'm happy to\l"
	.string "say I think you would be a fantastic\l"
	.string "trainer to any one of these Pokémon.\p"
	.string "Which Pokémon would you like?$"

RaintreeIsland_Gym_Text_YouNeedToTakeAPokemon:
	.string "These Pokémon are in need of a home.\n"
	.string "Are you that heartless that you won't\l"
	.string "Help a Pokémon in need?\p"
	.string "Don't be unkind, choose a Pokémon.$"

RaintreeIsland_Gym_Text_YouTookChansey:
	.string "Chansey was added to your party.$"

RaintreeIsland_Gym_Text_YouTookUmbreon:
	.string "Umbreon was added to your party.$"

RaintreeIsland_Gym_Text_YouTookMilotic:
	.string "Milotic was added to your party.$"
