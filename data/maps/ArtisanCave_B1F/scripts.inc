ArtisanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ArtisanCave_B1F_OnResume
	.byte 0

ArtisanCave_B1F_OnTransition:
	setflag FLAG_LANDMARK_ARTISAN_CAVE
	call_if_unset FLAG_CAUGHT_OGERPON, ArtisanCave_B1F_EventScript_SetOgerponPos
	end

ArtisanCave_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ArtisanCave_B1F_EventScript_TryRemoveOgerpon
	end

ArtisanCave_B1F_EventScript_TryRemoveOgerpon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

ArtisanCave_B1F_EventScript_SetOgerponPos::
	clearflag FLAG_HIDE_B1F_OGERPON
	call_if_eq VAR_OGERPON_PROGRESS, 0, ArtisanCave_B1F_EventScript_SetOgerponPos_0
	call_if_eq VAR_OGERPON_PROGRESS, 1, ArtisanCave_B1F_EventScript_SetOgerponPos_1
	call_if_eq VAR_OGERPON_PROGRESS, 2, ArtisanCave_B1F_EventScript_SetOgerponPos_2
	call_if_eq VAR_OGERPON_PROGRESS, 3, ArtisanCave_B1F_EventScript_SetOgerponPos_3
	return

ArtisanCave_B1F_EventScript_SetOgerponPos_0::
	setobjectxyperm LOCALID_OGERPON, 13, 27
	setobjectmovementtype LOCALID_OGERPON, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	return

ArtisanCave_B1F_EventScript_SetOgerponPos_1::
	setobjectxyperm LOCALID_OGERPON, 23, 40
	setobjectmovementtype LOCALID_OGERPON, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	return

ArtisanCave_B1F_EventScript_SetOgerponPos_2::
	setobjectxyperm LOCALID_OGERPON, 19, 10
	setobjectmovementtype LOCALID_OGERPON, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	return

ArtisanCave_B1F_EventScript_SetOgerponPos_3::
	setobjectxyperm LOCALID_OGERPON, 8, 5
	setobjectmovementtype LOCALID_OGERPON, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	return

ArtisanCave_B1F_EventScript_Ogerpon::
	lock
	faceplayer
	waitse
	playse SE_PIN
	applymovement LOCALID_OGERPON, Common_Movement_ExclamationMark
	delay 40
	playmoncry SPECIES_OGERPON, CRY_MODE_DOUBLES
	waitse
	goto_if_eq VAR_OGERPON_PROGRESS, 0, ArtisanCave_B1F_EventScript_OgerponRun_1
	goto_if_eq VAR_OGERPON_PROGRESS, 1, ArtisanCave_B1F_EventScript_OgerponRun_2
	goto_if_eq VAR_OGERPON_PROGRESS, 2, ArtisanCave_B1F_EventScript_OgerponRun_3
	goto_if_eq VAR_OGERPON_PROGRESS, 3, ArtisanCave_B1F_EventScript_OgerponFight
	release
	end

ArtisanCave_B1F_EventScript_OgerponRun_1::
	playse SE_LEDGE
	applymovement LOCALID_OGERPON, ArtisanCave_B1F_Movement_ClimbHill
	waitmovement 0
	setvar VAR_OGERPON_PROGRESS, 1
	removeobject LOCALID_OGERPON
	call ArtisanCave_B1F_EventScript_SetOgerponPos
	release
	end

ArtisanCave_B1F_EventScript_OgerponRun_2::
	playse SE_LEDGE
	applymovement LOCALID_OGERPON, ArtisanCave_B1F_Movement_JumpLedge
	waitmovement 0
	setvar VAR_OGERPON_PROGRESS, 2
	removeobject LOCALID_OGERPON
	call ArtisanCave_B1F_EventScript_SetOgerponPos
	release
	end

ArtisanCave_B1F_EventScript_OgerponRun_3::
	playse SE_LEDGE
	applymovement LOCALID_OGERPON, ArtisanCave_B1F_Movement_JumpCliff
	waitmovement 0
	setvar VAR_OGERPON_PROGRESS, 3
	removeobject LOCALID_OGERPON
	call ArtisanCave_B1F_EventScript_SetOgerponPos
	release
	end

