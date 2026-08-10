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
	call_if_lt VAR_DREAM_WORLD_STATE, 6, FantasyLand_Main_EventScript_ClosePortals
	end

FantasyLand_Main_EventScript_ClosePortals::
	setmetatile 18, 20, METATILE_General_LightGrass_Center, FALSE
	setmetatile 20, 20, METATILE_General_LightGrass_Center, FALSE
	setmetatile  5, 19, METATILE_General_LightGrass_Center, FALSE
	setmetatile 11, 26, METATILE_General_LightGrass_Center, FALSE
	setmetatile 20, 36, METATILE_General_LightGrass_Center, FALSE
	setmetatile 35, 30, METATILE_General_LightGrass_Center, FALSE
	return

FantasyLand_Main_EventScript_OpenPortals::
	fadeoutbgm 0
	playse SE_M_TELEPORT
	fadescreenswapbuffers FADE_TO_WHITE, TRUE
	delay 40
	playse SE_M_TELEPORT
	setmetatile 18, 20, METATILE_BattleFrontier_Portal, FALSE
	setmetatile 20, 20, METATILE_BattleFrontier_Portal, FALSE
	setmetatile  5, 19, METATILE_BattleFrontier_Portal, FALSE
	setmetatile 11, 26, METATILE_BattleFrontier_Portal, FALSE
	setmetatile 20, 36, METATILE_BattleFrontier_Portal, FALSE
	setmetatile 35, 30, METATILE_BattleFrontier_Portal, FALSE
	delay 40
	playse SE_M_TELEPORT
	waitse
	playse SE_M_BARRIER
	fadescreenswapbuffers FADE_FROM_WHITE
	waitse
	fadeinbgm 0
	setflag FLAG_SYS_NEW_GAME_PLUS
	return

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

FantasyLand_Main_EventScript_FakeMay::
	lock
	faceplayer
	goto_if_eq VAR_DREAM_WORLD_STATE, 7, FantasyLand_Main_EventScript_SuperbossCheck
	goto_if_eq VAR_DREAM_WORLD_STATE, 6, FantasyLand_Main_EventScript_Interesting
	msgbox FantasyLand_Main_Text_AreYouReadyMay, MSGBOX_AUTOCLOSE
	hidefollower
	switch VAR_FACING
	case DIR_NORTH, FantasyLand_Main_EventScript_GotoPosNorth
	case DIR_EAST,  FantasyLand_Main_EventScript_GotoPosEast
	case DIR_SOUTH, FantasyLand_Main_EventScript_GotoPosSouth
	case DIR_WEST,  FantasyLand_Main_EventScript_GotoPosWest
	end

FantasyLand_Main_EventScript_FakeBrendan::
	lock
	faceplayer
	goto_if_eq VAR_DREAM_WORLD_STATE, 7, FantasyLand_Main_EventScript_SuperbossCheck
	goto_if_eq VAR_DREAM_WORLD_STATE, 6, FantasyLand_Main_EventScript_Interesting
	msgbox FantasyLand_Main_Text_AreYouReadyBrendan, MSGBOX_AUTOCLOSE
	hidefollower
	switch VAR_FACING
	case DIR_NORTH, FantasyLand_Main_EventScript_GotoPosNorth
	case DIR_EAST,  FantasyLand_Main_EventScript_GotoPosEast
	case DIR_SOUTH, FantasyLand_Main_EventScript_GotoPosSouth
	case DIR_WEST,  FantasyLand_Main_EventScript_GotoPosWest
	end

FantasyLand_Main_EventScript_Interesting::
	msgbox FantasyLand_Main_Text_Hmm, MSGBOX_AUTOCLOSE
	release
	end

FantasyLand_Main_EventScript_GotoPosNorth::
	applymovement LOCALID_PLAYER, FantasyLand_Main_Movement_FromNorth
	switch VAR_LOCALID_FAKE_RIVAL
	case LOCALID_FAKE_MAY, FantasyLand_Main_EventScript_FakeMayFight
	case LOCALID_FAKE_BRENDAN, FantasyLand_Main_EventScript_FakeBrendanFight
	end

