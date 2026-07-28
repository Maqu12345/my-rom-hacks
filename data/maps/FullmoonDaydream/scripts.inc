FullmoonDaydream_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FullmoonDaydream_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FullmoonDaydream_OnTransition
	.byte 0

FullmoonDaydream_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FullmoonDaydream_EventScript_TryRemoveCresselia
	end

FullmoonDaydream_OnTransition:
	call_if_eq VAR_DREAM_WORLD_STATE, 0, FullmoonDaydream_EventScript_ShowIslands
	end

FullmoonDaydream_EventScript_TryRemoveCresselia::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

FullmoonDaydream_EventScript_ShowIslands::
	setvar VAR_DREAM_WORLD_STATE, 1
	clearflag FLAG_ITEM_ROUTE_N5_SHARP_BEAK
	clearflag FLAG_ITEM_ROUTE_N5_SPELL_TAG
	setflag FLAG_DEFEATED_CRESSELIA
	setflag FLAG_HIDE_FAKE_BRENDAN
	return

FullmoonDaydream_EventScript_Cresselia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
	delay 50
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_CRESSELIA
	goto_if_set FLAG_SYS_GAME_CLEAR, FullmoonDaydream_EventScript_SetHighLevel
	setwildbattle SPECIES_CRESSELIA, 50
FullmoonDaydream_EventScript_CresseliaCont:
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FullmoonDaydream_EventScript_DefeatedCresselia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FullmoonDaydream_EventScript_DefeatedCresselia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FullmoonDaydream_EventScript_DefeatedCresselia
	setflag FLAG_DEFEATED_CRESSELIA
	removeobject LOCALID_CRESSELIA
	release
	end

FullmoonDaydream_EventScript_DefeatedCresselia::
	setflag FLAG_DEFEATED_CRESSELIA
	setvar VAR_0x8004, SPECIES_CRESSELIA
	goto Common_EventScript_LegendaryFlewAway
	end

FullmoonDaydream_EventScript_SetHighLevel::
	setwildbattle SPECIES_CRESSELIA, 70
	goto FullmoonDaydream_EventScript_CresseliaCont
	end

FullmoonDaydream_Eventscript_FakeRival::
	lock
	delay 10
	playse SE_M_FLY
	applymovement LOCALID_FAKE_RIVAL, FullmoonDaydream_Movement_Jump
	delay 15
	removeobject LOCALID_FAKE_RIVAL
	delay 5
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN
	waitmovement 0
	delay 60
	call_if_eq VAR_TEMP_1, 1, FullmoonDaydream_Eventscript_WalkRight
	call_if_eq VAR_TEMP_1, 2, FullmoonDaydream_Eventscript_WalkLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	setvar VAR_DREAM_WORLD_STATE, 3
	applymovement LOCALID_PLAYER, FullmoonDaydream_Movement_LookAround
	waitmovement 0
	end

FullmoonDaydream_Eventscript_WalkRight::
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	return

FullmoonDaydream_Eventscript_WalkLeft::
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	return

FullmoonDaydream_Movement_Jump:
	jump_in_place_left
	step_end

FullmoonDaydream_Movement_LookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	face_down
	step_end
