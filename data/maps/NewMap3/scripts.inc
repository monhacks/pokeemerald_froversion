NewMap3_MapScripts::
	.byte 0


EventScript_NewMap3_AriadosBossBattle::
	playmoncry SPECIES_ARIADOS, 2
	setwildbattle SPECIES_ARIADOS, 50, ITEM_NONE
	waitmoncry
	setflag FLAG_BATTLE_HAUNTING
	special StartAriadosBossBattle
	waitstate
	//msgbox Text_NewMap3_TheAirFeelsClear, MSGBOX_DEFAULT
	playmoncry SPECIES_VENUSAUR, 2
	removeobject 1
	waitmoncry
	givecustommon SPECIES_VENUSAUR, 50, ITEM_LEFTOVERS, ITEM_DUSK_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_CURSE, MOVE_SLUDGE_BOMB, MOVE_LEECH_SEED, MOVE_SYNTHESIS, 0
	setflag FLAG_ITEM_MOUNT_CINNABAR_WEST_1F_NUGGET
	release
	end
