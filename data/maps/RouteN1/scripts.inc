RouteN1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RouteN1_OnTransition
	.byte 0

RouteN1_OnTransition:
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	end
