CinnabarIslandNCC_MapScripts::
	.byte 0


@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------

CinnabarIslandNCC_Receptionist::
	lockall
		faceplayer
		goto_if_set FLAG_GAVE_NCC_PACKAGE, CinnabarIslandNCC_Receptionist_IllLetYouGetSettled
		compare VAR_ROUTE101_STATE, 1
		goto_if_eq CinnabarIslandNCC_Receptionist_GivePackage
	releaseall
	end


CinnabarIslandNCC_Receptionist_GivePackage:
		msgbox CinnabarIslandNCC_Text_ThankYouForDeliveringPackage, MSGBOX_DEFAULT
		removeitem ITEM_NCC_PACKAGE, 1
		setflag FLAG_GAVE_NCC_PACKAGE
		msgbox CinnabarIslandNCC_Text_NCCExplaination, MSGBOX_DEFAULT
	goto CinnabarIslandNCC_Receptionist_EnjoyYourStay
	
	
CinnabarIslandNCC_Receptionist_EnjoyYourStay:
		msgbox CinnabarIslandNCC_Text_EnjoyYourStay, MSGBOX_DEFAULT
	goto CinnabarIslandNCC_Receptionist_IllLetYouGetSettled

CinnabarIslandNCC_Receptionist_IllLetYouGetSettled:
		msgbox CinnabarIslandNCC_Text_IllLetYouGetSettled, MSGBOX_DEFAULT
		closemessage
	releaseall
	end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------


CinnabarIslandNCC_Text_ThankYouForDeliveringPackage:
	.string "Oh! Are those the parts we've been\n"
	.string "waiting for?\p"
	.string "Yes, that is them! Thank you so much\n"
	.string "for delivering them. They will help\l"
	.string "tremendously with our newest project!$"

CinnabarIslandNCC_Text_NCCExplaination:
	.string "The Nautic Communication Center, or\n"
	.string "NCC for short, is Cinnabar Island's\l"
	.string "leading employer.\p"
	.string "We do a wide range of things here\n"
	.string "that not only benefit our home Island,\l"
	.string "but all people and Pokémon alike.$"

CinnabarIslandNCC_Text_EnjoyYourStay:
	.string "Oh my, you look very tired.\n"
	.string "I think I've taken enough of your\l"
	.string "time.\p"
	.string "Are you sailing again or staying the\n"
	.string "night?\p"
	.string "Oh you're staying the night! How\n"
	.string "Wonderful!$" 

CinnabarIslandNCC_Text_IllLetYouGetSettled:	
	.string "I'll let you go get settled\n"
	.string "into your room then!$"
	