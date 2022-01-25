LakeMeadVillage_FrosHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LakeMeadVillage_FrosHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakeMeadVillage_FrosHouse_1F_OnFrame	
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LakeMeadVillage_FrosHouse_1F_OnWarp	
	.byte 0

//Variables
// VAR_LITTLEROOT_INTRO_STATE 0 = Intro state which triggers intro event when warping to starting map. sets var to 1 after initial cutscene
// VAR_LITTLEROOT_INTRO_STATE 1 = In this state the player must speak to angelina to trigger event which allows player to enter the basement. sets var to 2 when complete
// VAR_LITTLEROOT_INTRO_STATE 2 = In this state the player must go to their room and go to sleep, ending the prolouge event and setting the var to 3
// VAR_LITTLEROOT_INTRO_STATE 3 = Player must enter Isiahs house; when set to 3 isiahs mom event will trigger promting you to return home and setting var to 4
// VAR_LITTLEROOT_INTRO_STATE 4 = Upon returning home mom event occurs; sets VAR_LITTLEROOT_INTRO_STATE to 5 and VAR_LITTLEROOT_TOWN_STATE 1, allowing professor give pokemon event to trigger
// VAR_LITTLEROOT_INTRO_STATE 5 =  as of now this serves as the final variable currently coded no special events (except 6 which offers one special dialouge option)
// VAR_LITTLEROOT_INTRO_STATE 6 = Unlocks special dialouge option for Isiah in village


// VAR_LITTLEROOT_TOWN_STATE 0 = Default Town State, prevents player from leaving town before finding professor and picking pokemon
// VAR_LITTLEROOT_TOWN_STATE 1 = Mom has told you Isiah was just here looking for you. Now you can try to leave town and professor will stop you and take you to his lab
// VAR_LITTLEROOT_TOWN_STATE 2 = Set after professor takes you to his lab. 
// VAR_LITTLEROOT_TOWN_STATE 3 = Set after dialouge telling you to pick pokemon inside lab. also prevents player from leaving lab without picking pokemon
// VAR_LITTLEROOT_TOWN_STATE 4 = set after you pick pokemon. You can now leave the lab. Triggers battle with john when leaving Lake mead village going to Jagow Way for the first time
// VAR_LITTLEROOT_TOWN_STATE 5 = set after battle with john. Final state as of now.


// VAR_OLDALE_TOWN_STATE 1 = this will be set to 1 in walmore town by visiting the pokemart. When set to 1 professor will give pokedex then set VAR_OLDALE_TOWN_STATE to 2.
// VAR_OLDALE_TOWN_STATE 2 = Set to this after recieved pokedex. Final state as of right now.

LakeMeadVillage_FrosHouse_1F_IsiahWasJustHere:
lock
msgbox T_FrosHouse1F_IsiahWasJustHere, MSGBOX_DEFAULT
setvar VAR_LITTLEROOT_TOWN_STATE, 1
setvar VAR_LITTLEROOT_INTRO_STATE, 5
clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_ISIAH
closemessage
release
end

//NEW GAME SEQUENCE STARTS HERE

LakeMead_FrosHouse_1F_SetFroFacingTV:
lockall
removeobject 2
applymovement 1, MovementAngelinaMoveNextToFro
waitmovement 1
applymovement OBJ_EVENT_ID_PLAYER,  LakeMeadVillage_FrosHouse_1F_FroFacesAngelina
msgbox LakeMeadVillage_Text_DidYouSeeThatBroadcast, MSGBOX_DEFAULT
special SpawnCameraObject
applymovement 1, MovementAngelinaJumps
playSE SE_M_BELLY_DRUM
waitse
waitmovement 1
applymovement 1, MovementAngelinaJumps
playSE SE_M_BELLY_DRUM
waitse
waitmovement 1
applymovement 1, MovementAngelinaJumps
playSE SE_M_BELLY_DRUM
waitse
waitmovement 1
applymovement OBJ_EVENT_ID_CAMERA, LakeMeadVillage_FrosHouse_1F_CameraFollowsAngelina
applymovement 1, MovementAngelinaRunsToDoor
waitmovement 1
msgbox LakeMeadVillage_Text_iSawTrumpsPokemon
applymovement 1, MovementAngelinaKicksDownDoor
playSE SE_EFFECTIVE
waitmovement 1
waitse
msgbox LakeMeadVillage_Text_AngelinaKickedDoor, MSGBOX_DEFAULT
applymovement OBJ_EVENT_ID_CAMERA, LakeMeadVillage_FrosHouse_1F_CameraReturnToFro
waitmovement OBJ_EVENT_ID_CAMERA
special RemoveCameraObject
setvar VAR_LITTLEROOT_INTRO_STATE, 1
releaseall
end

