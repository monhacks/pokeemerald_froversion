.set LOCALID_LATTKA, 1
.set LOCALID_ZENDANO, 2

LockportTrail_BF2_MapScripts::
	.byte 0

SummitCaverns_EventScript_ChanseyHeal::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, 0
	setrespawn HEAL_LOCATION_LOCKPORT_TRAIL_BF2
	msgbox SummitCaverns_Text_RestUpHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCaverns_EventScript_Rest
	closemessage
	release
	end

SummitCaverns_EventScript_Porygon::
	lock
	playmoncry SPECIES_PORYGON, 0
	scrollingmultichoice 9, 2, 3, 3, TRUE
	compare VAR_RESULT, 0
	goto_if_eq Eventscript_Porygon_PCMainMenu
	compare VAR_RESULT, 1
	goto_if_eq MyChimney_EventScript_Amneet
	compare VAR_RESULT, 2
	goto_if_eq BossBattleMoveRelearner
	release
	end

SummitCaverns_EventScript_Rest:: @ 822A941
	msgbox SummitCaverns_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end


SummitCaverns_EventScript_MagaGruntBF21:: @ 81F2F93
	trainerbattle_single TRAINER_KAREN_2, SummitCaverns_Text_MagaGruntBF21Intro, SummitCaverns_Text_MagaGruntBF21Defeat
	msgbox SummitCaverns_Text_MagaGruntBF21PostBattle, MSGBOX_DEFAULT
	release
	end

SummitCaverns_EventScript_MagaGruntBF22:: @ 81F2F93
	trainerbattle_single TRAINER_KAREN_3, SummitCaverns_Text_MagaGruntBF22Intro, SummitCaverns_Text_MagaGruntBF22Defeat
	msgbox SummitCaverns_Text_MagaGruntBF22PostBattle, MSGBOX_DEFAULT
	release
	end

SummitCaverns_EventScript_MagaGruntBF23:: @ 81F2F93
	trainerbattle_single TRAINER_KAREN_4, SummitCaverns_Text_MagaGruntBF23Intro, SummitCaverns_Text_MagaGruntBF23Defeat
	msgbox SummitCaverns_Text_MagaGruntBF23PostBattle, MSGBOX_DEFAULT
	release
	end

SummitCaverns_EventScript_MagaGruntBF24:: @ 81F2F93
	trainerbattle_single TRAINER_KAREN_5, SummitCaverns_Text_MagaGruntBF24Intro, SummitCaverns_Text_MagaGruntBF24Defeat
	msgbox SummitCaverns_Text_MagaGruntBF24PostBattle, MSGBOX_DEFAULT
	release
	end

SummitCaverns_EventScript_LattkaBattleTrigger::
	lockall
	setrespawn HEAL_LOCATION_LOCKPORT_TRAIL_BF2
	goto_if_set FLAG_HIDE_SUMMIT_CAVERNS_TEAM_MAGA_ZENDANO, SummitCaverns_EventScript_LattkaBattleEnd
	playbgm MUS_FV_TEAM_MAGA, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_LATTKA, Common_Movement_FaceRight
	applymovement LOCALID_ZENDANO, Common_Movement_FaceLeft
	waitmovement LOCALID_ZENDANO
	msgbox SummitCaverns_Text_TestSubjectResults, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_ZENDANO, Common_Movement_QuestionMark
	msgbox SummitCaverns_Text_WhatWasThat, MSGBOX_DEFAULT
	applymovement LOCALID_ZENDANO, Common_Movement_FaceDown
	applymovement LOCALID_LATTKA, Common_Movement_FaceDown
	waitmovement LOCALID_LATTKA
	msgbox SummitCaverns_Text_YouAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ZENDANO, SummitCavenrs_Movement_ZendanoLeaves1
	waitmovement LOCALID_ZENDANO
	playse SE_WALL_HIT
	applymovement OBJ_EVENT_ID_PLAYER, SummitCaverns_Movement_FroGetsPushed
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_ZENDANO, SummitCavenrs_Movement_ZendanoLeaves2
	waitmovement LOCALID_ZENDANO
	removeobject LOCALID_ZENDANO
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp_LockportTrail
	waitmovement OBJ_EVENT_ID_PLAYER
	setflag FLAG_HIDE_SUMMIT_CAVERNS_TEAM_MAGA_ZENDANO
	msgbox SummitCaverns_Text_LattkaChallengesFro, MSGBOX_DEFAULT
	releaseall
	end

