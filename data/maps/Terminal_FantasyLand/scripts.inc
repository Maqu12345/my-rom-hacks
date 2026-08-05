Terminal_FantasyLand_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Terminal_FantasyLand_OnLoad
	.byte 0

Terminal_FantasyLand_OnLoad:
	checkplayergender
	call_if_eq VAR_RESULT, FEMALE, Terminal_FantasyLand_EventScript_ChangeBed
	end

Terminal_FantasyLand_EventScript_ChangeBed::
	setmetatile 3, 4, METATILE_BrendansMaysHouse_BrendansBed_TopLeft, FALSE
	setmetatile 3, 5, METATILE_BrendansMaysHouse_BrendansBed_BottomLeft, FALSE
	setmetatile 4, 4, METATILE_BrendansMaysHouse_BrendansBed_TopCenter, FALSE
	setmetatile 4, 5, METATILE_BrendansMaysHouse_BrendansBed_BottomCenter, FALSE
	setmetatile 5, 4, METATILE_BrendansMaysHouse_BrendansBed_TopRight, FALSE
	setmetatile 5, 5, METATILE_BrendansMaysHouse_BrendansBed_BottomRight, FALSE
	return
