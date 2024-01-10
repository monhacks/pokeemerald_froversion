BlackForest3_MapScripts::
	.byte 0


EventScript_BlackForest3_Murkrow::
	givecustommon SPECIES_MURKROW, 50, ITEM_LEFTOVERS, ITEM_DUSK_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_DRILL_PECK, MOVE_SHADOW_BALL, MOVE_PROTECT, MOVE_REST, 0
	removeobject 5
	setflag FLAG_ITEM_MOUNT_CINNABAR_WEST_1F_ULTRA_BALL
	release
	end