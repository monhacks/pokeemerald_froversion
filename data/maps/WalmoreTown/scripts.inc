.set LOCALID_AMNEET, 1
.set LOCALID_FREEWOMAN, 2

WalmoreTown_MapScripts::
	.byte 0


// Scripts	

Script_WMT_Signpost_JohnsHouse:
	lock
	msgbox Text_Signpost_WMT_JohnsHouse, MSGBOX_SIGN
	release
	end

Script_WMT_Signpost_BobbysHouse:
	lock
	msgbox Text_Signpost_WMT_BobbysHouse, MSGBOX_SIGN
	release
	end

Script_WalmoreTown_KickDownDoor::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox T_WMT_KickDownDoor, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, WalmoreTown_EventScript_DidntAttemptKick
	case YES, WalmoreTown_EventScript_TooWeakToKick
	case MULTI_B_PRESSED, WalmoreTown_EventScript_DidntAttemptKick
	release
	end

WalmoreTown_EventScript_DidntAttemptKick:
	msgbox T_WMT_DidntAttemptKick, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

WalmoreTown_EventScript_TooWeakToKick:
	msgbox T_WMT_TooWeakToKick, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

Script_WalmoreTown_AmneetIntroductionTrigger1::
	lock
	goto_if_set FLAG_HIDE_WMT_AMNEET, Script_WalmoreTown_AmneetIntroductionDone
	applymovement OBJ_EVENT_ID_PLAYER, M_WMT_MoveForAmneetIntro1
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_0x8000, MUGSHOT_AMNEET
	callnative DrawMugshot
	playbgm MUS_FV_PIMP, 0
	msgbox T_WMT_AmneetIntro, MSGBOX_DEFAULT
	applymovement LOCALID_FREEWOMAN, M_WMT_FreeWomanLeaves
	waitmovement LOCALID_FREEWOMAN
	applymovement LOCALID_AMNEET, Common_Movement_FacePlayer
	waitmovement LOCALID_AMNEET
	msgbox T_WMT_AmneetText2, MSGBOX_DEFAULT
	callnative ClearMugshot
	applymovement LOCALID_AMNEET, M_WMT_AmneetLeaves
	waitmovement LOCALID_AMNEET
	setflag FLAG_HIDE_WMT_AMNEET
	fadedefaultbgm
	release
	end

Script_WalmoreTown_AmneetIntroductionTrigger2::
	lock
	goto_if_set FLAG_HIDE_WMT_AMNEET, Script_WalmoreTown_AmneetIntroductionDone
	applymovement OBJ_EVENT_ID_PLAYER, M_WMT_MoveForAmneetIntro2
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_0x8000, MUGSHOT_AMNEET
	callnative DrawMugshot
	playbgm MUS_FV_PIMP, 0
	msgbox T_WMT_AmneetIntro, MSGBOX_DEFAULT
	applymovement LOCALID_FREEWOMAN, M_WMT_FreeWomanLeaves
	waitmovement LOCALID_FREEWOMAN
	applymovement LOCALID_AMNEET, Common_Movement_FacePlayer
	waitmovement LOCALID_AMNEET
	msgbox T_WMT_AmneetText2, MSGBOX_DEFAULT
	callnative ClearMugshot
	applymovement LOCALID_AMNEET, M_WMT_AmneetLeaves
	waitmovement LOCALID_AMNEET
	setflag FLAG_HIDE_WMT_AMNEET
	fadedefaultbgm
	release
	end

Script_WalmoreTown_AmneetIntroductionTrigger3::
	lock
	goto_if_set FLAG_HIDE_WMT_AMNEET, Script_WalmoreTown_AmneetIntroductionDone
	applymovement OBJ_EVENT_ID_PLAYER, M_WMT_MoveForAmneetIntro3
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_0x8000, MUGSHOT_AMNEET
	callnative DrawMugshot
	playbgm MUS_FV_PIMP, 0
	msgbox T_WMT_AmneetIntro, MSGBOX_DEFAULT
	applymovement LOCALID_FREEWOMAN, M_WMT_FreeWomanLeaves
	waitmovement LOCALID_FREEWOMAN
	applymovement LOCALID_AMNEET, Common_Movement_FacePlayer
	waitmovement LOCALID_AMNEET
	msgbox T_WMT_AmneetText2, MSGBOX_DEFAULT
	callnative ClearMugshot
	closemessage
	applymovement LOCALID_AMNEET, M_WMT_AmneetLeaves
	waitmovement LOCALID_AMNEET
	removeobject LOCALID_FREEWOMAN
	removeobject LOCALID_AMNEET
	setflag FLAG_HIDE_WMT_AMNEET
	fadedefaultbgm
	release
	end

Script_WalmoreTown_AmneetIntroductionDone:
	release
	end


M_WMT_MoveForAmneetIntro1:
	walk_right
	walk_down
	walk_right
	walk_right
	face_up
	step_end

M_WMT_MoveForAmneetIntro2:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

M_WMT_MoveForAmneetIntro3:
	walk_right
	walk_right
	walk_right
	walk_up
	step_end
	
M_WMT_FreeWomanLeaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

M_WMT_AmneetLeaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end



Script_WalmoreTown_IsflagSet::
	lock
	checkflag FLAG_SYS_POKEDEX_GET
	goto_if FALSE, Script_WMT_CantLeave
	release
	end

Script_WMT_CantLeave:
	applymovement 1, M_WMT_NPCstopsPlayer
	waitmovement 1
	msgbox T_WMT_CheckOutTheTown, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, M_WMT_PlayerIsflagSet
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

Script_WMT_WelcomeSign::
lock
msgbox T_WMT_WelcomeSign, MSGBOX_SIGN
release
end

//Movements

M_WMT_NPCstopsPlayer:
emote_exclamation_mark
step_end

M_WMT_PlayerIsflagSet:
walk_left
step_end

//TEXT

T_WMT_CheckOutTheTown:
	.string "{COLOR RED}Hey, why so {COLOR BLUE}quick to pass through \n{COLOR DARK_GREY}town? Take a look around!$"
T_WMT_WelcomeSign:
	.string "Walmore Town. Where friends are made!$"

T_WMT_AmneetIntro:
	.string "Salesman: So would you like 2 watches \n"
	.string "for 10 dollars each, or would you \l"
	.string "prefer 1 watch for 20 dollars and you\l"
	.string "get an additional watch for free?\p"
	.string "Woman: I LIKE THE FREE!!!\p"
	.string "Salesman: Excellent, thank you for \n"
	.string "your patronage. Have a baller day!$"

T_WMT_AmneetText2:
	.string "Salesman: Yo, is that Fro!?\p"
	.string "Sup dude, it's me Amneet!\p"
	.string "Since Pokémon were discovered my \n"
	.string "business has been boomin'! \p"
	.string "I'm a traveling merchant now, so I \n"
	.string "go all around the region selling \l"
	.string "all sorts of stuff.\p"
	.string "In fact I'm on my way to Summit City\n"
	.string "right now, so I can't stay and chat, \l"
	.string "but I hope to see you around!$"

T_WMT_DidntAttemptKick:
	.string "Better not, John would probably get\n"
	.string "grounded again.$"

T_WMT_TooWeakToKick:
	.string "The Door didn't budge. Paul must have\n"
	.string "reinforced the door.$"

T_WMT_KickDownDoor:
	.string "The door is locked. Kick it down?$"

Text_Signpost_WMT_JohnsHouse:	
	.string "Mis Household$"

Text_Signpost_WMT_BobbysHouse:
	.string "Wasula Residence$"
