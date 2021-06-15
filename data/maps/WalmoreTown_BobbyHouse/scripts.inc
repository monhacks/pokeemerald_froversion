WalmoreTown_BobbyHouse_MapScripts::
	.byte 0

WalmoreTown_BobbyHouse_EventScript_BobbysMom::
	lock
	//goto_if_set FLAG_RECIEVED_GRILLED_CHEESE
	//WalmoreTown_BobbyHouse_EventScript_BobbysMomAlreadyGaveGrilledCheese
	msgbox WalmoreTown_BobbyHouse_Text_BobbysMom, MSGBOX_NPC
	//giveitem ITEM_GRILLED_CHEESE
	msgbox WalmoreTown_BobbyHouse_Text_BobbysMomGivesGrilledCheese
	release
	end

WalmoreTown_BobbyHouse_EventScript_BobbysMomAlreadyGaveGrilledCheese::
	msgbox WalmoreTown_BobbyHouse_Text_BobbysMomHaveFunBeSafe, MSGBOX_NPC
	release
	end

WalmoreTown_BobbyHouse_Text_BobbysMom:
	.string "Hi Anthony. It's nice to see you.\p"
	.string "Bobby isn't home right now. He said\n"
	.string "He was going to head to Summit City\l"
	.string "to play Pokémon Battles with Chad and\l"
	.string "Mark.\p"
	.string "Are you heading there too? Would you\n"
	.string "Like a Grilled Cheese?$"

WalmoreTown_BobbyHouse_Text_BobbysMomGivesGrilledCheese:
	.string "Bobby and his Pokemon {COLOR BLUE}love {COLOR DARK_GREY}Grilled\n"
	.string "Cheese!$"

WalmoreTown_BobbyHouse_Text_BobbysMomHaveFunBeSafe:
	.string "Good luck out there. Have fun and\n"
	.string "be safe!$"
