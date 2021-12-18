.set LOCALID_GREETER, 1
.set LOCALID_SNOWFLAKE_CHAMPION, 6

HomesteadNorth_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SnowVillage_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SnowVillage_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SnowVillageOnWarp
	.byte 0

SnowVillage_EventScript_PlayerFaceUp::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SnowVillage_OnFrame::
	map_script_2 VAR_HOMESTEAD_NORTH_STATE, 0, SnowVillage_EventScript_Intoduction
	map_script_2 VAR_OLDALE_TOWN_STATE, 13, SootopolisCity_EventScript_ZendanoCallsFro
	.2byte 0

SnowVillageOnWarp::
	map_script_2 VAR_OLDALE_TOWN_STATE, 13, LakeMead_FrosHouse_1F_SetFroWest
	.2byte 0


LakeMead_FrosHouse_1F_SetFroWest:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	end

SnowVillage_OnLoad::
	compare VAR_OLDALE_TOWN_STATE, 13
	goto_if_eq SnowVillage_EventScript_MoveChampion
	end

SnowVillage_EventScript_MoveChampion:
	setobjectxyperm LOCALID_SNOWFLAKE_CHAMPION, 32, 14
	setobjectmovementtype LOCALID_SNOWFLAKE_CHAMPION, MOVEMENT_TYPE_FACE_RIGHT
	end

@------------------------------------------------------------------------------------------------------
@-------------------------------SCRIPTS----------------------------------------------------------------
@------------------------------------------------------------------------------------------------------

SnowVillage_EventScript_Intoduction::
	applymovement OBJ_EVENT_ID_PLAYER, SnowVillage_Movement_PlayerBegins
	waitmovement 0
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement LOCALID_GREETER
	msgbox SnowVillage_Text_GreeterIntroDialouge, MSGBOX_DEFAULT
	msgbox SnowVillage_Text_TownIntro, MSGBOX_DEFAULT
	closemessage
	setvar VAR_HOMESTEAD_NORTH_STATE, 1
	release
end

SnowVillage_EventScript_StopPlayerFromLeaving::
	lock
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox SnowVillage_Text_GreeterStopsFromLeaving, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, SnowVillage_Movement_PlayerCantLeave
	waitmovement 0
	release
end

SnowVillage_EventScript_Greeter::
	lockall
	msgbox SnowVillage_Text_GreeterStopsFromLeaving, MSGBOX_NPC
	release
end

SnowVillage_EventScript_BugCatcher::
	lockall
	msgbox SnowVillage_Text_MyPokemonIsStrong, MSGBOX_NPC
	releaseall
end

SnowVillage_EventScript_Camper::
	lockall
	msgbox SnowVillage_Text_IWillWinThisBattle, MSGBOX_NPC
	releaseall
end

SnowVillage_EventScript_GetMaskBeforeEnteringCave::
lock
	msgbox SnowVillage_Text_CantEnterCaveWithoutMask1, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, SnowVillage_Movement_CantEnterCave1
	msgbox SnowVillage_Text_CantEnterCaveWithoutMask2
	applymovement OBJ_EVENT_ID_PLAYER, SnowVillage_Movement_CantEnterCave2
	waitmovement 0
	release
end

SnowVillage_EventScript_RemindPlayerToPutMaskOn::
	lock
	msgbox SnowVillage_Text_DontForgetToPutMaskOn, MSGBOX_NPC
	release
end

SnowVillage_EventScript_NormalNPCDialouge1::
	msgbox SnowVillage_Text_NormalNPCDialouge1, MSGBOX_NPC
	release
end

SnowVillage_EventScript_Battle::
	applymovement 4, SnowVillage_Movement_WalkJumpRight
	waitmovement 0
	applymovement 9, SnowVillage_Movement_walkJumpLeft
	waitmovement 0
	setvar VAR_TEMP_0, 1
end

