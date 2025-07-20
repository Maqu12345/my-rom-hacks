AbandonedShip_Rooms_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_OnResume
	.byte 0

AbandonedShip_Rooms_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER2, 17, 4
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AbandonedShip_Rooms_B1F_EventScript_TryRemoveSpiritomb
	end

AbandonedShip_Rooms_B1F_EventScript_TryRemoveSpiritomb::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AbandonedShip_Rooms_B1F_EventScript_FatMan::
	msgbox AbandonedShip_Rooms_B1F_Text_GettingQueasy, MSGBOX_NPC
	end

AbandonedShip_Rooms_B1F_EventScript_Spiritomb::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPIRITOMB, CRY_MODE_ENCOUNTER
	delay 60
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ABANDONED_SHIP_SPIRITOMB
	setwildbattle SPECIES_SPIRITOMB, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AbandonedShip_Rooms_B1F_EventScript_DefeatedSpiritomb
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AbandonedShip_Rooms_B1F_EventScript_DefeatedSpiritomb
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AbandonedShip_Rooms_B1F_EventScript_DefeatedSpiritomb
	setflag FLAG_DAILY_SPIRITOMB
	removeobject LOCALID_ABANDONED_SHIP_SPIRITOMB
	release
	end

AbandonedShip_Rooms_B1F_EventScript_DefeatedSpiritomb::
	setflag FLAG_DAILY_SPIRITOMB
	goto Common_EventScript_RemoveStaticPokemon
	end

AbandonedShip_Rooms_B1F_Text_GettingQueasy:
	.string "Urrrrppp…\p"
	.string "I'm getting queasy just being aboard\n"
	.string "this ship…\p"
	.string "It's not even moving, but…$"

