WalmoreTown_MapScripts::
	.byte 0


// Scripts	


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