.set LOCALID_MATT, 6
.set LOCALID_KOSTIW, 7

HubRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HubroomOnTransition
	map_script MAP_SCRIPT_ON_LOAD, MS_HubRoom_OnLoad
	.byte 0

HubroomOnTransition::
	setrespawn HEAL_LOCATION_HUB_ROOM

MS_HubRoom_OnLoad::
	compare VAR_OLDALE_TOWN_STATE, 0
	call_if_eq Script_HubRoom_RemoveKostiwMatt
	compare VAR_HUBROOM_STATE, 1
	call_if_eq Script_ShowJohnHubRoom
end

HubRoom_John_Dialouge::
	goto_if_set FLAG_JOHN_DIALOUGE_COMPLETE, John_Dialouge_End
	msgbox HubRoom_JohnDialouge_Text, MSGBOX_DEFAULT
	giveegg SPECIES_TOGEPI
John_Dialouge_End:
	msgbox HubRoom_JohnDialougeEnd_Text, MSGBOX_DEFAULT
	setflag FLAG_JOHN_DIALOUGE_COMPLETE
	release
end

HubRoom_JohnDialougeEnd_Text:
	.string "Good luck out there man. If you\n"
	.string "get into trouble don't forget to\l"
	.string "use balrog's gambit!$"


HubRoom_JohnDialouge_Text:
	.string "Nike! I hear you really\n" 
	.string "destroyed Chad in that battle.\p"
	.string "Congrats dude.\n"
	.string "How's your foot doing?\p"
	.string "Still can't believe you did that…\p "
	.string "Anyway I'm glad I ran into\n"
	.string "you! Long story, but I'm the\l"
	.string "Dark Room Master, it's bullshit,\l"
	.string "and something really strange\l"
	.string "happened to me I wanted\l"
	.string "to tell you about.\p"
	.string "Since I'm in the Dark room\n"
	.string "there are usually only Dark type\l"
	.string "pokemon there, which is bullshit,\l"
	.string "but today I saw a pokemon that\l"
	.string "wasn't Dark type in there.\p"
	.string "A togekiss flew in.  I couldn't\n"
	.string "figure out what possibly could\l"
	.string "have brought her to such a dark\l"
	.string "and bullshit place until I \l"
	.string "realized she was being chased\l"
	.string "by something!\p"
	.string "Just then a huge Dark Pokemon\n"
	.string "came crashing in and attacked\l"
	.string "her with this crazy dark attack,\l"
	.string "which was bullshit, and it\l"
	.string "engulfed her in powerful darkness.\p"
	.string "The Dark pokemon flew away before\n"
	.string "I could try to battle it but it\l"
	.string "looked really powerful…\p"
	.string "I tried to save the Togekiss\n"
	.string "but she was still engulfed in\l"
	.string "darkness and it was slowly\l"
	.string "killing her. It was such bullshit!\p"
	.string "And that's not even the \n"
	.string "saddest or most bullshit part,\l"
	.string "she was also pregnant! And just\l"
	.string "before she died she laid this egg.\p"
	.string "That's why I wanted to come\n"
	.string "see you. I know how much you love\l"
	.string "Togekiss, so I thought you'd be a\l"
	.string "good person to take\l"
	.string "care of this Togepi egg!$"

Script_HubRoom_RemoveKostiwMatt:
	removeobject LOCALID_MATT
	removeobject LOCALID_KOSTIW
	removeobject 10
	removeobject 11
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_TILYOU
	setflag FLAG_HUBROOM_JOHN
return

Script_ShowJohnHubRoom:
	addobject 11
	addobject 12
	clearflag FLAG_HUBROOM_JOHN
return
	

HubRoom_EventScripts_WouldYouLikeToEnterPoisonRoom::
	lockall
	msgbox HubRoom_Text_WouldYouLikeToEnterPoisonRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToPoisonRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToPoisonRoom:
	goto_if_unset FLAG_INTRO_SEQUENCE_COMPLETE, HubRoom_EventScripts_IntroSequenceMatt
	goto_if_unset FLAG_PICKED_STARTER, HubRoom_EventScripts_YouDontHaveAPokemon
	compare VAR_LITTLEROOT_TOWN_STATE, 5
	goto_if_lt HubRoom_EventScript_RoomIsLocked
	warp MAP_BUG_A, 0, 11, 78
	release
end

