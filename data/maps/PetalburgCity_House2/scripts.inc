PetalburgCity_House2_MapScripts:: @ 82078F2
	.byte 0

PetalburgCity_House2_EventScript_Woman:: @ 82078F3
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid:: @ 82078FC
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader: @ 8207905
	.string "Grant became our town's new\n"
	.string "Gym Leader.\p"
	.string "He moved back here after losing\n"
	.string "all his money gambling. Now he\l"
	.string "can only afford to live in this\l"
	.string "run down trailer park.$"

PetalburgCity_House2_Text_BattledNormanOnce: @ 8207969
	.string "I battled Grant once, but, whew,\n"
	.string "he was way too strong.\p"
	.string "How would I put it?\p"
	.string "I just got the feeling that he\n"
	.string "lives for Pokémon.$"

