NewMap3_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewMap3_OnFrame
	.byte 0

NewMap3_OnFrame:
	map_script_2 VAR_INFECTED_WOODS_STATE, 0, NewMap3_EventScript_PreBossBattle
	.2byte 0


NewMap3_EventScript_PreBossBattle:
	lockall	
		applymovement 2, Common_Movement_ExclamationMark
		waitmovement 2
		msgbox MagaScientist_Text_RealityPokemon, MSGBOX_AUTOCLOSE
		applymovement 2, NewMap3_Movement_ScientistLeaves
		waitmovement 2
		removeobject 2
		setflag FLAG_DEKU_TREE_HIDE_SCIENTIST
		setvar VAR_INFECTED_WOODS_STATE, 1
	releaseall
	end


EventScript_NewMap3_AriadosBossBattle::
	playmoncry SPECIES_ARIADOS, 2
	setwildbattle SPECIES_ARIADOS, 25, ITEM_NONE
	waitmoncry
	setflag FLAG_BATTLE_HAUNTING
	special StartAriadosBossBattle
	waitstate
	msgbox Text_NewMap3_TheAirFeelsClear, MSGBOX_DEFAULT
	playmoncry SPECIES_ARIADOS, 2
	removeobject 1
	setflag FLAG_RECEIVED_BIKE
	clearflag FLAG_BATTLE_HAUNTING
	releaseall
	end

EventScript_NewMap3_AriadosBossBattleLost:
	msgbox Text_NewMap3_TheAirFeelsHeavy, MSGBOX_DEFAULT
	setflag FLAG_LOST_BOSS_BATTLE
	fadescreen FADE_TO_BLACK
	warpsilent MAP_MAGM8EXTENDED_FOREST, 255, 44, 28 //replace this with anercomps map
	

NewMap3_Movement_ScientistLeaves:
	walk_right
	walk_down
	step_end

Text_NewMap3_TheAirFeelsClear::
	.string "{PLAYER} notices the air feels clear.\n"
	.string "{PLAYER} notices a peice of paper\l"
	.string "underneath the wild Pokemon.\p"
	.string "It's ripped in half, the left side\n"
	.string "is missing.\p"
	.string "{PLAYER} can make out the numbers\n"
	.string "4 8 2 2$"

Text_NewMap3_TheAirFeelsHeavy::
	.string "{PLAYER} notices the air feels heavy.\p"
	.string "{PLAYER} passes out.$"


Text_NewMap3_AllDone::
	.string "To do: save the forest...\n"
	.string "done!$"
	release
	end

MagaScientist_Text_RealityPokemon:
	.string "You found me... I thought no one\n"
	.string "could navigate this cursed maze.\p"
	.string "It wasn't supposed to be this way.\n"
	.string "My creation... it defied all control.\p"
	.string "I worked for Team MAGA, running tests\n"
	.string "to create a Pokémon capable of bending\l"
	.string "reality itself. It worked. Too well.\p"
	.string "The Pokémon developed powers far\n"
	.string "beyond our calculations. Reality\l"
	.string "itself shifted in its presence.\p"
	.string "It turned the woods into this maze,\n"
	.string "trapping me and driving everyone away.\p"
	.string "Team MAGA fled, leaving me behind\n"
	.string "to contain the chaos alone.\p"
	.string "Professor Gooseberry discovered\n"
	.string "our experiments, but the Pokémon\l"
	.string "sensed him and reacted violently.\p"
	.string "It turned the wild Pokémon against\n"
	.string "him. They attacked relentlessly.\p"
	.string "I couldn't stop it. Its power grew\n"
	.string "beyond anything I imagined.\p"
	.string "I ran more experiments, hoping to\n"
	.string "find a way to reverse this.\p"
	.string "But the Pokémon only became more\n"
	.string "unpredictable, more dangerous.\p"
	.string "If you want to stop this, you'll\n"
	.string "need to face what I've created.\p"
	.string "But be warned... it won't go down\n"
	.string "easy...$"

