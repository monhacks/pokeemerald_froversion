HomesteadCavernsMainRoom_MapScripts::
	.byte 0


CalvinTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_CalvinTrainerBattle
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
end

RickTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_Rick
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
end

TianaTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_Tiana
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
end

AllenTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_Allen
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
end

IvanTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_Ivan
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
end

BillyTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_Billy
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
end

ElliotTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_Elliot
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
end


IceCave_EventScript_CalvinTrainerBattle:
	trainerbattle_single TRAINER_ROSE_4, IceCave_Text_CalvinIntro, IceCave_Text_CalvinDefeated, IceCave_EventScript_CalvinGivesSnowflake
	msgbox IceCave_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
end

IceCave_EventScript_CalvinGivesSnowflake:
	msgbox IceCave_Text_CalvinGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	
	release
end

IceCave_Text_CalvinIntro:
	 .string "Let's see if you can beat my Pokemon!$"

IceCave_Text_CalvinDefeated:
	.string "Aw shucks, you beat me.$"

IceCave_Text_CalvinGivesSnowflake:
 .string "Here's my Snowflake."

IceCave_Text_CalvinPostBattle:
	.string "Good luck with the \nrest of the trainers.$"

IceCave_EventScript_Rick::
	trainerbattle_single TRAINER_DIANA_5, IceCave_Text_RickIntro, IceCave_Text_RickDefeated, IceCave_EventScript_RickGivesSnowflake
	msgbox IceCave_Text_RickPostBattle, MSGBOX_AUTOCLOSE
end

IceCave_EventScript_RickGivesSnowflake:
	msgbox IceCave_Text_RickGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	
	release
end

IceCave_EventScript_Tiana::
	trainerbattle_single TRAINER_DIANA_3, IceCave_Text_TianaIntro, IceCave_Text_TianaDefeated, IceCave_EventScript_TianaGivesSnowflake
	msgbox IceCave_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
end

IceCave_EventScript_TianaGivesSnowflake:
	msgbox IceCave_Text_TianaGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	
	release
end

IceCave_EventScript_Allen::
	trainerbattle_single TRAINER_ROSE_2, IceCave_Text_AllenIntro, IceCave_Text_AllenDefeated, IceCave_EventScript_AllenGivesSnowflake
	msgbox IceCave_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	
end	

IceCave_EventScript_AllenGivesSnowflake:
	msgbox IceCave_Text_AllenGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	
	release
end

IceCave_EventScript_Ivan::
	trainerbattle_single TRAINER_DIANA_4, IceCave_Text_IvanIntro, IceCave_Text_IvanDefeated, IceCave_EventScript_IvanGivesSnowflake
	msgbox IceCave_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
end	

IceCave_EventScript_IvanGivesSnowflake:
	msgbox IceCave_Text_IvanGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	release
end

IceCave_EventScript_Billy::
	trainerbattle_single TRAINER_ROSE_3, IceCave_Text_BillyIntro, IceCave_Text_BillyDefeated, IceCave_EventScript_BillyGivesSnowflake
	msgbox IceCave_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
end	

IceCave_EventScript_BillyGivesSnowflake:
	msgbox IceCave_Text_BillyGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	release
end

IceCave_EventScript_Elliot::
	trainerbattle_single TRAINER_JENNY_5, IceCave_Text_ElliotIntro, IceCave_Text_ElliotDefeated, IceCave_EventScript_ElliotGivesSnowflake
	msgbox IceCave_Text_ElliotPostBattle, MSGBOX_AUTOCLOSE
	end	

IceCave_EventScript_ElliotGivesSnowflake:
	msgbox IceCave_Text_ElliotGivesSnowflake, MSGBOX_NPC
	giveitem ITEM_SNOWFLAKE, 1
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	
	release
end

IceCave_Text_RickIntro:
	.string "I love the cold!$"

IceCave_Text_RickDefeated:
 	.string "That's too cold!$"

IceCave_Text_RickGivesSnowflake:
	.string "Here, you earned this.$"

IceCave_Text_RickPostBattle:
	.string "I should get a coat$"

IceCave_Text_AllenIntro:
	.string "This cave is kind of scary.$"

IceCave_Text_AllenDefeated:
 	.string "I'm spooked!$"

IceCave_Text_AllenGivesSnowflake:
	.string "Here's my Snowflake. Good luck.$"

IceCave_Text_AllenPostBattle:
	.string "Good luck. Don't forget to restock \nwhen you can$"

IceCave_Text_TianaIntro:
	.string "How's my hair look?$"

IceCave_Text_TianaDefeated:
 	.string "I feel my hair standing up from \nour battle.$"

IceCave_Text_TianaGivesSnowflake:
	.string "Take this, you're really strong.$"

IceCave_Text_TianaPostBattle:
	.string "Keep safe in these crazy times.$"

IceCave_Text_IvanIntro:
	.string "My Pokemon wear masks, do yours?$"

IceCave_Text_IvanDefeated:
 	.string "My masks didn't help, you're sick!$"

IceCave_Text_IvanGivesSnowflake:
	.string "Take my Snowflake and go.$"

IceCave_Text_IvanPostBattle:
	.string "I'm mad that I lost.$"

IceCave_Text_BillyIntro:
	.string "Don't worry, I'll take it easy \non you!$"

IceCave_Text_BillyDefeated:
 	.string "Next Time I'll actually try!$"

IceCave_Text_BillyGivesSnowflake:
	.string "Ugh fine, here!$"

IceCave_Text_BillyPostBattle:
	.string "Next time I won't take it easy on \nyou.$"

IceCave_Text_ElliotIntro:
	.string "I like ice fishing!$"

IceCave_Text_ElliotDefeated:
 	.string "I can't even catch a cold.$"

IceCave_Text_ElliotGivesSnowflake:
	.string "I fished this out of the lake the \nother day.$"

IceCave_Text_ElliotPostBattle:
	.string "I caught a Magikarp the other day.$"


IceCave_Text_TrainerNoBattle:
	.string "I won't battle you!\n"
	.string "One of your Pokemon is infected!$"

