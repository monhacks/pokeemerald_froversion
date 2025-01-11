EscapeRoom_StartingRoom_MapScripts::
	.byte 0


EscapeRoom_StartingRoom_EventScript_SolveTheRiddle::
	compare VAR_TEMP_1, 0
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolvePlains
	compare VAR_TEMP_1, 1
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveWater
	compare VAR_TEMP_1, 2
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveSnow
	compare VAR_TEMP_1, 3
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveMountain

EscapeRoom_StartingRoom_EventScript_SolvePlains:
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired1stNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 5
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolvePlains_CorrectAnswer1
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolvePlains_CorrectAnswer1:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 5
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolvePlains_CorrectAnswer2
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolvePlains_CorrectAnswer2:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 7
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolvePlains_CorrectAnswer3
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle
	
EscapeRoom_StartingRoom_EventScript_SolvePlains_CorrectAnswer3:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 3
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolvePlains_Solved
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolvePlains_Solved:
	msgbox EscapeRoom_StartingRoom_Text_SolvedGoAgain, MSGBOX_DEFAULT
	addvar VAR_TEMP_1, 1
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveWater: 
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired1stNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 6
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveWater_CorrectAnswer1
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveWater_CorrectAnswer1:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveWater_CorrectAnswer2
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveWater_CorrectAnswer2:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveWater_CorrectAnswer3
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle
	
EscapeRoom_StartingRoom_EventScript_SolveWater_CorrectAnswer3:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 6
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveWater_Solved
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveWater_Solved:
	msgbox EscapeRoom_StartingRoom_Text_SolvedGoAgain, MSGBOX_DEFAULT
	addvar VAR_TEMP_1, 1
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveSnow:
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired1stNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveSnow_CorrectAnswer1
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveSnow_CorrectAnswer1:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 7
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveSnow_CorrectAnswer2
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveSnow_CorrectAnswer2:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveSnow_CorrectAnswer3
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle
	
EscapeRoom_StartingRoom_EventScript_SolveSnow_CorrectAnswer3:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 6
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveSnow_Solved
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveSnow_Solved:
	msgbox EscapeRoom_StartingRoom_Text_SolvedGoAgain, MSGBOX_DEFAULT
	addvar VAR_TEMP_1, 1
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveMountain:
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired1stNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 8
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveMountain_CorrectAnswer1
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveMountain_CorrectAnswer1:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 4
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveMountain_CorrectAnswer2
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveMountain_CorrectAnswer2:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveMountain_CorrectAnswer3
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle
	
EscapeRoom_StartingRoom_EventScript_SolveMountain_CorrectAnswer3:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 9
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveMountain_Solved
	msgbox EscapeRoom_StartingRoom_Text_FourNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_SolveMountain_Solved:
	msgbox EscapeRoom_StartingRoom_Text_SolvedGoAgain, MSGBOX_DEFAULT
	addvar VAR_TEMP_1, 1
	goto_if_eq EscapeRoom_StartingRoom_EventScript_SolveTheRiddle

EscapeRoom_StartingRoom_EventScript_Tree::
	lock
	msgbox EscapeRoom_StartingRoom_Text_Tree, MSGBOX_DEFAULT
	release
	end

EscapeRoom_StartingRoom_EventScript_LeftPokeballStatue::
	lock
	msgbox EscapeRoom_StartingRoom_Text_LeftPokeballStatue, MSGBOX_DEFAULT
	release
	end

EscapeRoom_StartingRoom_EventScript_RightPokeballStatue::
	lock
	msgbox EscapeRoom_StartingRoom_Text_RightPokeballStatue, MSGBOX_DEFAULT
	release
	end

EscapeRoom_StartingRoom_EventScript_Rock::
	lock
	msgbox EscapeRoom_StartingRoom_Text_Rock, MSGBOX_DEFAULT
	release
	end

EscapeRoom_StartingRoom_EventScript_BookShelfLeft::
	lock
	msgbox EscapeRoom_StartingRoom_Text_BookShelfLeft, MSGBOX_DEFAULT
	release
	end

EscapeRoom_StartingRoom_EventScript_BookShelfLeft2::
	lock
		msgbox EscapeRoom_StartingRoom_Text_BookShelfLeft2, MSGBOX_YESNO
		switch VAR_RESULT
			case NO, EscapeRoom_StartingRoom_EventScript_BookShelfLeft2End
			case YES, EscapeRoom_StartingRoom_EventScript_BookShelfLeft2Exceprt
			case MULTI_B_PRESSED, EscapeRoom_StartingRoom_EventScript_BookShelfLeft2End
		EscapeRoom_StartingRoom_EventScript_BookShelfLeft2End:
	release
	end

EscapeRoom_StartingRoom_EventScript_BookShelfLeft2Exceprt:
	msgbox EscapeRoom_StartingRoom_Text_BookShelfLeftExcerpt, MSGBOX_DEFAULT
	release
	end


EscapeRoom_StartingRoom_Text_Tree:
	.string "A tree planted in soil.$"

EscapeRoom_StartingRoom_Text_LeftPokeballStatue:
	.string "Red before Green...$"

EscapeRoom_StartingRoom_Text_RightPokeballStatue:
	.string "Soil before Rock...$"

EscapeRoom_StartingRoom_Text_Rock:
	.string "A mountainous terrain made of\n"
	.string "rock...$"

EscapeRoom_StartingRoom_Text_BookShelfLeft:
	.string "A bookshelf lined with books.\n"
	.string "One in particular is sticking out.\p"
	.string "“Why the Prequels Are Better: Count\n"
	.string "Dooku Edition”$"

EscapeRoom_StartingRoom_Text_BookShelfLeft2:
	.string "A bookshelf lined with books.\n"
	.string "One in particular is sticking out.\p"
	.string "“The Secret Language of Pokénglish”\p"
	.string "Would you like to read an excerpt?$"

EscapeRoom_StartingRoom_Text_BookShelfLeftExcerpt:
	.string "Pokénglish is an encrypted language.\n"
	.string "This book contains the key and will\l"
	.string "help you convert the encrypted\l"
	.string "messages to a language you can\l"
	.string "understand.\p"
	.string "Here is a fun little riddle to get you\n"
	.string "started.\p"
	.string "LRUB when converted to English, is a\n"
	.string "four letter word that is a synonym\l"
	.string "of the first Hidden Machine you\l"
	.string "get in every Pokemon game.$"
