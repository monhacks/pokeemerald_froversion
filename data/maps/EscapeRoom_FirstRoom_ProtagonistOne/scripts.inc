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
		special BufferStoredPokemon
		scrollingmultichoice 16, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyB
		compare VAR_RESULT, 1
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyC
		release
		end

EscapeRoom_FirstRoom_ProtagonistB_EventScripts_FunctionalTradeMenu::
		special BufferStoredPokemon
		scrollingmultichoice 17, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyA
		compare VAR_RESULT, 1
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyC
		release
		end

EscapeRoom_FirstRoom_ProtagonistC_EventScripts_FunctionalTradeMenu::
		special BufferStoredPokemon
		scrollingmultichoice 18, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyA
		compare VAR_RESULT, 1
		goto_if_eq EscapeRoom_FirstRoom_LoadDynamicPartyB
		release
		end

EscapeRoom_FirstRoom_LoadDynamicPartyA::
	msgbox EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike, MSGBOX_DEFAULT
		//set the text var for the two party pokemon somehow
		//set the text var for the two party pokemon somehow
		scrollingmultichoice 19, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		//goto_if_eq TradeFirstPokemon
		compare VAR_RESULT, 1
		//goto_if_eq TradeSecondPokemon
		release
		end

EscapeRoom_FirstRoom_LoadDynamicPartyB::
	msgbox EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike, MSGBOX_DEFAULT
		//set the text var for the two party pokemon somehow
		//set the text var for the two party pokemon somehow
		scrollingmultichoice 19, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		//goto_if_eq TradeFirstPokemon
		compare VAR_RESULT, 1
		//goto_if_eq TradeSecondPokemon
		release
		end

EscapeRoom_FirstRoom_LoadDynamicPartyC::
	msgbox EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike, MSGBOX_DEFAULT
		//set the text var for the two party pokemon somehow
		//set the text var for the two party pokemon somehow
		scrollingmultichoice 19, 2, 3, 2, TRUE
		compare VAR_RESULT, 0
		//goto_if_eq TradeFirstPokemon
		compare VAR_RESULT, 1
		//goto_if_eq TradeSecondPokemon
		release
		end

EscapeRoom_FirstRoom_Text_WhoWouldYouLikeToTradeWith:
	.string "Who would you like to trade with?$"

EscapeRoom_FirstRoom_Text_WhichPokemonWouldYouLike:
	.string "Which Pokemon Would you Like?$"
