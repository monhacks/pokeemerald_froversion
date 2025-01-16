.set LOCALID_JENNIFER, 1
.set LOCALID_NURSE, 2

VermillionCityMattsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermillionCityMattsHouse_OnFrame
	.byte 0

VermillionCityMattsHouse_OnFrame:
	map_script_2 VAR_MAGEE_VERSION, 4, VermillionCityMattsHouse_EventScript_WildPokemonKnockedYouOut
	.2byte 0

VermillionCityMattsHouse_EventScript_WildPokemonKnockedYouOut:
	lockall
		msgbox VermillionCityMattsHouse_Text_WakingUp, MSGBOX_DEFAULT
		applymovement LOCALID_JENNIFER, Common_Movement_ExclamationMark
		applymovement LOCALID_NURSE, Common_Movement_ExclamationMark
		waitmovement LOCALID_NURSE
		msgbox VermillionCityMattsHouse_Text_WildPokemonKnockedYouOut, MSGBOX_DEFAULT
		applymovement LOCALID_JENNIFER, VermillionCityMattsHouse_Movement_JenniferLeaves
		applymovement LOCALID_NURSE, VermillionCityMattsHouse_Movement_NurseLeaves
		waitmovement LOCALID_NURSE
		removeobject LOCALID_NURSE
		removeobject LOCALID_JENNIFER
		setflag FLAG_HIDE_MATTS_HOUSE_NPCS
		setvar VAR_MAGEE_VERSION, 5
		releaseall
		end

VermillionCityMattsHouse_Movement_JenniferLeaves:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

VermillionCityMattsHouse_Movement_NurseLeaves:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

VermillionCityMattsHouse_Text_WakingUp:
	.string "...\p"
	.string "...\p"
	.string "{PLAYER}: What...\p"
	.string "What happened...?$"

VermillionCityMattsHouse_Text_WildPokemonKnockedYouOut:
	.string "Jennifer: Oh good {PLAYER}, you're\n"
	.string "awake! I was so worried!\p"
	.string "Nurse: What were you thinking running\n"
	.string "into the tall grass without a\l"
	.string "Pokémon?\p"
	.string "{PLAYER}: What are you talking about?\p"
	.string "Jennifer: You chased after Team MAGA\n"
	.string "after they stole Metagross, don't\l"
	.string "you remember?\p"
	.string "{PLAYER}: Those dirty Team MAGA theifs!\n"
	.string "Yes, I almost caught them but\l"
	.string "a wild Pokémon got in my way!\p"
	.string "Nurse: Yes Jen found you knocked\n"
	.string "out cold!\p"
	.string "You need to be more careful! You could\n"
	.string "have been seriously hurt!\p"
	.string "You're lucky she was able to carry\n"
	.string "you back here to me so quickly, or\l"
	.string "things may have been a lot worse!\p"
	.string "{PLAYER}: Thank you for helping me\n"
	.string "but I need to get back and find\l"
	.string "Metagross. They were talking about\l"
	.string "doing experiments on him.\p"
	.string "I don't think I have much time!\p"
	.string "Nurse: You will NOT go back without\n"
	.string "A Pokémon to protect you!\p"
	.string "Jennifer: She's right {PLAYER}, it's\n"
	.string "just too dangerous.\p"
	.string "You should go talk to Tommy, the\n"
	.string "owner of the fruit stand in the\l"
	.string "Market.\p"
	.string "I heard through the grapevines that\n"
	.string "he has been looking for someone\l"
	.string "to take over training of one\l"
	.string "of his Pokémon.\p"
	.string "{PLAYER}: Okay, fine. I will go talk to\n"
	.string "Tommy before I go after Team MAGA.\p"
	.string "Nurse: Please be careful! I have to\n"
	.string "get back to the Pokémon Center, but\l"
	.string "you seem to be fully recovered.\p"
	.string "Jennifer: I'll keep an eye on\n"
	.string "The Pleasure Factory while you're\l"
	.string "gone. Be safe!$"
