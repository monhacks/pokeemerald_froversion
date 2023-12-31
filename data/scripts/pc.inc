EventScript_PC:: @ 8271D92
	lockall
	compare VAR_MAGEE_VERSION, 1
	goto_if_eq EventScript_PCIsBroke
	setvar VAR_0x8004, 0
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu:: @ 8271DAC
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_AccessPC
	end

EventScript_PCIsBroke::
	message gText_PCIsBroke
	waitmessage
	delay 60	
	closemessage
	end

EventScript_AccessPC:: @ 8271DBC
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_AccessHallOfFame
	case 3, EventScript_TurnOffPC
	case MULTI_B_PRESSED, EventScript_TurnOffPC
	end

EventScript_AccessPlayersPC:: @ 8271DF9
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage:: @ 8271E0E
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC:: @ 8271E35
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC:: @ 8271E3E
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

EventScript_TurnOffPC:: @ 8271E47
	setvar VAR_0x8004, 0
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame:: @ 8271E54
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_AccessPC
	end


////PORYGON PC////

Eventscript_Porygon_PCMainMenu:: @ 8271DAC
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto Eventscript_Porygon_AccessPC
	end

Eventscript_Porygon_AccessPC:: @ 8271DBC
	switch VAR_RESULT
	case 0, Eventscript_Porygon_AccessPokemonStorage
	case 1, Eventscript_Porygon_AccessPlayersPC
	case 2, Eventscript_Porygon_AccessHallOfFame
	case 3, Eventscript_Porygon_TurnOffPC
	case MULTI_B_PRESSED, Eventscript_Porygon_TurnOffPC
	end

Eventscript_Porygon_AccessPlayersPC:: @ 8271DF9
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto Eventscript_Porygon_PCMainMenu
	end

Eventscript_Porygon_AccessPokemonStorage:: @ 8271E0E
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, Eventscript_Porygon_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, Eventscript_Porygon_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto Eventscript_Porygon_PCMainMenu
	end

Eventscript_Porygon_AccessSomeonesPC:: @ 8271E35
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

Eventscript_Porygon_AccessLanettesPC:: @ 8271E3E
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

Eventscript_Porygon_TurnOffPC:: @ 8271E47
	setvar VAR_0x8004, 0
	releaseall
	end

Eventscript_Porygon_AccessHallOfFame:: @ 8271E54
	goto_if_unset FLAG_SYS_GAME_CLEAR, Eventscript_Porygon_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto Eventscript_Porygon_AccessPC
	end

	///BAD MUSHROOM//

EventScript_IsBadMushroom:: @ 8271D92
	lockall
	goto_if_unset FLAG_LAKE_MEAD_VILLAGE_HIDE_TILYOU, EventScript_IsBadMushroom_PreInfection
	goto_if_set FLAG_LAKE_MEAD_VILLAGE_HIDE_TILYOU, EventScript_IsBadMushroom_CheckInfectionState
	releaseall	
end
EventScript_BadMushroomDiceRoll:
	goto_if_unset FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_TILYOU, EventScript_IsBadMushroom_FirstBattleGuarentee
	msgbox Text_BadMushroom, MSGBOX_DEFAULT
		random 10
	switch VAR_RESULT
		case 5, EventScript_BlackForestWildPokemonEncounter
		case 3, EventScript_BlackForestWildPokemonEncounter
		case 1, EventScript_BlackForestWildPokemonEncounter
		case 7, EventScript_BlackForestWildPokemonEncounter
		case 9, EventScript_BlackForestWildPokemonEncounter
	releaseall
end
EventScript_IsBadMushroom_PreInfection:
	msgbox Text_PickMushroom, MSGBOX_DEFAULT
	giveitem ITEM_TINY_MUSHROOM, 1
	setflag FLAG_LAKE_MEAD_VILLAGE_HIDE_TILYOU
	releaseall
end
EventScript_IsBadMushroom_CheckInfectionState:
	compare VAR_ROUTE101_STATE, 1
	goto_if_ge EventScript_BadMushroomDiceRoll
	goto_if_le EventScript_IsBadMushroom_AlreadyPickedMushroom
	releaseall
end
EventScript_IsBadMushroom_AlreadyPickedMushroom:
	msgbox Text_AlreadyPickedMushroom, MSGBOX_DEFAULT
	releaseall
end

EventScript_IsBadMushroom_FirstBattleGuarentee:
	msgbox Text_ItLooksLikeSomethingIsHidingInTheMushroom, MSGBOX_DEFAULT
	goto Eventscript_SetWildBattleEscarataco

EventScript_BlackForestWildPokemonEncounter:
		random 5
	switch VAR_RESULT
		case 0, Eventscript_SetWildBattleAriados
		case 1, Eventscript_SetWildBattleEscarataco
		case 2, Eventscript_SetWildBattleShedinja
		case 3, Eventscript_SetWildBattleNinjask
		case 4, Eventscript_SetWildBattleScyther
