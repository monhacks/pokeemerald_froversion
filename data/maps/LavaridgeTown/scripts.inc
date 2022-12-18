.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts:: @ 81EA4D3
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition: @ 81EA4DE
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_CheckSetRivalPos
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_HideMapNamePopup
	call_if_set FLAG_MARRIOTT_VERSION, LavaridgeTown_EventScript_SetMarriottLayout
	end

LavaridgeTown_EventScript_SetMarriottLayout:: @ 81E5801
	setmaplayoutindex LAYOUT_LAVARIDIGE_TOWN_MARRIOTT_LAYOUT
	return

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut:: @ 81EA514
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos:: @ 81EA518
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 9
	goto_if_eq LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos:: @ 81EA529
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers:: @ 81EA53F
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup:: @ 81EA543
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame: @ 81EA547
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles:: @ 81EA551
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalNoticePlayer
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LavaridgeTown_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq LavaridgeTown_EventScript_PlayBrendanMusic
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalApproachPlayer1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LavaridgeTown_EventScript_MayGiveGoGoggles
	compare VAR_RESULT, FEMALE
	goto_if_eq LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles:: @ 81EA5B5
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles:: @ 81EA5DA
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit:: @ 81EA5FF
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalExit1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic:: @ 81EA630
	playbgm MUS_ENCOUNTER_MAY, 1
	return

LavaridgeTown_EventScript_PlayBrendanMusic:: @ 81EA635
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	return

LavaridgeTown_EventScript_RivalNoticePlayer:: @ 81EA63A
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop:: @ 81EA65C
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1:: @ 81EA6A1
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2:: @ 81EA6AC
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1:: @ 81EA6B7
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2:: @ 81EA6C9
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2: @ 81EA6D4
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit: @ 81EA6DF
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LavaridgeTown_Movement_RivalExit1: @ 81EA6E3
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2: @ 81EA6ED
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1: @ 81EA6F4
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop: @ 81EA6F8
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger:: @ 81EA6FA
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings:: @ 81EA70B
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM:: @ 81EA70E
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan:: @ 81EA717
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin:: @ 81EA720
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1:: @ 81EA729
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2:: @ 81EA732
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF:: @ 81EA73B
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman:: @ 81EA744
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_TOGEPI
	release
	end

LavaridgeTown_EventScript_ReceivedEgg:: @ 81EA787
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg:: @ 81EA791
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg:: @ 81EA79B
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign:: @ 81EA7A5
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign:: @ 81EA7AE
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign:: @ 81EA7B7
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis: @ 81EA7C0
	.string "John: {PLAYER}{KUN}! Long time no see!\p"
	.string "Oh? While I visited the hot springs,\n"
	.string "you got the Grand Island Gym Badge.\p"
	.string "You must have collected\n"
	.string "good Pokémon…\l"
	.string "No, I believe you raised some.\p"
	.string "I guess it would be okay for you to\n"
	.string "have this.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad: @ 81EA897
	.string "John: With those Go-Goggles, you'll\n"
	.string "have no trouble getting through the\l"
	.string "desert near Route 111.\p"
	.string "But, wow, {PLAYER}{KUN}…\n"
	.string "Challenging Gyms…\p"
	.string "You're trying hard because you don't\n"
	.string "want to lose to me, I bet!\p"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
	.string "Grant in Lynch Park Gym.\p"
	.string "See you again!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis: @ 81EA9A2
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
	.string "How's it going?\p"
	.string "Hmm…\n"
	.string "That's a decent collection of BADGES.\p"
	.string "All right, then.\n"
	.string "You may as well have this.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad: @ 81EAA2E
	.string "BRENDAN: Keep those with you if you're\n"
	.string "planning on going into that desert near\l"
	.string "Route 111.\p"
	.string "There should be some Pokémon that\n"
	.string "are exclusively desert-dwellers.\l"
	.string "You might look around for those.\p"
	.string "As for me…\n"
	.string "I'm considering challenging Grant,\l"
	.string "the Gym Leader of Lynch Park.\p"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
	.string "he really is tough.\p"
	.string "See you around!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt: @ 81EAB80
	.string "I have here an Egg.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with Pokémon and\l"
	.string "carried about.\p"
	.string "You are a Trainer, yes?\n"
	.string "And your Pokémon radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this Egg to hatch?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg: @ 81EACC0
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here Egg!$"

LavaridgeTown_Text_ReceivedTheEgg: @ 81EACF4
	.string "{PLAYER} received the Egg.$"

