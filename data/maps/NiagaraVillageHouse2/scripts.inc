NiagaraVillageHouse2_MapScripts::
	.byte 0

NiagaraVillage_House2_Messenger::
	lock
	goto_if_set FLAG_DEFEATED_RAYQUAZA, NiagaraVillage_MessengerByWoodsPostDracaster
	msgbox NiagaraVillage_Text_BylawsAmendNextMonth, MSGBOX_NPC
	release
	end

NiagaraVillage_Text_BylawsAmendNextMonth:
	.string "One hundred years ago, the Council\n"
	.string "set forth the bylaws for our order.\p"
	.string "I think they're going to be\n"
	.string "amended at next month's meeting.$"
