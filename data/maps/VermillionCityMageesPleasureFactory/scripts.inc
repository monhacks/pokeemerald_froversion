.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_GRUNT_3, 3
.set LOCALID_JENNIFER, 4
.set LOCALID_POKEBALL, 5

VermillionCityMageesPleasureFactory_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermillionCityMageesPleasureFactory_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, VermillionCityMageesPleasureFactory_OnLoad
	.byte 0

VermillionCityMageesPleasureFactory_OnFrame:
	map_script_2 VAR_MAGEE_VERSION, 0, VermillionCityMageesPleasureFactory_EventScript_EscortMageeToOffice
	map_script_2 VAR_MAGEE_VERSION, 2, VermillionCityMageesPleasureFactory_EventScript_JenniferTellsMageeMetagrossIsGone
	.2byte 0

VermillionCityMageesPleasureFactory_OnLoad:
	call_if_set FLAG_OPENED_HIDDEN_DOOR_MAGEES_PLEASURE_FACTORY, VermillionCityMageesPleasureFactory_EventScript_RevealHiddenStaircaseOnLoad
	compare VAR_MAGEE_VERSION, 2
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_ChangeJenniferXY
	end



VermillionCityMageesPleasureFactory_EventScript_EscortMageeToOffice:
	lockall
		playbgm MUS_FV_TEAM_MAGA, 0
		addobject LOCALID_GRUNT_1
		addobject LOCALID_GRUNT_2
		addobject LOCALID_GRUNT_3
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
		waitmovement OBJ_EVENT_ID_PLAYER
		applymovement OBJ_EVENT_ID_PLAYER, VermillionCityMageesPleasureFactory_Movement_MageeWalksToGrunts
		waitmovement OBJ_EVENT_ID_PLAYER
		msgbox VermillionCityMageesPleasureFactory_Text_WhatsGoingOnHere, MSGBOX_AUTOCLOSE
		applymovement OBJ_EVENT_ID_PLAYER, VermillionCityMageesPleasureFactory_Movement_MageeWalksToRegister
		waitmovement OBJ_EVENT_ID_PLAYER
		addobject LOCALID_POKEBALL
		playse SE_WALL_HIT
		waitse
		applymovement OBJ_EVENT_ID_PLAYER, VermillionCityMageesPleasureFactory_Movement_MageeWalksBackFromRegister
		waitmovement OBJ_EVENT_ID_PLAYER
		msgbox VermillionCityMageesPleasureFactory_Text_LetsGo, MSGBOX_AUTOCLOSE
		applymovement LOCALID_GRUNT_2, VermillionCityMageesPleasureFactory_Movement_WalkToOffice
		applymovement LOCALID_GRUNT_3, VermillionCityMageesPleasureFactory_Movement_WalkToOffice
		applymovement OBJ_EVENT_ID_PLAYER, VermillionCityMageesPleasureFactory_Movement_WalkToOffice
		waitmovement OBJ_EVENT_ID_PLAYER
		removeobject LOCALID_GRUNT_2
		removeobject LOCALID_GRUNT_3
		setvar VAR_MAGEE_VERSION, 1
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
		waitmovement OBJ_EVENT_ID_PLAYER
		warp MAP_VERMILLION_CITY_MAGEES_PLEASURE_FACTORY_OFFICE, 255, 6, 6
	releaseall
	end

VermillionCityMageesPleasureFactory_EventScript_JenniferTellsMageeMetagrossIsGone:
	lockall
		getplayerxy VAR_TEMP_0, VAR_TEMP_1
		compare VAR_TEMP_0, 8
		call_if_eq VermillionCityMageesPleasureFactory_EventScript_MoveJenniferToMattXPosition8
		call_if_ne VermillionCityMageesPleasureFactory_EventScript_MoveJenniferToMattXPosition9
		waitmovement LOCALID_JENNIFER
		applymovement LOCALID_JENNIFER, Common_Movement_ExclamationMark
		waitmovement LOCALID_JENNIFER
		msgbox VermillionCityMageesPleasureFactory_Text_JenniferTellsMageeMetagrossIsGone, MSGBOX_AUTOCLOSE
		setvar VAR_MAGEE_VERSION, 3
		releaseall
	end

VermillionCityMageesPleasureFactory_EventScript_ChangeJenniferXY:
		setobjectxyperm LOCALID_JENNIFER, 9, 8
	end

VermillionCityMageesPleasureFactory_EventScript_MoveJenniferToMattXPosition8:
		applymovement LOCALID_JENNIFER, VermillionCityMageesPleasureFactory_Movement_JenniferWalkToMattXPosition8
		waitmovement LOCALID_JENNIFER
	return

