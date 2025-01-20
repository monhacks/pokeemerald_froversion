VermillionCityArnoldsBoatRepair_MapScripts::
	.byte 0


VermillionCityArnoldsBoatRepair_EventScript_Arnold::
	goto_if_set FLAG_RIVERTON_FUEL_QUEST_STARTED, VermillionCityArnoldsBoatRepair_EventScript_Arnold_Fuel
	msgbox VermillionCityArnoldsBoatRepair_Text_Arnold, MSGBOX_NPC
	end

VermillionCityArnoldsBoatRepair_EventScript_Arnold_Fuel:
	msgbox VermillionCityArnoldsBoatRepair_Text_Arnold_Fuel, MSGBOX_NPC
	setvar VAR_MAGEE_VERSION, 8
	end

VermillionCityArnoldsBoatRepair_Text_Arnold:
	.string "Welcome to Arnold's Boat Repair Shop!\n"
	.string "We fix everything from small dinghies\l"
	.string "to luxury yachts!$"

VermillionCityArnoldsBoatRepair_Text_Arnold_Fuel:
	.string "Oh, you're looking for fuel for Captain Greg?\n"
	.string "You're in luck! I've got just what you need.\p"
	.string "Take this and tell him I said hi!$"
