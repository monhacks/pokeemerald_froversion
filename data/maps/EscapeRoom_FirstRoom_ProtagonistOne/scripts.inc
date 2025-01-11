EscapeRoom_FirstRoom_ProtagonistOne_MapScripts::
	.byte 0


EscapeRoom_FirstRoom_EventScripts_FunctionalTradeMenu::
	msgbox EscapeRoom_FirstRoom_Text_WhoWouldYouLikeToTradeWith, MSGBOX_DEFAULT	
	special GetActiveChar
	switch VAR_RESULT
		case 0, EscapeRoom_FirstRoom_ProtagonistA_EventScripts_FunctionalTradeMenu
		case 1, EscapeRoom_FirstRoom_ProtagonistB_EventScripts_FunctionalTradeMenu
		case 2, EscapeRoom_FirstRoom_ProtagonistC_EventScripts_FunctionalTradeMenu
end

EscapeRoom_FirstRoom_ProtagonistA_EventScripts_FunctionalTradeMenu::
		scrollingmultichoice 16, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyB
		compare VAR_RESULT, 1
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyC
		release
		end

EscapeRoom_FirstRoom_ProtagonistB_EventScripts_FunctionalTradeMenu::
		scrollingmultichoice 17, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyA
		compare VAR_RESULT, 1
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyC
		release
		end

EscapeRoom_FirstRoom_ProtagonistC_EventScripts_FunctionalTradeMenu::
		scrollingmultichoice 18, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyA
		compare VAR_RESULT, 1
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyB
		release
		end

EscapeRoom_FirstRoom_LoadDynamicPartyA::
		setvar VAR_0x8006, 0
		setvar VAR_0x8007, 1
		special BufferStoredPokemon
	msgbox EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike, MSGBOX_DEFAULT
		setvar VAR_0x800B, 0
		scrollingmultichoice 19, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq TradePokemon
		compare VAR_RESULT, 1
		goto_if_eq TradePokemon
		release
		end

EscapeRoom_FirstRoom_LoadDynamicPartyB::
		setvar VAR_0x8006, 2
		setvar VAR_0x8007, 3
		special BufferStoredPokemon
	msgbox EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike, MSGBOX_DEFAULT
		setvar VAR_0x800B, 1
		scrollingmultichoice 19, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq TradePokemon
		compare VAR_RESULT, 1
		goto_if_eq TradePokemon
		release
		end

EscapeRoom_FirstRoom_LoadDynamicPartyC::
		setvar VAR_0x8006, 4
		setvar VAR_0x8007, 5
		special BufferStoredPokemon
	msgbox EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike, MSGBOX_DEFAULT
		setvar VAR_0x800B, 2
		scrollingmultichoice 19, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq TradePokemon
		compare VAR_RESULT, 1
		goto_if_eq TradePokemon
		release
		end

TradePokemon::
 msgbox EscapeRoom_FirstRoom_Text_WhichToTradeFor, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x8005 VAR_0x8004
	special CreateInGameCharacterTradePokemon
	special DoInGameTradeScene
	end

EscapeRoom_FirstRoom_Text_WhichToTradeFor:
	.string "Which do you want to trade for?$"

EscapeRoom_FirstRoom_Text_WhoWouldYouLikeToTradeWith:
	.string "Who would you like to trade with?$"

EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike:
	.string "Which Pokemon Would you Like?$"

EscapeRoom_Debug::
	msgbox EscapeRoom_FirstRoom_Text_Test, MSGBOX_DEFAULT
end

EscapeRoom_FirstRoom_Text_Test::
	.string "{STR_VAR_1}$"

EventScript_Timeout::
	msgbox Text_Timeout, MSGBOX_SIGN
	@ Use 'setvar VAR_TIMEOUT_SECONDS, X' to reset the time before
	@ this script runs again. Time starts ticking down immediately
	@ after the 'setvar', so it's a good idea to do it as late as
	@ possible.
	@ 'setvar VAR_TIMEOUT_SECONDS, 0xFFFF' will disable the timer.
	setvar VAR_TIMEOUT_SECONDS, 0xFFFF
	end

Text_Timeout:
	.string "Uh-oh, time's up!$"



///

EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutRiddleStart::
	lockall
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired1stLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutCorrectAnswer1
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired3rdLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired4thLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutRiddleStart
	release
	end

EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutCorrectAnswer1:
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 7
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutCorrectAnswer2
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired3rdLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired4thLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutRiddleStart
	release
	end

EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutCorrectAnswer2:
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired3rdLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 14
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutCorrectAnswer3
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired4thLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutRiddleStart
	release
	end

EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutCorrectAnswer3:
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired4thLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 15
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutSolved
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutRiddleStart
	release
	end

EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CutSolved:
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequiredCorrectSolution, MSGBOX_DEFAULT
	finditem ITEM_HM01
	release
	end

EscapeRoom_FirstRoom_ProtagonistOne_EventScript_FindRazorLeaf::
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_ThisItemIsTheKeyToUnlockingGrassDoor, MSGBOX_DEFAULT
	finditem ITEM_TM01
	release
	end

EscapeRoom_FirstRoom_ProtagonistOne_EventScript_FindOverheat::
	finditem ITEM_TM50
	release
	end
	
EscapeRoom_FirstRoom_ProtagonistOne_EventScript_CantLeave::
	lockall
	msgbox EscapeRoom_FirstRoom_ProtagonistOne_Text_CantGoBack, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

