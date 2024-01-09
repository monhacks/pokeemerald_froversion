.set LOCALID_NURSE, 1

LilycoveCity_PokemonCenter_1F_MapScripts:: @ 821C5B2
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_PokemonCenter_1F_OnTransition
	.byte 0

LilycoveCity_PokemonCenter_1F_OnTransition: @ 821C5BD
	setrespawn HEAL_LOCATION_PC_IN_THE_WOODS
	call_if_set FLAG_RECEIVED_BLAZIKEN, LilycoveCity_PokemonCenter_EventScript_RemovePokeball
	end

@ SetLilycoveLadyGfx returns TRUE if its the Contest Lady
LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx:: @ 821C5C6
	special SetLilycoveLadyGfx
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon
	end

LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon:: @ 821C5E0
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon:: @ 821C5E4
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_Nurse:: @ 821C5E8
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Boy:: @ 821C5F6
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon, MSGBOX_NPC
	end

LilycoveCity_PokemonCenter_1F_EventScript_Maniac:: @ 821C5FF
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone
	msgbox LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone:: @ 821C614
	msgbox LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_EventScript_RemovePokeball::
	setmetatile 5, 1, METATILE_PokemonCenter_HealingMachineEmpty, 1
	special DrawWholeMapView
	return

LilycoveCity_PokemonCenter_EventScript_TryHeal:: @ 821C5FF
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BLAZIKEN, LilycoveCity_PokemonCenter_EventScript_Heal
	msgbox LilycoveCity_PokemonCenter_1F_Text_BallStuckInMachine, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLAZIKEN
	playmoncry SPECIES_BLAZIKEN, 2
    delay 40
    waitmoncry
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThePokeballContainedBlaziken, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
    givecustommon SPECIES_BLAZIKEN, 50, ITEM_LEFTOVERS, ITEM_DUSK_BALL, NATURE_CALM, 1, 100, 0, 4, 0, 75, 75, 16, 16, 16, 16, 16, 16, MOVE_CUT, MOVE_SWORDS_DANCE, MOVE_OVERHEAT, MOVE_ROCK_SLIDE, 0
    setmetatile 5, 1, METATILE_PokemonCenter_HealingMachineEmpty, 1
	special DrawWholeMapView
    setflag FLAG_RECEIVED_BLAZIKEN
	release
	end

LilycoveCity_PokemonCenter_EventScript_Heal::
	lock
	msgbox LilycoveCity_PokemonCenter_1F_Text_HealYourPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_PokemonCenter_EventScript_Heal2
	release
	end

LilycoveCity_PokemonCenter_EventScript_Heal2::
	special HealPlayerParty
	release
	end

LilycoveCity_PokemonCenter_EventScript_JumpDesk:: @ 821C5FF
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_JumpDesk, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_PokemonCenter_EventScript_JumpDeskYes
	end

LilycoveCity_PokemonCenter_1F_Text_JumpDesk::
	.string "No one is here, do you want to jump\n"
	.string "over the counter?$"

LilycoveCity_PokemonCenter_EventScript_JumpDeskYes::
	special StorePlayerCoordsInVars
	compare VAR_0x8005, 2
	goto_if_ne LilycoveCity_PokemonCenter_EventScript_JumpDeskUp
	goto LilycoveCity_PokemonCenter_EventScript_JumpDeskDown
	end

LilycoveCity_PokemonCenter_EventScript_JumpDeskDown::
	delay 30
	setmetatile 7, 2, METATILE_PokemonCenter_CounterCovered, 0
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, Movement_JumpDeskDown
	waitmovement 0
	setmetatile 7, 2, METATILE_PokemonCenter_CounterUncovered, 0
	special DrawWholeMapView
	release
	end

LilycoveCity_PokemonCenter_EventScript_JumpDeskUp::
	delay 30
	setmetatile 7, 2, METATILE_PokemonCenter_CounterCovered, 0
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, Movement_JumpDeskUp
	waitmovement 0
	setmetatile 7, 2, METATILE_PokemonCenter_CounterUncovered, 0
	special DrawWholeMapView
	release
	end

Movement_JumpDeskUp: @ 827224E
	JUMP_SPECIAL_UP
	JUMP_SPECIAL_UP
	step_end
	
Movement_JumpDeskDown: @ 827224E
	JUMP_SPECIAL_DOWN
	JUMP_SPECIAL_DOWN
	step_end

LilycoveCity_PokemonCenter_1F_Text_HealYourPokemon::
	.string "Do you want to heal your Pokemon\n"
	.string "on your own?$"

LilycoveCity_PokemonCenter_1F_Text_BallStuckInMachine::
	.string "There is a Pokeball stuck in the\n"
	.string "machine. You remove it carefully.$"

LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon: @ 821C61E
	.string "I wonder how many kinds of Pokémon\n"
	.string "there are in the world.\p"
	.string "It'd be great to cross seas and\n"
	.string "trade Pokémon with people far away.$"

LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels: @ 821C69D
	.string "I've been hearing about some rotten\n"
	.string "scoundrels who steal Pokémon and rip\l"
	.string "off METEORITES.$"

LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels: @ 821C6F6
	.string "Those rotten scoundrels who steal\n"
	.string "Pokémon and rip off METEORITES…\p"
	.string "I haven't seen them around recently.$"

LilycoveCity_PokemonCenter_1F_Text_ThePokeballContainedBlaziken:
	.string "The Pokéball contained a Blaziken!$"

