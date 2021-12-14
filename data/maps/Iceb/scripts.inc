Iceb_MapScripts::
	.byte 0


EventScript_SeelIceLeader::
	lock
	setvar VAR_0x8000, TYPE_ICE
	callnative CheckPartyForType
	compare VAR_RESULT, FALSE
	goto_if_eq NikeVersionEventScript_YouHavePokemonThatCantBeUsed
	setflag FLAG_SYS_NO_BAG_USE
	trainerbattle_single TRAINER_SEEL_ICE_LEADER, SeelIceLeader_IntroText, SeelIceLeader_DefeatText, SeelIceLeader_DefeatedScript
	clearflag FLAG_BATTLE_POISON_FIELD
	clearflag FLAG_SYS_NO_BAG_USE
	msgbox SeelIceLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

SeelIceLeader_DefeatedScript:
	clearflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_DEFEATED_ICE
	msgbox SeelIceLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

SeelIceLeader_IntroText:	
	.string "I'm chad and I like poison!$"

SeelIceLeader_DefeatText:
	.string "I'm chad and I lost!$"

SeelIceLeader_DefeatedText:
	.string "I'm chad and you won!$"
