MountCinnabar_2F_MapScripts::
	.byte 0


MountCinnabar_2F_EventScript_ChanseyHeal::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, 0
	setrespawn HEAL_LOCATION_MOUNT_CINNABAR_2F
	msgbox SummitCaverns_Text_RestUpHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCaverns_EventScript_Rest
	closemessage
	release
	end