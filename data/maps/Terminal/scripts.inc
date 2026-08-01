Terminal_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Terminal_OnTransition
	.byte 0

Terminal_OnTransition:
	setflag FLAG_VISITED_DREAM_WORLD
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setescapewarp MAP_TERMINAL, WARP_ID_DW_ENTRANCE
	goto_if_ge VAR_DREAM_WORLD_STATE, 5, Terminal_SetFantasyWarp
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Terminal_SetBrendanWarp
	setdynamicwarp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 7, 4
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F_2
	call_if_eq VAR_DREAM_WORLD_STATE, 3, Terminal_EventScript_CheckProgress
	end

Terminal_SetBrendanWarp::
	setdynamicwarp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 1, 4
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_2
	call_if_eq VAR_DREAM_WORLD_STATE, 3, Terminal_EventScript_CheckProgress
	end

Terminal_EventScript_CheckProgress::
	goto_if_unset FLAG_SYS_GAME_CLEAR, Common_EventScript_NopReturn
	goto_if_unset FLAG_DEFEATED_CRESSELIA, Common_EventScript_NopReturn
	goto_if_unset FLAG_DEFEATED_DARKRAI, Common_EventScript_NopReturn
	setdynamicwarp MAP_TERMINAL_INTERIOR, 0
	return

Terminal_SetFantasyWarp::
	setdynamicwarp MAP_TERMINAL_INTERIOR, 0
	end
