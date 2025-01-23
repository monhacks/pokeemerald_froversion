MAGM8ForestTownPostInfectionMart_MapScripts::
	.byte 0


MAGM8ForestTownPostInfectionMart_Clerk:: @ 8202587
	lock
	faceplayer
	msgbox MAGM8ForestTownPostInfectionMart_Text_NoClerk, MSGBOX_DEFAULT
	closemessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MAGM8ForestTownPostInfectionMart_Text_NoClerk:
	.string "{PLAYER}: It looks like there is no one\n"
	.string "around to take my money.\p"
	.string "There is plenty of stuff, I'll just\n"
	.string "leave money for whatever I take!$"
	