FantasyLand_Main_EventScript_GotoPosEast::
	applymovement LOCALID_PLAYER, FantasyLand_Main_Movement_FromEast
	switch VAR_LOCALID_FAKE_RIVAL
	case LOCALID_FAKE_MAY, FantasyLand_Main_EventScript_FakeMayFight
	case LOCALID_FAKE_BRENDAN, FantasyLand_Main_EventScript_FakeBrendanFight
	end

FantasyLand_Main_EventScript_GotoPosSouth::
	applymovement LOCALID_PLAYER, FantasyLand_Main_Movement_FromSouth
	switch VAR_LOCALID_FAKE_RIVAL
	case LOCALID_FAKE_MAY, FantasyLand_Main_EventScript_FakeMayFight
	case LOCALID_FAKE_BRENDAN, FantasyLand_Main_EventScript_FakeBrendanFight
	end

FantasyLand_Main_EventScript_GotoPosWest::
	applymovement LOCALID_PLAYER, FantasyLand_Main_Movement_FromWest
	switch VAR_LOCALID_FAKE_RIVAL
	case LOCALID_FAKE_MAY, FantasyLand_Main_EventScript_FakeMayFight
	case LOCALID_FAKE_BRENDAN, FantasyLand_Main_EventScript_FakeBrendanFight
	end

FantasyLand_Main_Movement_FromNorth:
	walk_left
	walk_left
	walk_up
	face_right
	step_end

FantasyLand_Main_Movement_FromEast:
	walk_left
	face_right
	step_end

FantasyLand_Main_Movement_FromSouth:
	walk_left
	walk_left
	walk_down
	face_right
	step_end

FantasyLand_Main_Movement_FromWest:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	face_right
	step_end

FantasyLand_Main_EventScript_FakeMayFight::
	delay 30
	applymovement VAR_LOCALID_FAKE_RIVAL, FantasyLand_Main_Movement_FakeRivalIntoPos
	waitmovement LOCALID_PLAYER
	waitmovement VAR_LOCALID_FAKE_RIVAL
	msgbox FantasyLand_Main_Text_ComeAtMe, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FAKE_MAY, FantasyLand_Main_Text_PokemonAreWonderful
	msgbox FantasyLand_Main_Text_AfterBattleMay, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LOCALID_FAKE_RIVAL, FantasyLand_Main_Movement_WalkLeft2
	waitmovement
	setvar VAR_DREAM_WORLD_STATE, 6
	call FantasyLand_Main_EventScript_OpenPortals
	msgbox FantasyLand_Main_Text_GoExploreMay, MSGBOX_AUTOCLOSE
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	release
	end

FantasyLand_Main_EventScript_FakeBrendanFight::
	delay 30
	applymovement VAR_LOCALID_FAKE_RIVAL, FantasyLand_Main_Movement_FakeRivalIntoPos
	waitmovement LOCALID_PLAYER
	waitmovement VAR_LOCALID_FAKE_RIVAL
	msgbox FantasyLand_Main_Text_ComeAtMe, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FAKE_BRENDAN, FantasyLand_Main_Text_PokemonAreWonderful
	msgbox FantasyLand_Main_Text_AfterBattleBrendan, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LOCALID_FAKE_RIVAL, FantasyLand_Main_Movement_WalkLeft2
	waitmovement
	setvar VAR_DREAM_WORLD_STATE, 6
	call FantasyLand_Main_EventScript_OpenPortals
	msgbox FantasyLand_Main_Text_GoExploreBrendan, MSGBOX_AUTOCLOSE
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	release
	end

FantasyLand_Main_Movement_FakeRivalIntoPos:
	walk_right
	face_left
	step_end

FantasyLand_Main_Movement_WalkLeft2:
	walk_left
	walk_left
	step_end

FantasyLand_Main_EventScript_SuperbossCheck: @ Dummy function for now
	msgbox FantasyLand_Main_Text_NotReadyYet, MSGBOX_NPC
	release
	end

