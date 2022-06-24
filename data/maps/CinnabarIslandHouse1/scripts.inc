CinnabarIslandHouse1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_House_1_OnLoad
	.byte 0
CinnabarIsland_House_1_OnLoad:
	compare VAR_ROUTE101_STATE, 3
	call_if_ge CinnabarIsland_House_1_EventScript_SetDynamicWarpPostSleep
	call_if_lt CinnabarIsland_House_1_EventScript_SetDynamicWarpPreSleep
	end

@--------------------------------------------------------------------------------
@------------------------------------Events--------------------------------------
@--------------------------------------------------------------------------------
CinnabarIsland_House_1_EventScript_SetDynamicWarpPreSleep:
	setdynamicwarp MAP_CINNIBAR_ISLAND, 255, 33, 47
end

CinnabarIsland_House_1_EventScript_SetDynamicWarpPostSleep:
	setdynamicwarp MAP_CINNABAR_ISLAND_POST_SHIP_WRECK, 255, 33, 47
end

CinnabarIslandHouse1_EventScript_Student1::
	msgbox CinnabarIslandHouse1_Text_Student1, MSGBOX_DEFAULT
	closemessage
	end

CinnabarIslandHouse1_EventScript_Student2::
	msgbox CinnabarIslandHouse1_Text_Student2, MSGBOX_NPC
	end

CinnabarIslandHouse1_EventScript_Student3::
	msgbox CinnabarIslandHouse1_Text_Student3, MSGBOX_NPC
	end

CinnabarIslandHouse1_EventScript_Student4::
	msgbox CinnabarIslandHouse1_Text_Student4, MSGBOX_NPC
	end

CinnabarIslandHouse1_EventScript_Student5::
	msgbox CinnabarIslandHouse1_Text_Student5_1, MSGBOX_DEFAULT
	closemessage
	msgbox CinnabarIslandHouse1_Text_Student5_2, MSGBOX_NPC
	closemessage
	end

CinnabarIslandHouse1_EventScript_Student6::
	msgbox CinnabarIslandHouse1_Text_Student6, MSGBOX_NPC
	end

CinnabarIslandHouse1_EventScript_Student7::
	msgbox CinnabarIslandHouse1_Text_Student7, MSGBOX_NPC
	end

CinnabarIslandHouse1_EventScript_Teacher::
	msgbox CinnabarIslandHouse1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	end

@--------------------------------------------------------------------------------
@-------------------------------------Text---------------------------------------
@--------------------------------------------------------------------------------
@'''''''''''[______________________________________]

CinnabarIslandHouse1_Text_Student1:
	.string "ZZZzzz...$"

CinnabarIslandHouse1_Text_Student2:
	.string "I thought studying abroad would be a\n"
	.string "cool idea but this island is so boring.$"

CinnabarIslandHouse1_Text_Student3:
	.string "This reading was titled 'Basic Pokemon\n"
	.string "anatomy' but this prof is so fixated\p"
	
	
	.string "on the brain. Like, dude, is this\n"
	.string "neurobiology, am i right?$"

CinnabarIslandHouse1_Text_Student4:
	.string "Did you know this prof right there has\n"
	.string "a PhD in Genetics? I bet he cloned\p"
	
	
	.string "himself to not attend this reading.\n"
	.string "Can't blame him to be honest.$"

CinnabarIslandHouse1_Text_Student5_1:
	.string "'The brain ... central nervous...'$"

	CinnabarIslandHouse1_Text_Student5_2:
	.string "Could you please stop reading my\n"
	.string "notes? Just sit down already!$"

CinnabarIslandHouse1_Text_Student6:
	.string "This reading is so basic it almost\n"
	.string "hurts. Any good movies lately?$"

CinnabarIslandHouse1_Text_Student7:
	.string "When I have my PhD i will build an\n"
	.string "underground lab just because I can.\p"
	
	
	.string "Or I start growing crystals. As a\n"
	.string "hobby. Maybe I can do both.Hmmm...$"

CinnabarIslandHouse1_Text_Teacher:
	.string "And that's why Oxytocin plays a key\n"
	.string "role in forming intra and interspecial\p"
	
	
	.string "relationships. Moderating the Oxytocin\n"
	.string "level thus enables switching between\p"

	.string "a social, obedient state and an\n"
	.string "uncontrollable state of aggression.$"	


