UnknownCave_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UnknownCave_OnFrame
	.byte 0

UnknownCave_OnFrame: @ 81EBCCB
	map_script_2 VAR_ROUTE101_STATE, 7, Script_UnknownCave_PostGameEvent //Froversion Script
	.2byte 0
	
Script_UnknownCave_PostGameEvent:
	lock
	msgbox UnknownCave_Text_PlayerWokeUpInCave, MSGBOX_DEFAULT
	release
	end

UnknownCave_Text_PlayerWokeUpInCave:
	.string "After the events on Cinnabar\n"
	.string "{PLAYER} woke up in a cave\l"
	.string "with no recollection of what\l"
	.string "happened or how he ended up here.$"

	