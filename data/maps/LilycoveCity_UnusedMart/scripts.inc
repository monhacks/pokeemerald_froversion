LilycoveCity_UnusedMart_MapScripts:: @ 821C784
	.byte 0

LilycoveCity_UnusedMart_EventScript_VendingMachine:: @ 8220295
	lockall
	message LilycoveCity_UnusedMart_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0, 0
	goto LilycoveCity_UnusedMart_EventScript_ChooseDrink
	end

LilycoveCity_UnusedMart_EventScript_ChooseDrink:: @ 82202A6
	multichoice 16, 0, MULTI_TM_VENDING_MACHINE1, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_UnusedMart_EventScript_1
	case 1, LilycoveCity_UnusedMart_EventScript_2
	case 2, LilycoveCity_UnusedMart_EventScript_3
	case 3, LilycoveCity_UnusedMart_EventScript_4
	case 4, LilycoveCity_UnusedMart_EventScript_5
	case 5, LilycoveCity_UnusedMart_EventScript_6
	case 6, LilycoveCity_UnusedMart_EventScript_7
	case 7, LilycoveCity_UnusedMart_EventScript_Next
	case 8, LilycoveCity_UnusedMart_EventScript_ExitVendingMachine
	msgbox LilycoveCity_UnusedMart_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto LilycoveCity_UnusedMart_EventScript_ExitVendingMachine
	end

LilycoveCity_UnusedMart_EventScript_Next::
	multichoice 16, 0, MULTI_TM_VENDING_MACHINE2, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_UnusedMart_EventScript_8
	case 1, LilycoveCity_UnusedMart_EventScript_9
	case 2, LilycoveCity_UnusedMart_EventScript_10
	case 3, LilycoveCity_UnusedMart_EventScript_11
	case 4, LilycoveCity_UnusedMart_EventScript_12
	case 5, LilycoveCity_UnusedMart_EventScript_13
	case 6, LilycoveCity_UnusedMart_EventScript_ChooseDrink
	case 7, LilycoveCity_UnusedMart_EventScript_ExitVendingMachine
	msgbox LilycoveCity_UnusedMart_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto LilycoveCity_UnusedMart_EventScript_ExitVendingMachine
	end

LilycoveCity_UnusedMart_EventScript_1:: @ 82202E4
	setvar VAR_TEMP_0, ITEM_TM01
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_2:: @ 82202EF
	setvar VAR_TEMP_0, ITEM_TM02
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_3:: @ 82202FA
	setvar VAR_TEMP_0, ITEM_TM03
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_4:: @ 82202E4
	setvar VAR_TEMP_0, ITEM_TM04
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_5:: @ 82202EF
	setvar VAR_TEMP_0, ITEM_TM05
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_6:: @ 82202FA
	setvar VAR_TEMP_0, ITEM_TM06
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end
LilycoveCity_UnusedMart_EventScript_7:: @ 82202E4
	setvar VAR_TEMP_0, ITEM_TM07
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_8:: @ 82202EF
	setvar VAR_TEMP_0, ITEM_TM08
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_9:: @ 82202FA
	setvar VAR_TEMP_0, ITEM_TM09
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_10:: @ 82202E4
	setvar VAR_TEMP_0, ITEM_TM10
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_11:: @ 82202EF
	setvar VAR_TEMP_0, ITEM_TM11
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_12:: @ 82202FA
	setvar VAR_TEMP_0, ITEM_TM12
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_13:: @ 82202FA
	setvar VAR_TEMP_0, ITEM_TM13
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_CheckMoneyFreshWater:: @ 8220305
	checkmoney 200, 0
	return

LilycoveCity_UnusedMart_EventScript_CheckMoneySodaPop:: @ 822030C
	checkmoney 300, 0
	return

LilycoveCity_UnusedMart_EventScript_CheckMoneyLemonade:: @ 8220313
	checkmoney 350, 0
	return

LilycoveCity_UnusedMart_EventScript_RemoveMoneyFreshWater:: @ 822031A
	removemoney 200, 0
	return

LilycoveCity_UnusedMart_EventScript_RemoveMoneySodaPop:: @ 8220321
	removemoney 300, 0
	return

LilycoveCity_UnusedMart_EventScript_RemoveMoneyLemonade:: @ 8220328
	removemoney 350, 0
	return

LilycoveCity_UnusedMart_EventScript_TryBuyDrink:: @ 822032F
	compare VAR_TEMP_1, 0
	call_if_eq LilycoveCity_UnusedMart_EventScript_CheckMoneyFreshWater
	compare VAR_TEMP_1, 1
	call_if_eq LilycoveCity_UnusedMart_EventScript_CheckMoneySodaPop
	compare VAR_TEMP_1, 2
	call_if_eq LilycoveCity_UnusedMart_EventScript_CheckMoneyLemonade
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NoRoomForDrink
	compare VAR_TEMP_1, 0
	call_if_eq LilycoveCity_UnusedMart_EventScript_RemoveMoneyFreshWater
	compare VAR_TEMP_1, 1
	call_if_eq LilycoveCity_UnusedMart_EventScript_RemoveMoneySodaPop
	compare VAR_TEMP_1, 2
	call_if_eq LilycoveCity_UnusedMart_EventScript_RemoveMoneyLemonade
	updatemoneybox 0, 0
	bufferitemname 0, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_UnusedMart_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_UnusedMart_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_UnusedMart_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_UnusedMart_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_UnusedMart_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_UnusedMart_EventScript_ChooseNewDrink
	end

LilycoveCity_UnusedMart_EventScript_ChooseNewDrink:: @ 8220436
	message LilycoveCity_UnusedMart_Text_WhichDrinkWouldYouLike
	waitmessage
	goto LilycoveCity_UnusedMart_EventScript_ChooseDrink
	end

LilycoveCity_UnusedMart_EventScript_NotEnoughMoneyForDrink:: @ 8220442
	msgbox LilycoveCity_UnusedMart_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto LilycoveCity_UnusedMart_EventScript_ExitVendingMachine
	end

LilycoveCity_UnusedMart_EventScript_NoRoomForDrink:: @ 8220450
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto LilycoveCity_UnusedMart_EventScript_ExitVendingMachine
	end

LilycoveCity_UnusedMart_EventScript_ExitVendingMachine:: @ 822045E
	hidemoneybox
	releaseall
	end

LilycoveCity_UnusedMart_Text_WhichDrinkWouldYouLike: @ 822056D
	.string "It's a TM VENDING MACHINE.\n"
	.string "Which one would you like?$"

LilycoveCity_UnusedMart_Text_CanOfDrinkDroppedDown: @ 82205A1
	.string "Clang!\p"
	.string "A copy of {STR_VAR_1} dropped down.$"

LilycoveCity_UnusedMart_Text_ExtraCanOfDrinkDroppedDown: @ 82205C2
	.string "Clang!\p"
	.string "Score! An extra copy of {STR_VAR_1}\n"
	.string "dropped down!$"

LilycoveCity_UnusedMart_Text_NotEnoughMoney: @ 82205F1
	.string "Not enough money…$"

LilycoveCity_UnusedMart_Text_DecidedAgainstBuyingDrink: @ 8220603
	.string "Decided against buying anything.$"
