SummitCityGym_MapScripts::
	.byte 0

SummitCity_Gym_FindProtectionAgreement::
	lock
	setvar VAR_0x8000, MUGSHOT_SEARS_PA
	callnative DrawMugshot
	msgbox SummitCity_Gym_Text_FoundPAClue, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SummitCityGym_EventScript_TakeYourTime
	callnative ClearMugshot
	release
	end

SummitCityGym_EventScript_TakeYourTime:
	msgbox SummitCity_Gym_Text_TakeYourTime, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SummitCityGym_EventScript_TakeYourTime
	callnative ClearMugshot
	release
	end


SummitCityGym_EventScript_FoundChadsNameBadge::
	msgbox SummitCity_Gym_Text_ChadNameBadgeFound, MSGBOX_AUTOCLOSE
	setflag FLAG_FOUND_CHADS_NAME_BADGE
	release
	end

SummitCity_Gym_Text_ChadNameBadgeFound:
	.string "You found Chad's name Badge!$"

SummitCity_Gym_Text_FoundPAClue:
	.string "You found the Protection\n"
	.string "Agreement!\p"
	.string "Are you done studying it for\n"
	.string "clues?$"

SummitCity_Gym_Text_TakeYourTime:
	.string "Take your time...\p"
	.string "Are you done studying it for\n"
	.string "clues?$"
