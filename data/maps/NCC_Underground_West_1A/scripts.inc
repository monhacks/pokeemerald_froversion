NCC_Underground_West_1A_MapScripts::
	.byte 0

@--------------------------------------------------------------------------------
@-------------------------------------Events-------------------------------------
@--------------------------------------------------------------------------------

NCC_Underground_West_1A_ScientistRhydonBattle::
	@@NOTDONEYET 
	@@ THIS WILL BE AN EVENT WHERE THE PLAYER FIGHTS SHADOW DUGTRIO AND OBTAINS HM STRENGTH REQUIRED FOR PROGRESSING THROUGH DUNGEON
	lockall
		faceplayer
		trainerbattle_single TRAINER_WINSTON_2, NCC_Underground_West_1A_1F_Text_GruntIntro, NCC_Underground_West_1A_1F_Text_GruntDefeat, NCC_Underground_West_1A_ScientistDefeat
		msgbox NCC_Underground_West_1A_1F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

NCC_Underground_West_1A_ScientistDefeat:
		goto_if_set FLAG_RECEIVED_SS_TICKET, NCC_Underground_West_1F_Eventscript_GruntPostBattle
		goto_if_defeated TRAINER_WINSTON_4, NCC_Underground_West_1A_GiveKey
	releaseall
	end

NCC_Underground_West_1A_GiveKey:
		msgbox NCC_Underground_West_1A_1F_Text_GruntPostGiveKey, MSGBOX_AUTOCLOSE
		giveitem ITEM_LAB_KEY, 1
		setflag FLAG_RECEIVED_SS_TICKET
	releaseall
	end

NCC_Underground_West_1A_Eventscript_GruntPostBattle:
		msgbox NCC_Underground_West_1A_1F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	releaseall
	end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

NCC_Underground_West_1A_1F_Text_GruntIntro:
	.string "I am tasked with stopping anyone who\n"
	.string "tries to interfere with our secret\l"
	.string "operation\p"
	.string "You'll be sorry you ever messed with\n"
	.string "me!$"

NCC_Underground_West_1A_1F_Text_GruntDefeat:
	.string "Impossible!$"

NCC_Underground_West_1A_1F_Text_GruntPostBattleGiveStrength:
	.string "Don't hurt me. Take this!$"

NCC_Underground_West_1A_1F_Text_GruntPostBattle:
	.string "The Boss is going to be so mad\n"
	.string "at me.$"

NCC_Underground_West_1A_1F_Text_GruntPostGiveKey:
	.string "I can't stand up to you, please\n"
	.string "take this key and leave me alone.$"
