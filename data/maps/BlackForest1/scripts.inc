.set LOCALID_SCROLLINGMENU_PROFESSORS_JOURNAL_INITIAL, 15 //references 15 in sScrollingSets located in script_menu.c

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

BlackForest1_EventScript_ProfessorsBag::
	lock
	finditem ITEM_DIARY,1
	finddiaryentry DIARY_ENTRY_TWENTIETH
	finddiaryentry DIARY_ENTRY_NINETEENTH
	finddiaryentry DIARY_ENTRY_EIGHTEENTH
	finddiaryentry DIARY_ENTRY_SEVENTEENTH
	finddiaryentry DIARY_ENTRY_SIXTEENTH
	finddiaryentry DIARY_ENTRY_FIFTEENTH
	finddiaryentry DIARY_ENTRY_FOURTEENTH
	finddiaryentry DIARY_ENTRY_THIRTEENTH
	clearflag FLAG_ITEM_ROUTE_132_PROTEIN                                 
	clearflag FLAG_ITEM_ROUTE_133_MAX_REVIVE                              
	clearflag FLAG_ITEM_ROUTE_134_CARBOS                                  
	clearflag FLAG_ITEM_ROUTE_134_STAR_PIECE                              
	clearflag FLAG_ITEM_ROUTE_114_ENERGY_POWDER                           
	clearflag FLAG_ITEM_ROUTE_115_PP_UP                                   
	clearflag FLAG_ITEM_ARTISAN_CAVE_B1F_HP_UP                            
	clearflag FLAG_ITEM_ARTISAN_CAVE_1F_CARBOS                            
	clearflag FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAX_ELIXIR                    
	clearflag FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_FULL_RESTORE                  
	clearflag FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_NUGGET                        
	clearflag FLAG_ITEM_MAGMA_HIDEOUT_3F_2R_PP_MAX                        
	clearflag FLAG_ITEM_MAGMA_HIDEOUT_4F_MAX_REVIVE                       
	clearflag FLAG_ITEM_SAFARI_ZONE_NORTH_EAST_NUGGET                     
	clearflag FLAG_ITEM_SAFARI_ZONE_SOUTH_EAST_BIG_PEARL
	release
	end


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
