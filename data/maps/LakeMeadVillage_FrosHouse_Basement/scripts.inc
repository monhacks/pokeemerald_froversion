LakeMeadVillage_FrosHouse_Basement_MapScripts::
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


//Scripts

LakeMeadVillage_FrosHouse_Basement_WouldYouLikeToSleep::
	lock
	msgbox Text_LakeMeadVillageFrosHouseBasement_WouldYouLikeToSleep, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LakeMeadVillage_FrosHouse_Basement_NoToSleep
	applymovement OBJ_EVENT_ID_PLAYER, MovementLakeMeadVillageFrosHouseBasementFroSleeps
	fadescreen 1
	playfanfare MUS_FV_GOODNIGHT
	waitfanfare
	msgbox Text_LakeMeadVillageFrosHouseBasement_YesToSleep, MSGBOX_DEFAULT
	fadescreen 0
	msgbox Text_LakeMeadVillageFrosHouseBasement_OneYearLater, MSGBOX_DEFAULT
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	setrespawn HEAL_LOCATION_LAKE_MEAD_VILLAGE
	release
	end
	
LakeMeadVillage_FrosHouse_Basement_BookOnDesk::
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillageFrosHouseBasement_Book1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_Book2
	end

LakeMeadVillage_FrosHouse_Basement_PosterOnWall::
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillageFrosHouseBasement_Poster1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_Poster2
	end
	
LakeMeadVillage_FrosHouse_Basement_Gamecube::
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillageFrosHouseBasement_Gamecube1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_Gamecube2
	end
	
LakeMeadVillage_FrosHouse_Basement_TV::
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq Script_LakeMeadVillageFrosHouseBasement_TV1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_TV2
	end

LakeMeadVillage_FrosHouse_Basement_Dresser::
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	goto_if_le Script_LakeMeadVillageFrosHouseBasement_Dresser1
	goto_if_gt Script_LakeMeadVillageFrosHouseBasement_Dresser2
	end
	
Script_LakeMeadVillageFrosHouseBasement_Dresser1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Dresser1, MSGBOX_SIGN
	end
	
Script_LakeMeadVillageFrosHouseBasement_Dresser2:
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	msgbox Text_LakeMeadVillageFrosHouseBasement_Dresser2, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Gamecube1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Gamecube1, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Gamecube2:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Gamecube2, MSGBOX_SIGN
	end
	
Script_LakeMeadVillageFrosHouseBasement_TV1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_TV1, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_TV2:
	msgbox Text_LakeMeadVillageFrosHouseBasement_TV2, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Poster1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Poster1, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Poster2:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Poster2, MSGBOX_SIGN
	end
	
Script_LakeMeadVillageFrosHouseBasement_Book1:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Book1, MSGBOX_SIGN
	end

Script_LakeMeadVillageFrosHouseBasement_Book2:
	msgbox Text_LakeMeadVillageFrosHouseBasement_Book2, MSGBOX_SIGN
	end

MovementLakeMeadVillageFrosHouseBasementFroSleeps:
	face_down
	step_end
	
LakeMeadVillage_FrosHouse_Basement_NoToSleep::
	release
	end

//Text

Text_LakeMeadVillageFrosHouseBasement_WouldYouLikeToSleep:
	.string "Would you like to sleep?$"
	
Text_LakeMeadVillageFrosHouseBasement_YesToSleep:
	.string "{PLAYER} drifted off to sleep...\p"
	.string "...$"
	
Text_LakeMeadVillageFrosHouseBasement_OneYearLater:
	.string "             One Year Later...        $"
	
Text_LakeMeadVillageFrosHouseBasement_Book1:
	.string "Critique of Practical Reason by \nImmanuel Kant lays open on the desk$"
	
Text_LakeMeadVillageFrosHouseBasement_Book2:
	.string "Pokémon for Dummies lays open on \nthe desk$"
	
Text_LakeMeadVillageFrosHouseBasement_Poster1:
	.string "A Poster that reads\n“Don't Tread on Me”.\pIt has a picture of a snake on it.$"
	
Text_LakeMeadVillageFrosHouseBasement_Poster2:
	.string "A Poster that reads\n“Don't Tread on Me”.\pIt has a picture of Ekans on it.$"
	
Text_LakeMeadVillageFrosHouseBasement_Gamecube1:
	.string "A Gamecube with Smash Bro's Melee \nin it.\p"
	.string "Better not play, you're grounded.$"
	
Text_LakeMeadVillageFrosHouseBasement_Gamecube2:
	.string "You're finally allowed to play.\p"
	.string "Better not though, you're really \nfar behind your friends on your \lPokémon training. \pBetter get to it.$"
	
Text_LakeMeadVillageFrosHouseBasement_TV1:
	.string "Breaking Bad is playing on the TV.\p"
	.string "Better not watch, you're grounded.$"
	
Text_LakeMeadVillageFrosHouseBasement_TV2:
	.string "Detective Pikachu is playing on TV.\p"
	.string "You should get going.$"
	
Text_LakeMeadVillageFrosHouseBasement_Dresser1:
	.string "The top drawer of your dresser is \nfilled with socks.\p"
	.string "Most of them are full of holes.\p"
	.string "Your bottom drawer contains all of \nyour Yu-Gi-Oh cards.$"
	
Text_LakeMeadVillageFrosHouseBasement_Dresser2:
	.string "Some of your Yu-Gi-Oh cards are \nmissing...$"

	
