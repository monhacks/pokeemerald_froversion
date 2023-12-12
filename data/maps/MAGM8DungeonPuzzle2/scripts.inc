.set LOCAL_ID_PUZZLE_BOULDER_1, 2
MAGM8DungeonPuzzle2_MapScripts::
	.byte 0


MAGM8DungeonPuzzle2_EventScript_RemoveBoulderBlockingTeleportProgress::
	lock
		removeobject LOCAL_ID_PUZZLE_BOULDER_1
		setflag FLAG_UNUSED_0x027
		release
	end

