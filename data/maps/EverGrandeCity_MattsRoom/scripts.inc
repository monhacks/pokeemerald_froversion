.set LOCALID_MATT, 1
.set LOCALID_WALLACE, 2

EverGrandeCity_MattsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_MattsRoom_OnFrame
	.byte 0

EverGrandeCity_MattsRoom_OnFrame: @ 8228A14
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_MattsRoom_EventScript_EnterMattsRoom
	.2byte 0

EverGrandeCity_MattsRoom_EventScript_EnterMattsRoom:: @ 8229850
	lockall
	applymovement LOCALID_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkIntoHallOfFame1
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox EverGrandeCity_HallOfFame_Text_LooksLikeMattAcutallyBeatBobbyRightBeforeYouGotHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_HallOfFame_Movement_WalkToMatt1
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_HallOfFame_Movement_WalkToMatt1
	waitmovement 0
	delay 20
	applymovement LOCALID_MATT Common_Movement_ExclamationMark
	waitmovement LOCALID_MATT
	msgbox EverGrandeCity_HallOfFame_Text_SeeIfYouCanBeatMeNow, MSGBOX_DEFAULT
	//setflag FLAG_BATTLE_DREAM_FOG
	trainerbattle_no_intro TRAINER_SUMMIT_CAVERNS_LATTKA_2, SummitCaverns_Text_LattkaDefeat2
	//clearflag FLAG_BATTLE_DREAM_FOG
	setvar VAR_TEMP_1, 1
	releaseall
	end

	EverGrandeCity_HallOfFame_Movement_WalkToMatt1:
		walk_up
		walk_up
		walk_up
		step_end

EverGrandeCity_HallOfFame_Text_LooksLikeMattAcutallyBeatBobbyRightBeforeYouGotHere:
	.string "I know this is going to annoy you\n"
	.string "but Bobby wasn't the real champion.\p"
	.string "Icee ended up beating Bobby right\n"
	.string "before you got here.\p"
	.string "Looks to me like you've got one\n"
	.string "more battle before you're crowned\l"
	.string "champion.$"

EverGrandeCity_HallOfFame_Text_SeeIfYouCanBeatMeNow:
	.string "That's right {PLAYER}, I'm the real\n"
	.string "Chimp Champ.\p"
	.string "Let's see if you can beat me.\p"
	.string "SPEED!\p"
	.string "VIOLENCE!\p"
	.string "MOMENTUM!!$"
