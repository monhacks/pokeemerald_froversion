NewMap2_MapScripts::
	.byte 0


HomesteadNorth_Mart_EventScript_Clerk:: @ 81FC240
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Homestead_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Mart_EventScript_Man1::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_LetItSnow, MSGBOX_DEFAULT
	release
end

HomesteadNorth_Mart_EventScript_Woman1::
	lock
	faceplayer
	msgbox HomesteadNorth_Text_FavoritePartOfYear, MSGBOX_DEFAULT
	release
end

.align 2
Homestead_Mart_Pokemart: @ 81FC260
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

HomesteadNorth_Text_LetItSnow:
	.string "Let it snow, let it snow, let it\n snow!!!\p"
	.string "I love this time of year!$"

HomesteadNorth_Text_FavoritePartOfYear:
	.string "My favorite part about December 26?\n"
	.string "Only 364 days until Christmas!$"