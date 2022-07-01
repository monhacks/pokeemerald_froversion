MountCinnabar_2F_South_MapScripts::
	.byte 0


MountCinnabar_2F_South_EventScript_DynamicPunchTutor:: @ 82C81EE
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH, PorygonTutor_EventScript_DynamicPunchTaught
	msgbox PorygonTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	msgbox PorygonTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DYNAMIC_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
	goto PorygonTutor_EventScript_DynamicPunchTaught
	end

PorygonTutor_EventScript_DynamicPunchTaught:: @ 82C824C
	msgbox PorygonTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	end


PorygonTutor_Text_DynamicPunchTeach: @ 82C79A6
	.string "I am a digital move teacher.\n"
	.string "I am programmed to teach the move\l"
	.string "Dynamic Punch.\p"
	.string "Be aware, you will need to scan your\n"
	.string "Trainer Card, as I can only teach\l"
	.string "the move to one Pokémon per trainer.\p"
	.string "Would you like to teach one of your\n"
	.string "Pokémon Dynamic Punch?$"


PorygonTutor_Text_DynamicPunchWhichMon: @ 82C7B0D
	.string "Which Pokémon should I teach?$"

PorygonTutor_Text_DynamicPunchTaught: @ 82C7B4F
	.string "Thank you for utilizing my\n"
	.string "database, {PLAYER}.$"
