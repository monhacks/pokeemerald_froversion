NiagaraVillage_House1_MapScripts::
	.byte 0

NiagaraVillage_House1_Messenger::
	lock
	goto_if_set FLAG_DEFEATED_RAYQUAZA, NiagaraVillage_MessengerByWoodsPostDracaster
	msgbox NiagaraVillage_Text_PrivateOrder, MSGBOX_NPC
	release
	end

NiagaraVillage_Text_PrivateOrder:
	.string "The Messengers are a private order.\p"
	.string "You cannot join.\n"
	.string "Please do not ask to join.$"
