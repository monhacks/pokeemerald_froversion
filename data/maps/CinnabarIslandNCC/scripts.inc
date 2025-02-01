CinnabarIslandNCC_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIslandNCC_OnLoad
	.byte 0

CinnabarIslandNCC_OnLoad:
	goto_if_defeated TRAINER_SUMMIT_CAVERNS_LATTKA_2, CinnabarIslandWarehouse_EventScript_SetDynamicWarpPreSleep
	compare VAR_ROUTE101_STATE, 3
	call_if_ge CinnabarIslandNCC_EventScript_SetDynamicWarpPostSleep
	call_if_lt CinnabarIslandNCC_EventScript_SetDynamicWarpPreSleep
	end

CinnabarIslandNCC_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 52, 44
end

CinnabarIslandNCC_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 52, 44
	compare VAR_ROUTE101_STATE, 6
	goto_if_eq CinnabarIslandNCC_EventScript_LeaveElevator
end

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIslandNCC_Sailor1::
	msgbox CinnabarIslandNCC_Text_Coffee, MSGBOX_NPC
	closemessage
end

CinnabarIslandNCC_Sailor2::
	msgbox CinnabarIslandNCC_Text_NicePlace, MSGBOX_NPC
	closemessage
end

CinnabarIslandNCC_Sailor3::
	msgbox CinnabarIslandNCC_Text_ComfyCouch, MSGBOX_NPC
	closemessage
end

CinnabarIslandNCC_Sailor4::
	msgbox CinnabarIslandNCC_Text_CoolToSeeWork, MSGBOX_NPC
	closemessage
end

CinnabarIslandNCC_ScientistUpstairs::
	msgbox CinnabarIslandNCC_Text_NotOnlyCom, MSGBOX_NPC
	closemessage
end

CinnabarIslandNCC_Scientist1Chat::
	msgbox CinnabarIslandNCC_Text_chat1
	closemessage
end

CinnabarIslandNCC_Scientist2Chat::
	msgbox CinnabarIslandNCC_Text_chat2
	closemessage
end

CinnabarIslandNCC_ScientistElevator::
	msgbox CinnabarIslandNCC_Text_VolcanicActivity, MSGBOX_NPC
	closemessage
end

CinnabarIslandNCC_NotAllowedUpstairs::
	msgbox CinnabarIslandNCC_Text_NotAllowedUpstairs
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	closemessage
end

CinnabarIslandNCC_Receptionist::
	lockall
		faceplayer
		goto_if_set FLAG_GAVE_NCC_PACKAGE, CinnabarIslandNCC_Receptionist_IllLetYouGetSettled
		compare VAR_ROUTE101_STATE, 1
		goto_if_eq CinnabarIslandNCC_Receptionist_GivePackage
	releaseall
end


CinnabarIslandNCC_Receptionist_GivePackage:
		msgbox CinnabarIslandNCC_Text_ThankYouForDeliveringPackage, MSGBOX_DEFAULT
		removeitem ITEM_NCC_PACKAGE, 1
		setflag FLAG_GAVE_NCC_PACKAGE
		setflag FLAG_SYS_B_DASH
		msgbox CinnabarIslandNCC_Text_NCCExplaination, MSGBOX_DEFAULT
	goto CinnabarIslandNCC_Receptionist_EnjoyYourStay
	
	
CinnabarIslandNCC_Receptionist_EnjoyYourStay:
		msgbox CinnabarIslandNCC_Text_EnjoyYourStay, MSGBOX_DEFAULT
	goto CinnabarIslandNCC_Receptionist_IllLetYouGetSettled

CinnabarIslandNCC_Receptionist_IllLetYouGetSettled:
		msgbox CinnabarIslandNCC_Text_IllLetYouGetSettled, MSGBOX_DEFAULT
		closemessage
	releaseall
	end

CinnabarIslandNCC_EventScript_PC::
	msgbox CinnabarIslandNCC_Text_PC
	closemessage
end

CinnabarIslandNCC_EventScript_ElevatorCheckKey::
	goto_if_set FLAG_DEFEATED_REGISTEEL, CinnabarIslandNCC_EventScript_ElevatorUp
	msgbox CinnabarIslandNCC_Text_KeyNeeded, MSGBOX_NPC
