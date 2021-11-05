.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_ColangeloGraphics_3F_MapScripts:: @ 821242D
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_ColangeloGraphics_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_ColangeloGraphics_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_ColangeloGraphics_3F_OnFrame
	.byte 0

RustboroCity_ColangeloGraphics_3F_OnTransition: @ 821243D
	compare VAR_COLANGELO_GRAPHICS_3F_STATE, 0
	call_if_eq RustboroCity_ColangeloGraphics_3F_EventScript_SetEmployeePos
	end

RustboroCity_ColangeloGraphics_3F_EventScript_SetEmployeePos:: @ 8212449
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_ColangeloGraphics_3F_OnWarp: @ 8212455
	map_script_2 VAR_COLANGELO_GRAPHICS_3F_STATE, 0, RustboroCity_ColangeloGraphics_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_ColangeloGraphics_3F_EventScript_PlayerFaceEast:: @ 821245F
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_ColangeloGraphics_3F_OnFrame: @ 8212464
	map_script_2 VAR_COLANGELO_GRAPHICS_3F_STATE, 0, RustboroCity_ColangeloGraphics_3F_EventScript_MeetPresident
	map_script_2 VAR_OLDALE_TOWN_STATE, 14, RustboroCity_ColangeloGraphics_3F_EventScript_RevealMAGABoss
	.2byte 0

RustboroCity_ColangeloGraphics_3F_EventScript_MeetPresident:: @ 821246E
	lockall
	msgbox RustboroCity_ColangeloGraphics_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_ColangeloGraphics_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_ColangeloGraphics_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_ColangeloGraphics_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_ColangeloGraphics_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_ColangeloGraphics_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_ColangeloGraphics_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_ColangeloGraphics_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_ColangeloGraphics_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_ColangeloGraphics_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_ColangeloGraphics_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_ColangeloGraphics_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_ColangeloGraphics_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_ColangeloGraphics_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_COLANGELO_GRAPHICS_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_ColangeloGraphics_3F_Movement_Unused: @ 821252F
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

RustboroCity_ColangeloGraphics_3F_Movement_LeadPlayerToPresident: @ 8212534
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_left
	step_end

RustboroCity_ColangeloGraphics_3F_Movement_EmployeeFaceDesk: @ 8212543
	delay_16
	walk_in_place_fastest_down
	step_end

RustboroCity_ColangeloGraphics_3F_Movement_EmployeeWalkOffscreen: @ 8212546
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_ColangeloGraphics_3F_Movement_EmployeeReturnToPlayer: @ 821254F
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_ColangeloGraphics_3F_Movement_PlayerFollowToPresident: @ 8212558
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_ColangeloGraphics_3F_Movement_PlayerApproachDesk: @ 8212566
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

RustboroCity_ColangeloGraphics_3F_EventScript_MrStone:: @ 821256C
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_ColangeloGraphics_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_ColangeloGraphics_3F_EventScript_GiveExpShare
	msgbox RustboroCity_ColangeloGraphics_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_ColangeloGraphics_3F_EventScript_GiveExpShare:: @ 8212595
	msgbox RustboroCity_ColangeloGraphics_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_ColangeloGraphics_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_ColangeloGraphics_3F_EventScript_MrStoneAfterFavor:: @ 82125CC
	msgbox RustboroCity_ColangeloGraphics_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_ColangeloGraphics_3F_EventScript_Employee:: @ 82125E1
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_ColangeloGraphics_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_ColangeloGraphics_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_3F_EventScript_EmployeeBalls:: @ 82125F6
	msgbox RustboroCity_ColangeloGraphics_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_3F_EventScript_RareRocksDisplay:: @ 8212600
	msgbox RustboroCity_ColangeloGraphics_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_ColangeloGraphics_3F_Text_MrStoneIHaveFavor: @ 8212609
	.string "Fro?! It's me, Dom!\p"
	.string "I'm the president of the\n"
	.string "Colangelo Graphics now.\p"
	.string "Isn't that wild?!\p"
	.string "I'd just got word about you!\p"
	.string "You saved our staff not just once,\n"
	.string "but twice!\p"
	.string "I have a favor to ask of an amazing\n"
	.string "person like you.\p"
	.string "I understand that you're delivering\n"
	.string "a package to Slateport's Shipyard.\p"
	.string "Well, on the way, could you stop off in\n"
	.string "Raintree Island?\p"
	.string "I was hoping that you'd deliver a\n"
	.string "Letter to Steven in Raintree.$"

