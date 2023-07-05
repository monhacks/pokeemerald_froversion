.set LOCALID_SECRETARY, 1

MageeVersionProtagonistsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MageeVersionProtagonistsHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MageeVersionProtagonistsHouse_OnWarp	
	.byte 0

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
///////////////////////////MAP SCRIPTS////////////////////////////
////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////

MageeVersionProtagonistsHouse_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, Script_MageeVersionProtagonistsHouse_Secretary

MageeVersionProtagonistsHouse_OnWarp:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, Script_MageeVersionProtagonistsHouse_SetProtagSouth
	.2byte 0

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////EVENT SCRIPTS///////////////////////////
////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////

Script_MageeVersionProtagonistsHouse_Secretary:
	lock
		showobjectat LOCALID_SECRETARY, MAP_MAGEE_VERSION_PROTAGONISTS_HOUSE
		applymovement LOCALID_SECRETARY, Movement_MageeVersionProtagonistsHouse_SecretaryAwakensProtag
		waitmovement LOCALID_SECRETARY
		//insert mugshot script here for secretary
		msgbox Text_MageeVersionProtagonistsHouse_WakeUpYouHaveAChallenger, MSGBOX_DEFAULT
		givecustommon SPECIES_SNOUBAUL ,55, ITEM_LEFTOVERS, ITEM_ULTRA_BALL, NATURE_CAREFUL,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_SLEEP_TALK, MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_REST, 0
		//insert mugshot script here for protagonist 
		msgbox Text_MageeVersionProtagonistsHouse_StillGroggyButOkay, MSGBOX_DEFAULT
		givecustommon SPECIES_ALAKAZAM ,55, ITEM_LEFTOVERS, ITEM_ULTRA_BALL, NATURE_CAREFUL,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_FLASH_CANNON, MOVE_ASSURANCE, MOVE_PSYCHIC, MOVE_MAGIC_MIRROR, 0
		//insert mugshot script here for secretary
		msgbox Text_MageeVersionProtagonistsHouse_FineJustHurry, MSGBOX_DEFAULT
		givecustommon SPECIES_METAGROSS ,55, ITEM_LEFTOVERS, ITEM_ULTRA_BALL, NATURE_CAREFUL,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_METEOR_MASH, MOVE_AGILITY, MOVE_PSYCHIC, MOVE_NONE, 0
		applymovement LOCALID_SECRETARY, Movement_MageeVersionProtagonistsHouse_SecretaryLeavesHouse
		waitmovement LOCALID_SECRETARY
		removeobject LOCALID_SECRETARY
		setflag FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY
		setflag FLAG_SYS_POKEMON_GET
		setflag FLAG_SYS_POKEDEX_GET
		setvar VAR_LITTLEROOT_INTRO_STATE, 1
		release
	end

Script_MageeVersionProtagonistsHouse_SetProtagSouth:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	end

MageeVersionProtagonistsHouse_TestScript::
	release
	end

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
////////////////////////MOVEMENT SCRIPTS//////////////////////////
////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////

Movement_MageeVersionProtagonistsHouse_SecretaryAwakensProtag:
		walk_up
		walk_up
		walk_up
		walk_left
	step_end

Movement_MageeVersionProtagonistsHouse_SecretaryLeavesHouse:
		walk_right
		walk_down
		walk_down
		walk_down
	step_end


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////TEXT SCRIPTS////////////////////////////
////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////

Text_MageeVersionProtagonistsHouse_WakeUpYouHaveAChallenger:
	.string "Mr. Magee, you've overslept!\p"
	.string "Wake Up! Wake Up!\p"
	.string "You are late for your challenger!\p"
	.string "As the esteemed Gym Leader of\n"
	.string "Homestead North this is unacceptable!\p"
	.string "Make haste, before you have to forfeit\n"
	.string "and bring shame to our Town!$"

Text_MageeVersionProtagonistsHouse_StillGroggyButOkay:
	.string "I'm up, I'm up.\p"
	.string "Chill back, tell that rat I'll be\n"
	.string "there in a minute...$"

Text_MageeVersionProtagonistsHouse_FineJustHurry:
	.string "Fine, just hurry!$"
