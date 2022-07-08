CinnibarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CinnabarIsland_OnFrame
	.byte 0

CinnabarIsland_OnFrame: @ 8238C4F
	map_script_2 VAR_ROUTE101_STATE, 0, CinnabarIsland_NewGameEvents
	.2byte 0

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

FishRandomItem::
	random 101
	copyvar VAR_0x8004, VAR_RESULT
	addvar VAR_0x8004, 211
	bufferitemname 0, VAR_0x8004
	msgbox Text_FishedItem, MSGBOX_DEFAULT
	giveitem VAR_0x8004, 1
	closemessage
end

debug_RandomItem1:
	.string "Random {STR_VAR_1}$"
debug_RandomItem2:
	.string "0x8004 {STR_VAR_1}$"
debug_RandomItem3:
	.string "ItemID {STR_VAR_1}$"

CinnabarIsland_NewGameEvents::
	lock
		giveitem ITEM_NCC_PACKAGE, 1
				givecustommon SPECIES_VAPOREON, 50, ITEM_LEFTOVERS, ITEM_DIVE_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_SCALD, MOVE_WISH, MOVE_PROTECT, MOVE_HEAL_BELL, 0
                givecustommon SPECIES_MACHAMP, 50, ITEM_NONE, ITEM_ULTRA_BALL, NATURE_JOLLY, 1, 0, 100, 4, 100, 0, 0, 16, 16, 16, 16, 16, 16, MOVE_CROSS_CHOP, MOVE_BULK_UP, MOVE_BULLET_PUNCH, MOVE_KNOCK_OFF, 0
                givecustommon SPECIES_HOUNDOOM, 50, ITEM_SITRUS_BERRY, ITEM_DUSK_BALL, NATURE_TIMID, 1, 56, 0, 0, 88, 100, 12, 16, 16, 16, 16, 16, 16, MOVE_CRUNCH, MOVE_NASTY_PLOT, MOVE_FLAMETHROWER, MOVE_TOXIC, 0
		setvar VAR_ROUTE101_STATE, 1
		setflag FLAG_SYS_POKEMON_GET
		setflag FLAG_ITEM_FISHING
		clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
		setrespawn HEAL_LOCATION_CINNIBAR_ISLAND
	release
	end


CinnabarIsland_EventScript_ManUnloadingShip::
	msgbox CinnabarIsland_Text_ManUnloadingShip, MSGBOX_NPC
	end

CinnabarIsland_EventScript_GymClosedToday::
	lock
	msgbox CinnabarIsland_Text_GymClosedToday, MSGBOX_NPC
	release
end


CinnabarIsland_EventScript_ManNextToBoxes::
	msgbox CinnabarIsland_Text_ManNextToBoxes1, MSGBOX_DEFAULT
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_FacePlayer
	msgbox CinnabarIsland_Text_ManNextToBoxes2
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
end

CinnabarIsland_EventScript_ManMovingBoxes::
	msgbox CinnabarIsland_Text_ManMovingBoxes, MSGBOX_NPC
end

CinnabarIsland_EventScript_Sailor::
	msgbox CinnabarIsland_Text_Sailor, MSGBOX_NPC
end

CinnabarIsland_EventScript_Scientist::
	msgbox CinnabarIsland_Text_Scientist, MSGBOX_NPC
end

CinnabarIsland_EventScript_Fisherman::
	msgbox CinnabarIsland_Text_Fisherman, MSGBOX_NPC
end

CinnabarIsland_EventScript_PostFisherman::
	goto_if_set FLAG_HIDE_ROUTE_109_MR_BRINEY, CinnabarIsland_EventScript_PostFishermanCaughtSmth
	msgbox CinnabarIsland_Text_PostFisherman1, MSGBOX_NPC
	giveitem ITEM_OLD_ROD, 1
	msgbox CinnabarIsland_Text_PostFisherman2, MSGBOX_NPC
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
end

CinnabarIsland_EventScript_PostFishermanCaughtSmth::
	msgbox CinnabarIsland_Text_FishermanAlreadyCaughtSmth, MSGBOX_NPC
	checkitem ITEM_BLACK_GLASSES, 1
	compare VAR_RESULT, TRUE
	goto_if_eq Cinnabarisland_EventScript_PlayerHasGlasses
	msgbox CinnabarIsland_Text_FishermanNoGlasses, MSGBOX_NPC
end


Cinnabarisland_EventScript_PlayerHasGlasses::
	msgbox CinnabarIsland_Text_PostFishermanThanks, MSGBOX_NPC
	giveitem ITEM_TM32, 1
	msgbox CinnabarIsland_Text_PostFishermanRelaxedNow, MSGBOX_NPC
end

CinnabarIsland_EventScript_Guy::
	msgbox CinnabarIsland_Text_Guy, MSGBOX_NPC
