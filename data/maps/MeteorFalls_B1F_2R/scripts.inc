MeteorFalls_B1F_2R_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MeteorFalls_B1F_2R_OnResume
	.byte 0

MeteorFalls_B1F_2R_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AbandonedShip_Rooms_B1F_EventScript_TryRemoveJirachi
	end

AbandonedShip_Rooms_B1F_EventScript_TryRemoveJirachi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MeteorFalls_B1F_2R_EventScript_Jirachi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 50
	waitmoncry
	call_if_eq VAR_FACING, DIR_NORTH, MeteorFalls_B1F_2R_EventScript_FaceJirachiNorth
	call_if_eq VAR_FACING, DIR_WEST, MeteorFalls_B1F_2R_EventScript_FaceJirachiWest
	call_if_eq VAR_FACING, DIR_EAST, MeteorFalls_B1F_2R_EventScript_FaceJirachiEast
	applymovement LOCALID_METEOR_FALLS_JIRACHI, MeteorFalls_B1F_2R_Movement_Jump
	call MeteorFalls_B1F_2R_EventScript_SETiming
	waitmovement 0
	playse SE_PIN
	delay 30
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 50
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_METEOR_FALLS_JIRACHI
	setwildbattle SPECIES_JIRACHI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MeteorFalls_B1F_2R_EventScript_DefeatedJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MeteorFalls_B1F_2R_EventScript_DefeatedJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MeteorFalls_B1F_2R_EventScript_DefeatedJirachi
	setflag FLAG_DEFEATED_JIRACHI
	removeobject LOCALID_METEOR_FALLS_JIRACHI
	release
	end

MeteorFalls_B1F_2R_EventScript_DefeatedJirachi::
	setflag FLAG_DEFEATED_JIRACHI
	goto Common_EventScript_RemoveStaticPokemon
	end

MeteorFalls_B1F_2R_EventScript_FaceJirachiNorth::
	applymovement LOCALID_PLAYER, MeteorFalls_B1F_2R_Movement_FaceJirachiNorth
	return

MeteorFalls_B1F_2R_EventScript_FaceJirachiWest::
	applymovement LOCALID_PLAYER, MeteorFalls_B1F_2R_Movement_FaceJirachiWest
	return

MeteorFalls_B1F_2R_EventScript_FaceJirachiEast::
	applymovement LOCALID_PLAYER, MeteorFalls_B1F_2R_Movement_FaceJirachiEast
	return

MeteorFalls_B1F_2R_EventScript_SETiming::
	delay 15
	playse SE_LEDGE
	delay 31
	playse SE_LEDGE
	delay 31
	playse SE_LEDGE
	delay 31
	playse SE_PUDDLE
	delay 31
	playse SE_PUDDLE
	delay 31
	playse SE_PUDDLE
	delay 31
	playse SE_LEDGE
	delay 31
	playse SE_LEDGE
	return

MeteorFalls_B1F_2R_Movement_Jump:
	jump_up
	jump_2_left
	jump_2_down
	jump_2_down
	jump_2_right
	jump_2_right
	jump_2_up
	jump_2_up
	jump_2_left
	delay_1
	face_down
	delay_16
	walk_slow_down
	face_player
	emote_heart
	step_end

MeteorFalls_B1F_2R_Movement_FaceJirachiNorth:
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

MeteorFalls_B1F_2R_Movement_FaceJirachiWest:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	face_left
	step_end

MeteorFalls_B1F_2R_Movement_FaceJirachiEast:
	delay_16
	face_up
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	step_end
