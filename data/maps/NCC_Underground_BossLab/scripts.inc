.set LOCAL_ID_MEWTWO, 1
.set LOCAL_ID_SCIENTIST_2, 2
.set LOCAL_ID_SCIENTIST_3, 3
.set LOCAL_ID_SCIENTIST_4, 4
.set LOCAL_ID_SCIENTIST_5, 5
.set LOCAL_ID_POKE_BALL, 6



NCC_Underground_BossLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NCC_Underground_BossLab_OnLoad
	.byte 0

NCC_Underground_BossLab_OnLoad:
	removeobject LOCAL_ID_MEWTWO
	setflag FLAG_HIDE_NCC_LAB_MEWTWO
	end

NCC_Underground_BossLab_BossBattleInitiate::
	lockall
		applymovement LOCAL_ID_SCIENTIST_5, Common_Movement_FaceUp
		waitmovement LOCAL_ID_SCIENTIST_5
		applymovement LOCAL_ID_SCIENTIST_5, Common_Movement_ExclamationMark
		waitmovement LOCAL_ID_SCIENTIST_5
		msgbox NCC_Underground_BossLab_Text_DontTouchThat, MSGBOX_DEFAULT
		closemessage
		fadescreen FADE_TO_BLACK
		playse SE_SLIDING_DOOR
		waitse
		clearflag FLAG_HIDE_NCC_LAB_MEWTWO
		addobject LOCAL_ID_MEWTWO
		setobjectmovementtype LOCAL_ID_MEWTWO, MOVEMENT_TYPE_FACE_RIGHT
		fadescreen FADE_FROM_BLACK
		msgbox NCC_Underground_BossLab_Text_MewtwoPlanReveal
		trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_2, SummitCaverns_Text_LattkaDefeat2
		msgbox SummitCaverns_Text_PostLattkaBattle, MSGBOX_DEFAULT
	releaseall
	end

NCC_Underground_BossLab_Mewtwo::
	lock
		msgbox NCC_Underground_BossLab_Text_MewtwoPlanReveal, MSGBOX_DEFAULT
		trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_2, SummitCaverns_Text_LattkaDefeat2
		msgbox SummitCaverns_Text_PostLattkaBattle, MSGBOX_DEFAULT
	release
	end

NCC_Underground_BossLab_Text_DontTouchThat:
	.string "Hey, you can't touch that!\p"
	.string "That is our newest experiment the\n"
	.string "Boss does not want anyone, even\l"
	.string "trained scientists touching it!\p"
	.string "You better get away, the Boss won't\n"
	.string "only have your head, but mine too\l"
	.string "if he sees you touching that!$"

NCC_Underground_BossLab_Text_MewtwoPlanReveal:
	.string "This is where I tell you my PLAN!!!!!$"

	