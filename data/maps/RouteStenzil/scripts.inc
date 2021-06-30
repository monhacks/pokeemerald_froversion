.set LOCALID_BOBBY, 1

RouteStenzil_MapScripts::
	.byte 0


SummitCave_EventScript_BobbyRivalBattleTrigger1::
	lock
	addobject LOCALID_BOBBY
	setvar VAR_MUGSHOT_ID, MUGSHOT_WASULA
	applymovement LOCALID_BOBBY, Movement_SummitCave_BobbyApproachesFroTrigger1
	waitmovement LOCALID_BOBBY
	msgbox Text_SummitCave_HaventMadeItToSummitCityYet, MSGBOX_DEFAULT
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	switch VAR_STARTER_MON
	case 0, Script_SummitCave_WasulaBattleFlobra //fros starter is rascaloot
	case 1, Script_SummitCave_WasulaBattleEmboryps //fros starter is flobra
	case 2, Script_SummitCave_WasulaBattleRascaloot //fros starter is emboryps
	release
	end

SummitCave_EventScript_BobbyRivalBattleTrigger2::
	lock
	addobject LOCALID_BOBBY
	setvar VAR_MUGSHOT_ID, MUGSHOT_WASULA
	applymovement LOCALID_BOBBY, Movement_SummitCave_BobbyApproachesFroTrigger2
	waitmovement LOCALID_BOBBY
	msgbox Text_SummitCave_HaventMadeItToSummitCityYet, MSGBOX_DEFAULT
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	switch VAR_STARTER_MON
	case 0, Script_SummitCave_WasulaBattleFlobra
	case 1, Script_SummitCave_WasulaBattleEmboryps
	case 2, Script_SummitCave_WasulaBattleRascaloot
	release
	end

EventScript_SummitCave_GiveItemDependingOnStarterBattleLost:
	lock
	msgbox Text_SummitCave_BobbyPostBattleLost, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, SummitCave_EventScript_GiveItemRascaloot //fros starter is rascaloot
	case 1, SummitCave_EventScript_GiveItemFlobra //fros starter is Flobra
	case 2, SummitCave_EventScript_GiveItemEmboryps //fros starter is emboryps
	release
	end

EventScript_SummitCave_GiveItemDependingOnStarterBattleWon:
	lock
	msgbox Text_SummitCave_BobbyPostBattleWon, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, SummitCave_EventScript_GiveItemRascaloot //fros starter is rascaloot
	case 1, SummitCave_EventScript_GiveItemFlobra //fros starter is flobra
	case 2, SummitCave_EventScript_GiveItemEmboryps //fros starter is emboryps
	release
	end

	Script_SummitCave_WasulaBattleFlobra:
	trainerbattle_no_intro TRAINER_WASULA_SUMMIT_CAVE_FLOBRA, Text_SummitCave_BobbyDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EventScript_SummitCave_GiveItemDependingOnStarterBattleLost
	goto EventScript_SummitCave_GiveItemDependingOnStarterBattleWon
	end
		
	Script_SummitCave_WasulaBattleRascaloot:
	trainerbattle_no_intro TRAINER_WASULA_SUMMIT_CAVE_RASCALOOT, Text_SummitCave_BobbyDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EventScript_SummitCave_GiveItemDependingOnStarterBattleLost
	goto EventScript_SummitCave_GiveItemDependingOnStarterBattleWon
	end

	Script_SummitCave_WasulaBattleEmboryps:
	trainerbattle_no_intro TRAINER_WASULA_SUMMIT_CAVE_EMBORYPS, Text_SummitCave_BobbyDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EventScript_SummitCave_GiveItemDependingOnStarterBattleLost
	goto EventScript_SummitCave_GiveItemDependingOnStarterBattleWon
	end
	
	
	


