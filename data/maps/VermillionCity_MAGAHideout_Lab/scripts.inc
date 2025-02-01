VermillionCity_MAGAHideout_Lab_MapScripts::
	.byte 0


VermillionCity_MAGAHideout_Lab_EventScripts_FinalBoss::
lock
	msgbox FinalBoss_Text_MagaLeadScientist, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_MATT_FINAL_BOSS,MAGAHideout3F_Text_FinalBossDefeated
	msgbox MAGAHideout3F_Text_FinalBossMonologue, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	setflag FLAG_HIDE_MAGA_HIDEOUT_SCIENTISTS
	fadescreen FADE_FROM_BLACK
	msgbox MAGAHideout3F_Text_PlayerSad, MSGBOX_AUTOCLOSE
	release
	end

MAGAHideout3F_EventScript_Scientist1::
	lock
	msgbox MAGAHideout3F_Text_Scientist1, MSGBOX_NPC
	release
	end

MAGAHideout3F_EventScript_Scientist2::
	lock
	msgbox MAGAHideout3F_Text_Scientist1, MSGBOX_NPC
	release
	end

MAGAHideout3F_EventScript_Scientist3::
	lock
	msgbox MAGAHideout3F_Text_Scientist3, MSGBOX_NPC
	release
	end

MAGAHideout3F_Text_Scientist1:
	.string "We were on the verge of a major\n"
	.string "breakthrough! Now the lab is in\p"
	.string "chaos! Was this your doing?!$"

MAGAHideout3F_Text_Scientist2:
	.string "The generators... they're down?!\n"
	.string "Did you do this?! This will set\p"
	.string "our experiments back by months!$"

MAGAHideout3F_Text_Scientist3:
	.string "The generators... they're down?!\n"
	.string "Did you do this?! This will set\p"
	.string "our experiments back by months!$"

MAGAHideout3F_Text_FinalBossDefeated:
	.string "No... this isn't possible!\n"
	.string "How could {PLAYER} defeat my\l"
	.string "greatest creation?! I must flee!$"

MAGAHideout3F_Text_PlayerSad:
	.string "Metagross... you're gone...\n"
	.string "You were my best friend...\l"
	.string "and now... now I lost you...\p"
	.string "Even though I stopped Team MAGA,\n"
	.string "I feel so empty...\p"
	.string "This journey might be over...\n"
	.string "but I won't stop until Team MAGA\l"
	.string "stops taking from innocent people!$"



	

FinalBoss_Text_MagaLeadScientist:
	.string "Hah! {PLAYER}, you finally see it!\n"
	.string "Your little shop? A perfect disguise.\p"
	.string "While you peddled goods, Team MAGA\n"
	.string "was perfecting something far greater.\p"
	.string "Shutting off the power was a smart\n"
	.string "move, but you were just a little\l"
	.string "too late to stop it.\p"
	.string "The work is complete. The experiment?\n"
	.string "A success.\p"
	.string "Your precious Metagross? No longer\n"
	.string "yours. We have reshaped it entirely.\p"
	.string "Stronger. Smarter. Unstoppable. And\n"
	.string "now, it stands against its former master.\p"
	.string "If you want to stop us, you must\n"
	.string "defeat your own Pokémon.\p"
	.string "But tell me, {PLAYER}... can you really\n"
	.string "bring yourself to destroy it?\p"
	.string "{PLAYER}: Metagross... I'm sorry I\n"
	.string "couldn't protect you. But I promise,\l"
	.string "I will set things right.\p"
	.string "Metagross is still my Pokémon.\p"
	.string "If stopping you means facing it,\n"
	.string "then I will do what I must!\p"
	.string "Hah! How pathetic, {PLAYER}!\n"
	.string "You think words can save it now?\p"
	.string "Metagross no longer remembers you.\n"
	.string "It obeys only us, its true masters!\p"
	.string "Go on, fight it! Watch as your\n"
	.string "precious Pokémon destroys you!$"

MAGAHideout3F_Text_FinalBossMonologue:
	.string "This is a disaster...\n"
	.string "Losing this fight... I might\l"
	.string "lose my job over this!\p"
	.string "The boss won't be happy...\l"
	.string "I have to report to him at once!$"
