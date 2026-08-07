ShiftingPeak_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShiftingPeak_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShiftingPeak_1F_OnFrame
	.byte 0

ShiftingPeak_1F_OnLoad:
	goto_if_lt VAR_DREAM_WORLD_STATE, 6, ShiftingPeak_1F_EventScript_ClosePortals
	end

ShiftingPeak_1F_EventScript_ClosePortals::
	setmetatile 14, 53, METATILE_Cave_CaveFloor_Smooth, FALSE
	end

ShiftingPeak_1F_OnFrame:
	map_script_2 VAR_TEMP_4, 0, ShiftingPeak_1F_EventScript_ShowName
	.2byte 0

ShiftingPeak_1F_EventScript_ShowName::
	setvar VAR_TEMP_4, 1
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ne VAR_0x8005, 53, ShiftingPeak_1F_EventScript_End
	special ShowMapNamePopup
ShiftingPeak_1F_EventScript_End::
	end

ShiftingPeak_1F_Eventscript_Seal::
	lock
	msgbox ShiftingPeak_1F_Text_OnlyWorthy, MSGBOX_SIGN
	goto_if_set FLAG_ACHROMA_HOLLOW_OPEN, ShiftingPeak_1F_Eventscript_OpenedSeal
	goto_if_eq VAR_ACHROMA_RUINS_STATE, 2, ShiftingPeak_1F_Eventscript_OpenSeal
	msgbox ShiftingPeak_1F_Text_NotWorthy, MSGBOX_SIGN
	release
	end

ShiftingPeak_1F_Eventscript_OpenSeal::
	msgbox ShiftingPeak_1F_Text_YouAreWorthy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShiftingPeak_1F_Eventscript_DeclineSeal
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	delay 30
	setflag FLAG_ACHROMA_HOLLOW_OPEN
ShiftingPeak_1F_Eventscript_OpenedSeal::
	msgbox ShiftingPeak_1F_Text_OtherSide, MSGBOX_SIGN
	release
	end

ShiftingPeak_1F_Eventscript_DeclineSeal::
	release
	end

ShiftingPeak_1F_Text_OnlyWorthy:
	.string "Only ones deemed worthy may\n"
	.string "enter ACHROMA HOLLOW.$"

ShiftingPeak_1F_Text_NotWorthy:
	.string "You are not worthy.$"

ShiftingPeak_1F_Text_YouAreWorthy:
	.string "You are worthy, DREAMER.\n"
	.string "Will you break the seal?$"

ShiftingPeak_1F_Text_OtherSide:
	.string "The answer you seek is\n"
	.string "on the other side.$"
