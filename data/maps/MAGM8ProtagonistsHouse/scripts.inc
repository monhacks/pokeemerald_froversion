//FLAG_0x4EB == FLAG_TO_DO_LIST_CHECKED
.set LOCALID_SCROLLINGMENU_FIRST_TO_DO_LIST, 13

MAGM8ProtagonistsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MAGM8ProtagonistsHouse_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MAGM8ProtagonistsHouse_OnWarp
	.byte 0

MAGM8ProtagonistsHouse_OnLoad:
	compare VAR_ROUTE101_STATE, 1
	call_if_ge MAGM8ProtagonistsHouse_EventScript_SetDynamicWarpPostInfection
	call_if_lt MAGM8ProtagonistsHouse_EventScript_SetDynamicWarpPreInfection
	end

MAGM8ProtagonistsHouse_OnWarp:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, MAGM8ProtagonistsHouse_SetProtagWest
	.2byte 0

MAGM8ProtagonistsHouse_SetProtagWest:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	addvar VAR_LITTLEROOT_INTRO_STATE, 1
	end

MAGM8ProtagonistsHouse_EventScript_SetDynamicWarpPreInfection:
	setdynamicwarp MAP_MAGM8BLACK_FOREST_PRE_INFECTION, 255, 29, 32
end

MAGM8ProtagonistsHouse_EventScript_SetDynamicWarpPostInfection:
	setdynamicwarp MAP_NEW_MAP1, 255, 29, 32
end

MAGM8ProtagonistsHouse_EventScript_PreventPlayerFromLeavingUntilToDoListChecked::
	lock
		goto_if_set FLAG_0x4EB, MAGM8ProtagonistsHouse_EventScript_ToDoListHasBeenChecked
		msgbox MAGM8ProtagonistsHouse_Text_CheckToDoList, MSGBOX_DEFAULT
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
		waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
		MAGM8ProtagonistsHouse_EventScript_ToDoListHasBeenChecked:
	release
	end
		
MAGM8ProtagonistsHouse_EventScript_ToDoList::
	lock
		msgbox MAGM8ProtagonistsHouse_Text_ToDoList, MSGBOX_YESNO
		switch VAR_RESULT
		case NO, MAGM8ProtagonistsHouse_EventScript_ToDoListExit
		case YES, MAGM8ProtagonistsHouse_EventScript_ShowToDoList
		case MULTI_B_PRESSED, MAGM8ProtagonistsHouse_EventScript_ToDoListExit
	release
	end	
MAGM8ProtagonistsHouse_EventScript_ToDoListExit:
	release
	end
MAGM8ProtagonistsHouse_EventScript_ShowToDoList:
			closemessage
			scrollingmultichoice LOCALID_SCROLLINGMENU_FIRST_TO_DO_LIST, 2, 3, 2, TRUE
			switch VAR_RESULT
				case 0, MAGM8ProtagonistsHouse_EventScript_ToDoListHarvestMushrooms
				case 1, MAGM8ProtagonistsHouse_EventScript_ToDoListGoToTownForMedicine
				case MULTI_B_PRESSED, MAGM8ProtagonistsHouse_EventScript_ToDoListExit
	release
	end
MAGM8ProtagonistsHouse_EventScript_ToDoListHarvestMushrooms:
		setflag FLAG_0x4EB
		msgbox MAGM8ProtagonistsHouse_Text_ToDoListHarvestMushrooms, MSGBOX_DEFAULT
		goto MAGM8ProtagonistsHouse_EventScript_ShowToDoList
MAGM8ProtagonistsHouse_EventScript_ToDoListGoToTownForMedicine:
		setflag FLAG_0x4EB
		msgbox MAGM8ProtagonistsHouse_Text_ToDoListGoToTownForMedicine, MSGBOX_DEFAULT
		goto MAGM8ProtagonistsHouse_EventScript_ShowToDoList

MAGM8ProtagonistsHouse_EventScript_MakeSoup::
	lockall
			goto_if_set FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY, MAGM8ProtagonistsHouse_EventScript_AlreadyMadeSoup

			msgbox MAGM8ProtagonistsHouse_Text_WouldYouLikeToMakeSoup, MSGBOX_YESNO
				switch VAR_RESULT
				case NO, MAGM8ProtagonistsHouse_EventScript_WouldYouLikeToMakeSoupEnd
				case YES, MAGM8ProtagonistsHouse_EventScriptWouldYouLikeToMakeSoupYes
				case NO, MAGM8ProtagonistsHouse_EventScript_WouldYouLikeToMakeSoupEnd
