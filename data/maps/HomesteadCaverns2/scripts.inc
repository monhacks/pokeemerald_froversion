HomesteadCaverns2_MapScripts::
	.byte 0

KylaTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_Kyla
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
	end

IceCave_EventScript_Kyla::
	trainerbattle_single TRAINER_DIANA_2, IceCave_Text_KylaIntro, IceCave_Text_KylaDefeated, IceCave_EventScript_KylaGivesSnowflake
	msgbox IceCave_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

IceCave_EventScript_KylaGivesSnowflake:
	msgbox IceCave_Text_KylaGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	release
	end

IceCave_Text_KylaIntro:
	.string "I was the Champion before!$"

IceCave_Text_KylaDefeated:
 	.string "You have a real shot at winning \nthe Challenge!$"

IceCave_Text_KylaGivesSnowflake:
	.string "Take this future Champ.$"

IceCave_Text_KylaPostBattle:
	.string "Keep up the good work.$"

DouglasTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_Douglas
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
	end

IceCave_EventScript_Douglas::
	trainerbattle_single TRAINER_JENNY_3, IceCave_Text_DouglasIntro, IceCave_Text_DouglasDefeated, IceCave_EventScript_DouglasGivesSnowflake
	msgbox IceCave_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

IceCave_EventScript_DouglasGivesSnowflake:
	msgbox IceCave_Text_DouglasGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	release
	end

IceCave_Text_DouglasIntro:
	.string "I love hiking in caves.$"

IceCave_Text_DouglasDefeated:
 	.string "I think you would make a fine Hiker!$"

IceCave_Text_DouglasGivesSnowflake:
	.string "Your hike will be easier with this!$"

IceCave_Text_DouglasPostBattle:
	.string "We can hike together if you'd like.$"
