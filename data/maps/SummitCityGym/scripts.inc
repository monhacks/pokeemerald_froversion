SummitCityGym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SummitCity_Gym_OnLoad
	.byte 0

SummitCity_Gym_OnLoad:
	call_if_set FLAG_HIDE_MATTS_HOUSE_NPCS, SummitCity_Gym_EventScript_RevealHiddenStaircase
	end
	

SummitCity_Gym_FindProtectionAgreement::
	lock
	setvar VAR_0x8000, MUGSHOT_SEARS_PA
	callnative DrawMugshot
	msgbox SummitCity_Gym_Text_FoundPAClue, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SummitCityGym_EventScript_TakeYourTime
	callnative ClearMugshot
	release
	end

SummitCity_Gym_FindAttachment::
	lock
	setvar VAR_0x8000, MUGSHOT_SEARS_ATTACHMENT
	callnative DrawMugshot
	msgbox SummitCity_Gym_Text_FoundAttachmentClue, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SummitCityGym_EventScript_TakeYourTime
	callnative ClearMugshot
	release
	end	

SummitCity_Gym_FindCreditCard::
	lock
	setvar VAR_0x8000, MUGSHOT_SEARS_CREDIT_CARD
	callnative DrawMugshot
	msgbox SummitCity_Gym_Text_FoundCreditCardClue, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SummitCityGym_EventScript_TakeYourTime
	callnative ClearMugshot
	release
	end	

SummitCityGym_EventScript_TakeYourTime:
	msgbox SummitCity_Gym_Text_TakeYourTime, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SummitCityGym_EventScript_TakeYourTime
	callnative ClearMugshot
	release
	end

SummitCity_Gym_EventScript_GentlemanCashier::
	lockall
	goto_if_set FLAG_HIDE_MATTS_HOUSE_NPCS, SummitCityGym_EventScript_GoodLuckFacingChadAndMark
	goto_if_unset FLAG_TEMP_4, SummitCity_Gym_EventScript_ChadAndMarkSetUpEscapeRoom
	call_if_set FLAG_TEMP_1, SummitCity_Gym_EventScript_RiddleOneSolvedCheck
	msgbox SummitCity_Gym_Text_WhichRiddleWouldYouLikeToSolve, MSGBOX_DEFAULT
	scrollingmultichoice 8, 2, 3, 5, TRUE
	compare VAR_RESULT, 0
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementRiddleStart
	compare VAR_RESULT, 1
	goto_if_eq SummitCity_Gym_EventScript_CreditCardRiddleStart
	compare VAR_RESULT, 2
	goto_if_eq SummitCity_Gym_EventScript_AttachmentRiddleStart
	release
	end

SummitCity_Gym_EventScript_RiddleOneSolvedCheck:
	call_if_set FLAG_TEMP_2, SummitCity_Gym_EventScript_RiddleOneTwoSolvedCheck
	return

SummitCity_Gym_EventScript_RiddleOneTwoSolvedCheck:
	goto_if_set FLAG_TEMP_3, SummitCityGym_EventScript_CongratsYouSolvedRiddle
	return


SummitCity_Gym_EventScript_ChadAndMarkSetUpEscapeRoom:
	msgbox SummitCity_Gym_Text_ChadAndMarkSetUpAnEscapeRoom, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	release
	end

SummitCityGym_EventScript_AlreadySolvedThisRiddle:
	msgbox SummitCity_Gym_Text_AlreadySolvedThisRiddle, MSGBOX_AUTOCLOSE
	msgbox SummitCity_Gym_Text_WhichRiddleWouldYouLikeToSolve, MSGBOX_DEFAULT
	scrollingmultichoice 8, 2, 3, 5, TRUE
	compare VAR_RESULT, 0
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementRiddleStart
	compare VAR_RESULT, 1
	goto_if_eq SummitCity_Gym_EventScript_CreditCardRiddleStart
	compare VAR_RESULT, 2
	goto_if_eq SummitCity_Gym_EventScript_AttachmentRiddleStart
	release
	end

SummitCity_Gym_EventScript_ProtectionAgreementRiddleStart::
	lockall
	goto_if_set FLAG_TEMP_1, SummitCityGym_EventScript_AlreadySolvedThisRiddle
	msgbox SummitCity_Gym_Text_FourLetterComboRequired1stLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 18
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementCorrectAnswer1
	msgbox SummitCity_Gym_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourLetterComboRequired3rdLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourLetterComboRequired4thLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementRiddleStart
	release
	end

SummitCity_Gym_EventScript_ProtectionAgreementCorrectAnswer1:
	msgbox SummitCity_Gym_Text_FourLetterComboRequired2ndLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 14
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementCorrectAnswer2
	msgbox SummitCity_Gym_Text_FourLetterComboRequired3rdLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourLetterComboRequired4thLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementRiddleStart
	release
	end

