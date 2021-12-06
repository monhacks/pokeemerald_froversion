LakeMeadVillage_TilyousLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MS_LakeMeadVillage_TilyousLab_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MS_LakeMeadVillage_TilyousLab_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MS_LakeMeadVillage_TilyousLab_OnWarp
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
// VAR_OLDALE_TOWN_STATE 2 = Set to this after recieved pokedex. Triggers Cutscene with military 

// Map Scripts

MS_LakeMeadVillage_TilyousLab_OnWarp:
	map_script_2 VAR_OLDALE_TOWN_STATE, 5, Script_TilyousLab_SetFroNorth
	.2byte 0
	

MS_LakeMeadVillage_TilyousLab_OnLoad::
	compare VAR_OLDALE_TOWN_STATE, 5
	goto_if_eq Script_TilyousLab_MoveBobbyAndTilyou
	compare VAR_LITTLEROOT_TOWN_STATE, 2
	goto_if_lt Script_TilyousLab_RemoveTilyouBobbyJohn
	goto_if_eq Script_TilyousLab_ShowTilyouBobbyJohn
	compare VAR_OLDALE_TOWN_STATE, 1
	goto_if_eq Script_TilyousLab_MoveTilyouPokedex
	end

MS_LakeMeadVillage_TilyousLab_OnFrame::
	map_script_2 VAR_OLDALE_TOWN_STATE, 5, Script_TilyousLab_IsiahTellsProfessorAboutTeamMAGA
	map_script_2 VAR_LITTLEROOT_TOWN_STATE, 2, Script_TilyousLab_PickAPokemon
	.2byte 0
	
//Scripts

Script_TilyousLab_MoveTilyouPokedex:
setobjectxyperm 1, 3, 2
setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
end

Script_TilyousLab_SetFroNorth:
turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
end

Script_TilyousLab_MoveBobbyAndTilyou:
clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
clearflag FLAG_HIDE_TILYOUS_LAB_ISIAH
addobject 2
addobject 9
setobjectxyperm 1, 6, 5
setobjectmovementtype 1, MOVEMENT_TYPE_NONE
setobjectxyperm 2, 5, 6
setobjectmovementtype 2, MOVEMENT_TYPE_FACE_UP
end


Script_TilyousLab_RemoveTilyouBobbyJohn:
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 9
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_TILYOU
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setflag FLAG_HIDE_TILYOUS_LAB_ISIAH
	end

Script_TilyousLab_ShowTilyouBobbyJohn:
	addobject 1
	addobject 2
	addobject 3
	removeobject 9
	setflag FLAG_HIDE_TILYOUS_LAB_ISIAH
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_TILYOU
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	clearflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setobjectxyperm 1, 6, 11
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	end
	
Script_TilyousLab_PickAPokemon:
	applymovement 1, M_TilyousLab_TilyouMovesToTop
	applymovement OBJ_EVENT_ID_PLAYER, M_TilyousLab_PlayerFollows
	waitmovement 1
	msgbox T_TilyousLab_TellPlayerToPick, MSGBOX_DEFAULT
	applymovement 2, M_TilyousLab_BobbyFacesTilyou
	waitmovement 2
	msgbox T_TilyousLab_BobbySaysFroCanGo MSGBOX_DEFAULT
	applymovement 3, M_TilyousLab_JohnFacesTilyou
	waitmovement 3
	msgbox T_TilyousLab_JohnAgrees MSGBOX_DEFAULT
	applymovement 2, M_TilyousLab_BobbyFacesDown
	applymovement 3, M_TilyousLab_JohnFacesDown
	waitmovement 3
	msgbox T_TilyousLab_OkAnthonyGoAhead, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	release
	end
	
Script_TilyousLab_DontLeaveBeforePickingAPokemon::
	lock
	msgbox T_TilyousLab_HeyDontGoYet, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, M_TilyousLab_PlayerCantLeave
	waitmovement OBJ_EVENT_ID_PLAYER
	closemessage
	release
	end

