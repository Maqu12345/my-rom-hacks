Terminal_Interior_2F_MapScripts::
	.byte 0

Terminal_Interior_2F_EventScript_Terminal_BrendanPC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto Terminal_Interior_2F_EventScript_PCMainMenu
	end

Terminal_Interior_2F_EventScript_PCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto Terminal_Interior_2F_EventScript_AccessPC
	end

Terminal_Interior_2F_EventScript_AccessPC::
	switch VAR_RESULT
	case 0, Terminal_Interior_2F_EventScript_AccessPokemonStorage
	case 1, Terminal_Interior_2F_EventScript_AccessPlayersPC
	case 2, Terminal_Interior_2F_EventScript_AccessHallOfFame
	case 3, Terminal_Interior_2F_EventScript_TurnOffPC
	case MULTI_B_PRESSED, Terminal_Interior_2F_EventScript_TurnOffPC
	end

Terminal_Interior_2F_EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto Terminal_Interior_2F_EventScript_PCMainMenu
	end

Terminal_Interior_2F_EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto Terminal_Interior_2F_EventScript_PCMainMenu
	end

Terminal_Interior_2F_EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, Terminal_Interior_2F_EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto Terminal_Interior_2F_EventScript_AccessPC
	end

Terminal_Interior_2F_EventScript_TurnOffPC::
	getplayerxy VAR_0x8005, VAR_0x8006
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	call_if_le VAR_0x8005, 4, Terminal_Interior_2F_EventScript_SetBrendanOff
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

Terminal_Interior_2F_EventScript_SetBrendanOff::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	return

Terminal_Interior_2F_EventScript_MayPC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto Terminal_Interior_2F_EventScript_PCMainMenu
	end

Terminal_Interior_2F_EventScript_BrendanDiary::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Terminal_Interior_2F_EventScript_EmptyDiary
	goto Terminal_Interior_2F_EventScript_UnreadableDiary
	end

Terminal_Interior_2F_EventScript_MayDiary::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, Terminal_Interior_2F_EventScript_EmptyDiary
	goto Terminal_Interior_2F_EventScript_UnreadableDiary
	end

Terminal_Interior_2F_EventScript_EmptyDiary::
	msgbox Terminal_Interior_2F_Text_EmptyDiary, MSGBOX_SIGN
	end

Terminal_Interior_2F_EventScript_UnreadableDiary::
	msgbox Terminal_Interior_2F_Text_UnreadableDiary, MSGBOX_SIGN
	end

Terminal_Interior_2F_EventScript_BrendansBed::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, Terminal_Interior_2F_EventScript_GoToFantasyLand
	goto_if_eq VAR_DREAM_WORLD_STATE, 4, Terminal_Interior_2F_EventScript_NothingHappened
	msgbox Terminal_Interior_2F_Text_GoHome, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Terminal_Interior_2F_EventScript_End
	closemessage
	fadenewbgm MUS_NONE
	hidefollower
	fadescreenspeed FADE_TO_BLACK, 10
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 1, 4
	waitstate
Terminal_Interior_2F_EventScript_End::
	releaseall
	end

Terminal_Interior_2F_EventScript_MaysBed::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Terminal_Interior_2F_EventScript_GoToFantasyLand
	goto_if_eq VAR_DREAM_WORLD_STATE, 4, Terminal_Interior_2F_EventScript_NothingHappened
	msgbox Terminal_Interior_2F_Text_GoHome, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Terminal_Interior_2F_EventScript_End
	closemessage
	fadenewbgm MUS_NONE
	hidefollower
	fadescreenspeed FADE_TO_BLACK, 10
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 7, 4
	waitstate
	releaseall
	end

Terminal_Interior_2F_EventScript_GoToFantasyLand::
	goto_if_eq VAR_DREAM_WORLD_STATE, 4, Terminal_Interior_2F_EventScript_SkipToFantasyLand
	msgbox Terminal_Interior_2F_Text_GoDeeper, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Terminal_Interior_2F_EventScript_End
	closemessage
	fadenewbgm MUS_NONE
	hidefollower
	fadescreenspeed FADE_TO_BLACK, 10
	warpsilent MAP_FANTASY_LAND_MAIN, 0
	waitstate
	releaseall
	end

Terminal_Interior_2F_EventScript_SkipToFantasyLand::
	fadenewbgm MUS_NONE
	hidefollower
	fadescreenspeed FADE_TO_BLACK, 10
	warpsilent MAP_TERMINAL_FANTASY_LAND, 0
	waitstate
	releaseall
	end

Terminal_Interior_2F_EventScript_NothingHappened::
	hidefollower
	fadeoutbgm 0
	fadescreenspeed FADE_TO_BLACK, 10
	delay 60
	fadeinbgm 0
	fadescreenspeed FADE_FROM_BLACK, 10
	delay 30
	msgbox Terminal_Interior_2F_Text_Nothing, MSGBOX_AUTOCLOSE
	releaseall
	end

Terminal_Interior_2F_Text_EmptyDiary:
	.string "It appears to be a diary…\p"
	.string "But all the pages are empty.$"

Terminal_Interior_2F_Text_UnreadableDiary:
	.string "It appears to be a diary…\p"
	.string "But you don't recognize the language.$"

Terminal_Interior_2F_Text_GoHome:
	.string "Do you want to wake up?$"

Terminal_Interior_2F_Text_GoDeeper:
	.string "Do you want to go deeper?$"

Terminal_Interior_2F_Text_Nothing:
	.string "Nothing happened…$"
