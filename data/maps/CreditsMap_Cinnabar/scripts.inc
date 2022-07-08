CreditsMap_Cinnabar_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CreditsMap_Cinnabar_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CreditsMap_Cinnabar_OnWarp
	.byte 0

CreditsMap_Cinnabar_OnWarp:
	map_script_2 VAR_ROUTE101_STATE, 7, Script_CreditsMap_Cinnabar_HidePlayerForCutscene
	.2byte 0

CreditsMap_Cinnabar_OnFrame: @ 81EBCCB
	map_script_2 VAR_ROUTE101_STATE, 7, Script_CreditsMap_Cinnabar_CreditCutscene //Froversion Script
	.2byte 0

Script_CreditsMap_Cinnabar_HidePlayerForCutscene:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CREDITS_MAP_CINNABAR
	end

Script_CreditsMap_Cinnabar_CreditCutscene:
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown51
	msgbox CreditsMap_Cinnabar_Text_Credits, MSGBOX_DEFAULT
	waitmovement OBJ_EVENT_ID_PLAYER
	closemessage
	delay 30
	warpsilent MAP_UNKNOWN_CAVE, 255, 9, 8
	release
	end

CreditsMap_Cinnabar_Text_Credits:
	.string "Pokémon: Burning Shadows\n"
	.string "Presented by Camgotay and Anercomp\p"
	.string "Mapping: Camgotay and Anercomp\p"
	.string "Scripting: Camgotay and Anercomp\p"
	.string "Coding: Camgotay, Anercomp, MGriffin\n"
	.string "Sbird(Karathan), Ghoulslash\p"
	.string "Custom Graphics: Camgotay, Anercomp\p"
	.string "Public Graphics: KyleDove and\n"
	.string "PrincessPhoenix\p"
	.string "Custom Music: Cinnabar Island theme\n"
	.string "written and sequenced by Camgotay\p"
	.string "Public Music: Sequenced by Camgotay\p"
	.string "Storyline: Anercomp and Camgotay\p"
	.string "Thank you for playing!$"