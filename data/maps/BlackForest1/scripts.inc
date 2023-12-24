BlackForest1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackForest1_OnLoad
	.byte 0

BlackForest1_OnLoad: @ 822D989
	call_if_unset FLAG_TEMP_1, BlackForest1_SetWildBattleLocation
	end

BlackForest1_SetWildBattleLocation:
	setvar VAR_TEMP_1, 3
	return

///////////////////////////////////
////////FROVERSION SCRIPT/////////
/////////////////////////////////
	//random 5
	//switch VAR_RESULT
	//	case 0, BlackForest1_EventScript_SetWildBattleLocation0
	//	case 1, BlackForest1_EventScript_SetWildBattleLocation1
	//	case 2, BlackForest1_EventScript_SetWildBattleLocation2
	//	case 3, BlackForest1_EventScript_SetWildBattleLocation3
	//	case 4, BlackForest1_EventScript_SetWildBattleLocation4
	//return

BlackForest1_EventScript_SetWildBattleLocation0:
	return

BlackForest1_EventScript_SetWildBattleLocation1:
	setvar VAR_TEMP_1, 1
	return
	
BlackForest1_EventScript_SetWildBattleLocation2:
	setvar VAR_TEMP_1, 2
	return	

BlackForest1_EventScript_SetWildBattleLocation3:
	setvar VAR_TEMP_1, 3
	return
	
BlackForest1_EventScript_SetWildBattleLocation4:
	setvar VAR_TEMP_1, 4
	return

BlackForest1_EventScript_WildBattleSpecialGastlyLocationCheck0::
	lock
	compare VAR_TEMP_1, 0
	goto_if_eq BlackForest1_EventScript_WildBattleSpecialGastly
	goto EventScript_IsBadMushroom
end

BlackForest1_EventScript_WildBattleSpecialGastlyLocationCheck1::
	lock
	compare VAR_TEMP_1, 1
	goto_if_eq BlackForest1_EventScript_WildBattleSpecialGastly
	goto EventScript_IsBadMushroom
end

BlackForest1_EventScript_WildBattleSpecialGastlyLocationCheck2::
	lock
	compare VAR_TEMP_1, 2
	goto_if_eq BlackForest1_EventScript_WildBattleSpecialGastly
	goto EventScript_IsBadMushroom
end

BlackForest1_EventScript_WildBattleSpecialGastlyLocationCheck3::
	lock
	compare VAR_TEMP_1, 3
	goto_if_eq BlackForest1_EventScript_WildBattleSpecialGastly
	goto EventScript_IsBadMushroom
end

BlackForest1_EventScript_WildBattleSpecialGastlyLocationCheck4::
	lock
	compare VAR_TEMP_1, 4
	goto_if_eq BlackForest1_EventScript_WildBattleSpecialGastly
	goto EventScript_IsBadMushroom
end

BlackForest1_EventScript_WildBattleSpecialGastly:
	goto_if_set FLAG_RECEIVED_SPELLBOOK, EventScript_IsBadMushroom
	msgbox BlackForest1_Text_WildGastlyBattle, MSGBOX_DEFAULT
	setwildbattle SPECIES_GASTLY, 50, ITEM_NONE
	dowildbattle
	msgbox BlackForest1_Text_WildGastlyDroppedThis, MSGBOX_DEFAULT
	// FROVERSION SCRIPT giveitem ITEM_SPELLBOOK, 1
	giveitem ITEM_POKEPRIMER, 1
	setflag FLAG_RECEIVED_SPELLBOOK
	release
end

BlackForest1_EventScript_Clue1_LanguageDetermine::
	lock
	checkitem ITEM_POKEPRIMER, 1
	compare VAR_RESULT, TRUE
	goto_if_eq BlackForest1_EventScript_Clue1_English
	msgbox BlackForest1_Text_Clue1BadLanguage, MSGBOX_DEFAULT
	release
end

BlackForest1_EventScript_Clue1_English:
	msgbox BlackForest1_Text_Clue1English, MSGBOX_DEFAULT
	release
end

BlackForest1_EventScript_ProfessorsBag::
	lock
	msgbox BlackForest1_Text_ProfessorsJournalEntry1, MSGBOX_DEFAULT
	release
end

BlackForest1_Text_Clue1BadLanguage:
	.string "Dra Tenaldeuh ec Mavd.$"

BlackForest1_Text_Clue1English:
	.string "The Direction is LEFT.$"


BlackForest1_Text_WildGastlyBattle:
	.string "There's something strange about this\n"
	.string  "mushroom...$"

BlackForest1_Text_WildGastlyDroppedThis:
	.string "It looks like the Pokémon dropped\n"
	.string "something.$"

BlackForest1_Text_ProfessorsJournalEntry1:
	.string "11/23/1911 - I have made it through\n"
	.string "the Lost Woods after years and years\l"
	.string "of research.\p"
	.string "It is even more magnificent than I\n"
	.string "imagined.$"
