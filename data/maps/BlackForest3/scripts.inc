BlackForest3_MapScripts::
	.byte 0


EventScript_BlackForest3_Murkrow::
	playmoncry SPECIES_MURKROW, 2
	setwildbattle SPECIES_MURKROW, 50, ITEM_NONE
	waitmoncry
	special StartMurkrowBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq WildBattleSpecialMurkrowOutcomeRan
	msgbox BlackForest3_Text_WildGastlyWantsToJoinParty, MSGBOX_DEFAULT
	playmoncry SPECIES_MURKROW, 2
	removeobject 5
	waitmoncry
	givecustommon SPECIES_MURKROW, 50, ITEM_LEFTOVERS, ITEM_DUSK_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_DRILL_PECK, MOVE_SHADOW_BALL, MOVE_PROTECT, MOVE_REST, 0
	setflag FLAG_ITEM_MOUNT_CINNABAR_WEST_1F_ULTRA_BALL
	release
	end

WildBattleSpecialMurkrowOutcomeRan:
	playmoncry SPECIES_MURKROW, 2
	removeobject 5
	waitmoncry
	msgbox BlackForest3_Text_WildMurkrowRan, MSGBOX_DEFAULT
	setflag FLAG_ITEM_MOUNT_CINNABAR_WEST_1F_ULTRA_BALL
	release
end

BlackForest3_Text_WildMurkrowRan:
	.string "The wild Murkrow ran away in the\n"
	.string "opposite direction!$"

BlackForest3_Text_WildGastlyWantsToJoinParty:
	.string "The wild Murkrow seems to want to join\n"
	.string "you after you've defeated it.\p"
	.string "{PLAYER} allows Murkrow to join the\n"
	.string  "party.$"
