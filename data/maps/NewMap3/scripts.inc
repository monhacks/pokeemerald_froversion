NewMap3_MapScripts::
	.byte 0


EventScript_NewMap3_AriadosBossBattle::
	playmoncry SPECIES_ARIADOS, 2
	setwildbattle SPECIES_ARIADOS, 50, ITEM_NONE
	waitmoncry
	setflag FLAG_BATTLE_HAUNTING
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	special StartAriadosBossBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EventScript_NewMap3_AriadosBossBattleLost
	msgbox Text_NewMap3_TheAirFeelsClear, MSGBOX_DEFAULT
	playmoncry SPECIES_ARIADOS, 2
	removeobject 1
	setflag FLAG_ITEM_MOUNT_CINNABAR_WEST_1F_NUGGET
	fadescreenspeed FADE_TO_BLACK, 24
	msgbox Text_NewMap3_AllDone, MSGBOX_DEFAULT
	special GameClear
	waitstate
	releaseall
	end

EventScript_NewMap3_AriadosBossBattleLost:
	msgbox Text_NewMap3_TheAirFeelsHeavy, MSGBOX_DEFAULT
	setflag FLAG_LOST_BOSS_BATTLE
	fadescreen FADE_TO_BLACK
	warpsilent MAP_MAGM8EXTENDED_FOREST, 255, 44, 28 //replace this with anercomps map
	

Text_NewMap3_TheAirFeelsClear::
	.string "{PLAYER} notices the air feels clear.$"

Text_NewMap3_TheAirFeelsHeavy::
	.string "{PLAYER} notices the air feels heavy.\p"
	.string "{PLAYER} passes out.$"


Text_NewMap3_AllDone::
	.string "To do: save the forest...\n"
	.string "done!$"
	release
	end