LavaridgeTown_Text_NoRoomForThisEgg: @ 81EAD09
	.string "Oh? You've too many Pokémon.\n"
	.string "There's no room for this Egg…$"

LavaridgeTown_Text_AsYouWishThen: @ 81EAD44
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this Egg, I will be here.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare: @ 81EAD9E
	.string "Every so often, an Egg will be found at\n"
	.string "the Pokémon Day Care.\p"
	.string "Or at least that's how the rumor goes.$"

LavaridgeTown_Text_HotSpringsNeverRunDry: @ 81EAE03
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"

LavaridgeTown_Text_PokemonNippedBackside: @ 81EAEE1
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A Pokémon nipped my backside!$"

LavaridgeTown_Text_OhYouLikeHotSprings: @ 81EAF4E
	.string "Oh, you like hot springs, do you?\p"
	.string "That's surprising for one as young\n"
	.string "as you.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay: @ 81EAF9B
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "Gym Leader like Marriott.$"

LavaridgeTown_Text_IfPokemonInHotSprings: @ 81EB003
	.string "If people put Pokémon in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"

LavaridgeTown_Text_HotSpringsClaims: @ 81EB092
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"

LavaridgeTown_Text_TownSign: @ 81EB12B
	.string "Grand Island\p"
	.string "“Pokémon Center Hot Springs\n"
	.string "An excellent place for relaxing!”$"

LavaridgeTown_Text_GymSign: @ 81EB178
	.string "Grand Island Pokémon Gym\n"
	.string "Leader: Marriott\l"
	.string "“One with a watery passion that bubbles!”$"

LavaridgeTown_Text_HerbShopSign: @ 81EB1CB
	.string "Pokémon Herb Shop\n"
	.string "“Bitter taste--better cure!”$"

/////////////////FROVERSION///////////////////////

Lavaridge_EventScript_Amneet::
	lock
	faceplayer
	playbgm MUS_FV_PIMP, 0
	message SummitCity_Text_AmneetSummitCityMerchant
	waitmessage
	pokemart LavaridgeCity_Pokemart_Amneet
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

	.align 2
LavaridgeCity_Pokemart_Amneet:
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_LIFE_ORB
	.2byte ITEM_CARBOS
	.2byte ITEM_HEART_SCALE
	.2byte ITEM_WATER_CAMOUFLAGE
	.2byte ITEM_GRASS_CAMOUFLAGE
	.2byte ITEM_NONE
	release
	end

Lavaridge_EventScript_Amneet2::
	lock
	faceplayer
	playbgm MUS_FV_PIMP, 0
	message SummitCity_Text_AmneetSummitCityMerchant
	waitmessage
	pokemart LavaridgeCity_Pokemart_Amneet2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

	.align 2
LavaridgeCity_Pokemart_Amneet2:
	.2byte ITEM_TM01
	.2byte ITEM_TM02
	.2byte ITEM_TM03
	.2byte ITEM_TM04
	.2byte ITEM_TM05
	.2byte ITEM_TM06
	.2byte ITEM_TM07
	.2byte ITEM_TM08
	.2byte ITEM_TM09
	.2byte ITEM_TM10
	.2byte ITEM_TM11
	.2byte ITEM_TM12
	.2byte ITEM_TM13
	.2byte ITEM_TM14
	.2byte ITEM_TM15
	.2byte ITEM_TM16
	.2byte ITEM_TM17
	.2byte ITEM_TM18
	.2byte ITEM_TM19
	.2byte ITEM_TM20
	.2byte ITEM_TM21
	.2byte ITEM_TM22
	.2byte ITEM_TM23
	.2byte ITEM_TM24
	.2byte ITEM_TM25
	.2byte ITEM_TM26
	.2byte ITEM_TM27
	.2byte ITEM_TM28
	.2byte ITEM_TM29
	.2byte ITEM_TM30
	.2byte ITEM_TM31
	.2byte ITEM_TM32
	.2byte ITEM_TM33
	.2byte ITEM_TM34
	.2byte ITEM_TM35
	.2byte ITEM_TM36
	.2byte ITEM_TM37
	.2byte ITEM_TM38
	.2byte ITEM_TM39
	.2byte ITEM_TM40
	.2byte ITEM_TM41
	.2byte ITEM_TM42
	.2byte ITEM_TM43
	.2byte ITEM_TM44
	.2byte ITEM_TM45
	.2byte ITEM_TM46
	.2byte ITEM_TM47
	.2byte ITEM_TM48
	.2byte ITEM_TM49
	.2byte ITEM_TM50
	.2byte ITEM_NONE
	release
	end