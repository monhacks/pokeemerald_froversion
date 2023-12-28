MAGM8DiaryEntry_EventScript_DiaryEntryFocusPunch::
	lock
	msgbox MAGM8DiaryEntry_Text_FoundDiaryEntry, MSGBOX_YESNO
		switch VAR_RESULT
		case NO, MAGM8DiaryEntry_EventScript_DiaryEntryFocusPunch_End
		case YES, MAGM8DiaryEntry_EventScript_DiaryEntryFocusPunch_LanguageCheck
		case MULTI_B_PRESSED, MAGM8DiaryEntry_EventScript_DiaryEntryFocusPunch_End
MAGM8DiaryEntry_EventScript_DiaryEntryFocusPunch_LanguageCheck:
	checkitem ITEM_POKEPRIMER, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MAGM8DiaryEntry_EventScript_DiaryEntryFocusPunch_MSGBOX_Pokeprimer
	msgbox MAGM8DiaryEntry_Text_DiaryEntryFocusPunch_English, MSGBOX_DEFAULT
	release
	end
MAGM8DiaryEntry_EventScript_DiaryEntryFocusPunch_MSGBOX_Pokeprimer:
	msgbox MAGM8DiaryEntry_Text_DiaryEntryFocusPunch_Pokeprimer, MSGBOX_DEFAULT
	release
	end
MAGM8DiaryEntry_EventScript_DiaryEntryFocusPunch_End:
	release
	end

MAGM8DiaryEntry_Text_DiaryEntryFocusPunch_English:
	.string "I really need to Focus.\p"
	.string "I can't seem to find my way through\n"
	.string "these woods.\p"
	.string "It feels like a Punch in the gut.\p"
	.string "I guess I just have to keep my head\n"
	.string "Up and keep moving.$"

MAGM8DiaryEntry_Text_DiaryEntryDragonClaw_English:
	.string "There are lots of different Pokémon\n"
	.string "the deeper I get into these woods\p"
	.string "I think I even saw a Dragon type\n"
	.string "Pokémon Claw it's way out of a\l"
	.string "tree truck Up ahead.$"

MAGM8DiaryEntry_Text_DiaryEntryWaterPulse_English:
	.string "It's been a few days since I've had\n"
	.string "Water.\p"
	.string "My Pulse is weakening. I should have\n"
	.string "prepared for this better.\p"
	.string "I can't give Up.\n"
	.string "Not now.$"

MAGM8DiaryEntry_Text_DiaryEntryCalmMind_English:
	.string "I ran into a water-type Pokémon.\n"
	.string "It was kind enough to help hydrate\l"
	.string "me.\p"
	.string "I feel better. My Mind is Calm.\p"
	.string "I'm feeling all Right.\n"
	.string "I can do this.$"

MAGM8DiaryEntry_Text_DiaryEntryRoar_English:
	.string "As I get deeper into the woods the\n"
	.string "stranger things seem.\p"
	.string "I heard a loud Roar, and I'm not.\n"
	.string "sure where it came from.\p"
	.string "It shook me deep Down to my core.$"

MAGM8DiaryEntry_Text_DiaryEntryToxic_English:
	.string "There are so many cute little Spinarak\n"
	.string "in this area of the woods!\p"
	.string "I just hope I don't get bit. There is\n"
	.string "no one Up here and the wound could\l"
	.string "could be infected with Toxic poison.$"

MAGM8DiaryEntry_Text_DiaryEntryHail_English:
	.string "Well that is interesting. It started\n"
	.string "to Hail! It's really coming Down!\p"
	.string "This place sure is strange. I have\n"
	.string "lost track of time, but there is no\l"
	.string "way it could be winter yet.$"

MAGM8DiaryEntry_Text_DiaryEntryFocusPunch_Pokeprimer:
	.string "Testing Different Paths need to adjust language\p"
	.string "I really need to Focus.\p"
	.string "I can't seem to find my way through\n"
	.string "these woods.\p"
	.string "It feels like a Punch in the gut.\p"
	.string "I guess the only thing Left to do\n"
	.string "is keep moving.$"

MAGM8DiaryEntry_Text_FoundDiaryEntry:
	.string "You've found a missing page from\n"
	.string "Professor Gooseberry's Journal.\p"
	.string "Would you like to read it?$"
