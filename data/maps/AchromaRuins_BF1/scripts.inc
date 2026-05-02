AchromaRuins_BF1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AchromaRuins_BF1_OnTransition
	.byte 0

@	VAR_ACHROMA_RUINS_STATE == 0 ; Before talking to the master on the truth side
@	VAR_ACHROMA_RUINS_STATE == 1 ; Master on the ideal side
@	VAR_ACHROMA_RUINS_STATE == 2 ; Master on lower floor

AchromaRuins_BF1_OnTransition:
	call_if_eq VAR_ACHROMA_RUINS_STATE, 1, AchromaRuins_BF1_EventScript_MoveTheMaster
	end

AchromaRuins_BF1_EventScript_MoveTheMaster::
	setobjectxyperm LOCALID_THE_MASTER, 22, 27
	setobjectmovementtype LOCALID_THE_MASTER, MOVEMENT_TYPE_FACE_RIGHT
	return

AchromaRuins_BF1_EventScript_DeleteTheMaster::
	setflag FLAG_TEMP_F
	end

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
	goto_if_unset FLAG_SYS_GAME_CLEAR, AchromaRuins_BF1_EventScript_NotWorthyYet
	msgbox AchromaRuins_BF1_Text_AWorthyChallenge, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_THE_MASTER, AchromaRuins_BF1_Text_TheMasterDefeat
	msgbox AchromaRuins_BF1_Text_Congratulations, MSGBOX_NPC
	setvar VAR_ACHROMA_RUINS_STATE, 2
	applymovement LOCALID_THE_MASTER, Common_Movement_WalkLeftSlow
	waitmovement
	removeobject LOCALID_THE_MASTER
	playse SE_EXIT
	waitse
	release
	end

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

AchromaRuins_BF1_EventScript_NotWorthyYet::
	msgbox AchromaRuins_BF1_Text_NotWorthy, MSGBOX_NPC
	release
	end

AchromaRuins_BF1_Text_NowDoItAgain:
	.string "THE MASTER: Now that you know the path\n"
	.string "of truth, come to the other side and\l"
	.string "prove your ideals to me.$"

AchromaRuins_BF1_Text_HoldIt:
	.string "THE MASTER: Hold it right there!$"

AchromaRuins_BF1_Text_LuckyOrNot:
	.string "Did you just get lucky, stumbling\n"
	.string "around blindly to get here?\p"
	.string "Or have you been here before?$"

AchromaRuins_BF1_Text_NotWorthy:
	.string "THE MASTER: You are not worthy yet,\n"
	.string "DREAMER…\p"
	.string "Return to me when you have proven\n"
	.string "your strength in the waking world.$"

AchromaRuins_BF1_Text_AWorthyChallenge:
	.string "THE MASTER: You are strong, DREAMER…\p"
	.string "Prove your strength to me, and show me\n"
	.string "that you are worthy of inheriting\l"
	.string "the power buried beneath.\p"
	.string "EN GUARDE!$"

AchromaRuins_BF1_Text_TheMasterDefeat:
	.string "You have proven yourself worthy…\n"
	.string "Go now, and claim the power.$"

AchromaRuins_BF1_Text_Congratulations:
	.string "THE MASTER: Congratulations, DREAMER.\p"
	.string "Follow me. The power that sleeps below\n"
	.string "is yours for the taking.$"
