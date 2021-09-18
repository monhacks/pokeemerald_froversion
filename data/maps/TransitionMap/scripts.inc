TransitionMap_MapScripts:: @ 81EBCBA
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TransitionMap_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TransitionMap_OnWarp
	.byte 0

TransitionMap_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 6, Script_TransitionMap_HidePlayerForMagaCutscene
	.2byte 0

TransitionMap_OnFrame: @ 81EBCCB
	map_script_2 VAR_PETALBURG_CITY_STATE, 6, Script_TransitionMap_MagaCaveCutscene //Froversion Script
	.2byte 0

Script_TransitionMap_HidePlayerForMagaCutscene:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_TRANSITION_MAP
	end

Script_TransitionMap_MagaCaveCutscene:
	lockall
	special ShowMapNamePopup
	delay 210
	applymovement 3, M_Grunt1FacesGrunt2
	applymovement 4, M_Grunt2FacesGrunt1
	waitmovement 4
	msgbox T_TransitionMap_PrototypeActingUp, MSGBOX_DEFAULT
	delay 30
	applymovement 3, M_Grunt1EnterCave
	waitmovement 3
	removeobject 3
	applymovement 4, M_Grunt2EnterCave
	waitmovement 4
	removeobject 4
	setvar VAR_PETALBURG_CITY_STATE, 7
	warpsilent MAP_PETALBURG_CITY, 255, 10, 6
	end

T_TransitionMap_PrototypeActingUp:
	.string "There seems to be an issue with the\n"
	.string "test subject. Jerett wants us to get\l"
	.string "it under control.\p"
	.string "Grunt 2: The subject is deep underground.\n"
	.string "We better get going, it's going to be a\l"
	.string "long time before we can reach him to see\l"
	.string "what the issue is!$"
