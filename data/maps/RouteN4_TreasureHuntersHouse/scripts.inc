RouteN4_TreasureHuntersHouse_MapScripts::
	.byte 0

RouteN4_TreasureHuntersHouse_EventScript_TreasureHunter::
	lock
	faceplayer
	goto_if_set FLAG_MET_DREAM_TREASURE_HUNTER, RouteN4_TreasureHuntersHouse_EventScript_SkipGreeting
	msgbox RouteN4_TreasureHuntersHouse_Text_Greeting, MSGBOX_DEFAULT
	setflag FLAG_MET_DREAM_TREASURE_HUNTER
	goto RouteN4_TreasureHuntersHouse_EventScript_CheckPlayerHasShard
	end

RouteN4_TreasureHuntersHouse_EventScript_SkipGreeting::
	msgbox RouteN4_TreasureHuntersHouse_Text_HaveYouSeenAnyShards, MSGBOX_DEFAULT
	goto RouteN4_TreasureHuntersHouse_EventScript_CheckPlayerHasShard
	end

RouteN4_TreasureHuntersHouse_EventScript_CheckPlayerHasShard::
	call RouteN4_TreasureHuntersHouse_EventScript_GetPlayersShards
	goto_if_eq VAR_TEMP_1, 0, RouteN4_TreasureHuntersHouse_EventScript_NoShards
	goto RouteN4_TreasureHuntersHouse_EventScript_HasShard
	end

RouteN4_TreasureHuntersHouse_EventScript_GetPlayersShards::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_RED_SHARD
	call_if_eq VAR_RESULT, TRUE, RouteN4_TreasureHuntersHouse_EventScript_HasRedShard
	checkitem ITEM_YELLOW_SHARD
	call_if_eq VAR_RESULT, TRUE, RouteN4_TreasureHuntersHouse_EventScript_HasYellowShard
	checkitem ITEM_BLUE_SHARD
	call_if_eq VAR_RESULT, TRUE, RouteN4_TreasureHuntersHouse_EventScript_HasBlueShard
	checkitem ITEM_GREEN_SHARD
	call_if_eq VAR_RESULT, TRUE, RouteN4_TreasureHuntersHouse_EventScript_HasGreenShard
	return

RouteN4_TreasureHuntersHouse_EventScript_HasRedShard::
	addvar VAR_TEMP_1, 1
	return

RouteN4_TreasureHuntersHouse_EventScript_HasYellowShard::
	addvar VAR_TEMP_1, 2
	return

RouteN4_TreasureHuntersHouse_EventScript_HasBlueShard::
	addvar VAR_TEMP_1, 4
	return

RouteN4_TreasureHuntersHouse_EventScript_HasGreenShard::
	addvar VAR_TEMP_1, 8
	return

RouteN4_TreasureHuntersHouse_EventScript_HasShard::
	msgbox RouteN4_TreasureHuntersHouse_Text_ThatsAShardIllTradeYou, MSGBOX_DEFAULT
	goto RouteN4_TreasureHuntersHouse_EventScript_ShowTradeOptions
	end

