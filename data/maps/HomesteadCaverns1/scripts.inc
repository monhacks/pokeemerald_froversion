HomesteadCaverns1_MapScripts::
	.byte 0


MikeTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_MikeTrainerBattle
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
	end

IceCave_EventScript_MikeTrainerBattle:
	trainerbattle_single TRAINER_JENNY_2, IceCave_Text_MikeIntro, IceCave_Text_MikeDefeated, IceCave_EventScript_MikeGivesSnowflake
	msgbox IceCave_Text_MikePostBattle, MSGBOX_DEFAULT
	release
	end

IceCave_EventScript_MikeGivesSnowflake:
	msgbox IceCave_Text_MikeGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	release
	end

IceCave_Text_MikeIntro:
	 .string "It's so snowy in here.$"

IceCave_Text_MikeDefeated:
	.string "Ah, man! I lost!$"

IceCave_Text_MikeGivesSnowflake:
 .string "Here's my Snowflake."

IceCave_Text_MikePostBattle:
	.string "Good luck with the \nrest of the challenge.$"

JoeyTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_JoeyTrainerBattle
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
	end

IceCave_EventScript_JoeyTrainerBattle:
	trainerbattle_single TRAINER_ROSE_5, IceCave_Text_JoeyIntro, IceCave_Text_JoeyDefeated, IceCave_EventScript_JoeyGivesSnowflake
	msgbox IceCave_Text_JoeyPostBattle, MSGBOX_DEFAULT
	release
	end

IceCave_EventScript_JoeyGivesSnowflake:
	msgbox IceCave_Text_JoeyGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	release
	end

IceCave_Text_JoeyIntro:
	 .string "Let's see if you can beat my Pokemon!$"

IceCave_Text_JoeyDefeated:
	.string "Aw shucks, you beat me.$"

IceCave_Text_JoeyGivesSnowflake:
 .string "Here's my Snowflake."

IceCave_Text_JoeyPostBattle:
	.string "Good luck with the \nrest of the trainers.$"