HubRoom_EventScripts_IntroSequenceMatt:
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	addobject LOCALID_MATT
	applymovement LOCALID_MATT, HubRoom_Movement_MattMovesToNike
	waitmovement LOCALID_MATT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox HubRoom_Text_MattIntro1, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 250
	msgbox HubRoom_Text_MattIntro2, MSGBOX_DEFAULT
	setflag FLAG_INTRO_SEQUENCE_COMPLETE
	release
end

HubRoom_EventScripts_NPCMatt::
	lock
	goto_if_set FLAG_PICKED_STARTER, HubRoom_EventScript_MattStarterChoiceDialouge
	msgbox HubRoom_NPCMatt_Text, MSGBOX_DEFAULT
	release
end

HubRoom_EventScript_MattStarterChoiceDialouge:
	compare VAR_STARTER_MON, 0
	goto_if_eq Matt_ES_YouChoseBuccanile
	compare VAR_STARTER_MON, 1
	goto_if_eq Matt_ES_YouChoseWallie
	compare VAR_STARTER_MON, 2
	goto_if_eq Matt_ES_YouChoseKopirar
	release
end

Matt_ES_YouChoseBuccanile:
	msgbox Matt_Text_YouChoseBuccanile, MSGBOX_DEFAULT
	release
end

Matt_ES_YouChoseWallie:
	msgbox Matt_Text_YouChoseWallie, MSGBOX_DEFAULT
	release
end

Matt_ES_YouChoseKopirar:
	msgbox Matt_Text_YouChoseKopirar, MSGBOX_DEFAULT
	release
end

Matt_Text_YouChoseBuccanile:
	.string "I knew it! Since Brady's\n"
	.string "your starting QB, I knew you'd\l"
	.string "pick Buccanile as your\l"
	.string "starting Pokemon!$"

Matt_Text_YouChoseWallie:
	.string "Ooh I knew you'd pick Wallite!\n"
 	.string "You're gonna be unstoppable at\l"
	.string "softball… and Kostiw will never\l"
	.string "get a hit off of you now!$"

Matt_Text_YouChoseKopirar:
	.string "Of course KOPITAR XX would\n"
	.string "Pick Kopirar as his first Pokemon!$"






HubRoom_NPCMatt_Text:
	.string "You gotta find Kostiw, he knew\n"
	.string "someone who got access when I\l"
	.string "first got here.$"

HubRoom_Text_MattIntro1:
	.string "Hey Nikesaur!\p"
	.string "You're walking!\p"
	.string "When you stabbed yourself in the\n"
	.string "foot with that plastic knife I\l"
	.string "didn't think you'd ever walk again!\p"
	.string "But I guess you were right,\n"
	.string "sleepfest did the trick.\p"
	.string "That whole scene put you so far\n"
	.string "behind with catching Pokemon though.\p"
	.string "Even fro has been catching pokes!\n"
	.string "And most of us have even become\l"
	.string "Room Masters already.\p"
	.string "What's a room Master?!\p"
	.string "Wow you really have been gone a long\n"
	.string "time…\p"
	.string "a Room Master is like a Gym Leader.\n"
	.string "We each specialize in a different type\l"
	.string "but the difference is, you have to\l"
	.string "defeat us using a team of that same\l"
	.string "type.\p"
	.string "It can be quite a challenge but if\n"
	.string "you want to be a master you're\l"
	.string "gonna have to lock it in.\p"
	.string "I myself am the Psychic Room\n"
	.string "Master.\p"
	.string "I look forward to fighting you someday.\n"
	.string "You're gonna need some pokes first\l"
	.string "though.\p"
	.string "Here take these.$"
	
HubRoom_Text_MattIntro2:	
	.string "The only problem now is that you\n"
	.string "need access to these doors.\p"
	.string "You gotta find Kostiw, he knew\n"
	.string "someone who got me access when\l"
	.string "I first got here.$"



HubRoom_Movement_MattMovesToNike:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

HubRoom_EventScripts_YouDontHaveAPokemon:
	msgbox HubRoom_Text_YouDontHaveAPokemon, MSGBOX_AUTOCLOSE
	release
end

HubRoom_EventScript_RoomIsLocked:
	msgbox HubRoom_Text_RoomIsLocked, MSGBOX_AUTOCLOSE
	release
end

HubRoom_Text_RoomIsLocked:
	.string "The Room is still locked...$"

HubRoom_Text_WouldYouLikeToEnterPoisonRoom:
	.string "Would you like to enter the \nPoison Room?$"

HubRoom_EventScripts_WouldYouLikeToEnterNormalRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_POISON, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterNormalRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToNormalRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToNormalRoom:
	compare VAR_HUBROOM_STATE, 2
	goto_if_lt HubRoom_EventScript_RoomIsLocked
	warp MAP_BUG4, 0, 11, 78
	release
