GraniteCave_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_B2F_OnTransition
	.byte 0

GraniteCave_B2F_OnTransition::
	gettimeofday
	call_if_eq VAR_0x8000, 3, GraniteCave_B2F_RemoveJaw
	call_if_ne VAR_0x8000, 3, GraniteCave_B2F_RemoveSail
	end

GraniteCave_B2F_RemoveJaw::
	setobjectxyperm LOCALID_GRANITE_CAVE_JAW_FOSSIL, 0, 0
	return

GraniteCave_B2F_RemoveSail::
	setobjectxyperm LOCALID_GRANITE_CAVE_SAIL_FOSSIL, 0, 0
	return


