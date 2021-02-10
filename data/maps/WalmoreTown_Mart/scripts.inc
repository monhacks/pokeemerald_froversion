WalmoreTown_Mart_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, WalmoreTown_Mart_OnFrame
	.byte 0
	
	WalmoreTown_Mart_OnFrame:
	map_script_2 VAR_OLDALE_TOWN_STATE, 0, Script_WalmoreTownMart_TilyousPackage
	.2byte 0
	
Script_WalmoreTownMart_TilyousPackage:
	lock
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	msgbox T_WalmoreTown_HeyYoureFromLakeMeadVillage, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, M_WalkToCashier
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox T_WalmoreTown_TakeTilyousParcel, MSGBOX_DEFAULT
	giveitem ITEM_OAKS_PARCEL, 1
	setvar VAR_OLDALE_TOWN_STATE, 1
	release
	end

WalmoreTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, WalmoreTown_Mart_ExpandedItems
	pokemart WalmoreTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

WalmoreTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

WalmoreTown_Mart_ExpandedItems:: 
	pokemart WalmoreTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
WalmoreTown_Mart_Pokemart_Expanded: 
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end
	
WalmoreTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, WalmoreTown_Mart_EventScript_PokeBallsInStock
	msgbox WalmoreTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

WalmoreTown_Mart_EventScript_PokeBallsInStock::
	msgbox WalmoreTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

WalmoreTown_Mart_EventScript_Boy::
	msgbox WalmoreTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

//Movements

M_WalkToCashier:
walk_up
walk_up
walk_up
walk_up
face_left
step_end

//Text

T_WalmoreTown_HeyYoureFromLakeMeadVillage:
	.string "Cashier: Hey!\pYou're Fro, from Lake Mead \nVillage right?\p"
	.string "Fro: Hell yeah!\p"
	.string "Cashier: Can you come here I have \na favor to ask you?$"
	
T_WalmoreTown_TakeTilyousParcel:
	.string "I recieved this parcel addressed to \nProf. Tilyou. \pAmazon acidentally delivered it \nhere, is there any chance you could \ltake this back to the Professor for \lme?\p"
	.string "Fro: Sure no problem, I don't have \nanything better to do.\p"
	.string "Cashier: Gee thanks, you're a life \nsaver!$"
	

WalmoreTown_Mart_Text_PokeBallsAreSoldOut:
	.string "The clerk says they're all sold out.\n"
	.string "I can't buy any Poké balls.$"

WalmoreTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "I'm going to buy a bunch of Poké balls\n"
	.string "and catch a bunch of Pokémon!$"

WalmoreTown_Mart_Text_RestoreHPWithPotion:
	.string "If a Pokémon gets hurt and loses its HP\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your Pokémon from fainting,\n"
	.string "restore its HP with a potion.$"