end

CinnabarIsland_EventScript_VolcanoGuy::
	msgbox CinnabarIsland_Text_VolcanoGuy, MSGBOX_NPC
end

CinnabarIsland_EventScript_DoorIsLocked::
	msgbox CinnabarIsland_Text_DoorIsLocked, MSGBOX_NPC
end

CinnabarIsland_EventScript_NCCSign::
	msgbox CinnabarIsland_Text_NCC, MSGBOX_NPC
end

CinnabarIsland_EventScript_TownSign::
	msgbox CinnabarIsland_Text_TownSign, MSGBOX_NPC
end

Cinnabar_EventScript_GymSign::
	msgbox Cinnabar_Text_GymSign, MSGBOX_NPC
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

CinnabarIsland_Text_DoorIsLocked:
	.string "The door is locked from the inside.$"

CinnabarIsland_Text_NCC:
	.string "Nautical Communication Center\n"
	.string "We send waves through oceans and ethers$"

CinnabarIsland_Text_TownSign:
	.string "Cinnabar Island\n"
	.string "The place where land and ocean meets$"

Cinnabar_Text_GymSign:
	.string "Cinnabar Island gym$"

CinnabarIsland_Text_PostFishermanRelaxedNow:
	.string "But the actual reward is that you are\n"
	.string "much more relaxed now. Maybe I threw\l"
	.string "them in on purpose to get you to relax?\p"
	.string "Or maybe a Magikarp just bested me...$"	

CinnabarIsland_Text_PostFishermanThanks:
	.string "Oh! You found my glasses! Thank you\n"
	.string "so much! Here, take this.$"

CinnabarIsland_Text_FishermanAlreadyCaughtSmth:
	.string "Nice to see you again!\n"
	.string "Did you see my glasses?$"

CinnabarIsland_Text_FishermanNoGlasses:
	.string "No worries! I have a spare pair. So...\n"
	.string "where did I put them?$"

CinnabarIsland_Text_ManUnloadingShip:
	.string "No time for talking!\n"
	.string "I need to unload those boxes!$"

CinnabarIsland_Text_ManNextToBoxes1:
	.string "Those stupid boxes with their\n"
	.string "stupid corners and stupid brown color\p"
	.string "...$"

CinnabarIsland_Text_ManNextToBoxes2:
	.string "Oh hello, as you can see I am working. As\n"
	.string "I love my job and those boxes you don't\l"
	.string "need to tell anyone anything you might\l"
	.string "have heard.$"

CinnabarIsland_Text_Sailor:
	.string "I still can't believe my old captain\n"
	.string "got seasick on a regular basis.\p"
	.string "I suppose you're off to tell them their\n"
	.string "delivery arrived?$"

CinnabarIsland_Text_Guy:
	.string "I came here for the Gym all the way from\n"
	.string "Plaglaci Town. Do you know where this\l"
	.string "is? No? Well no wonder, there is no\l"
	.string "dock where you could land with your ship.$"

CinnabarIsland_Text_Scientist:
	.string "I am glad I have the brains. If I lift\n"
	.string "one of those crates I would hurt myself.\p"
	.string "Also it's quite entertaining to mess\l"
	.string "with those smooth brains.$"

CinnabarIsland_Text_Fisherman:
	.string "Ahoy! That's what you guys say, isn't\n"
	.string "it? Being on the wild untamed sea all\l"
	.string "the time sounds like a dream to me.\p"
	.string "All day fishing at the best spots.$"

CinnabarIsland_Text_PostFisherman1:
	.string "Hello again. Oh my Arceus, you look\n"
	.string "really stressed out! You know what\l"
	.string "always calms me down? Fishing! You\p"
	.string "should try it yourself. $"

CinnabarIsland_Text_PostFisherman2:
	.string "Oh by the way, if you happen to find\n"
	.string "my glasses please return them to me.$"
	
CinnabarIsland_Text_ManMovingBoxes:
	.string "Do you want to help me or just distract\n"
	.string "me? Those boxes don't move themselves.\p"
	.string "Please move aside and let me finish my\n"
	.string "work!$"

CinnabarIsland_Text_VolcanoGuy:
	.string "This volcano isn't safe for the public.\n"
	.string "Please head back towards southern end of\l"
	.string "the island.$"

CinnabarIsland_Text_GymClosedToday:
	.string "Sorry buster, the gym is closed today.\p"
	.string "Not like you stand a chance against\n"
	.string "Blaine anyway.\p"
	.string "He's hot like a volcano and cool as a\n"
	.string "cucumber.\p"
	.string "Come back tomorrow if you want to get\n"
	.string "handed a good old fasioned beat down.$"

@--------------------------------------------------------------------------------
@-----------------------------------Movement-------------------------------------
@--------------------------------------------------------------------------------

