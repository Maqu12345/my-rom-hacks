AchromaHollow_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AchromaHollow_OnResume
	.byte 0

AchromaHollow_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AchromaHollow_EventScript_TryRemoveKyurem
	end

AchromaHollow_EventScript_TryRemoveKyurem::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AchromaHollow_EventScript_Kyurem::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
	delay 50
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_KYUREM
	setwildbattle SPECIES_KYUREM, 72
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AchromaHollow_EventScript_DefeatedKyurem
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AchromaHollow_EventScript_DefeatedKyurem
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AchromaHollow_EventScript_DefeatedKyurem
	setflag FLAG_DEFEATED_KYUREM
	removeobject LOCALID_KYUREM
	release
	end

AchromaHollow_EventScript_DefeatedKyurem::
	setflag FLAG_DEFEATED_KYUREM
	setvar VAR_0x8004, SPECIES_KYUREM
	goto Common_EventScript_LegendaryFlewAway
	end

AchromaHollow_Eventscript_GardenSecret::
	msgbox AchromaHollow_Text_GardenSecret, MSGBOX_SIGN
	end

AchromaHollow_Text_GardenSecret:
	.string "GARDEN SECRET\n"
	.string "{RIGHT_ARROW}{LEFT_ARROW}{LEFT_ARROW}{UP_ARROW}{RIGHT_ARROW}{DOWN_ARROW}{LEFT_ARROW}{UP_ARROW}$" @ RLLURDLU
