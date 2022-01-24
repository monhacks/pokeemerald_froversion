WalmoreTown_JohnsHouse_MapScripts::
	.byte 0


WalmoreTown_JohnsHouse_EventScript_EggAlreadyGiven:
	msgbox WalmoreTown_JohnsHouse_Text_TakeCareFro, MSGBOX_DEFAULT
	release
end

WalmoreTown_JohnsHouse_EventScript_GiveEgg::
@ Case 0: Fro Rascaloot/John Emboryps/Bobby Flobra
@ Case 1: Fro Flobra/John Rascaloot/Bobby Emboryps
@ Case 2: Fro Emboryps/John Flobra/Bobby Rascaloot
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_JOHNS_EGG, WalmoreTown_JohnsHouse_EventScript_EggAlreadyGiven
	msgbox WalmoreTown_JohnsHouse_Text_CongratsOnBecomingChampion, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, WalmoreTown_JohnsHouse_EventScript_EmborypsEgg
	case 1, WalmoreTown_JohnsHouse_EventScript_RascalootEgg
	case 2, WalmoreTown_JohnsHouse_EventScript_FlobraEgg

WalmoreTown_JohnsHouse_EventScript_EmborypsEgg:	
	msgbox WalmoreTown_JohnsHouse_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_JOHNS_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_EMBORYPS
	release
end

WalmoreTown_JohnsHouse_EventScript_RascalootEgg:	
	msgbox WalmoreTown_JohnsHouse_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_JOHNS_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_RASCALOOT
	release
end

WalmoreTown_JohnsHouse_EventScript_FlobraEgg:	
	msgbox WalmoreTown_JohnsHouse_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_JOHNS_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_FLOBRA
	release
end

WalmoreTown_JohnsHouse_Text_CongratsOnBecomingChampion:
	.string "I can't believe you did it Fro!\p"
	.string "You're a real life God!\n"
	.string "The way you yeeted Bobby in that\l"
	.string "final match.\p"
	.string "WOW!$"

WalmoreTown_JohnsHouse_Text_HaveEggWillYouTakeIt:
	.string "Come to think of it Champ,\n"
	.string "It would be pretty yeeting hard\l"
	.string "to complete your dex without\l"
	.string "my help!\p"
	.string "Let me yeet you this egg.$"

WalmoreTown_JohnsHouse_Text_TakeCareFro:
	.string "Take care {PLAYER}!\p"
	.string "See you around!$"
