.set LOCALID_FREDERIC, 2
.set LOCALID_FREDERIC2, 6

WesternApproachOpenLand2_MapScripts::
	.byte 0

WesternApproachOpenLand2_EventScript_FindFredericSupplies::
	finditem ITEM_FREDERIC_SUPPLIES_4
	addvar VAR_FREDERIC_STATE, 1
end


WesternApproachOpenLand2_EventScript_FredericQuestAssignment::
	goto_if_unset FLAG_STARTED_FREDERIC_QUEST, WesternApproachOpenLand2_EventScript_FredericIntro
	compare VAR_FREDERIC_STATE, 4
	goto_if_le WesternApproachOpenLand2_EventScript_FredericNeedSupplies
	compare VAR_FREDERIC_STATE, 14
	goto_if_le WesternApproachOpenLand2_EventScript_FredericRemoveTraps
	compare VAR_FREDERIC_STATE, 15
	goto_if_le WesternApproachOpenLand2_EventScript_FredericFindManuscript
	compare VAR_FREDERIC_STATE, 16
	goto_if_le WesternApproachOpenLand2_EventScript_FredericSetBait
	goto_if_gt WesternApproachOpenLand2_EventScript_FredericGoesToFindDragon
end

WesternApproachOpenLand2_EventScript_FredericIntro:
	msgbox WesternApproachOpenLand2_Text_FredericIntro, MSGBOX_DEFAULT
	setflag FLAG_STARTED_FREDERIC_QUEST
goto WesternApproachOpenLand2_EventScript_FredericQuestAssignment

WesternApproachOpenLand2_EventScript_FredericNeedSupplies:
	msgbox WesternApproachOpenLand2_Text_FredericNeedSupplies, MSGBOX_DEFAULT
	release
end

WesternApproachOpenLand2_EventScript_FredericRemoveTraps:
	removeitem ITEM_FREDERIC_SUPPLIES_1
	removeitem ITEM_FREDERIC_SUPPLIES_2
	removeitem ITEM_FREDERIC_SUPPLIES_3
	removeitem ITEM_FREDERIC_SUPPLIES_4
	removeitem ITEM_FREDERIC_SUPPLIES_5
	msgbox WesternApproachOpenLand2_Text_FredericRemoveTraps, MSGBOX_DEFAULT
	release
end

WesternApproachOpenLand2_EventScript_FredericFindManuscript:
	removeitem ITEM_TRAP
	hideobjectat 2, MAP_WESTERN_APPROACH_LOST_SPRING_CANYON_TRAIL1
	hideobjectat 3, MAP_WESTERN_APPROACH_LOST_SPRING_CANYON_TRAIL1
	setflag FLAG_ITEM_ROUTE_120_REVIVE
	setflag FLAG_ITEM_ROUTE_119_ELIXIR_2
	msgbox WesternApproachOpenLand2_Text_FredericFindManuscript, MSGBOX_DEFAULT
	release
end

WesternApproachOpenLand2_EventScript_FredericSetBait:
	clearflag FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY
	showobjectat 5, MAP_WESTERN_APPROACH_OPEN_LAND2
	msgbox WesternApproachOpenLand2_Text_FredericFourthQuest, MSGBOX_DEFAULT
	release
end

WesternApproachOpenLand2_EventScript_FredericGoesToFindDragon:
	msgbox WesternApproachOpenLand2_Text_FredericGoesToFindDragon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FREDERIC
	setflag FLAG_HIDE_FREDERIC
	clearflag FLAG_HIDE_FREDERIC_2
	fadescreen FADE_FROM_BLACK
	release
end

WesternApproachOpenLand2_EventScript_BaitBox::
	compare VAR_FREDERIC_STATE, 16
	goto_if_gt WesternApproachOpenLand2_EventScript_BaitBox2
	msgbox WesternApproachOpenLand2_Text_BaitHasBeenSet, MSGBOX_DEFAULT
	addvar VAR_FREDERIC_STATE, 1
	release
