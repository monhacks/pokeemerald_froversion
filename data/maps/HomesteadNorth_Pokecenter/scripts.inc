HomesteadNorth_Pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HomesteadNorth_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Script_HomesteadNorth_Pokecenter_OnLoad
	.byte 0

Script_HomesteadNorth_Pokecenter_OnLoad:
	goto_if_set FLAG_MAGEE_VERSION, Script_HomesteadNorth_Pokecenter_SetDynamicWarpMageeVersion
	setdynamicwarp MAP_HOMESTEAD_NORTH, 255, 58, 34
	end

Script_HomesteadNorth_Pokecenter_SetDynamicWarpMageeVersion:
	setdynamicwarp MAP_MAGEE_VERSION_HOMESTEAD_TOWN_NORTH, 255, 58, 34
	end

HomesteadNorth_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_HOMESTEAD_NORTH
	call Common_EventScript_UpdateBrineyLocation
	end

HomesteadNorth_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
end

HomesteadNorth_EventScript_Gentleman::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_MisplacedMoney, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_MisplacedMoney:
	.string "I've seen Frank Capra's It's a\n"
	.string "Wonderful Life over 100 times.\p"
	.string "I really identify with Uncle Billy.\p"
	.string "For instance, I misplaced 8,000 dollars\n"
	.string "earlier today.$"

HomesteadNorth_EventScript_Hiker::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_NoArtificalTrees, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_NoArtificalTrees:
	.string "No one in Homestead North uses an\n"
	.string "artificial tree.\p"
	.string "Christmas is our most important\n"
	.string "tradition.$"

HomesteadNorth_EventScript_ExpertF::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_OutOfControl, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Text_OutOfControl:
	.string "We spend all year planning the\n"
	.string "festivities.\p"
	.string "We always try to outdo what we did\n"
	.string "last year.\p"
	.string "It's starting to get out of control.$"
