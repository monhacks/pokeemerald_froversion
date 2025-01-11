EscapeRoom_IceCave2_MapScripts::
	.byte 0

EscapeRoom_IceCave2_EventScript_RockPuzzleAdd1::
	lock
	goto_if_set FLAG_TEMP_1, EscapeRoom_IceCave2_EventScript_RockPuzzleAddEnd
	setflag FLAG_TEMP_1
	addvar VAR_TEMP_1, 1
	compare VAR_TEMP_1, 4
	goto_if_eq EscapeRoom_IceCave2_EventScript_RockPuzzleAddSolve
	EscapeRoom_IceCave2_EventScript_RockPuzzleAddEnd:
	release
	end

EscapeRoom_IceCave2_EventScript_RockPuzzleAdd2::
	lock
	goto_if_set FLAG_TEMP_2, EscapeRoom_IceCave2_EventScript_RockPuzzleAddEnd
	setflag FLAG_TEMP_2
	addvar VAR_TEMP_1, 1
	compare VAR_TEMP_1, 4
	goto_if_eq EscapeRoom_IceCave2_EventScript_RockPuzzleAddSolve
	goto EscapeRoom_IceCave2_EventScript_RockPuzzleAddEnd

EscapeRoom_IceCave2_EventScript_RockPuzzleAdd3::
	lock
	goto_if_set FLAG_TEMP_3, EscapeRoom_IceCave2_EventScript_RockPuzzleAddEnd
	setflag FLAG_TEMP_3
	addvar VAR_TEMP_1, 1
	compare VAR_TEMP_1, 4
	goto_if_eq EscapeRoom_IceCave2_EventScript_RockPuzzleAddSolve
	goto EscapeRoom_IceCave2_EventScript_RockPuzzleAddEnd
	
EscapeRoom_IceCave2_EventScript_RockPuzzleAdd4::
	lock
	goto_if_set FLAG_TEMP_4, EscapeRoom_IceCave2_EventScript_RockPuzzleAddEnd
	setflag FLAG_TEMP_4
	addvar VAR_TEMP_1, 1
	compare VAR_TEMP_1, 4
	goto_if_eq EscapeRoom_IceCave2_EventScript_RockPuzzleAddSolve
	goto EscapeRoom_IceCave2_EventScript_RockPuzzleAddEnd

EscapeRoom_IceCave2_EventScript_RockPuzzleReset::
	lock
	setvar VAR_TEMP_1, 0
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_2
	clearflag FLAG_TEMP_3
	clearflag FLAG_TEMP_4
	release
	end
	
EscapeRoom_IceCave2_EventScript_RockPuzzleAddSolve::
	goto_if_set FLAG_RECIEVED_CARD_KEY_ICE_CAVE EscapeRoom_IceCave2_EventScript_RockPuzzleAddSolveEnd
	giveitem ITEM_CARD_KEY, 1
		EscapeRoom_IceCave2_EventScript_RockPuzzleAddSolveEnd:
			release
			end