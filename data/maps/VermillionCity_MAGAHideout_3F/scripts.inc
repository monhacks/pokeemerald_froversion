VermillionCity_MAGAHideout_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermillionCity_MAGAHideout_3F_OnLoad
	.byte 0

VermillionCity_MAGAHideout_3F_OnLoad:
	goto_if_defeated TRAINER_DYLAN_5, VermillionCity_MAGAHideout_3F_EventScript_RevealHiddenStaircaseOnLoad
	end

VermillionCity_MAGAHideout_3F_EventScript_RevealHiddenStaircaseOnLoad:
	setmetatile 12, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0 , 1
	setmetatile 13, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1 , 1
	setmetatile 14, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1 , 1
	setmetatile 15, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2 , 1
	setmetatile 12, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3 , 1
	setmetatile 13, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4 , 0
	setmetatile 14, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4 , 0
	setmetatile 15, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5 , 1
	setmetatile 12, 2, 0x340 , 0
	setmetatile 13, 2, 0x340, 0
	setmetatile 14, 2, 0x340, 0
	setmetatile 15, 2, 0x340 , 0
	setmetatile 12, 3, 0x340 , 0
	setmetatile 13, 3, 0x340, 0
	setmetatile 14, 3, 0x340, 0
	setmetatile 15, 3, 0x340 , 0
	setmetatile 12, 4, 0x340, 0
	setmetatile 13, 4, 0x340, 0
	setmetatile 14, 4, 0x340, 0
	setmetatile 15, 4, 0x340, 0
	setmetatile 12, 5, 0x340, 0
	setmetatile 13, 5, 0x340, 0
	setmetatile 14, 5, 0x340, 0
	setmetatile 15, 5, 0x340, 0
	special DrawWholeMapView
	release
	end


MAGAHideout3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_DYLAN_5, MAGAHideout3F_Text_Grunt1Intro, MAGAHideout3F_Text_Grunt1Defeated
	msgbox MAGAHideout3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MAGAHideout3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_MARIA_1, MAGAHideout3F_Text_Grunt2Intro, MAGAHideout3F_Text_Grunt2Defeated
	msgbox MAGAHideout3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MAGAHideout3F_EventScript_Grunt3::
	trainerbattle_single TRAINER_MARIA_2, MAGAHideout3F_Text_Grunt3Intro, MAGAHideout3F_Text_Grunt3Defeated
	msgbox MAGAHideout3F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MAGAHideout3F_EventScript_Grunt4::
	trainerbattle_single TRAINER_MARIA_3, MAGAHideout3F_Text_Grunt4Intro, MAGAHideout3F_Text_Grunt4Defeated
	msgbox MAGAHideout3F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MAGAHideout3F_EventScript_Grunt5::
	trainerbattle_single TRAINER_MARIA_4, MAGAHideout3F_Text_Grunt5Intro, MAGAHideout3F_Text_Grunt5Defeated
	msgbox MAGAHideout3F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MAGAHideout3F_EventScript_Grunt6::
	trainerbattle_single TRAINER_MARIA_5, MAGAHideout3F_Text_Grunt6Intro, MAGAHideout3F_Text_Grunt6Defeated
	msgbox MAGAHideout3F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

VermillionCity_MAGAHideout_3F_EventScript_FinalGenerator::
lock
	msgbox VermillionCity_MAGAHideout_1F_Text_YouTurnedOffTheGenerator, MSGBOX_AUTOCLOSE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setmetatile 12, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0 , 1
	setmetatile 13, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1 , 1
	setmetatile 14, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1 , 1
	setmetatile 15, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2 , 1
	setmetatile 12, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3 , 1
	setmetatile 13, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4 , 0
	setmetatile 14, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4 , 0
	setmetatile 15, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5 , 1
	setmetatile 12, 2, 0x340 , 0
	setmetatile 13, 2, 0x340, 0
	setmetatile 14, 2, 0x340, 0
	setmetatile 15, 2, 0x340 , 0
	setmetatile 12, 3, 0x340 , 0
	setmetatile 13, 3, 0x340, 0
	setmetatile 14, 3, 0x340, 0
	setmetatile 15, 3, 0x340 , 0
	setmetatile 12, 4, 0x340, 0
	setmetatile 13, 4, 0x340, 0
	setmetatile 14, 4, 0x340, 0
	setmetatile 15, 4, 0x340, 0
	setmetatile 12, 5, 0x340, 0
	setmetatile 13, 5, 0x340, 0
	setmetatile 14, 5, 0x340, 0
	setmetatile 15, 5, 0x340, 0
	special DrawWholeMapView
release
end
