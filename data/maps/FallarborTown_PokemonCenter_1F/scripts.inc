.set LOCALID_NURSE, 1
.set LOCALID_LANETTE, 4

FallarborTown_PokemonCenter_1F_MapScripts:: @ 8200BCD
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition: @ 8200BD8
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse:: @ 8200BE1
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl:: @ 8200BEF
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM:: @ 8200BF8
	msgbox VermillionCity_Pokecenter_Text_Trainer, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Lanette:: @ 8200C01
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth:: @ 8200C28
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest:: @ 8200C38
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
	end

FallarborTown_PokemonCenter_1F_EventScript_LanetteExited:: @ 8200C48
	playse SE_SLIDING_DOOR
	removeobject LOCALID_LANETTE
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	release
	end

VermillionCity_Pokemart_EventScript_Clerk::
	lock
	faceplayer
	playbgm MUS_FV_PIMP, 0
	message VermillionCity_Pokemart_Text_Clerk
	waitmessage
	pokemart LavaridgeCity_Pokemart_Amneet
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth: @ 8200C53
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_LanetteExitWest: @ 8200C60
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_LanetteGreeting: @ 8200C6B
	.string "Oh, hello.\n"
	.string "You are?\p"
	.string "Okay, your name's {PLAYER}{KUN}.\n"
	.string "I can see that you're a Trainer.\p"
	.string "So that means you use the Pokémon\n"
	.string "Storage System I developed.\p"
	.string "How I arrived at that conclusion is\n"
	.string "a simple deductive process.\p"
	.string "You spoke to me because you wanted\n"
	.string "to access something on this PC.\p"
	.string "Oh, I'm sorry. I'm LANETTE.\p"
	.string "Honestly, I'm glad to meet you--it's\n"
	.string "great you're using the Storage System.\p"
	.string "If you could, please visit me at home.\n"
	.string "My house is on ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown: @ 8200E22
	.string "Wow, your Pokémon look really strong!\n"
	.string "I bet you've been training a lot.\p"
	.string "My big brother is out challenging the\n"
	.string "Vermillion Gym right now.\p"
	.string "He says the Gym Leader uses Electric\n"
	.string "types, so watch out for that.\p"
	.string "Do you think I'll ever be as good as\n"
	.string "you someday? Maybe if I keep trying!$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees: @ 8200E8B
	.string "In the fields of Cayuga, we plant\n"
	.string "seedlings of hardy trees that thrive\l"
	.string "even in volcanic ash.$"

VermillionCity_Pokemart_Text_Clerk:
	.string "Welcome to the Pokémart, {PLAYER}!\n"
	.string "How can I help you today?\p"
	.string "We've got a variety of items in stock\n"
	.string "to assist you on your journey.\p"
	.string "Potions, Poké Balls, and more. Just let\n"
	.string "me know what you need!\p"
	.string "Thanks for shopping with us! Good luck\n"
	.string "out there, and come back anytime!$"


VermillionCity_Pokecenter_Text_Trainer:
	.string "Hey there, {PLAYER}! Did you just\n"
	.string "arrive in Vermillion City?\p"
	.string "This Pokécenter is a lifesaver when\n"
	.string "training on the routes nearby.\p"
	.string "Make sure to stock up on potions if\n"
	.string "you're heading out again.\p"
	.string "The trainers around here don't hold\n"
	.string "back! Good luck out there.$"
