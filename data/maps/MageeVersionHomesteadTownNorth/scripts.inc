.set LOCALID_SNOWFLAKE_CHALLENGER, 6

MageeVersionHomesteadTownNorth_MapScripts::
	.byte 0

Script_MageeVersionHomesteadTownNorth_FroChallengesMagee::
	lockall
		//set mugshot for fro
		msgbox Text_MageeVersionHomesteadTownNorth__FroWaiting, MSGBOX_NPC
		//set mugshot for magee
		msgbox Text_MageeVersionHomesteadTownNorth_RelaxAngelHairArms, MSGBOX_DEFAULT
		special SpawnCameraObject
		applymovement OBJ_EVENT_ID_CAMERA, HomesteadNorth_Movement_PanCameraUp
		applymovement LOCALID_SNOWFLAKE_CHALLENGER, SnowVillage_Movement_ChampionTakesBattlePosition
		applymovement OBJ_EVENT_ID_PLAYER, SnowVillage_Movement_PlayerTakesBattlePosition
		waitmovement 0
		goto Script_MageeVersionHomesteadTownNorth_Fro
		release
	end

Script_MageeVersionHomesteadTownNorth_Fro::
		setflag FLAG_SYS_NO_BAG_USE
		setflag FLAG_FORCE_BATTLE_STYLE_SET
		setflag FLAG_CAN_LOSE_NEXT_BATTLE
		//set mugshot for magee
		trainerbattle_single TRAINER_MAGEEVERSION_FRO_SNOWFLAKE_CHALLENGER, Text_MageeVersionHomesteadTownNorth_FroIntro, Text_MageeVersionHomesteadTownNorth_FroPostBattleMessage, Script_MageeVersionHomesteadTownNorth_FroResult, NO_MUSIC
	end

Script_MageeVersionHomesteadTownNorth_FroResult:
	clearflag FLAG_CAN_LOSE_NEXT_BATTLE
	clearflag FLAG_SYS_NO_BAG_USE
	clearflag FLAG_FORCE_BATTLE_STYLE_SET
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Script_MageeVersionHomesteadTownNorth_FroBattleLost
	goto Script_MageeVersionHomesteadTownNorth_FroBattleWon
end

Script_MageeVersionHomesteadTownNorth_FroBattleLost:
	//set mugshot for magee
	msgbox Text_MageeVersionHomesteadTownNorth_FroBattleLost, MSGBOX_DEFAULT
	//set mugshot for fro
	msgbox Text_MageeVersionHomesteadTownNorth_FroBattleLostResponse, MSGBOX_DEFAULT
	//set mugshot badge???
	playse SE_SELECT
	msgbox Text_MageeVersionHomesteadTownNorth_MageeGivesFroBadge, MSGBOX_DEFAULT
	//set mugshot for fro
	msgbox Text_MageeVersionHomesteadTownNorth_FroSaysBye, MSGBOX_DEFAULT
	applymovement LOCALID_SNOWFLAKE_CHALLENGER, Movement_MageeVersionHomesteadNorth_FroLeaves
	waitmovement LOCALID_SNOWFLAKE_CHALLENGER
	//play sad music sound effect
	special RemoveAllPartySlots
	fadescreenspeed FADE_TO_BLACK, 24
	warpsilent MAP_VERMILLION_BEACH, 255, 15, 17
	release
end

Script_MageeVersionHomesteadTownNorth_FroBattleWon:
	//set mugshot for magee
	msgbox Text_MageeVersionHomesteadTownNorth_FroBattleWon, MSGBOX_DEFAULT
	fadescreenspeed FADE_TO_BLACK, 24
    special GameClear
    waitstate
    releaseall
    end
end

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
////////////////////////MOVEMENT SCRIPTS//////////////////////////
////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////


Movement_MageeVersionHomesteadNorth_FroLeaves:
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	step_end


//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////TEXT SCRIPTS////////////////////////////
////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////

Text_MageeVersionHomesteadTownNorth__FroWaiting:
	.string "Fro: {PLAYER}, I've been waiting here since\n"
	.string "I finished my 15 mile run at 5 A.M.\p"
	.string "This is unacceptable.$"

Text_MageeVersionHomesteadTownNorth_RelaxAngelHairArms:
	.string "{PLAYER}: Settle down there {COLOR LIGHT_BLUE}Angel Hair\n"
	.string "Arms.\p"
	.string "{COLOR DARK_GREY}Go to your side of the battle rink\n"
	.string "and I will make this quick and painless\l"
	.string "for you.$"

Text_MageeVersionHomesteadTownNorth_FroIntro:
	.string "Fro: {PLAYER}, Now you will experience\n"
	.string "my absolute power.$"

Text_MageeVersionHomesteadTownNorth_FroPostBattleMessage:
	.string "Speen, Violence and Momentum!$"

Text_MageeVersionHomesteadTownNorth_FroBattleLost:
	.string "{PLAYER}: I can NOT believe I lost to YOU.\p"
	.string "Here is your stinkin' badge!\p"
	.string "That is the last straw, I'm done battling\n"
	.string "Pokémon.\p"
	.string "I am so tired of being a Gym Leader.\p"
	.string "I am retiring and moving away, preferably\n"
	.string "to someplace with a {COLOR DYNAMIC_COLOR6}Sandy Beach.\p"
	.string "{COLOR DARK_GREY}Thanks for ruining my life, {COLOR RED}Fro.$"

Text_MageeVersionHomesteadTownNorth_FroBattleLostResponse:
	.string "Fro: Stop being so dramatic and hand\n"
	.string "it over.$"

Text_MageeVersionHomesteadTownNorth_MageeGivesFroBadge:
	.string "{COLOR GREEN}{PLAYER} gives Fro the Tit Badge.$"

Text_MageeVersionHomesteadTownNorth_FroSaysBye:
	.string "Thanks chump, enjoy your retirement!$"

Text_MageeVersionHomesteadTownNorth_FroBattleWon:
	.string "Easy as Pie.$"