end

Eventscript_SetWildBattleAriados:
	//setwildbattle SPECIES_ARIADOS, 50, ITEM_NONE
	setwildbattle SPECIES_SPINARAK, 50, ITEM_NONE
dowildbattle
releaseall
end

Eventscript_SetWildBattleEscarataco:
		//setwildbattle SPECIES_ESCARATACO, 50, ITEM_NONE
		setwildbattle SPECIES_PARAS, 50, ITEM_NONE
	dowildbattle
	goto_if_unset FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_TILYOU, EventScript_IsBadMushroom_AfterFirstBattle
	releaseall
	end
EventScript_IsBadMushroom_AfterFirstBattle:
	msgbox Text_LooksLikePokemonLikeToHideInMushrooms, MSGBOX_DEFAULT
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_TILYOU
	releaseall
end
Eventscript_SetWildBattleShedinja:
	setwildbattle SPECIES_SHEDINJA, 50, ITEM_NONE
	dowildbattle
	releaseall
end

Eventscript_SetWildBattleScyther:
	//setwildbattle SPECIES_SCYTHER, 50, ITEM_NONE
	setwildbattle SPECIES_CATERPIE, 50, ITEM_NONE
dowildbattle
releaseall
end

Eventscript_SetWildBattleNinjask:
	setwildbattle SPECIES_NINJASK, 50, ITEM_NONE
dowildbattle
releaseall
end

Text_BadMushroom:
	.string "This mushroom is no good...$"

EventScript_IsWesternApproachTrap:: @ 8271D92
	lockall
	compare VAR_FREDERIC_STATE, 4
	goto_if_le EventScript_WesternApproachNoWildPokemonEncounter
	compare VAR_FREDERIC_STATE, 15
	goto_if_ge EventScript_WesternApproachTrapDisarmed
	msgbox Text_WesternApproachTrap, MSGBOX_DEFAULT
	goto EventScript_WesternApproachWildPokemonEncounter
	releaseall
end

EventScript_WesternApproachTrapDisarmed:
	msgbox Text_TrapDisarmed, MSGBOX_DEFAULT
	releaseall
end

EventScript_WesternApproachNoWildPokemonEncounter:
	msgbox Text_WesternApproachTrapNoPokemon, MSGBOX_DEFAULT
	releaseall
end

EventScript_WesternApproachWildPokemonEncounter:
		random 5
		addvar VAR_FREDERIC_STATE, 1
		finditem ITEM_TRAP
	switch VAR_RESULT
		case 0, Eventscript_SetWildBattleSandslash
		case 1, Eventscript_SetWildBattleDugtrio
		case 2, Eventscript_SetWildBattleGolem
		case 3, Eventscript_SetWildBattleAzumarill
		case 4, Eventscript_SetWildBattlePoliwrath
		releaseall
end

Eventscript_SetWildBattleSandslash:
	setwildbattle SPECIES_SANDSLASH, 50, ITEM_NONE
dowildbattle
releaseall
end

Eventscript_SetWildBattleDugtrio:
	setwildbattle SPECIES_DUGTRIO, 50, ITEM_NONE
dowildbattle
releaseall
end

Eventscript_SetWildBattleGolem:
	setwildbattle SPECIES_GOLEM, 50, ITEM_NONE
dowildbattle
releaseall
end

Eventscript_SetWildBattleAzumarill:
	setwildbattle SPECIES_AZUMARILL, 50, ITEM_NONE
dowildbattle
releaseall
end

Eventscript_SetWildBattlePoliwrath:
	setwildbattle SPECIES_POLIWRATH, 50, ITEM_NONE
dowildbattle
releaseall
end

Text_WesternApproachTrap:
	.string "It appears there is a Pokémon\n"
	.string "stuck in the trap.$"

Text_WesternApproachTrapNoPokemon:
	.string "It appears to be some kind\n"
	.string "of trap.$"

Text_TrapDisarmed:
	.string "The trap has been disarmed.$"

Text_PickMushroom:
	.string "You picked a mushroom.\n"
	.string "They are delicious in soup!$"

Text_AlreadyPickedMushroom:
	.string "Dad's advice...\p"
	.string "Never take more than you need.$"

Text_ItLooksLikeSomethingIsHidingInTheMushroom:
	.string "Wait!\p"
	.string "It looks like something is hiding in\n"
	.string "the mushroom!$"

Text_LooksLikePokemonLikeToHideInMushrooms:
	.string "It seems these mushrooms are now\n"
	.string "large enough to hide wild Pokémon.\p"
	.string "Best to proceed with caution.$"
