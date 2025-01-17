SaltLakeCityHouse2_MapScripts::
	.byte 0

SaltLakeCityHouse2_EventScript_Woman::
	msgbox SaltLakeCity_House2_Text_LocalPrideSaltLake, MSGBOX_NPC
	end

SaltLakeCityHouse2_EventScript_GoodsWoman::
	lockall
		checkitem ITEM_OAKS_PARCEL, 1
		compare VAR_RESULT, TRUE
		goto_if_eq SaltLakeCityHouse2_EventScript_AlreadyReceivedGoods
		msgbox SaltLakeCityHouse2_Text_TommyGoods, MSGBOX_NPC
		giveitem ITEM_OAKS_PARCEL, 1
		goto SaltLakeCityHouse2_EventScript_AlreadyReceivedGoods

SaltLakeCityHouse2_EventScript_AlreadyReceivedGoods:
		msgbox SaltLakeCityHouse2_Text_TommyGoods2, MSGBOX_NPC
	releaseall
	end

SaltLakeCity_House2_Text_LocalPrideSaltLake:
.string "Our city's name comes from the Great\n"
.string "Salt Lake, a symbol of resilience and\l"
.string "natural beauty!\p"
.string "Back in the day, pioneers settled\n"
.string "here because of its unique resources\l"
.string "and breathtaking scenery.$"

SaltLakeCityHouse2_Text_TommyGoods:
	.string "Did Tommy send you? If so, I've got\n"
	.string "the goods he asked for right here.\l"
	.string "Let me hand them over to you!$x"

SaltLakeCityHouse2_Text_TommyGoods2:
	.string "Make sure to tell Tommy that his shipment\n"
	.string "arrived safely and to let me know if he\l"
	.string "needs anything else.$"
