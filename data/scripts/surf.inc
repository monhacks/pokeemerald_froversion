EventScript_UseSurf:: @ 8271EA0
	checkpartymove MOVE_SURF
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_EndUseSurf
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf:: @ 8271ED5
	releaseall
EventScript_EndUseSurf:: @ 8271ED6
	end

gFieldEffectScript_UseTeleportFromField:: @ 82DBCED
	checkpartymove MOVE_TELEPORT
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EventScript_EndUseTeleportFromField
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_TeleportToPad, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_ReleaseUseTeleportFromField
	dofieldeffect FLDEFF_USE_TELEPORT
	setflag FLAG_UNUSED_0x027
EventScript_ReleaseUseTeleportFromField:: @ 8271ED5
	releaseall
EventScript_EndUseTeleportFromField:: @ 8271ED6
	end
	