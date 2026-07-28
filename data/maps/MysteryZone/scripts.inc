MysteryZone_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MysteryZone_OnTransition
	.byte 0

MysteryZone_OnTransition:
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, MysteryZone_SetBrendanWarp
	setdynamicwarp MAP_NEWMOON_NIGHTMARE, 0
	end

MysteryZone_SetBrendanWarp::
	setdynamicwarp MAP_FULLMOON_DAYDREAM, 0
	end

