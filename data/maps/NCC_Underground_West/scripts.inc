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
		checkitem ITEM_SS_TICKET, 1
		compare VAR_RESULT, FALSE
		goto_if_eq NCC_Underground_West_NoKey
		msgbox NCC_Underground_West_1F_Text_KeyUnlocksDoor, MSGBOX_AUTOCLOSE
		opendoor 13, 27
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
		msgbox NCC_Underground_West_1F_Text_ThisDoorIsLocked, MSGBOX_AUTOCLOSE
		applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
		waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end
	

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

NCC_Underground_West_1F_Text_GruntIntro:
	.string "What are you doing down here?$"

NCC_Underground_West_1F_Text_GruntDefeat:
	.string "Damn you won$"

NCC_Underground_West_1F_Text_GruntPostBattleGiveStrength:
	.string "Don't hurt me. Take this!$"

NCC_Underground_West_1F_Text_GruntPostBattle:
	.string "You'll never understand the importance\n"
	.string "of what the NCC is trying to\l"
	.string "accomplish.$"

NCC_Underground_West_1F_Text_ThisDoorIsLocked:
	.string "This door is locked.$"

NCC_Underground_West_1F_Text_KeyUnlocksDoor:
	.string "The key opens the door.$"

