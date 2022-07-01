NCC_Elevator_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NCC_Elevator_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NCC_Elevator_OnWarp
	.byte 0

NCC_Elevator_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 5, NCC_ElevatorTakingDownPlayer
	.2byte 0

NCC_Elevator_OnWarp:
	map_script_2 VAR_ROUTE101_STATE, 6, NCC_ElevatorTakingUpPlayer
	.2byte 0



@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

NCC_ElevatorTakingDownPlayer::
	lock
	setvar VAR_ROUTE101_STATE, 6
	playse SE_TRUCK_MOVE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	playse SE_TRUCK_STOP
	waitse
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	warp MAP_NCC_ELEVATOR_EXIT_ROOM, 255, 10, 11
	releaseall
end

NCC_ElevatorTakingUpPlayer::
	setvar VAR_ROUTE101_STATE, 4
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	playse SE_TRUCK_MOVE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	warpsilent MAP_CINNABAR_ISLAND_NCC, 255, 23, 16
	releaseall
end
