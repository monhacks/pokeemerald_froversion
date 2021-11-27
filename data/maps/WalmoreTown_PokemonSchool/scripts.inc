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

WalmoreTown_PokemonSchool_EventScript_GameboyKid1:: @ 8213F5F
	msgbox WalmoreTown_PokemonSchool_Text_NotPayingAttention, MSGBOX_NPC
	end

WalmoreTown_PokemonSchool_EventScript_GameboyKid2:: @ 8213F68
	msgbox WalmoreTown_PokemonSchool_Text_TryingToLearn, MSGBOX_NPC
	end

WalmoreTown_PokemonSchool_EventScript_SchoolKidM:: @ 8213F71
	msgbox WalmoreTown_PokemonSchool_Text_PokemonTrainingTip, MSGBOX_NPC
	end

WalmoreTown_PokemonSchool_EventScript_Lass:: @ 8213F7A
	msgbox WalmoreTown_PokemonSchool_Text_GainExpEvenWhenCatching, MSGBOX_NPC
	end

WalmoreTown_PokemonSchool_EventScript_Teacher::
	msgbox WalmoreTown_PokemonSchool_Text_TeachingIsHard, MSGBOX_NPC
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

WalmoreTown_PokemonSchool_Text_NotPayingAttention:
	.string "I'm supposed to be paying attention to\n"
	.string "learn about Pokémon, but I would rather\l"
	.string "talk to my friend.$"

WalmoreTown_PokemonSchool_Text_TryingToLearn:
	.string "I come here to learn, but it's hard when\n"
	.string "my friends would rather chat than listen\l"
	.string "to the teacher.$"

WalmoreTown_PokemonSchool_Text_PokemonTrainingTip:
	.string "Teach says to always keep in mind a\n"
	.string "Pokémon's nature. Different natures\l"
	.string "boost different stats, but they also\l"
	.string "lower a stat as well.\p"
	.string "You can tell a Pokémon's nature and\n"
	.string "what stats they affect in the summary\l"
	.string "screen!$"

WalmoreTown_PokemonSchool_Text_GainExpEvenWhenCatching:
	.string "Your Pokémon will gain Exp when you\n"
	.string "catch wild Pokémon!$"

WalmoreTown_PokemonSchool_Text_TeachingIsHard:
	.string "It is hard to teach everything\n"
	.string "there is to know about Pokémon battles\p"
	.string "Did you know there are 17 types of \nPokémon?$"
