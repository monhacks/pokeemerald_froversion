CaveOfOrigin_1F_MapScripts:: @ 8235768
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, CaveOfOrigin_1F_OnLoad
	.byte 0

CaveOfOrigin_1F_OnTransition: @ 823576E
	call_if_set FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE, CaveOfOrigin_EventScript_DisableTriggers
	end

CaveOfOrigin_1F_OnLoad:
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_ge SkyPillar_Top_SetExitForNorthHomestead
	end

SkyPillar_Top_SetExitForNorthHomestead:
	setmetatile 12, 4 , 0x2C9, 1
	setmetatile 12, 3 , 0x2C1, 0
	end


	
