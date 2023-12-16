NewMap1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMap1_OnLoad
	.byte 0

NewMap1_OnLoad:
	goto_if_set FLAG_MAGEE_VERSION, NewMap1_EventScript_SetDynamicWarpMageeVersion
	goto_if_unset FLAG_MAGEE_VERSION, NewMap1_EventScript_SetDynamicWarpFroVersion
	end

NewMap1_EventScript_SetDynamicWarpMageeVersion:
	setdynamicwarp MAP_MAGM8FOREST_TOWN, 255, 24, 9
end

NewMap1_EventScript_SetDynamicWarpFroVersion:
	setdynamicwarp MAP_NIAGARA_VILLAGE, 255, 24, 9
end

MAGM8Forest_MainArea_EventScripts_SouthSign::
	lock
	msgbox MAGM8Forest_MainArea_Text_SouthSign, MSGBOX_SIGN
	release
end

MAGM8Forest_MainArea_EventScripts_NorthSign::
	lock
	msgbox MAGM8Forest_MainArea_Text_NorthSign, MSGBOX_SIGN
	release
end

MAGM8Forest_MainArea_Eventscripts_HouseSign::
	lock
	msgbox MAGM8Forest_MainArea_Text_HouseSign, MSGBOX_SIGN
	release
end

MAGM8Forest_MainArea_Text_HouseSign:
	.string "{PLAYER}'s House:\n"
	.string "No Trespassing!$"

MAGM8Forest_MainArea_Text_NorthSign:
	.string "{UP_ARROW} Northern Woods\n"
	.string "{DOWN_ARROW} {PLAYER}'s House$"
	
MAGM8Forest_MainArea_Text_SouthSign:
	.string "{UP_ARROW} {PLAYER}'s House\n"
	.string "{DOWN_ARROW}$ Town Name"
