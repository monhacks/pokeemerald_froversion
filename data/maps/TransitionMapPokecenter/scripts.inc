.set LOCALID_ZENDANO, 1
.set LOCALID_PAUL, 2
.set LOCALID_LATTKA, 3

TransitionMapPokecenter_MapScripts:: @ 81EBCBA
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TransitionMapPokecenter_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TransitionMapPokecenter_OnWarp
	.byte 0

TransitionMapPokecenter_OnWarp:
	map_script_2 VAR_OLDALE_TOWN_STATE, 12, Script_TransitionMapPokecenter_HidePlayerForMagaCutscene
	.2byte 0

TransitionMapPokecenter_OnFrame: @ 81EBCCB
	map_script_2 VAR_OLDALE_TOWN_STATE, 12, Script_TransitionMapPokecenter_MagaCaveCutscene //Froversion Script
	.2byte 0

Script_TransitionMapPokecenter_HidePlayerForMagaCutscene:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_TRANSITION_MAP
	end

Script_TransitionMapPokecenter_MagaCaveCutscene:
	lockall
	delay 210
	msgbox T_TransitionMapPokecenter_TeamMAGALeadersDiscussion, MSGBOX_DEFAULT
	applymovement LOCALID_LATTKA, M_TransitionMapPokecenter_LattkaLeaves
	applymovement LOCALID_PAUL, M_TransitionMapPokecenter_PaulLeaves
	waitmovement LOCALID_PAUL
	removeobject LOCALID_PAUL
	removeobject LOCALID_LATTKA
	msgbox T_TransitionMapPokecenter_ZendanoCallsFro, MSGBOX_DEFAULT
	setvar VAR_OLDALE_TOWN_STATE, 13
	warpsilent MAP_SOOTOPOLIS_CITY, 255, 31, 33
	end

M_TransitionMapPokecenter_LattkaLeaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

M_TransitionMapPokecenter_PaulLeaves:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

T_TransitionMapPokecenter_TeamMAGALeadersDiscussion:
	.string "Lattka: The Boss isn't happy with\n"
	.string "your decision to halt the operation!\p"
	.string "Zendano: I know, but we we're\n"
	.string "medddling with power we can't\l"
	.string "comprehend.\p"
	.string "There is no way, even with our\n" 
	.string "scientific advancements we can come\l"
	.string "close to the power those ancient\l"
	.string "Pokémon achieved.\p"
	.string "If we continue trying to make Pokémon\p"
	.string "stronger by unnatural means, we will\l"
	.string "be punished by a greater power.\p"
	.string "Haigh: Hogwash! We must continue with\n"
	.string "Team MAGA's vision!\p"
	.string "Lattka: He's right, we haven't come\n"
	.string "this far to give up.\p"
	.string "America is suffering. We need to do\n"
	.string "something about it.\p" 
	.string "Lets report back to HQ. I'll meet you\n"
	.string "guys in Summit City, and we will see\l"
	.string "what the Big Boss has to say about your\l"
	.string "failure, and poor decision making, Z.\p"
	.string "Zendano: You're right, sorry for my\n"
	.string "lapse in judgement. You guys go ahead\l"
	.string "I just have to make a quick call\l"
	.string "to my mom.\p"
	.string "Lattka: Alright, lets go Pauly.$"

T_TransitionMapPokecenter_ZendanoCallsFro:
	.string "(716)\p"
	.string "(579)...$"