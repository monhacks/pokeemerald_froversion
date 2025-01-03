EscapeRoom_FirstRoom_Protagonist2_MapScripts::
	.byte 0

EscapeRoom_FirstRoom_Protagonist2__EventScript_IceRoomClue1::
	lockall
	msgbox EscapeRoom_FirstRoom_Protagonist2__Text_IceRoomClue1, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_FirstRoom_Protagonist2__EventScript_IceRoomClue2::
	lockall
	msgbox EscapeRoom_FirstRoom_Protagonist2__Text_IceRoomClue2, MSGBOX_DEFAULT
	releaseall
	end

EscapeRoom_FirstRoom_Protagonist2__Text_IceRoomClue1:	
	.string "Lralg Nulg\n"
	.string "\l"
	.string "\p"
	.string "{COLOR BLUE}3 5$"

EscapeRoom_FirstRoom_Protagonist2__Text_IceRoomClue2:	
	.string "{COLOR BLUE}Reverse then repeat to unlock\n"
	.string "your next treat.$"
	