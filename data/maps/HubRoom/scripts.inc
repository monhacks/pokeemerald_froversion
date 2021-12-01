HubRoom_MapScripts::
	.byte 0

HubRoom_EventScripts_WouldYouLikeToEnterPoisonRoom::
	lockall
	msgbox HubRoom_Text_WouldYouLikeToEnterPoisonRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToPoisonRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToPoisonRoom:
	goto_if_unset FLAG_PICKED_STARTER, HubRoom_EventScripts_YouDontHaveAPokemon
	warp MAP_BUG_A, 0, 11, 78
	release
end


HubRoom_EventScripts_YouDontHaveAPokemon:
	msgbox HubRoom_Text_YouDontHaveAPokemon, MSGBOX_AUTOCLOSE
	release
end

HubRoom_Text_WouldYouLikeToEnterPoisonRoom:
	.string "Would you like to enter the \nPoison Room?$"

HubRoom_EventScripts_WouldYouLikeToEnterNormalRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_POISON, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterNormalRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToNormalRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToNormalRoom:
	warp MAP_BUG4, 0, 11, 78
	release
end

HubRoom_Text_WouldYouLikeToEnterNormalRoom:
	.string "Would you like to enter the \nNormal Room?$"

HubRoom_EventScripts_WouldYouLikeToEnterIceRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_NORMAL, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterIceRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToIceRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToIceRoom:
	warp MAP_POISON1, 0, 11, 78
	release
end



HubRoom_Text_WouldYouLikeToEnterIceRoom:
	.string "Would you like to enter the \nIce Room?$"


////////////////Universal/////////////////////

HubRoom_EventScripts_DontWarpToRoom:
	msgbox HubRoom_Text_PleaseComeBackWhenYoureReady, MSGBOX_DEFAULT
	releaseall	
end

HubRoom_EventScripts_HaventUnlockedRoom:
	msgbox HubRoom_Text_HaventUnlockedRoom, MSGBOX_DEFAULT
	releaseall
end

HubRoom_Text_PleaseComeBackWhenYoureReady:
	.string "Please come back whenever you \nare ready.$"

HubRoom_Text_HaventUnlockedRoom:
	.string "You haven't unlocked this room \nyet!$"

HubRoom_Text_YouDontHaveAPokemon:
	.string "You don't have a Pokemon, dummy.$"
