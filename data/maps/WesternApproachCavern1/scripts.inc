WesternApproachCavern1_MapScripts::
	.byte 0

WesternApproachCavern1_EventScript_FindFredericSupplies::
	finditem ITEM_FREDERIC_SUPPLIES_5
	addvar VAR_FREDERIC_STATE, 1
	end