RustboroCity_ColangeloGraphics_3F_Text_MrStoneWantYouToHaveThis: @ 821277C
	.string "Dom: Now, you should know that\n"
	.string "I am a great President.\p"
	.string "So, I'd never be so cheap as to ask\n"
	.string "a favor for nothing in return.\p"
	.string "That's why I want you to have this!$"

RustboroCity_ColangeloGraphics_3F_Text_ReceivedPokenav: @ 8212820
	.string "{PLAYER} received a Pokénav.$"

RustboroCity_ColangeloGraphics_3F_Text_MrStoneExplainPokenavRestUp: @ 8212837
	.string "Dom: That device…\p"
	.string "It's a Pokémon Navigator, or Pokénav\n"
	.string "for short.\p"
	.string "It's an indispensable tool for any\n"
	.string "Trainer on an adventure.\p"
	.string "It has a map of the Niagara region.\p"
	.string "You can check the locations of\n"
	.string "Raintree and Slateport easily!\p"
	.string "By the way, I've heard that sinister\n"
	.string "criminals--MAGA, I believe--\l"
	.string "have been making trouble far and wide.\p"
	.string "I think it would be best if you rested\n"
	.string "up before you go on your way.$"

RustboroCity_ColangeloGraphics_3F_Text_MrStoneGoWithCautionAndCare: @ 82129D2
	.string "Dom: Well, then, {PLAYER}{KUN},\n"
	.string "go with caution and care!$"

RustboroCity_ColangeloGraphics_3F_Text_CountingOnYou: @ 8212A09
	.string "Dom: I'm counting on you!$"

RustboroCity_ColangeloGraphics_3F_Text_ThankYouForDeliveringLetter: @ 8212A29
	.string "Dom: You delivered my Letter?\n"
	.string "Thank you kindly!\p"
	.string "This is my way of thanking you.\n"
	.string "It should help you, as a Trainer.$"

RustboroCity_ColangeloGraphics_3F_Text_ExplainExpShare: @ 8212A9E
	.string "Dom: A Pokémon holding that\n"
	.string "EXP. SHARE will be given some of the\l"
	.string "EXP Points from battle.\p"
	.string "It will get EXP Points even if it didn't\n"
	.string "actually battle.\p"
	.string "I would say EXP. SHARE is quite useful\n"
	.string "for raising weak Pokémon.$"

RustboroCity_ColangeloGraphics_3F_Text_NotFamiliarWithTrends: @ 8212B78
	.string "Dom: Since my youth, I've immersed\n"
	.string "myself in work.\p"
	.string "Consequently, I'm not familiar with\n"
	.string "trends and that sort of thing.\p"
	.string "But do young people all want to be\n"
	.string "Trainers in the Pokémon League?$"

RustboroCity_ColangeloGraphics_3F_Text_ThisIs3rdFloorWaitHere: @ 8212C37
	.string "This is the Colangelo Graphics's\n"
	.string "third floor.\p"
	.string "Our President's Office is on\n"
	.string "this floor.\p"
	.string "Anyway, I can't tell you how much I'm\n"
	.string "grateful for what you've done.\p"
	.string "Um… By the way, that parcel\n"
	.string "you got back for us…\p"
	.string "Could I get you to deliver that to\n"
	.string "the Shipyard in Slateport?\p"
	.string "It would be awful if those robbers\n"
	.string "tried to take it again.\p"
	.string "Uh… Hehehe, so, uh, could I count\n"
	.string "on you to do that for me?\p"
	.string "Oh, that's right.\n"
	.string "Could you wait here a second?$"

RustboroCity_ColangeloGraphics_3F_Text_WordWithPresidentComeWithMe: @ 8212DE8
	.string "Our President would like to have\n"
	.string "a word with you.\p"
	.string "Please come with me.$"

RustboroCity_ColangeloGraphics_3F_Text_PleaseGoAhead: @ 8212E2F
	.string "Please, go ahead.$"

RustboroCity_ColangeloGraphics_3F_Text_VisitCaptSternShipyard: @ 8212E41
	.string "If you visit the Shipyard in Slateport,\n"
	.string "you should go see Capt. Stern.$"

