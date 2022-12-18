WesternApproachCaverns2_MapScripts::
	.byte 0


WesternApproachCaverns2_EventScript_FindManuscript::
	finditem ITEM_MANUSCRIPT
	addvar VAR_FREDERIC_STATE, 1
	release
end