Script_TilyousLab_RascalootPokeball::
	lock
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_lt Script_TilyousLab_ProfTilyousPokeball
	showmonpic SPECIES_RASCALOOT, 10, 3
	msgbox T_TilyousLab_PickRascaloot, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, 1
	goto_if_eq Script_TilyousLab_RascalootYes
	closemessage
	release
	end
	
Script_TilyousLab_RascalootYes:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STARTER_MON 0
	givemon SPECIES_RASCALOOT, 5, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	removeobject 4
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_RASCALOOT
	waitfanfare
	msgbox T_TilyousLab_RascalootYes, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TilyousLab_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	goto_if_eq TilyousLab_BobbyAndJohnPick
	closemessage
	release
	end
	
TilyousLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto TilyousLab_BobbyAndJohnPick
	end
	
TilyousLab_BobbyAndJohnPick:
	msgbox T_TilyousLab_OkJohnYoureUp MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnFacesTilyou
	waitmovement 3
	msgbox T_TilyousLab_JohnSoundsGood, MSGBOX_DEFAULT
	closemessage
	compare VAR_STARTER_MON, 0
	goto_if_eq Script_TilyousLab_FroTookRascaloot
	compare VAR_STARTER_MON, 1
	goto_if_eq Script_TilyousLab_FroTookFlobra
	compare VAR_STARTER_MON, 2
	goto_if_eq Script_TilyousLab_FroTookEmboryps
	release
	end

Script_TilyousLab_FroTookRascaloot:
	applymovement 3, M_TilyousLab_JohnEmboryps
	waitmovement 3
	removeobject 6
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_EMBORYPS
	msgbox T_TilyousLab_JohnEmboryps, MSGBOX_DEFAULT
	closemessage
	msgbox T_TilyousLab_TilyouBobbysTurn, MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnEmborypsReturn
	applymovement 2, M_TilyousLab_BobbyFlobra
	waitmovement 2
	removeobject 5
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_FLOBRA
	msgbox T_TilyousLab_BobbyFlobra
	closemessage
	msgbox T_TilyousLab_YouAllHaveStarters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyousLab_BobbyFlobraExit
	applymovement 3, M_TilyousLab_JohnExits
	waitmovement 3
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	
	release
	end

Script_TilyousLab_FlobraPokeball::
	lock
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_lt Script_TilyousLab_ProfTilyousPokeball
	showmonpic SPECIES_FLOBRA, 10, 3
	msgbox T_TilyousLab_PickFlobra, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, 1
	goto_if_eq Script_TilyousLab_FlobraYes
	closemessage
	release
	end
	
	
Script_TilyousLab_FlobraYes:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STARTER_MON 1
	givemon SPECIES_FLOBRA, 5, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	removeobject 5
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_FLOBRA
	waitfanfare
	msgbox T_TilyousLab_FlobraYes, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TilyousLab_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	goto_if_eq TilyousLab_BobbyAndJohnPick
	closemessage
	release
	end	
	
Script_TilyousLab_FroTookFlobra:
	applymovement 3, M_TilyousLab_JohnRascaloot
	waitmovement 3
	removeobject 4
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_RASCALOOT
	msgbox T_TilyousLab_JohnRascaloot, MSGBOX_DEFAULT
	closemessage
	msgbox T_TilyousLab_TilyouBobbysTurn, MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnRascalootReturn
	applymovement 2, M_TilyousLab_BobbyEmboryps
	waitmovement 2
	removeobject 6
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_EMBORYPS
	msgbox T_TilyousLab_BobbyEmboryps
	closemessage
	msgbox T_TilyousLab_YouAllHaveStarters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyousLab_BobbyEmborypsExit
	applymovement 3, M_TilyousLab_JohnExits
	waitmovement 3
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end	
	
Script_TilyousLab_EmborypsPokeball::
	lock
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_lt Script_TilyousLab_ProfTilyousPokeball
	showmonpic SPECIES_EMBORYPS, 10, 3
	msgbox T_TilyousLab_PickEmboryps, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, 1
	goto_if_eq Script_TilyousLab_EmborypsYes
	closemessage
	release
	end
	
	