LakeMeadVillage_FrosHouse_1F_FroFacesAngelina:
face_right
step_end

LakeMeadVillage_FrosHouse_1F_CameraReturnToFro:
walk_up
walk_up
walk_up
walk_up
walk_left
walk_left
walk_left
step_end

LakeMeadVillage_FrosHouse_1F_CameraFollowsAngelina:
walk_fast_right
walk_fast_right
walk_fast_right
walk_fast_down
walk_fast_down
walk_fast_down
walk_fast_down
step_end

MovementAngelinaKicksDownDoor:
jump_in_place_up_down
step_end

MovementAngelinaJumps:
jump_in_place_up
step_end

MovementAngelinaRunsToDoor:
walk_fast_right
walk_fast_right
walk_fast_right
walk_fast_down
walk_fast_down
walk_fast_down
walk_fast_down
step_end

MovementAngelinaMoveNextToFro:
walk_up
face_left
step_end

MovementFroFacesTV:
face_up
step_end

LakeMeadVillage_FrosHouse_1F_OnLoad:
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq LakeMeadVillage_FrosHouse_1F_MoveMom2
	compare VAR_LITTLEROOT_INTRO_STATE, 0
	goto_if_eq LakeMeadVillage_FrosHouse_1F_MoveMom
	end

LakeMeadVillage_FrosHouse_1F_MoveMom2:
	setobjectxyperm 2, 2, 11
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	end

LakeMeadVillage_FrosHouse_1F_MoveMom:
	setobjectxyperm 2, 8, 2
	removeobject 2
	setflag FLAG_HIDE_MOM
	end

LakeMead_FrosHouse_1F_SetFroNorth:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

LakeMeadVillage_FrosHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, LakeMeadVillage_FrosHouse_1F_IsiahWasJustHere
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, LakeMead_FrosHouse_1F_SetFroFacingTV
	.2byte 0

LakeMeadVillage_FrosHouse_1F_OnWarp:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, LakeMead_FrosHouse_1F_SetFroNorth
	.2byte 0

//Angelina NPC Script

LakeMeadVillage_FrosHouse_1F_Angelina_NPC::
	lock
	faceplayer
	addobject 2
	clearflag FLAG_HIDE_MOM
	compare VAR_LITTLEROOT_INTRO_STATE, 1
	goto_if_eq LakeMeadVillage_FrosHouse_1F_WhatHaveYouDone
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillage_FrosHouse_1F_HahaYoureGrounded
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	goto_if_ge Script_LakeMeadVillage_FrosHouse_1F_Angelina_StandardDialouge
	end
	
Script_LakeMeadVillage_FrosHouse_1F_HahaYoureGrounded::
	msgbox Text_LakeMeadVillage_FrosHouse_1F_HahaYoureGrounded, MSGBOX_DEFAULT
	release
	end

Script_LakeMeadVillage_FrosHouse_1F_Angelina_StandardDialouge::	
	random 3
	switch VAR_RESULT
	case 0, Script_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge1
	case 1, Script_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge2
	case 2, Script_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge3
	end

Script_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge1::
	msgbox Text_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge1, MSGBOX_DEFAULT
	release
	end
	
Script_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge2::
	msgbox Text_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge2, MSGBOX_DEFAULT
	release
	end

Script_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge3::
	msgbox Text_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge3, MSGBOX_DEFAULT
	release
	end
	
// End Angelina NPC

// MOM NPC
LakeMeadVillage_FrosHouse_1F_Mom_NPC::
	lock
	faceplayer
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillage_FrosHouse_1F_GoDownstairsStandard
	compare VAR_LITTLEROOT_TOWN_STATE, 4
	goto_if_ge Script_LakeMeadVillage_FrosHouse_1F_MomAfterRecievedPoke
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_eq Script_LakeMeadVillage_FrosHouse_IsiahLookingForYou
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	goto_if_ge Script_LakeMeadVillage_FrosHouse_1F_MomRandom1
	end

Script_LakeMeadVillage_FrosHouse_IsiahLookingForYou:
	msgbox T_FrosHouse1F_IsiahWasJustHere, MSGBOX_NPC
	end

Script_LakeMeadVillage_FrosHouse_1F_GoDownstairsStandard::
	msgbox Text_LakeMeadVillage_FrosHouse_1F_GoDownstairsStandard, MSGBOX_DEFAULT
	release
	end

