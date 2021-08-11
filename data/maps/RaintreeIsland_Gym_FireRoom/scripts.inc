RaintreeIsland_Gym_FireRoom_MapScripts::
	.byte 0

///////////////////////////////////////
///////////////Scripts/////////////////
//////////////////////////////////////

EventScript_RaintreeIsland_FireRoom_GymTrainer1::
	trainerbattle_single TRAINER_LAURA, RaintreeIsland_FireRoom_Text_GymTrainer1Intro, RaintreeIsland_FireRoom_Text_GymTrainer1Defeat, EventScript_RaintreeIsland_FireRoom_GymTrainer1PostBattle
	msgbox Text_RaintreeIsland_GymTrainer1Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 12, 26
	release
	end

EventScript_RaintreeIsland_FireRoom_GymTrainer1PostBattle:
	msgbox Text_RaintreeIsland_GymTrainer1Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 12, 26
	release
	end

EventScript_RaintreeIsland_FireRoom_GymTrainer3::
	trainerbattle_single TRAINER_BRENDEN, RaintreeIsland_FireRoom_Text_GymTrainer3Intro, RaintreeIsland_FireRoom_Text_GymTrainer3Defeat, EventScript_RaintreeIsland_FireRoom_GymTrainer3PostBattle
	msgbox Text_RaintreeIsland_GymTrainer3Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 12, 12
	release
	end

EventScript_RaintreeIsland_FireRoom_GymTrainer3PostBattle:
	msgbox Text_RaintreeIsland_GymTrainer3Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 12, 12
	release
	end

EventScript_RaintreeIsland_FireRoom_GymTrainer5::
	trainerbattle_single TRAINER_JOCELYN, RaintreeIsland_FireRoom_Text_GymTrainer5Intro, RaintreeIsland_FireRoom_Text_GymTrainer5Defeat, EventScript_RaintreeIsland_FireRoom_GymTrainer5PostBattle
	msgbox Text_RaintreeIsland_GymTrainer5Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 17, 7
	release
	end

EventScript_RaintreeIsland_FireRoom_GymTrainer5PostBattle:
	msgbox Text_RaintreeIsland_GymTrainer5Defeated, MSGBOX_DEFAULT
	warpsilent MAP_RAINTREE_ISLAND_GYM, 255, 17, 7
	release
	end


///////////////////////////////////////
///////////////Texts///////////////////
//////////////////////////////////////


RaintreeIsland_FireRoom_Text_GymTrainer1Intro:
	.string "It's pretty hot in here!\p"
	.string "Why don't we cool it down?$"

RaintreeIsland_FireRoom_Text_GymTrainer1Defeat:
	.string "Woah, you're too cool for me.$"

RaintreeIsland_FireRoom_Text_GymTrainer3Intro:
	.string "I can't stand the heat!\p"
	.string "Wouldn't you agree, Ice is way\n"
	.string "cooler than fire?$"

RaintreeIsland_FireRoom_Text_GymTrainer3Defeat:
	.string "I would have battled better if\n"
	.string "I wasn't in this uncomfortable\l"
	.string "heat!$"

RaintreeIsland_FireRoom_Text_GymTrainer5Intro:
	.string "You've made it pretty far!\p"
	.string "But I will test your strength\n"
	.string "to see if you're worthy of\l"
	.string "facing the leader.$"

RaintreeIsland_FireRoom_Text_GymTrainer5Defeat:
	.string "It seems you are more than worthy.$"

Text_RaintreeIsland_GymTrainer1Defeated:
	.string "Want to see something even\n"
	.string "cooler than our battle?$"

Text_RaintreeIsland_GymTrainer3Defeated:
	.string "This heat is so uncomfortable!$"

Text_RaintreeIsland_GymTrainer5Defeated:
	.string "Good luck with the leader.\p"
	.string "He's much stronger than I.$"
