.set LOCALID_STAIR_GUARD, 2

RustboroCity_ColangeloGraphics_1F_MapScripts:: @ 8211245
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_ColangeloGraphics_1F_OnTransition
	.byte 0

RustboroCity_ColangeloGraphics_1F_OnTransition: @ 821124B
	call_if_unset FLAG_RETURNED_COLANGELO_GEARS, RustboroCity_ColangeloGraphics_1F_EventScript_BlockStairs
	end

RustboroCity_ColangeloGraphics_1F_EventScript_BlockStairs:: @ 8211255
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_ColangeloGraphics_1F_EventScript_Employee:: @ 8211261
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_COLANGELO_GEARS, RustboroCity_ColangeloGraphics_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_COLANGELO_GEARS_STOLEN, RustboroCity_ColangeloGraphics_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_ColangeloGraphics_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_1F_EventScript_RobberWasntBright:: @ 821127F
	msgbox RustboroCity_ColangeloGraphics_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_1F_EventScript_GoodsRecovered:: @ 8211289
	msgbox RustboroCity_ColangeloGraphics_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_1F_EventScript_StairGuard:: @ 8211293
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_COLANGELO_GEARS, RustboroCity_ColangeloGraphics_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_COLANGELO_GEARS, RustboroCity_ColangeloGraphics_1F_EventScript_GotRobbed
	goto_if_set FLAG_COLANGELO_GEARS_STOLEN, RustboroCity_ColangeloGraphics_1F_EventScript_GotRobbed
	msgbox RustboroCity_ColangeloGraphics_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_1F_EventScript_AlwaysWelcome:: @ 82112BA
	msgbox RustboroCity_ColangeloGraphics_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_1F_EventScript_GotRobbed:: @ 82112C4
	msgbox RustboroCity_ColangeloGraphics_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_1F_EventScript_Greeter:: @ 82112CE
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_COLANGELO_GEARS, RustboroCity_ColangeloGraphics_1F_EventScript_WelcomeToColangeloGraphics
	goto_if_set FLAG_RECOVERED_COLANGELO_GEARS, RustboroCity_ColangeloGraphics_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_COLANGELO_GEARS_STOLEN, RustboroCity_ColangeloGraphics_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_ColangeloGraphics_1F_Text_WelcomeToColangeloGraphics, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_1F_EventScript_WelcomeToColangeloGraphics:: @ 82112F5
	msgbox RustboroCity_ColangeloGraphics_1F_Text_WelcomeToColangeloGraphics, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_1F_EventScript_StaffGotRobbed:: @ 82112FF
	msgbox RustboroCity_ColangeloGraphics_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_ColangeloGraphics_1F_EventScript_RocksMetalDisplay:: @ 8211309
	msgbox RustboroCity_ColangeloGraphics_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_ColangeloGraphics_1F_EventScript_ProductsDisplay:: @ 8211312
	msgbox RustboroCity_ColangeloGraphics_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_ColangeloGraphics_1F_Text_WelcomeToColangeloGraphics: @ 821131B
	.string "Hello and welcome to Colangelo\n"
	.string "Graphics.\p"
	.string "We're proud producers of items and\n"
	.string "medicine that enhance your life.$"

RustboroCity_ColangeloGraphics_1F_Text_StaffGotRobbed: @ 821138B
	.string "One of our research staff stupidly\n"
	.string "got robbed of an important parcel.$"

RustboroCity_ColangeloGraphics_1F_Text_ThoseShoesAreOurProduct: @ 82113D1
	.string "Hey, those Running Shoes!\n"
	.string "They're one of our products!\p"
	.string "It makes me happy when I see someone\n"
	.string "using something we made.$"

RustboroCity_ColangeloGraphics_1F_Text_RobberWasntVeryBright: @ 8211446
	.string "That stolen parcel…\p"
	.string "Well, sure it's important, but it's not\n"
	.string "anything that anyone can use.\p"
	.string "In my estimation, that robber must not\n"
	.string "have been very bright.$"

RustboroCity_ColangeloGraphics_1F_Text_SoundsLikeStolenGoodsRecovered: @ 82114DE
	.string "It sounds like they've recovered\n"
	.string "the ripped-off Colangelo Gears.$"

RustboroCity_ColangeloGraphics_1F_Text_OnlyAuthorizedPeopleEnter: @ 821151B
	.string "I'm sorry, only authorized personel\n"
	.string "are allowed to enter here.$"

RustboroCity_ColangeloGraphics_1F_Text_HowCouldWeGetRobbed: @ 8211558
	.string "It's beyond stupid.\n"
	.string "How could we get robbed?$"

RustboroCity_ColangeloGraphics_1F_Text_YoureAlwaysWelcomeHere: @ 8211585
	.string "Hi, there!\n"
	.string "You're always welcome here!$"

RustboroCity_ColangeloGraphics_1F_Text_RocksMetalDisplay: @ 82115AC
	.string "Samples of rocks and metal are\n"
	.string "displayed in the glass case.\p"
	.string "There's a panel with some writing\n"
	.string "on it…\p"
	.string "“Colangelo Graphics got its start as\n"
	.string "a freelance group working out of the.\l"
	.string "“presidents basement.\p"
	.string "“From that humble start as a graphics\n"
	.string "design firm, Colangelo branched out.\p"
	.string "“Colangelo is now a producer of a wide\n"
	.string "range of industrial products.”$"

RustboroCity_ColangeloGraphics_1F_Text_ProductDisplay: @ 8211722
	.string "Prototypes and test products fill\n"
	.string "the glass display case.\p"
	.string "There's a panel with a description…\p"
	.string "“In addition to industrial products,\n"
	.string "Colangelo now markets sundries and\l"
	.string "pharmaceuticals for better lifestyles.\p"
	.string "“Recently, Colangelo has begun marketing\n"
	.string "tools for Pokémon Trainers, including\l"
	.string "Poké Balls and Pokénav systems.”$"

