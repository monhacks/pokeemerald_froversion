NCC_Underground_East_1B_MapScripts::
	.byte 0


@--------------------------------------------------------------------------------
@-------------------------------------Events-------------------------------------
@--------------------------------------------------------------------------------

NCC_Underground_East_1B_ScientistNidokindAndQueenBattle::
	@@NOTDONEYET 
	@@ THIS WILL BE AN EVENT WHERE THE PLAYER FIGHTS SHADOW DUGTRIO AND OBTAINS HM STRENGTH REQUIRED FOR PROGRESSING THROUGH DUNGEON
	lockall
		faceplayer
		trainerbattle_double TRAINER_WINSTON_4, NCC_Underground_East_1B_1F_Text_GruntIntro, NCC_Underground_East_1B_1F_Text_GruntDefeat, Route104_Text_GinaNotEnoughMons, NCC_Underground_East_1B_ScientistDefeat
		msgbox NCC_Underground_East_1B_1F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

NCC_Underground_East_1B_ScientistDefeat:
	@@Msgbox NCC_Underground_East_1B_1F_Text_GruntPostBattleGiveStrength, MSGBOX_DEFAULT
	@@giveitem ITEM_HM04, 1
releaseall
end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]'''''''''''''''''''''''''''''

NCC_Underground_East_1B_1F_Text_GruntIntro:
	.string "What are you doing down here?$"

NCC_Underground_East_1B_1F_Text_GruntDefeat:
	.string "Damn you won$"

NCC_Underground_East_1B_1F_Text_GruntPostBattleGiveStrength:
	.string "Don't hurt me. Take this!$"

NCC_Underground_East_1B_1F_Text_GruntPostBattle:
	.string "You'll never understand the importance\n"
	.string "of what the NCC is trying to\l"
	.string "accomplish.$"