Script_LakeMeadVillage_FrosHouse_1F_MomRandom1::
	random 3
	switch VAR_RESULT
	case 0, Script_LakeMeadVillage_FrosHouse_1F_MomRandomText1
	case 1, Script_LakeMeadVillage_FrosHouse_1F_MomRandomText2
	case 2, Script_LakeMeadVillage_FrosHouse_1F_MomRandomText3
	end

Script_LakeMeadVillage_FrosHouse_1F_MomAfterRecievedPoke::
	goto_if_set FLAG_BADGE05_GET, PlayersHouse_1F_EventScript_TryGiveAmuletCoin
	msgbox T_FrosHouse1F_YouFoundTheProfessor, MSGBOX_NPC
	end

Script_LakeMeadVillage_FrosHouse_1F_MomRandomText1::
msgbox Text_LakeMeadVillage_FrosHouse_1F_MomRandomText1, MSGBOX_DEFAULT
release
end

Script_LakeMeadVillage_FrosHouse_1F_MomRandomText2::
msgbox Text_LakeMeadVillage_FrosHouse_1F_MomRandomText2, MSGBOX_DEFAULT
release
end

Script_LakeMeadVillage_FrosHouse_1F_MomRandomText3::
msgbox Text_LakeMeadVillage_FrosHouse_1F_MomRandomText3, MSGBOX_DEFAULT
release
end




// END MOM NPC
LakeMeadVillage_FrosHouse_1F_WhatHaveYouDone::
	lockall
	msgbox LakeMeadVillage_Text_WhatHaveYouDone, MSGBOX_DEFAULT	
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	applymovement 2, MovementMomSeesDoor
	waitmovement 2
	msgbox LakeMeadVillage_Text_MomNoticesDamage, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, MovementFroShocked
	applymovement 1, MovementAngelinaShocked
	playSE SE_PIN
	waitmovement 1,
	applymovement OBJ_EVENT_ID_PLAYER, MovementFroMovesOutOfDoorway
	applymovement 1, MovementAngelinaMovesOutOfDoorway
	waitmovement 1
	msgbox LakeMeadVillage_Text_MomGroundsFro, MSGBOX_DEFAULT
	applymovement 1, MovementAngelinaMovesOutOfWay
	Waitmovement 1
	releaseall
	end

LakeMeadVillage_FrosHouse_1F_MomsRoomBetterNotGoUp::
	lock
	msgbox Text_LakeMeadVillage_FrosHouse_1F_MomsRoomBetterNotGoUp, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_BackAwayFromMomsRoom
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

LakeMeadVillage_FrosHouse_1F_BetterNotGoOut::
	lock
	compare VAR_LITTLEROOT_INTRO_STATE, 1
	goto_if_eq Script_LakeMeadVillage_FrosHouse_1F_CheckTheDamage
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillage_FrosHouse_1F_YoureGroundedGoDownstairs
	release
	end

Script_LakeMeadVillage_FrosHouse_1F_CheckTheDamage::
	msgbox Text_LakeMeadVillage_FrosHouse_1F_CheckTheDamage, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_BackAwayFromFrontDoor
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
Script_LakeMeadVillage_FrosHouse_1F_YoureGroundedGoDownstairs::
	msgbox Text_LakeMeadVillage_FrosHouse_1F_YoureGroundedGoDownstairs, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_BackAwayFromFrontDoor
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end
	
Script_LakeMeadVillage_FrosHouse_1F_TV::
	compare VAR_LITTLEROOT_INTRO_STATE, 1
	goto_if_eq Script_LakeMeadVillageFros_1F_TV1
	goto_if_gt Script_LakeMeadVillageFros_1F_TV2
	end
	
Script_LakeMeadVillageFros_1F_TV1::
	msgbox Text_LakeMeadVillageFros_1F_TV1, MSGBOX_SIGN
	end

Script_LakeMeadVillageFros_1F_TV2::
	msgbox Text_LakeMeadVillageFros_1F_TV2, MSGBOX_SIGN
	
Movement_BackAwayFromFrontDoor:
walk_up
step_end

Movement_BackAwayFromMomsRoom:
walk_down
step_end

MovementAngelinaMovesOutOfDoorway:
walk_up
step_end

MovementFroMovesOutOfDoorway:
walk_fast_right
face_up
step_end

MovementAngelinaMovesOutOfWay:
walk_left
face_right
step_end

MovementAngelinaShocked:
emote_exclamation_mark
face_up
step_end

MovementFroShocked:
emote_exclamation_mark
face_up
step_end

MovementMomSeesDoor:
walk_down
walk_down
walk_down
walk_down
walk_down
step_end
	
