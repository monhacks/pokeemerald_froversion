VermillionBeach_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermillionBeach_OnFrame
	.byte 0

VermillionBeach_OnFrame::
	map_script_2 VAR_MAGEE_VERSION_INTRO_STATE, 1, VermillionBeach_Eventscript_ProtagRestingOnBeach
	.2byte 0

VermillionBeach_Eventscript_ProtagRestingOnBeach:
	lockall
		msgbox VermillionBeach_Text_ProtagIntroText, MSGBOX_DEFAULT
		closemessage
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
		applymovement 9, Common_Movement_FaceRight
		waitmovement 0
		playmoncry SPECIES_METAGROSS, 2
		waitmoncry
		msgbox VermillionBeach_Text_ProtagIntroText2, MSGBOX_DEFAULT
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
		applymovement 9, Common_Movement_FaceDown
		waitmovement 0
		closemessage
		msgbox VermillionBeach_Text_ProtagIntroText3, MSGBOX_DEFAULT
		closemessage
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
		applymovement 9, Common_Movement_FaceRight
		waitmovement 0
		playmoncry SPECIES_METAGROSS, 2
		waitmoncry
		msgbox VermillionBeach_Text_ProtagIntroText2, MSGBOX_DEFAULT
		removeobject 9
		playfanfare MUS_OBTAIN_ITEM
		waitfanfare
		setflag FLAG_HIDE_BEACH_METAGROSS
	addvar VAR_MAGEE_VERSION_INTRO_STATE, 1 					@@ sets var to 2
	releaseall
	end

VermillionBeach_Eventscript_ShadeWoman::
	lockall
	msgbox VermillionBeach_Text_ShadeWoman, MSGBOX_DEFAULT
	releaseall
	end

VermillionBeach_Eventscript_SumoBoy::
	lockall
	msgbox VermillionBeach_Text_SumoBoy, MSGBOX_DEFAULT
	releaseall
	end

VermillionBeach_Eventscript_SumoGirl::
	lockall
	msgbox VermillionBeach_Text_SumoGirl, MSGBOX_DEFAULT
	releaseall
	end

VermillionBeach_Eventscript_WaterVendor::
	lockall
	msgbox VermillionBeach_Text_WaterVendor, MSGBOX_DEFAULT
	releaseall
	end

VermillionBeach_Eventscript_SeashellScientist::
	lockall
	msgbox VermillionBeach_Text_SeashellScientist, MSGBOX_DEFAULT
	releaseall
	end

VermillionBeach_Eventscript_OldMan::
	lockall
	msgbox VermillionBeach_Text_OldMan, MSGBOX_DEFAULT
	releaseall
	end

VermillionBeach_Eventscript_SwimmerF::
	lockall
	msgbox VermillionBeach_Text_SwimmerF, MSGBOX_DEFAULT
	releaseall
	end

VermillionBeach_Eventscript_SandcastleBoy::
	lockall
	msgbox VermillionBeach_Text_SandcastleBoy, MSGBOX_DEFAULT
	releaseall
	end

VermillionBeach_Eventscript_TreasureHunter1::
	lockall
	msgbox VermillionBeach_Text_TreasureHunter1, MSGBOX_DEFAULT
	releaseall
	end

VermillionBeach_Eventscript_TreasureHunter2::
	lockall
	msgbox VermillionBeach_Text_TreasureHunter2, MSGBOX_DEFAULT
	releaseall
	end


VermillionBeach_Text_ShadeWoman:
.string "Ah, the shade feels like a cool embrace.\n"
.string "I could stay here forever.$"
@--------------------------------------------------
VermillionBeach_Text_SumoBoy:
.string "Sumo time! I'm unbeatable with my mighty\n"
.string "swim ring!$"
@--------------------------------------------------
VermillionBeach_Text_SumoGirl:
.string "Oh no, you won last time. Today is my\n"
.string "revenge match! Get ready!$"
@--------------------------------------------------
VermillionBeach_Text_WaterVendor:
.string "Stay refreshed, folks! Ice-cold water!\n"
.string "Quench your thirst and keep the beach\p"
.string "vibes going. Only a few coins!$"
@--------------------------------------------------
VermillionBeach_Text_SeashellScientist:
.string "Incredible! Look at the intricate patterns\n"
.string "on this shell.\p"
.string "Nature's design never ceases to amaze me.\n"
.string "Have you ever seen such beauty?$"
@--------------------------------------------------
VermillionBeach_Text_OldMan:
.string "Ah, the sea air takes me back. Reminds me\n"
.string "of the good old days.\p"
.string "You know, life's a lot like the ocean...\n"
.string "full of waves, but it's the calm moments\p"
.string "that make it worthwhile.$"
@--------------------------------------------------
VermillionBeach_Text_SwimmerF:
.string "The ocean has a way of washing away\n"
.string "worries, doesn't it? Join me!\p"
.string "The water's perfect, the waves are calling.$"
@--------------------------------------------------
VermillionBeach_Text_SandcastleBoy:
.string "I'm building the greatest sand castle ever!\n"
.string "It's got a moat and everything.\p"
.string "Wanna help me defend it from the incoming\n"
.string "tide?$"
@--------------------------------------------------
VermillionBeach_Text_TreasureHunter1:
.string "Hey, have you seen any shiny stuff in the\n"
.string "sand? I heard sometimes people drop coins\p"
.string "or cool things around here.$"
@--------------------------------------------------
VermillionBeach_Text_TreasureHunter2:
.string "I'm on the lookout. Maybe we'll find some\n"
.string "buried treasure! Last time, I found a\p"
.string "cool seashell. Today, it's all about\n"
.string "the coins!$"
@--------------------------------------------------
VermillionBeach_Text_ProtagIntroText:
	.string "{PLAYER}: It sure is nice relaxing\n"
	.string "at the beach, isn't it Metagross?\p"
	.string "I can't believe it's been over a year\n"
	.string "since we've battled together.$"
@--------------------------------------------------
VermillionBeach_Text_ProtagIntroText2:
	.string "Metagross: Mrraahhh.$"
@--------------------------------------------------
VermillionBeach_Text_ProtagIntroText3:
	.string "{PLAYER}: I know buddy, I miss it\n"
	.string "too.\p"
	.string "But we have a good thing going for us\n"
	.string "here.\p"
	.string "Our dreams have become a reality.\n"
	.string "We finally got to open {COLOR RED}Magee's Pleasure\l"
	.string "Factory{COLOR DARK_GREY}, a place that brings joy to\l"
	.string "both Pokémon and trainers.\p"
	.string "Speaking of that, we should probably\n"
	.string "head back to town and check on\l"
	.string "{COLOR RED}Jennifer{COLOR DARK_GREY}.\p"
	.string "She hates when we leave her to run\n"
	.string "the store while we kick back on the\l"
	.string "beach.\p"
	.string "Let's go buddy!$"

