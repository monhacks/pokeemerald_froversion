LakeMeadVillage_TilyousLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MS_LakeMeadVillage_TilyousLab_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MS_LakeMeadVillage_TilyousLab_OnFrame
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

MS_LakeMeadVillage_TilyousLab_OnLoad::
	compare VAR_LITTLEROOT_TOWN_STATE, 2
	goto_if_lt Script_TilyousLab_RemoveTilyouBobbyJohn
	goto_if_eq Script_TilyousLab_ShowTilyouBobbyJohn
	compare VAR_OLDALE_TOWN_STATE, 1
	goto_if_eq Script_TilyousLab_MoveTilyouPokedex
	end

MS_LakeMeadVillage_TilyousLab_OnFrame::
	map_script_2 VAR_LITTLEROOT_TOWN_STATE, 2, Script_TilyousLab_PickAPokemon
	.2byte 0
	
//Scripts

Script_TilyousLab_MoveTilyouPokedex:
setobjectxyperm 1, 3, 2
setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
end

Script_TilyousLab_RemoveTilyouBobbyJohn:
	removeobject 1
	removeobject 2
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_TILYOU
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	end

Script_TilyousLab_ShowTilyouBobbyJohn:
	addobject 1
	addobject 2
	addobject 3
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

Script_TilyousLab_BULBASAURPokeball::
	lock
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_lt Script_TilyousLab_ProfTilyousPokeball
	showmonpic SPECIES_BULBASAUR, 10, 3
	msgbox T_TilyousLab_PickBULBASAUR, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, 1
	goto_if_eq Script_TilyousLab_BULBASAURYes
	closemessage
	release
	end
	
Script_TilyousLab_BULBASAURYes:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STARTER_MON 1
	givemon SPECIES_BULBASAUR, 5, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	removeobject 4
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BULBASAUR
	waitfanfare
	msgbox T_TilyousLab_BULBASAURYes, MSGBOX_YESNO
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
	compare VAR_STARTER_MON, 1
	goto_if_eq Script_TilyousLab_FroTookBULBASAUR
	compare VAR_STARTER_MON, 2
	goto_if_eq Script_TilyousLab_FroTookSQUIRTLE
	compare VAR_STARTER_MON, 3
	goto_if_eq Script_TilyousLab_FroTookCHARMANDER
	release
	end

Script_TilyousLab_FroTookBULBASAUR:
	applymovement 3, M_TilyousLab_JohnCHARMANDER
	waitmovement 3
	removeobject 6
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_CHARMANDER
	msgbox T_TilyousLab_JohnCHARMANDER, MSGBOX_DEFAULT
	closemessage
	msgbox T_TilyousLab_TilyouBobbysTurn, MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnCHARMANDERReturn
	applymovement 2, M_TilyousLab_BobbySQUIRTLE
	waitmovement 2
	removeobject 5
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_SQUIRTLE
	msgbox T_TilyousLab_BobbySQUIRTLE
	closemessage
	msgbox T_TilyousLab_YouAllHaveStarters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyousLab_BobbySQUIRTLEExit
	applymovement 3, M_TilyousLab_JohnExits
	waitmovement 3
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	
	release
	end

Script_TilyousLab_SQUIRTLEPokeball::
	lock
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_lt Script_TilyousLab_ProfTilyousPokeball
	showmonpic SPECIES_SQUIRTLE, 10, 3
	msgbox T_TilyousLab_PickSQUIRTLE, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, 1
	goto_if_eq Script_TilyousLab_SQUIRTLEYes
	closemessage
	release
	end
	
	
Script_TilyousLab_SQUIRTLEYes:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STARTER_MON 2
	givemon SPECIES_SQUIRTLE, 5, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	removeobject 5
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_SQUIRTLE
	waitfanfare
	msgbox T_TilyousLab_SQUIRTLEYes, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TilyousLab_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	goto_if_eq TilyousLab_BobbyAndJohnPick
	closemessage
	release
	end	
	
Script_TilyousLab_FroTookSQUIRTLE:
	applymovement 3, M_TilyousLab_JohnBULBASAUR
	waitmovement 3
	removeobject 4
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BULBASAUR
	msgbox T_TilyousLab_JohnBULBASAUR, MSGBOX_DEFAULT
	closemessage
	msgbox T_TilyousLab_TilyouBobbysTurn, MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnBULBASAURReturn
	applymovement 2, M_TilyousLab_BobbyCHARMANDER
	waitmovement 2
	removeobject 6
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_CHARMANDER
	msgbox T_TilyousLab_BobbyCHARMANDER
	closemessage
	msgbox T_TilyousLab_YouAllHaveStarters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyousLab_BobbyCHARMANDERExit
	applymovement 3, M_TilyousLab_JohnExits
	waitmovement 3
	removeobject 2
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BOBBY
	removeobject 3
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_JOHN
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end	
	
Script_TilyousLab_CHARMANDERPokeball::
	lock
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_lt Script_TilyousLab_ProfTilyousPokeball
	showmonpic SPECIES_CHARMANDER, 10, 3
	msgbox T_TilyousLab_PickCHARMANDER, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, 1
	goto_if_eq Script_TilyousLab_CHARMANDERYes
	closemessage
	release
	end
	
	
