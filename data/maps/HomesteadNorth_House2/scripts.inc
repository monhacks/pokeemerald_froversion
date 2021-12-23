HomesteadNorth_House2_MapScripts::
	.byte 0

HomesteadNorth_EventScript_GameBoyKid::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_TopThreeGifts, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_TopThreeGifts:
	.string "My top three gifts on my wishlist\n"
	.string "this year are gold, frankinsence,\l"
	.string "and myrrh.\p"
	.string "Last year, all I got was a lump\n"
	.string "of coal...$"

HomesteadNorth_EventScript_House2Woman::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_NicksTurn, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_NicksTurn:
	.string "Everyone in town takes turn playing\n"
	.string "Santa.\p"
	.string "This year, it's Nick's turn.\n"
	.string "Imagine that! Haha!$"
