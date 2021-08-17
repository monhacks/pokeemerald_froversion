RustboroCity_Gym_MapScripts:: @ 8212F30
	.byte 0

RustboroCity_Gym_EventScript_Roxanne:: @ 8212F31
	setvar VAR_MUGSHOT_ID, MUGSHOT_CHADANDMARK
	setflag FLAG_BATTLE_POISON_FIELD
	setflag FLAG_SYS_NO_BAG_USE
	trainerbattle_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_MarkAndChadNeedTwoMons, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	clearflag FLAG_BATTLE_POISON_FIELD
	clearflag FLAG_SYS_NO_BAG_USE
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM39, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_CantBattleYetLostNameBadge:
	setflag FLAG_TEMP_1
	msgbox SummitCity_Gym_Text_ChadLostNameBadge, MSGBOX_AUTOCLOSE
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated:: @ 8212F66
	clearflag FLAG_BATTLE_POISON_FIELD
	clearflag FLAG_SYS_NO_BAG_USE
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb:: @ 8212FA4
	giveitem ITEM_TM06
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch:: @ 8212FC8
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh:: @ 8212FE3
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	goto_if_set FLAG_TEMP_1, RustboroCity_Gym_EventScript_JoshSearching
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_JoshSearching:
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattleSearching, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy:: @ 8212FFA
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc:: @ 8213011
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	goto_if_set FLAG_TEMP_1, RustboroCity_Gym_EventScript_MarcSearching
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_MarcSearching:: @ 8213011
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	setvar VAR_0x8000, MUGSHOT_SEARS_PA
	msgbox RustboroCity_Gym_Text_MarcSearchingPostBattle, MSGBOX_AUTOCLOSE
	callnative DrawMugshot
	msgbox SummitCity_Gym_Text_CheckOutThisMap, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuide:: @ 8213028
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	goto_if_set FLAG_TEMP_4, SummitCity_Gym_EventScript_CheckOutThisMap
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_CheckOutThisMap:
	msgbox SummitCity_Gym_Text_CheckOutThisMap, MSGBOX_DEFAULT
	setvar VAR_0x8000, MUGSHOT_SEARS_TREASURE_MAP
	callnative DrawMugshot
	msgbox SummitCity_Gym_Text_TakeYourTime, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SummitCityGym_EventScript_TakeYourTime
	callnative ClearMugshot
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory:: @ 821303D
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue:: @ 8213047
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue:: @ 8213057
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified:: @ 8213067
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue:: @ 8213071
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne:: @ 821307B
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice: @ 821309D
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "Would you like to become the Champion?\p"
	.string "I'm no Champion, not me, but I can\n"
	.string "sure give you winning advice.\p"
	.string "That's settled, then! We'll aim for the\n"
	.string "Pokémon Championship together!\p"
	.string "It's your job as a Champion to collect\n"
	.string "Gym Badges, am I right?\p"
	.string "But Gym Leaders aren't pushovers!\p"
	.string "And that's where I come in!\n"
	.string "I'm here to provide expert advice!\p"
	.string "Also, the Leaders Chad and Mark are\n"
	.string "constantly smoking or vaping, and it\l"
	.string "leaves the field covered in poisonus\l"
	.string "fumes.\p"
	.string "Poison-Type Pokémon seem to love it\n"
	.string "but any non Poison-Type Pokémon take\l"
	.string "damage every turn.\p"
	.string "If I were you I would use a Poison-\n"
	.string "Type Pokémon, or find a way to trick\l"
	.string "the fumes into thinking your Pokémon\l"
	.string "is Poison-Type.\p"
	.string "Come see me afterwards, if you beat\n"
	.string "the Gym Leader.\p"
	.string "Well, go for it!$"

RustboroCity_Gym_Text_GymGuidePostVictory: @ 82132E2
	.string "Whoa! What a breathtaking victory!\n"
	.string "My cheering must've worked!\p"
	.string "Great!\n"
	.string "Check your Trainer Card.\p"
	.string "The STONE BADGE you got should be\n"
	.string "properly recorded on it.\p"
	.string "In other words…\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the Championship!\p"
	.string "That's got to feel awesome!$"

RustboroCity_Gym_Text_JoshIntro: @ 82133E9
	.string "Don't take us Gym Trainers lightly!\n"
	.string "I'll show you why we're better!$"

RustboroCity_Gym_Text_JoshDefeat: @ 821342D
	.string "You were too good for me…$"

RustboroCity_Gym_Text_JoshPostBattle: @ 8213447
	.string "You haven't seen anything of the Poison\n"
	.string "type's terrifying power!$"

RustboroCity_Gym_Text_TommyIntro: @ 8213486
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against Chad And Mark!$"

RustboroCity_Gym_Text_TommyDefeat: @ 82134C6
	.string "Wow! You've got some potential!$"

RustboroCity_Gym_Text_TommyPostBattle: @ 82134E6
	.string "Chad And Mark are stronger than me by\n"
	.string "several times.\p"
	.string "You'd better be on your guard!$"

RustboroCity_Gym_Text_MarcIntro: @ 8213533
	.string "We might be in the middle of town,\n"
	.string "but so what?\p"
	.string "My Poison Pokémon need room to\n"
	.string "rampage!$"

