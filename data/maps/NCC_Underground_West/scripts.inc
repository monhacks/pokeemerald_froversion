NCC_Underground_West_MapScripts::
	.byte 0


@--------------------------------------------------------------------------------
@-------------------------------------Events-------------------------------------
@--------------------------------------------------------------------------------

NCC_Underground_West_ScientistDugtrioBattle::
	@@NOTDONEYET 
	@@ THIS WILL BE AN EVENT WHERE THE PLAYER FIGHTS SHADOW DUGTRIO AND OBTAINS HM STRENGTH REQUIRED FOR PROGRESSING THROUGH DUNGEON
	lockall
		faceplayer
		trainerbattle_single TRAINER_WINSTON_3, NCC_Underground_West_1F_Text_GruntIntro, NCC_Underground_West_1F_Text_GruntDefeat, NCC_Underground_West_ScientistDefeat
		msgbox NCC_Underground_West_1F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

NCC_Underground_West_ScientistDefeat:
	msgbox NCC_Underground_West_1F_Text_GruntPostBattleGiveStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM04, 1
	setflag FLAG_BADGE04_GET
releaseall
end

NCC_Underground_West_LockedDoorCheck::
	lockall
		goto_if_unset FLAG_RECEIVED_SS_TICKET, NCC_Underground_West_NoKey
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
		waitmovement OBJ_EVENT_ID_PLAYER
		msgbox NCC_Underground_West_1F_Text_KeyUnlocksDoor, MSGBOX_AUTOCLOSE
		opendoor 13, 27
		setvar VAR_NCC_UNDERGROUND_STATE, 1
		waitdooranim
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
		waitmovement OBJ_EVENT_ID_PLAYER
		hideobjectat OBJ_EVENT_ID_PLAYER, 0
		closedoor 13 27
		waitdooranim
		warp MAP_NCC_UNDERGROUND_BOSS_LAB, 0, 6, 12
		waitstate
	releaseall
	end




NCC_Underground_West_NoKey::
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
		waitmovement OBJ_EVENT_ID_PLAYER
		msgbox NCC_Underground_West_1F_Text_ThisDoorIsLocked, MSGBOX_AUTOCLOSE
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
		waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end
	

NCC_Underground_west_EventScript_HazeTutor:: @ 82C81EE
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_HAZE, PorygonTutor_EventScript_HazeTaught
	msgbox PorygonTutor_Text_HazeTeach, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_HazeDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	compare VAR_RESULT, NO
	goto_if_eq MoveTutor_EventScript_HazeDeclined
	msgbox PorygonTutor_Text_HazeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_HAZE
	call MoveTutor_EventScript_OpenPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq MoveTutor_EventScript_HazeDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_HAZE
	goto PorygonTutor_EventScript_HazeTaught
	end

MoveTutor_EventScript_HazeDeclined:: @ 82C8242
	msgbox MoveTutor_Text_HazeDeclined, MSGBOX_DEFAULT
	release
	end

PorygonTutor_EventScript_HazeTaught:: @ 82C824C
	msgbox PorygonTutor_Text_HazeTaught, MSGBOX_DEFAULT
	release
	end


PorygonTutor_Text_HazeTeach: @ 82C79A6
	.string "I am a digital move teacher.\n"
	.string "I am programmed to teach the move\l"
	.string "Haze.\p"
	.string "Be aware, you will need to scan your\n"
	.string "Trainer Card, as I can only teach\l"
	.string "the move to one Pokémon per trainer.\p"
	.string "Would you like to teach one of your\n"
	.string "Pokémon Haze?$"


PorygonTutor_Text_HazeWhichMon: @ 82C7B0D
	.string "Which Pokémon should I teach?$"

PorygonTutor_Text_HazeTaught: @ 82C7B4F
	.string "Thank you for utilizing my\n"
	.string "database, {PLAYER}.$"


@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

NCC_Underground_West_1F_Text_GruntIntro:
	.string "What are you doing down here?$"

NCC_Underground_West_1F_Text_GruntDefeat:
	.string "How did you beat me...?$"

NCC_Underground_West_1F_Text_GruntPostBattleGiveStrength:
	.string "You shouldn't be interfering with\n"
	.string "us. This is far bigger than you.$"

NCC_Underground_West_1F_Text_GruntPostBattle:
	.string "You'll never understand the importance\n"
	.string "of what the NCC is trying to\l"
	.string "accomplish.$"

NCC_Underground_West_1F_Text_ThisDoorIsLocked:
	.string "This door is locked.$"

NCC_Underground_West_1F_Text_KeyUnlocksDoor:
	.string "The key opens the door.$"

MoveTutor_Text_HazeDeclined: @ 82C7AD4
	.string "Please let me know when you're\n"
	.string "ready to teach Haze to a Pokémon.$"