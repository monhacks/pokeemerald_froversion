HomesteadNorth_House4_MapScripts::
	.byte 0

HomesteadNorth_EventScript_House4Man1::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_CommonBond, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_CommonBond:
	.string "Our whole town comes together every\n"
	.string "Christmas to celebrate.\p"
	.string "It's great for the community to have\n"
	.string "that common bond.$"

HomesteadNorth_EventScript_House4Man2::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_ImFromEngland, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_ImFromEngland:
	.string "Happy Christmas! I'm from England.\p"
	.string "I moved here just because I love\n"
	.string "Christmas so much!$"

HomesteadNorth_EventScript_House4Man3::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_StayJolly, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_StayJolly:
	.string "There's an old law on the books\n"
	.string "that everyone must be jolly, all\l"
	.string "year round.\p"
	.string "It's never been enforced. As long\n"
	.string "as you stay jolly, there's nothing\l"
	.string "to worry about!$"
	