VermillionCityMageesPleasureFactory_EventScript_MoveJenniferToMattXPosition9:
		applymovement LOCALID_JENNIFER, VermillionCityMageesPleasureFactory_Movement_JenniferWalkToMattXPosition9
		waitmovement LOCALID_JENNIFER
	return

VermillionCityMageesPleasureFactory_EventScript_RevealHiddenStaircase:
		msgbox VermillionCityMageesPleasureFactory_Text_RevelHiddenStaircase, MSGBOX_AUTOCLOSE
		setmetatile 22, 0, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorTopLeft , 1
		setmetatile 23, 0, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorTopMiddle , 1
		setmetatile 24, 0, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorTopRight , 1
		setmetatile 22, 1, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorMiddleLeft , 1
		setmetatile 23, 1, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorMiddle , 0
		setmetatile 24, 1, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorMiddleRight , 1
		setmetatile 22, 2, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorBottomLeft , 0
		setmetatile 24, 2, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorBottomRight , 0
		special DrawWholeMapView
		setflag FLAG_OPENED_HIDDEN_DOOR_MAGEES_PLEASURE_FACTORY
		setvar VAR_MAGEE_VERSION, 9
	releaseall
	end

VermillionCityMageesPleasureFactory_EventScript_RevealHiddenStaircaseOnLoad:
		setmetatile 22, 0, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorTopLeft , 1
		setmetatile 23, 0, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorTopMiddle , 1
		setmetatile 24, 0, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorTopRight , 1
		setmetatile 22, 1, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorMiddleLeft , 1
		setmetatile 23, 1, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorMiddle , 0
		setmetatile 24, 1, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorMiddleRight , 1
		setmetatile 22, 2, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorBottomLeft , 0
		setmetatile 24, 2, METATILE_SummitCityGym_SummitCity_Gym_HiddenDoorBottomRight , 0
	return

VermillionCityMageesPleasureFactory_EventScript_Jennifer::
	lockall
		goto_if_unset FLAG_RECEIVED_BIKE, VermillionCityMageesPleasureFactory_EventScript_JenniferNPC
		goto_if_unset FLAG_DEFEATED_SHADOW_CHARIZARD, VermillionCityMageesPleasureFactory_EventScript_JenniferNPC
		goto_if_set FLAG_OPENED_HIDDEN_DOOR_MAGEES_PLEASURE_FACTORY, VermillionCityMageesPleasureFactory_EventScript_JenniferNPC
		goto_if_set FLAG_TALKED_TO_JEN_AFTER_BEATING_BOSSES, VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart
		msgbox VermillionCityMageesPleasureFactory_Text_FoundThisCode, MSGBOX_AUTOCLOSE
		setflag FLAG_TALKED_TO_JEN_AFTER_BEATING_BOSSES
VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart:
		msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
		scrollingmultichoice 7, 2, 3, 5, TRUE
		compare VAR_RESULT, 1
		goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer1
		msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
		scrollingmultichoice 7, 2, 3, 5, TRUE
		msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
		scrollingmultichoice 7, 2, 3, 5, TRUE
		msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
		scrollingmultichoice 7, 2, 3, 5, TRUE
		msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
		scrollingmultichoice 7, 2, 3, 5, TRUE
		msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
		scrollingmultichoice 7, 2, 3, 5, TRUE
		msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
		scrollingmultichoice 7, 2, 3, 5, TRUE
		msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
		scrollingmultichoice 7, 2, 3, 5, TRUE
		msgbox VermillionCityMageesPleasureFactory_Text_EightNumberComboRequiredWrongSolution, MSGBOX_YESNO
		compare VAR_RESULT, YES
		goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart
	release
	end
		
VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer1:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 2
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer2
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_EightNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart
	release
	end

VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer2:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 6
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer3
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_EightNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart
	release
	end

VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer3:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 5
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer4
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_EightNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart
	release
	end

VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer4:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 4
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer5
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_EightNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart
	release
	end

VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer5:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 8
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer6
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_EightNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart
	release
	end

VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer6:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 2
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer7
	msgbox VermillionCityMageesPleasureFactory_Text_WhatsTheCode, MSGBOX_DEFAULT
	scrollingmultichoice 7, 2, 3, 5, TRUE
	msgbox VermillionCityMageesPleasureFactory_Text_EightNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart
	release
	end

VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayCorrectAnswer7:
	scrollingmultichoice 7, 2, 3, 5, TRUE
	compare VAR_RESULT, 2
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_RevealHiddenStaircase
	msgbox VermillionCityMageesPleasureFactory_Text_EightNumberComboRequiredWrongSolution, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermillionCityMageesPleasureFactory_EventScript_SecretDoorwayRiddleStart
	release
	end


VermillionCityMageesPleasureFactory_EventScript_JenniferNPC:
		compare VAR_MAGEE_VERSION, 8
		goto_if_le VermillionCityMageesPleasureFactory_EventScript_JenniferCantBelieveThisIsHappening
		msgbox VermillionCityMageesPleasureFactory_Text_YouBetterGoStopThem, MSGBOX_AUTOCLOSE
	releaseall
	end

VermillionCityMageesPleasureFactory_EventScript_JenniferCantBelieveThisIsHappening:
		msgbox VermillionCityMageesPleasureFactory_Text_CantBelieveThisIsHappening, MSGBOX_AUTOCLOSE
	releaseall
	end




VermillionCityMageesPleasureFactory_Movement_MageeWalksToGrunts:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VermillionCityMageesPleasureFactory_Movement_MageeWalksToRegister:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

VermillionCityMageesPleasureFactory_Movement_MageeWalksBackFromRegister:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

VermillionCityMageesPleasureFactory_Movement_WalkToOffice:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VermillionCityMageesPleasureFactory_Movement_JenniferWalkToMattXPosition8:	
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

VermillionCityMageesPleasureFactory_Movement_JenniferWalkToMattXPosition9:	
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


VermillionCityMageesPleasureFactory_Text_WhatsGoingOnHere:
	.string "{PLAYER}: What's going on here?\p"
	.string "MAGA Grunt: Mr. Magee, the boss isn't\n"
	.string "happy.\p"
	.string "We need to have a little talk. Let's\n"
	.string "go to your office.\p"
	.string "{PLAYER}: We can talk right here!\p"
	.string "MAGA Grunt: Oh I don't think that\n"
	.string "would be wise.\p"
	.string "I won't ask nicely again. We don't\n"
	.string "want anyone to get hurt, do we?\p"
	.string "{PLAYER}: Fine, fine. We can go\n"
	.string "to the office.\p"
	.string "MAGA Grunt: Good, and one more\n"
	.string "thing, leave your Pokémon with\l"
	.string "the girl, we don't want any funny\l"
	.string "business.$"

VermillionCityMageesPleasureFactory_Text_LetsGo:
	.string "MAGA Grunt: Great, let's get to it\n"
	.string "then.$"

VermillionCityMageesPleasureFactory_Text_JenniferTellsMageeMetagrossIsGone:
	.string "Jennifer: Matt! They took Metagross!\n"
	.string "I tried to stop them-\p"
	.string "Matt: I know, I need to go after\n"
	.string "them and get him back, which way\l"
	.string "did they go?\p"
	.string "Jennifer: They went outside and\n"
	.string "headed south!\p"
	.string "Matt: I can't believe this. Stay\n"
	.string "here-I'm going after them.\p"
	.string "Jennifer: Matt, wait! What if you get\n"
	.string "hurt?\p"
	.string "Matt: They're not getting away with\n"
	.string "this, Jen.\p"
	.string "Just stay put and call someone if I'm\n"
	.string "not back soon.$"

VermillionCityMageesPleasureFactory_Text_CantBelieveThisIsHappening:
	.string "Jennifer: I can't believe this\n"
	.string "is happening.$"

VermillionCityMageesPleasureFactory_Text_FoundThisCode:
	.string "Jennifer: Oh {PLAYER}, you're back!\p"
	.string "{PLAYER}: Yes, and I found out team\n"
	.string "MAGA has been using our store to\l"
	.string "secretly run experiments on Pokémon.\p"
	.string "I have this code. Can you enter it\n"
	.string "on the register for me?$"

VermillionCityMageesPleasureFactory_Text_WhatsTheCode:
	.string "Jennifer: Sure {PLAYER}, what's the\n"
	.string "code?$"

VermillionCityMageesPleasureFactory_Text_EightNumberComboRequiredWrongSolution:
	.string "Jennifer: That didn't work.\p"
	.string "Do you want me to try again?$"

VermillionCityMageesPleasureFactory_Text_RevelHiddenStaircase:
	.string "Jennifer: Something is happening.\p"
	.string "It says “Secret Doorway Open”.\p"
	.string "Oh I see it! It's in the back!\n"
	.string "You should go stop them, but be\l"
	.string "careful!$"

VermillionCityMageesPleasureFactory_Text_YouBetterGoStopThem:
	.string "You should go stop them, but be\n"
	.string "careful!$"