SummitCaverns_EventScript_LattkaBattleNPC::
	trainerbattle_double TRAINER_SUMMIT_CAVERNS_LATTKA_1, SummitCaverns_Text_LattkaBattle, SummitCaverns_Text_LattkaDefeat1, Route104_Text_GinaNotEnoughMons, SummitCaverns_EventScript_LattkaBattleNPCPart2
	
SummitCaverns_EventScript_LattkaBattleNPCPart2::
	special HealPlayerParty
	msgbox SummitCaverns_Text_LattkaBattlePrototype, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_2, SummitCaverns_Text_LattkaDefeat2
	msgbox SummitCaverns_Text_PostLattkaBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LATTKA
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_SUMMIT_CAVERNS_TEAM_MAGA
	setvar VAR_PETALBURG_CITY_STATE, 8
	fadedefaultbgm
	goto SummitCaverns_EventScript_LattkaBattleEnd
	releaseall
	end

SummitCaverns_EventScript_LattkaBattleEnd:
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
	.string "Time the moves we can make ends\n"
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

Common_Movement_FaceUp_LockportTrail:
	face_up
	lock_facing_direction
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
	.string "into humans could produce such\l"
	.string "incredible results.\p"
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

SummitCaverns_Text_MagaGruntBF21Intro:
	.string "It's so damp down here!\p"
	.string "I wish I could have gotten a better\n"
	.string "assignment!$"

SummitCaverns_Text_MagaGruntBF21Defeat:
	.string "I can't wait until we no longer\n"
	.string "have use for this cave!$"

SummitCaverns_Text_MagaGruntBF21PostBattle:
	.string "I'm starting to question my life\n"
	.string "choices.$"

SummitCaverns_Text_MagaGruntBF22Intro:
	.string "How did you make it all the way\n"
	.string "down here?$"

SummitCaverns_Text_MagaGruntBF22Defeat:
	.string "You are strong. But not strong\n"
	.string "enough to stop our science!$"

SummitCaverns_Text_MagaGruntBF22PostBattle:
	.string "We've got plans bigger than you\n"
	.string "can imagine!$"

SummitCaverns_Text_MagaGruntBF23Intro:
	.string "FOR AMERICA!$"

SummitCaverns_Text_MagaGruntBF23Defeat:
	.string "RETREAT!$"

SummitCaverns_Text_MagaGruntBF23PostBattle:
	.string "AMERICA WILL HAVE VENGEANCE!$"

SummitCaverns_Text_MagaGruntBF24Intro:
	.string "Unmasked. Unmuzzled. Unafraid.$"

SummitCaverns_Text_MagaGruntBF24Defeat:
	.string "Unmasked. Unmuzzled. Unable to\n"
	.string "breathe...$"

SummitCaverns_Text_MagaGruntBF24PostBattle:
	.string "Unexpected. Underground.$"

SummitCaverns_Text_LattkaChallengesFro:
	.string "Lattka: Well com on then, punk.\n"
	.string "Challenge me if you dare.$"

SummitCaverns_Text_RestUpHere: @ 822A978
	.string "The path ahead looks tough.\n"
	.string "If you'd like, rest up here.$"

SummitCaverns_Text_TakeYourTimeRestUp: @ 822A9EC
	.string "That's right.\n"
	.string "Take your time and rest up!$"
