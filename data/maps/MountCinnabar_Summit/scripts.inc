.set LOCAL_ID_SCIENTIST_1, 2
.set LOCAL_ID_SCIENTIST_2, 3
.set LOCAL_ID_ALLY, 5

MountCinnabar_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MountCinnabar_Summit_OnTransition
	.byte 0

MountCinnabar_Summit_OnTransition:
	removeobject LOCAL_ID_SCIENTIST_1
	removeobject LOCAL_ID_SCIENTIST_2
	setflag FLAG_HIDE_MOUNT_SUMMIT_NCC_SCIENTIST
end


MountCinnabar_Summit_EventScript_ChanseyHeal::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, 0
	setrespawn HEAL_LOCATION_MOUNT_CINNABAR_SUMMIT
	msgbox SummitCaverns_Text_RestUpHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SummitCaverns_EventScript_Rest
	closemessage
	release
	end

MountCinnabar_Summit_ShadowPrimeapeBattle::
	lock
		faceplayer
		waitse
		playmoncry SPECIES_PRIMEAPE, 2
		delay 40
		waitmoncry
		setwildbattle SPECIES_PRIMEAPE, 45, ITEM_NONE
		setflag FLAG_SYS_CTRL_OBJ_DELETE
		setflag FLAG_SYS_NO_CATCHING
		setflag FLAG_CAN_LOSE_NEXT_BATTLE
		special StartPrimeapeBattle
		waitstate
		setflag FLAG_DEFEATED_REGISTEEL
		fadescreenswapbuffers FADE_TO_BLACK
		removeobject VAR_LAST_TALKED
		fadescreenswapbuffers FADE_FROM_BLACK
		setflag FLAG_HIDE_PRIMEAPE
		msgbox MountCinnabar_Summit_Text_PrimeapeDroppedSomething, MSGBOX_DEFAULT
		finditem ITEM_LIFT_KEY
		clearflag FLAG_HIDE_MOUNT_SUMMIT_NCC_SCIENTIST
		clearflag FLAG_SYS_NO_CATCHING
		clearflag FLAG_CAN_LOSE_NEXT_BATTLE
		special HealPlayerParty
		addobject LOCAL_ID_SCIENTIST_1
		addobject LOCAL_ID_SCIENTIST_2
		applymovement LOCAL_ID_SCIENTIST_1, MountCinnabar_Summit_Movement_Scientist1MoveToFro
		applymovement LOCAL_ID_SCIENTIST_2, MountCinnabar_Summit_Movement_Scientist2MoveToFro
		waitmovement LOCAL_ID_SCIENTIST_1
		applymovement LOCAL_ID_SCIENTIST_1, Common_Movement_ExclamationMark
		waitmovement LOCAL_ID_SCIENTIST_1
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
		waitmovement OBJ_EVENT_ID_PLAYER
		msgbox MountCinnabar_Summit_Text_HaveYouSeenAnythingStrange, MSGBOX_DEFAULT
		applymovement LOCAL_ID_SCIENTIST_2, Common_Movement_ExclamationMark
		waitmovement LOCAL_ID_SCIENTIST_2
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
		waitmovement OBJ_EVENT_ID_PLAYER
		msgbox MountCinnabar_Summit_Text_YouSaidTooMuch, MSGBOX_DEFAULT
		applymovement LOCAL_ID_SCIENTIST_1, MountCinnabar_Summit_Movement_Scientist1Leave
		applymovement LOCAL_ID_SCIENTIST_2, MountCinnabar_Summit_Movement_Scientist2Leave
		waitmovement LOCAL_ID_SCIENTIST_2
		removeobject LOCAL_ID_SCIENTIST_1
		removeobject LOCAL_ID_SCIENTIST_2
		addobject LOCAL_ID_ALLY
		applymovement LOCAL_ID_ALLY, MountCinnabar_Summit_Movement_Scientist1MoveToFro
		waitmovement LOCAL_ID_ALLY
		playse SE_PIN
		applymovement LOCAL_ID_ALLY, Common_Movement_ExclamationMark
		waitmovement LOCAL_ID_ALLY
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
		waitmovement OBJ_EVENT_ID_PLAYER
		msgbox MountCinnabar_Summit_Text_NeverTrustedTheNCC, MSGBOX_DEFAULT
		scrollingmultichoice 11, 2, 3, 3, TRUE
		switch VAR_RESULT
		case 0, MountCinnabar_Summit_EventScript_GiveJolteon
		case 1, MountCinnabar_Summit_EventScript_GiveGengar
		case 2, MountCinnabar_Summit_EventScript_GiveEspeon
		case MULTI_B_PRESSED, MountCinnabar_Summit_EventScript_ChooseAPokemon
		setflag FLAG_HIDE_MOUNT_SUMMIT_NCC_SCIENTIST
	release
	end

