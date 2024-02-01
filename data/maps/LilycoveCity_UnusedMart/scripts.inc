LilycoveCity_UnusedMart_MapScripts:: @ 821C784
	.byte 0

LilycoveCity_UnusedMart_EventScript_VendingMachine:: @ 8220295
	lockall
	msgbox LilycoveCity_UnusedMart_Text_WhichDrinkWouldYouLike, MSGBOX_DEFAULT
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
	case 5, LilycoveCity_UnusedMart_EventScript_ChooseDrink
	case 6, LilycoveCity_UnusedMart_EventScript_ExitVendingMachine
	msgbox LilycoveCity_UnusedMart_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto LilycoveCity_UnusedMart_EventScript_ExitVendingMachine
	end

LilycoveCity_UnusedMart_EventScript_1:: @ 82202E4
	setvar VAR_TEMP_0, ITEM_TM01
	goto_if_set FLAG_VENDINGMACHINE_TM1, LilycoveCity_UnusedMart_EventScript_TMSoldOut
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_2:: @ 82202EF
	setvar VAR_TEMP_0, ITEM_TM02
	goto_if_set FLAG_VENDINGMACHINE_TM2, LilycoveCity_UnusedMart_EventScript_TMSoldOut
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_3:: @ 82202FA
	setvar VAR_TEMP_0, ITEM_TM03
	goto_if_set FLAG_VENDINGMACHINE_TM3, LilycoveCity_UnusedMart_EventScript_TMSoldOut
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_4:: @ 82202E4
	setvar VAR_TEMP_0, ITEM_TM04
	goto_if_set FLAG_VENDINGMACHINE_TM4, LilycoveCity_UnusedMart_EventScript_TMSoldOut
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_5:: @ 82202EF
	setvar VAR_TEMP_0, ITEM_TM05
	goto_if_set FLAG_VENDINGMACHINE_TM5, LilycoveCity_UnusedMart_EventScript_TMSoldOut
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_6:: @ 82202FA
	setvar VAR_TEMP_0, ITEM_TM06
	goto_if_set FLAG_VENDINGMACHINE_TM6, LilycoveCity_UnusedMart_EventScript_TMSoldOut
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end
LilycoveCity_UnusedMart_EventScript_7:: @ 82202E4
	setvar VAR_TEMP_0, ITEM_TM07
	goto_if_set FLAG_VENDINGMACHINE_TM7, LilycoveCity_UnusedMart_EventScript_TMSoldOut
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink
	end

LilycoveCity_UnusedMart_EventScript_8:: @ 82202EF
	setvar VAR_TEMP_0, ITEM_TM08
	goto_if_set FLAG_VENDINGMACHINE_TM8, LilycoveCity_UnusedMart_EventScript_TMSoldOut2
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2
	end

LilycoveCity_UnusedMart_EventScript_9:: @ 82202FA
	setvar VAR_TEMP_0, ITEM_TM09
	goto_if_set FLAG_VENDINGMACHINE_TM9, LilycoveCity_UnusedMart_EventScript_TMSoldOut2
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2
	end

LilycoveCity_UnusedMart_EventScript_10:: @ 82202E4
	setvar VAR_TEMP_0, ITEM_TM10
	goto_if_set FLAG_VENDINGMACHINE_TM10, LilycoveCity_UnusedMart_EventScript_TMSoldOut2
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2
	end

LilycoveCity_UnusedMart_EventScript_11:: @ 82202EF
	setvar VAR_TEMP_0, ITEM_TM11
	goto_if_set FLAG_VENDINGMACHINE_TM11, LilycoveCity_UnusedMart_EventScript_TMSoldOut2
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2
	end

LilycoveCity_UnusedMart_EventScript_12:: @ 82202FA
	setvar VAR_TEMP_0, ITEM_TM12
	goto_if_set FLAG_VENDINGMACHINE_TM12, LilycoveCity_UnusedMart_EventScript_TMSoldOut2
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2
	end

LilycoveCity_UnusedMart_EventScript_CheckMoney:: @ 8220305
	checkmoney 200, 0
	return

LilycoveCity_UnusedMart_EventScript_RemoveMoney:: @ 822031A
	removemoney 200, 0
	return

LilycoveCity_UnusedMart_EventScript_TMSoldOut::
	message LilycoveCity_UnusedMart_Text_TMSoldOut
	waitmessage
	goto LilycoveCity_UnusedMart_EventScript_ChooseDrink

LilycoveCity_UnusedMart_EventScript_TMSoldOut2::
	message LilycoveCity_UnusedMart_Text_TMSoldOut
	waitmessage
	goto LilycoveCity_UnusedMart_EventScript_Next

LilycoveCity_UnusedMart_EventScript_TryBuyDrink:: @ 822032F
	call LilycoveCity_UnusedMart_EventScript_CheckMoney
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NoRoomForDrink
	call LilycoveCity_UnusedMart_EventScript_RemoveMoney
	updatemoneybox 0, 0
	bufferitemname 0, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_UnusedMart_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_UnusedMart_EventScript_SetTMFlag
	
