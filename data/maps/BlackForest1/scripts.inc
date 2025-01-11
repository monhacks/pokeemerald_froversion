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
	goto_if_set FLAG_FOUND_CIPHER, EventScript_IsBadMushroom
	msgbox BlackForest1_Text_WildGastlyBattle, MSGBOX_DEFAULT
	playmoncry SPECIES_GASTLY, 2
	setwildbattle SPECIES_GASTLY, 50, ITEM_NONE
	waitmoncry
	special StartGastlyBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq WildBattleSpecialGastlyOutcomeRan
	msgbox BlackForest1_Text_WildGastlyDroppedThis, MSGBOX_DEFAULT
	// FROVERSION SCRIPT giveitem ITEM_SPELLBOOK, 1
	giveitem ITEM_POKEPRIMER, 1
	msgbox BlackForest1_Text_WildGastlyWantsToJoinParty, MSGBOX_DEFAULT
	playmoncry SPECIES_GASTLY, 2
	removeobject 6
	waitmoncry
	playfanfare MUS_OBTAIN_ITEM
	givecustommon SPECIES_GASTLY, 50, ITEM_LEFTOVERS, ITEM_DUSK_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_SUBSTITUTE, 0
	waitfanfare
	setflag FLAG_FOUND_CIPHER
	release
end

WildBattleSpecialGastlyOutcomeRan:
	release
end

BlackForest1_EventScript_ProfessorsBag::
	lock
	msgbox BlackForest1_Text_ProfessorsBagFound, MSGBOX_DEFAULT
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
	msgbox BlackForest1_Text_ProfessorsBagFoundRunningShoes, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	release
	end



EventScript_BlackForest1_Venusaur::
	playmoncry SPECIES_VENUSAUR, 2
	setwildbattle SPECIES_VENUSAUR, 50, ITEM_NONE
	waitmoncry
	special StartVenusaurBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq WildBattleSpecialVenusaurOutcomeRan
	msgbox Text_BlackForest3_VenusaurJoins, MSGBOX_DEFAULT
	playmoncry SPECIES_VENUSAUR, 2
	removeobject 7
	waitmoncry
	playfanfare MUS_OBTAIN_ITEM
	givecustommon SPECIES_VENUSAUR, 50, ITEM_LEFTOVERS, ITEM_DUSK_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_CURSE, MOVE_SLUDGE_BOMB, MOVE_LEECH_SEED, MOVE_SYNTHESIS, 0
	waitfanfare
	setflag FLAG_ITEM_MOUNT_CINNABAR_NORTHWEST_1F_MAX_REVIVE
	release
	end

WildBattleSpecialVenusaurOutcomeRan:
	playmoncry SPECIES_VENUSAUR, 2
	removeobject 7
	waitmoncry
	msgbox BlackForest3_Text_WildVenusaurRan, MSGBOX_DEFAULT
	setflag FLAG_ITEM_MOUNT_CINNABAR_NORTHWEST_1F_MAX_REVIVE
	release
end

BlackForest1_Text_WildVenusaurRan:
	.string "The wild Venusaur ran away in the\n"
	.string "opposite direction!$"



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

BlackForest1_Text_WildGastlyWantsToJoinParty:
	.string "The wild Gastly seems to want to join\n"
	.string "you after you've defeated it.\p"
	.string "{PLAYER} allows Gastly to join the\n"
	.string  "party.$"

BlackForest1_Text_ProfessorsBagFoundRunningShoes:	
	.string "{PLAYER} Also found a pair of running\n"
	.string "shoes in the Professor's Bag.\p"
	.string "Might as well wear them until you\n"
	.string "find the professor to return them.$"
	
BlackForest1_Text_ProfessorsBagFound:
	.string "{PLAYER} found a bag.\p"
	.string "“This Bag Belongs to Professor\n"
	.string "Gooseberry”\p"
	.string "It looks like there is a Diary\n"
	.string "inside.$"

BlackForest1_Text_WildGastlyRan:
	.string "The wild Gastly ran away in the\n"
	.string "opposite direction!$"

BlackForest3_Text_WildVenusaurRan:
	.string "The wild Venusaur ran away in the\n"
	.string "opposite direction!$"

Text_BlackForest3_VenusaurJoins:
	.string "The wild Venusaur seems to want to join\n"
	.string "you after you've defeated it.\p"
	.string "{PLAYER} allows Venusaur to join the\n"
	.string  "party.$"