ArtisanCave_B1F_EventScript_OgerponFight::
	call_if_eq VAR_FACING, DIR_NORTH, ArtisanCave_B1F_EventScript_OgerponLookLR
	call_if_eq VAR_FACING, DIR_WEST, ArtisanCave_B1F_EventScript_OgerponLookUD
	waitse
	playmoncry SPECIES_OGERPON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_OGERPON
	setwildbattle SPECIES_OGERPON, 65
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArtisanCave_B1F_EventScript_DefeatedOgerpon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ArtisanCave_B1F_EventScript_RanFromOgerpon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ArtisanCave_B1F_EventScript_RanFromOgerpon
	setflag FLAG_CAUGHT_OGERPON
	setobjectxyperm LOCALID_ARTISAN_CAVE_OLD_MAN, 9, 12
	addobject LOCALID_ARTISAN_CAVE_OLD_MAN
	msgbox ArtisanCave_B1F_Text_CaughtOgre, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, ArtisanCave_B1F_EventScript_OldManLookLeft
	call_if_eq VAR_FACING, DIR_WEST, ArtisanCave_B1F_EventScript_OldManLookUp
	msgbox ArtisanCave_B1F_Text_ExplainMasks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTISAN_CAVE_OLD_MAN, ArtisanCave_B1F_Movement_OldManLeave
	waitmovement 0
	copyobjectxytoperm LOCALID_ARTISAN_CAVE_OLD_MAN
	release
	end

ArtisanCave_B1F_EventScript_OldManLookLeft::
	applymovement LOCALID_ARTISAN_CAVE_OLD_MAN, ArtisanCave_B1F_Movement_OldManApproach
	turnobject LOCALID_PLAYER, DIR_EAST
	waitmovement 0
	turnobject LOCALID_ARTISAN_CAVE_OLD_MAN, DIR_WEST
	return

ArtisanCave_B1F_EventScript_OldManLookUp::
	applymovement LOCALID_ARTISAN_CAVE_OLD_MAN, ArtisanCave_B1F_Movement_OldManApproach
	turnobject LOCALID_PLAYER, DIR_SOUTH
	waitmovement 0
	return

ArtisanCave_B1F_EventScript_OgerponLookLR::
	applymovement LOCALID_OGERPON, ArtisanCave_B1F_Movement_LookLR
	waitmovement 0
	faceplayer
	playse SE_LEDGE
	applymovement LOCALID_OGERPON, ArtisanCave_B1F_Movement_JumpInPlaceDown
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_OGERPON, ArtisanCave_B1F_Movement_JumpInPlaceDown
	waitmovement 0
	return

ArtisanCave_B1F_EventScript_OgerponLookUD::
	applymovement LOCALID_OGERPON, ArtisanCave_B1F_Movement_LookUD
	waitmovement 0
	faceplayer
	playse SE_LEDGE
	applymovement LOCALID_OGERPON, ArtisanCave_B1F_Movement_JumpInPlaceRight
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_OGERPON, ArtisanCave_B1F_Movement_JumpInPlaceRight
	waitmovement 0
	return

ArtisanCave_B1F_EventScript_DefeatedOgerpon::
	setvar VAR_OGERPON_PROGRESS, 0
	setflag FLAG_HIDE_B1F_OGERPON
	goto Common_EventScript_RemoveStaticPokemon
	end

ArtisanCave_B1F_EventScript_RanFromOgerpon::
	setvar VAR_0x8004, SPECIES_OGERPON
	goto Common_EventScript_LegendaryFlewAway
	end

ArtisanCave_B1F_Movement_ClimbHill:
	jump_right
	delay_16
	walk_slow_diag_northeast
	delay_8
	walk_slow_right
	delay_8
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

ArtisanCave_B1F_Movement_JumpLedge:
	jump_2_left
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

ArtisanCave_B1F_Movement_JumpCliff:
	jump_up
	delay_16
	walk_left
	walk_left
	walk_left
	face_right
	delay_16
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

