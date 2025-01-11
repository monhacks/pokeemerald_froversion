EscapeRoom_FirstRoom_Protagonist2_MapScripts::
	.byte 0

EscapeRoom_FirstRoom_Protagonist2__EventScript_IceRoomClue1::
	lockall
	msgbox EscapeRoom_FirstRoom_Protagonist2__Text_IceRoomClue1, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_FirstRoom_Protagonist2__EventScript_SnowRoomFinalClue::
	lockall
	msgbox EscapeRoom_FirstRoom_Protagonist2__Text_SnowRoomFinalClue, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_FirstRoom_Protagonist2__EventScript_IceRoomClue2::
	lockall
	msgbox EscapeRoom_FirstRoom_Protagonist2__Text_IceRoomClue2, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_FirstRoom_Protagonist2_EventScript_RockOrderClue::
	lockall
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_RockOrderClue, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipher::
	lockall
	goto_if_set FLAG_SOLVED_BURN_CIPHER, EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherSolvedEnd
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired1stNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 3
	goto_if_eq EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherCorrectAnswer1
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired3rdNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipher
	release
	end

EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherCorrectAnswer1:
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 7
	goto_if_eq EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherCorrectAnswer2
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired3rdNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipher
	release
	end

EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherCorrectAnswer2:
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired3rdNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 6
	goto_if_eq EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherCorrectAnswer3
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipher
	release
	end

EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherCorrectAnswer3:
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 5
	goto_if_eq EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherSolved
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipher
	release
	end

EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherSolved:
	msgbox EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequiredCorrectSolution, MSGBOX_DEFAULT
	setflag FLAG_SOLVED_BURN_CIPHER
		EscapeRoom_FirstRoom_Protagonist2_EventScript_BurnCipherSolvedEnd:
			msgbox Text_Solved_Burn_Cipher, MSGBOX_DEFAULT
	release
	end

EscapeRoom_FirstRoom_Protagonist2_WildBattleSpecialGastly::
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
	giveitem ITEM_MASTER_BALL, 1
	playmoncry SPECIES_GASTLY, 2
	removeobject 4 
	waitmoncry
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_FOUND_CIPHER
	release
end

EscapeRoom_FirstRoom_Protagonist2_Text_RockOrderClue:
	.string "I like rocks 43182765 times better\n"
	.string "than you.$"

Text_Solved_Burn_Cipher:
	.string "Pohr: A Pokemon Status that will\n"
	.string "inflict damage every turn and also\l"
	.string "lowers thier attack!$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired1stNumber:
	.string "Input 1st Letter of four digit code$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired2ndNumber:
	.string "Input 2nd Letter of four digit code$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired3rdNumber:
	.string "Input 3rd Letter of four digit code$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequired4thNumber:
	.string "Input 4th Letter of four digit code$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequiredWrongSolution:
	.string "That is incorrect. Try Again?$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComnoRequiredCorrectSolution:
	.string "Congratulations! That is correct!$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComboRequired1stNumber:
	.string "Input 1st Number of four digit code.$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComboRequired2ndNumber:
	.string "Input 2nd Number of four digit code.$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComboRequired3rdNumber:
	.string "Input 3rd Number of four digit code.$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComboRequired4thNumber:
	.string "Input 4th Number of four digit code.$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComboRequiredWrongSolution:
	.string "Sorry that is incorrect. Try again?$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComboRequiredYellowNumber:
	.string "Input Yellow Number of Four digit code.$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComboRequiredBlueNumber:
	.string "Input Blue Number of Four digit code.$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComboRequiredGreenNumber:
	.string "Input Green Number of Four digit code.$"

EscapeRoom_FirstRoom_Protagonist2_Text_FourNumberComboRequiredRedNumber:
	.string "Input Red Number of Four digit code.$"

EscapeRoom_FirstRoom_Protagonist2_Text_FiveLetterComboRequiredWrongSolution:
	.string "Sorry that is incorrect. Try again?$"


EscapeRoom_FirstRoom_Protagonist2__Text_IceRoomClue1:	
	.string "Lralg Nulg\n"
	.string "\l"
	.string "\p"
	.string "{COLOR BLUE}3 5$"

EscapeRoom_FirstRoom_Protagonist2__Text_IceRoomClue2:	
	.string "{COLOR BLUE}Reverse then repeat to unlock\n"
	.string "your a snowy retreat.$"

EscapeRoom_FirstRoom_Protagonist2__Text_SnowRoomFinalClue:	
	.string "Log, Log, Dead, Alive, Grass, Dead,\n"
	.string "Grass, Log$"
	