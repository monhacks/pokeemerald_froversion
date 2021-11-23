HomesteadSouth_FrattHouse_MapScripts::
	.byte 0

////////////////////////
/////////TRAINERS///////
////////////////////////

FrattHouse_EventScript_NotReady::
	msgbox FrattHouse_Text_LetOneOfUsKnowWhenReady, MSGBOX_DEFAULT
	release
end

FrattHouse_EventScript_WasulaBattleCheck::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FRATT_HOUSE_ITEM, FrattHouse_EventScript_WasulaBattleStart
	compare VAR_TEMP_0, 1
	goto_if_eq FrattHouse_EventScript_WasulaBattleStart
	msgbox FrattHouse_Text_ExplainChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FrattHouse_EventScript_NotReady
	case YES, FrattHouse_EventScript_WasulaBattleStart
	case MULTI_B_PRESSED, FrattHouse_EventScript_NotReady
	release
end

FrattHouse_EventScript_WasulaBattleStart:
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	setflag FLAG_BATTLE_RECHARGE 
	setflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_FORCE_BATTLE_STYLE_SET
	setvar VAR_TEMP_0, 1
	trainerbattle_single TRAINER_DUSTY_2, FrattHouse_Text_WasulaIntro, FrattHouse_Text_WasulaPostBattleMessage, FrattHouse_EventScript_WasulaResult, NO_MUSIC
end

FrattHouse_EventScript_WasulaResult:
	clearflag FLAG_BATTLE_RECHARGE
	clearflag FLAG_CAN_LOSE_NEXT_BATTLE
	clearflag FLAG_SYS_NO_BAG_USE
	clearflag FLAG_FORCE_BATTLE_STYLE_SET
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq FrattHouse_EventScript_WasulaBattleLost
	goto FrattHouse_EventScript_WasulaBattleWon
end

FrattHouse_EventScript_WasulaBattleLost:
	special HealPlayerParty
	cleartrainerflag TRAINER_DUSTY_2
	setvar VAR_TEMP_1, 0
	msgbox FrattHouse_Text_WasulaBattleLost, MSGBOX_DEFAULT
	release
end

FrattHouse_EventScript_WasulaBattleWon:
	msgbox FrattHouse_Text_WasulaBattleWon, MSGBOX_DEFAULT
	addvar VAR_TEMP_1, 1
	compare VAR_TEMP_1, 8
	goto_if_eq FrattHouse_EventScript_BeatAllTrainers
	release
end

FrattHouse_EventScript_MarkBattleCheck::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FRATT_HOUSE_ITEM, FrattHouse_EventScript_MarkBattleStart
	compare VAR_TEMP_0, 1
	goto_if_eq FrattHouse_EventScript_MarkBattleStart
	msgbox FrattHouse_Text_ExplainChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FrattHouse_EventScript_NotReady
	case YES, FrattHouse_EventScript_MarkBattleStart
	case MULTI_B_PRESSED, FrattHouse_EventScript_NotReady
	release
end

FrattHouse_EventScript_MarkBattleStart:
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	setflag FLAG_BATTLE_POST_PRODUCTION
	setflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_FORCE_BATTLE_STYLE_SET
	setvar VAR_TEMP_0, 1
	trainerbattle_single TRAINER_DUSTY_3, FrattHouse_Text_MarkIntro, FrattHouse_Text_MarkPostBattleMessage, FrattHouse_EventScript_MarkResult, NO_MUSIC
end

FrattHouse_EventScript_MarkResult:
	clearflag FLAG_BATTLE_POST_PRODUCTION
	clearflag FLAG_CAN_LOSE_NEXT_BATTLE
	clearflag FLAG_SYS_NO_BAG_USE
	clearflag FLAG_FORCE_BATTLE_STYLE_SET
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq FrattHouse_EventScript_MarkBattleLost
	goto FrattHouse_EventScript_MarkBattleWon
end

FrattHouse_EventScript_MarkBattleLost:
	special HealPlayerParty
	cleartrainerflag TRAINER_DUSTY_3
	setvar VAR_TEMP_1, 0
	msgbox FrattHouse_Text_MarkBattleLost, MSGBOX_DEFAULT
	release
end

FrattHouse_EventScript_MarkBattleWon:
	msgbox FrattHouse_Text_MarkBattleWon, MSGBOX_DEFAULT
	addvar VAR_TEMP_1, 1
	compare VAR_TEMP_1, 8
	goto_if_eq FrattHouse_EventScript_BeatAllTrainers
	release
end

FrattHouse_EventScript_KostiwBattleCheck::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FRATT_HOUSE_ITEM, FrattHouse_EventScript_KostiwBattleStart
	compare VAR_TEMP_0, 1
	goto_if_eq FrattHouse_EventScript_KostiwBattleStart
	msgbox FrattHouse_Text_ExplainChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FrattHouse_EventScript_NotReady
	case YES, FrattHouse_EventScript_KostiwBattleStart
	case MULTI_B_PRESSED, FrattHouse_EventScript_NotReady
	release
end

FrattHouse_EventScript_KostiwBattleStart:
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	setflag FLAG_BATTLE_HAUNTING 
	setflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_FORCE_BATTLE_STYLE_SET
	setvar VAR_TEMP_0, 1
	trainerbattle_single TRAINER_DUSTY_4, FrattHouse_Text_KostiwIntro, FrattHouse_Text_KostiwPostBattleMessage, FrattHouse_EventScript_KostiwResult, NO_MUSIC
end

