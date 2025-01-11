EscapeRoom_Plains_MapScripts::
	.byte 0

EscapeRoom_Plains_EventScript_FindIceCaveKey::
	finditem ITEM_CARD_KEY
	release
	end

EscapeRoom_Plains_EventScript_FindStrength::
	finditem ITEM_HM04
	release
	end

EscapeRoom_Plains_Text_OverheatClue::
	lockall
	msgbox EscapeRoom_Plains_Text_IceCaveClue, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_Plains_EventScript_WaterRoomFinalClue::
	lockall
	msgbox EscapeRoom_Plains_Text_WaterRoomFinalClue, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_Plains_Text_MountainClue::
	lockall
	msgbox EscapeRoom_Plains_Text_MountainRoomClue, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_Plains_EventScript_FlameOrbRiddleStart::
	lockall
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired1stLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_Plains_EventScript_FlameOrbCorrectAnswer1
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Plains_EventScript_FlameOrbRiddleStart
	release
	end

EscapeRoom_Plains_EventScript_FlameOrbCorrectAnswer1:
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 20
	goto_if_eq EscapeRoom_Plains_EventScript_FlameOrbCorrectAnswer2
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Plains_EventScript_FlameOrbRiddleStart
	release
	end

EscapeRoom_Plains_EventScript_FlameOrbCorrectAnswer2:
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 17
	goto_if_eq EscapeRoom_Plains_EventScript_FlameOrbCorrectAnswer3
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Plains_EventScript_FlameOrbRiddleStart
	release
	end

EscapeRoom_Plains_EventScript_FlameOrbCorrectAnswer3:
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 13
	goto_if_eq EscapeRoom_Plains_EventScript_FlameOrbSolved
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Plains_EventScript_FlameOrbRiddleStart
	release
	end

EscapeRoom_Plains_EventScript_FlameOrbSolved:
	msgbox EscapeRoom_Plains_Text_FourLetterComboRequiredCorrectSolution, MSGBOX_DEFAULT
	finditem ITEM_FLAME_ORB
	release
	end

EscapeRoom_Plains_EventScript_WarpPadPuzzleUpperOne::
	compare VAR_TEMP_1, 0
	goto_if_eq EscapeRoom_Plains_EventScript_WarpPadPuzzleAddVar
	goto_if_ne EscapeRoom_Plains_EventScript_WarpPadPuzzleReset

EscapeRoom_Plains_EventScript_WarpPadPuzzleLowerTwo::
	compare VAR_TEMP_1, 1
	goto_if_eq EscapeRoom_Plains_EventScript_WarpPadPuzzleAddVar
	goto_if_ne EscapeRoom_Plains_EventScript_WarpPadPuzzleReset

EscapeRoom_Plains_EventScript_WarpPadPuzzleUpperTwo::
	compare VAR_TEMP_1, 2
	goto_if_eq EscapeRoom_Plains_EventScript_WarpPadPuzzleAddVar
	goto_if_ne EscapeRoom_Plains_EventScript_WarpPadPuzzleReset

EscapeRoom_Plains_EventScript_WarpPadPuzzleLowerThree::
	compare VAR_TEMP_1, 3
	goto_if_eq EscapeRoom_Plains_EventScript_WarpPadPuzzleAddVar
	goto_if_ne EscapeRoom_Plains_EventScript_WarpPadPuzzleReset

EscapeRoom_Plains_EventScript_WarpPadPuzzleUpperFour::
	compare VAR_TEMP_1, 4
	goto_if_eq EscapeRoom_Plains_EventScript_WarpPadPuzzleAddVar
	goto_if_ne EscapeRoom_Plains_EventScript_WarpPadPuzzleReset

EscapeRoom_Plains_EventScript_WarpPadPuzzleLowerOne::
	compare VAR_TEMP_1, 5
	goto_if_eq EscapeRoom_Plains_EventScript_WarpPadPuzzleAddVar
	goto_if_ne EscapeRoom_Plains_EventScript_WarpPadPuzzleReset

EscapeRoom_Plains_EventScript_WarpPadPuzzleLowerFour::
	compare VAR_TEMP_1, 6
	goto_if_eq EscapeRoom_Plains_EventScript_WarpPadPuzzleAddVar
	goto_if_ne EscapeRoom_Plains_EventScript_WarpPadPuzzleReset
	
EscapeRoom_Plains_EventScript_WarpPadPuzzleUpperThree::
	compare VAR_TEMP_1, 7
	goto_if_eq EscapeRoom_Plains_EventScript_WarpPadPuzzleAddVar
	goto_if_ne EscapeRoom_Plains_EventScript_WarpPadPuzzleReset

EscapeRoom_Plains_EventScript_WarpPadPuzzleAddVar:
	addvar VAR_TEMP_1, 1
	compare VAR_TEMP_1, 7
	goto_if_eq EscapeRoom_Plains_EventScript_WarpPadPuzzleSolved
	release
	end

EscapeRoom_Plains_EventScript_WarpPadPuzzleSolved:
	goto_if_unset FLAG_WAR_PAD_PUZZLE_SOLVED, EscapeRoom_Plains_EventScript_WarpPadPuzzleSolvedEnd
	addobject 3
	clearflag FLAG_WAR_PAD_PUZZLE_SOLVED
	playse SE_SAVE
	waitse
EscapeRoom_Plains_EventScript_WarpPadPuzzleSolvedEnd:
	release
	end

EscapeRoom_Plains_EventScript_FinalPuzzleClue::
	msgbox EscapeRoom_Plains_Text_FinalPuzzleSolved, MSGBOX_DEFAULT
	release
	end

EscapeRoom_Plains_EventScript_WarpPadPuzzleReset:
	setvar VAR_TEMP_1, 0
	release
	end

EscapeRoom_Plains_Text_IceCaveClue:	
	.string "If you're ever feeling too cold,\n"
	.string "try Yfihnied.$"

EscapeRoom_Plains_Text_MountainRoomClue:
	.string "To unlock a new room, who is\n"
	.string "the most recent Groom?$"

EscapeRoom_Plains_Text_FourLetterComboRequired1stLetter:
	.string "Input 1st Letter of four digit code$"

EscapeRoom_Plains_Text_FourLetterComboRequired2ndLetter:
	.string "Input Next Letter of four digit code$"

EscapeRoom_Plains_Text_FourLetterComboRequiredCorrectSolution:
	.string "Congratulations! That is correct!$"

EscapeRoom_Plains_Text_FourLetterComboRequiredWrongSolution:
	.string "Sorry that is incorrect. Try again?$"

EscapeRoom_Plains_Text_WaterRoomFinalClue:
	.string "There is water hidden in the\n"
	.string "Grass...$"

EscapeRoom_Plains_Text_FinalPuzzleSolved:
	.string "Dra Vencd vuin hispan luta du aclyba\n"
	.string "ec: Veja, Veja, Cajah, Drnaa$"

