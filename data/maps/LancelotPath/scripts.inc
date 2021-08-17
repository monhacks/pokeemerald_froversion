LancelotPath_MapScripts::
	.byte 0

.set LOCALID_MANIAC, 19

LancelotPath_EventScript_CaveCheck::
goto_if_unset FLAG_BADGE02_GET, LancelotPath_EventScript_CavesDangerous
release
end

LancelotPath_EventScript_CavesDangerous:
lock
applymovement LOCALID_MANIAC, LP_M_ManiacFacePlayer
waitmovement LOCALID_MANIAC
msgbox LP_T_CavesDangerous, MSGBOX_NPC
applymovement OBJ_EVENT_ID_PLAYER, LP_M_PlayerStepBack
waitmovement OBJ_EVENT_ID_PLAYER
release
end


///////////////////////////////////////
////////////////MOVEMENTS/////////////
//////////////////////////////////////

LP_M_ManiacFacePlayer:
face_left
emote_exclamation_mark
step_end

LP_M_PlayerStepBack:
walk_fast_down
step_end



///////////////////////////////////////
////////////////Trainers///////////////
//////////////////////////////////////


EventScript_General_MessengerIntro:
	setflag FLAG_SPOKE_TO_FIRST_MESSENGER
	msgbox GeneralTrainer_Text_MessengerIntro, MSGBOX_NPC
	trainerbattle_single TRAINER_MESSENGER_1, LancelotPath_Text_Messenger1, LancelotPath_Text_Messenger1Defeated
	msgbox LancelotPath_Text_Messenger1Defeated, MSGBOX_AUTOCLOSE
	end



LancelotPath_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, LancelotPath_Text_CalvinIntro, LancelotPath_Text_CalvinDefeated
	msgbox LancelotPath_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

LancelotPath_EventScript_Messenger::
	goto_if_unset FLAG_SPOKE_TO_FIRST_MESSENGER, EventScript_General_MessengerIntro
	trainerbattle_single TRAINER_MESSENGER_1, LancelotPath_Text_Messenger1, LancelotPath_Text_Messenger1Defeated
	msgbox LancelotPath_Text_Messenger1Defeated, MSGBOX_AUTOCLOSE
	end

LancelotPath_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_AUTOCLOSE
	release
	end

LancelotPath_EventScript_Haley::
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
	release
	end


LancelotPath_EventScript_Maniac::
	lock
	goto_if_unset FLAG_BADGE02_GET, LancelotPath_EventScript_CavesDangerousDialouge
	msgbox LP_T_PLACEHOLDER, MSGBOX_NPC
	release
	end

LancelotPath_EventScript_CavesDangerousDialouge:
	msgbox LP_T_CavesDangerous, MSGBOX_NPC
	release
	end

///////////////////////////////////////
////////////////SIGNPOSTS/////////////
//////////////////////////////////////

LancelotPath_Signpost_ColangeloGraphics::
	msgbox LP_T_ColangeloGraphics, MSGBOX_SIGN
	release
	end

///////////////////////////////////////
////////////////TEXTS/////////////////
/////////////////////////////////////

LP_T_ColangeloGraphics:
	.string "Colangelo Graphics$"

LP_T_CavesDangerous:
	.string "These caves aren't safe right now!$"

LP_T_PLACEHOLDER:
	.string "Placeholder!$"