MountCinnabar_Summit_EventScript_ChooseAPokemon::
	msgbox MountCinnabar_Summit_Text_YouNeedToTakeAPokemon
	scrollingmultichoice 11, 2, 3, 3, TRUE
	switch VAR_RESULT
		case 0, MountCinnabar_Summit_EventScript_GiveJolteon
		case 1, MountCinnabar_Summit_EventScript_GiveGengar
		case 2, MountCinnabar_Summit_EventScript_GiveEspeon
		case MULTI_B_PRESSED, MountCinnabar_Summit_EventScript_ChooseAPokemon
	end

MountCinnabar_Summit_EventScript_GiveJolteon::
		playmoncry SPECIES_JOLTEON, 2
		waitmoncry
		msgbox MountCinnabar_Summit_Text_YouTookJolteon, MSGBOX_DEFAULT
		givecustommon SPECIES_JOLTEON ,50, ITEM_LIFE_ORB, ITEM_ULTRA_BALL, NATURE_TIMID,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_HYPER_VOICE, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_YAWN, 0
		msgbox MountCinnabar_Summit_PostShipwreck_Text_TakeGoodCareOfPokemon, MSGBOX_DEFAULT
		applymovement LOCAL_ID_ALLY, MountCinnabar_Summit_Movement_Scientist1Leave
		waitmovement LOCAL_ID_ALLY
		removeobject LOCAL_ID_ALLY
		setflag FLAG_HIDE_MOUNT_SUMMIT_NCC_SCIENTIST
	releaseall
	end

MountCinnabar_Summit_EventScript_GiveGengar::
		playmoncry SPECIES_GENGAR, 2
		waitmoncry
		msgbox MountCinnabar_Summit_Text_YouTookGengar, MSGBOX_DEFAULT
		givecustommon SPECIES_GENGAR ,50, ITEM_LIFE_ORB, ITEM_ULTRA_BALL, NATURE_TIMID,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_FOCUS_BLAST, MOVE_NASTY_PLOT, MOVE_SHADOW_BALL, MOVE_SLUDGE_WAVE, 0
		msgbox MountCinnabar_Summit_PostShipwreck_Text_TakeGoodCareOfPokemon, MSGBOX_DEFAULT
		applymovement LOCAL_ID_ALLY, MountCinnabar_Summit_Movement_Scientist1Leave
		waitmovement LOCAL_ID_ALLY
		removeobject LOCAL_ID_ALLY
		setflag FLAG_HIDE_MOUNT_SUMMIT_NCC_SCIENTIST
	releaseall
	end

MountCinnabar_Summit_EventScript_GiveEspeon::
		playmoncry SPECIES_ESPEON, 2
		waitmoncry
		msgbox MountCinnabar_Summit_Text_YouTookEspeon, MSGBOX_DEFAULT
		givecustommon SPECIES_ESPEON ,50, ITEM_QUICK_CLAW, ITEM_ULTRA_BALL, NATURE_TIMID,1,150,50,50,50,50,50,15,16,15,16,15,16, MOVE_CALM_MIND, MOVE_MORNING_SUN, MOVE_DAZZLING_GLEAM, MOVE_SHADOW_BALL, 0
		msgbox MountCinnabar_Summit_PostShipwreck_Text_TakeGoodCareOfPokemon, MSGBOX_DEFAULT
		applymovement LOCAL_ID_ALLY, MountCinnabar_Summit_Movement_Scientist1Leave
		waitmovement LOCAL_ID_ALLY
		removeobject LOCAL_ID_ALLY
		setflag FLAG_HIDE_MOUNT_SUMMIT_NCC_SCIENTIST
	releaseall
	end

