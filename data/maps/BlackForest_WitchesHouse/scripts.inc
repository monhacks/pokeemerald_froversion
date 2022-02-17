BlackForest_WitchesHouse_MapScripts::
	.byte 0

BlackForest_WitchesHouse_EventScript_Witch::
	lock
	goto_if_set FLAG_RECEIVED_SPELLBOOK, BlackForest_WitchesHouse_EventScript_WitchFoundSpellbook
	msgbox BlackForest_WitchesHouse_Text_WitchIntro, MSGBOX_DEFAULT
	release
end

BlackForest_WitchesHouse_EventScript_WitchFoundSpellbook:
	compare VAR_BLACK_FOREST_STATE, 0
	goto_if_gt BlackForest_WitchesHouse_Eventscript_WitchNeedItems
	msgbox BlackForest_WitchesHouse_Text_WitchFoundSpellbook, MSGBOX_DEFAULT
	setvar VAR_BLACK_FOREST_STATE, 1
	release
end

BlackForest_WitchesHouse_Eventscript_WitchNeedItems:
	msgbox BlackForest_WitchesHouse_Text_WitchNeedItems, MSGBOX_DEFAULT
	release
end

BlackForest_WitchesHouse_Text_WitchIntro:
	.string "Why hello, dear.\n"
	.string "I am the Witch of the Black Forest.\p"
	.string "I am trying out a new spell but I\n"
	.string "can't seem to find my Spellbook.\p"
	.string "There is a pesky Gastly that is\n"
	.string "always playing tricks on me. I bet\l"
	.string "he stole it.\p"
	.string "He likes to hide in mushrooms deep\n"
	.string "into the forest. Do you think you\l"
	.string "could find it for me?$"

BlackForest_WitchesHouse_Text_WitchFoundSpellbook:
	.string "Oh is that my Spellbook?\n"
	.string "Thank you for finding it! I knew that\l"
	.string "Gastly stole it!\p"

BlackForest_WitchesHouse_Text_WitchNeedItems:
	.string "Well this is no good! I don't have any\n"
	.string "of the ingredients for this spell.\p"
	.string "I need PLACEHOLDER from inside the\n"
	.string "GIANT HAUNTED TREE, PLACEHOLDER, and\l"
	.string "PLACEHOLDER.\p"
	.string "If you can find those, I will repay you\n"
	.string "with a special item.$"