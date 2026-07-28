NewmoonNightmare_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewmoonNightmare_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, NewmoonNightmare_OnTransition
	.byte 0

NewmoonNightmare_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewmoonNightmare_EventScript_TryRemoveDarkrai
	end

NewmoonNightmare_OnTransition:
	call_if_eq VAR_DREAM_WORLD_STATE, 0, NewmoonNightmare_EventScript_ShowIslands
	end

NewmoonNightmare_EventScript_TryRemoveDarkrai::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

NewmoonNightmare_EventScript_ShowIslands::
	setvar VAR_DREAM_WORLD_STATE, 2
	clearflag FLAG_ITEM_ROUTE_N5_SHARP_BEAK
	clearflag FLAG_ITEM_ROUTE_N5_SPELL_TAG
	setflag FLAG_DEFEATED_DARKRAI
	setflag FLAG_HIDE_FAKE_MAY
	return

NewmoonNightmare_EventScript_Darkrai::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
	delay 50
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_DARKRAI
	goto_if_set FLAG_SYS_GAME_CLEAR, NewmoonNightmare_EventScript_SetHighLevel
	setwildbattle SPECIES_DARKRAI, 50
NewmoonNightmare_EventScript_DarkraiCont:
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewmoonNightmare_EventScript_DefeatedDarkrai
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewmoonNightmare_EventScript_DefeatedDarkrai
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewmoonNightmare_EventScript_DefeatedDarkrai
	setflag FLAG_DEFEATED_DARKRAI
	removeobject LOCALID_DARKRAI
	release
	end

NewmoonNightmare_EventScript_DefeatedDarkrai::
	setflag FLAG_DEFEATED_DARKRAI
	setvar VAR_0x8004, SPECIES_DARKRAI
	goto Common_EventScript_LegendaryFlewAway
	end

NewmoonNightmare_EventScript_SetHighLevel::
	setwildbattle SPECIES_DARKRAI, 70
	goto NewmoonNightmare_EventScript_DarkraiCont
	end

NewmoonNightmare_Eventscript_FakeRivalWalkRight::
	setvar VAR_TEMP_1, 1
	goto FullmoonDaydream_Eventscript_FakeRival
	end

NewmoonNightmare_Eventscript_FakeRivalWalkLeft::
	setvar VAR_TEMP_1, 2
	goto FullmoonDaydream_Eventscript_FakeRival
	end
