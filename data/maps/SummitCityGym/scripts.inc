SummitCityGym_MapScripts::
	.byte 0


SummitCityGym_EventScript_FoundChadsNameBadge::
	msgbox SummitCity_Gym_Text_ChadNameBadgeFound, MSGBOX_AUTOCLOSE
	setflag FLAG_FOUND_CHADS_NAME_BADGE
	release
	end

SummitCity_Gym_Text_ChadNameBadgeFound:
	.string "You found Chad's name Badge!$"
