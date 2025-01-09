EscapeRoom_BlackRoomPlainsGrass_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_BlackRoomPlainsGrass_OnFrame
	.byte 0

EscapeRoom_BlackRoomPlainsGrass_OnFrame::
	map_script_2 VAR_ESCAPE_ROOM_PLAINS_GRASS, 0, EscapeRoom_BlackRoomPlainsGrass_EventScript_GameStart
	.2byte 0

EscapeRoom_BlackRoomPlainsGrass_EventScript_GameStart::
	givecustommon SPECIES_ARCANINE, 50, ITEM_NONE, ITEM_GREAT_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_ESCAPE_ROOM_PLAINS_GRASS, 1
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart::
	lockall
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired1stLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 17
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer1
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer1:
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer2
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer2:
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 25
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer3
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer3:
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 14
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer4
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer4:
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 17
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer5
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer5:
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 11
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer6
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer6:
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 4
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer7
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer7:
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer8
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleCorrectAnswer8:
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 5
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleSolved
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomPlainsGrass_EventScript_DoorRiddleSolved:
	msgbox EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredCorrectSolution, MSGBOX_DEFAULT
			opendoor 2 1
			applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
			waitmovement OBJ_EVENT_ID_PLAYER
			closedoor 2 1
			waitdooranim
			warp MAP_ESCAPE_ROOM_PLAINS, 255, 35, 74
			waitstate
	release
	end

EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired1stLetter:
	.string "Input 1st Letter$"

EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequired2ndLetter:
	.string "Input next letter$"

EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredCorrectSolution:
	.string "Congratulations! That is correct!$"	

EscapeRoom_BlackRoomPlainsGrass_Text_FourLetterComboRequiredWrongSolution:	
	.string "That is not correct.\p"
	.string "Would you like to try again?$"
