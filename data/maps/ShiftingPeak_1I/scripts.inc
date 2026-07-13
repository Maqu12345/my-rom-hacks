ShiftingPeak_1I_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShiftingPeak_1I_OnLoad
	.byte 0

ShiftingPeak_1I_OnLoad:
	call_if_set FLAG_ACHROMA_HOLLOW_OPEN, ShiftingPeak_1I_EventScript_OpenDoor
	end

ShiftingPeak_1I_EventScript_OpenDoor::
	setmetatile 16, 10, METATILE_Cave_IceDoor_Top, TRUE
	setmetatile 16, 11, METATILE_Cave_IceDoor_Bottom, FALSE
	return

ShiftingPeak_1I_EventScript_IceRock::
	msgbox ShiftingPeak_1I_Text_NotBreakable, MSGBOX_SIGN
	end

ShiftingPeak_1I_EventScript_ColdAir::
	msgbox ShiftingPeak_1I_Text_DeepChill, MSGBOX_SIGN
	end

ShiftingPeak_1I_Text_NotBreakable:
	.string "This rock appears to be breakable…\p"
	.string "But a layer of ice protects it.$"

ShiftingPeak_1I_Text_DeepChill:
	.string "You feel cold air emanating\n"
	.string "from a crack in the wall.\p"
	.string "…\p"
	.string "You felt a sudden chill deep within.$"