RustboroCity_ColangeloGraphics_3F_Text_RepeatAndTimerHugelyPopular: @ 8212E88
	.string "C. G.'s new products, the Repeat Ball\n"
	.string "and Timer Ball, have become hugely\l"
	.string "popular among TrainerS.$"

RustboroCity_ColangeloGraphics_3F_Text_RareRocksDisplay: @ 8212EE9
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by the President.$"

RustboroCity_ColangeloGraphics_3F_EventScript_RevealMAGABoss::
	lockall
	clearflag FLAG_HIDE_MAGA_COLANGELO_GRAPHICS
	msgbox ColangeloGraphics_Text_DomIsAngry, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ColangeloGraphics_Movement_PlayerToBoss
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox ColangeloGraphics_Text_SoYouveRuinedOurPlans, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_COLANGELO_GRAPHICS_DOM, ColangeloGraphics_Text_DomDefeat
	setvar VAR_OLDALE_TOWN_STATE, 15
	msgbox ColangeloGraphics_Text_MaybePokemonArentMeantToBeUsedAsWeapons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject 5
	removeobject 4
	setflag FLAG_HIDE_MAGA_COLANGELO_GRAPHICS
	fadescreen FADE_FROM_BLACK
	delay 30
	msgbox ColangeloGraphics_Text_ThankYouForStandingUpToMe, MSGBOX_DEFAULT
	giveitem ITEM_HM07
	setflag FLAG_RECEIVED_HM07
	releaseall
	end

ColangeloGraphics_Text_MaybePokemonArentMeantToBeUsedAsWeapons:
	.string "Even with all that power, I couldn't\n"
	.string "Win.\p"
	.string "Maybe Pokémon aren't meant to be\n"
	.string "used as weapons.\p"
	.string "\p"
	.string "Lattka, Paul, we are halting all\n"
	.string "Pokémon Enhancement related\l"
	.string "activities.\p"
	.string "Paul: But sir!\p"
	.string "D. Colangelo: I've made up my\n"
	.string "mind. You're dismissed.$"

ColangeloGraphics_Text_ThankYouForStandingUpToMe:
	.string "Thank you for showing me what\n"
	.string "really matters, {PLAYER}.\p"
	.string "What we were doing was wrong, and\n"
	.string "hurt the Pokémon. I will have to\l"
	.string "find other ways to help America!\p"
	.string "I want you to take this as a token\n"
	.string "of my gratitude!$"


ColangeloGraphics_Text_DomDefeat:
	.string "I can't believe it...\p"
	.string "All odds were against you and\n"
	.string "you still didn't back down.$"
	
ColangeloGraphics_Text_DomIsAngry:
	.string "D. Colangelo: This is not good!!$"

ColangeloGraphics_Text_SoYouveRuinedOurPlans:
	.string "D. Colangelo: Fro...?\p"
	.string "I'm sorry you had to find out like\n"
	.string "this good buddy, but it looks like\l"
	.string "I have no other choice...\p"
	.string "You see, I've always wanted to help\n"
	.string "people, it's why I joined the\l"
	.string "Military.\p"
	.string "What you don't understand is that\n"
	.string "if we stop now, our Country will\l"
	.string "fall.\p"
	.string "I've seen how far other Countries \n"
	.string "will go first hand, and it ain't\l"
	.string "pretty...\p"
	.string "So I developed Technology to make\n"
	.string "Pokémon stronger, keeping it hidden\l"
	.string "behind Colangelo Graphics.\p"
	.string "It works exceptionally well, and\n"
	.string "will be the edge America needs to\l"
	.string "maintain it's control of the world.\p"
	.string "You have to see the logic, right?\p"
	.string "No? Fine then, you're not going to\n"
	.string "stand a chance against my Octire.\p"
	.string "With the technology of Coloangelo\n"
	.string "Graphics, I have enhanced it's\l"
	.string "strength well beyond anything you\l"
	.string "can handle.\p"
	.string "It is so strong I once saw it rip\n"
	.string	"Semi-Truck in half.\p"
	.string "You still want to try to stop me?\n"
	.string "Alright then, give me your best\l"
	.string "shot!$"

ColangeloGraphics_Movement_PlayerToBoss:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end
