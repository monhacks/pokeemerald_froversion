Electric2_MapScripts::
	.byte 0


EventScript_MarkElectricLeader::
	lock
	setvar VAR_0x8000, TYPE_ELECTRIC
	callnative CheckPartyForType
	compare VAR_RESULT, FALSE
	goto_if_eq NikeVersionEventScript_YouHavePokemonThatCantBeUsed
	setflag FLAG_BATTLE_POST_PRODUCTION
	setflag FLAG_SYS_NO_BAG_USE
	trainerbattle_single TRAINER_MARK_ELECTRIC_LEADER, MarkElectricLeader_IntroText, MarkElectricLeader_DefeatText, MarkElectricLeader_DefeatedScript
	clearflag FLAG_BATTLE_POST_PRODUCTION
	clearflag FLAG_SYS_NO_BAG_USE
	msgbox MarkElectricLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

MarkElectricLeader_DefeatedScript:
	clearflag FLAG_BATTLE_POST_PRODUCTION
	clearflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_DEFEATED_ELECTRIC
	msgbox MarkElectricLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

MarkElectricLeader_IntroText:	
	.string "I'm chad and I like poison!$"

MarkElectricLeader_DefeatText:
	.string "I'm chad and I lost!$"

MarkElectricLeader_DefeatedText:
	.string "I'm chad and you won!$"
