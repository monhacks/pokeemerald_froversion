.set LOCALID_NORMALBOSS1, 31

Bug4_MapScripts::
	.byte 0


EventScript_BugRoom4_TrainerBattle2::
	lock
	trainerbattle_single TRAINER_AISHA, Bug4_Text_BossIntro, RusturfTunnel_Text_GruntDefeat, NormalBossSetVar
	msgbox RusturfTunnel_Text_GruntDefeat, MSGBOX_DEFAULT
	release
end

EventScript_BugRoom4_CantAdvance::
	lock
	applymovement LOCALID_NORMALBOSS1, Common_Movement_FacePlayer
	applymovement LOCALID_NORMALBOSS1, Common_Movement_ExclamationMark
	waitmovement LOCALID_NORMALBOSS1
	trainerbattle_single TRAINER_MELINA, Bug4_Text_BossIntro, RusturfTunnel_Text_GruntDefeat, NormalBossSetVar
	release
end

NormalBossSetVar::
	lock
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	msgbox RusturfTunnel_Text_GruntDefeat, MSGBOX_DEFAULT
	release
end


Bug4_Text_BossIntro:
	.string "You can't go any further \nuntil you beat me.$"