VermillionCityHarbor_MapScripts::
	.byte 0

Riverton_EventScript_CaptainGreg::
		compare VAR_MAGEE_VERSION, 7
		goto_if_eq Riverton_EventScript_CaptainGregOffersRideNeedsFuel
		goto_if_gt Riverton_EventScript_CaptainGregOffersRide
		msgbox Riverton_Text_CaptainGreg_Generic, MSGBOX_NPC
	end

Riverton_EventScript_CaptainGregOffersRideNeedsFuel:
		goto_if_set FLAG_RIVERTON_FUEL_QUEST_COMPLETED, Riverton_EventScript_CaptainGregOffersRideFuelGiven
		goto_if_set FLAG_RIVERTON_FUEL_QUEST_STARTED, Riverton_EventScript_CaptainNeedFuel
		msgbox Riverton_Text_CaptainGregOffersRideNeedFuel, MSGBOX_NPC
		setflag FLAG_RIVERTON_FUEL_QUEST_STARTED
	end

Riverton_EventScript_CaptainGregOffersRide:
		msgbox Riverton_Text_GiveFuel, MSGBOX_NPC
		setflag FLAG_RIVERTON_FUEL_QUEST_COMPLETED
		Riverton_EventScript_CaptainGregOffersRideFuelGiven:
			msgbox Riverton_Text_SoWhereWouldYouLikeToGo, MSGBOX_DEFAULT
		release
		end

Riverton_EventScript_CaptainNeedFuel:
		msgbox Riverton_Text_CaptainNeedFuel, MSGBOX_NPC
	release
	end

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
	.string "Have you seen the captain? He's been\l"
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