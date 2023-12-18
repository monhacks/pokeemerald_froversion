//FLAG_0x4EB == FLAG_TO_DO_LIST_CHECKED

MAGM8ProtagonistsHouse_MapScripts::
	.byte 0

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
			scrollingmultichoice 13, 2, 3, 2, TRUE
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
