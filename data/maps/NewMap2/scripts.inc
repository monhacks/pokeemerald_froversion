NewMap2_MapScripts::
	.byte 0


npc1eventscript::
	lockall
	msgbox testdialogue, MSGBOX_DEFAULT
	release
	end

testdialogue::
	.string "First line\n"
	.string "second line\l"
	.string "third line and on\l"
	.string "reset paragraph\p"
	.string "Escape text$"