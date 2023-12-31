MAGM8ForestTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MAGM8ForestTown_OnLoad
	.byte 0

MAGM8ForestTown_OnLoad: @ 822D989
	call_if_set FLAG_SYS_GAME_CLEAR, MAGM8ForestTown_EventScript_RevealBlackForest
	end

MAGM8ForestTown_EventScript_RevealBlackForest:: @ 822D993
	setmetatile 23, 6, 0x025, 1
	setmetatile 24, 6, 0x026, 1
	setmetatile 23, 7, 0x018, 0
	setmetatile 24, 7, 0x018, 0
	setmetatile 23, 8, 0x08F, 0
	setmetatile 24, 8, 0x08F, 0
	return

MAGM8ForestTown_EventScript_LockedDoor::
	lockall
		msgbox MAGM8ForestTown_Text_DoorLocked, MSGBOX_DEFAULT
		releaseall
	end

MAGM8ForestTown_EventScript_PokemartClosed::
	lock
		goto_if_set FLAG_HIDE_LAKE_MEAD_VILLAGE_ISIAH  , MAGM8ForestTown_EventScript_LockedDoor
		msgbox MAGM8ForestTown_Text_PokemartClosed, MSGBOX_DEFAULT
		giveitem ITEM_MAGM8_HEAL_POWDER, 1
		setflag FLAG_HIDE_LAKE_MEAD_VILLAGE_ISIAH
	release
end

MAGM8ForestTown_Text_PokemartClosed:
	.string "The door is locked, but there is a\n"
	.string "note.\p"
	.string "{PLAYER}, I am sorry we missed you.\n"
	.string "before we closed for the night.\p"
	.string "I know your Azumarill is very sick.\n"
	.string "I have left the medicine you asked\l"
	.string "for in this bag.\p"
	.string "Please take it.\p"
	.string "Sending get well wishes from your\n"
	.string "favorite Pokémart clerk!\p"
	.string "Sincerely --Gordon.$"

MAGM8ForestTown_Text_DoorLocked:
	.string "The door is locked.$"