Script_TilyousLab_EmborypsYes:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STARTER_MON 2
	givemon SPECIES_EMBORYPS, 5, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	removeobject 6
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_EMBORYPS
	waitfanfare
	msgbox T_TilyousLab_EmborypsYes, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TilyousLab_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	goto_if_eq TilyousLab_BobbyAndJohnPick
	closemessage
	release
	end	
	
Script_TilyousLab_FroTookEmboryps:
	applymovement 3, M_TilyousLab_JohnFlobra
	waitmovement 3
	removeobject 5
	msgbox T_TilyousLab_JohnFlobra, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_FLOBRA
	msgbox T_TilyousLab_TilyouBobbysTurn, MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnFlobraReturn
	applymovement 2, M_TilyousLab_BobbyRascaloot
	waitmovement 2
	removeobject 4
	msgbox T_TilyousLab_BobbyRascaloot
	closemessage
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_RASCALOOT
	msgbox T_TilyousLab_YouAllHaveStarters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyousLab_BobbyRascalootExit
	applymovement 3, M_TilyousLab_JohnExits
	waitmovement 3
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end	


Script_TilyousLab_ProfTilyousPokeball:
	msgbox T_TilyousLab_ProfTilyousPokemon, MSGBOX_NPC
	release
	end

Script_TilyousLab_IsiahTellsProfessorAboutTeamMAGA::
lockall
special HealPlayerParty
msgbox T_TilyousLab_IsiahExplainsWhatHeSaw, MSGBOX_NPC
applymovement 9, M_TilyousLab_IsiahLeavesAfterSavingIsiah
waitmovement 9
applymovement 2, M_TilyousLab_BobbyFaceRight
waitmovement 2
msgbox T_TilyousLab_BobbyGivesFroPokeballs, MSGBOX_NPC
giveitem ITEM_POKE_BALL, 5
msgbox T_TilyousLab_BobbyGivesExpShare, MSGBOX_NPC
giveitem ITEM_EXP_SHARE, 1
msgbox T_TilyousLab_ComeOnFroLetsGo, MSGBOX_NPC
applymovement 2, M_TilyousLab_BobbyLeavesAfterSavingIsiah
waitmovement 2
setvar VAR_OLDALE_TOWN_STATE, 6
removeobject 2
setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
removeobject 9
setflag FLAG_HIDE_TILYOUS_LAB_ISIAH
releaseall
end



// Movements

M_TilyousLab_BobbyLeavesAfterSavingIsiah:
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
step_end

M_TilyousLab_IsiahLeavesAfterSavingIsiah:
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
step_end

M_TilyousLab_JohnFlobra:
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
face_up
step_end

M_TilyousLab_JohnFlobraReturn:
walk_left
walk_left
walk_left
walk_left
walk_left
walk_up
face_down
step_end

M_TilyousLab_BobbyRascaloot:
walk_fastest_down
walk_fastest_down
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_up
step_end

M_TilyousLab_BobbyRascalootExit:
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
step_end

M_TilyousLab_JohnRascaloot:
walk_down
walk_right
walk_right
walk_right
walk_right
face_up
step_end

M_TilyousLab_JohnRascalootReturn:
walk_left
walk_left
walk_left
walk_left
walk_up
face_down
step_end

M_TilyousLab_BobbyEmboryps:
walk_fastest_down
walk_fastest_down
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_up
step_end

M_TilyousLab_BobbyEmborypsExit:
walk_fastest_down
walk_fastest_left
walk_fastest_left
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
step_end

M_TilyousLab_JohnExits:
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
step_end

M_TilyousLab_BobbyFlobraExit:
walk_fastest_down
walk_fastest_left
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
walk_fastest_down
step_end

M_TilyousLab_BobbyFlobra:
walk_fastest_down
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_right
walk_fastest_down
walk_fastest_right
walk_fastest_right
walk_fastest_up
step_end


M_TilyousLab_JohnEmborypsReturn:
walk_down
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
walk_up
walk_up
face_down
step_end

M_TilyousLab_JohnEmboryps:
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_up
step_end

