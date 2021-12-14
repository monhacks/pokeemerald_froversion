Water2_MapScripts::
	.byte 0


EventScript_MarriottWaterLeader::
	lock
	setvar VAR_0x8000, TYPE_WATER
	callnative CheckPartyForType
	compare VAR_RESULT, FALSE
	goto_if_eq NikeVersionEventScript_YouHavePokemonThatCantBeUsed
	setflag FLAG_BATTLE_RAIN
	setflag FLAG_SYS_NO_BAG_USE
	trainerbattle_single TRAINER_MARRIOTT_WATER_LEADER, MarriottWaterLeader_IntroText, MarriottWaterLeader_DefeatText, MarriottWaterLeader_DefeatedScript
	clearflag FLAG_BATTLE_RAIN
	clearflag FLAG_SYS_NO_BAG_USE
	msgbox MarriottWaterLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

MarriottWaterLeader_DefeatedScript:
	clearflag FLAG_BATTLE_RAIN
	clearflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_DEFEATED_WATER
	msgbox MarriottWaterLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

MarriottWaterLeader_IntroText:	
	.string "I'm chad and I like poison!$"

MarriottWaterLeader_DefeatText:
	.string "I'm chad and I lost!$"

MarriottWaterLeader_DefeatedText:
	.string "I'm chad and you won!$"