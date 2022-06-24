CinnibarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CinnabarIsland_OnFrame
	.byte 0

CinnabarIsland_OnFrame: @ 8238C4F
	map_script_2 VAR_ROUTE101_STATE, 0, CinnabarIsland_NewGameEvents
	.2byte 0

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIsland_NewGameEvents::
	lock
		giveitem ITEM_NCC_PACKAGE, 1
				givecustommon SPECIES_VAPOREON, 50, ITEM_LEFTOVERS, ITEM_DIVE_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_SURF, MOVE_WISH, MOVE_PROTECT, MOVE_HEAL_BELL, 0
                givecustommon SPECIES_MACHAMP, 50, ITEM_NONE, ITEM_ULTRA_BALL, NATURE_JOLLY, 1, 0, 100, 4, 100, 0, 0, 16, 16, 16, 16, 16, 16, MOVE_CROSS_CHOP, MOVE_BULK_UP, MOVE_BULLET_PUNCH, MOVE_KNOCK_OFF, 0
                givecustommon SPECIES_HOUNDOOM, 50, ITEM_SITRUS_BERRY, ITEM_DUSK_BALL, NATURE_TIMID, 1, 56, 0, 0, 88, 100, 12, 16, 16, 16, 16, 16, 16, MOVE_CRUNCH, MOVE_NASTY_PLOT, MOVE_FLAMETHROWER, MOVE_TOXIC, 0
		setvar VAR_ROUTE101_STATE, 1
		release
	end


CinnabarIsland_EventScript_ManUnloadingShip::
	msgbox CinnabarIsland_Text_ManUnloadingShip, MSGBOX_NPC
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

CinnabarIsland_EventScript_Guy::
	msgbox CinnabarIsland_Text_Guy, MSGBOX_NPC
	end

CinnabarIsland_EventScript_VolcanoGuy::
	msgbox CinnabarIsland_Text_VolcanoGuy, MSGBOX_NPC
	end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

CinnabarIsland_Text_ManUnloadingShip:
	.string "No time for talking!\n"
	.string "I need to unload those boxes!$"

CinnabarIsland_Text_ManNextToBoxes1:
	.string "Those stupid boxes with their\n"
	.string "stupid corners and stupid brown color\p"
	.string "...$"

CinnabarIsland_Text_ManNextToBoxes2:
	.string "Oh hello, as you can see i am working. As\n"
	.string "I love my job and those boxes you don't\p"
	.string "need to tell anyone anything you might\n"
	.string "have heard.$"

CinnabarIsland_Text_Sailor:
	.string "I still can't believe my old captain\n"
	.string "got seasick on a regular basis.\p"
	.string "I suppose you're off to tell them their\n"
	.string "delivery arrived?$"

CinnabarIsland_Text_Guy:
	.string "I came here for the Gym all the way from\n"
	.string "Plaglaci Town. Do you know where this\p"
	.string "is? No? Well no wonder, there is no\n"
	.string "dock where you could land with your ship.$"

CinnabarIsland_Text_Scientist:
	.string "I am glad I have the brains. If I lift\n"
	.string "one of those crates I would hurt myself.\p"
	.string "Also it's quite entertaining to mess\n"
	.string "with those smooth brains.$"

CinnabarIsland_Text_Fisherman:
	.string "Ahoy! That's what you guys say, isn't\n"
	.string "it? Being on the wild untamed sea all\p"
	.string "the time sounds like a dream to me.\n"
	.string "All day fishing at the best spots.$"
	
CinnabarIsland_Text_ManMovingBoxes:
	.string "Do you want to help me or just distract\n"
	.string "me? Those boxes don't move themselves.\p"
	.string "Please move aside and let me finish my\n"
	.string "work!$"

CinnabarIsland_Text_VolcanoGuy:
	.string "This volcano isn't safe for the\n"
	.string "Public. Please head back towards\l"
	.string "southern end of the Island.$"
@--------------------------------------------------------------------------------
@-----------------------------------Movement-------------------------------------
@--------------------------------------------------------------------------------