RouteN4_TreasureHuntersHouse_EventScript_ShowTradeOptions::
	message RouteN4_TreasureHuntersHouse_Text_WhatDoYouWantToTrade
	waitmessage
	switch VAR_TEMP_1
	case 1,  RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsR
	case 2,  RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsY
	case 3,  RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRY
	case 4,  RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsB
	case 5,  RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRB
	case 6,  RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsYB
	case 7,  RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRYB
	case 8,  RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsG
	case 9,  RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRG
	case 10, RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsYG
	case 11, RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRYG
	case 12, RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsBG
	case 13, RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRBG
	case 14, RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsYBG
	case 15, RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRYBG
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsR::
	multichoice 0, 0, MULTI_SHARDS_R, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeRedShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsY::
	multichoice 0, 0, MULTI_SHARDS_Y, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRY::
	multichoice 0, 0, MULTI_SHARDS_RY, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeRedShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsB::
	multichoice 0, 0, MULTI_SHARDS_B, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeBlueShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRB::
	multichoice 0, 0, MULTI_SHARDS_RB, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeRedShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsYB::
	multichoice 0, 0, MULTI_SHARDS_YB, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRYB::
	multichoice 0, 0, MULTI_SHARDS_RYB, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeRedShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_TradeBlueShard
	case 3, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsG::
	multichoice 0, 0, MULTI_SHARDS_G, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeGreenShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRG::
	multichoice 0, 0, MULTI_SHARDS_RG, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeRedShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeGreenShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsYG::
	multichoice 0, 0, MULTI_SHARDS_YG, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeGreenShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRYG::
	multichoice 0, 0, MULTI_SHARDS_RYG, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeRedShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_TradeGreenShard
	case 3, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsBG::
	multichoice 0, 0, MULTI_SHARDS_BG, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeBlueShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeGreenShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRBG::
	multichoice 0, 0, MULTI_SHARDS_RBG, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeRedShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_TradeGreenShard
	case 3, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsYBG::
	multichoice 0, 0, MULTI_SHARDS_YBG, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeYellowShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeBlueShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_TradeGreenShard
	case 3, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardOptionsRYBG::
	multichoice 0, 0, MULTI_SHARDS_RYBG, FALSE
	switch VAR_RESULT
	case 0, RouteN4_TreasureHuntersHouse_EventScript_TradeRedShard
	case 1, RouteN4_TreasureHuntersHouse_EventScript_TradeYellowShard
	case 2, RouteN4_TreasureHuntersHouse_EventScript_TradeBlueShard
	case 3, RouteN4_TreasureHuntersHouse_EventScript_TradeGreenShard
	case 4, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_TradeRedShard::
	setvar VAR_0x8008, ITEM_RED_SHARD
	setvar VAR_0x8009, ITEM_DAWN_STONE
	goto RouteN4_TreasureHuntersHouse_EventScript_TryTradeShard

RouteN4_TreasureHuntersHouse_EventScript_TradeYellowShard::
	setvar VAR_0x8008, ITEM_YELLOW_SHARD
	setvar VAR_0x8009, ITEM_ICE_STONE
	goto RouteN4_TreasureHuntersHouse_EventScript_TryTradeShard

RouteN4_TreasureHuntersHouse_EventScript_TradeBlueShard::
	setvar VAR_0x8008, ITEM_BLUE_SHARD
	setvar VAR_0x8009, ITEM_SHINY_STONE
	goto RouteN4_TreasureHuntersHouse_EventScript_TryTradeShard

RouteN4_TreasureHuntersHouse_EventScript_TradeGreenShard::
	setvar VAR_0x8008, ITEM_GREEN_SHARD
	setvar VAR_0x8009, ITEM_DUSK_STONE
	goto RouteN4_TreasureHuntersHouse_EventScript_TryTradeShard

RouteN4_TreasureHuntersHouse_EventScript_TryTradeShard::
	bufferitemname STR_VAR_1, VAR_0x8008
	bufferitemname STR_VAR_2, VAR_0x8009
	msgbox RouteN4_TreasureHuntersHouse_Text_YoullTradeShardForStone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, TRUE, RouteN4_TreasureHuntersHouse_EventScript_TradeShard
	checkitem VAR_0x8008, 2
	goto_if_eq VAR_RESULT, FALSE, RouteN4_TreasureHuntersHouse_EventScript_TradeShard
	goto RouteN4_TreasureHuntersHouse_EventScript_BagFull
	end

