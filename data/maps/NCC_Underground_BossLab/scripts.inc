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
	compare VAR_ROUTE101_STATE, 7
	goto_if_lt  NCC_Underground_BossLab_OnLoad_ShowItemBall
	end

NCC_Underground_BossLab_OnLoad_ShowItemBall:
	special HealPlayerParty
	clearflag FLAG_HIDE_LAB_ITEM_BALL
	addobject LOCAL_ID_POKE_BALL
	end

NCC_Underground_BossLab_BossBattleInitiate::
	lockall
		goto NCC_Underground_BossLab_BossBattleStart
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
		playmoncry SPECIES_MEWTWO, 2
		waitmoncry
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeftSurprised
		waitmovement OBJ_EVENT_ID_PLAYER
		playse SE_PIN
		waitse
		msgbox NCC_Underground_BossLab_Text_MagaScientistReveal
		applymovement LOCAL_ID_POKE_BALL, Common_Movement_WalkDown
		waitmovement LOCAL_ID_POKE_BALL
		applymovement LOCAL_ID_POKE_BALL, Common_Movement_WalkLeft
		waitmovement LOCAL_ID_POKE_BALL
		playse SE_SLIDING_DOOR
		waitse
		removeobject LOCAL_ID_POKE_BALL
		setflag FLAG_HIDE_LAB_ITEM_BALL
	NCC_Underground_BossLab_BossBattleStart:
		msgbox StartBattle, MSGBOX_YESNO
		compare VAR_RESULT, FALSE
		goto_if_eq NCC_Underground_BossLab_Release
		@@trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_2, NCC_Underground_BossLab_Text_MewtwoDefeat
		trainerbattle_no_intro TRAINER_WINSTON_5, NCC_Underground_BossLab_Text_MewtwoDefeat
		playbgm MUS_HALL_OF_FAME_ROOM, 0
		msgbox NCC_Underground_BossLab_Text_MewtwoPostBattle, MSGBOX_DEFAULT
		fadescreen FADE_TO_BLACK
		removeobject LOCAL_ID_MEWTWO
		removeobject LOCAL_ID_SCIENTIST_2
		removeobject LOCAL_ID_SCIENTIST_3
		removeobject LOCAL_ID_SCIENTIST_4
		removeobject LOCAL_ID_SCIENTIST_5
		setflag FLAG_HIDE_NCC_LAB_MEWTWO
		setflag FLAG_HIDE_NCC_LAB_SCIENTIST
		setvar VAR_ROUTE101_STATE, 7
		warpsilent MAP_CINNIBAR_ISLAND, 255, 62, 53
	NCC_Underground_BossLab_Release:
	releaseall
	end

NCC_Underground_BossLab_Mewtwo::
	lock
		msgbox NCC_Underground_BossLab_Text_MagaScientistReveal, MSGBOX_DEFAULT
		trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_2, SummitCaverns_Text_LattkaDefeat2
		msgbox SummitCaverns_Text_PostLattkaBattle, MSGBOX_DEFAULT
	release
	end

NCC_Underground_BossLab_eventscript_Scientist1::
	msgbox NCC_Underground_BossLab_Text_Scientist1, MSGBOX_NPC
end

NCC_Underground_BossLab_eventscript_Scientist2::
	msgbox NCC_Underground_BossLab_Text_Scientist2, MSGBOX_NPC
end

NCC_Underground_BossLab_eventscript_Scientist3::
	msgbox NCC_Underground_BossLab_Text_Scientist3, MSGBOX_NPC
end

NCC_Underground_BossLab_eventscript_Scientist4::
	msgbox NCC_Underground_BossLab_Text_Scientist4, MSGBOX_NPC
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

NCC_Underground_BossLab_Text_DontTouchThat:
	.string "Hey, you can't touch that!\p"
	.string "That is our newest experiment the\n"
	.string "Boss does not want anyone, even\l"
	.string "trained scientists touching it!\p"
	.string "You better get away, the Boss won't\n"
	.string "only have your head, but mine too\l"
	.string "if he sees you touching that!$"

NCC_Underground_BossLab_Text_MagaScientistReveal:
	.string "What is this?\p"
	.string "\p"
	.string "I should have expected someone to\n"
	.string "discover my experiments eventually.\p"
	.string "\p"
	.string "Surprised? It is I, a MAGA Scientist,\n"
	.string "responsible for all you've seen here.\p"
	.string "My goal is simple: to create the\n"
	.string "ultimate Pokémon, one beyond limits.\p"
	.string "For years, we have worked to push\n"
	.string "the boundaries of Pokémon potential.\p"
	.string "Using advanced DNA manipulation, we\n"
	.string "aim to forge a new evolutionary\l"
	.string "path.\p"
	.string "Our methods? Ruthless but necessary.\n"
	.string "Greatness demands sacrifice and\l"
	.string "vision.\p"
	.string "You see, normal evolution is too slow.\n"
	.string "Science can expedite what nature\l"
	.string "takes centuries to achieve.\p"
	.string "By blending genes of powerful species,\n"
	.string "we unlock untapped power and skill.\p"
	.string "However, controlling these creations\n"
	.string "requires precision only I can offer.\p"
	.string "Some experiments failed, but others\n"
	.string "produced extraordinary results.\p"
	.string "Our latest success is before you now.\n"
	.string "A Pokémon that defies all limits.\p"
	.string "Blaine, our Gym Leader, provided the\n"
	.string "species. It exceeded all expectations.\p"
	.string "In that PokéBall lies the pinnacle of\n"
	.string "my research. Are you ready to face it?$"


NCC_Underground_BossLab_Text_Scientist1:
	.string "Why are you not wearing a lab coat?!\n"
	.string "We are working with mutagenic material\l"
	.string "here, leave now!$"

NCC_Underground_BossLab_Text_Scientist2:
	.string "You grunts are not supposed to be here.\n"
	.string "Go get me a coffee and get lost!$"

NCC_Underground_BossLab_Text_Scientist3:
	.string "I have no intent to care about your\n"
	.string "presence. My work is way to important.$"

NCC_Underground_BossLab_Text_Scientist4:
	.string "How the hell did you get in here?! If\n"
	.string "only the security could do their job!$"

NCC_Underground_BossLab_Text_MewtwoDefeat:
	.string "No...\p"
	.string "This can't be...$"

NCC_Underground_BossLab_Text_MewtwoPostBattle:
	.string "All my time... my research...\p"
	.string "And you've destroyed it all...\p"
	.string "You will pay for this. Mark my words.\n"
	.string "But I have no Pokémon left in battle\l"
	.string "condition.\p"
	.string "I am not going to waste my energy and\n"
	.string "fight you myself...\p"
	.string "Enjoy your victory, but this isn't\n"
	.string "over.$"

StartBattle:
	.string "Are you ready to test this boss\n"
	.string "battle for Camgotay?$"