MAGM8ProtagonistsHouse_EventScriptWouldYouLikeToMakeSoupYes:
			checkitem ITEM_TINY_MUSHROOM, 1
			compare VAR_RESULT, FALSE
			goto_if_eq MAGM8ProtagonistsHouse_EventScript_MissingIngredientToMakeSoup
			msgbox MAGM8ProtagonistsHouse_Text_PrepareSoup, MSGBOX_DEFAULT
			playse SE_M_CUT
			waitse
			playse SE_M_HARDEN
			waitse
			playse SE_M_CUT
			waitse
			msgbox MAGM8ProtagonistsHouse_Text_SoupReady, MSGBOX_DEFAULT
			applymovement OBJ_EVENT_ID_PLAYER, MAGM8ProtagonistsHouse_Movement_MoveToTable
			waitmovement OBJ_EVENT_ID_PLAYER
			playse SE_M_BITE
			waitse
			playse SE_M_BITE
			waitse
			msgbox MAGM8ProtagonistsHouse_Text_PlayerFeelsSleepy, MSGBOX_DEFAULT
			removeitem ITEM_TINY_MUSHROOM, 1
			setflag FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY
MAGM8ProtagonistsHouse_EventScript_WouldYouLikeToMakeSoupEnd:
	releaseall
end

MAGM8ProtagonistsHouse_EventScript_AlreadyMadeSoup:
	msgbox MAGM8ProtagonistsHouse_Text_AlreadyMadeSoup, MSGBOX_DEFAULT
	releaseall
end

MAGM8ProtagonistsHouse_EventScript_MissingIngredientToMakeSoup::
		msgbox MAGM8ProtagonistsHouse_Text_CantMakeSoupWithoutMushroom, MSGBOX_DEFAULT
	releaseall
end

MAGM8ProtagonistsHouse_EventScript_SickPokemon::
	lockall
	goto_if_set FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN, MAGM8ProtagonistsHouse_EventScript_SickPokemonAlreadyGivenMedicine
	msgbox MAGM8ProtagonistsHouse_Text_PokemonIsSick, MSGBOX_NPC
	msgbox MAGM8ProtagonistsHouse_Text_WouldYouLikeToGiveMedicineToSickPokemon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MAGM8ProtagonistsHouse_EventScript_SickPokemonEnd
	case YES, MAGM8ProtagonistsHouse_EventScript_SickPokemonHeal
	case MULTI_B_PRESSED, MAGM8ProtagonistsHouse_EventScript_SickPokemonEnd
MAGM8ProtagonistsHouse_EventScript_NoMedicineToGiveSickPokemon:
	msgbox MAGM8ProtagonistsHouse_Text_NoMedicineToGiveSickPokemon, MSGBOX_DEFAULT
	releaseall
	end
MAGM8ProtagonistsHouse_EventScript_SickPokemonEnd:
	releaseall
end
MAGM8ProtagonistsHouse_EventScript_SickPokemonAlreadyGivenMedicine:
	msgbox MAGM8ProtagonistsHouse_Text_SickPokemonAlreadyGivenMedicine, MSGBOX_DEFAULT
	releaseall
end
MAGM8ProtagonistsHouse_EventScript_SickPokemonHeal:
	checkitem ITEM_MAGM8_HEAL_POWDER, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MAGM8ProtagonistsHouse_EventScript_NoMedicineToGiveSickPokemon
	msgbox MAGM8ProtagonistsHouse_Text_MedicineGiveSickPokemon, MSGBOX_DEFAULT
	playse SE_PIN
	waitse
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	removeitem ITEM_MAGM8_HEAL_POWDER, 1
release
end

MAGM8ProtagonistsHouse_EventScript_WouldYouLikeToSleep::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox MAGM8ProtagonistsHouse_Text_WouldYouLikeToSleep, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MAGM8ProtagonistsHouse_EventScript_WouldYouLikeToSleepEnd
	case YES, MAGM8ProtagonistsHouse_EventScriptWouldYouLikeToSleepYes
	case NO, MAGM8ProtagonistsHouse_EventScript_WouldYouLikeToSleepEnd
MAGM8ProtagonistsHouse_EventScript_WouldYouLikeToSleepEnd:
	releaseall
	end
MAGM8ProtagonistsHouse_EventScriptWouldYouLikeToSleepYes:
	goto_if_unset FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY, MAGM8ProtagonistsHouse_EventScript_HaventEatenYet
	goto_if_unset FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN, MAGM8ProtagonistsHouse_EventScript_HaventHealedSickPokemonYet
	setvar VAR_ROUTE101_STATE, 1
	fadescreen FADE_TO_BLACK
	playfanfare MUS_FV_GOODNIGHT
	waitfanfare
	removeobject 1
	setflag FLAG_HIDE_NALLS_RESIDENCE_1F_ISIAH
	special HealPlayerParty
	setdynamicwarp MAP_NEW_MAP1, 255, 29, 32
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	givecustommon SPECIES_AZUMARILL, 50, ITEM_LEFTOVERS, ITEM_DIVE_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_SUBSTITUTE, MOVE_WATERFALL, MOVE_SING, MOVE_BODY_SLAM, 0
	fadescreen FADE_FROM_BLACK
	releaseall
end

MAGM8ProtagonistsHouse_EventScript_HaventEatenYet:
	msgbox MAGM8ProtagonistsHouse_Text_HaventEatenYet, MSGBOX_DEFAULT
	releaseall
end

MAGM8ProtagonistsHouse_EventScript_HaventHealedSickPokemonYet:
	msgbox MAGM8ProtagonistsHouse_Text_HaventHealedSickPokemonYet, MSGBOX_DEFAULT
	releaseall
