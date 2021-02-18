.set LOCALID_GREETER, 1
.set LOCALID_SNOWFLAKE_CHAMPION, 7

GratwickPeaks_MapScripts::
	.byte 0

GratwickPeaks_OnWarp: 
	.2byte 0

GratwickPeaks_EventScript_PlayerFaceUp::
	removeobject 14
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

GratwickPeaks_OnFrame::
	.2byte 0

@------------------------------------------------------------------------------------------------------
@-------------------------------SCRIPTS----------------------------------------------------------------
@------------------------------------------------------------------------------------------------------


GratwickPeaks_EventScript_BugCatcher::
	lockall
	msgbox GratwickPeaks_Text_MyPokemonIsStrong, MSGBOX_NPC
	releaseall
end

GratwickPeaks_EventScript_Camper::
	lockall
	msgbox GratwickPeaks_Text_IWillWinThisBattle, MSGBOX_NPC
	releaseall
end



GratwickPeaks_EventScript_NormalNPCDialouge1::
	msgbox GratwickPeaks_Text_NormalNPCDialouge1, MSGBOX_NPC
	release
end

GratwickPeaks_EventScript_Battle::
	applymovement 5, GratwickPeaks_Movement_WalkJumpRight
	waitmovement 0
	applymovement 10, GratwickPeaks_Movement_walkJumpLeft
	waitmovement 0
	setvar VAR_TEMP_0, 1
end

GratwickPeaks_EventScript_FinalBattle::
	lock
	msgbox GratwickPeaks_Text_YouDontHaveEnoughSnowflakes, MSGBOX_NPC
	release
	end

GratwickPeaks_EventScript_StartFinalBattle:
	msgbox GratwickPeaks_Text_CongratsYouCollectedAllSnowflakes, MSGBOX_NPC
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp
	applymovement LOCALID_SNOWFLAKE_CHAMPION, GratwickPeaks_Movement_ChampionTakesBattlePosition
	applymovement OBJ_EVENT_ID_PLAYER, GratwickPeaks_Movement_PlayerTakesBattlePosition
	waitmovement 0
	trainerbattle_single TRAINER_JOHANNA, GratwickPeaks_Text_LetTheBattleBegin, GratwickPeaks_Text_CongratsYouAreTheNewChampion,GratwickPeaks_Text_GameBoyKidAlreadyRecievedGreatBalls
	release
end

	
GratwickPeaks_EventScript_GameBoyKid::
lockall
	//goto_if_set FLAG_GratwickPeaks_GREAT_BALLS_RECIEVED, GratwickPeaks_EventScript_GameBoyKidAlreadyRecievedGreatBalls
	msgbox GratwickPeaks_Text_GameBoyKidGiveGreatBalls, MSGBOX_NPC
	giveitem ITEM_GREAT_BALL, 15
	//setflag FLAG_GratwickPeaks_GREAT_BALLS_RECIEVED
	releaseall
	end

GratwickPeaks_EventScript_GameBoyKidAlreadyRecievedGreatBalls:
	msgbox  GratwickPeaks_Text_GameBoyKidAlreadyRecievedGreatBalls, MSGBOX_NPC
	releaseall
	end


GratwickPeaks_EventScript_CaveGuard::
	lockall
		msgbox GratwickPeaks_Text_CaveGuard, MSGBOX_NPC
		releaseall
	end

GratwickPeaks_EventScript_HouseLocked::
	lock
		msgbox GratwickPeaks_Text_HouseLocked, MSGBOX_SIGN
		release
	end

GratwickPeaks_EventScript_Watcher::
lockall
	msgbox GratwickPeaks_Text_Watcher, MSGBOX_NPC
	releaseall
end


@------------------------------------------------------------------------------------------------------
@-------------------------------MOVEMENTS--------------------------------------------------------------
@------------------------------------------------------------------------------------------------------

GratwickPeaks_Movement_PlayerBegins:
	walk_up
	walk_up
	walk_up
	walk_up
step_end

GratwickPeaks_Movement_PlayerMovesToGreeter:
	emote_exclamation_mark
	walk_right
step_end

GratwickPeaks_Movement_PlayerCantLeave:
	walk_fastest_up
step_end

GratwickPeaks_Movement_CantEnterCave1:
	face_up
	emote_exclamation_mark
step_end

GratwickPeaks_Movement_CantEnterCave2:
	walk_fast_right
step_end

GratwickPeaks_Movement_walkJumpLeft:
	walk_fastest_left
	walk_fastest_left
	jump_left
	jump_right
	walk_fastest_right
	walk_fastest_right
	face_left
step_end

GratwickPeaks_Movement_WalkJumpRight:
	walk_fastest_right
	walk_fastest_right
	jump_right
	jump_left
	walk_fastest_left
	walk_fastest_left
	face_right
step_end

GratwickPeaks_Movement_ChampionTakesBattlePosition:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
step_end

