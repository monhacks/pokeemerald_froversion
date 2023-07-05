HomesteadNorth_House1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Script_HomesteadNorth_House1_OnLoad
	.byte 0

Script_HomesteadNorth_House1_OnLoad:
	goto_if_set FLAG_MAGEE_VERSION, Script_HomesteadNorth_House1_SetDynamicWarpMageeVersion
	setdynamicwarp MAP_HOMESTEAD_NORTH, 255, 45, 39
	end

Script_HomesteadNorth_House1_SetDynamicWarpMageeVersion:
	setdynamicwarp MAP_MAGEE_VERSION_HOMESTEAD_TOWN_NORTH, 255, 45, 39
	end

HomesteadNorth_EventScript_Artist::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_ThatsPolitics, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_ThatsPolitics:
	.string "If there's ever a problem, a\n"
	.string "skeleton will tell a fish lady\l"
	.string "about it.\p"
	.string "Thaaaaat's politics!$"

HomesteadNorth_EventScript_PokefanF::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_StandingOvation, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_StandingOvation:
	.string "Our whole town always makes sure to\n"
	.string "leave out cookies and milk for Santa.\p"
	.string "If I saw someone eat that much,\n"
	.string "I would give them a standing ovation.$"