RustboroCity_Gym_Text_MarcDefeat: @ 8213589
	.string "Oh, man oh man!\n"
	.string "Our challenger is one feisty customer!$"

RustboroCity_Gym_Text_MarcPostBattle: @ 82135C0
	.string "I have to hand it to our Leaders.\p"
	.string "It took smarts and sense for them to\n"
	.string "pick the Poison type at her young age.$"

RustboroCity_Gym_Text_RoxanneIntro: @ 821362A
	.string "Since you've been grounded we have\n"
	.string "become the Summit City Gym Leaders.\p"
	.string "What better spot for us to be in\n"
	.string "than where it all started?\p"
	.string "Let's see what you've got buddy!$"

RustboroCity_Gym_Text_RoxanneDefeat: @ 821370B
	.string "Chad: So…\n"
	.string "We lost…\p"
	.string "Mark: That was INTERESTING!!!!\p"
	.string "Chad: The Pokémon League's rules state\n"
	.string "that Trainers are to be given this\l"
	.string "if they defeat a Gym Leader.\p"
	.string "Mark: Please accept the official Pokémon\n"
	.string "League STONE BADGE.$"

RustboroCity_Gym_Text_ReceivedStoneBadge: @ 82137EC
	.string "{PLAYER} received the STONE BADGE\n"
	.string "from Chad And Mark.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis: @ 8213816
	.string "The STONE BADGE heightens the ATTACK\n"
	.string "power of your Pokémon.\p"
	.string "It also enables them to use the HM move\n"
	.string "CUT outside of battle.\p"
	.string "Please take this with you, too.$"

RustboroCity_Gym_Text_ExplainRockTomb: @ 82138B1
	.string "That Technical Machine, TM06,\n"
	.string "contains Toxic.\p"
	.string "It badly poisons the target, dealing\n"
	.string "double the damage from poison each turn.\p"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a Pokémon.$"

RustboroCity_Gym_Text_RoxannePostBattle: @ 82139A7
	.string "Since you are so strong, you should\n"
	.string "challenge other Gym Leaders.\p"
	.string "By battling many Trainers, you should\n"
	.string "learn many things.$"

RustboroCity_Gym_Text_GymStatue: @ 8213A21
	.string "Summit City Pokémon Gym$"

RustboroCity_Gym_Text_GymStatueCertified: @ 8213A3B
	.string "Summit City Pokémon Gym\p"
	.string "Chad's Certified Trainers:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall: @ 8213A76
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Chad: Oh, hello, {PLAYER}?\n"
	.string "This is Chad of Summit City.\p"
	.string "I heard from Wes that you're\n"
	.string "moving up through the ranks of\l"
	.string "Trainers at an incredible clip.\p"
	.string "Well, I'd rather not think that\n"
	.string "I can't beat you.\p"
	.string "I promise, I will shape up my Gym\n"
	.string "so that you may challenge us again.\p"
	.string "I hope you'll be looking forward to\n"
	.string "that occasion as much as me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne: @ 8213C01
	.string "Registered Gym Leader Chad And Mark\n"
	.string "in the Pokénav.$"

RustboroCity_Gym_Text_RoxannePreRematch: @ 8213C2F
	.string "Chad And Mark: I'm so glad to see you again.\n"
	.string "I'm Chad And Mark, the Gym Leader here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat: @ 8213CF9
	.string "Grr…\n"
	.string "Again, we have lost…$"

RustboroCity_Gym_Text_RoxannePostRematch: @ 8213D12
	.string "Chad And Mark: I still have much to learn\n"
	.string "when it comes to battling Pokémon.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons: @ 8213D93
	.string "Chad And Mark: I'm so glad to see you again.\n"
	.string "I'm Chad And Mark, the Gym Leader here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one Pokémon with you?\p"
	.string "Please return with at least one more\n"
	.string "Pokémon.$"

RustboroCity_Gym_MarkAndChadNeedTwoMons:
	.string "Mark and Chad: Yo fro, you need to \nPokémon since we will be having a \ldouble battle!$"

SummitCity_Gym_Text_ChadLostNameBadge:
	.string "Mark and Chad: {PLAYER}!\p"
	.string "It is great to see you.\p"
	.string "We would love to battle you, but Chad\n"
	.string "lost his name Badge. Now challengers\l"
	.string "won't know who is who!\p"
	.string "Please help us find his name badge.\n"
	.string "I wonder if Patches over in Electronics\l"
	.string "knows where it is...\p"
	.string "After we find it, we will battle you.$"

RustboroCity_Gym_Text_JoshPostBattleSearching:
	.string "Chad's name badge? Haven't seen it.\n"
	.string "Why don't you ask the fella in\l"
	.string "the matress department.$"

RustboroCity_Gym_Text_MarcSearchingPostBattle:
	.string "Oh yea, Chad's name badge. I think\n"
	.string "I saw it in one of the refridgerators!$"

SummitCity_Gym_Text_CheckOutThisMap:
	.string "Ah, so Chad and Mark are pulling this\n"
	.string "trick again, huh?\p"
	.string "Very well, take a look at this map of\n"
	.string "the gym and try to look for anything\l"
	.string "that doesn't look right.$"