end

CinnabarIslandNCC_EventScript_ElevatorUp::
	setvar VAR_ROUTE101_STATE, 5
	msgbox CinnabarIslandNCC_Text_KeyNeeded
	msgbox CinnabarIslandNCC_Text_InsertedKey
	closemessage
	playse SE_PC_LOGIN
	waitse
	playse SE_TRUCK_MOVE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	playse SE_TRUCK_STOP
	waitse
	setmetatile 22, 15, METATILE_Building_ElevatorFloorFence, 1
	setmetatile 23, 15, METATILE_Building_ElevatorFloorFence, 1
	setmetatile 24, 15, METATILE_Building_ElevatorFloorFence, 1

	setmetatile 22, 16, METATILE_Building_ElevatorFloorBeam, 0
	setmetatile 23, 16, METATILE_Building_ElevatorFloorBeam, 0
	setmetatile 24, 16, METATILE_Building_ElevatorFloorBeam, 0

	setmetatile 22, 17, METATILE_Facility_ElevatorFloor, 0
	setmetatile 23, 17, METATILE_Facility_ElevatorFloor, 0
	setmetatile 24, 17, METATILE_Facility_ElevatorFloor, 0

	setmetatile 22, 18, METATILE_Facility_ElevatorFloor, 0
	setmetatile 23, 18, METATILE_Facility_ElevatorFloor, 0
	setmetatile 24, 18, METATILE_Facility_ElevatorFloor, 0	
	
	setmetatile 22, 19, METATILE_Facility_TiledFloor, 0
	setmetatile 23, 19, METATILE_Facility_TiledFloor, 0
	setmetatile 24, 19, METATILE_Facility_TiledFloor, 0
	special DrawWholeMapView
end

CinnabarIslandNCC_EventScript_ElevatorDown::
playse SE_TRUCK_MOVE
	setmetatile 22, 15, 0x01B, 1
	setmetatile 23, 15, 0x01B, 1
	setmetatile 24, 15, 0x01B, 1

	setmetatile 22, 16, 0x01C, 1
	setmetatile 23, 16, 0x01C, 1
	setmetatile 24, 16, 0x01C, 1

	setmetatile 22, 17, 0x012, 1
	setmetatile 23, 17, 0x012, 1
	setmetatile 24, 17, 0x012, 1

	setmetatile 22, 18, METATILE_Building_ElevatorBarrier, 1
	setmetatile 23, 18, METATILE_Building_ElevatorBarrier, 1
	setmetatile 24, 18, METATILE_Building_ElevatorBarrier, 1	
	
	setmetatile 22, 19, 0x014, 0
	setmetatile 23, 19, 0x014, 0
	setmetatile 24, 19, 0x014, 0
	special DrawWholeMapView
	playse SE_TRUCK_STOP	
end

CinnabarIslandNCC_TakeElevatorLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	goto CinnabarIslandNCC_TakeElevator

CinnabarIslandNCC_TakeElevatorRight::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	goto CinnabarIslandNCC_TakeElevator

CinnabarIslandNCC_TakeElevator::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	warpsilent MAP_NCC_ELEVATOR, 255, 4, 3
end

CinnabarIslandNCC_EventScript_LeaveElevator::
	setmetatile 22, 15, METATILE_Building_ElevatorFloorFence, 1
	setmetatile 23, 15, METATILE_Building_ElevatorFloorFence, 1
	setmetatile 24, 15, METATILE_Building_ElevatorFloorFence, 1

	setmetatile 22, 16, METATILE_Building_ElevatorFloorBeam, 0
	setmetatile 23, 16, METATILE_Building_ElevatorFloorBeam, 0
	setmetatile 24, 16, METATILE_Building_ElevatorFloorBeam, 0

	setmetatile 22, 17, METATILE_Facility_ElevatorFloor, 0
	setmetatile 23, 17, METATILE_Facility_ElevatorFloor, 0
	setmetatile 24, 17, METATILE_Facility_ElevatorFloor, 0

	setmetatile 22, 18, METATILE_Facility_ElevatorFloor, 0
	setmetatile 23, 18, METATILE_Facility_ElevatorFloor, 0
	setmetatile 24, 18, METATILE_Facility_ElevatorFloor, 0	
	
	setmetatile 22, 19, METATILE_Facility_TiledFloor, 0
	setmetatile 23, 19, METATILE_Facility_TiledFloor, 0
	setmetatile 24, 19, METATILE_Facility_TiledFloor, 0

	playse SE_TRUCK_STOP
	waitse
	end

