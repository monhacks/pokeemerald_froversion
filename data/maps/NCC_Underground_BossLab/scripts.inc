.set LOCAL_ID_MEWTWO, 1
.set LOCAL_ID_SCIENTIST_2, 2
.set LOCAL_ID_SCIENTIST_3, 3
.set LOCAL_ID_SCIENTIST_4, 4
.set LOCAL_ID_SCIENTIST_5, 5
.set LOCAL_ID_POKE_BALL, 6



NCC_Underground_BossLab_MapScripts::


	.byte 0


NCC_Underground_BossLab_BossBattleInitiate::
	lockall
		applymovement LOCAL_ID_SCIENTIST_5, Common_Movement_FaceUp
		waitmovement LOCAL_ID_SCIENTIST_5
		applymovement LOCAL_ID_SCIENTIST_5, Common_Movement_ExclamationMark
		waitmovement LOCAL_ID_SCIENTIST_5
	releaseall
	end

NCC_Underground_BossLab_Mewtwo::
	lock
		msgbox NCC_Underground_BossLab_Text_MewtwoPlanReveal, MSGBOX_DEFAULT
		trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_2, SummitCaverns_Text_LattkaDefeat2
		msgbox SummitCaverns_Text_PostLattkaBattle, MSGBOX_DEFAULT
	release
	end


NCC_Underground_BossLab_Text_MewtwoPlanReveal:
	.string "This is where I tell you my PLAN!!!!!$"

	