NCC_Elevator_ExitRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NCC_Elevator_ExitRoom_OnFrame
	.byte 0

NCC_Elevator_ExitRoom_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 5, NCC_ElevatorInitUp
.2byte 0

NCC_ElevatorInitUp::
	setvar VAR_ROUTE101_STATE, 6
end