FantasyLand_Main_EventScript_ReleaseLegend1::
	lock
	playse SE_PIN
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_ExclamationMark
	delay 60
	msgbox FantasyLand_Main_Text_BeforeIForget, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement VAR_LOCALID_FAKE_RIVAL, FantasyLand_Main_Movement_WalkTo1
	goto FantasyLand_Main_EventScript_ReleaseLegendR
	release
	end

FantasyLand_Main_Movement_WalkTo1:
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

FantasyLand_Main_EventScript_ReleaseLegend2::
	lock
	playse SE_PIN
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_ExclamationMark
	delay 60
	msgbox FantasyLand_Main_Text_BeforeIForget, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement VAR_LOCALID_FAKE_RIVAL, FantasyLand_Main_Movement_WalkTo2
	goto FantasyLand_Main_EventScript_ReleaseLegendR
	release
	end

FantasyLand_Main_Movement_WalkTo2:
	walk_left
	walk_down
	walk_down
	step_end

FantasyLand_Main_EventScript_ReleaseLegend3::
	lock
	playse SE_PIN
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_ExclamationMark
	delay 60
	msgbox FantasyLand_Main_Text_BeforeIForget, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement VAR_LOCALID_FAKE_RIVAL, FantasyLand_Main_Movement_WalkTo3
	goto FantasyLand_Main_EventScript_ReleaseLegendL
	release
	end

FantasyLand_Main_Movement_WalkTo3:
	walk_down
	walk_down
	step_end

FantasyLand_Main_EventScript_ReleaseLegend4::
	lock
	playse SE_PIN
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_ExclamationMark
	delay 60
	msgbox FantasyLand_Main_Text_BeforeIForget, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement VAR_LOCALID_FAKE_RIVAL, FantasyLand_Main_Movement_WalkTo4
	goto FantasyLand_Main_EventScript_ReleaseLegendL
	release
	end

FantasyLand_Main_Movement_WalkTo4:
	walk_right
	walk_down
	walk_down
	step_end

FantasyLand_Main_EventScript_ReleaseLegendR::
	msgbox FantasyLand_Main_Text_IWontNeedThis, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_WalkUp2
	waitmovement 0
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	copyobjectxytoperm VAR_LOCALID_FAKE_RIVAL
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FantasyLand_Main_EventScript_SetCress
	call_if_eq VAR_RESULT, FEMALE, FantasyLand_Main_EventScript_SetDark
	getobjectxy VAR_LOCALID_FAKE_RIVAL, CURRENT_POSITION, VAR_TEMP_1, VAR_TEMP_2
	subvar VAR_TEMP_1, 1
	delay 10
	setobjectxyperm VAR_TEMP_A, VAR_TEMP_1, VAR_TEMP_2
	addobject VAR_TEMP_A
	applymovement VAR_TEMP_A, Common_Movement_ExitPokeball
	playse SE_BALL_OPEN
	waitse
	playmoncry VAR_TEMP_B, CRY_MODE_NORMAL
	waitmoncry
	bufferspeciesname STR_VAR_1, VAR_TEMP_B
	msgbox FantasyLand_Main_Text_ByeBye, MSGBOX_DEFAULT
	playmoncry VAR_TEMP_B, CRY_MODE_NORMAL
	applymovement VAR_TEMP_A, FantasyLand_Movement_FleeingLegendaryR
	waitmovement 0
	playse SE_M_FLY
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_FaceDown
	applymovement VAR_TEMP_A, FantasyLand_Movement_FleeingLegendary2
	waitmovement 0
	setobjectxyperm VAR_TEMP_A, 0, 0
	removeobject VAR_TEMP_A
	msgbox FantasyLand_Main_Text_CheckOutRealWorldToo, MSGBOX_DEFAULT
	closemessage
	setvar VAR_DREAM_WORLD_STATE, 7
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, FantasyLand_Main_EventScript_UnsetCress
	clearflag FLAG_DEFEATED_DARKRAI
	release
	end

