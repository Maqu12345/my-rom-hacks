AchromaRuins_BF1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AchromaRuins_BF1_OnTransition
	.byte 0

@	VAR_ACHROMA_RUINS_STATE == 0 ; Before talking to the master on the truth side
@	VAR_ACHROMA_RUINS_STATE == 1 ; Master on the ideal side
@	VAR_ACHROMA_RUINS_STATE >= 2 ; Master on lower floor

AchromaRuins_BF1_OnTransition:
	call_if_eq VAR_ACHROMA_RUINS_STATE, 1, AchromaRuins_BF1_EventScript_MoveTheMaster
	call_if_ge VAR_ACHROMA_RUINS_STATE, 2, AchromaRuins_BF1_EventScript_DeleteTheMaster
	end

AchromaRuins_BF1_EventScript_MoveTheMaster::
	setobjectxyperm LOCALID_THE_MASTER, 22, 27
	setobjectmovementtype LOCALID_THE_MASTER, MOVEMENT_TYPE_FACE_RIGHT
	return

AchromaRuins_BF1_EventScript_DeleteTheMaster::
	removeobject LOCALID_THE_MASTER
	return

AchromaRuins_BF1_EventScript_TheMaster::
	lock
	goto_if_eq VAR_ACHROMA_RUINS_STATE, 1, AchromaRuins_BF1_EventScript_TheMasterFight
	msgbox AchromaRuins_BF1_Text_NowDoItAgain, MSGBOX_NPC
	setvar VAR_ACHROMA_RUINS_STATE, 1
	applymovement LOCALID_THE_MASTER, AchromaRuins_BF1_Movement_OtherSide
	waitmovement
	call AchromaRuins_BF1_EventScript_MoveTheMaster
	release
	end

AchromaRuins_BF1_Movement_OtherSide:
	walk_slow_down
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_up
	delay_16
	face_right
	step_end

AchromaRuins_BF1_EventScript_TheMasterFight::
	end @ UNFINISHED

AchromaRuins_BF1_EventScript_TheMasterAlert::
	lock
	playse SE_PIN
	applymovement LOCALID_THE_MASTER, Common_Movement_ExclamationMark
	waitse
	turnobject LOCALID_THE_MASTER, DIR_EAST
	msgbox AchromaRuins_BF1_Text_HoldIt, MSGBOX_NPC
	applymovement LOCALID_THE_MASTER, AchromaRuins_BF1_Movement_OtherSide
	waitmovement
	call AchromaRuins_BF1_EventScript_MoveTheMaster
	setvar VAR_ACHROMA_RUINS_STATE, 1
	msgbox AchromaRuins_BF1_Text_LuckyOrNot, MSGBOX_NPC
	release
	end

AchromaRuins_BF1_Text_NowDoItAgain:
	.string "Now that you know the path of truth,\n"
	.string "come to the other side and prove\l"
	.string "your ideals to me.$"

AchromaRuins_BF1_Text_HoldIt:
	.string "Hold it right there!$"

AchromaRuins_BF1_Text_LuckyOrNot:
	.string "Did you just get lucky, stumbling\n"
	.string "around blindly to get here?\p"
	.string "Or have you been here before?$"

