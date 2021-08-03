RaintreeIsland_Gym_MapScripts::
	.byte 0

///////////////////////////////////////
///////////////Scripts/////////////////
//////////////////////////////////////

EventScript_RaintreeIsland_IceRoom_GymTrainer2::
	lock
	msgbox Text_RaintreeIsland_GymTrainer2Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM_FIRE_ROOM, 255, 7, 16
	release
	end

	EventScript_RaintreeIsland_IceRoom_GymTrainer4::
	lock
	msgbox Text_RaintreeIsland_GymTrainer4Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM_FIRE_ROOM, 255, 19, 31
	release
	end

///////////////////////////////////////
///////////////Texts///////////////////
//////////////////////////////////////

Text_RaintreeIsland_GymTrainer2Defeated:
	.string "Defeated text change room!$"

Text_RaintreeIsland_GymTrainer4Defeated:
	.string "Defeated text change room!$"