SummitCave_EventScript_GiveItemRascaloot:
	msgbox Text_SummitCave_BobbyGivesMint, MSGBOX_DEFAULT
	giveitem ITEM_RELAXED_MINT, 1
	msgbox Text_SummitCave_BobbyLeavesSummitCave
	applymovement LOCALID_BOBBY Movement_SummitCaveBobbyLeavesSummitCave
	waitmovement LOCALID_BOBBY
	removeobject LOCALID_BOBBY
	setflag FLAG_ITEM_SUMMIT_CAVE_MINT 
	setvar VAR_OLDALE_TOWN_STATE, 8
	release
	end

SummitCave_EventScript_GiveItemFlobra:
	msgbox Text_SummitCave_BobbyGivesMint, MSGBOX_DEFAULT
	giveitem ITEM_BRAVE_MINT, 1
	msgbox Text_SummitCave_BobbyLeavesSummitCave
	applymovement LOCALID_BOBBY Movement_SummitCaveBobbyLeavesSummitCave
	waitmovement LOCALID_BOBBY
	removeobject LOCALID_BOBBY
	setflag FLAG_ITEM_SUMMIT_CAVE_MINT 
	setvar VAR_OLDALE_TOWN_STATE, 8
	release
	end

SummitCave_EventScript_GiveItemEmboryps:
	msgbox Text_SummitCave_BobbyGivesMint, MSGBOX_DEFAULT
	giveitem ITEM_MODEST_MINT, 1
	msgbox Text_SummitCave_BobbyLeavesSummitCave
	applymovement LOCALID_BOBBY Movement_SummitCaveBobbyLeavesSummitCave
	waitmovement LOCALID_BOBBY
	removeobject LOCALID_BOBBY
	setflag FLAG_ITEM_SUMMIT_CAVE_MINT 
	setvar VAR_OLDALE_TOWN_STATE, 8
	release
	end

////////////////////////////////
//////////MOVEMENTS////////////
///////////////////////////////

Movement_SummitCave_BobbyApproachesFroTrigger1:
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
step_end

Movement_SummitCave_BobbyApproachesFroTrigger2:
walk_fastest_down
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
step_end

Movement_SummitCaveBobbyLeavesSummitCave:
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
walk_fastest_left
step_end

///////////////////TEXT/////////////////////
///////////////////////////////////////////

Text_SummitCave_BobbyPostBattleLost:
	.string "You gave it a good shot. I think you\n"
	.string "train a little harder if you want a\l"
	.string "shot at beating Chad and Mark.$"

Text_SummitCave_BobbyPostBattleWon:
	.string "Woah, you're learning fast. I can't\n"
	.string "believe I got bested by a novice!\p"
	.string "You should go battle Chad and Mark.$"

Text_SummitCave_HaventMadeItToSummitCityYet:
	.string "Hey Fro. How is the badge collecting\n"
	.string "coming along?\p"
	.string "You haven't made it to Summit City \nyet?\p"
	.string "Chad and Mark are the Gym Leaders\n"
	.string "of the Summit City Gym.\p"
	.string "I just beat them pretty easily and\n"
	.string "got a badge from them. You should\l"
	.string "head north through this cave, find\l"
	.string "Summit City and challenge them aswell\p"
	.string "But before that, how about a quick\n"
	.string "battle with me?$"

Text_SummitCave_BobbyGivesMint:
	.string "Oh and before you do, take this!$"

Text_SummitCave_BobbyLeavesSummitCave:
	.string "That is a rare mint that changes\n"
	.string "A Pokémon's nature.\p"
	.string "That one I found wasn't ideal for\n"
	.string "any of my Pokémon, but it looks like\l"
	.string "it would really help your starter\l"
	.string "Pokémon.\p"
	.string "Anyway, I'm going to get going to get\n"
	.string "some more badges so I can challenge\l"
	.string "the Elite Four and become champion!\p"
	.string "Try to keep up Fro, smell ya later!$"

Text_SummitCave_BobbyDefeated:
	.string "Damn U won$"
