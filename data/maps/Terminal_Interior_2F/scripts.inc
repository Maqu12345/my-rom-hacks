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
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_AccessHallOfFame
	case 3, EventScript_TurnOffPC
	case MULTI_B_PRESSED, Terminal_Interior_2F_EventScript_TurnOffPC
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

Terminal_Interior_2F_Text_EmptyDiary:
	.string "It appears to be a diary…\p"
	.string "But all the pages are empty.$"

Terminal_Interior_2F_Text_UnreadableDiary:
	.string "It appears to be a diary…\p"
	.string "But you don't recognize the language.$"
