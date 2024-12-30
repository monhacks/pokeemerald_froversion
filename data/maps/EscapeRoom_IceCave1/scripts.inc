EscapeRoom_IceCave1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IceCave1_OnFrame
	.byte 0


IceCave1_OnFrame: @ 8238C4F
	map_script_2 VAR_TEMP_1, 0, IceCave1_EventScript_CheckOverheat
	.2byte 0

IceCave1_EventScript_CheckOverheat::
	goto EventScript_Overheat
	end