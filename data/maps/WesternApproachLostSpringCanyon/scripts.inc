.set LOCAL_ID_FLANNERY, 1

WesternApproachLostSpringCanyon_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WesternApproachSandstormCheck_OnTransition
	.byte 0

///////////////////////////////
////////Event Scripts//////////
//////////////////////////////

WesternApproachLostSpringCanyon_EventScript_Tent::
	lock
	setrespawn HEAL_LOCATION_WESTERN_APPROACH_LOST_SPRING_CANYON
	msgbox WesternApproachLostSpringCanyon_Text_RestUpHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq WesternApproachLostSpringCanyon_EventScript_Rest
end

WesternApproachLostSpringCanyon_EventScript_Rest:: @ 822A941
	msgbox WesternApproachLostSpringCanyon_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
end

WesternApproachLostSpringCanyon_EventScript_Flannery::
	lockall
	faceplayer
	msgbox WesternApproachLostSpringCanyon_Text_Flannery, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	removeobject LOCAL_ID_FLANNERY
	setflag FLAG_FRO_VERSION_HIDE_TILYOUS_LAB_BOBBY_MAGEE_VERSION_HIDE_SECRETARY
	fadescreen FADE_FROM_BLACK
	releaseall
end

///////////////////////////////
//////////MOVEMENTS////////////
//////////////////////////////


///////////////////////////////
////////////TEXTS//////////////
//////////////////////////////


WesternApproachLostSpringCanyon_Text_RestUpHere:
	.string "Would you like to rest here?$"

WesternApproachLostSpringCanyon_Text_TakeYourTimeRestUp:
	.string "Take your time. Rest Up!$"

WesternApproachLostSpringCanyon_Text_Flannery:
	.string "Hmmmm...\p"
	.string "Very strange indeed...\p"
	.string "Oh! Sorry I was a bit distracted.\p"
	.string "Yes I am Flannery, Leader of the\n"
	.string "Grand Island Gym.\p"
	.string "I do not have time to take on\n"
	.string "challengers at this time.\p"
	.string "There are reports of a strange\n"
	.string "Pokémon that has been disturbing\l"
	.string "the ecosystem of the area, and I'm\l"
	.string "trying to find out where this\l"
	.string "Pokémon is hiding, and how to get\l"
	.string "it to cohabitate with the other\l"
	.string "Pokémon in the area.\p"
	.string "Oh you're not looking to challenge\n"
	.string "me?\p"
	.string "You're here to apply to take over\n"
	.string "as gym leader once I retire?\p"
	.string "Well, this is still not a matter\n"
	.string "I can attend to at this time.\p"
	.string "It will have to wait until the\n"
	.string "Pokémon in the Western Approach\l"
	.string "are happy and healthy again.\p"
	.string "I'm going to go investigate to the\n"
	.string "south, feel free to go wait by the\l"
	.string "Gym.\p"
	.string "Oh you want to help?\p"
	.string "Well, I don't know how qualified\n"
	.string "you are, so please be careful if you\l"
	.string "do.\p"
	.string "I'm going to go on ahead, maybe I'll\n"
	.string "see you out there.$"