M_TilyousLab_PlayerCantLeave:
walk_up
step_end

M_TilyousLab_JohnFacesDown:
face_down
step_end

M_TilyousLab_BobbyFacesDown:
face_down
step_end

M_TilyousLab_JohnFacesTilyou:
face_right
step_end

M_TilyousLab_BobbyFacesTilyou:
face_right
step_end

M_TilyousLab_TilyouMovesToTop:
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
face_down
step_end

M_TilyousLab_PlayerFollows:
walk_up
walk_up
walk_up
walk_up
walk_up
walk_up
step_end

M_TilyousLab_BobbyFaceRight:
face_right
step_end


//NPCS

Script_TilyousLab_NPC_Tilyou::
lock
compare VAR_OLDALE_TOWN_STATE, 6
goto_if_eq Script_TilyousLab_Script_PostTeamMAGADialouge
compare VAR_OLDALE_TOWN_STATE, 1
goto_if_eq Script_TilyousLab_TilyouGivesPokedex
compare VAR_LITTLEROOT_TOWN_STATE, 3
goto_if_eq Script_TilyousLab_GoAheadAnthony
compare VAR_LITTLEROOT_TOWN_STATE 4
goto_if_ge Script_TilyousLab_GoodLuckOnYourAdventure
release
end

Script_TilyousLab_TilyouGivesPokedex:
faceplayer
msgbox T_TilyousLab_FroGivesParcel, MSGBOX_DEFAULT
applymovement 1, Common_Movement_Delay48
waitmovement 0
playfanfare MUS_OBTAIN_ITEM
msgbox T_TilyousLab_RecievedPokedex
waitfanfare
msgbox T_TilyousLab_ExplainPokedex
setflag FLAG_SYS_POKEDEX_GET
setflag FLAG_ADVENTURE_STARTED
removeitem ITEM_OAKS_PARCEL, 1
setvar VAR_OLDALE_TOWN_STATE, 2
closemessage
release
end

Script_TilyousLab_Script_PostTeamMAGADialouge:
faceplayer
msgbox T_TilyousLab_GetLeadersTogether, MSGBOX_NPC
release
end

Script_TilyousLab_GoAheadAnthony:
msgbox T_TilyousLab_GoAheadAnthony, MSGBOX_NPC
end

Script_TilyousLab_GoodLuckOnYourAdventure:
msgbox T_TilyousLab_GoodLuckOnYourAdventure, MSGBOX_NPC
end

Script_TilyousLab_NPC_John::
lock
msgbox T_TilyousLab_JohnLongTimeNoSee, MSGBOX_NPC
end

Script_TilyousLab_NPC_Bobby::
lock
msgbox T_TilyousLab_BobbyAllPokesAreViable, MSGBOX_NPC
end

Script_TilyousLab_NPC_Scientist1::
lock
compare VAR_LITTLEROOT_TOWN_STATE, 2
goto_if_gt Script_TilyousLab_NPC_Scientist1Dialouge2
msgbox T_TilyousLab_DoesntSpendAlotOfTimeInLab, MSGBOX_NPC
end

Script_TilyousLab_NPC_Scientist1Dialouge2:
msgbox T_TilyousLab_HeWontStayLong, MSGBOX_NPC
end

Script_TilyousLab_NPC_Scientist2::
lock
msgbox T_TilyousLab_WonAwards, MSGBOX_NPC
end


//Text

T_TilyousLab_TellPlayerToPick:
	.string "Prof. Tilyou: As you can see there \nare three Pokéballs on the table. \pI have one for you, one for John, \nand one for Bobby. \pThey were nice enough to wait for \nyou to be ungrounded to start \ltheir journeys. \pNow it is time to choose your \nPokémon. \pWho wants to go first?$"

T_TilyousLab_BobbySaysFroCanGo:
	.string "Bobby: Let Fro go, he's been stuck \ninside his house for a year. \pPlus John and I know what were \ndoing, Fro has never even played a \lPokémon game before!$"
	
T_TilyousLab_JohnAgrees:
	.string "John: Yea, let Fro go first!$"
	
