.set LOCALID_FREDERIC, 2
.set LOCALID_FREDERIC2, 6

WesternApproachOpenLand2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WesternApproachSandstormCheck_OnTransition
	.byte 0

WesternApproachOpenLand2_EventScript_FindFredericSupplies::
	finditem ITEM_FREDERIC_SUPPLIES_4
	addvar VAR_FREDERIC_STATE, 1
end


WesternApproachOpenLand2_EventScript_FredericQuestAssignment::
	goto_if_unset FLAG_OPENED_BLACKROOM_DOOR_1, WesternApproachOpenLand2_EventScript_FredericIntro
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
	msgbox WesternApproachOpenLand2_Text_FredericIntro, MSGBOX_NPC
	setflag FLAG_OPENED_BLACKROOM_DOOR_1
goto WesternApproachOpenLand2_EventScript_FredericQuestAssignment

WesternApproachOpenLand2_EventScript_FredericNeedSupplies:
	msgbox WesternApproachOpenLand2_Text_FredericNeedSupplies, MSGBOX_NPC
	release
end

WesternApproachOpenLand2_EventScript_FredericRemoveTraps:
	removeitem ITEM_FREDERIC_SUPPLIES_1
	removeitem ITEM_FREDERIC_SUPPLIES_2
	removeitem ITEM_FREDERIC_SUPPLIES_3
	removeitem ITEM_FREDERIC_SUPPLIES_4
	removeitem ITEM_FREDERIC_SUPPLIES_5
	msgbox WesternApproachOpenLand2_Text_FredericRemoveTraps, MSGBOX_NPC
	release
end

WesternApproachOpenLand2_EventScript_FredericFindManuscript:
	removeitem ITEM_TRAP
	hideobjectat 2, MAP_WESTERN_APPROACH_LOST_SPRING_CANYON_TRAIL1
	hideobjectat 3, MAP_WESTERN_APPROACH_LOST_SPRING_CANYON_TRAIL1
	setflag FLAG_ITEM_ROUTE_120_REVIVE
	setflag FLAG_ITEM_ROUTE_119_ELIXIR_2
	msgbox WesternApproachOpenLand2_Text_FredericFindManuscript, MSGBOX_NPC
	release
end

WesternApproachOpenLand2_EventScript_FredericSetBait:
	clearflag FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY
	showobjectat 5, MAP_WESTERN_APPROACH_OPEN_LAND2
	msgbox WesternApproachOpenLand2_Text_FredericFourthQuest, MSGBOX_NPC
	release
end

WesternApproachOpenLand2_EventScript_FredericGoesToFindDragon:
	msgbox WesternApproachOpenLand2_Text_FredericGoesToFindDragon, MSGBOX_NPC
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
	.string "Hello my name is Frederic.\p"
	.string "I study Pokémon, and the unusual\n"
	.string "activity in the area has lead me\l"
	.string "here.\p"
	.string "I believe a Dragon-Type Pokémon is\n"
	.string "responsible for the disruption to\l"
	.string "the habitat.\p"
	.string "From what I can tell it is upset\n"
	.string "and territorial, punishing any\l"
	.string "Pokémon that is living in it's home\p"
	.string "I would really like to capture this Pokémon\n"
	.string "to restore natural order and protect\l"
	.string "the innocent Pokémon here.\p"
	.string "Unfortunately the Dragon-Type Pokémon\n"
	.string "doesn't seem like it wants to be\l"
	.string "seen.\p"
	.string "I think we need to lure it out, but\n"
	.string "I've dropped my supplies while\l"
	.string "researching in various areas of\l"
	.string "the Western Approach.$"

WesternApproachOpenLand2_Text_FredericNeedSupplies:
	.string "I'll need those supplies if I'm\n"
	.string "going to be able to lure the\l"
	.string "Dragon.$"


WesternApproachOpenLand2_Text_FredericRemoveTraps:
	.string "Now that you've found my supplies\n"
	.string "I noticed some other hunters have\l"
	.string "placed traps to try and lure the\l"
	.string "Dragon themselves.\p"
	.string "The problem is these traps are not\n"
	.string "made correctly.\p"
	.string "If we want to lure the dragon we will\n"
	.string "need to disarm those traps.$"

WesternApproachOpenLand2_Text_FredericFindManuscript:
	.string "Excellent, you've disamred all the\n"
	.string "traps.\p"
	.string "Now we need to make our own traps.\p"
	.string "The issue is I seem to have dropped\n"
	.string "my Manuscript which details how to\l"
	.string "lure Dragon-Type Pokémon...\p"
	.string "I think the last time I saw it was\n"
	.string "when I was running out of a\l"
	.string "collapsing cave!$"

WesternApproachOpenLand2_Text_FredericFourthQuest:
	.string "Oh you found the Manuscript!\p"
	.string "Great, so I'll get everything ready\n"
	.string "for the trap to the south.\p"
	.string "All I need you to do is go set the bait!$"

WesternApproachOpenLand2_Text_FredericGoesToFindDragon:
	.string "You set the bait?\p"
	.string "Great! I'm going to go see if it\n"
	.string "worked.\p"
	.string "You've been a great help. I no\n"
	.string "longer need your assistance.\p"
	.string "Please do not follow me, I will\n"
	.string "handle it from here.$"

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
	