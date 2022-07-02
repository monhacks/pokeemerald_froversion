NCC_Underground_BossLab_MapScripts::
	.byte 0


NCC_Underground_BossLab_Mewtwo::
	lock
		msgbox NCC_Underground_BossLab_Text_MewtwoPlanReveal, MSGBOX_DEFAULT
		trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_2, SummitCaverns_Text_LattkaDefeat2
		msgbox SummitCaverns_Text_PostLattkaBattle, MSGBOX_DEFAULT
	release
	end


NCC_Underground_BossLab_Text_MewtwoPlanReveal:
	.string "This is where I tell you my PLAN!!!!!$"

	