T_TilyousLab_OkAnthonyGoAhead:
	.string "Prof. Tilyou: Alright then, we are \nall in agreement. \pGo ahead Anthony, pick your \nPokémon. \pChoose carefully!$"
	
T_TilyousLab_HeyDontGoYet:
	.string "Prof. Tilyou: Hey, don't go yet!\p"
	.string "I'm trying to help you not die. I \ncould always give you a carbon \lmonoxide detector if you would \lprefer!$"
	
T_TilyousLab_ProfTilyousPokemon:
	.string "A Pokéball belonging to Prof. \nTilyou. \pYou can hear a quite buzz coming \nfrom inside of it.$"
	
T_TilyousLab_PickRascaloot:
	.string "The Pokéball contains the grass \ntype Bandicoot Pokémon Rascaloot. \pIs this the Pokémon you choose?$"
	
T_TilyousLab_RascalootYes:

	.string "You've recieved Rascaloot!\p"
	.string "Why don't you give it a nickname?$"

T_TilyousLab_OkJohnYoureUp:
	.string "Prof Tilyou: Great choice Anthony. \pYou're up John, go ahead and pick!$"
	
T_TilyousLab_JohnSoundsGood:
	.string "John: Sounds good! I know who I \nwant!$"
	
T_TilyousLab_JohnEmboryps:
	.string "John took the Fire Pokémon, \nEmboryps!\p"
	.string "John: Emboryps is so lit!$"

T_TilyousLab_TilyouBobbysTurn:
	.string "Prof. Tilyou: Great pick Johnny \nWaffles. \pNow it's time for Bobby to pick!$"
	
T_TilyousLab_BobbyFlobra:
	.string "Bobby took the Water Pokémon, \nFlobra!$"

T_TilyousLab_YouAllHaveStarters:
	.string "Prof Tilyou: Well it looks like you \nall have companions for your \ljourney. Get out there and start \ltraining your Pokémon!\p"
	.string "Bobby: Let's do it! \pGood luck boys, see you at Victory \nRoad!\p"
	.string "John: YEEEEEEEEEET!!!!$"
	
T_TilyousLab_GoAheadAnthony:
	.string "Go ahead Anthony, pick your \nPokémon. \pChoose carefully!$"
	
T_TilyousLab_GoodLuckOnYourAdventure:
	.string "Good luck on your adventure! Take \ncare of your Pokémon.$"

T_TilyousLab_BobbyAllPokesAreViable:
	.string "Bobby: I took a look at the Pokémon \navailable. They are all in the OU \lcategory on Smogon so any choice \lwill be fine.$"
	
T_TilyousLab_JohnLongTimeNoSee:
	.string "John: What's up Fro, long time no \nsee.\p"
	.string "Hurry up and pick a Pokémon. We've \nbeen waiting the whole year on you.\p"
	.string "Don't make us wait any longer!$"
	
T_TilyousLab_PickFlobra:
	.string "The Pokéball contains the water \ntype Pokémon Flobra. \pIs this the Pokémon you choose?$"
	
T_TilyousLab_FlobraYes:

	.string "You've recieved Flobra!\p"
	.string "Why don't you give it a nickname?$"
	
T_TilyousLab_JohnRascaloot:
	.string "John took the Grass Pokémon, \nRascaloot!\p"
	.string "John: My Rascaloot is on fleek!$"
	
T_TilyousLab_BobbyEmboryps:
	.string "Bobby took the Fire Pokémon, \nEmboryps!$"
	
T_TilyousLab_PickEmboryps:
	.string "The Pokéball contains the Fire \ntype Pokémon Emboryps. \pIs this the Pokémon you choose?$"
	
T_TilyousLab_EmborypsYes:

	.string "You've recieved Emboryps!\p"
	.string "Why don't you give it a nickname?$"
	
T_TilyousLab_JohnFlobra:
	.string "John took the Water Pokémon, \nFlobra!\p"
	.string "John: Flobra is dirty A F!$"
	
T_TilyousLab_BobbyRascaloot:
	.string "Bobby took the Grass Pokémon, \nRascaloot!$"
	
