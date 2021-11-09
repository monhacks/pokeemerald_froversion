WalmoreTown_BobbyHouse_MapScripts::
	.byte 0

WalmoreTown_BobbyHouse_EventScript_BobbysMom::
	lock
	goto_if_set FLAG_RECIEVED_GRILLED_CHEESE, WalmoreTown_BobbyHouse_EventScript_BobbysMomAlreadyGaveGrilledCheese
	msgbox WalmoreTown_BobbyHouse_Text_BobbysMom, MSGBOX_NPC
	giveitem ITEM_GRILLED_CHEESE
	msgbox WalmoreTown_BobbyHouse_Text_BobbysMomGivesGrilledCheese
	setflag FLAG_RECIEVED_GRILLED_CHEESE
	release
	end

WalmoreTown_BobbyHouse_EventScript_BobbysMomAlreadyGaveGrilledCheese::
	msgbox WalmoreTown_BobbyHouse_Text_BobbysMomHaveFunBeSafe, MSGBOX_NPC
	checkitem ITEM_HEART_SCALE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq WalmoreTown_BobbysHouse_EventScript_ComeBackWithHeartScale
	msgbox WalmoreTown_BobbysHouse_Text_ThatsAHeartScaleWantGrilledCheese, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, WalmoreTown_BobbysHouse_EventScript_ComeBackWithHeartScale
	goto WalmoreTown_BobbysHouse_EventScript_GiveGrilledCheese
	release
	end

WalmoreTown_BobbysHouse_EventScript_GiveGrilledCheese:
	msgbox WalmoreTown_BobbyHouse_Text_ThankYouForHeartScale, MSGBOX_NPC
	giveitem ITEM_GRILLED_CHEESE, 1
	removeitem ITEM_HEART_SCALE, 1
	release
	end

WalmoreTown_BobbyHouse_Text_ThankYouForHeartScale:
	.string "Thank you so much!\p"
	.string "Here is your Grilled Cheese!\p"
	.string "Come back anytime for more!$"

WalmoreTown_BobbysHouse_Text_ThatsAHeartScaleWantGrilledCheese:
	.string "Hey you have a Heart Scale!\p"
	.string "Want to trade it for a Grilled\n"
	.string "cheese?$"

WalmoreTown_BobbysHouse_EventScript_ComeBackWithHeartScale:
	msgbox WalmoreTown_BobbysHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	release
	end

WalmoreTown_BobbysHouse_Text_ComeBackWithHeartScale:
	.string "If you want a Grilled Cheese you\n"
	.string "need to bring me a Heart Scale.$"

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
	.string "be safe!\p"
	.string "Also, I'm collecting Heart Scales\n"
	.string "for a project, if you can bring them\l"
	.string "some, I will make you more Grilled\l"
	.string "Cheese!$"
