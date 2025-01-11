EscapeRoom_IceCave1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IceCave1_OnFrame
	.byte 0


IceCave1_OnFrame: @ 8238C4F
	map_script_2 VAR_TEMP_1, 0, IceCave1_EventScript_CheckOverheat
	.2byte 0

IceCave1_EventScript_CheckOverheat::
	goto EventScript_Overheat
	end

IceCave1_EventScript_YouWillNeedToFaceBobbyInMarkards::
	lock
	msgbox IceCave1_Text_YouWillNeedToFaceBobbyInMarkards, MSGBOX_DEFAULT
	release
	end

IceCave1_Text_YouWillNeedToFaceBobbyInMarkards:	
	.string "The Pai Gow master is eagerly\n" 
	.string "awaiting a challenge in a card\l"
	.string "game you have recieved as a previous\l"
	.string "secret santa gift\p"
	.string "A specific prize card holds a clue\n"
	.string "for you to progress.\p"
	.string "If you can win, choose your prize\n"
	.string "card wisely...$"