end

WesternApproachOpenLand2_EventScript_BaitBox2:
	msgbox WesternApproachOpenLand2_Text_BaitHasAlreadyBeenSet, MSGBOX_DEFAULT
	release
end

WesternApproachOpenLand2_EventScript_FredericBattle::
	trainerbattle_double TRAINER_WINSTON_5, WesternApproachOpenLand2_Text_FredericBattleIntro, WesternApproachOpenLand2_Text_FredericBattleDefeat, WesternApproachOpenLand2_Text_FredericNotEnoughMons, WesternApproachOpenLand2_EventScript_FredericPostBattleEvent

WesternApproachOpenLand2_EventScript_FredericPostBattleEvent:
	msgbox WesternApproachOpenLand2_Text_FredericPostBattle, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FREDERIC2
	setflag FLAG_HIDE_FREDERIC_2
	clearflag FLAG_HIDE_FLANNERY_WESTERN_APPROACH
	addobject 7
	faceplayer
	fadescreen FADE_FROM_BLACK
	msgbox WesternApproachOpenLand2_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_LAVARIDIGE_TOWN_MARRIOTT_LAYOUT
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear
	release
end



WesternApproachOpenLand2_Text_FredericIntro:
	.string "Hey this is my intro, Frederic.$"

WesternApproachOpenLand2_Text_FredericNeedSupplies:
	.string "Need Supplies.$"


WesternApproachOpenLand2_Text_FredericRemoveTraps:
	.string "Remove Traps.$"

WesternApproachOpenLand2_Text_FredericFindManuscript:
	.string "Find Manuscript.$"

WesternApproachOpenLand2_Text_FredericFourthQuest:
	.string "Set Bait.$"

WesternApproachOpenLand2_Text_FredericGoesToFindDragon:
	.string "I'm going to go see if the lures worked! Bye Bye!$"

WesternApproachOpenLand2_Text_BaitHasBeenSet:
	.string "You have set the bait.$"

WesternApproachOpenLand2_Text_BaitHasAlreadyBeenSet:
	.string "You have already set the bait...$"

WesternApproachOpenLand2_Text_FredericBattleIntro:
	.string "It appears the lure worked...\p"
	.string "I must thank you for all your help...\p"
	.string "I managed to capture not only the\n"
	.string "Pokémon that has been disrupting\l"
	.string "the area, but it's offspring as\l"
	.string "well...\p"
	.string "They are very powerful...\p"
	.string "I think it's only appropriate that\n"
	.string "I keep them locked away and conduct\l"
	.string "unethical experiments on them...\p"
	.string "You don't like that idea?\p"
	.string "Well I'd like to see you stop me!$"

WesternApproachOpenLand2_Text_FredericBattleDefeat:
	.string "Guess they aren't so powerful\n"
	.string "after all.\p"
	.string "They just got wallopped by a kid...$"

WesternApproachOpenLand2_Text_FredericNotEnoughMons:
	.string "You really want to challenge me\n"
	.string "with just one Pokémon?\p"
	.string "Haha don't make me laugh.\p"
	.string "I'll be here waiting for you.$"

WesternApproachOpenLand2_Text_FredericPostBattle:
	.string "Fine, if you care that much\n"
	.string "about Pokémon rights, then take them.\p"
	.string "I'll be seeing you around, PUNK!$"

WesternApproachOpenLand2_Text_FlanneryPostBattle:
	.string "I saw the way you handled\n"
	.string "yourself not only in battle but\l"
	.string "throughout your entire investigation\l"
	.string "here.\p"
	.string "You did a better job than I did, and\n"
	.string "I am happy to say watching you has\l"
	.string "given me the confidence to name\l"
	.string "you as my successor.\p"
	.string "Congratulations, you are now the\n"
	.string "Grand Island Gym leader!$"
	