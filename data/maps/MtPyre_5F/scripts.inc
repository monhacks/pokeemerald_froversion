MtPyre_5F_MapScripts:: @ 8231C6D
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha:: @ 8231C6E
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro: @ 8231C85
	.string "The walls of church don't make it\n"
	.string "holy…$"

MtPyre_4F_Text_TashaDefeat: @ 8231CDB
	.string "Security isn't glitzy or glamorous,\n"
	.string "concrete or cohesive.$"

MtPyre_4F_Text_TashaPostBattle: @ 8231CEE
	.string "Therein lies the truth.\n"
	.string "Lift your head up high.$"

