MAGM8ForestTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MAGM8ForestTown_OnLoad
	.byte 0

MAGM8ForestTown_OnLoad: @ 822D989
	call_if_set FLAG_SYS_GAME_CLEAR, MAGM8ForestTown_EventScript_RevealBlackForest
	end

MAGM8ForestTown_EventScript_RevealBlackForest:: @ 822D993
	setmetatile 23, 6, 0x025, 1
	setmetatile 24, 6, 0x026, 1
	setmetatile 23, 7, 0x018, 0
	setmetatile 24, 7, 0x018, 0
	setmetatile 23, 8, 0x08F, 0
	setmetatile 24, 8, 0x08F, 0
	return