EscapeRoom_FirstRoom_ProtagonistOne__EventScript_MountainRoomFinalClue::
	lockall
	msgbox EscapeRoom_FirstRoom_Protagonist2__Text_MountainRoomFinalClue, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_FirstRoom_ProtagonistOne__EventScript_Log:: @@ Var 0 -> 1 -> 2  Var 7 -> Solved
	lock
	goto_if_set FLAG_SNOW_FINAL_PUZZLE_SOLVED, EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleSolved
	compare VAR_SNOW_FINAL_PUZZLE, 7
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleSolved
	compare VAR_SNOW_FINAL_PUZZLE, 2
	goto_if_gt EscapeRoom_FirstRoom_ProtagonistOne_EventScript_ResetFinalPuzzle
	goto_if_lt EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleAddVar

EscapeRoom_FirstRoom_ProtagonistOne__EventScript_DeadTree:: @@ Var 2 -> 3 // Var 5 -> 6
	lock
	goto_if_set FLAG_SNOW_FINAL_PUZZLE_SOLVED, EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleSolved
	compare VAR_SNOW_FINAL_PUZZLE, 5
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleAddVar
	compare VAR_SNOW_FINAL_PUZZLE, 2
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleAddVar
	goto_if_ne EscapeRoom_FirstRoom_ProtagonistOne_EventScript_ResetFinalPuzzle

EscapeRoom_FirstRoom_ProtagonistOne__EventScript_AliveTree:: @@ Var 3 ->4
	lock
	goto_if_set FLAG_SNOW_FINAL_PUZZLE_SOLVED, EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleSolved
	compare VAR_SNOW_FINAL_PUZZLE, 3
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleAddVar
	goto_if_ne EscapeRoom_FirstRoom_ProtagonistOne_EventScript_ResetFinalPuzzle

EscapeRoom_FirstRoom_ProtagonistOne__EventScript_Grass:: @@ Var 4 -> 5 // Var 6 -> 7
	lock
	goto_if_set FLAG_SNOW_FINAL_PUZZLE_SOLVED, EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleSolved
	compare VAR_SNOW_FINAL_PUZZLE, 6
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleAddVar
	compare VAR_SNOW_FINAL_PUZZLE, 4
	goto_if_eq EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleAddVar
	goto_if_ne EscapeRoom_FirstRoom_ProtagonistOne_EventScript_ResetFinalPuzzle

EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleAddVar:
	addvar VAR_SNOW_FINAL_PUZZLE, 1
	release
	end

EscapeRoom_FirstRoom_ProtagonistOne_EventScript_ResetFinalPuzzle:
	setvar VAR_SNOW_FINAL_PUZZLE, 0
	release
	end

EscapeRoom_FirstRoom_ProtagonistOne__EventScript_FinalPuzzleSolved:
	msgbox EscapeRoom_FirstRoom_ProtagonistOne__Text_FinalPuzzleSolved, MSGBOX_DEFAULT
	setflag FLAG_SNOW_FINAL_PUZZLE_SOLVED
	release
	end

EscapeRoom_FirstRoom_ProtagonistOne_Text_ThisItemIsTheKeyToUnlockingGrassDoor:
	.string "This item contains the code to unlock\n"
	.string "a locked door!$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired1stLetter:
	.string "Input 1st Letter of four digit code$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired2ndLetter:
	.string "Input 2nd Letter of four digit code$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired3rdLetter:
	.string "Input 3rd Letter of four digit code$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequired4thLetter:
	.string "Input 4th Letter of four digit code$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequiredWrongSolution:
	.string "That is incorrect. Try Again?$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourLetterComboRequiredCorrectSolution:
	.string "Congratulations! That is correct!$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FiveNumberComboRequired1stNumber:
	.string "Input 1st Number of five digit code.$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FiveNumberComboRequired2ndNumber:
	.string "Input 2nd Number of five digit code.$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FiveNumberComboRequired3rdNumber:
	.string "Input 3rd Number of five digit code.$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FiveNumberComboRequired4thNumber:
	.string "Input 4th Number of five digit code.$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FiveNumberComboRequired5thNumber:
	.string "Input 5th Number of five digit code.$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FiveNumberComboRequiredWrongSolution:
	.string "Sorry that is incorrect. Try again?$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourNumberComboRequiredYellowNumber:
	.string "Input Yellow Number of Four digit code.$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourNumberComboRequiredBlueNumber:
	.string "Input Blue Number of Four digit code.$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourNumberComboRequiredGreenNumber:
	.string "Input Green Number of Four digit code.$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FourNumberComboRequiredRedNumber:
	.string "Input Red Number of Four digit code.$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_FiveLetterComboRequiredWrongSolution:
	.string "Sorry that is incorrect. Try again?$"

EscapeRoom_FirstRoom_ProtagonistOne_Text_CantGoBack:
	.string "The door is locked from the inside.$"

EscapeRoom_FirstRoom_Protagonist2__Text_MountainRoomFinalClue:	
	.string "When covering the lava, make sure\n"
	.string "to start third from the right,\l"
	.string "followed by the furthest left.\p"
	.string "After that make your way from left\n"
	.string "to right.$"

EscapeRoom_FirstRoom_ProtagonistOne__Text_FinalPuzzleSolved:
	.string "Dra Vencd vuin hispan luta du aclyba\n"
	.string "ec: Uha, Cajah, Dfu, Ceq$"

