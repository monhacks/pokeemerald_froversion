WesternApproachOpenLand1_MapScripts::
	.byte 0

WesternApproachOpenLand1_EventScript_FindFredericSupplies::
	finditem ITEM_FREDERIC_SUPPLIES_3
	addvar VAR_FREDERIC_STATE, 1
	end