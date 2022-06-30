NCC_Elevator_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NCC_Elevator_OnFrame
	.byte 0

NCC_Elevator_OnFrame: @ 8238C4F
	map_script NCC_ElevatorTakingDownPlayer
	.2byte 0


@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

NCC_ElevatorTakingDownPlayer::
	lockplayer
	playse SE_TRUCK_MOVE
	special ShakeCamera
	waitstate
		@applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	releaseall
end