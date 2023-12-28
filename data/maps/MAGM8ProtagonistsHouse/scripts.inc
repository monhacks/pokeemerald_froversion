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
