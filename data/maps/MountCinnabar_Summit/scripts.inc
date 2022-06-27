.set LOCAL_ID_SCIENTIST_1, 2
.set LOCAL_ID_SCIENTIST_2, 3

MountCinnabar_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MountCinnabar_Summit_OnTransition
	.byte 0

MountCinnabar_Summit_OnTransition:
	removeobject LOCAL_ID_SCIENTIST_1
	removeobject LOCAL_ID_SCIENTIST_2
	setflag FLAG_HIDE_MOUNT_SUMMIT_NCC_SCIENTIST
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
		setflag FLAG_HIDE_MOUNT_SUMMIT_NCC_SCIENTIST
	release
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
	.string "The Primeape Fled.\p"
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
	.string "But if I can't find it soon I'll need\n"
	.string "come clean, otherwise I won't be able\l"
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
