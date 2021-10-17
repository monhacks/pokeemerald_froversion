.set LOCALID_LATTKA, 1
.set LOCALID_ZENDANO, 2

LockportTrail_BF2_MapScripts::
	.byte 0


SummitCaverns_EventScript_LattkaBattleTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_LATTKA, Common_Movement_FaceRight
	applymovement LOCALID_ZENDANO, Common_Movement_FaceLeft
	waitmovement LOCALID_ZENDANO
	msgbox SummitCaverns_Text_TestSubjectResults, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_ZENDANO, Common_Movement_QuestionMark
	msgbox SummitCaverns_Text_WhatWasThat, MSGBOX_DEFAULT
	applymovement LOCALID_ZENDANO, Common_Movement_FacePlayer
	applymovement LOCALID_LATTKA, Common_Movement_FacePlayer
	waitmovement LOCALID_LATTKA
	msgbox SummitCaverns_Text_YouAgain, MSGBOX_DEFAULT
	applymovement LOCALID_ZENDANO, SummitCavenrs_Movement_ZendanoLeaves1
	waitmovement LOCALID_ZENDANO
	playse SE_WALL_HIT
	applymovement OBJ_EVENT_ID_PLAYER, SummitCaverns_Movement_FroGetsPushed
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_ZENDANO, SummitCavenrs_Movement_ZendanoLeaves2
	waitmovement LOCALID_ZENDANO
	removeobject LOCALID_ZENDANO
	msgbox SummitCaverns_Text_LattkaBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_1, SummitCaverns_Text_LattkaDefeat1
	special HealPlayerParty
	msgbox SummitCaverns_Text_LattkaBattlePrototype, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_2, SummitCaverns_Text_LattkaDefeat2
	msgbox SummitCaverns_Text_PostLattkaBattle, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LATTKA
	fadescreen FADE_FROM_BLACK
	//setflags
	releaseall
	end

SummitCaverns_Text_LattkaDefeat2:
	.string "I guess I didn't time the moves right...$"

SummitCaverns_Text_PostLattkaBattle:
	.string "No...\p"
	.string "This can't be...\p"
	.string "All my time... my research...\p"
	.string "And you've destroyed it all...\p"
	.string "You will pay for this. Mark my words.\n"
	.string "But I have no Pokémon left in battle\l"
	.string "condition.\p"
	.string "Team MAGA will have to flee and regroup...$"

SummitCaverns_Text_LattkaBattlePrototype:
	.string "I didn't want to have to do this,\n"
	.string "but you leave me no choice.\p"
	.string "Now I'm going to have to show you\n"
	.string "Team MAGA's true power.\p"
	.string "Behold, the first ever human and\n"
	.string "Pokémon fusion!$"

SummitCaverns_Text_LattkaDefeat1:
	.string "Time the moves we can make ends\p"
	.string "meet. Something about the ends$"

SummitCaverns_Text_LattkaBattle:
	.string "You really don't see that everything\n"
	.string "we're doing is for the greater good?\p"
	.string "I guess I'll just have to show you\n"
	.string "then!$"

SummitCavenrs_Movement_ZendanoLeaves2:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SummitCaverns_Movement_FroGetsPushed:
	lock_facing_direction
	walk_fastest_left
	unlock_facing_direction
	face_right
	step_end

SummitCavenrs_Movement_ZendanoLeaves1:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

SummitCaverns_Text_YouAgain:
	.string "You again?!\p"
	.string "Lattka: Is this the thug that stole \n"
	.string "the Meteorite from you Z?\p"
	.string "Zendano: Yea, and it looks like he\n"
	.string "wants a rematch!\p"
	.string "Lattka: Why don't you let me handle him,\n"
	.string "you get out of here and warn the boss\l"
	.string "this punk is still interfering with\l"
	.string "Team MAGA.$"

SummitCaverns_Text_WhatWasThat:
	.string "What was that?$"

SummitCaverns_Text_TestSubjectResults:	

	.string "Lattka: Ah yes, the prototype is\n"
	.string "progressing very well.\p"
	.string "Although you weren't able to\n"
	.string "secure the Meteroite, this may prove\l"
	.string "to be an even larger development.\p"
	.string "Who knew that the fusion of Pokémon DNA\n"
	.string "into humans could produce such incredible\l"
	.string "results.\p"
	.string "Zendano: Is it ready for field testing\n"
	.string "yet?\p"
	.string "Lattka: Not quite. Our test subject is\n"
	.string "a proud member of the airforce, and his\l"
	.string "participation wasn't exactly voluentary.\p"
	.string "For the most part, he obeys commands like\n"
	.string "a normal Pokémon should, but sometimes I\l"
	.string "can tell there is still a little bit of\l"
	.string "his human side in there, fighting back.\p"
	.string "I still need to train that out of him.\p"
	.string "Zendano: I'll report this to the boss.\n"
	.string "Have the subject ready for a field\l"
	.string "test as soon as you can.$"
