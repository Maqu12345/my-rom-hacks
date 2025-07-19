ScorchedSlab_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ScorchedSlab_B2F_OnResume
	.byte 0

ScorchedSlab_B2F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ScorchedSlab_B2F_EventScript_TryRemoveHeatran
	end

ScorchedSlab_B2F_EventScript_TryRemoveHeatran::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

ScorchedSlab_B2F_EventScript_Altar::
	goto_if_set FLAG_DEFEATED_HEATRAN, ScorchedSlab_B2F_EventScript_Done
	msgbox ScorchedSlab_B2F_Text_WhatThis, MSGBOX_SIGN
	checkitem ITEM_RUBY
	compare VAR_RESULT, TRUE
	goto_if_ge ScorchedSlab_B2F_EventScript_PlaceItem
	release
	end

ScorchedSlab_B2F_EventScript_Done::
	msgbox ScorchedSlab_B2F_Text_FilledAltar, MSGBOX_SIGN
	end

ScorchedSlab_B2F_EventScript_PlaceItem::
	msgbox ScorchedSlab_B2F_Text_PlaceHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ScorchedSlab_B2F_EventScript_HeatranFight
	release
	end

ScorchedSlab_B2F_EventScript_HeatranFight::
	closemessage
	removeallitem ITEM_RUBY
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 40
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 40
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 5  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 40
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 6  @ horizontal pan
	setvar VAR_0x8006, 12  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 50
	waitse
	playmoncry SPECIES_HEATRAN, CRY_MODE_ENCOUNTER
	delay 60
	waitmoncry
	playse SE_FALL
	applymovement LOCALID_SCORCHED_SLAB_HEATRAN, ScorchedSlab_B2F_Movement_Fall
	waitmovement 0
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 10  @ horizontal pan
	setvar VAR_0x8006, 2  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 4
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 6  @ horizontal pan
	setvar VAR_0x8006, 2  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 4
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 20
	waitse
	playmoncry SPECIES_HEATRAN, CRY_MODE_ENCOUNTER
	delay 60
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SCORCHED_SLAB_HEATRAN
	setwildbattle SPECIES_HEATRAN, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ScorchedSlab_B2F_EventScript_DefeatedHeatran
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ScorchedSlab_B2F_EventScript_DefeatedHeatran
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ScorchedSlab_B2F_EventScript_DefeatedHeatran
	setflag FLAG_DEFEATED_HEATRAN
	release
	end

ScorchedSlab_B2F_EventScript_DefeatedHeatran::
	setflag FLAG_DEFEATED_HEATRAN
	goto Common_EventScript_RemoveStaticPokemon
	end

ScorchedSlab_B2F_Movement_Fall:
	set_visible
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

ScorchedSlab_B2F_Text_WhatThis:
	.string "There seems to be a kind of altar here.\n"
	.string "There's a octagonal indent in the center.$"

ScorchedSlab_B2F_Text_PlaceHere:
	.string "Place the RUBY in the indent?$"

ScorchedSlab_B2F_Text_FilledAltar:
	.string "There seems to be a kind of altar here.\n"
	.string "The RUBY is lodged in the center.$"
