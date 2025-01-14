.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2

VermillionCityMageesPleasureFactoryOffice_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermillionCityMageesPleasureFactoryOffice_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VermillionCityMageesPleasureFactoryOffice_OnWarp
	.byte 0

VermillionCityMageesPleasureFactoryOffice_OnFrame:
	map_script_2 VAR_MAGEE_VERSION, 1, VermillionCityMageesPleasureFactoryOffice_EventScript_GruntsTakeMetagross
	.2byte 0

VermillionCityMageesPleasureFactoryOffice_OnWarp::
	map_script_2 VAR_MAGEE_VERSION, 1, LakeMead_FrosHouse_1F_SetMageeWestAddGrunts
	.2byte 0

LakeMead_FrosHouse_1F_SetMageeWestAddGrunts:
		addobject LOCALID_GRUNT_1
		addobject LOCALID_GRUNT_2
		turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	end

VermillionCityMageesPleasureFactoryOffice_EventScript_GruntsTakeMetagross:
	lockall
		msgbox VermillionCityMageesPleasureFactoryOffice_Text_GruntsTakeMetagross, MSGBOX_AUTOCLOSE
		applymovement LOCALID_GRUNT_1, Common_Movement_WalkUp4
		applymovement LOCALID_GRUNT_2, Common_Movement_WalkUp4
		waitmovement LOCALID_GRUNT_2
		applymovement LOCALID_GRUNT_2, VermillionCityMageesPleasureFactoryOffice_Movement_Grunt2_Leaving
		waitmovement LOCALID_GRUNT_2
		applymovement LOCALID_GRUNT_1, Common_Movement_WalkUp
		applymovement LOCALID_GRUNT_2, Common_Movement_WalkUp
		waitmovement LOCALID_GRUNT_2
		removeobject LOCALID_GRUNT_1
		removeobject LOCALID_GRUNT_2
		setvar VAR_MAGEE_VERSION,2
		playbgm MUS_FV_SANDY_BEACH, 0
	releaseall
	end

VermillionCityMageesPleasureFactoryOffice_Movement_Grunt2_Leaving:
	walk_right
	walk_up
	step_end

VermillionCityMageesPleasureFactoryOffice_Text_GruntsTakeMetagross:
	.string "MAGA Grunt: {PLAYER}, my man. We've got\n"
	.string "a problem. You know I don't like\l"
	.string "problems.\p"
	.string "{PLAYER}: Look, I-I know I'm behind,\n"
	.string "but the shop's been slow.\p"
	.string "The holidays are coming, though! I\n"
	.string "just need a little more time-\p"
	.string "MAGA Grunt: Time? You want time? My\n"
	.string "boss, he doesn't care about your\l"
	.string "holidays or your slow business. What\l"
	.string "he cares about is that you're three\l"
	.string "weeks behind.\p"
	.string "{PLAYER}: I'm trying, I swear!\p"
	.string "MAGA Grunt: Trying ain't enough. You\n"
	.string "borrowed the capital, {PLAYER}, and with\l"
	.string "it came responsibilities.\p"
	.string "My boss, he's not a patient guy. So\n"
	.string "here's what's gonna happen. We're\l"
	.string "taking some collateral.\p"
	.string "{PLAYER}: Collateral? W-what kind of\n"
	.string "collateral?\p"
	.string "MAGA Grunt: Whatever holds value. That\n"
	.string "shiny car of yours? That fancy watch\l"
	.string "you always wear?\p"
	.string "Or maybe your Pokémon.\p"
	.string "{PLAYER}: No please! Metagross-he's\n"
	.string "my best friend!\p"
	.string "MAGA Grunt: Look, {PLAYER}, I'm not in\n"
	.string "this business to make enemies, but\l"
	.string "I'm also not running a daycare.\p"
	.string "You're behind, and there are\n"
	.string "consequences.\p"
	.string "My hands are tied. Now we're going to\n"
	.string "leave and take Metagross, and next\l"
	.string "time we come back for our money maybe\l"
	.string "you'll remember this!$"
	