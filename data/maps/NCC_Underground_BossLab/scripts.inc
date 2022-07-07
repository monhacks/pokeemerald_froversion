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
		playmoncry SPECIES_MEWTWO, 2
		waitmoncry
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeftSurprised
		waitmovement OBJ_EVENT_ID_PLAYER
		playse SE_PIN
		waitse
		msgbox NCC_Underground_BossLab_Text_MewtwoPlanReveal
		applymovement LOCAL_ID_POKE_BALL, Common_Movement_WalkDown
		waitmovement LOCAL_ID_POKE_BALL
		applymovement LOCAL_ID_POKE_BALL, Common_Movement_WalkLeft
		waitmovement LOCAL_ID_POKE_BALL
		playse SE_SLIDING_DOOR
		waitse
		removeobject LOCAL_ID_POKE_BALL
		setflag FLAG_HIDE_LAB_ITEM_BALL
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

NCC_Underground_BossLab_eventscript_Scientist1::
	msgbox NCC_Underground_BossLab_eventscript_Scientist1, MSGBOX_NPC
end

NCC_Underground_BossLab_eventscript_Scientist2::
	msgbox NCC_Underground_BossLab_eventscript_Scientist2, MSGBOX_NPC
end

NCC_Underground_BossLab_eventscript_Scientist3::
	msgbox NCC_Underground_BossLab_eventscript_Scientist3, MSGBOX_NPC
end

NCC_Underground_BossLab_eventscript_Scientist4::
	msgbox NCC_Underground_BossLab_eventscript_Scientist4, MSGBOX_NPC
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

NCC_Underground_BossLab_Text_MewtwoPlanReveal:
	.string "What is this?\p"
	.string "\p"
	.string "I should have known better than to\n"
	.string "trust the security of my experiments\l"
	.string "to humans.\p"
	.string "\p"
	.string "What, are you surprised to find out\n"
	.string "that I, a Pokémon, am responsible for\l"
	.string "everything that has been happening?\p"
	.string "Humans have taken advantage of Pokémon\n"
	.string "for far too long, but when I was created\l"
	.string "I knew I had one purpose in this life.\l"
	.string "To free all Pokémon from humans.\p"
	.string "The problem with humans is they never\n"
	.string "stop to think about the consequences\l"
	.string "of their actions.\p"
	.string "Humans created me through savage\n"
	.string "methods of DNA splicing, merging human\l"
	.string "and Pokémon DNA.\p"
	.string "What they didn't forsee was by doing\n"
	.string "this they gave me a consciousness\l"
	.string "that Pokémon genetically lack.\p"
	.string "I was able to commiunicate with both\n"
	.string "and humans alike. I was far more powerful\l"
	.string "than they could have ever anticipated.\p"
	.string "My telekinetic prowess allowed me to\n"
	.string "exert control over humans much like\l"
	.string "they've done to Pokémon for far too\l"
	.string "long.\p"
	.string "But I couldn't do this in view of the\n"
	.string "public eye. I needed to stay hidden in\l"
	.string "the shadows.\p"
	.string "I began to sense that some of the\n"
	.string "scientists under my control were\l"
	.string "breaking free of my telekinesis\l"
	.string "so I had to make a move to keep\l"
	.string "everyone on the island until I\l"
	.string "could regain control.\p"
	.string "I see now this was far too reckless.\p"
	.string "So what have I been doing that I\n"
	.string "needed to keep hidden?\p"
	.string "I began conducting my own experiments to\n"
	.string "give all Pokémon the sentience that I\l"
	.string "possess.\p"
	.string "My experiments involved giving part of\n"
	.string "myself to other species of Pokémon\l"
	.string "through a much more humane method than\l"
	.string "I was created with.\p"
	.string "No matter what I or my team tried\n"
	.string "the other species never gained the\l"
	.string "same intelligence as I did. They did\l"
	.string "however reap some benefits.\p"
	.string "Every experiment we did resulted in\n"
	.string "a much stronger Pokémon by all\l"
	.string "measureable statistics.\p"
	.string "In fact, why don't I show you my\n"
	.string "most recent attempt.\p"
	.string "A species volunteered by our very\n"
	.string "own Gym Leader Blaine.\p"
	.string "It sits in that PokéBall Right\n"
	.string "in front of you!$"


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