SummitCity_Gym_EventScript_ProtectionAgreementCorrectAnswer2:
	msgbox SummitCity_Gym_Text_FourLetterComboRequired3rdLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 13
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementCorrectAnswer3
	msgbox SummitCity_Gym_Text_FourLetterComboRequired4thLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementRiddleStart
	release
	end

SummitCity_Gym_EventScript_ProtectionAgreementCorrectAnswer3:
	msgbox SummitCity_Gym_Text_FourLetterComboRequired4thLetter, MSGBOX_DEFAULT
	scrollingmultichoice 6, 2, 3, 5, TRUE
	compare VAR_RESULT, 6
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementSolved
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_ProtectionAgreementRiddleStart
	release
	end

SummitCity_Gym_EventScript_ProtectionAgreementSolved:
	setflag FLAG_TEMP_1
	call_if_set FLAG_TEMP_1, SummitCity_Gym_EventScript_RiddleOneSolvedCheck
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredCorrectSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_GentlemanCashier
	release
	end

SummitCityGym_EventScript_CongratsYouSolvedRiddle:
	lockall
	msgbox SummitCity_Gym_Text_SolvedRiddleRevealSecretPassage, MSGBOX_DEFAULT
	setflag FLAG_HIDE_MATTS_HOUSE_NPCS
	playse SE_DOOR
	warpsilent MAP_SUMMIT_CITY_GYM, 255, 3, 4
	release
	end

SummitCity_Gym_EventScript_CreditCardRiddleStart:
	goto_if_set FLAG_TEMP_2, SummitCityGym_EventScript_AlreadySolvedThisRiddle
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired1stNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 5
	goto_if_eq SummitCity_Gym_EventScript_CreditCardCorrectAnswer1
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired3rdNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired5thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_CreditCardRiddleStart
	release
	end

SummitCity_Gym_EventScript_CreditCardCorrectAnswer1:
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired2ndNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 4
	goto_if_eq SummitCity_Gym_EventScript_CreditCardCorrectAnswer2
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired3rdNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired5thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_CreditCardRiddleStart
	release
	end

SummitCity_Gym_EventScript_CreditCardCorrectAnswer2:
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired3rdNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 4
	goto_if_eq SummitCity_Gym_EventScript_CreditCardCorrectAnswer3
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired5thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_CreditCardRiddleStart
	release
	end

SummitCity_Gym_EventScript_CreditCardCorrectAnswer3:
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired4thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 6
	goto_if_eq SummitCity_Gym_EventScript_CreditCardCorrectAnswer4
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired5thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FiveNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_CreditCardRiddleStart
	release
	end

SummitCity_Gym_EventScript_CreditCardCorrectAnswer4:
	msgbox SummitCity_Gym_Text_FiveNumberComboRequired5thNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 0
	goto_if_eq SummitCity_Gym_EventScript_CreditCardRiddleSolved
	msgbox SummitCity_Gym_Text_FiveNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_CreditCardRiddleStart
	release
	end

SummitCity_Gym_EventScript_CreditCardRiddleSolved:
	setflag FLAG_TEMP_2
	call_if_set FLAG_TEMP_1, SummitCity_Gym_EventScript_RiddleOneSolvedCheck
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredCorrectSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_GentlemanCashier
	release
	end

SummitCity_Gym_EventScript_AttachmentRiddleStart:
	goto_if_set FLAG_TEMP_3, SummitCityGym_EventScript_AlreadySolvedThisRiddle
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredYellowNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 9
	goto_if_eq SummitCity_Gym_EventScript_AttachmentCorrectAnswer1
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredBlueNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredGreenNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredRedNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_AttachmentRiddleStart
	release
	end

SummitCity_Gym_EventScript_AttachmentCorrectAnswer1:
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredBlueNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 1
	goto_if_eq SummitCity_Gym_EventScript_AttachmentCorrectAnswer2
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredGreenNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredRedNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_AttachmentRiddleStart
	release
	end

SummitCity_Gym_EventScript_AttachmentCorrectAnswer2:
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredGreenNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 5
	goto_if_eq SummitCity_Gym_EventScript_AttachmentCorrectAnswer3
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredRedNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_AttachmentRiddleStart
	release
	end

SummitCity_Gym_EventScript_AttachmentCorrectAnswer3:
	msgbox SummitCity_Gym_Text_FourNumberComboRequiredRedNumber, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 8
	goto_if_eq SummitCity_Gym_EventScript_AttachmentSolved
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_AttachmentRiddleStart
	release
	end

SummitCity_Gym_EventScript_AttachmentSolved:
	setflag FLAG_TEMP_3
	call_if_set FLAG_TEMP_1, SummitCity_Gym_EventScript_RiddleOneSolvedCheck
	msgbox SummitCity_Gym_Text_FourLetterComboRequiredCorrectSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCity_Gym_EventScript_GentlemanCashier
	release
	end