StepOutFromElevator::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_ROUTE101_STATE, 5
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

Text_FishedItem:
	.string "Oh!\p"
	.string "You caught a {STR_VAR_1}!$"

CinnabarIslandNCC_Text_ThankYouForDeliveringPackage:
	.string "Oh! Are those the parts we've been\n"
	.string "waiting for?\p"
	.string "Yes, that is them! Thank you so much\n"
	.string "for delivering them. They will help\l"
	.string "tremendously with our newest project!$"

CinnabarIslandNCC_Text_NCCExplaination:
	.string "The Nautic Communication Center, or\n"
	.string "NCC for short, is Cinnabar Island's\l"
	.string "leading employer.\p"
	.string "We do a wide range of things here\n"
	.string "that not only benefit our home island,\l"
	.string "but all people and Pokémon alike.$"

CinnabarIslandNCC_Text_EnjoyYourStay:
	.string "Oh my, you look very tired.\n"
	.string "I think I've taken enough of your\l"
	.string "time.\p"
	.string "Are you sailing again or staying the\n"
	.string "night?\p"
	.string "Oh you're staying the night! How\n"
	.string "wonderful!\p"
	.string "Before I let you go I want to\n"
	.string "thank you for your trouble.\l"
	.string "Please, take these Running Shoes!\p"
	.string "You can put them on by pressing\n"
	.string "The R Button!$" 

CinnabarIslandNCC_Text_IllLetYouGetSettled:	
	.string "I'll let you go get settled\n"
	.string "into your room then!$"

CinnabarIslandNCC_Text_NotAllowedUpstairs:
	.string "It says 'Employees only!'$"

CinnabarIslandNCC_Text_NicePlace:
	.string "I love coming to the NCC. The\n"
	.string "People here always have interesting\l"
	.string "stories to tell.$"

CinnabarIslandNCC_Text_NotOnlyCom:
	.string "Did you know the NCC is not\n"
	.string "limited to communication but\l"
	.string "also has a R&D department?$"

CinnabarIslandNCC_Text_Coffee:
	.string "I tell you, nothing beats the coffee\n"
	.string "from the inn here on the Island.$"

CinnabarIslandNCC_Text_ComfyCouch:
	.string "As much as i love the sea but\n"
	.string "sometimes i just like sitting down\l"
	.string "on a comfy couch and not move at all.$"

@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

CinnabarIslandNCC_Text_CoolToSeeWork:
	.string "Isn't it cool that you can watch\n"
	.string "all the important work being done\l"
	.string "from above here? I love watching\l"
	.string "others work.$"


CinnabarIslandNCC_Text_chat1:
	.string "We can not increase the pressure any\n"
	.string "further. The physical state of the\l"
	.string "Nitrogen would change. If you want to\l"
	.string "deal with a puddle of 77 Kelvin cold\l"
	.string "liquid go on.\p"
	.string "You better have frost burn heal!$"

CinnabarIslandNCC_Text_chat2:
	.string "You can't lower the pressure. If we\n"
	.string "don't cool it fast enough it will\l"
	.string "cause a lot of stress on all parts.\p"
	.string "This time you will tell them that we\n"
	.string "need replacement parts again.$"

CinnabarIslandNCC_Text_VolcanicActivity:
	.string "You would generally think it's a bad\n"
	.string "idea to build next to a volcano. But\l"
	.string "did you think about all the free\p"
	.string "geothermal energy and fertilizer? It's\n"
	.string "so convenient!$"

CinnabarIslandNCC_Text_KeyNeeded:
	.string "Looks like this terminal needs a key.$"

CinnabarIslandNCC_Text_InsertedKey:
	.string "You inserted the LIFT KEY$"

CinnabarIslandNCC_Text_PC:
	.string "I don't think i should touch that.$"
