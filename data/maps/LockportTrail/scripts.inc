LockportTrail_MapScripts::
	.byte 0


LockportTrail_1F_EventScript_Grunt1:: @ 823988C
	trainerbattle_single TRAINER_CHARLIE, LockportTrail_1F_Text_Grunt1Intro, LockportTrail_1F_Text_Grunt1Defeat
	msgbox LockportTrail_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

LockportTrail_1F_Text_Grunt1Intro: @ 82398BA
	.string "What are you doing in these caves?\p"
	.string "I can't let you wander around here\n"
	.string "and see what our research team is\l"
	.string "working on!$"

LockportTrail_1F_Text_Grunt1Defeat: @ 82398BA
	.string "Now our Pokéresearch is at risk!$"

LockportTrail_1F_Text_Grunt1PostBattle:
	.string "Don't you want America to be\n"
	.string "the best PokéCountry in the world?$"

LockportTrail_1F_EventScript_Grunt2:: @ 823988C
	trainerbattle_single TRAINER_KEEGAN, LockportTrail_1F_Text_Grunt2Intro, LockportTrail_1F_Text_Grunt2Defeat
	msgbox LockportTrail_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

LockportTrail_1F_Text_Grunt2Intro: @ 82398BA
	.string "Who are you?\n"
    .string "How did you get here?$"

LockportTrail_1F_Text_Grunt2Defeat: @ 82398BA
	.string "Oww!\n"
    .string "Beaten!$"

LockportTrail_1F_Text_Grunt2PostBattle:
	.string "Blast it… You're dissing Team\n"
    .string "MAGA, aren't you?$"

LockportTrail_1F_EventScript_Grunt3:: @ 823988C
	trainerbattle_single TRAINER_JACE, LockportTrail_1F_Text_Grunt3Intro, LockportTrail_1F_Text_Grunt3Defeat
	msgbox LockportTrail_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

LockportTrail_1F_Text_Grunt3Intro: @ 82398BA
	.string "You broke into Team MAGA's\n"
    .string "operation? What nerve!$"

LockportTrail_1F_Text_Grunt3Defeat: @ 82398BA
	.string "Boom!$"

LockportTrail_1F_Text_Grunt3PostBattle:
	.string "You're not going to get away with\n"
    .string "this, brat!$"

LockportTrail_1F_EventScript_Grunt4:: @ 823988C
	trainerbattle_single TRAINER_JEFF, LockportTrail_1F_Text_Grunt4Intro, LockportTrail_1F_Text_Grunt4Defeat
	msgbox LockportTrail_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

LockportTrail_1F_Text_Grunt4Intro: @ 82398BA
    .string "Intruder alert!$"
   
LockportTrail_1F_Text_Grunt4Defeat: @ 82398BA
	.string "I can't do it!$"

LockportTrail_1F_Text_Grunt4PostBattle:
	.string "The Prototype? Humph!\n"
    .string "I don't know where it is.$"

LockportTrail_1F_EventScript_Grunt5:: @ 823988C
	trainerbattle_single TRAINER_ELI, LockportTrail_1F_Text_Grunt5Intro, LockportTrail_1F_Text_Grunt5Defeat
	msgbox LockportTrail_1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

LockportTrail_1F_Text_Grunt5Intro: @ 82398BA
	.string "Why did you come here?$"

LockportTrail_1F_Text_Grunt5Defeat: @ 82398BA
	.string "This won't do...$"

LockportTrail_1F_Text_Grunt5PostBattle:
	.string "Okay, I'll talk...\n"
	.string "Take the ladder downwards. The\l"
	.string "Researcher is down deeper in the\l"
	.string "caverns.$"

LockportTrail_1F_EventScript_Grunt6:: @ 823988C
	trainerbattle_single TRAINER_MISSY, LockportTrail_1F_Text_Grunt6Intro, LockportTrail_1F_Text_Grunt6Defeat
	msgbox LockportTrail_1F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

LockportTrail_1F_Text_Grunt6Intro: @ 82398BA
	.string "Are you lost, you little mouse?$"

LockportTrail_1F_Text_Grunt6Defeat: @ 82398BA
	.string "Why…?$"

LockportTrail_1F_Text_Grunt6PostBattle:
	.string "Uh-oh, that ruckus hurt my\n"
    .string "ears!$"
