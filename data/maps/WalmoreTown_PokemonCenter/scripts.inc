.set LOCALID_NURSE, 1

WalmoreTown_PokemonCenter_MapScripts:: @ 81FC006
	map_script MAP_SCRIPT_ON_TRANSITION, WalmoreTown_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

WalmoreTown_PokemonCenter_OnTransition: @ 81FC011
	setrespawn HEAL_LOCATION_WALMORE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

WalmoreTown_PokemonCenter_EventScript_Nurse:: @ 81FC01A
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end