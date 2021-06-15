WalmoreTown_PokemonSchool_MapScripts::
	.byte 0

WalmoreTown_PokemonSchool_EventScript_Blackboard:: @ 8213EA9
	lockall
	msgbox WalmoreTown_PokemonSchool_Text_BlackboardListsNewMechanics, MSGBOX_DEFAULT
	goto WalmoreTown_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

WalmoreTown_PokemonSchool_EventScript_ChooseBlackboardTopic:: 
	message WalmoreTown_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_NEW_MECHANICS, 3, 0
	switch VAR_RESULT
	case 0, WalmoreTown_PokemonSchool_EventScript_AbilitieLearnsets
	case 1, WalmoreTown_PokemonSchool_EventScript_TypeEffectiveness
	case 2, WalmoreTown_PokemonSchool_EventScript_HeldItems
	case 3, WalmoreTown_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, WalmoreTown_PokemonSchool_EventScript_ExitTopicSelect
	end

	WalmoreTown_PokemonSchool_EventScript_AbilitieLearnsets:: @ 8213F17
	msgbox WalmoreTown_PokemonSchool_Text_ExplainAbilityLearnsets, MSGBOX_DEFAULT
	goto WalmoreTown_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

WalmoreTown_PokemonSchool_EventScript_TypeEffectiveness:: @ 8213F17
	msgbox WalmoreTown_PokemonSchool_Text_ExplainTypeEffectiveness, MSGBOX_DEFAULT
	goto WalmoreTown_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

WalmoreTown_PokemonSchool_EventScript_HeldItems:: @ 8213F17
	msgbox WalmoreTown_PokemonSchool_Text_ExplainHeldItems, MSGBOX_DEFAULT
	goto WalmoreTown_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

WalmoreTown_PokemonSchool_EventScript_ExitTopicSelect:: @ 8213F5D
	releaseall
	end

///////////////////////////////////////////
////////////////TEXTS//////////////////////
///////////////////////////////////////////

WalmoreTown_PokemonSchool_Text_BlackboardListsNewMechanics: @ 82140B2
	.string "The blackboard lists some factors\n"
	.string "that may affect Pokémon in battle.$"

WalmoreTown_PokemonSchool_Text_ReadWhichTopic: @ 82140F9
	.string "Which topic do you want to read?$"
	
WalmoreTown_PokemonSchool_Text_ExplainAbilityLearnsets:
	.string "Every Pokémon is born with an\n"
	.string "ability, but as they level up they\l"
	.string "unlock new abilities.\p"
	.string "You can change their ability anytime\n"
	.string "through the start menu.$"

WalmoreTown_PokemonSchool_Text_ExplainTypeEffectiveness:
	.string "Every Pokémon has a Type.\p"
	.string "Some types of attacks are more\n"
	.string "effective than others.\p"
	.string "During battle the selected move is\n"
	.string "color coded to show how effective an\l"
	.string "attack will be to the target$"

WalmoreTown_PokemonSchool_Text_ExplainHeldItems:
	.string "Your Pokémon can hold certain items,\n"
	.string "and they all have different effects\l"
	.string "during battle.\p"
	.string "For example, a Choice Scarf will make\n"
	.string "your Pokémon super fast, but limit the\l"
	.string "moves they can select.$"
