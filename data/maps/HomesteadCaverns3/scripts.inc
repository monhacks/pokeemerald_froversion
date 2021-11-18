HomesteadCaverns3_MapScripts::
	.byte 0


NedTrainer::
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, FALSE
	goto_if_eq IceCave_EventScript_Ned
	msgbox IceCave_Text_TrainerNoBattle, MSGBOX_NPC
	end

IceCave_EventScript_Ned::
	trainerbattle_single TRAINER_JENNY_4, IceCave_Text_NedIntro, IceCave_Text_NedDefeated, IceCave_EventScript_NedGivesSnowflake
	msgbox IceCave_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

IceCave_EventScript_NedGivesSnowflake:
	msgbox IceCave_Text_NedGivesSnowflake, MSGBOX_NPC
	addvar VAR_HOMESTEAD_NORTH_STATE, 1
	giveitem ITEM_SNOWFLAKE, 1
	release
	end

IceCave_Text_NedIntro:
	.string "I like hanging out in the deepest \narea of the cave!$"

IceCave_Text_NedDefeated:
 	.string "I'm in too deep!$"

IceCave_Text_NedGivesSnowflake:
	.string "Here's a Snowflake for your trouble.$"

IceCave_Text_NedPostBattle:
	.string "The Climb back up won't be as easy!$"
