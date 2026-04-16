ForestWarriorSecret_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ForestWarriorSecret_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ForestWarriorSecret_OnResume
	.byte 0

ForestWarriorSecret_OnTransition:
	call ForestWarriorSecret_EventScript_ShowKleavor
	end

ForestWarriorSecret_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ForestWarriorSecret_EventScript_TryRemoveKleavor
	end

ForestWarriorSecret_EventScript_ShowKleavor::
	setflag FLAG_HIDE_KLEAVOR
	goto_if_set FLAG_DAILY_KLEAVOR, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_KLEAVOR
	return

ForestWarriorSecret_EventScript_TryRemoveKleavor::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

ForestWarriorSecret_EventScript_Kleavor::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KLEAVOR, CRY_MODE_ENCOUNTER
	delay 60
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_KLEAVOR
	random 20
	call_if_ne VAR_RESULT, 0, ForestWarriorSecret_EventScript_SetKleavorNoItem
	call_if_eq VAR_RESULT, 0, ForestWarriorSecret_EventScript_SetKleavorItem
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ForestWarriorSecret_EventScript_DefeatedKleavor
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ForestWarriorSecret_EventScript_DefeatedKleavor
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ForestWarriorSecret_EventScript_DefeatedKleavor
	setflag FLAG_DAILY_KLEAVOR
	setflag FLAG_HIDE_KLEAVOR
	removeobject LOCALID_KLEAVOR
	release
	end

ForestWarriorSecret_EventScript_DefeatedKleavor::
	setflag FLAG_DAILY_KLEAVOR
	setflag FLAG_HIDE_KLEAVOR
	goto Common_EventScript_RemoveStaticPokemon
	end

ForestWarriorSecret_EventScript_SetKleavorNoItem::
	setwildbattle SPECIES_KLEAVOR, 35
	return

ForestWarriorSecret_EventScript_SetKleavorItem::
	setwildbattle SPECIES_KLEAVOR, 35, item=ITEM_BLACK_AUGURITE
	return
