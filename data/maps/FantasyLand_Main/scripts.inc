FantasyLand_Main_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FantasyLand_Main_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, FantasyLand_Main_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FantasyLand_Main_OnFrame
	.byte 0

FantasyLand_Main_OnTransition:
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FantasyLand_EventScript_HideFakeBrendan
	call_if_eq VAR_RESULT, FEMALE, FantasyLand_EventScript_HideFakeMay
	call_if_ge VAR_DREAM_WORLD_STATE, 5, FantasyLand_EventScript_MoveFakeRival
	end

FantasyLand_EventScript_HideFakeBrendan::
	setflag FLAG_TEMP_10
	setvar VAR_LOCALID_FAKE_RIVAL, LOCALID_FAKE_MAY
	return

FantasyLand_EventScript_HideFakeMay::
	setflag FLAG_TEMP_11
	setvar VAR_LOCALID_FAKE_RIVAL, LOCALID_FAKE_BRENDAN
	return

FantasyLand_EventScript_MoveFakeRival::
	setobjectxyperm VAR_LOCALID_FAKE_RIVAL, 20, 8
	return

FantasyLand_Main_OnLoad:
	goto_if_lt VAR_DREAM_WORLD_STATE, 6, FantasyLand_Main_EventScript_ClosePortals
	end

FantasyLand_Main_EventScript_ClosePortals::
	setmetatile 18, 20, METATILE_General_LightGrass_Center, FALSE
	setmetatile 20, 20, METATILE_General_LightGrass_Center, FALSE
	setmetatile  5, 19, METATILE_General_LightGrass_Center, FALSE
	setmetatile 11, 26, METATILE_General_LightGrass_Center, FALSE
	setmetatile 20, 36, METATILE_General_LightGrass_Center, FALSE
	setmetatile 35, 30, METATILE_General_LightGrass_Center, FALSE
	end

FantasyLand_Main_OnFrame:
	map_script_2 VAR_DREAM_WORLD_STATE, 4, FantasyLand_Main_EventScript_Intro
	.2byte 0

FantasyLand_Main_EventScript_Intro::
	lock
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	msgbox FantasyLand_Main_Text_IForgor, MSGBOX_AUTOCLOSE
	delay 40
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FantasyLand_Main_EventScript_FakeMayIntro
	call_if_eq VAR_RESULT, FEMALE, FantasyLand_Main_EventScript_FakeBrendanIntro
	applymovement VAR_LOCALID_FAKE_RIVAL, FantasyLand_Movement_FollowMe
	applymovement LOCALID_PLAYER, FantasyLand_Movement_Follows
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FantasyLand_Main_EventScript_FakeMaySpeech
	call_if_eq VAR_RESULT, FEMALE, FantasyLand_Main_EventScript_FakeBrendanSpeech
	setvar VAR_DREAM_WORLD_STATE, 5
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	setobjectxyperm VAR_LOCALID_FAKE_RIVAL, 20, 8
	release
	end

FantasyLand_Main_EventScript_FakeMayIntro::
	msgbox FantasyLand_Main_Text_MayWelcome, MSGBOX_AUTOCLOSE
	return

FantasyLand_Main_EventScript_FakeMaySpeech::
	msgbox FantasyLand_Main_Text_MayPokemon, MSGBOX_AUTOCLOSE
	return

FantasyLand_Main_EventScript_FakeBrendanIntro::
	msgbox FantasyLand_Main_Text_BrendanWelcome, MSGBOX_AUTOCLOSE
	return

FantasyLand_Main_EventScript_FakeBrendanSpeech::
	msgbox FantasyLand_Main_Text_BrendanPokemon, MSGBOX_AUTOCLOSE
	return

FantasyLand_Movement_Follows:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

FantasyLand_Movement_FollowMe:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_player
	step_end

FantasyLand_Main_EventScript_Audino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AUDINO, CRY_MODE_NORMAL
	msgbox FantasyLand_Main_Text_Audino, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FantasyLand_Main_Text_Audino:
	.string "Dididiii?$"

FantasyLand_Main_Text_IForgor:
	.string "Oh no… How…\p"
	.string "Did I forget to…$"

FantasyLand_Main_Text_MayWelcome:
	.string "MAY?: Greetings, welcome.\n"
	.string "You're probably wondering where you\l"
	.string "are right now.\p"
	.string "I made this place because I wanted to\n"
	.string "meet with a strong POKéMON TRAINER.\p"
	.string "The barrier between dreams and reality\n"
	.string "is thin here. That is how you found\l"
	.string "your way here, yes?\p"
	.string "Please follow me.$"

FantasyLand_Main_Text_BrendanWelcome:
	.string "BRENDAN?: Greetings, welcome.\n"
	.string "You're probably wondering where you\l"
	.string "are right now.\p"
	.string "I made this place because I wanted to\n"
	.string "meet with a strong POKéMON TRAINER.\p"
	.string "The barrier between dreams and reality\n"
	.string "is thin here. That is how you found\l"
	.string "your way here, yes?\p"
	.string "Please follow me.$"

FantasyLand_Main_Text_MayPokemon:
	.string "MAY?: I've always wanted to try this…\p"
	.string "I wish to fight you in a POKéMON BATTLE!\p"
	.string "But before we begin, please take your\n"
	.string "time and get ready. You can leave and\l"
	.string "come back anytime. Just take the bed on\l"
	.string "the right in the house in your DREAMS.\p"
	.string "I'll be waiting for you…$"

FantasyLand_Main_Text_BrendanPokemon:
	.string "BRENDAN?: I've always wanted to try this…\p"
	.string "I wish to fight you in a POKéMON BATTLE!\p"
	.string "But before we begin, please take your\n"
	.string "time and get ready. You can leave and\l"
	.string "come back anytime. Just take the bed on\l"
	.string "the left in the house in your DREAMS.\p"
	.string "I'll be waiting for you…$"

	.string "POKéMON are such wonderful creatures,\n"
	.string "wouldn't you say?\p"
