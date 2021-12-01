bug3_MapScripts::
	.byte 0


EventScript_ChadPoisonLeader::
	lock
	setflag FLAG_BATTLE_POISON_FIELD
	setflag FLAG_SYS_NO_BAG_USE
	trainerbattle_single TRAINER_CHAD_POISON_LEADER, ChadPoisonLeader_IntroText, ChadPoisonLeader_DefeatText, ChadPoisonLeader_DefeatedScript
	clearflag FLAG_BATTLE_POISON_FIELD
	clearflag FLAG_SYS_NO_BAG_USE
	msgbox ChadPoisonLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

ChadPoisonLeader_DefeatedScript:
	clearflag FLAG_BATTLE_POISON_FIELD
	clearflag FLAG_SYS_NO_BAG_USE
	setflag FLAG_DEFEATED_POISON
	msgbox ChadPoisonLeader_DefeatedText, MSGBOX_DEFAULT
	release
end

ChadPoisonLeader_IntroText:	
	.string "I'm chad and I like poison!$"

ChadPoisonLeader_DefeatText:
	.string "I'm chad and I lost!$"

ChadPoisonLeader_DefeatedText:
	.string "I'm chad and you won!$"

EventScript_BugRoom3_TrainerBattle1::
	lock
	trainerbattle_single TRAINER_GRUNT_MUSEUM_1, BugRoom3_Trainer1_Intro, BugRoom3_Trainer1_Defeat
	msgbox BugRoom3_Trainer1_Defeated, MSGBOX_DEFAULT
	release
end

EventScript_BugRoom3_TrainerBattle2::
	lock
	trainerbattle_single TRAINER_GRUNT_MUSEUM_2, BugRoom3_Trainer2_Intro, BugRoom3_Trainer2_Defeat
	msgbox BugRoom3_Trainer2_Defeated, MSGBOX_DEFAULT
	release
end



///////////////////Texts////////////////////////
///////////////////////////////////////////////

BugRoom3_Trainer1_Intro:
	.string "I'm a trainer 1.$"

BugRoom3_Trainer1_Defeat:
	.string "You won message 1.$"

BugRoom3_Trainer1_Defeated:
	.string "Post battle message 1.$"

BugRoom3_Trainer2_Intro:
	.string "I'm a trainer 2.$"

BugRoom3_Trainer2_Defeat:
	.string "You won message 2.$"

BugRoom3_Trainer2_Defeated:
	.string "Post battle message 2.$"


