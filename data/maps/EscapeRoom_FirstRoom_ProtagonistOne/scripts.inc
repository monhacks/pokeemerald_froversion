EscapeRoom_FirstRoom_ProtagonistOne_MapScripts::
	.byte 0


EscapeRoom_FirstRoom_EventScripts_FunctionalTradeMenu::
	msgbox EscapeRoom_FirstRoom_Text_WhoWouldYouLikeToTradeWith, MSGBOX_DEFAULT	
	special GetActiveChar
	switch VAR_RESULT
		case 0, EscapeRoom_FirstRoom_ProtagonistA_EventScripts_FunctionalTradeMenu
		case 1, EscapeRoom_FirstRoom_ProtagonistB_EventScripts_FunctionalTradeMenu
		case 2, EscapeRoom_FirstRoom_ProtagonistC_EventScripts_FunctionalTradeMenu
end

EscapeRoom_FirstRoom_ProtagonistA_EventScripts_FunctionalTradeMenu::
		scrollingmultichoice 16, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyB
		compare VAR_RESULT, 1
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyC
		release
		end

EscapeRoom_FirstRoom_ProtagonistB_EventScripts_FunctionalTradeMenu::
		scrollingmultichoice 17, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyA
		compare VAR_RESULT, 1
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyC
		release
		end

EscapeRoom_FirstRoom_ProtagonistC_EventScripts_FunctionalTradeMenu::
		scrollingmultichoice 18, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyA
		compare VAR_RESULT, 1
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyB
		release
		end

EscapeRoom_FirstRoom_LoadDynamicPartyA::
		setvar VAR_0x8006, 0
		setvar VAR_0x8007, 1
		special BufferStoredPokemon
	msgbox EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike, MSGBOX_DEFAULT
		setvar VAR_0x800B, 0
		scrollingmultichoice 19, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq TradePokemon
		compare VAR_RESULT, 1
		goto_if_eq TradePokemon
		release
		end

EscapeRoom_FirstRoom_LoadDynamicPartyB::
		setvar VAR_0x8006, 2
		setvar VAR_0x8007, 3
		special BufferStoredPokemon
	msgbox EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike, MSGBOX_DEFAULT
		setvar VAR_0x800B, 1
		scrollingmultichoice 19, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq TradePokemon
		compare VAR_RESULT, 1
		goto_if_eq TradePokemon
		release
		end

EscapeRoom_FirstRoom_LoadDynamicPartyC::
		setvar VAR_0x8006, 4
		setvar VAR_0x8007, 5
		special BufferStoredPokemon
	msgbox EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike, MSGBOX_DEFAULT
		setvar VAR_0x800B, 2
		scrollingmultichoice 19, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq TradePokemon
		compare VAR_RESULT, 1
		goto_if_eq TradePokemon
		release
		end

TradePokemon::
 msgbox EscapeRoom_FirstRoom_Text_WhichToTradeFor, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x8005 VAR_0x8004
	special CreateInGameCharacterTradePokemon
	special DoInGameTradeScene
	end

EscapeRoom_FirstRoom_Text_WhichToTradeFor:
	.string "Which do you want to trade for?$"

EscapeRoom_FirstRoom_Text_WhoWouldYouLikeToTradeWith:
	.string "Who would you like to trade with?$"

EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike:
	.string "Which Pokemon Would you Like?$"

EscapeRoom_Debug::
	msgbox EscapeRoom_FirstRoom_Text_Test, MSGBOX_DEFAULT
end

EscapeRoom_FirstRoom_Text_Test::
	.string "{STR_VAR_1}$"
