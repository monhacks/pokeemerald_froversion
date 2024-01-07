MAGM8CaveHiddenBehindWaterfall_MapScripts::
	.byte 0


MAGM8CaveHiddenBehindWaterfall_EventScripts_BarrelCheck::
	lock
	msgbox MAGM8CaveHiddenBehindWaterfall_Text_BarrelEmpty, MSGBOX_AUTOCLOSE
	release
	end

MAGM8CaveHiddenBehindWaterfall_Text_BarrelEmpty:
	.string "The barrel is empty...$"
