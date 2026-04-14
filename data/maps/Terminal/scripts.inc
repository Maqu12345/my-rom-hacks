Terminal_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Terminal_OnTransition
	.byte 0

Terminal_OnTransition:
	setflag FLAG_VISITED_DREAM_WORLD
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setescapewarp MAP_TERMINAL, WARP_ID_DW_ENTRANCE
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Terminal_SetBrendanWarp
	setdynamicwarp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 7, 4
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F_2
	end

Terminal_SetBrendanWarp::
	setdynamicwarp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 1, 4
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_2
	end
