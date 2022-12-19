WesternApproachOpenLand1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WesternApproachSandstormCheck_OnTransition
	.byte 0


WesternApproachSandstormCheck_OnTransition:
	random 5
	compare VAR_RESULT, 3
	goto_if_eq gEventScript_SetSandWeather
	end

gEventScript_SetSandWeather:: @ 81F5523
	setweather WEATHER_SANDSTORM
	return

WesternApproachOpenLand1_EventScript_FindFredericSupplies::
	finditem ITEM_FREDERIC_SUPPLIES_3
	addvar VAR_FREDERIC_STATE, 1
	end