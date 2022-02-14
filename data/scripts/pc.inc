EventScript_PC:: @ 8271D92
	lockall
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
	msgbox Text_BadMushroom, MSGBOX_DEFAULT
		random 10
	switch VAR_RESULT
		case 5, EventScript_BlackForestWildPokemonEncounter
	releaseall
end

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
	setwildbattle SPECIES_ARIADOS, 50, ITEM_NONE
dowildbattle
releaseall
end

Eventscript_SetWildBattleEscarataco:
	setwildbattle SPECIES_ESCARATACO, 50, ITEM_NONE
dowildbattle
releaseall
end

Eventscript_SetWildBattleShedinja:
	setwildbattle SPECIES_SHEDINJA, 50, ITEM_NONE
dowildbattle
releaseall
end

Eventscript_SetWildBattleScyther:
	setwildbattle SPECIES_SCYTHER, 50, ITEM_NONE
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