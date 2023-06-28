.set LOCALID_SECRETARY, 1

MageeVersionProtagonistsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MageeVersionProtagonistsHouse_OnFrame
	.byte 0

MageeVersionProtagonistsHouse_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, Script_MageeVersionProtagonistsHouse_Secretary

MageeVersionProtagonistsHouse_TestScript::
	release
	end