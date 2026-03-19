MauvilleCity_Mart_MapScripts::
	.byte 0

MauvilleCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_DEF
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	pokemartlistend

MauvilleCity_Mart_EventScript_ExpertM::
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Man::
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_MAUVILLE_NPC_TRADE_COMPLETED, MauvilleCity_Mart_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_GRIMER
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox MauvilleCity_Mart_Text_WillYouTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_Mart_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_Mart_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, MauvilleCity_Mart_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox MauvilleCity_Mart_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_MAUVILLE_NPC_TRADE_COMPLETED
	release
	end

MauvilleCity_Mart_EventScript_DeclineTrade::
	msgbox MauvilleCity_Mart_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Mart_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox MauvilleCity_Mart_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Mart_EventScript_TradeCompleted::
	msgbox MauvilleCity_Mart_Text_MuchNicerPokemon, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Mart_Text_WillYouTrade:
	.string "Hey, kid…\p"
	.string "I had a bit of a misunderstanding with\n"
	.string "another collector, and have a rare,\l"
	.string "imported, green {STR_VAR_2} here.\p"
	.string "I'll trade it to you for a regular {STR_VAR_1}.\n"
	.string "What do you say?$"

MauvilleCity_Mart_Text_PleaseBeGoodToMyPokemon:
	.string "You're a great kid, kid.\n"
	.string "Don't end up like me.$"

MauvilleCity_Mart_Text_DoesntLookLikeMonToMe:
	.string "I know a {STR_VAR_1} when I see one,\n"
	.string "and that is not it.$"

MauvilleCity_Mart_Text_YouDontWantToThatsOkay:
	.string "The offer still stands.\n"
	.string "Come back any time.$"

MauvilleCity_Mart_Text_MuchNicerPokemon:
	.string "I know you'll do great things one day,\n"
	.string "kid.$"

MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats:
	.string "There are items that temporarily\n"
	.string "elevate the stats of POKéMON.\p"
	.string "The ones I know you use in battle\n"
	.string "are X SPEED and X DEFEND…\p"
	.string "I do believe that there are others\n"
	.string "like them.$"

MauvilleCity_Mart_Text_DecisionsDetermineBattle:
	.string "Use a certain move, or use an item\n"
	.string "instead…\p"
	.string "The TRAINER's decisions determine how\n"
	.string "battles turn out, I think.$"

