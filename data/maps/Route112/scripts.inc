.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 6
.set LOCALID_BOBBY, 15

Route112_MapScripts:: @ 81F1DA8
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition: @ 81F1DAE
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

Route112_EventScript_MagmaGrunts:: @ 81F1DB7
	lockall
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 20
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 40
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 20
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign:: @ 81F1E46
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign:: @ 81F1E4F
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge:: @ 81F1E58
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker:: @ 81F1E61
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice:: @ 81F1E6A
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent:: @ 81F1E81
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent:: @ 81F1EAD
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	release
	end

Route112_EventScript_RematchTrent:: @ 81F1ECC
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry:: @ 81F1EE3
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol:: @ 81F1EFA
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant:: @ 81F1F11
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla:: @ 81F1F28
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_LeaderGoingToAwakenThing: @ 81F1F3F
	.string "Hey, man, is our leader really able\n"
	.string "to harness all that energy?$"

Route112_Text_YeahWeNeedMeteorite: @ 81F1F7A
	.string "Sounds like it, yeah. But I heard\n"
	.string "we need a Meteorite to do it.$"

Route112_Text_OhThatsWhyCrewWentToFallarbor: @ 81F1FBA
	.string "Oh, I get it now. That's why the rest\n"
	.string "of the crew went out to Cayuga.$"

Route112_Text_CantLetAnyonePassUntilTheyreBack: @ 81F2003
	.string "You got it. And until they come back,\n"
	.string "we're not to let anyone pass, right.$"

Route112_Text_NotEasyToGetBackToLavaridge: @ 81F204E
	.string "Eh, I'd like to get to Wheatfield, but if\n"
	.string "I went down these ledges, it'd be no\l"
	.string "easy matter to get back to Grand\l"
	.string "Island.$"

Route112_Text_MtChimneyCableCarSign: @ 81F20C1
	.string "Mt. Lancelot Cable Car\n"
	.string "“A short walk {UP_ARROW} way!”$"

Route112_Text_MtChimneySign: @ 81F20ED
	.string "Mt. Lancelot\p"
	.string "“For Grand Island or the summit,\n"
	.string "please take the Cable Car.”$"

Route112_Text_RouteSignLavaridge: @ 81F2138
	.string "Route 112\n"
	.string "{LEFT_ARROW} Grand Island$"

//////////////////////////////
/////Froversion Scripts//////
////////////////////////////

Route112_EventScript_BobbyTrigger1::
	lock
	playbgm MUS_ENCOUNTER_MALE, 0
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	addobject LOCALID_BOBBY
	setvar VAR_MUGSHOT_ID, MUGSHOT_WASULA
	applymovement LOCALID_BOBBY, Movement_Route112_BobbyApproachesFroTrigger1
	waitmovement LOCALID_BOBBY
	msgbox Text_Route112_DoingGoodSoFarFro, MSGBOX_DEFAULT
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	switch VAR_STARTER_MON
	case 0, Script_Route112_WasulaBattleFlobra //fros starter is rascaloot
	case 1, Script_Route112_WasulaBattleEmboryps //fros starter is flobra
	case 2, Script_Route112_WasulaBattleRascaloot //fros starter is emboryps
	release
	end

Route112_EventScript_BobbyTrigger2::
	lock
	playbgm MUS_ENCOUNTER_MALE, 0
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	addobject LOCALID_BOBBY
	setvar VAR_MUGSHOT_ID, MUGSHOT_WASULA
	applymovement LOCALID_BOBBY, Movement_Route112_BobbyApproachesFroTrigger2
	waitmovement LOCALID_BOBBY
	msgbox Text_Route112_DoingGoodSoFarFro, MSGBOX_DEFAULT
	setflag FLAG_CAN_LOSE_NEXT_BATTLE
	switch VAR_STARTER_MON
	case 0, Script_Route112_WasulaBattleFlobra //fros starter is rascaloot
	case 1, Script_Route112_WasulaBattleEmboryps //fros starter is flobra
	case 2, Script_Route112_WasulaBattleRascaloot //fros starter is emboryps
	release
	end

Movement_Route112_BobbyApproachesFroTrigger1:
	walk_fastest_right
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	step_end

Movement_Route112_BobbyApproachesFroTrigger2:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	step_end

Text_Route112_DoingGoodSoFarFro:
	.string "Wow three badges? You've really come\n"
	.string "a long way.\p"
	.string "I was trying to take the cable car up\n"
	.string "the mountain so I could get to Grand\l"
	.string "Island to battle for my fourth badge,\l"
	.string "but there is a couple of clowns\l"
	.string "blocking the way.\p"
	.string "Anyway, why don't we have a friendly\n"
	.string "battle to see how strong you really are?$"

Script_Route112_WasulaBattleFlobra:
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Text_SummitCave_BobbyDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EventScript_Route112_BobbyBattleLost
	goto EventScript_Route112_BobbyBattleWon
	end

Script_Route112_WasulaBattleRascaloot:
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Text_SummitCave_BobbyDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EventScript_Route112_BobbyBattleLost
	goto EventScript_Route112_BobbyBattleWon
	end

Script_Route112_WasulaBattleEmboryps:
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Text_SummitCave_BobbyDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq EventScript_Route112_BobbyBattleLost
	goto EventScript_Route112_BobbyBattleWon
	end

EventScript_Route112_BobbyBattleLost:
	special HealPlayerParty
	msgbox Text_Route112_FroLostToBobby, MSGBOX_DEFAULT
	applymovement LOCALID_BOBBY, Movement_Route112_BobbyLeaves
	waitmovement LOCALID_BOBBY
	removeobject LOCALID_BOBBY
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY 
	setvar VAR_OLDALE_TOWN_STATE, 9
	release
	end

EventScript_Route112_BobbyBattleWon:
	msgbox Text_Route112_FroBeatBobby, MSGBOX_DEFAULT
	applymovement LOCALID_BOBBY, Movement_Route112_BobbyLeaves
	waitmovement LOCALID_BOBBY
	removeobject LOCALID_BOBBY
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY 
	setvar VAR_OLDALE_TOWN_STATE, 9
	release
	end 

Text_Route112_FroLostToBobby:
	.string "Good try Fro, but you're no match for\n"
	.string "me. Keep practicing. Anyway...\p"
	.string "Looks like we need to find a way to get\n"
	.string "access to the cable car.\p"
	.string "I'm going to head through Lancelot\n"
	.string "Cave and head into Fallarbor Town.\p"
	.string "I'll see if I can figure out why Team\n"
	.string "MAGA is blocking the way to the top of\l"
	.string "Mount Lancelot. See if you can keep up!$"

Text_Route112_FroBeatBobby:
	.string "No way, I can't believe it. I'll get\n"
	.string "you next time. Anyway...\p"
	.string "Looks like we need to find a way to get\n"
	.string "access to the cable car.\p"
	.string "I'm going to head through Lancelot\n"
	.string "Cave and head into Fallarbor Town.\p"
	.string "I'll see if I can figure out why Team MAGA\n"
	.string "is blocking the way to the top of\l"
	.string "Mount Lancelot. See if you can keep up!$"

Movement_Route112_BobbyLeaves:
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end