LakeMeadVillage_Text_DidYouSeeThatBroadcast:
.string "Angelina: Anthony, did you see that?\p"
.string "I can't believe a real Pokémon has \nbeen discovered!\p"
.string "I can't wait to battle with mine!\p"
.string "{PLAYER}: Calm down Angelina.\nyou can't trust a word Trump says.\p"
.string "Angelina: I saw it with my own \ntwo eyes.$" 

LakeMeadVillage_Text_iSawTrumpsPokemon:
.string "I saw Trumps Pokemon do this!$"

LakeMeadVillage_Text_AngelinaKickedDoor:
.string "Angelina used Hi Jump Kick!\p"
.string "Angelina damaged the door.$"

LakeMeadVillage_Text_WhatHaveYouDone:
.string "{PLAYER}: Look at what you did!$"

LakeMeadVillage_Text_MomNoticesDamage:
.string "Mom: Anthony, Angelina. What was \nthat noise?$"

LakeMeadVillage_Text_MomGroundsFro:
.string "Angelina: Mom! Um... Um...\p"
.string "{PLAYER}: Mom, Angelina saw Trump \non TV saying he discovered a...\p"
.string "Angelina: He found a real live\nPokémon!\pAnthony got so mad at Trumps \nannouncement he came over here and \lkicked the door!\p"
.string "Mom: Anthony is this true?\p"
.string "{PLAYER}: No Mom, I swear it was \nAngeli...\p"
.string "Angelina: Yes mom it's true you \nknow how Anthony gets when \lTrump speaks!\p"
.string "Mom: That is true.\pYou're grounded for a year Anthony.\p"
.string "{PLAYER}: I didn't even do anything! \nIt was...\p"
.string "Mom: Do not talk back to me. \nGo down to the basement and think \labout what you've done.\p"
.string "{PLAYER}: But Mom...\p"
.string "Mom: No but's! \pDownstairs now before I make it two \nyears.$"

Text_LakeMeadVillage_FrosHouse_1F_MomsRoomBetterNotGoUp:
	.string "Mom and Dad's room is off limits.$"

Text_LakeMeadVillage_FrosHouse_1F_CheckTheDamage:
	.string "You better check the damage \nAngelina caused before going out.$"
	
Text_LakeMeadVillage_FrosHouse_1F_YoureGroundedGoDownstairs:
	.string "Mom: Anthony you can't go outside,\n"
	.string "you're grounded!$"
	
Text_LakeMeadVillage_FrosHouse_1F_HahaYoureGrounded:
	.string "Haha you're grounded!\p"
	.string "Now I have a year headstart to \ntrain my Pokémon.\p"
	.string "You'll never be as good as me.$"
	
Text_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge1:
	.string "I've been training my Jigglypuff \nthe whole time you were grounded!$"

Text_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge2:
	.string "The world has changed a lot since \nyou were allowed outside.$"
	
Text_LakeMeadVillage_FrosHouse_1F_AngelinaNPCDialouge3:
	.string "I saw on the news that Sy Pathway \nhad to temporarily be closed for \lmaintenence.$"
	
Text_LakeMeadVillage_FrosHouse_1F_GoDownstairsStandard:
	.string "Downstairs now before I make it two \nyears.$"

Text_LakeMeadVillage_FrosHouse_1F_MomRandomText1:
	.string "Good morning Anthony.\pHave some pancakes before going \nout!$"
	
Text_LakeMeadVillage_FrosHouse_1F_MomRandomText2:
	.string "Professor Tilyou was looking for \nyou. You should go over to his lab \lwhen you get a chance.$"
	
Text_LakeMeadVillage_FrosHouse_1F_MomRandomText3:
	.string "Bobby and John have been waiting \nfor you to start training their \lPokémon. \pI think they were going to meet you \lat Professor Tilyou's lab.$"
	
Text_LakeMeadVillageFros_1F_TV1:
	.string "President Trump is discussing the \neconomic impact Pokémon will have, \lspecifically in the technology \lsector.$"
	
Text_LakeMeadVillageFros_1F_TV2:
	.string "A news broadcast is showing a \nPokémon construction crew hard \lat work.$"
	
T_FrosHouse1F_IsiahWasJustHere:
	.string "Mom: Isiah was just here. He said \nhe left something in your room. \pHe was down there for a while \nlooking for it...$"
	
T_FrosHouse1F_YouFoundTheProfessor:
	.string "Mom: Oh you found the Professor? \nAnd he gave you your Pokémon? \pThat's great! Safe travels then, \nand good luck!$"
