EscapeRoom_BlackRoom_MapScripts::
	.byte 0


EscapeRoom_BlackRoom_EventScript_DoorCode::
	lockall
	goto_if_set FLAG_OPENED_BLACKROOM_DOOR_1, EscapeRoom_BlackRoom_EventScript_CutSolvedWarp 
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired1stNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 5
	goto_if_eq EscapeRoom_BlackRoom_EventScript_CutCorrectAnswer1
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired3rdNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoom_EventScript_DoorCode
	release
	end

EscapeRoom_BlackRoom_EventScript_CutCorrectAnswer1:
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 3
	goto_if_eq EscapeRoom_BlackRoom_EventScript_CutCorrectAnswer2
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired3rdNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoom_EventScript_DoorCode
	release
	end

EscapeRoom_BlackRoom_EventScript_CutCorrectAnswer2:
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired3rdNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 7
	goto_if_eq EscapeRoom_BlackRoom_EventScript_CutCorrectAnswer3
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoom_EventScript_DoorCode
	release
	end

EscapeRoom_BlackRoom_EventScript_CutCorrectAnswer3:
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 6
	goto_if_eq EscapeRoom_BlackRoom_EventScript_CutSolved
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_BlackRoom_EventScript_DoorCode
	release
	end

EscapeRoom_BlackRoom_EventScript_CutSolved:
	msgbox EscapeRoom_BlackRoom_Text_FourNumberComnoRequiredCorrectSolution, MSGBOX_DEFAULT
	setflag FLAG_OPENED_BLACKROOM_DOOR_1
		EscapeRoom_BlackRoom_EventScript_CutSolvedWarp:
			opendoor 2 1
			applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
			waitmovement OBJ_EVENT_ID_PLAYER
			closedoor 2 1
			waitdooranim
			warp MAP_ESCAPE_ROOM_FIRST_ROOM_PROTAGONIST_ONE, 255, 35, 74
			waitstate
	release
	end
	
EscapeRoom_BlackRoom_Text_FourNumberComnoRequired1stNumber:
	.string "Input 1st Letter of four digit code$"

EscapeRoom_BlackRoom_Text_FourNumberComnoRequired2ndNumber:
	.string "Input 2nd Letter of four digit code$"

EscapeRoom_BlackRoom_Text_FourNumberComnoRequired3rdNumber:
	.string "Input 3rd Letter of four digit code$"

EscapeRoom_BlackRoom_Text_FourNumberComnoRequired4thNumber:
	.string "Input 4th Letter of four digit code$"

EscapeRoom_BlackRoom_Text_FourNumberComnoRequiredWrongSolution:
	.string "That is incorrect. Try Again?$"

EscapeRoom_BlackRoom_Text_FourNumberComnoRequiredCorrectSolution:
	.string "Congratulations! That is correct!$"

EscapeRoom_BlackRoom_Text_FourNumberComboRequired1stNumber:
	.string "Input 1st Number of four digit code.$"

EscapeRoom_BlackRoom_Text_FourNumberComboRequired2ndNumber:
	.string "Input 2nd Number of four digit code.$"

EscapeRoom_BlackRoom_Text_FourNumberComboRequired3rdNumber:
	.string "Input 3rd Number of four digit code.$"

EscapeRoom_BlackRoom_Text_FourNumberComboRequired4thNumber:
	.string "Input 4th Number of four digit code.$"

EscapeRoom_BlackRoom_Text_FourNumberComboRequiredWrongSolution:
	.string "Sorry that is incorrect. Try again?$"

EscapeRoom_BlackRoom_Text_FourNumberComboRequiredYellowNumber:
	.string "Input Yellow Number of Four digit code.$"

EscapeRoom_BlackRoom_Text_FourNumberComboRequiredBlueNumber:
	.string "Input Blue Number of Four digit code.$"

EscapeRoom_BlackRoom_Text_FourNumberComboRequiredGreenNumber:
	.string "Input Green Number of Four digit code.$"

EscapeRoom_BlackRoom_Text_FourNumberComboRequiredRedNumber:
	.string "Input Red Number of Four digit code.$"

EscapeRoom_BlackRoom_Text_FiveLetterComboRequiredWrongSolution:
	.string "Sorry that is incorrect. Try again?$"
