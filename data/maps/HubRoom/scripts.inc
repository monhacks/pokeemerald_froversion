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
	warp MAP_POISON1, 1, 40 , 12
	release
end



HubRoom_Text_WouldYouLikeToEnterIceRoom:
	.string "Would you like to enter the \nIce Room?$"


HubRoom_EventScripts_WouldYouLikeToEnterWaterRom::
	lockall
	goto_if_unset FLAG_DEFEATED_ICE, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterWaterRom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToWaterRom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToWaterRom:
	warp MAP_WATERT, 0, 40 , 12
	release
end

HubRoom_Text_WouldYouLikeToEnterWaterRom:
	.string "Would you like to enter the \nWater Room?$"



HubRoom_Text_WouldYouLikeToEnterFireRoom:
	.string "Would you like to enter the \nFire Room?$"



HubRoom_EventScripts_WouldYouLikeToEnterFireRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_WATER, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterFireRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToFireRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToFireRoom:
	warp MAP_NEW_MAP2, 0, 40 , 12
	release
end

HubRoom_EventScripts_WouldYouLikeToEnterElectricRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_FIRE, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterElectricRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToElectricRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToElectricRoom:
	warp MAP_ELECTRIC1, 0, 40 , 12
	release
end



HubRoom_Text_WouldYouLikeToEnterElectricRoom:
	.string "Would you like to enter the \nElectric Room?$"

HubRoom_EventScripts_WouldYouLikeToEnterSteelRoom::
	lockall
	goto_if_unset FLAG_DEFEATED_ELECTRIC, HubRoom_EventScripts_HaventUnlockedRoom
	msgbox HubRoom_Text_WouldYouLikeToEnterSteelRoom, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq HubRoom_EventScripts_WarpToSteelRoom
	compare VAR_RESULT, NO
	goto_if_eq HubRoom_EventScripts_DontWarpToRoom
	releaseall
end

HubRoom_EventScripts_WarpToSteelRoom:
	warp MAP_STEEL1, 0, 40 , 12
	release
end



HubRoom_Text_WouldYouLikeToEnterSteelRoom:
	.string "Would you like to enter the \nSteel Room?$"



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
