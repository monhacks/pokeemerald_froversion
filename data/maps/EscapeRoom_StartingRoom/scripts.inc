EscapeRoom_StartingRoom_MapScripts::
	.byte 0


EscapeRoom_StartingRoom_EventScript_SolveTheRiddle::
	end

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
