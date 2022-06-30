NCC_Elevator_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NCC_Elevator_OnFrame
	.byte 0

NCC_Elevator_OnFrame: @ 8238C4F
	map_script_2 VAR_ROUTE101_STATE, 5, NCC_ElevatorTakingDownPlayer
	.2byte 0


@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

NCC_ElevatorTakingDownPlayer::
	lock
	setvar VAR_ROUTE101_STATE, 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	@special ShakeCamera
	@waitstate
	releaseall
end