SnowVillage_EventScript_FinalBattle::
	lock
	compare VAR_HOMESTEAD_NORTH_STATE, 13
	goto_if_eq SnowVillage_EventScript_StartFinalBattle
	goto_if_unset FLAG_MATT_INTRO, SnowVillage_EventScript_ChampionIntro
	msgbox SnowVillage_Text_YouDontHaveEnoughSnowflakes, MSGBOX_NPC
	release
	end

SnowVillage_EventScript_StartFinalBattle:
	msgbox SnowVillage_Text_CongratsYouCollectedAllSnowflakes, MSGBOX_NPC
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, HomesteadNorth_Movement_PanCameraUp
	applymovement LOCALID_SNOWFLAKE_CHAMPION, SnowVillage_Movement_ChampionTakesBattlePosition
	applymovement OBJ_EVENT_ID_PLAYER, SnowVillage_Movement_PlayerTakesBattlePosition
	waitmovement 0
	goto SootopolisCity_Gym_1F_EventScript_Juan
	trainerbattle_single TRAINER_JOHANNA, SnowVillage_Text_LetTheBattleBegin, SnowVillage_Text_CongratsYouAreTheNewChampion, SnowVillage_EventScript_EndGame
	release
end

SnowVillage_EventScript_EndGame:
	fadescreenspeed FADE_TO_BLACK, 24
    special GameClear
    waitstate
    releaseall
    end

SnowVillage_EventScript_ChampionIntro:
	setflag FLAG_MATT_INTRO
	msgbox SnowVillage_Text_CurrentChampionIntroText, MSGBOX_NPC
	checkitem ITEM_SNOWFLAKE, 12
	compare VAR_RESULT, TRUE
	goto_if_eq SnowVillage_EventScript_StartFinalBattle
	release
	end

	
SnowVillage_EventScript_GameBoyKid::
lockall
	goto_if_set FLAG_SNOWVILLAGE_GREAT_BALLS_RECIEVED, SnowVillage_EventScript_GameBoyKidAlreadyRecievedGreatBalls
	msgbox SnowVillage_Text_GameBoyKidGiveGreatBalls, MSGBOX_NPC
	giveitem ITEM_GREAT_BALL, 15
	setflag FLAG_SNOWVILLAGE_GREAT_BALLS_RECIEVED
	releaseall
	end

SnowVillage_EventScript_GameBoyKidAlreadyRecievedGreatBalls:
	msgbox  SnowVillage_Text_GameBoyKidAlreadyRecievedGreatBalls, MSGBOX_NPC
	releaseall
	end


SnowVillage_EventScript_CaveGuard::
	lockall
		msgbox SnowVillage_Text_CaveGuard, MSGBOX_NPC
		releaseall
	end

SnowVillage_EventScript_HouseLocked::
	lock
		msgbox SnowVillage_Text_HouseLocked, MSGBOX_SIGN
		release
	end

SnowVillage_EventScript_Watcher::
lockall
	msgbox SnowVillage_Text_Watcher, MSGBOX_NPC
	releaseall
end


@------------------------------------------------------------------------------------------------------
@-------------------------------MOVEMENTS--------------------------------------------------------------
@------------------------------------------------------------------------------------------------------

SnowVillage_Movement_PlayerBegins:
	walk_up
	walk_up
	walk_right
	walk_right
step_end

SnowVillage_Movement_PlayerMovesToGreeter:
	emote_exclamation_mark
	walk_right
step_end

SnowVillage_Movement_PlayerCantLeave:
	walk_fastest_up
step_end

SnowVillage_Movement_CantEnterCave1:
	face_up
	emote_exclamation_mark
step_end

SnowVillage_Movement_CantEnterCave2:
	walk_fast_right
step_end

SnowVillage_Movement_walkJumpLeft:
	walk_fastest_left
	walk_fastest_left
	jump_left
	jump_right
	walk_fastest_right
	walk_fastest_right
	face_left
step_end

SnowVillage_Movement_WalkJumpRight:
	walk_fastest_right
	walk_fastest_right
	jump_right
	jump_left
	walk_fastest_left
	walk_fastest_left
	face_right
step_end

SnowVillage_Movement_ChampionTakesBattlePosition:
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

SnowVillage_Movement_PlayerTakesBattlePosition:
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