end

HubRoom_Text_WouldYouLikeToEnterNormalRoom:
	.string "Would you like to enter the \nNormal Room?$"

HubRoom_EventScripts_WouldYouLikeToEnterIceRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_NORMAL, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterIceRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToIceRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToIceRoom:
	warp MAP_POISON1, 1, 40 , 12
	release
end



HubRoom_Text_WouldYouLikeToEnterIceRoom:
	.string "Would you like to enter the \nIce Room?$"


HubRoom_EventScripts_WouldYouLikeToEnterWaterRom::
	lockall
	goto_if_unset FLAG_DEFEATED_ICE, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterWaterRom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToWaterRom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToWaterRom:
	warp MAP_WATERT, 0, 40 , 12
	release
end

HubRoom_Text_WouldYouLikeToEnterWaterRom:
	.string "Would you like to enter the \nWater Room?$"



HubRoom_Text_WouldYouLikeToEnterFireRoom:
	.string "Would you like to enter the \nFire Room?$"



HubRoom_EventScripts_WouldYouLikeToEnterFireRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_WATER, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterFireRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToFireRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToFireRoom:
	warp MAP_NEW_MAP2, 0, 40 , 12
	release
end

HubRoom_EventScripts_WouldYouLikeToEnterElectricRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_FIRE, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterElectricRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToElectricRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToElectricRoom:
	warp MAP_ELECTRIC1, 0, 40 , 12
	release
end



HubRoom_Text_WouldYouLikeToEnterElectricRoom:
	.string "Would you like to enter the \nElectric Room?$"

HubRoom_EventScripts_WouldYouLikeToEnterSteelRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_ELECTRIC, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterSteelRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToSteelRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToSteelRoom:
	warp MAP_STEEL1, 0, 40 , 12
	release
end



HubRoom_Text_WouldYouLikeToEnterSteelRoom:
	.string "Would you like to enter the \nSteel Room?$"



////////////////Universal/////////////////////

HubRoom_EventScripts_DontWarpToRoom:
	msgbox HubRoom_Text_PleaseComeBackWhenYoureReady, MSGBOX_DEFAULT
	releaseall	
end

HubRoom_EventScripts_HaventUnlockedRoom:
	msgbox HubRoom_Text_HaventUnlockedRoom, MSGBOX_DEFAULT
	releaseall
end

HubRoom_Text_PleaseComeBackWhenYoureReady:
	.string "Please come back whenever you \nare ready.$"

HubRoom_Text_HaventUnlockedRoom:
	.string "You haven't unlocked this room \nyet!$"

HubRoom_Text_YouDontHaveAPokemon:
	.string "You don't have a Pokemon, dummy.$"


HubRoom_Text_OfficerGratwick:
	.string "Officer Gratwick: Let me know if you\n"
	.string "see any suspicious activity.$"

HubRoom_EventScript_OfficerGratwick::
	lock
	goto_if_unset FLAG_FOUND_LOST_WALLET, OfficerGratWick_EventScript_SeeAnythingSuspicious
	goto_if_unset FLAG_INTRO_SEQUENCE_COMPLETE, OfficerGratWick_EventScript_SeeAnythingSuspicious
	goto_if_set FLAG_KOSTIW_INTRO, OfficerGratWick_EventScript_SeeAnythingSuspicious
	msgbox HubRoom_Text_LooksLikeItBelongsToMrKostiw, MSGBOX_DEFAULT
	scrollingmultichoice 9, 2, 3,4, TRUE
	compare VAR_RESULT, 0
	goto_if_eq HubRoom_EventScript_Surprised
	compare VAR_RESULT, 1
	goto_if_eq HubRoom_EventScript_Greedy
	compare VAR_RESULT, 2
	goto_if_eq HubRoom_EventScript_Concerned
	compare VAR_RESULT, 3
	goto_if_eq HubRoom_EventScript_Reminiscent
	compare VAR_RESULT, 4
	goto_if_eq HubRoom_EventScript_Casual
	compare VAR_RESULT, 5
	goto_if_eq HubRoom_EventScript_Confused
	release
end

OfficerGratWick_EventScript_SeeAnythingSuspicious:
	msgbox HubRoom_Text_OfficerGratwick, MSGBOX_DEFAULT
	release
end