ArtisanCave_B1F_Movement_LookLR:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	delay_16
	step_end

ArtisanCave_B1F_Movement_LookUD:
	face_up
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	delay_16
	step_end

ArtisanCave_B1F_Movement_JumpInPlaceDown:
	jump_in_place_down
	step_end

ArtisanCave_B1F_Movement_JumpInPlaceRight:
	jump_in_place_right
	step_end

ArtisanCave_B1F_EventScript_MaskMan::
	lock
	faceplayer
	getcaughtmon SPECIES_OKIDOGI
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_B1F_EventScript_CheckMunkidori
	goto_if_set FLAG_CAUGHT_OGERPON, ArtisanCave_B1F_EventScript_Hint
	goto_if_set FLAG_TEMP_A, ArtisanCave_B1F_EventScript_HelpHer
	msgbox ArtisanCave_B1F_Text_ExplainOgerpon, MSGBOX_DEFAULT
	goto ArtisanCave_B1F_EventScript_HelpHer
	release
	end

ArtisanCave_B1F_EventScript_HelpHer::
	msgbox ArtisanCave_B1F_Text_HelpHer, MSGBOX_DEFAULT
	setflag FLAG_TEMP_A
	release
	end

ArtisanCave_B1F_EventScript_Hint::
	goto_if_set FLAG_TEMP_B, ArtisanCave_B1F_EventScript_Hint_2
	msgbox ArtisanCave_B1F_Text_HintLocation, MSGBOX_DEFAULT
	goto ArtisanCave_B1F_EventScript_Hint_2
	release
	end

ArtisanCave_B1F_EventScript_Hint_2::
	msgbox ArtisanCave_B1F_Text_Hint, MSGBOX_DEFAULT
	setflag FLAG_TEMP_B
	release
	end

ArtisanCave_B1F_EventScript_CheckMunkidori::
	getcaughtmon SPECIES_MUNKIDORI
	goto_if_eq VAR_RESULT, TRUE, ArtisanCave_B1F_EventScript_MasksBack
	goto ArtisanCave_B1F_EventScript_Hint
	release
	end

ArtisanCave_B1F_EventScript_MasksBack::
	getcaughtmon SPECIES_FEZANDIPITI
	goto_if_eq VAR_RESULT, FALSE, ArtisanCave_B1F_EventScript_Hint
	msgbox ArtisanCave_B1F_Text_MasksBack, MSGBOX_DEFAULT
	release
	end

ArtisanCave_B1F_Movement_OldManApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ArtisanCave_B1F_Movement_OldManLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ArtisanCave_B1F_Text_ExplainOgerpon:
	.string "A powerful but shy ogre resides in\n"
	.string "this cave.\p"
	.string "She used to play and fight with such\n"
	.string "joy, but she has been inconsolable\l"
	.string "and my words no longer reach her.$"

ArtisanCave_B1F_Text_HelpHer:
	.string "Please, Champion, would you go help\n"
	.string "her in my stead?$"

ArtisanCave_B1F_Text_CaughtOgre:
	.string "Ah, you caught the ogre. That is\n"
	.string "probably for the best…$"

ArtisanCave_B1F_Text_ExplainMasks:
	.string "She has been roaming this cave ever\n"
	.string "since three lousy POKéMON stole her\l"
	.string "precious masks.\p"
	.string "Search for them. I promise it will be\n"
	.string "worth your time.\p"
	.string "Both for you as a TRAINER…\p"
	.string "…and for OGERPON.$"

ArtisanCave_B1F_Text_HintLocation:
	.string "Those lousy three POKéMON are\n"
	.string "obsessed with OGERPON.\p"
	.string "But they love showing off to people\n"
	.string "in the facilities, too.\l"
	.string "But they are not here in the\l"
	.string "BATTLE FRONTIER…$"

ArtisanCave_B1F_Text_Hint:
	.string "Do you know of any other facilities,\n"
	.string "where one might show one's skills?$"

ArtisanCave_B1F_Text_MasksBack:
	.string "Ah…\n"
	.string "You got the masks back?\l"
	.string "I am sure OGERPON must be happy now.$"
