MountCinnabar_Summit_MapScripts::
	.byte 0


MountCinnabar_Summit_ShadowPrimeapeBattle::
	lock
		faceplayer
		waitse
		playmoncry SPECIES_PRIMEAPE, 2
		delay 40
		waitmoncry
		setwildbattle SPECIES_PRIMEAPE, 45, ITEM_NONE
		setflag FLAG_SYS_CTRL_OBJ_DELETE
		special StartPrimeapeBattle
		waitstate
		clearflag FLAG_SYS_CTRL_OBJ_DELETE
		specialvar VAR_RESULT, GetBattleOutcome
		compare VAR_RESULT, B_OUTCOME_WON
		goto_if_eq AncientTomb_EventScript_DefeatedRegisteel
		compare VAR_RESULT, B_OUTCOME_RAN
		goto_if_eq AncientTomb_EventScript_RanFromRegisteel
		compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
		goto_if_eq AncientTomb_EventScript_RanFromRegisteel
		setflag FLAG_DEFEATED_REGISTEEL
	release
	end