SummitCityGym_EventScript_GoodLuckFacingChadAndMark:
	msgbox SummitCityGym_Text_GoodLuckFacingChadAndMark,MSGBOX_DEFAULT
	release
	end


SummitCity_Gym_EventScript_RevealHiddenStaircase:
	setmetatile 2, 0, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorTopLeft , 1
	setmetatile 3, 0, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorTopMiddle , 1
	setmetatile 4, 0, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorTopRight , 1
	setmetatile 2, 1, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorMiddleLeft , 1
	setmetatile 3, 1, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorMiddle , 0
	setmetatile 4, 1, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorMiddleRight , 1
	setmetatile 2, 2, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorBottomLeft , 0
	setmetatile 4, 2, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorBottomRight , 0
	end


SummitCity_Gym_Text_ChadNameBadgeFound:
	.string "You found Chad's name Badge!$"

SummitCity_Gym_Text_FoundPAClue:
	.string "You found the Protection\n"
	.string "Agreement!\p"
	.string "Are you done studying it for\n"
	.string "clues?$"

SummitCity_Gym_Text_FoundAttachmentClue:
	.string "You found the Attachment!\p"
	.string "Are you done studying it for\n"
	.string "clues?$"

SummitCity_Gym_Text_FoundCreditCardClue:
	.string "You found the Credit Card!\p"
	.string "Are you done studying it for\n"
	.string "clues?$"

SummitCity_Gym_Text_TakeYourTime:
	.string "Take your time...\p"
	.string "Are you done studying it for\n"
	.string "clues?$"

SummitCity_Gym_Text_SolvedRiddleRevealSecretPassage:
	.string "Congratulations! You've Solved all\n"
	.string "the puzzles!\p"
	.string "Please proceed to the hidden staircase\n"
	.string "on the left! Chad and Mark await!$"

SummitCity_Gym_Text_FourLetterComboRequired1stLetter:
	.string "Input 1st Letter of four digit code$"

SummitCity_Gym_Text_FourLetterComboRequired2ndLetter:
	.string "Input 2nd Letter of four digit code$"

SummitCity_Gym_Text_FourLetterComboRequired3rdLetter:
	.string "Input 3rd Letter of four digit code$"

SummitCity_Gym_Text_FourLetterComboRequired4thLetter:
	.string "Input 4th Letter of four digit code$"

SummitCity_Gym_Text_FourLetterComboRequiredWrongSolution:
	.string "That is incorrect. Try Again?$"

SummitCity_Gym_Text_FourLetterComboRequiredCorrectSolution:
	.string "Congratulations! That is correct!\p"
	.string "Would you like to solve another?$"

SummitCity_Gym_Text_FiveNumberComboRequired1stNumber:
	.string "Input 1st Number of five digit code.$"

SummitCity_Gym_Text_FiveNumberComboRequired2ndNumber:
	.string "Input 2nd Number of five digit code.$"

SummitCity_Gym_Text_FiveNumberComboRequired3rdNumber:
	.string "Input 3rd Number of five digit code.$"

SummitCity_Gym_Text_FiveNumberComboRequired4thNumber:
	.string "Input 4th Number of five digit code.$"

SummitCity_Gym_Text_FiveNumberComboRequired5thNumber:
	.string "Input 5th Number of five digit code.$"

SummitCity_Gym_Text_FiveNumberComboRequiredWrongSolution:
	.string "Sorry that is incorrect. Try again?$"

SummitCity_Gym_Text_FourNumberComboRequiredYellowNumber:
	.string "Input Yellow Number of Four digit code.$"

SummitCity_Gym_Text_FourNumberComboRequiredBlueNumber:
	.string "Input Blue Number of Four digit code.$"

SummitCity_Gym_Text_FourNumberComboRequiredGreenNumber:
	.string "Input Green Number of Four digit code.$"

SummitCity_Gym_Text_FourNumberComboRequiredRedNumber:
	.string "Input Red Number of Four digit code.$"

SummitCity_Gym_Text_FiveLetterComboRequiredWrongSolution:
	.string "Sorry that is incorrect. Try again?$"

SummitCity_Gym_Text_AlreadySolvedThisRiddle:
	.string "You have already solved this puzzle.$"

SummitCity_Gym_Text_WhichRiddleWouldYouLikeToSolve:
	.string "Which Riddle would you like to solve?$"

SummitCity_Gym_Text_ChadAndMarkSetUpAnEscapeRoom:
	.string "Gym Leaders Chad and Mark are both\n"
	.string "huge fans of escape rooms. They have\l"
	.string "set up their Gym to be one!\p"
	.string "They left clues around the Gym that\n"
	.string "you need to solve in order to face them!\p"
	.string "Check with the greeter, he can point you\n"
	.string "in the right direction. Come back to me\l"
	.string "When you're ready to solve the riddles!$"

SummitCityGym_Text_GoodLuckFacingChadAndMark:
	.string "Head down the secret staircase to face\n"
	.string "Chad and Mark. It won't be easy!\p"
	.string "Good luck!$"
