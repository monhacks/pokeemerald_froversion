JagowWay_MapScripts::
	.byte 0


//Need to code an event that will stop player from going south near walmore town until after pokedex is recived in tilyous lab in lake mead village.
//At this point the variables will be VAR_LITTLEROOT_TOWN_STATE 5, VAR_LAKE_MEAD_VILLAGE_INTRO_STATE 5 or 6 depending on if special dialouge was unlocked and VAR_OLDALE_TOWN_STATE 2
//FLAG_SYS_POKEMON_GET will also need to be set for this event to take place

//Scripts

Script_JagowWay_TrainTracks_Right::
	lock
	msgbox T_JagowWay_TrainTracks, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_TrainTracks_Right
	waitmovement OBJ_EVENT_ID_PLAYER
	closemessage
	release
	end

Script_JagowWay_TrainTracks_Left::
	lock
	msgbox T_JagowWay_TrainTracks, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_TrainTracks_Left
	waitmovement OBJ_EVENT_ID_PLAYER
	closemessage
	release
	end


Script_JagowWay_StarterBattle:: 
	lock
	addobject 1
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	applymovement 1, M_JagowWay_JohnChallengesFro
	waitmovement 1
	msgbox T_JagowWay_JohnBattleDialouge, MSGBOX_DEFAULT
	closemessage
	msgbox T_JagowWay_JohnBattleDialouge2, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 1, Script_JagowWay_StarterBattleRascaloot
	case 2, Script_JagowWay_StarterBattleFlobra
	case 3, Script_JagowWay_StarterBattleEmboryps
	end
	
Script_JagowWay_StarterBattleRascaloot:
	setvar VAR_MUGSHOT_ID, MUGSHOT_JOHNM
	trainerbattle_no_intro TRAINER_JOHN_JAGOW_WAY_MUDKIP, T_JagowWay_JohnDefeated
	goto Script_JagowWay_AfterJohnBattle
	end

Script_JagowWay_StarterBattleFlobra:
	setvar VAR_MUGSHOT_ID, MUGSHOT_JOHNM
	trainerbattle_no_intro TRAINER_JOHN_JAGOW_WAY_TREECKO, T_JagowWay_JohnDefeated
	goto Script_JagowWay_AfterJohnBattle
	end

Script_JagowWay_StarterBattleEmboryps:
	setvar VAR_MUGSHOT_ID, MUGSHOT_JOHNM
	trainerbattle_no_intro TRAINER_JOHN_JAGOW_WAY_TORCHIC, T_JagowWay_JohnDefeated
	goto Script_JagowWay_AfterJohnBattle
	end	
	
Script_JagowWay_StarterBattle2:: 
	lock
	addobject 1
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	applymovement 1, M_JagowWay_JohnChallengesFro2
	waitmovement 1
	msgbox T_JagowWay_JohnBattleDialouge, MSGBOX_DEFAULT
	closemessage
	msgbox T_JagowWay_JohnBattleDialouge2, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 1, Script_JagowWay_StarterBattleRascaloot
	case 2, Script_JagowWay_StarterBattleFlobra
	case 3, Script_JagowWay_StarterBattleEmboryps
	end
	
Script_JagowWay_AfterJohnBattle:
setvar VAR_LITTLEROOT_TOWN_STATE, 5
msgbox T_JohnAfterBattle MSGBOX_DEFAULT
giveitem ITEM_POKE_BALL, 5
msgbox T_JW_JagowWoodsClosed, MSGBOX_DEFAULT
closemessage
fadedefaultbgm
applymovement 1, M_JagowWay_JohnLeaves
waitmovement 1
removeobject 1
setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
release
end


release
end


Script_JagowWay_NorthSignPost::
msgbox T_JagowWay_SignPostForLakeMead, MSGBOX_SIGN
release
end

//Movements

M_TrainTracks_Left:
walk_right
step_end

M_TrainTracks_Right:
walk_left
step_end

M_JagowWay_JohnLeaves:
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
step_end

M_JagowWay_JohnChallengesFro:
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
step_end

M_JagowWay_JohnChallengesFro2:
walk_down
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
step_end

//Text

T_JagowWay_SignPostForLakeMead:
	.string "{DOWN_ARROW} Walmore Town \n{UP_ARROW} Sy Pathway$"
	

T_JagowWay_JohnBattleDialouge:
	.string "John: Hey Fro, before you go out \ninto the wild why don't I show you \lhow to battle with your new \lPokemon?\p"
	.string "Fro: How hard can it be? Is this \nreally necessary?$"
	
T_JagowWay_JohnBattleDialouge2: 
	.string "John: Experience is a valuable \nteacher. Now let's battle!$"

T_JagowWay_JohnDefeated:
	.string "John: You're a natural, Fro!$"
	
T_JohnAfterBattle:
	.string "John: Great job Fro. I look forward \nto seeing you grow as a trainer. \pNext time I won't take it easy on \nyou.\p"
	.string "Oh yea, I just remembered,\nyou've never caught a Pokémon in the\lwild!\p" 
	.string "I hear Walmore Town's Pokémart is \nsold out of Pokéballs. \pHere take these.$"

T_JagowWay_TrainTracks:
	.string "Mom always says to stay of the \ntrain tracks. You could get hurt.$"

T_JW_JagowWoodsClosed:
	.string "You want to use these once you've \nweakened a wild Pokémon, it will be \leasier to catch that way.\p"
	.string "Normally I would say to go to Summit\nCity and start your Gym Challenge \lthere"
	.string "but Bobby already\lmade it there and the entrance is \lblocked.\p"
	.string "Looks like all of us will have to \nstart the Gym Challenge in Lynch \lPark instead.\p"
	.string "I'm going to stop home real quick \nsince it's on the way, but you can \ljust take Walmore to Lancelot to get \lthere.\p"
	.string "Better get going, we've got a lot of \ncatching up to do. \pSee you, and good luck!$"
