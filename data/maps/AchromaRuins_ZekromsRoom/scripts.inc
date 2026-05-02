AchromaRuins_ZekromsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AchromaRuins_ZekromsRoom_OnResume
	.byte 0

AchromaRuins_ZekromsRoom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AchromaRuins_ZekromsRoom_EventScript_TryRemoveZekrom
	end

AchromaRuins_ZekromsRoom_EventScript_TryRemoveZekrom::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AchromaRuins_ZekromsRoom_EventScript_Zekrom::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZEKROM, CRY_MODE_ENCOUNTER
	delay 50
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ZEKROM
	setwildbattle SPECIES_ZEKROM, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AchromaRuins_ZekromsRoom_EventScript_DefeatedZekrom
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AchromaRuins_ZekromsRoom_EventScript_DefeatedZekrom
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AchromaRuins_ZekromsRoom_EventScript_DefeatedZekrom
	setflag FLAG_DEFEATED_ZEKROM
	removeobject LOCALID_ZEKROM
	release
	end

AchromaRuins_ZekromsRoom_EventScript_DefeatedZekrom::
	setflag FLAG_DEFEATED_ZEKROM
	setvar VAR_0x8004, SPECIES_ZEKROM
	goto Common_EventScript_LegendaryFlewAway
	end

AchromaRuins_ZekromsRoom_EventScript_ZekromRoar::
	goto_if_set FLAG_DEFEATED_ZEKROM, AchromaRuins_ZekromsRoom_EventScript_End
	goto_if_set FLAG_DAILY_ZEKROM_ROAR, AchromaRuins_ZekromsRoom_EventScript_End
	lock
	playmoncry SPECIES_ZEKROM, CRY_MODE_NORMAL
	msgbox AchromaRuins_ZekromsRoom_Text_ZekromRoar, MSGBOX_AUTOCLOSE
	waitmoncry
	setflag FLAG_DAILY_ZEKROM_ROAR
	release
	end

AchromaRuins_ZekromsRoom_EventScript_End::
	end

AchromaRuins_ZekromsRoom_Text_ZekromRoar:
	.string "Bazzazzazzash!$"