FantasyLand_Main_EventScript_ReleaseLegendL::
	msgbox FantasyLand_Main_Text_IWontNeedThis, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_WalkUp2
	waitmovement 0
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	copyobjectxytoperm VAR_LOCALID_FAKE_RIVAL
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FantasyLand_Main_EventScript_SetCress
	call_if_eq VAR_RESULT, FEMALE, FantasyLand_Main_EventScript_SetDark
	getobjectxy VAR_LOCALID_FAKE_RIVAL, CURRENT_POSITION, VAR_TEMP_1, VAR_TEMP_2
	addvar VAR_TEMP_1, 1
	delay 10
	setobjectxyperm VAR_TEMP_A, VAR_TEMP_1, VAR_TEMP_2
	addobject VAR_TEMP_A
	applymovement VAR_TEMP_A, Common_Movement_ExitPokeball
	playse SE_BALL_OPEN
	waitse
	playmoncry VAR_TEMP_B, CRY_MODE_NORMAL
	waitmoncry
	bufferspeciesname STR_VAR_1, VAR_TEMP_B
	msgbox FantasyLand_Main_Text_ByeBye, MSGBOX_DEFAULT
	playmoncry VAR_TEMP_B, CRY_MODE_NORMAL
	applymovement VAR_TEMP_A, FantasyLand_Movement_FleeingLegendaryL
	waitmovement 0
	playse SE_M_FLY
	applymovement VAR_LOCALID_FAKE_RIVAL, Common_Movement_FaceDown
	applymovement VAR_TEMP_A, FantasyLand_Movement_FleeingLegendary2
	waitmovement 0
	setobjectxyperm VAR_TEMP_A, 0, 0
	removeobject VAR_TEMP_A
	msgbox FantasyLand_Main_Text_CheckOutRealWorldToo, MSGBOX_DEFAULT
	closemessage
	setvar VAR_DREAM_WORLD_STATE, 7
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, FantasyLand_Main_EventScript_UnsetCress
	clearflag FLAG_DEFEATED_DARKRAI
	release
	end

FantasyLand_Main_EventScript_UnsetCress::
	clearflag FLAG_DEFEATED_CRESSELIA
	release
	end

FantasyLand_Main_EventScript_SetCress::
	setvar VAR_TEMP_A, LOCALID_RELEASED_CRESSELIA
	setvar VAR_TEMP_B, SPECIES_CRESSELIA
	return

FantasyLand_Main_EventScript_SetDark::
	setvar VAR_TEMP_A, LOCALID_RELEASED_DARKRAI
	setvar VAR_TEMP_B, SPECIES_DARKRAI
	return

FantasyLand_Movement_FleeingLegendaryR:
	face_up
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

FantasyLand_Movement_FleeingLegendaryL:
	face_up
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_diag_northeast
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

FantasyLand_Movement_FleeingLegendary2:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

Common_Movement_ExitPokeball:
	exit_pokeball
	step_end

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
	.string "MAY?: I always wanted to try this…\p"
	.string "I wish to fight you in a POKéMON BATTLE!\p"
	.string "But before we begin, I know it is\n"
	.string "sudden, so please take your time\l"
	.string "and get ready. You can leave and\l"
	.string "come back anytime. Just take the bed on\l"
	.string "the right in the house in your DREAMS.\p"
	.string "I'll be waiting for you…$"

FantasyLand_Main_Text_BrendanPokemon:
	.string "BRENDAN?: I always wanted to try this…\p"
	.string "I wish to fight you in a POKéMON BATTLE!\p"
	.string "But before we begin, I know it is\n"
	.string "sudden, so please take your time\l"
	.string "and get ready. You can leave and\l"
	.string "come back anytime. Just take the bed on\l"
	.string "the left in the house in your DREAMS.\p"
	.string "I'll be waiting for you…$"

FantasyLand_Main_Text_AreYouReadyMay:
	.string "MAY?: So you're ready to start, then.\n"
	.string "Good, good.\p"
	.string "This is so exciting!\n"
	.string "Please stand over there…$"