SnowVillage_Text_GreeterIntroDialouge:
	.string "Hey you there!\p"
	.string "Welcome to Homestead North!$"

SnowVillage_Text_TownIntro:
	.string "Have you come to take the Snowflake\nchallenge?\p"
	.string "Oh, you have? How wonderful!\p"
	.string "The Snowflake Challenge is one of\nthe most popular events in the region.\p"
	.string "In order to beat the challenge you\nmust defeat all the trainers in Homestead\lCaverns and collect Snowflakes from \leach of them.\p"
	.string "Once you have collected all 12 \nSnowflakes, you can challenge the \lcurrent Gym Leader on the \lBattle rink.$"

SnowVillage_Text_GreeterStopsFromLeaving:
	.string "Good luck with the Snowflake Challenge!$"

SnowVillage_Text_CantEnterCaveWithoutMask1:
	.string "Hold it right there partner!$"

SnowVillage_Text_CantEnterCaveWithoutMask2:
	.string "Are you tryin' to get your Pokemon sick?\p"
	.string "You can't enter this cave without\na mask to protect your Pokemon from \lcatching Pokerus!\p"
	.string "Why don't you see if the Pokemart\nhas any left?$"

SnowVillage_Text_DontForgetToPutMaskOn:
	.string "Looks like you found a Mask!\p"
	.string "Don't forget to put it on your Pokemon. \nA mask is no good if not worn properly!$"

SnowVillage_Text_NormalNPCDialouge1:
	.string "I take Pokemon hygiene very \nseriously.$"

SnowVillage_Text_PlayerRecievesMask:
	.string "The Pokemart told you I bought all \ntheir masks? \pWell, that is true. One can never be \ntoo safe in times like these. \pAlways good to be prepared.\p"
	.string "Oh you would like to know if you can \nhave one of my masks to take the \lSnowflake Challenge? \pWell I suppose I could spare one mask.$"

SnowVillage_Text_MaskHoarder_GoodLuck:
	.string "Good luck and stay safe!$"

SnowVillage_Text_CurrentChampionIntroText:
	.string "Icee: Hi there {PLAYER}.\nAre you taking the \lSnowflake Challenge?\p"
	.string "I am the current Gym Leader\n and am looking forward to facing \lyou once you collect all the \lSnowflakes!\p"
	.string "Come see me once you've collected \nall 12 Snowflakes.$"

SnowVillage_Text_CongratsYouCollectedAllSnowflakes:
	.string "You've collected all 12 Snowflakes! \nIt looks like you're a worthy \lopponent, let's battle! \pTake position on the right side of \nthe Battle Rink!$"

SnowVillage_Text_LetTheBattleBegin:
	.string "Alright, we are in position, let the \nbattle begin!$"

SnowVillage_Text_YouDontHaveEnoughSnowflakes:
	.string "You don't have all the Snowflakes.\p"
	.string "Come see me once you've collected \nall 12 Snowflakes.$"

SnowVillage_Text_CongratsYouAreTheNewChampion:
	.string "Congrats. You are now the Snowflake \nChampion!$"

SnowVillage_Text_GameBoyKidGiveGreatBalls:
	.string "The Pokemart is running short on \nsupplies. This outbreak has made \lthings quite difficult. \pI don't want to catch any pokemon, \nI'm afraid they will give mine the \lPokerus. \pHere take these Great Balls away \nfrom me!$"

SnowVillage_Text_GameBoyKidAlreadyRecievedGreatBalls:
	.string "How are those Great Balls working \nout for you?$"

SnowVillage_Text_MyPokemonIsStrong:
	.string "I love battling, my Pokemon is so \nstrong.$"

SnowVillage_Text_IWillWinThisBattle:
	.string "This battle is within my grasp!$"

SnowVillage_Text_Watcher:
	.string "Oh this battle is so exciting to \nwatch!$"

SnowVillage_Text_CaveGuard:
	.string "...$"

SnowVillage_Text_HouseLocked:
	.string "This house is locked.$"

HomesteadNorth_Movement_PanCameraUp: @ 825D9B0
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end