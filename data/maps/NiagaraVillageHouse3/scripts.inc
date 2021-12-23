NiagaraVillageHouse3_MapScripts::
	.byte 0


NiagaraVillage_House3_Messenger::
	lock
	goto_if_set FLAG_DEFEATED_RAYQUAZA, NiagaraVillage_MessengerByWoodsPostDracaster
	msgbox NiagaraVillage_Text_PayCarefulAttention, MSGBOX_NPC
	release
	end

NiagaraVillage_Text_PayCarefulAttention:
	.string "You should pay careful attention to\n"
	.string "the messages.\p"
	.string "More is at stake than you realize.$"