GratwickPeaks_Movement_PlayerTakesBattlePosition:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
step_end

@------------------------------------------------------------------------------------------------------
@-------------------------------TEXTS------------------------------------------------------------------
@------------------------------------------------------------------------------------------------------

GratwickPeaks_Text_GreeterIntroDialouge:
	.string "Hey you there!\p"
	.string "Welcome to PLAGLACI TOWN!\p"
	.string "Please, come here so I can talk to you!$"

GratwickPeaks_Text_TownIntro:
	.string "Have you come to take the Snowflake\nchallenge?\p"
	.string "Oh, you have? How wonderful!\p"
	.string "The Snowflake Challenge is one of\nthe most popular events in the region.\p"
	.string "In order to beat the challenge you\nmust defeat all the trainers in PLAGLACI\lCAVERNS and collect Snowflakes from \leach of them.\p"
	.string "Once you have collected all 12 \nSnowflakes, you can challenge the \lcurrent Snowflake Champion on the \lBattle rink.\p"
	.string "Normally we love seeing all the\nnew challengers, but I must admit\lyou've arrived at a strange time.\p"
	.string "You see, there has been an outbreak\nof Pokerus in the area.\p"
	.string "Trainers will not battle you if any \nof your Pokemon have the virus. \lIt is extremely contagious.\p"
	.string "You will have to do your best to \nbeat all the trainers while keeping your \lPokemon safe.\p"
	.string "Good Luck!$"

GratwickPeaks_Text_GreeterStopsFromLeaving:
	.string "Don't leave yet, you still have to \ntake the challenge!$"

GratwickPeaks_Text_CantEnterCaveWithoutMask1:
	.string "Hold it right there partner!$"

GratwickPeaks_Text_CantEnterCaveWithoutMask2:
	.string "Are you tryin' to get your Pokemon sick?\p"
	.string "You can't enter this cave without\na mask to protect your Pokemon from \lcatching Pokerus!\p"
	.string "Why don't you see if the Pokemart\nhas any left?$"

GratwickPeaks_Text_DontForgetToPutMaskOn:
	.string "Looks like you found a Mask!\p"
	.string "Don't forget to put it on your Pokemon. \nA mask is no good if not worn properly!$"

GratwickPeaks_Text_NormalNPCDialouge1:
	.string "I take Pokemon hygiene very \nseriously.$"

GratwickPeaks_Text_PlayerRecievesMask:
	.string "The Pokemart told you I bought all \ntheir masks? \pWell, that is true. One can never be \ntoo safe in times like these. \pAlways good to be prepared.\p"
	.string "Oh you would like to know if you can \nhave one of my masks to take the \lSnowflake Challenge? \pWell I suppose I could spare one mask.$"

GratwickPeaks_Text_MaskHoarder_GoodLuck:
	.string "Good luck and stay safe!$"

GratwickPeaks_Text_CurrentChampionIntroText:
	.string "Hi there. Are you taking the \nSnowflake Challenge?\p"
	.string "That's Great! I am the current \nChampion and am looking forward to \lfacing you once you collect all the \lSnowflakes!\p"
	.string "Come see me once you've collected \nall 12 Snowflakes.$"

GratwickPeaks_Text_CongratsYouCollectedAllSnowflakes:
	.string "You've collected all 12 Snowflakes! \nIt looks like you're a worthy \lopponent, let's battle! \pTake position on the right side of \nthe Battle Rink!$"

GratwickPeaks_Text_LetTheBattleBegin:
	.string "Alright, we are in position, let the \nbattle begin!$"

GratwickPeaks_Text_YouDontHaveEnoughSnowflakes:
	.string "You don't have all the Snowflakes.\p"
	.string "Come see me once you've collected \nall 12 Snowflakes.$"

GratwickPeaks_Text_CongratsYouAreTheNewChampion:
	.string "Congrats. You are now the Snowflake \nChampion!$"

GratwickPeaks_Text_GameBoyKidGiveGreatBalls:
	.string "The Pokemart is running short on \nsupplies. This outbreak has made \lthings quite difficult. \pI don't want to catch any pokemon, \nI'm afraid they will give mine the \lPokerus. \pHere take these Great Balls away \nfrom me!$"

GratwickPeaks_Text_GameBoyKidAlreadyRecievedGreatBalls:
	.string "How are those Great Balls working \nout for you?$"

GratwickPeaks_Text_MyPokemonIsStrong:
	.string "I love battling, my Pokemon is so \nstrong.$"

GratwickPeaks_Text_IWillWinThisBattle:
	.string "This battle is within my grasp!$"

GratwickPeaks_Text_Watcher:
	.string "Oh this battle is so exciting to \nwatch!$"

GratwickPeaks_Text_CaveGuard:
	.string "...$"

GratwickPeaks_Text_HouseLocked:
	.string "This house is locked.$"