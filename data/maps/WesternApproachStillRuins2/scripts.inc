WesternApproachStillRuins2_MapScripts::
	.byte 0


WesternApproachStillRuins2_EventScript_FindFredericSupplies::
	finditem ITEM_FREDERIC_SUPPLIES_1
	addvar VAR_FREDERIC_STATE, 1
	end
