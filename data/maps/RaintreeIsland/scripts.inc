RaintreeIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RaintreeIsland_OnTransition
	.byte 0


RaintreeIsland_OnTransition: @ 81E950D
	setflag FLAG_VISITED_DEWFORD_TOWN
end

RaintreeIsland_EventScript_AmneetTravelingMerchant::
	lock
	faceplayer
	playbgm MUS_FV_PIMP, 0
	message RaintreeIsland_Text_AmneetRaintreeIslandMerchant
	waitmessage
	pokemart RaintreeIsland_Pokemart_Amneet
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

	.align 2
RaintreeIsland_Pokemart_Amneet:
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_SHELL_BELL
	.2byte ITEM_NONE
	release
	end

RaintreeIsland_Text_AmneetRaintreeIslandMerchant:
	.string "Aloha {PLAYER}. Good to see you.\n"
	.string "I've got some stuff that might\l"
	.string "help you out.$"