HubRoom_Text_LooksLikeItBelongsToMrKostiw:
	.string "Officer Gratwick: You found a Wallet?\p"
	.string "Looks like it belongs to a Mr. Joe\n"
	.string "Kostiw.\p"
	.string "I'll keep an eye out and let you\n"
	.string "know if he shows up.\p"
	.string "{COLOR RED}Choose a response.$"

HubRoom_EventScript_Surprised:
	msgbox Text_Surprised_HubRoom, MSGBOX_DEFAULT
	release
end

HubRoom_EventScript_Greedy:
	msgbox Text_Greedy_HubRoom, MSGBOX_DEFAULT
	release
end

HubRoom_EventScript_Concerned:
	msgbox Text_Concerned_HubRoom, MSGBOX_DEFAULT
	release
end

HubRoom_EventScript_Reminiscent:
	msgbox Text_Reminiscent_HubRoom, MSGBOX_DEFAULT
	release
end

HubRoom_EventScript_Casual:
	msgbox Text_Casual_HubRoom, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	addobject 7
	applymovement 7, HubRoom_Movement_MattMovesToNike
	msgbox Text_KostiwIntroSequence_HubRoom
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft35
	applymovement 7, Common_Movement_WalkLeft35
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox Text_KostiwIntroSequence2_HubRoom
	setflag FLAG_KOSTIW_INTRO
	addmoney 40000, 0
	release
end

Text_KostiwIntroSequence2_HubRoom:
	.string "Looks like you only have enough money\n"
	.string "to buy one Pokémon…\p"
	.string "yeah now that we're adults they're\n"
	.string "charging us money for the starters…\p"
	.string "what a racket. Well, go ahead\n"
	.string "and choose.$"

HubRoom_EventScripts_NPCKostiw::
	lock
	msgbox HubRoom_NPCKostiw_Text, MSGBOX_DEFAULT
	release
	end

HubRoom_NPCKostiw_Text:
	.string "Well, go ahead and choose!!$"

HubRoom_EventScript_Confused:
	msgbox Text_Confused_HubRoom, MSGBOX_DEFAULT
	release
end

Text_Surprised_HubRoom:
	.string "Nike: O M Jizou.\p"
	.string "Officer Gratwick: OK...$"

Text_Greedy_HubRoom:
	.string "Nike: I'll just keep it then.\p"
	.string "Officer Gratwick: I'll pretend\n"
	.string "I didn't hear that.$"

Text_Concerned_HubRoom:
	.string "Nike: I can't believe I\n"
	.string "trusted that guy with the stapler.\p"
	.string "Officer Gratwick: Stapler?\n"
	.string "What's so important about a\l"
	.string "stapler?$"

Text_Reminiscent_HubRoom:
	.string "Nike: That guys been losing\n"
	.string "his wallet for 8 billion years.\p"
	.string "Officer Gratwick: Why do I feel like\n"
	.string "that guy who wouldn't put his hands\l"
	.string "up that one time, is rolling his eyes\l"
	.string "right now?$"

Text_Casual_HubRoom:
	.string "Nike: Kostiw is always losing his\n"
	.string "wallet, eh?$"

Text_Confused_HubRoom:
	.string "Nike: This wallet is loster\n"
	.string "than lostness itself.\p"
	.string "Officer Gratwick: And there is\n"
	.string "so much shit in here that it is\l"
	.string "thicker than thickness itself.$"


Text_KostiwIntroSequence_HubRoom:
	.string "Eh!\p"
	.string "Well, if it isn't Cedric the\n"
	.string "Entertainer the First!\p"
	.string "Matt said you're ready to start your\n"
	.string "challenge! I'm pumped!\p"
	.string "Maybe one day you can come take\n"
	.string "on me and Spirett!\p"
	.string "And if you beat everyone else's\n"
	.string "Room Master teams, you can take\l"
	.string "on the final challenge and face\l"
	.string "each or our real level 100 teams,\l"
	.string "with no type restrictions.\p"
	.string "So make sure you're training up\n"
	.string "all your Pokémon along the way\l"
	.string "and not just the types you need.\p"
	.string "Hey!\p"
	.string "You found my Wallet!\n"
	.string "Thanks!\p"
	.string "Here you can keep the money in it,\n"
	.string "I have a Wilson Farms gift card\l"
	.string "so I don't need money anymore.\p"
	.string "I heard you need help getting access\n"
	.string "to those doors…\p"
	.string "Yeah I know someone who can help you\n"
	.string "out!\p"
	.string "But first you're gonna need a Pokémon.\p"
	.string "Come on, let's take the long journey\n"
	.string "to the starter table.$"
