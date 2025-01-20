.set LOCALID_SCROLLINGMENU_SAILING_DESTINATIONS, 16
.set LOCALID_CAPTAIN, 5
.set LOCALID_SS_TIDAL, 2

VermillionCityHarbor_MapScripts::
	.byte 0

Riverton_EventScript_CaptainGreg::
		compare VAR_MAGEE_VERSION, 7
		goto_if_eq Riverton_EventScript_CaptainGregOffersRideNeedsFuel
		goto_if_gt Riverton_EventScript_CaptainGregOffersRide
		msgbox Riverton_Text_CaptainGreg_Generic, MSGBOX_NPC
	end

Riverton_EventScript_CaptainGregOffersRideNeedsFuel:
		goto_if_set FLAG_RIVERTON_FUEL_QUEST_STARTED, Riverton_EventScript_CaptainNeedFuel
		msgbox Riverton_Text_CaptainGregOffersRideNeedFuel, MSGBOX_NPC
		setflag FLAG_RIVERTON_FUEL_QUEST_STARTED
	end

Riverton_EventScript_CaptainGregOffersRide:
		goto_if_set FLAG_RIVERTON_FUEL_QUEST_COMPLETED, Riverton_EventScript_CaptainGregOffersRideFuelGiven
		msgbox Riverton_Text_GiveFuel, MSGBOX_NPC
		removeitem ITEM_COIN_CASE, 1
		setflag FLAG_RIVERTON_FUEL_QUEST_COMPLETED
		Riverton_EventScript_CaptainGregOffersRideFuelGiven:
			msgbox Riverton_Text_SoWhereWouldYouLikeToGo, MSGBOX_DEFAULT
			closemessage
			scrollingmultichoice LOCALID_SCROLLINGMENU_SAILING_DESTINATIONS, 2, 3, 2, TRUE
			switch VAR_RESULT
				case 0, Riverton_EventScript_SailToIsland
				case 1, Riverton_EventScript_SailToSwamp
				case MULTI_B_PRESSED, Riverton_EventScript_CaptainGregOffersRideFuelGivenExit
			Riverton_EventScript_CaptainGregOffersRideFuelGivenExit:
		release
		end

Riverton_EventScript_CaptainNeedFuel:
		msgbox Riverton_Text_CaptainNeedFuel, MSGBOX_NPC
	release
	end

Riverton_EventScript_SailToIsland:
		msgbox Riverton_Text_AlrightLetsGo, MSGBOX_AUTOCLOSE
		applymovement OBJ_EVENT_ID_PLAYER, Riverton_Movement_PlayerEnterBoat
		waitmovement OBJ_EVENT_ID_PLAYER
		hideobjectat OBJ_EVENT_ID_PLAYER, 0
		applymovement LOCALID_CAPTAIN, Riverton_Movement_CaptainEnterBoat
		waitmovement LOCALID_CAPTAIN
		removeobject LOCALID_CAPTAIN
		applymovement LOCALID_SS_TIDAL, Common_Movement_WalkLeft
		waitmovement LOCALID_SS_TIDAL
		warpsilent MAP_CINNIBAR_ISLAND, 255, 62, 53
	releaseall
	end

Riverton_EventScript_SailToSwamp:
		msgbox Riverton_Text_AlrightLetsGo, MSGBOX_AUTOCLOSE
		applymovement OBJ_EVENT_ID_PLAYER, Riverton_Movement_PlayerEnterBoat
		waitmovement OBJ_EVENT_ID_PLAYER
		hideobjectat OBJ_EVENT_ID_PLAYER, 0
		applymovement LOCALID_CAPTAIN, Riverton_Movement_CaptainEnterBoat
		waitmovement LOCALID_CAPTAIN
		removeobject LOCALID_CAPTAIN
		applymovement LOCALID_SS_TIDAL, Common_Movement_WalkLeft
		waitmovement LOCALID_SS_TIDAL
		warpsilent MAP_MAGM8FOREST_TOWN_POST_INFECTION, 255, 16, 25
	releaseall
	end

Riverton_Movement_PlayerEnterBoat:
	walk_down
	walk_left
	step_end


Riverton_Movement_CaptainEnterBoat:
	walk_right
	walk_down
	walk_down
	walk_left
	step_end
	

Riverton_EventScript_DockWorkerPete::
	msgbox Riverton_Text_DockWorkerPete, MSGBOX_NPC
	end

Riverton_Text_CaptainGreg_Generic:
	.string "Being a ship captain isn't just a job.\n"
	.string "It's a way of life! The sea calls to\l"
	.string "adventurers with courage and dreams.$"

Riverton_Text_CaptainGregOffersRideNeedFuel:
	.string "Ahoy there! Looking for a ride?\n"
	.string "{PLAYER}: Have you seen Team MAGA?\l"
	.string "They stole my Pokémon! I need help.\p"
	.string "I've seen Team MAGA around two spots.\n"
	.string "One's an Island to the north, and\l"
	.string "the other's a Swamp to the east.\p"
	.string "Want to go? Pick a spot to start.\n"
	.string "Oh, but first, I'll need some fuel!\n"
	.string "Bring it, and I'll take you there.$"

Riverton_Text_CaptainNeedFuel:
	.string "I'll need some fuel! Bring it, and\n"
	.string "I'll take you to wherever you want!$"

Riverton_Text_DockWorkerPete:
	.string "Working on docks all day is tough.\n"
	.string "But someone's gotta keep it running.\p"
	.string "Have you seen the captain? He's been\n"
	.string "grumbling about needing more fuel.$"

Riverton_Text_GiveFuel:
	.string "Is that the fuel? Where did you get\n"
	.string "that from? That grimey landlubber\l"
	.string "Arnold?\p"
	.string "Haha what a chap! We either way, now\n"
	.string "that I have fuel, I'm happy to take\l"
	.string "you wherever you'd like!$"

Riverton_Text_SoWhereWouldYouLikeToGo:
	.string "So matey, where would you like to go?$"

Riverton_Text_AlrightLetsGo:
	.string "Ok off we go then! Go on, get on\n"
	.string	"board!$"
