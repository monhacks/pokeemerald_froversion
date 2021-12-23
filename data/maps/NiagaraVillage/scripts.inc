NiagaraVillage_MapScripts::
	.byte 0


NiagaraVillage_Messenger2::
	lock
	goto_if_set FLAG_DEFEATED_RAYQUAZA, NiagaraVillage_MessengerByWoodsPostDracaster
	msgbox NiagaraVillage_Text_BeenHeedingOurWords, MSGBOX_NPC
	release
	end

NiagaraVillage_Messenger1::
	lock
	goto_if_set FLAG_DEFEATED_RAYQUAZA, NiagaraVillage_MessengerByWoodsPostDracaster
	msgbox NiagaraVillage_Text_TreadLightly, MSGBOX_NPC
	release
	end


NiagaraVillage_MessengerByWoods::
	lock
	goto_if_set FLAG_DEFEATED_RAYQUAZA, NiagaraVillage_MessengerByWoodsPostDracaster
	msgbox NiagaraVillage_Text_LookToConstellationsForDirections, MSGBOX_NPC
	release
	end

NiagaraVillage_MessengerByWoodsPostDracaster:
	msgbox NiagaraVillage_Text_ConstellationsGuidedYou, MSGBOX_NPC
	release
	end

NiagaraVillage_Text_LookToConstellationsForDirections:
	.string "These woods are where lost souls go\n"
	.string "to be at peace.\p"
	.string "Many men have wandered endlessly\n"
	.string "never finding their way out.\p"
	.string "When I get lost, I look to the\n"
	.string "{COLOR RED}Constellations{COLOR DARK_GREY} for directions.$"

NiagaraVillage_Text_ConstellationsGuidedYou:
	.string "The {COLOR RED} Constellations{COLOR DARK_GREY} have guided\n"
	.string "you well.\p"
	.string "I can feel the raw power emanating\n"
	.string "from your aura.$" 

NiagaraVillage_Text_TreadLightly:
	.string "It is most unusual for an outsider\n"
	.string "to be in our presence.\p"
	.string "I would tread lightly if I were you.$" 

NiagaraVillage_Text_BeenHeedingOurWords:
	.string "Have you been heeding our words?$"
	