end

MAGM8ProtagonistsHouse_EventScript_Fridge::
	lockall
		msgbox MAGM8ProtagonistsHouse_Text_Fridge, MSGBOX_DEFAULT
	releaseall
end

MAGM8ProtagonistsHouse_EventScript_Sink::
	lockall
		msgbox MAGM8ProtagonistsHouse_Text_Sink, MSGBOX_DEFAULT
	releaseall
end

MAGM8ProtagonistsHouse_EventScript_Cabinets::
	lockall
		msgbox MAGM8ProtagonistsHouse_Text_Cabinets, MSGBOX_DEFAULT
	releaseall
end

MAGM8ProtagonistsHouse_Movement_MoveToTable:	
	walk_right	
	walk_right	
	walk_right	
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

MAGM8ProtagonistsHouse_Text_CheckToDoList:
	.string "Dad's advice…\p"
	.string "{PLAYER}, always keep a To Do list\n"
	.string "so you don't forget what you need\l"
	.string "to do!$"

MAGM8ProtagonistsHouse_Text_ToDoList:
	.string "{PLAYER}'s To Do List.\n"
	.string "Would you like to check it?$"

MAGM8ProtagonistsHouse_Text_ToDoListHarvestMushrooms:
	.string "Pick mushrooms from garden to make\n"
	.string "soup for dinner.$"

MAGM8ProtagonistsHouse_Text_ToDoListGoToTownForMedicine:
	.string "Medicine for POKEMON will be ready\n"
	.string "by mid-afternoon.\p"
	.string "Head to XXXXXXX Town to pick it up.$"

MAGM8ProtagonistsHouse_Text_PrepareSoup:
	.string "{PLAYER} begins to prepare the\n"
	.string "ingredients for their favorite soup.$"

MAGM8ProtagonistsHouse_Text_SoupReady:
	.string "The soup is ready. It looks\n"
	.string "delicious.\p"
	.string "Better eat it while it's hot!$"

MAGM8ProtagonistsHouse_Text_PlayerFeelsSleepy:
	.string "The soup is all gone.\p"
	.string "Dads advice... the best nights sleep\n"
	.string "is always had after a meal.$"

MAGM8ProtagonistsHouse_Text_CantMakeSoupWithoutMushroom:
	.string "It isn't possible to make your\n"
	.string "favorite soup without a tiny\l"
	.string "mushroom.$"

MAGM8ProtagonistsHouse_Text_PokemonIsSick:
	.string "Azumarill is feeling under the\n"
	.string "weather.$"

MAGM8ProtagonistsHouse_Text_WouldYouLikeToGiveMedicineToSickPokemon:
	.string "Would you like to give Azumarill\n"
	.string "the medicine?$"

MAGM8ProtagonistsHouse_Text_MedicineGiveSickPokemon:
	.string "Azumarill seems grateful for the\n"
	.string "medicine.\p"
	.string "After a good nights rest she should\n"
	.string "be as good as new!$"

MAGM8ProtagonistsHouse_Text_NoMedicineToGiveSickPokemon:
	.string "You don't have any medicine to\n"
	.string "give Azumarill...$"

MAGM8ProtagonistsHouse_Text_WouldYouLikeToSleep:
	.string "Would you like to sleep?$"

MAGM8ProtagonistsHouse_Text_HaventHealedSickPokemonYet:
	.string "...You forgot to give Azumarill\n"
	.string "her medicine.$"

MAGM8ProtagonistsHouse_Text_HaventEatenYet:
	.string "Rumble...\n"
	.string "Rumble...\p"
	.string "It's impossible to sleep on an\n"
	.string "empty stomach.\p"
	.string "Better head to the kitchen and\n"
	.string "make your favorite soup!$"

MAGM8ProtagonistsHouse_Text_WouldYouLikeToMakeSoup:
	.string "Ingredients to make your favorite\n"
	.string "soup are set neatly on the counter.\p"
	.string "Would you like to make soup?$"

MAGM8ProtagonistsHouse_Text_Fridge:
	.string "The fridge seems emptier than {PLAYER}\n"
	.string "remembers leaving it.\p"
	.string "Azumarill's stomach ache might not be\n"
	.string "a coincidence.$"

MAGM8ProtagonistsHouse_Text_Sink:
	.string "The sink is spotless. {PLAYER}'s Mom\n"
	.string "always said to take pride in a clean\l"
	.string "house.$"

MAGM8ProtagonistsHouse_Text_Cabinets:
	.string "The cabinets are organized with cups,\n"
	.string "plates, and silverware of various\l"
	.string "sizes.$"

MAGM8ProtagonistsHouse_Text_AlreadyMadeSoup:
	.string "All the ingredients have been used to\n"
	.string "make soup.\p"
	.string "{PLAYER} is feeling full.$"

MAGM8ProtagonistsHouse_Text_SickPokemonAlreadyGivenMedicine:
	.string "Azumarill seems grateful for the.\n"
	.string "medicine.\p"
	.string "She just needs a good nights sleep\n"
	.string "for it to take effect.$"

