FantasyLand_Main_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RouteN1_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, FantasyLand_Main_OnLoad
	.byte 0

FantasyLand_Main_OnLoad:
	goto_if_lt VAR_DREAM_WORLD_STATE, 6, FantasyLand_Main_EventScript_ClosePortals
	end

FantasyLand_Main_EventScript_ClosePortals::
	setmetatile 18,  6, METATILE_General_LightGrass_Center, FALSE
	setmetatile 20,  6, METATILE_General_LightGrass_Center, FALSE
	setmetatile  5,  5, METATILE_General_LightGrass_Center, FALSE
	setmetatile 11, 12, METATILE_General_LightGrass_Center, FALSE
	setmetatile 20, 22, METATILE_General_LightGrass_Center, FALSE
	setmetatile 35, 16, METATILE_General_LightGrass_Center, FALSE
	end
