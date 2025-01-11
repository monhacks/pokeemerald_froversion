EscapeRoom_Mountain_MapScripts::
	.byte 0

EscapeRoom_Mountain_EventScript_GiveLavaSurf::
	checkitem ITEM_CARD_KEY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_Mountain_EventScript_GiveLavaSurfDontHaveKey
	msgbox EscapeRoom_Mountain_Text_BoxOpenedRecievedIceVest, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	release
	end

EscapeRoom_Mountain_EventScript_RockPuzzle1::
	lock
	compare VAR_MOUNTAIN_ROCK_PUZZLE, 2
	goto_if_ne EscapeRoom_Mountain_EventScript_ResetPuzzle
	addvar VAR_MOUNTAIN_ROCK_PUZZLE, 1
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	release
	end

EscapeRoom_Mountain_EventScript_RockPuzzle2::
	lock
	compare VAR_MOUNTAIN_ROCK_PUZZLE, 4
	goto_if_ne EscapeRoom_Mountain_EventScript_ResetPuzzle
	addvar VAR_MOUNTAIN_ROCK_PUZZLE, 1
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	release
	end

EscapeRoom_Mountain_EventScript_RockPuzzle3::
	lock
	compare VAR_MOUNTAIN_ROCK_PUZZLE, 1
	goto_if_ne EscapeRoom_Mountain_EventScript_ResetPuzzle
	addvar VAR_MOUNTAIN_ROCK_PUZZLE, 1
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	release
	end

EscapeRoom_Mountain_EventScript_RockPuzzle4::
	lock
	compare VAR_MOUNTAIN_ROCK_PUZZLE, 0
	goto_if_ne EscapeRoom_Mountain_EventScript_ResetPuzzle
	addvar VAR_MOUNTAIN_ROCK_PUZZLE, 1
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	release
	end

EscapeRoom_Mountain_EventScript_RockPuzzle5::
	lock
	compare VAR_MOUNTAIN_ROCK_PUZZLE, 7
	goto_if_ne EscapeRoom_Mountain_EventScript_ResetPuzzle
	goto_if_eq EscapeRoom_Mountain_EventScript_PuzzleSolved
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	release
	end

EscapeRoom_Mountain_EventScript_RockPuzzle6:: 
	lock
	compare VAR_MOUNTAIN_ROCK_PUZZLE, 6
	goto_if_ne EscapeRoom_Mountain_EventScript_ResetPuzzle
	addvar VAR_MOUNTAIN_ROCK_PUZZLE, 1
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	release
	end

EscapeRoom_Mountain_EventScript_RockPuzzle7::
	lock
	compare VAR_MOUNTAIN_ROCK_PUZZLE, 5
	goto_if_ne EscapeRoom_Mountain_EventScript_ResetPuzzle
	addvar VAR_MOUNTAIN_ROCK_PUZZLE, 1
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	release
	end

EscapeRoom_Mountain_EventScript_RockPuzzle8::
	lock
	compare VAR_MOUNTAIN_ROCK_PUZZLE, 3
	goto_if_ne EscapeRoom_Mountain_EventScript_ResetPuzzle
	addvar VAR_MOUNTAIN_ROCK_PUZZLE, 1
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	release
	end

EscapeRoom_Mountain_EventScript_ResetPuzzle:
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	setvar VAR_MOUNTAIN_ROCK_PUZZLE, 0
	release
	end

EscapeRoom_Mountain_EventScript_PuzzleSolved:
	goto_if_set FLAG_RECEIVED_TM11, EscapeRoom_Mountain_EventScript_ResetPuzzle
	giveitem ITEM_TM18, 1
	setflag FLAG_RECEIVED_TM11
	release
	end

EscapeRoom_Mountain_EventScript_FinalPuzzleTrigger1:: @@ 1->2
	compare VAR_FINAL_MOUNTAIN_PUZZLE, 1
	goto_if_eq EscapeRoom_Mountain_EventScript_FinalPuzzleAddVar
	setvar VAR_FINAL_MOUNTAIN_PUZZLE, 25
	release
	end

EscapeRoom_Mountain_EventScript_FinalPuzzleTrigger2:: @@ 0->1
	compare VAR_FINAL_MOUNTAIN_PUZZLE, 0
	goto_if_eq EscapeRoom_Mountain_EventScript_FinalPuzzleAddVar
	setvar VAR_FINAL_MOUNTAIN_PUZZLE, 25
	release
	end

EscapeRoom_Mountain_EventScript_FinalPuzzleTrigger3:: @@ 2->3
	compare VAR_FINAL_MOUNTAIN_PUZZLE, 2
	goto_if_eq EscapeRoom_Mountain_EventScript_FinalPuzzleAddVar
	setvar VAR_FINAL_MOUNTAIN_PUZZLE, 25
	release
	end

EscapeRoom_Mountain_EventScript_FinalPuzzleTrigger4:: @@ 3->4
	compare VAR_FINAL_MOUNTAIN_PUZZLE, 3
	goto_if_eq EscapeRoom_Mountain_EventScript_FinalPuzzleAddVar
	setvar VAR_FINAL_MOUNTAIN_PUZZLE, 25
	release
	end

EscapeRoom_Mountain_EventScript_FinalPuzzleAddVar:
	addvar VAR_FINAL_MOUNTAIN_PUZZLE, 1
	compare VAR_FINAL_MOUNTAIN_PUZZLE, 4
	goto_if_eq EscapeRoom_Mountain_EventScript_FinalPuzzleSolved
	release
	end

EscapeRoom_Mountain_EventScript_FinalPuzzleSolved:
	addobject 7
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	playse SE_SAVE
	waitse
	release
	end

EscapeRoom_Mountain_EventScript_FinalPuzzleClue::
	msgbox EscapeRoom_Mountain_Text_FinalPuzzleSolved, MSGBOX_DEFAULT
	setflag FLAG_SNOW_FINAL_PUZZLE_SOLVED
	release
	end

EscapeRoom_Mountain_EventScript_GrassRoomFinalClue::
	lockall
	msgbox EscapeRoom_Mountain_Text_GrassRoomFinalClue, MSGBOX_DEFAULT
	releaseall
	end


EscapeRoom_Mountain_EventScript_GiveLavaSurfDontHaveKey:	
	msgbox EscapeRoom_Mountain_Text_GiveLavaSurfDontHaveKey, MSGBOX_DEFAULT
	release
	end

EscapeRoom_Mountain_Text_GiveLavaSurfDontHaveKey:
	.string "Looks like a key can open this\n"
	.string "box.$"

EscapeRoom_Mountain_Text_BoxOpenedRecievedIceVest:
	.string "The box opened...\n"
	.string "\l"
	.string "It contains a vest and a note.\p"
	.string "“Have your Pokémon wear this vest\n"
	.string "made of pure unmeltable ice to\l"
	.string "protect their skin.\p"
	.string "This will allow them to surf on hot\n"
	.string "Surfaces!"

EscapeRoom_Mountain_Text_GrassRoomFinalClue:
	.string "Grass room final clue.$"

EscapeRoom_Mountain_Text_FinalPuzzleSolved:
	.string "Dra Vencd vuin hispan luta du aclyba\n"
	.string "ec: Aekrd, Vuin, Uha, Heha$"

