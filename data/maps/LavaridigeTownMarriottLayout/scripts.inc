LavaridigeTownMarriottLayout_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridigeTownMarriottLayout_OnTransition
	.byte 0

LavaridigeTownMarriottLayout_OnTransition:
	setflag FLAG_MARRIOTT_VERSION
	end

LavaridigeTownMarriottLayout_EventScript_GymLeaderSignOnDoor::
	msgbox	LavaridigeTownMarriottLayout_Text_GymLeaderSignOnDoor, MSGBOX_DEFAULT
	end

LavaridigeTownMarriottLayout_Text_GymLeaderSignOnDoor:
	.string "There is a sign on the door.\p"
	.string "“GYM CLOSED: Leader Flannery is\n"
	.string "investigating some strange activity\l"
	.string "in the Western Approach.\p"
	.string "He will be reviewing all applications\n"
	.string "to fill his position once he returns.\p"
	.string "Thank you for you interest and\n"
	.string "understanding in the matter.”$"
