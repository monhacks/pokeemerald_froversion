CinnabarIslandNCC_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIslandNCC_OnLoad
	.byte 0

CinnabarIslandNCC_OnLoad:
	compare VAR_ROUTE101_STATE, 3
	call_if_ge CinnabarIslandNCC_EventScript_SetDynamicWarpPostSleep
	call_if_lt CinnabarIslandNCC_EventScript_SetDynamicWarpPreSleep
	end

CinnabarIslandNCC_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 52, 44
end

CinnabarIslandNCC_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 52, 44
end


@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIslandNCC_NotAllowedUpstairs::
	msgbox CinnabarIslandNCC_Text_NotAllowedUpstairs
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

CinnabarIslandNCC_EventScript_ElevatorUp::
playse SE_TRUCK_MOVE
	setmetatile 22, 15, ElevatorFloorFence, 0
	setmetatile 23, 15, ElevatorFloorFence, 0
	setmetatile 24, 15, ElevatorFloorFence, 0

	setmetatile 22, 16, ElevatorFloorBeam, 1
	setmetatile 23, 16, ElevatorFloorBeam, 1
	setmetatile 24, 16, ElevatorFloorBeam, 1

	setmetatile 22, 17, ElevatorFloor, 1
	setmetatile 23, 17, ElevatorFloor, 1
	setmetatile 24, 17, ElevatorFloor, 1

	setmetatile 22, 18, ElevatorFloor, 1
	setmetatile 23, 18, ElevatorFloor, 1
	setmetatile 24, 18, ElevatorFloor, 1	
	
	setmetatile 22, 19, TiledFloor, 1
	setmetatile 23, 19, TiledFloor, 1
	setmetatile 24, 19, TiledFloor, 1
	special DrawWholeMapView
end

CinnabarIslandNCC_EventScript_ElevatorDown::
playse SE_TRUCK_MOVE
	setmetatile 22, 15, 0x01B, 0
	setmetatile 23, 15, 0x01B, 0
	setmetatile 24, 15, 0x01B, 0

	setmetatile 22, 16, 0x01C, 1
	setmetatile 23, 16, 0x01C, 1
	setmetatile 24, 16, 0x01C, 1

	setmetatile 22, 17, 0x012, 1
	setmetatile 23, 17, 0x012, 1
	setmetatile 24, 17, 0x012, 1

	setmetatile 22, 18, ElevatorBarrier, 1
	setmetatile 23, 18, ElevatorBarrier, 1
	setmetatile 24, 18, ElevatorBarrier, 1	
	
	setmetatile 22, 19, 0x014, 1
	setmetatile 23, 19, 0x014, 1
	setmetatile 24, 19, 0x014, 1
	special DrawWholeMapView
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------


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
	.string "that not only benefit our home Island,\l"
	.string "but all people and Pokémon alike.$"

CinnabarIslandNCC_Text_EnjoyYourStay:
	.string "Oh my, you look very tired.\n"
	.string "I think I've taken enough of your\l"
	.string "time.\p"
	.string "Are you sailing again or staying the\n"
	.string "night?\p"
	.string "Oh you're staying the night! How\n"
	.string "Wonderful!$" 

CinnabarIslandNCC_Text_IllLetYouGetSettled:	
	.string "I'll let you go get settled\n"
	.string "into your room then!$"

CinnabarIslandNCC_Text_NotAllowedUpstairs:
	.string "It says 'Employees only!'$"	