FantasyLand_Main_Text_AreYouReadyBrendan:
	.string "BRENDAN?: So you're ready to start, then.\n"
	.string "Good, good.\p"
	.string "This is so exciting!\n"
	.string "Please stand over there…$"

FantasyLand_Main_Text_ComeAtMe:
	.string "Now!\n"
	.string "Come at me!$"

FantasyLand_Main_Text_PokemonAreWonderful:
	.string "POKéMON are such wonderful creatures,\n"
	.string "wouldn't you say?$"

FantasyLand_Main_Text_AfterBattleMay:
	.string "MAY?: Hahahahaha!\p"
	.string "How exciting. I haven't had\n"
	.string "so much fun in ages.\p"
	.string "You are strong indeed, so please come\n"
	.string "back soon. I'm sorry that I broke into\l"
	.string "your DREAM WORLD, even if unknowingly,\l"
	.string "so I'll give you a gift for beating me.$"

FantasyLand_Main_Text_AfterBattleBrendan:
	.string "BRENDAN?: Hahahahaha!\p"
	.string "How exciting. I haven't had\n"
	.string "so much fun in ages.\p"
	.string "You are strong indeed, so please come\n"
	.string "back soon. I'm sorry that I broke into\l"
	.string "your DREAM WORLD, even if unknowingly,\l"
	.string "so I'll give you a gift for beating me.$"

FantasyLand_Main_Text_GoExploreMay:
	.string "MAY?: There, it should be much\n"
	.string "easier for you to traverse the\l"
	.string "DREAM WORLD now.\p"
	.string "And as a bonus, I'm giving you access\n"
	.string "to my private garden where I collect\l"
	.string "all the cute POKéMON I've found.\p"
	.string "May you catch good dreams, DREAMER…\p"
	.string "… … …\n"
	.string "… … … Huh?\p"
	.string "I look like your neighbor to you?\p"
	.string "Perhaps you're imagining things.\n"
	.string "Of course, your DREAM WORLD SELF\l"
	.string "was never supposed to leave the\l"
	.string "DREAM WORLD as you have now.\p"
	.string "Interesting, hmm…$"

FantasyLand_Main_Text_GoExploreBrendan:
	.string "BRENDAN?: There, it should be much\n"
	.string "easier for you to traverse the\l"
	.string "DREAM WORLD now.\p"
	.string "And as a bonus, I'm giving you access\n"
	.string "to my private garden where I collect\l"
	.string "all the cute POKéMON I've found.\p"
	.string "May you catch good dreams, DREAMER…\p"
	.string "… … …\n"
	.string "… … … Huh?\p"
	.string "I look like your neighbor to you?\p"
	.string "Perhaps you're imagining things.\n"
	.string "Of course, your DREAM WORLD SELF\l"
	.string "was never supposed to leave the\l"
	.string "DREAM WORLD as you have now.\p"
	.string "Interesting, hmm…$"

FantasyLand_Main_Text_Hmm:
	.string "?????: Interesting, hmm…$"

FantasyLand_Main_Text_BeforeIForget:
	.string "?????: Oh yes, one more thing\n"
	.string "before I forget!$"

FantasyLand_Main_Text_IWontNeedThis:
	.string "?????: I don't need this anymore,\n"
	.string "so I will give you the chance to\l"
	.string "catch it, instead.$"

FantasyLand_Main_Text_ByeBye:
	.string "?????: Bye bye, {STR_VAR_1}!$"

FantasyLand_Main_Text_CheckOutRealWorldToo:
	.string "?????: I would love if you came by on\n"
	.string "occasion but don't forget that there's\l"
	.string "a whole world out there for you.\l"
	.string "Go explore, kid.\p"
	.string "One day, maybe I will fight you with\n"
	.string "my true strength, but you are not\l"
	.string "ready yet…$"

FantasyLand_Main_Text_NotReadyYet:
	.string "?????: One day, maybe I will fight\n"
	.string "you with my true strength, but you\l"
	.string "are not ready yet…$"
