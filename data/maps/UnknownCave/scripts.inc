UnknownCave_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UnknownCave_OnFrame
	.byte 0

UnknownCave_OnFrame: @ 81EBCCB
	map_script_2 VAR_ROUTE101_STATE, 7, Script_UnknownCave_PostGameEvent //Froversion Script
	map_script_2 VAR_ROUTE101_STATE, 0, Script_UnknownCave_BossBattleTestSetup //Script for boss battle
	.2byte 0
	
Script_UnknownCave_PostGameEvent:
	lock
	msgbox UnknownCave_Text_PlayerWokeUpInCave, MSGBOX_DEFAULT
	setvar VAR_ROUTE101_STATE, 8
	release
	end

Script_UnknownCave_BossBattleTestSetup:
	setflag FLAG_SYS_POKEMON_GET
	msgbox PleaseBePatient, MSGBOX_DEFAULT
	givecustommon SPECIES_LUTRADOR, 50, ITEM_NONE
	givecustommon SPECIES_CLEFAIRY, 50, ITEM_NONE 
	givecustommon SPECIES_ARIADOS, 50, ITEM_NONE 
	givecustommon SPECIES_MACHAMP, 50, ITEM_NONE 
	givecustommon SPECIES_GOLEM, 50, ITEM_NONE 
	givecustommon SPECIES_MAROWAK, 50, ITEM_NONE 
	givecustommon SPECIES_CRADILY, 50, ITEM_NONE
	givecustommon SPECIES_LUNATONE, 50, ITEM_NONE 
	givecustommon SPECIES_SOLROCK, 50, ITEM_NONE 
	givecustommon SPECIES_AZUMARILL, 50, ITEM_NONE 
	givecustommon SPECIES_POLIWRATH, 50, ITEM_NONE 
	givecustommon SPECIES_MILOTIC, 50, ITEM_NONE 
	givecustommon SPECIES_SANDSLASH, 50, ITEM_NONE 
	givecustommon SPECIES_WARTHAAG, 50, ITEM_NONE 
	givecustommon SPECIES_SCYTHER, 50, ITEM_NONE 
	givecustommon SPECIES_SCIZOR, 50, ITEM_NONE 
	givecustommon SPECIES_CRACKTUSS, 50, ITEM_NONE 
	givecustommon SPECIES_HOUNDOOM, 50, ITEM_NONE 
	givecustommon SPECIES_UMBREON, 50, ITEM_NONE  
	givecustommon SPECIES_GLALIE, 50, ITEM_NONE
	setvar VAR_ROUTE101_STATE, 1
	release
	end
		

UnknownCave_Text_PlayerWokeUpInCave:
	.string "After the events on Cinnabar\n"
	.string "{PLAYER} woke up in a cave\l"
	.string "with no recollection of what\l"
	.string "happened or how he ended up here.$"

PleaseBePatient:
	.string "Please be Patient, loading Pokémon\n"
	.string "into party and pc.$"
	