FrattHouse_EventScript_KostiwResult:
	clearflag FLAG_BATTLE_HAUNTING
	clearflag FLAG_CAN_LOSE_NEXT_BATTLE
	clearflag FLAG_SYS_NO_BAG_USE
	clearflag FLAG_FORCE_BATTLE_STYLE_SET
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq FrattHouse_EventScript_KostiwBattleLost
	goto FrattHouse_EventScript_KostiwBattleWon
end

FrattHouse_EventScript_KostiwBattleLost:
	special HealPlayerParty
	cleartrainerflag TRAINER_DUSTY_4
	setvar VAR_TEMP_1, 0
	msgbox FrattHouse_Text_KostiwBattleLost, MSGBOX_DEFAULT
	release
end

FrattHouse_EventScript_KostiwBattleWon:
	msgbox FrattHouse_Text_KostiwBattleWon, MSGBOX_DEFAULT
	addvar VAR_TEMP_1, 1
	compare VAR_TEMP_1, 8
	goto_if_eq FrattHouse_EventScript_BeatAllTrainers
	release
end


FrattHouse_EventScript_BeatAllTrainers::
	cleartrainerflag TRAINER_DUSTY_2
	cleartrainerflag TRAINER_DUSTY_3
	cleartrainerflag TRAINER_DUSTY_4
	goto_if_set FLAG_RECEIVED_FRATT_HOUSE_ITEM, FrattHouse_EventScript_AlreadyReceivedItem
	msgbox FrattHouse_Text_WonChallenge, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, FrattHouse_EventScript_GiveRascalootItem //fros starter is rascaloot
	case 1, FrattHouse_EventScript_GiveFlobraItem //fros starter is flobra
	case 2, FrattHouse_EventScript_GiveEmborypsItem //fros starter is emboryps
end

FrattHouse_EventScript_GiveRascalootItem:
	giveitem ITEM_ANTIDOTE
	setflag FLAG_RECEIVED_FRATT_HOUSE_ITEM
	setvar VAR_TEMP_1, 0
	release
end

FrattHouse_EventScript_GiveFlobraItem:
	giveitem ITEM_POTION
	setflag FLAG_RECEIVED_FRATT_HOUSE_ITEM
	setvar VAR_TEMP_1, 0
	release
end

FrattHouse_EventScript_GiveEmborypsItem:
	giveitem ITEM_REPEL
	setflag FLAG_RECEIVED_FRATT_HOUSE_ITEM
	setvar VAR_TEMP_1, 0
	release
end

FrattHouse_EventScript_AlreadyReceivedItem:
	msgbox FrattHouse_Text_AlreadyReceivedItem, MSGBOX_DEFAULT
	release
end


////////////////
/////Texts/////
///////////////

FrattHouse_Text_ExplainChallenge:
	.string "{PLAYER}!\p"
	.string "Glad you could come to hang out with\n"
	.string "us!\p"
	.string "We are all in the mood to battle.\n"
	.string "In fact, we have set up a challenge\l"
	.string "for anyone up for a challenge!\p"
	.string "If you can beat all of us\n"
	.string "consecutively without leaving,\l"
	.string "we will give you a special\l"
	.string "prize!\p"
	.string "So what do you say, would you like to\n"
	.string "give the challenge a try?$"

FrattHouse_Text_LetOneOfUsKnowWhenReady:
	.string "Okay, no problem! Let any one of\n"
	.string "us know when you want to give it\l"
	.string "a try!$"

FrattHouse_Text_WasulaIntro:
	.string "Alright, he we go.\n"
	.string "Give it your best shot!$"

FrattHouse_Text_WasulaPostBattleMessage:
	.string "That was heavy!$"

FrattHouse_Text_WasulaBattleLost:
	.string "Well, you gave it your best try.\p"
	.string "Try again whenever you would like.$"

FrattHouse_Text_WasulaBattleWon:
	.string "Man with confidence like that you\n"
	.string "have to bench at least 295!\p"
	.string "Congrats on the win, good luck with\n"
	.string "the rest of the battles!$"

FrattHouse_Text_MarkIntro:
	.string "This is going to be radical,\n"
	.string "{PLAYER}!\p"
	.string "Let's have a great match!$"

FrattHouse_Text_MarkPostBattleMessage:
	.string "That was INTERESTING!!$"

FrattHouse_Text_MarkBattleLost:
	.string "Aw jeez, no dice!\p"
	.string "Try again whenever you would like.$"

FrattHouse_Text_MarkBattleWon:
	.string "Oof, you're an incredible\n"
	.string "trainer!\n"

FrattHouse_Text_KostiwIntro:
	.string "This won't be as easy as our gym\n"
	.string "battle, {PLAYER}!\p"
	.string "Get ready for a real haunt!$"

FrattHouse_Text_KostiwPostBattleMessage:
	.string "Spooky!$"

FrattHouse_Text_KostiwBattleLost:
	.string "That battle will be haunting\p"
	.string "you for the rest of the day!"
	.string "Try again whenever you would like.$"

FrattHouse_Text_KostiwBattleWon:
	.string "You're too spooky for me.$"

FrattHouse_Text_WonChallenge:
	.string "Woah! You beat all of us!\p"
	.string "That is a serious achievement!\p"
	.string "As promised, here is your special\n"
	.string "prize!\p"
	.string "Great job!. Feel free to challenge\n"
	.string "us again anytime, but there won't\l"
	.string "be any prizes next time!$"

FrattHouse_Text_AlreadyReceivedItem:
	.string "Congrats on beating us again,\n"
	.string "but only one prize per\l"
	.string "contestant.\p"
