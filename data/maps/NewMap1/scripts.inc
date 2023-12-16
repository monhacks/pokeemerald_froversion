NewMap1_MapScripts::
	.byte 0


MAGM8Forest_MainArea_Eventscripts_SouthSign::
	lock
	msgbox MAGM8Forest_MainArea_Text_SouthSign, MSGBOX_SIGN
	release
end

MAGM8Forest_MainArea_Eventscripts_NorthSign::
	lock
	msgbox MAGM8Forest_MainArea_Text_NorthSign, MSGBOX_SIGN
	release
end

MAGM8Forest_MainArea_Eventscripts_HouseSign::
	lock
	msgbox MAGM8Forest_MainArea_Text_HouseSign, MSGBOX_SIGN
	release
end

MAGM8Forest_MainArea_Eventscripts_NorthExitBlocked::
	lock
	msgbox MAGM8Forest_MainArea_Text_NorthExitBlocked, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	release
end

MAGM8Forest_MainArea_Text_HouseSign:
	.string "{PLAYER}'s House:\n"
	.string "No Trespassing!$"

MAGM8Forest_MainArea_Text_NorthSign:
	.string "{UP_ARROW} Northern Woods\n"
	.string "{DOWN_ARROW} {PLAYER}'s House$"
	
MAGM8Forest_MainArea_Text_SouthSign:
	.string "{UP_ARROW} {PLAYER}'s House\n"
	.string "{DOWN_ARROW}$ Town Name"
