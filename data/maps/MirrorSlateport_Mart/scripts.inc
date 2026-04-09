MirrorSlateport_Mart_MapScripts::
	.byte 0

MirrorSlateport_Mart_EventScript_Clerk::
	lock
	faceplayer
	message MirrorSlateport_Mart_Text_HowMayIServeYou
	waitmessage
	pokemart MirrorSlateport_Mart_Pokemart
	msgbox MirrorSlateport_Mart_Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MirrorSlateport_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_DREAM_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	pokemartlistend

MirrorSlateport_Mart_Text_HowMayIServeYou:
	.string "!emocleW\p"
	.string "?uoy evres I yam woH$"

MirrorSlateport_Mart_Text_PleaseComeAgain:
	.string "!niaga emoc esaelP$"
