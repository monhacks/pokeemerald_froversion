LakeMeadVillage_NallsResidence_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MS_LakeMeadVillage_NallsResidence_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MS_LakeMeadVillage_NallsResidence_1F_OnFrame
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

//Mapscripts

MS_LakeMeadVillage_NallsResidence_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, Script_LakeMeadVillage_NallsResidence_1F_IsiahIsOut
	.2byte 0

//Scripts

Script_LakeMeadVillage_NallsResidence_1F_IsiahIsOut:
	lock
	applymovement 1, M_IsiahMomMovesToPlayer
	playSE SE_PIN
	waitmovement 1
	msgbox T_IsiahLookingForYou, MSGBOX_DEFAULT
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	release
	end
	
MS_LakeMeadVillage_NallsResidence_1F_OnLoad:
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	goto_if_eq Script_LakeMeadVillage_NallsResidence_1F_HideIsiahMoveMom
	end
	
Script_LakeMeadVillage_NallsResidence_1F_HideIsiahMoveMom:
	removeobject 3
	setflag FLAG_HIDE_NALLS_RESIDENCE_1F_ISIAH
	setobjectxyperm 1, 2, 6
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	end


//NPCS

Script_NallsResidence_IsiahMom_NPC::
	lock
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq Script_NallsResidence_IsiahMom_NPCDialouge1
	goto_if_gt Script_NallsResidence_IsiahMom_NPCDialouge2
	end

Script_NallsResidence_IsiahMom_NPCDialouge1:
	msgbox T_IsiahLookingForYou, MSGBOX_NPC
	end

Script_NallsResidence_IsiahMom_NPCDialouge2:
	msgbox T_NallsResidence_ImGladYoureFriends, MSGBOX_NPC
	end

Script_NallsResidence_IsiahDad_NPC::
	lock
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq Script_NallsResidence_IsiahDad_NPCDialouge1
	goto_if_gt Script_NallsResidence_IsiahDad_NPCDialouge2
	end

Script_NallsResidence_IsiahDad_NPCDialouge1:
	msgbox T_IsiahAlwaysOutExploring, MSGBOX_NPC
	end

Script_NallsResidence_IsiahDad_NPCDialouge2:
	msgbox T_NallsResidence_IsiahGettingIntoTrouble, MSGBOX_NPC
	end

// Movements

M_IsiahMomMovesToPlayer:
	emote_exclamation_mark
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end
	
//Text	

T_IsiahLookingForYou:
	.string "Isiah's Mom: Anthony, how good to \nsee you.\p"
	.string "Isiah just headed over to your \nhouse, you must have missed him on \lthe way here. \pHe was going to tell you Professor \nTilyou went out to do field \lresearch so you'll have to wait for \lhim to get back to get your \lPokémon.$"

T_NallsResidence_ImGladYoureFriends:
	.string "Isiah's Mom: " 
	.string "I'm glad you and Isiah \nare friends. \pYou are both such good boys!$"
	
T_IsiahAlwaysOutExploring:
	.string "Isiah's Dad: Isiah is always out \nexploring. \pI barely see him anymore since \nTrump developed the lake he spends \lmost of his free time there.$"
	
T_NallsResidence_IsiahGettingIntoTrouble:
	.string "Isiah's Dad: My son told me he \nheard a strange noise coming from \linside the caves at the center of \lLake Mead. \pI wish that boy would stay out of \ntrouble!$"