CinnabarIslandHouse1_MapScripts::
	.byte 0

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIslandHouse1_EventScript_Man::
	msgbox CinnabarIslandHouse1_Text_Man, MSGBOX_NPC
	end

CinnabarIslandHouse1_EventScript_Woman::
	msgbox CinnabarIslandHouse1_Text_Woman, MSGBOX_NPC
	end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]

CinnabarIslandHouse1_Text_Woman:
	.string "My husband works the night shift at\n"
	.string "the NCC. He always tells me how\p"
	
	
	.string "important his work is. Without him\n"
	.string "there would be chaos at night.$"

CinnabarIslandHouse1_Text_Man:
	.string "ZZZzzz... November November Charlie\n"
	.string "...please standby... ZZZzzz...\p$"

	.string "...not allowed... ZZZzzz...\n"
	.string "...basement elevator...ZZzzz...$"