Script_TilyousLab_CHARMANDERYes:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_STARTER_MON 3
	givemon SPECIES_CHARMANDER, 5, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	removeobject 6
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_CHARMANDER
	waitfanfare
	msgbox T_TilyousLab_CHARMANDERYes, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TilyousLab_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	goto_if_eq TilyousLab_BobbyAndJohnPick
	closemessage
	release
	end	
	
Script_TilyousLab_FroTookCHARMANDER:
	applymovement 3, M_TilyousLab_JohnSQUIRTLE
	waitmovement 3
	removeobject 5
	msgbox T_TilyousLab_JohnSQUIRTLE, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_SQUIRTLE
	msgbox T_TilyousLab_TilyouBobbysTurn, MSGBOX_DEFAULT
	closemessage
	applymovement 3, M_TilyousLab_JohnSQUIRTLEReturn
	applymovement 2, M_TilyousLab_BobbyBULBASAUR
	waitmovement 2
	removeobject 4
	msgbox T_TilyousLab_BobbyBULBASAUR
	closemessage
	setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_TILYOUS_LAB_BULBASAUR
	msgbox T_TilyousLab_YouAllHaveStarters, MSGBOX_DEFAULT
	closemessage
	applymovement 2, M_TilyousLab_BobbyBULBASAURExit
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

// Movements

M_TilyousLab_JohnSQUIRTLE:
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
face_up
step_end

M_TilyousLab_JohnSQUIRTLEReturn:
walk_left
walk_left
walk_left
walk_left
walk_left
walk_up
face_down
step_end

M_TilyousLab_BobbyBULBASAUR:
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
walk_up
step_end

M_TilyousLab_BobbyBULBASAURExit:
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

M_TilyousLab_JohnBULBASAUR:
walk_down
walk_right
walk_right
walk_right
walk_right
face_up
step_end

M_TilyousLab_JohnBULBASAURReturn:
walk_left
walk_left
walk_left
walk_left
walk_up
face_down
step_end

M_TilyousLab_BobbyCHARMANDER:
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
walk_up
step_end

M_TilyousLab_BobbyCHARMANDERExit:
walk_down
walk_left
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
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

M_TilyousLab_BobbySQUIRTLEExit:
walk_down
walk_left
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
walk_down
step_end

M_TilyousLab_BobbySQUIRTLE:
walk_down
walk_right
walk_right
walk_right
walk_right
walk_down
walk_right
walk_right
walk_up
step_end


M_TilyousLab_JohnCHARMANDERReturn:
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

M_TilyousLab_JohnCHARMANDER:
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


//NPCS

Script_TilyousLab_NPC_Tilyou::
lock
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
	
T_TilyousLab_PickBULBASAUR:
	.string "The Pokéball contains the grass \ntype Bandicoot Pokémon BULBASAUR. \pIs this the Pokémon you choose?$"
	
T_TilyousLab_BULBASAURYes:

	.string "You've recieved BULBASAUR!\p"
	.string "Why don't you give it a nickname?$"

T_TilyousLab_OkJohnYoureUp:
	.string "Prof Tilyou: Great choice Anthony. \pYou're up John, go ahead and pick!$"
	
T_TilyousLab_JohnSoundsGood:
	.string "John: Sounds good! I know who I \nwant!$"
	
T_TilyousLab_JohnCHARMANDER:
	.string "John took the Fire Pokémon, \nCHARMANDER!\p"
	.string "John: CHARMANDER is so lit!$"

T_TilyousLab_TilyouBobbysTurn:
	.string "Prof. Tilyou: Great pick Johnny \nWaffles. \pNow it's time for Bobby to pick!$"
	
T_TilyousLab_BobbySQUIRTLE:
	.string "Bobby took the Water Pokémon, \nSQUIRTLE!$"

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
	
T_TilyousLab_PickSQUIRTLE:
	.string "The Pokéball contains the water \ntype Pokémon SQUIRTLE. \pIs this the Pokémon you choose?$"
	
T_TilyousLab_SQUIRTLEYes:

	.string "You've recieved SQUIRTLE!\p"
	.string "Why don't you give it a nickname?$"
	
T_TilyousLab_JohnBULBASAUR:
	.string "John took the Grass Pokémon, \nBULBASAUR!\p"
	.string "John: My BULBASAUR is on fleek!$"
	
T_TilyousLab_BobbyCHARMANDER:
	.string "Bobby took the Fire Pokémon, \nCHARMANDER!$"
	
T_TilyousLab_PickCHARMANDER:
	.string "The Pokéball contains the Fire \ntype Pokémon CHARMANDER. \pIs this the Pokémon you choose?$"
	
T_TilyousLab_CHARMANDERYes:

	.string "You've recieved CHARMANDER!\p"
	.string "Why don't you give it a nickname?$"
	
T_TilyousLab_JohnSQUIRTLE:
	.string "John took the Water Pokémon, \nSQUIRTLE!\p"
	.string "John: SQUIRTLE is dirty A F!$"
	
T_TilyousLab_BobbyBULBASAUR:
	.string "Bobby took the Grass Pokémon, \nBULBASAUR!$"
	
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
	