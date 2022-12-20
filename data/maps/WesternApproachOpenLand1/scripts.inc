WesternApproachOpenLand1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WesternApproachSandstormCheck_OnTransition
	.byte 0


WesternApproachOpenLand1_EventScript_Tent::
	lock
	setrespawn HEAL_LOCATION_WESTERN_APPROACH_OPEN_LAND1
	msgbox WesternApproachLostSpringCanyon_Text_RestUpHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq WesternApproachOpenLand1_EventScript_Rest
end

WesternApproachOpenLand1_EventScript_Rest:: @ 822A941
	msgbox WesternApproachLostSpringCanyon_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
end

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