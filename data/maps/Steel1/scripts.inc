Steel1_MapScripts::
	.byte 0


EventScript_BobbySteelLeader::
	lock
	setvar VAR_0x8000, TYPE_STEEL
	callnative CheckPartyForType
	compare VAR_RESULT, FALSE
	goto_if_eq NikeVersionEventScript_YouHavePokemonThatCantBeUsed
	setflag FLAG_BATTLE_RECHARGE
	setflag FLAG_SYS_NO_BAG_USE
	trainerbattle_single TRAINER_BOBBY_STEEL_LEADER, BobbySteelLeader_IntroText, BobbySteelLeader_DefeatText, BobbySteelLeader_DefeatedScript
	clearflag FLAG_BATTLE_POISON_FIELD
	clearflag FLAG_SYS_NO_BAG_USE
	msgbox BobbySteelLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

BobbySteelLeader_DefeatedScript:
	clearflag FLAG_BATTLE_RECHARGE
	clearflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_DEFEATED_STEEL
	msgbox BobbySteelLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

BobbySteelLeader_IntroText:	
	.string "I'm chad and I like poison!$"

BobbySteelLeader_DefeatText:
	.string "I'm chad and I lost!$"

BobbySteelLeader_DefeatedText:
	.string "I'm chad and you won!$"