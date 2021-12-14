NewMap2_MapScripts::
	.byte 0


EventScript_WesFireLeader::
	lock
	setvar VAR_0x8000, TYPE_FIRE
	callnative CheckPartyForType
	compare VAR_RESULT, FALSE
	goto_if_eq NikeVersionEventScript_YouHavePokemonThatCantBeUsed
	setflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_BATTLE_SUN
	trainerbattle_single TRAINER_WES_FIRE_LEADER, WesFireLeader_IntroText, WesFireLeader_DefeatText, WesFireLeader_DefeatedScript
	clearflag FLAG_BATTLE_SUN
	clearflag FLAG_SYS_NO_BAG_USE
	msgbox WesFireLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

WesFireLeader_DefeatedScript:
	clearflag FLAG_SYS_NO_BAG_USE
	clearflag FLAG_BATTLE_SUN
	setflag FLAG_DEFEATED_FIRE
	msgbox WesFireLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

WesFireLeader_IntroText:	
	.string "I'm chad and I like poison!$"

WesFireLeader_DefeatText:
	.string "I'm chad and I lost!$"

WesFireLeader_DefeatedText:
	.string "I'm chad and you won!$"