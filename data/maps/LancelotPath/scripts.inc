LancelotPath_MapScripts::
	.byte 0

///////////////////////////////////////
////////////////TRAINERS///////////////
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
	//goto_if_unset FLAG_SPOKE_TO_FIRST_MESSENGER, EventScript_General_MessengerIntro
	trainerbattle_single TRAINER_MESSENGER_1, LancelotPath_Text_Messenger1, LancelotPath_Text_Messenger1Defeated
	msgbox LancelotPath_Text_Messenger1Defeated, MSGBOX_AUTOCLOSE
	end
