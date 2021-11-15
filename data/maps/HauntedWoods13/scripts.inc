HauntedWoods13_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, HauntedWoos13_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, HauntedWoods13_OnTransition
	.byte 0

HauntedWoos13_OnResume: @ 82396C8
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, HauntedWoods13_EventScript_TryRemoveDracaster
	end

HauntedWoods13_OnTransition::
	compare VAR_SKY_PILLAR_STATE, 2
	goto_if_ge HauntedWoods13_TryShowDracaster
	end

HauntedWoods13_TryShowDracaster::
	call_if_unset FLAG_DEFEATED_RAYQUAZA, HauntedWoods13_ShowDracaster
	return

HauntedWoods13_ShowDracaster:
	clearflag FLAG_HIDE_RAYQUAZA_SKY_TOWER_SUMMIT
	return


HauntedWoods13_EventScript_TryRemoveDracaster:: @ 82396D2
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return


HauntedWoods13_Dracster_Battle:: @ 8239722
	lockall
	waitse
	playmoncry SPECIES_MR_MIME, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_DRACASTER, 50, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SkyPillar_Top_EventScript_DefeatedRayquaza
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SkyPillar_Top_EventScript_RanFromRayquaza
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SkyPillar_Top_EventScript_RanFromRayquaza
	setflag FLAG_DEFEATED_RAYQUAZA
	releaseall
	end
