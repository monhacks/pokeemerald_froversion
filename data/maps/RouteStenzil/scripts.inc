.set LOCALID_MINT_BALL, 1

RouteStenzil_MapScripts::
	.byte 0


ItemScript_SummitCave_GiveItemDependingOnStarter::
	lock
	switch VAR_STARTER_MON
	case 1, SummitCave_EventScript_GiveItemTreecko //fros starter is rascaloot
	case 2, SummitCave_EventScript_GiveItemMudkip //fros starter is rascaloot
	case 3, SummitCave_EventScript_GiveItemTorchic //fros starter is emboryps
	release
	end

SummitCave_EventScript_GiveItemTreecko:
	finditem ITEM_RELAXED_MINT
	removeobject LOCALID_MINT_BALL
	setflag FLAG_ITEM_SUMMIT_CAVE_MINT 
	release
	end

SummitCave_EventScript_GiveItemMudkip:
	finditem ITEM_ADAMANT_MINT
	removeobject LOCALID_MINT_BALL
	setflag FLAG_ITEM_SUMMIT_CAVE_MINT 
	release
	end

SummitCave_EventScript_GiveItemTorchic:
	finditem ITEM_MODEST_MINT
	removeobject LOCALID_MINT_BALL
	setflag FLAG_ITEM_SUMMIT_CAVE_MINT 
	release
	end

