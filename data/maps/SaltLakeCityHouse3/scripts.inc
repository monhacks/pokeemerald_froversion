.set LOCALID_MAN, 1
.set LOCALID_GRUNT_1, 2

SaltLakeCityHouse3_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaltLakeCityHouse3_OnFrame
	.byte 0


SaltLakeCityHouse3_OnFrame:
	map_script_2 VAR_MAGEE_VERSION, 6, SaltLakeCityHouse3_EventScript_GruntBattle
	.2byte 0

SaltLakeCityHouse3_EventScript_Man::
	msgbox SaltLakeCity_Text_ManAfterBattle2, MSGBOX_NPC
	end

SaltLakeCityHouse3_EventScript_GruntBattle:
	lockall
		msgbox SaltLakeCity_Text_HeyLeaveHimAlone, MSGBOX_DEFAULT
		playse SE_PIN
		applymovement LOCALID_GRUNT_1, SaltLakeCity_Movement_LookShocked
		applymovement LOCALID_MAN, SaltLakeCity_Movement_LookShocked
		waitmovement LOCALID_MAN
		msgbox SaltLakeCity_Text_NoneOfYourBusiness, MSGBOX_DEFAULT
		applymovement LOCALID_GRUNT_1, SaltLakeCity_Movement_WalkToPlayer
		waitmovement LOCALID_GRUNT_1
		trainerbattle_no_intro TRAINER_GRUNT_SALT_LAKE, SaltLakeCity_Text_GruntDefeatedMessage
		setvar VAR_MAGEE_VERSION, 7
		applymovement LOCALID_GRUNT_1, SaltLakeCity_Movement_GruntLeaves
		waitmovement LOCALID_GRUNT_1
		removeobject LOCALID_GRUNT_1
		setflag FLAG_HIDE_SALT_LAKE_CITY_GRUNT
		msgbox SaltLakeCity_Text_ManAfterBattle, MSGBOX_DEFAULT
		msgbox SaltLakeCity_Text_ManAfterBattle2, MSGBOX_DEFAULT
	releaseall
	end
		

SaltLakeCity_Movement_LookShocked:
	face_down
	emote_exclamation_mark
	step_end

SaltLakeCity_Movement_WalkToPlayer:
	walk_left
	walk_down
	walk_down
	step_end

SaltLakeCity_Movement_GruntLeaves:
	walk_right
	walk_down
	step_end

SaltLakeCity_Text_HeyLeaveHimAlone:
	.string "Man: Please, I just need a little more\n"
	.string "time to get the money together.\p"
	.string "MAGA Grunt: No more delays! If you want\n"
	.string "protection, you need to pay up.\p"
	.string "Man: But-\p"
	.string "MAGA Grunt: No buts! Hand it over, or\n"
	.string "you'll regret it!\p"
	.string "{PLAYER}: Hey! Leave him alone!$"

SaltLakeCity_Text_NoneOfYourBusiness:
	.string "MAGA Grunt: This is none of your\n"
	.string "business, {PLAYER}. But if you want\l"
	.string "a fight, I'll gladly give you one!$"

SaltLakeCity_Text_GruntDefeatedMessage:
	.string "MAGA Grunt: Grr... I don't have time\n"
	.string "for this! I need to get to Riverton\l"
	.string "before the boat departs.\p"
	.string "This little scuffle took too much\n"
	.string "time already. You'll regret crossing\l"
	.string "crossing Team MAGA!$"

SaltLakeCity_Text_ManAfterBattle:
	.string "Man: Thank you so much, {PLAYER}.\n"
	.string "That guy was just stealing money.\p"
	.string "They call it protection, but it's just\n"
	.string "an excuse to bully and rob us!$"

SaltLakeCity_Text_ManAfterBattle2:
	.string "I overheard something about Team\n"
	.string "MAGA using Riverton's harbor.\p"
	.string "They've been transporting all kinds\n"
	.string "of suspicious goods there.\p"
	.string "Maybe following them to Riverton will\n"
	.string "help you find Metagross!$"

