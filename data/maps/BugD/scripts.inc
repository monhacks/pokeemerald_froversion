BugD_MapScripts::
	.byte 0


EventScript_FroNormalLeader::
	lock
	setflag FLAG_BATTLE_ROULETTE
	setflag FLAG_SYS_NO_BAG_USE
	trainerbattle_single TRAINER_CHAD_POISON_LEADER, FroNormalLeader_IntroText, FroNormalLeader_DefeatText, FroNormalLeader_DefeatedScript
	clearflag FLAG_BATTLE_ROULETTE
	clearflag FLAG_SYS_NO_BAG_USE
	msgbox FroNormalLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

FroNormalLeader_DefeatedScript:
	clearflag FLAG_BATTLE_ROULETTE
	clearflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_DEFEATED_NORMAL
	msgbox FroNormalLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

FroNormalLeader_IntroText:	
	.string "I'm chad and I like poison!$"

FroNormalLeader_DefeatText:
	.string "I'm chad and I lost!$"

FroNormalLeader_DefeatedText:
	.string "I'm chad and you won!$"
