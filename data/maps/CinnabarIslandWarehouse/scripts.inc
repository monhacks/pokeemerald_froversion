CinnabarIslandWarehouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIslandWarehouse_OnLoad
	.byte 0

CinnabarIslandWarehouse_OnLoad:
	compare VAR_ROUTE101_STATE, 3
	call_if_ge CinnabarIslandWarehouse_EventScript_SetDynamicWarpPostSleep
	call_if_lt CinnabarIslandWarehouse_EventScript_SetDynamicWarpPreSleep
end

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIslandWarehouse_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 64, 42
end

CinnabarIslandWarehouse_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 64, 42
end

CinnabarIslandWarehouse_EventScript_Worker1::
	msgbox CinnabarIslandWarehouse_Text_Worker1, MSGBOX_NPC
end

CinnabarIslandWarehouse_EventScript_Worker2::
	msgbox CinnabarIslandWarehouse_Text_Worker2, MSGBOX_NPC
end

CinnabarIslandWarehouse_EventScript_RedShardGuy::
	lock
	faceplayer
	msgbox CinnabarIslandWarehouse_Text_HaveAnyRedShards, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, CinnabarIslandWarehouse_EventScript_ThatsAShame
	case YES, CinnabarIslandWarehouse_EventScript_CheckRedShard
	case MULTI_B_PRESSED, CinnabarIslandWarehouse_EventScript_ThatsAShame
end

CinnabarIslandWarehouse_EventScript_ThatsAShame:
	msgbox  CinnabarIslandWarehouse_Text_ThatsAShame, MSGBOX_DEFAULT
	applymovement 6, Common_Movement_FaceOriginalDirection
	waitmovement 6
release
end

CinnabarIslandWarehouse_EventScript_CheckRedShard:
	checkitem ITEM_RED_SHARD, 50
	compare VAR_RESULT, FALSE
	goto_if_eq CinnabarIslandWarehouse_EventScript_NotEnoughShards
	msgbox CinnabarIslandWarehouse_Text_ThankYouSoMuch, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK, 1
	removeitem ITEM_RED_SHARD, 50
	release
end

CinnabarIslandWarehouse_EventScript_NotEnoughShards:
	msgbox CinnabarIslandWarehouse_Text_NotEnoughShards, MSGBOX_DEFAULT
	release
end

CinnabarIslandWarehouse_EventScript_Sengo::
	msgbox CinnabarIslandWarehouse_Text_Sengo, MSGBOX_NPC
end
@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]

CinnabarIslandWarehouse_Text_Worker1:
	.string "I swear to Arceus if one of those\n"
	.string "boxes lands on any part of my body\l"
	.string "I quit!\p"
	.string "They should supply us with\n"
	.string "way better equipment!$"

CinnabarIslandWarehouse_Text_Worker2:
	.string "Oops... I hope this label reading\n"
	.string "'fragile' was applied to the wrong box.\p"
	.string "Otherwise someone will have a bad day\n"
	.string "unboxing this.$"

CinnabarIslandWarehouse_Text_Sengo:
	.string "Zaaaan Zaaaangoooooooose!\n"
	.string "Zangoose!$"

CinnabarIslandWarehouse_Text_HaveAnyRedShards:
	.string "I'm collecting Red Shards! Do you\n"
	.string "happen to have any that I could have?$"

CinnabarIslandWarehouse_Text_ThatsAShame:
	.string "Well that's a shame. Let me know if\n"
	.string "you come across any.$"

CinnabarIslandWarehouse_Text_ThankYouSoMuch:
	.string "Woah, you have a ton of shards for\n"
	.string "me. Thanks so much!\p"
	.string "Please take this as a token of my\n"
	.string "appreciation!$"

CinnabarIslandWarehouse_Text_NotEnoughShards:
	.string "Thanks, but you don't have nearly\n"
	.string "enough shards!\p"
	.string "Please find more and come back again!$"

