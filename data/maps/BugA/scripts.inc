.set LOCALID_BUGBOSS1, 10

BugA_MapScripts::
	.byte 0

EventScript_BugRoomA_TrainerBattle1::
	lock
	trainerbattle_single TRAINER_HAIGH_PETALBURG_WOODS, PetalburgWoods_Text_NoOneCrossesTeamAqua, PetalburgWoods_Text_YoureKiddingMe
	msgbox PetalburgWoods_Text_YoureKiddingMe, MSGBOX_DEFAULT
	release
end

EventScript_BugRoomA_TrainerBattle2::
	lock
	trainerbattle_single TRAINER_GRUNT_RUSTURF_TUNNEL, BugA_Text_BossIntro, RusturfTunnel_Text_GruntDefeat, TrainerBattle2SetVar
	msgbox RusturfTunnel_Text_GruntDefeat, MSGBOX_DEFAULT
	release
end

EventScript_BugRoomA_CantAdvance::
	lock
	applymovement LOCALID_BUGBOSS1, Common_Movement_FacePlayer
	applymovement LOCALID_BUGBOSS1, Common_Movement_ExclamationMark
	waitmovement LOCALID_BUGBOSS1
	trainerbattle_single TRAINER_GRUNT_RUSTURF_TUNNEL, BugA_Text_BossIntro, RusturfTunnel_Text_GruntDefeat, TrainerBattle2SetVar
	release
end

TrainerBattle2SetVar:
	lock
	setvar VAR_LITTLEROOT_TOWN_STATE, 6
	msgbox RusturfTunnel_Text_GruntDefeat, MSGBOX_DEFAULT
	release
end


BugA_Text_BossIntro:
	.string "You can't go any further \nuntil you beat me.$"