T_TilyousLab_DoesntSpendAlotOfTimeInLab:
	.string "I'm not sure where Prof. Tilyou is. \nHe is not in the Lab very often. He \lprefers to do field work.\p"
	.string "Can't say I blame him.$"

T_TilyousLab_HeWontStayLong:
	.string "Prof Tilyou won't stay in the lab \nlong. \pHe will be back in the field \nleaving us to do the grunt work!$"

T_TilyousLab_WonAwards:
	.string "Prof. Tilyou has won awards for his \nworld class Pokéresearch.$"
	
T_TilyousLab_FroGivesParcel:
	.string "Fro: I was at the Pokémart in \nWalmore Town and the clerk said \lyour package was mistakenly \ldelivered to his store.\p"
	.string "Prof Tilyou: Wowie, thanks Anthony! \nI've been fighting with amazon \labout this for quite a while. \pThey were insistant that it was \ndelivered to me. I had just about \lgiven up and was about to order \lanother with free two day shipping!\p"
	.string "Anyway, this is the Pokédex I have \nbeen waiting for to help with my \lresearch. \pAlthough, I've been so busy lately\n"
	.string "I don't know how often I can use \lit. I have an idea,"
	.string "why don't you \ltake the Pokédex and help me with \lmy research while you travel?$"
	
T_TilyousLab_RecievedPokedex:
	.string "You recieved the Pokédex!$"
	
T_TilyousLab_ExplainPokedex:
	.string "Prof. Tilyou: The Pokédex is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any Pokémon you meet or catch.\p"
	.string "John and Bobby go everywhere\n"
	.string "with it.\p"
	.string "Whenever my kid catches a rare Pokémon\n"
	.string "and records its data in the Pokédex,\l"
	.string "he looks for me while I'm out\l"
	.string "doing fieldwork, and shows me.$"

T_TilyousLab_IsiahExplainsWhatHeSaw:
	.string "Isiah: ...and that is when Fro and \nBobby showed up an saved me.\p"
	.string "Prof Tilyou: So you saw team MAGA \ntaking a caged, mutated Pokémon, along \lwith equipment down into Lake Mead's \lnatural caverns?\p"
	.string "That does not sound good. I will get \nthe Village Leaders together and \linvestigate. \pYou kids need to be more careful, \nteam MAGA is not to be taken lightly. \pIf Bobby and Fro didn't come to your \nrescue who knows what could have \lhappened.\p"
	.string "Thank you for letting me know what you \nsaw. I don't want any of you messing \laround at the Lake until we can look \linto this futher. \pPlease continue with your gym challenge \nand try to stay out of team MAGA's \lway if you run into them.\p"
	.string "Isiah: Thank you professor, I will \nbe more careful not to get caught \ldoing anything wrong from now on.$"
	
T_TilyousLab_ComeOnFroLetsGo:
	.string "I'm going to head back towards \nLynch Park, I bet this unforeseen \ldelay has given John a considerable \lheadstart. \pCome on Fro, lets go!$"

T_TilyousLab_GetLeadersTogether:
	.string "I will get the Village Leaders \ntogether and investigate. \pYou kids need to be more careful, \nteam MAGA is not to be taken lightly.$"

T_TilyousLab_BobbyGivesFroPokeballs: 
	.string "Bobby: Hey Fro, I just remembered,\nyou've never caught a Pokémon in the\lwild!\p" 
	.string "I hear Walmore Town's Pokémart was \nsold out of Pokéballs. \pHere take these.\p"
	.string "You want to use these once you've \nweakened a wild Pokémon, it will be \leasier to catch that way.$"

T_TilyousLab_BobbyGivesExpShare:
	.string "One last thing. I also want you to \ntake this Exp. Share.\p"
	.string "This makes raising multiple Pokemon \nmuch easier by giving a portion of \lExp. to all Pokémon in your party, \leven the ones who didn't participate \lin battle!\p"
	.string "Place it in your Key Items pocket \nin your bag, and you can turn it on \lor off depending on how much of a \lchallenge you want.$"

