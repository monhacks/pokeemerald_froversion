Poison1_MapScripts::
	.byte 0

IceRoomOne_EventScript_StrangeOldMan::
	lockall
	goto_if_set FLAG_DEFEATED_ICE, IceRoomOne_EventScript_StrangeOldManBattle
	msgbox IceRoomOne_Text_YouDontHaveTheForbiddenPokemon MSGBOX_DEFAULT
	releaseall
end

IceRoomOne_EventScript_StrangeOldManBattle:
	trainerbattle_single TRAINER_STRANGE_OLD_MAN, IceRoomOne_Text_StrangeOldMan_NoChoiceButToLaunch, IceRoomOne_Text_StrangeOldMan_IGotLaunchedInstead
	msgbox IceRoomOne_Text_StrangeOldMan_DropIceCanOnlyLearnIce
	releaseall
end

IceRoomOne_Text_YouDontHaveTheForbiddenPokemon:
	.string "Strange Old Man: You don't have the\n"
	.string "forbidden Pokemon, so I have no\l"
	.string "quarrel with you.$"

IceRoomOne_Text_StrangeOldMan_NoChoiceButToLaunch:
	.string "I see you have Dropice…\n"
	.string "I have no choice but to launch a\l"
	.string "meteor at you!$"

IceRoomOne_Text_StrangeOldMan_DropIceCanOnlyLearnIce:
	.string "Strange Old Man: Dropice can only\n"
	.string "learn Ice type moves before it evolves…\p"
	.string "I waited until level 44 when it\n"
	.string "learned Blizzard, but you can evolve\l"
	.string "yours whenever you want…\p"
	.string "if you have the right stone.$"


IceRoomOne_Text_StrangeOldMan_IGotLaunchedInstead:
	.string "I got launched instead...!$"