LilycoveCity_UnusedMart_EventScript_TryBuyDrink1::	
	random 64  																			@ 1/64 chance of an additional drink dropping
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
	random 64  																			@ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
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

LilycoveCity_UnusedMart_EventScript_TryBuyDrink2:: @ 822032F
	call LilycoveCity_UnusedMart_EventScript_CheckMoney
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NoRoomForDrink
	call LilycoveCity_UnusedMart_EventScript_RemoveMoney
	updatemoneybox 0, 0
	bufferitemname 0, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_UnusedMart_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_UnusedMart_EventScript_SetTMFlag

LilycoveCity_UnusedMart_EventScript_TryBuyDrink2b::	
	random 64  																			@ 1/64 chance of an additional drink dropping
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_UnusedMart_EventScript_ChooseNewDrink2
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_UnusedMart_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  																			@ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_UnusedMart_EventScript_ChooseNewDrink2
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_UnusedMart_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_UnusedMart_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_UnusedMart_EventScript_ChooseNewDrink2
	end

LilycoveCity_UnusedMart_EventScript_SetTMFlag::
	switch VAR_TEMP_0
	case ITEM_TM01, LilycoveCity_UnusedMart_EventScript_TM1Sold
	case ITEM_TM02, LilycoveCity_UnusedMart_EventScript_TM2Sold
	case ITEM_TM03, LilycoveCity_UnusedMart_EventScript_TM3Sold
	case ITEM_TM04, LilycoveCity_UnusedMart_EventScript_TM4Sold
	case ITEM_TM05, LilycoveCity_UnusedMart_EventScript_TM5Sold
	case ITEM_TM06, LilycoveCity_UnusedMart_EventScript_TM6Sold
	case ITEM_TM07, LilycoveCity_UnusedMart_EventScript_TM7Sold
	case ITEM_TM08, LilycoveCity_UnusedMart_EventScript_TM8Sold
	case ITEM_TM09, LilycoveCity_UnusedMart_EventScript_TM9Sold
	case ITEM_TM10, LilycoveCity_UnusedMart_EventScript_TM10Sold
	case ITEM_TM11, LilycoveCity_UnusedMart_EventScript_TM11Sold
	case ITEM_TM12, LilycoveCity_UnusedMart_EventScript_TM12Sold
end

LilycoveCity_UnusedMart_EventScript_TM1Sold::
	setflag FLAG_VENDINGMACHINE_TM1
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink1
end

LilycoveCity_UnusedMart_EventScript_TM2Sold::
	setflag FLAG_VENDINGMACHINE_TM2
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink1
end

LilycoveCity_UnusedMart_EventScript_TM3Sold::
	setflag FLAG_VENDINGMACHINE_TM3
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink1
end

LilycoveCity_UnusedMart_EventScript_TM4Sold::
	setflag FLAG_VENDINGMACHINE_TM4
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink1
end

LilycoveCity_UnusedMart_EventScript_TM5Sold::
	setflag FLAG_VENDINGMACHINE_TM5
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink1
end

LilycoveCity_UnusedMart_EventScript_TM6Sold::
	setflag FLAG_VENDINGMACHINE_TM6
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink1
end

LilycoveCity_UnusedMart_EventScript_TM7Sold::
	setflag FLAG_VENDINGMACHINE_TM7
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink1
end

LilycoveCity_UnusedMart_EventScript_TM8Sold::
	setflag FLAG_VENDINGMACHINE_TM8
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2b
end

LilycoveCity_UnusedMart_EventScript_TM9Sold::
	setflag FLAG_VENDINGMACHINE_TM9
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2b
end

LilycoveCity_UnusedMart_EventScript_TM10Sold::
	setflag FLAG_VENDINGMACHINE_TM10
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2b
end

LilycoveCity_UnusedMart_EventScript_TM11Sold::
	setflag FLAG_VENDINGMACHINE_TM11
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2b
end

LilycoveCity_UnusedMart_EventScript_TM12Sold::
	setflag FLAG_VENDINGMACHINE_TM12
	goto LilycoveCity_UnusedMart_EventScript_TryBuyDrink2b
end

LilycoveCity_UnusedMart_EventScript_ChooseNewDrink:: @ 8220436
	message LilycoveCity_UnusedMart_Text_WhichDrinkWouldYouLike
	waitmessage
	goto LilycoveCity_UnusedMart_EventScript_ChooseDrink
	end

LilycoveCity_UnusedMart_EventScript_ChooseNewDrink2:: @ 8220436
	message LilycoveCity_UnusedMart_Text_WhichDrinkWouldYouLike
	waitmessage
	goto LilycoveCity_UnusedMart_EventScript_Next
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

LilycoveCity_UnusedMart_Text_TMSoldOut:
	.string "This TM is sold out. Choose a\n"
	.string "different one!$"
