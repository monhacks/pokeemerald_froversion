VermillionCity_MAGAHideout_1F_Cutscene_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermillionCity_MAGAHideout_1F_Cutscene_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VermillionCity_MAGAHideout_1F_Cutscene_OnWarp
	.byte 0

VermillionCity_MAGAHideout_1F_Cutscene_OnFrame: @ 8238C4F
	map_script_2 VAR_MAGA_HIDEOUT_GENERATOR_STATE, 1, VermillionCity_MAGAHideout_1F_Cutscene_RevealHiddenStaircaseFrom1F
	map_script_2 VAR_MAGA_HIDEOUT_GENERATOR_STATE, 2, VermillionCity_MAGAHideout_1F_Cutscene_RevealHiddenStaircaseFrom2F
	.byte 0

VermillionCity_MAGAHideout_1F_Cutscene_OnWarp:
	map_script_2 VAR_MAGA_HIDEOUT_GENERATOR_STATE, 1, VermillionCity_MAGAHideout_1F_Cutscene_Hideplayer
	map_script_2 VAR_MAGA_HIDEOUT_GENERATOR_STATE, 2, VermillionCity_MAGAHideout_1F_Cutscene_Hideplayer
	.2byte 0

VermillionCity_MAGAHideout_1F_Cutscene_RevealHiddenStaircaseFrom1F:
	lock
	msgbox VermillionCity_MAGAHideout_1F_Cutscene_Text_AllGeneratorsOff, MSGBOX_AUTOCLOSE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 31, 29, METATILE_Facility_NewMauvilleDoor_Open_Tile0 , 1
	setmetatile 32, 29, METATILE_Facility_NewMauvilleDoor_Open_Tile1 , 1
	setmetatile 33, 29, METATILE_Facility_NewMauvilleDoor_Open_Tile2 , 1
	setmetatile 31, 30, METATILE_Facility_NewMauvilleDoor_Open_Tile3 , 1
	setmetatile 32, 30, METATILE_Facility_NewMauvilleDoor_Open_Tile4 , 0
	setmetatile 33, 30, METATILE_Facility_NewMauvilleDoor_Open_Tile5 , 1
	special DrawWholeMapView
	warpsilent MAP_VERMILLION_CITY_MAGAHIDEOUT_1F, 255, VAR_PLAYER_X, VAR_PLAYER_Y
	release
	end

VermillionCity_MAGAHideout_1F_Cutscene_RevealHiddenStaircaseFrom2F:
	lock
	msgbox VermillionCity_MAGAHideout_1F_Cutscene_Text_AllGeneratorsOff, MSGBOX_AUTOCLOSE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 31, 29, METATILE_Facility_NewMauvilleDoor_Open_Tile0 , 1
	setmetatile 32, 29, METATILE_Facility_NewMauvilleDoor_Open_Tile1 , 1
	setmetatile 33, 29, METATILE_Facility_NewMauvilleDoor_Open_Tile2 , 1
	setmetatile 31, 30, METATILE_Facility_NewMauvilleDoor_Open_Tile3 , 1
	setmetatile 32, 30, METATILE_Facility_NewMauvilleDoor_Open_Tile4 , 0
	setmetatile 33, 30, METATILE_Facility_NewMauvilleDoor_Open_Tile5 , 1
	special DrawWholeMapView
	warpsilent MAP_VERMILLION_CITY_MAGAHIDEOUT_2F, 255, VAR_PLAYER_X, VAR_PLAYER_Y
	release
	end

VermillionCity_MAGAHideout_1F_Cutscene_Hideplayer::
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_VERMILLION_CITY_MAGAHIDEOUT_1F_CUTSCENE
	release
	end 

VermillionCity_MAGAHideout_1F_Cutscene_Text_AllGeneratorsOff:
	.string "All the generators are off.\n"
	.string "Something is happening...$"