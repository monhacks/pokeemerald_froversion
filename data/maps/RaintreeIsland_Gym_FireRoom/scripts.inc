RaintreeIsland_Gym_FireRoom_MapScripts::
	.byte 0

///////////////////////////////////////
///////////////Scripts/////////////////
//////////////////////////////////////

EventScript_RaintreeIsland_FireRoom_GymTrainer1::
	lock
	msgbox Text_RaintreeIsland_GymTrainer1Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 12, 26
	release
	end

EventScript_RaintreeIsland_FireRoom_GymTrainer3::
	lock
	msgbox Text_RaintreeIsland_GymTrainer3Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 12, 12
	release
	end

EventScript_RaintreeIsland_FireRoom_GymTrainer5::
	lock
	msgbox Text_RaintreeIsland_GymTrainer5Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 17, 7
	release
	end


///////////////////////////////////////
///////////////Texts///////////////////
//////////////////////////////////////

Text_RaintreeIsland_GymTrainer1Defeated:
	.string "Defeated text change room!$"

Text_RaintreeIsland_GymTrainer3Defeated:
	.string "Defeated text change room!$"

Text_RaintreeIsland_GymTrainer5Defeated:
	.string "Defeated text change room!$"
