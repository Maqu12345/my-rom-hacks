Terminal_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Terminal_Interior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Terminal_Interior_OnFrame
	.byte 0

Terminal_Interior_OnTransition:
	goto_if_eq VAR_DREAM_WORLD_STATE, 4, Terminal_Interior_EventScript_Loop
	setdynamicwarp MAP_TERMINAL, 1
	end

Terminal_Interior_EventScript_Loop::
	setdynamicwarp MAP_TERMINAL_INTERIOR, 0
	end

Terminal_Interior_OnFrame:
	map_script_2 VAR_DREAM_WORLD_STATE, 3, Terminal_Interior_EventScript_FirstTime
	.2byte 0

Terminal_Interior_EventScript_FirstTime::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN
	delay 60
	applymovement LOCALID_PLAYER, Terminal_Interior_Movement_LookAround
	waitmovement 0
	setvar VAR_DREAM_WORLD_STATE, 4
	setdynamicwarp MAP_TERMINAL_INTERIOR, 0
	release
	end

Terminal_Interior_Movement_LookAround:
	face_left
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	step_end

Terminal_Interior_EventScript_TV::
	msgbox Terminal_Interior_Text_Broken, MSGBOX_SIGN
	end

Terminal_Interior_Text_Broken:
	.string "It doesn't appear to be working.$"
