EscapeRoom_BlackRoomMountain_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_BlackRoomMountain_OnFrame
	.byte 0

EscapeRoom_BlackRoomMountain_OnFrame::
	map_script_2 VAR_ESCAPE_ROOM_MOUNTAIN, 0, EscapeRoom_BlackRoomMountain_EventScript_GameStart
	.2byte 0

EscapeRoom_BlackRoomMountain_EventScript_GameStart::
	givecustommon SPECIES_DEWGONG, 50, ITEM_NONE, ITEM_GREAT_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_SURF, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0
	givecustommon SPECIES_UNOWN, 1, ITEM_NONE, ITEM_GREAT_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_NONE, 0
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_ESCAPE_ROOM_MOUNTAIN, 1
	release
	end

EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleStart::
	lockall
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired1stLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 12
	goto_if_eq EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleCorrectAnswer1
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleCorrectAnswer1:
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleCorrectAnswer2
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleCorrectAnswer2:
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 19
	goto_if_eq EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleCorrectAnswer3
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleStart
	release
	end

EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleCorrectAnswer3:
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 19
	goto_if_eq EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleSolved
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleStart
	release
	end


EscapeRoom_BlackRoomMountain_EventScript_DoorRiddleSolved:
	msgbox EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequiredCorrectSolution, MSGBOX_DEFAULT
			opendoor 2 1
			applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
			waitmovement OBJ_EVENT_ID_PLAYER
			closedoor 2 1
			waitdooranim
			warp MAP_ESCAPE_ROOM_MOUNTAIN, 255, 35, 74
			waitstate
	release
	end

EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired1stLetter:
	.string "Input 1st Letter$"

EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequired2ndLetter:
	.string "Input next letter$"

EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequiredCorrectSolution:
	.string "Congratulations! That is correct!$"	

EscapeRoom_BlackRoomMountain_Text_FourLetterComboRequiredWrongSolution:	
	.string "That is not correct.\p"
	.string "Would you like to try again?$"

