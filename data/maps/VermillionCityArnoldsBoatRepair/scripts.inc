VermillionCityArnoldsBoatRepair_MapScripts::
	.byte 0


VermillionCityArnoldsBoatRepair_EventScript_Arnold::
	goto_if_set FLAG_RIVERTON_FUEL_QUEST_STARTED, VermillionCityArnoldsBoatRepair_EventScript_Arnold_Fuel
	VermillionCityArnoldsBoatRepair_EventScript_ArnoldReturn:
	msgbox VermillionCityArnoldsBoatRepair_Text_Arnold, MSGBOX_NPC
	end

VermillionCityArnoldsBoatRepair_EventScript_Arnold_Fuel:
	compare VAR_MAGEE_VERSION, 8
	goto_if_eq VermillionCityArnoldsBoatRepair_EventScript_ArnoldReturn
	msgbox VermillionCityArnoldsBoatRepair_Text_Arnold_Fuel, MSGBOX_NPC
	giveitem ITEM_COIN_CASE, 1
	setvar VAR_MAGEE_VERSION, 8
	end

VermillionCityArnoldsBoatRepair_Text_Arnold:
	.string "Welcome to Arnold's Boat Repair Shop!\n"
	.string "We fix everything from small dinghies\l"
	.string "to luxury yachts!$"

VermillionCityArnoldsBoatRepair_Text_Arnold_Fuel:
	.string "Oh, you're looking for fuel for Captain\n"
	.string "Greg?\p"
	.string "You're in luck! I've got just what you\n"
	.string "need.\p"
	.string "Take this and tell him I said hi!$"
