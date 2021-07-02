RaintreeIsland_BerryStand_MapScripts::
	.byte 0

EventScript_RaintreeIsland_BerryStand_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart RaintreeIsland_BerryStand_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RaintreeIsland_BerryStand_Pokemart: @ 81FF9E8
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_OCCA_BERRY
	.2byte ITEM_COBA_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_NONE
	release
	end
