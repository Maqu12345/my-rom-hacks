RouteN5_Islands_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RouteN5_OnTransition
	.byte 0

RouteN5_OnTransition:
	goto_if_eq VAR_DREAM_WORLD_STATE, 0, RouteN5_EventScript_HideIslands
	setmaplayoutindex LAYOUT_ROUTE_N5_ISLANDS
	end

@	VAR_DREAM_WORLD_STATE
@	0	; Haven't visited the islands yet.
@	1-2	; Visited the islands, but haven't met ????? yet.
@	3	; Saw ????? on the islands.
@	4	; Started Postgame, stuck in house
@	5	; Free access to land of fantasy
@	6	; Beat ????? first time
@	7	; Beat ????? second time (superboss)

RouteN5_EventScript_HideIslands::
	setmaplayoutindex LAYOUT_ROUTE_N5_MYSTERY_ZONE_CONNECTION_LAYOUT
	setflag FLAG_ITEM_ROUTE_N5_SHARP_BEAK
	setflag FLAG_ITEM_ROUTE_N5_SPELL_TAG
	end

RouteN5_EventScript_ShowIslands::
	setvar VAR_DREAM_WORLD_STATE, 1
	clearflag FLAG_ITEM_ROUTE_N5_SHARP_BEAK
	clearflag FLAG_ITEM_ROUTE_N5_SPELL_TAG
	return
