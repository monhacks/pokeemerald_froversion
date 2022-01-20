WesternApproachLostSpringCanyon_MapScripts::
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


///////////////////////////////
////////////TEXTS//////////////
//////////////////////////////


WesternApproachLostSpringCanyon_Text_RestUpHere:
	.string "Would you like to rest here?$"

WesternApproachLostSpringCanyon_Text_TakeYourTimeRestUp:
	.string "Take your time. Rest Up!$"
