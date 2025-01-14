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
	map_script_2 VAR_MAGEE_VERSION, 1, LakeMead_FrosHouse_1F_SetFroWest
	.2byte 0

VermillionCityMageesPleasureFactoryOffice_EventScript_GruntsTakeMetagross:
	lockall
		addobject LOCALID_GRUNT_1
		addobject LOCALID_GRUNT_2
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
	releaseall
	end

VermillionCityMageesPleasureFactoryOffice_Movement_Grunt2_Leaving:
	walk_right
	walk_up
	step_end

VermillionCityMageesPleasureFactoryOffice_Text_GruntsTakeMetagross:
	.string "This will be the text$"