RouteN4_TreasureHuntersHouse_EventScript_TradeShard::
	removeitem VAR_0x8008
	giveitem VAR_0x8009
	msgbox RouteN4_TreasureHuntersHouse_Text_ItsADeal, MSGBOX_DEFAULT
	call RouteN4_TreasureHuntersHouse_EventScript_GetPlayersShards
	goto_if_eq VAR_TEMP_1, 0, RouteN4_TreasureHuntersHouse_EventScript_EndTrade
	msgbox RouteN4_TreasureHuntersHouse_Text_TradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RouteN4_TreasureHuntersHouse_EventScript_ShowTradeOptions
	goto RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade
	end

RouteN4_TreasureHuntersHouse_EventScript_BagFull::
	msgbox RouteN4_TreasureHuntersHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

RouteN4_TreasureHuntersHouse_EventScript_DeclineTrade::
	msgbox RouteN4_TreasureHuntersHouse_Text_ComeBackIfYouChangeMind, MSGBOX_DEFAULT
	release
	end

RouteN4_TreasureHuntersHouse_EventScript_NoShards::
	msgbox RouteN4_TreasureHuntersHouse_Text_YouHaventGotAnyShards, MSGBOX_DEFAULT
	release
	end

RouteN4_TreasureHuntersHouse_EventScript_EndTrade::
	release
	end

RouteN4_TreasureHuntersHouse_EventScript_ShardTradeBoard::
	msgbox RouteN4_TreasureHuntersHouse_Text_ShardTradeBoard, MSGBOX_SIGN
	end

RouteN4_TreasureHuntersHouse_Text_Greeting:
	.string "I'm the DREAM TREASURE HUNTER!\p"
	.string "I'm the awesome gal who makes\n"
	.string "deep-sea dives to gather treasures\l"
	.string "resting at the bottom.$"

RouteN4_TreasureHuntersHouse_Text_HaveYouSeenAnyShards:
	.string "Tell me, have you seen any SHARDS of\n"
	.string "tools made in ancient times?$"

RouteN4_TreasureHuntersHouse_Text_YouHaventGotAnyShards:
	.string "You haven't got any treasures\n"
	.string "for me…\p"
	.string "If you see any SHARDS, like the RED\n"
	.string "SHARD, you've got to trade it with me!$"

RouteN4_TreasureHuntersHouse_Text_ThatsAShardIllTradeYou:
	.string "Oh, hey! That…\n"
	.string "That's a SHARD! I'm looking for those!\p"
	.string "Oh, man, you've got to trade that\n"
	.string "with me! I'll give you something good!$"

RouteN4_TreasureHuntersHouse_Text_WhatDoYouWantToTrade:
	.string "What do you want to trade?$"

RouteN4_TreasureHuntersHouse_Text_YoullTradeShardForStone:
	.string "You'll trade your {STR_VAR_1} for\n"
	.string "my {STR_VAR_2}, then?$"

RouteN4_TreasureHuntersHouse_Text_ItsADeal:
	.string "It's a done deal!\n"
	.string "Use that wisely!$"

RouteN4_TreasureHuntersHouse_Text_TradeSomethingElse:
	.string "Do you want to trade something else?$"

RouteN4_TreasureHuntersHouse_Text_BagFull:
	.string "Whoops, your BAG's full.\n"
	.string "Get rid of some items, friend!$"

RouteN4_TreasureHuntersHouse_Text_ComeBackIfYouChangeMind:
	.string "No? That's a downer.\n"
	.string "Well, if you change your mind, come back.$"

RouteN4_TreasureHuntersHouse_Text_ShardTradeBoard:
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x0f}RED SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}DAWN STONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x06}YELLOW SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7e}ICE STONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x0c}BLUE SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x79}SHINY STONE{CLEAR_TO 0xc8}\p"
	.string "{CLEAR_TO 0x0a}Wanted item{CLEAR_TO 0x7c}Trade item\n"
	.string "{CLEAR_TO 0x08}GREEN SHARD{CLEAR_TO 0x59}{LEFT_ARROW}{RIGHT_ARROW}{CLEAR_TO 0x7b}DUSK STONE$"