MountCinnabar_Summit_Movement_Scientist1Leave:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MountCinnabar_Summit_Movement_Scientist2Leave:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MountCinnabar_Summit_Movement_Scientist1MoveToFro:	
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_up
	face_left
	step_end

MountCinnabar_Summit_Movement_Scientist2MoveToFro:	
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end


MountCinnabar_Summit_EventScript_DefeatedPrimeape:
	setflag FLAG_DEFEATED_REGISTEEL
	goto Common_EventScript_RemoveStaticPokemon
	end

MountCinnabar_Summit_EventScript_EscapePlan::
	warp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 54, 54
	end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]''
			 	
MountCinnabar_Summit_Text_PrimeapeDroppedSomething:
	.string "The Primeape fled.\p"
	.string "It seems to have dropped something in\n"
	.string "it's haste.$"

MountCinnabar_Summit_Text_HaveYouSeenAnythingStrange:
	.string "Hey you!\p"
	.string "You haven't happened to see anthing...\n"
	.string "strange around here have you?\p"
	.string "Nothing? You sure?\p"
	.string "Okay then, we need to keep looking for\n"
	.string "Subject 057 before he causes any more\l"
	.string "trouble.\p"
	.string "Oh and let me know if you see a Card\n"
	.string "Key anywhere. I don't want to have to\l"
	.string "tell the Boss I lost it, he will be so\l"
	.string "mad.\p"
	.string "But if I can't find it soon I'll need to\n"
	.string "come clean, otherwise I won't be able to\l"
	.string "do my experiments in the secret\l"
	.string "underground...$"

MountCinnabar_Summit_Text_YouSaidTooMuch:
	.string "Hey! Stop talking! You've said too\n"
	.string "much. We can't let anyone know\l"
	.string "what we're really doing at the NCC.\p"
	.string "You won't say anything about what you\n"
	.string "just heard, right?\p"
	.string "In fact I think you should just forget\n"
	.string "you saw us. Can you do that?\p"
	.string "Thanks pal.\p"
	.string "Now come on, let's get this under\n"
	.string "control quickly.$"

MountCinnabar_Summit_Text_NeverTrustedTheNCC:
	.string "I follwed those Scientists through the\n"
	.string "volcano, but I couldn't keep up.\p"
	.string "I never trusted the Nautic\n"
	.string "communication center, and when I\l"
	.string "saw them sneaking around Mount\l"
	.string "Cinnabar, I knew they were up to\l"
	.string "no good.\p"
	.string "What was wrong with that Pokémon\n"
	.string "you just battled? Do you think\l"
	.string "the NCC is responsible?\p"
	.string "I think so too! I want to help\n"
	.string "find out what they're up to but\l"
	.string "I'm afraid I am not very adept\l"
	.string "when it comes to Pokémon Battling.\p"
	.string "Oh I know, why don't you take one\n"
	.string "of my Pokémon?\p"
	.string "I saw the way you handled yourself,\n"
	.string "you shouldn't have any problem\l"
	.string "getting to the bottom of this.\p"
	.string "Go ahead, take one!$"

MountCinnabar_Summit_PostShipwreck_Text_TakeGoodCareOfPokemon:
	.string "Please, don't let my Pokemon get\n"
	.string "hurt!$"

MountCinnabar_Summit_Text_YouTookJolteon:
	.string "Jolteon was added to your party.$"

MountCinnabar_Summit_Text_YouTookGengar:
	.string "Gengar was added to your party.$"

MountCinnabar_Summit_Text_YouTookEspeon:
	.string "Espeon was added to your party.$"

MountCinnabar_Summit_Text_YouNeedToTakeAPokemon:
	.string "I insist you take a Pokémon. I want\n"
	.string "to help in any way I can.\p"
	.string "Please choose a Pokémon.$"
