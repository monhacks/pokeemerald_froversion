WesternApproachLostSpringCanyonTrail1_MapScripts::
	.byte 0

WesternApproachLostSpringCanyonTrail1_EventScript_FindFredericSupplies::
	finditem ITEM_FREDERIC_SUPPLIES_2
	addvar VAR_FREDERIC_STATE, 1
	end
