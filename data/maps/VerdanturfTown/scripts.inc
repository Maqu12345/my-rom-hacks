VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, VerdanturfTown_OnResume
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	call_if_unset FLAG_DEFEATED_PECHARUNT, VerdanturfTown_EventScript_StartFestival
	end

VerdanturfTown_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VerdanturfTown_EventScript_TryRemovePecharunt
	end

VerdanturfTown_EventScript_TryRemovePecharunt::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

VerdanturfTown_EventScript_StartFestival::
	setflag FLAG_HIDE_PECHARUNT
	goto_if_unset FLAG_CAUGHT_OGERPON, Common_EventScript_NopReturn
	setobjectxyperm LOCALID_VERDANTURF_TWIN, 9, 7
	setobjectxyperm LOCALID_VERDANTURF_CAMPER, 8, 8
	setobjectxyperm LOCALID_VERDANTURF_BOY, 10, 8
	setobjectxyperm LOCALID_VERDANTURF_MAN, 9, 9
	setobjectmovementtype LOCALID_VERDANTURF_TWIN, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_VERDANTURF_CAMPER, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_VERDANTURF_BOY, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	setobjectmovementtype LOCALID_VERDANTURF_MAN, MOVEMENT_TYPE_ROTATE_CLOCKWISE
	clearflag FLAG_HIDE_PECHARUNT
	setflag FLAG_TEMP_7
	return

VerdanturfTown_EventScript_MochiMochi::
	msgbox VerdanturfTown_Text_Mochi, MSGBOX_DEFAULT
	waitmessage
	call VerdanturfTown_EventScript_CheckLoyalThree
	goto_if_set FLAG_TEMP_9, VerdanturfTown_EventScript_GetWellSoon
	closemessage
	goto_if_set FLAG_TEMP_8, VerdanturfTown_EventScript_Pecharunt
	release
	end

VerdanturfTown_EventScript_CheckLoyalThree::
	goto_if_unset FLAG_CAUGHT_OKIDOGI, Common_EventScript_NopReturn
	goto_if_unset FLAG_CAUGHT_MUNKIDORI, Common_EventScript_NopReturn
	goto_if_unset FLAG_CAUGHT_FEZANDIPITI, Common_EventScript_NopReturn
	setflag FLAG_TEMP_8
	return

VerdanturfTown_EventScript_Pecharunt::
	waitse
	playse SE_PIN
	applymovement LOCALID_PECHARUNT, Common_Movement_QuestionMark
	delay 60
	goto_if_eq VAR_FACING, DIR_NORTH, VerdanturfTown_EventScript_GoDown
	goto_if_eq VAR_FACING, DIR_EAST, VerdanturfTown_EventScript_GoLeft
	goto_if_eq VAR_FACING, DIR_SOUTH, VerdanturfTown_EventScript_GoUp
	goto_if_eq VAR_FACING, DIR_WEST, VerdanturfTown_EventScript_GoRight
	release
	end

VerdanturfTown_EventScript_GetWellSoon::
	msgbox VerdanturfTown_Text_GetBetter, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_GoDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkDownFast
	call VerdanturfTown_EventScript_MakeWay
	waitmovement
	waitse
	playse SE_PIN
	applymovement LOCALID_PECHARUNT, Common_Movement_ExclamationMark
	applymovement LOCALID_PECHARUNT, Common_Movement_FaceDown
	delay 60
	applymovement LOCALID_PECHARUNT, VerdanturfTown_Movement_WalkDown2
	waitmovement
	delay 16
	applymovement LOCALID_PECHARUNT, Common_Movement_FacePlayer
	goto VerdanturfTown_EventScript_PecharuntFight
	release
	end

VerdanturfTown_EventScript_GoLeft::
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeftFast
	call VerdanturfTown_EventScript_MakeWay
	waitmovement
	waitse
	playse SE_PIN
	applymovement LOCALID_PECHARUNT, Common_Movement_ExclamationMark
	applymovement LOCALID_PECHARUNT, Common_Movement_FaceLeft
	delay 60
	applymovement LOCALID_PECHARUNT, VerdanturfTown_Movement_WalkLeft2
	waitmovement
	delay 16
	applymovement LOCALID_PECHARUNT, Common_Movement_FacePlayer
	goto VerdanturfTown_EventScript_PecharuntFight
	release
	end

VerdanturfTown_EventScript_GoUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkUpFast
	call VerdanturfTown_EventScript_MakeWay
	waitmovement
	waitse
	playse SE_PIN
	applymovement LOCALID_PECHARUNT, Common_Movement_ExclamationMark
	applymovement LOCALID_PECHARUNT, Common_Movement_FaceUp
	delay 60
	applymovement LOCALID_PECHARUNT, VerdanturfTown_Movement_WalkUp2
	waitmovement
	delay 16
	applymovement LOCALID_PECHARUNT, Common_Movement_FacePlayer
	goto VerdanturfTown_EventScript_PecharuntFight
	release
	end

VerdanturfTown_EventScript_GoRight::
	applymovement LOCALID_PLAYER, Common_Movement_WalkRightFast
	call VerdanturfTown_EventScript_MakeWay
	waitmovement
	waitse
	playse SE_PIN
	applymovement LOCALID_PECHARUNT, Common_Movement_ExclamationMark
	applymovement LOCALID_PECHARUNT, Common_Movement_FaceRight
	delay 60
	applymovement LOCALID_PECHARUNT, VerdanturfTown_Movement_WalkRight2
	waitmovement
	delay 16
	applymovement LOCALID_PECHARUNT, Common_Movement_FacePlayer
	goto VerdanturfTown_EventScript_PecharuntFight
	release
	end

VerdanturfTown_EventScript_MakeWay::
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_WalkLeftSlow
	applymovement LOCALID_VERDANTURF_CAMPER, Common_Movement_WalkDownSlow
	applymovement LOCALID_VERDANTURF_BOY, Common_Movement_WalkUpSlow
	applymovement LOCALID_VERDANTURF_MAN, Common_Movement_WalkRightSlow
	return

VerdanturfTown_EventScript_PecharuntFight::
	getdirectiontoface VAR_RESULT, LOCALID_PLAYER, LOCALID_PECHARUNT
	call_if_eq VAR_RESULT, DIR_NORTH, VerdanturfTown_EventScript_LookUp
	call_if_eq VAR_RESULT, DIR_EAST, VerdanturfTown_EventScript_LookRight
	call_if_eq VAR_RESULT, DIR_SOUTH, VerdanturfTown_EventScript_LookDown
	call_if_eq VAR_RESULT, DIR_WEST, VerdanturfTown_EventScript_LookLeft
	delay 20
	waitse
	playmoncry SPECIES_PECHARUNT, CRY_MODE_ENCOUNTER
	delay 60
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_PECHARUNT
	setwildbattle SPECIES_PECHARUNT, 68
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VerdanturfTown_EventScript_DefeatedPecharunt
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VerdanturfTown_EventScript_DefeatedPecharunt
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VerdanturfTown_EventScript_DefeatedPecharunt
	setflag FLAG_DEFEATED_PECHARUNT
	call VerdanturfTown_EventScript_BackToNormal
	release
	end

VerdanturfTown_EventScript_DefeatedPecharunt::
	setflag FLAG_DEFEATED_PECHARUNT
	call VerdanturfTown_EventScript_BackToNormal
	goto Common_EventScript_RemoveStaticPokemon
	end

VerdanturfTown_EventScript_BackToNormal::
	setflag FLAG_TEMP_9
	return

VerdanturfTown_EventScript_LookUp::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	return

VerdanturfTown_EventScript_LookRight::
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	return

VerdanturfTown_EventScript_LookDown::
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	return

VerdanturfTown_EventScript_LookLeft::
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	return

VerdanturfTown_Movement_WalkUp2:
	walk_up
	walk_up
	step_end

VerdanturfTown_Movement_WalkDown2:
	walk_down
	walk_down
	step_end

VerdanturfTown_Movement_WalkLeft2:
	walk_left
	walk_left
	step_end

VerdanturfTown_Movement_WalkRight2:
	walk_right
	walk_right
	step_end

VerdanturfTown_EventScript_Twin::
	goto_if_set FLAG_TEMP_7, VerdanturfTown_EventScript_MochiMochi
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	goto_if_set FLAG_TEMP_7, VerdanturfTown_EventScript_MochiMochi
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	goto_if_set FLAG_TEMP_7, VerdanturfTown_EventScript_MochiMochi
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	goto_if_set FLAG_TEMP_7, VerdanturfTown_EventScript_MochiMochi
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "My papa told me.\p"
	.string "He says this tunnel is full of\n"
	.string "timid POKéMON.\p"
	.string "They get all scared of loud noise and\n"
	.string "make a big uproar.\p"
	.string "So they had to stop the big tunnel\n"
	.string "project.\p"
	.string "But there's one man. He's trying to dig\n"
	.string "the tunnel by himself!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "There was a man who dug a tunnel for\n"
	.string "a lady he loved.\p"
	.string "I don't really get it, but hey!$"

VerdanturfTown_Text_AirCleanHere:
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "My POKéMON and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my BATTLE TENT\n"
	.string "debut in this town.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Did you see the cave next to the\n"
	.string "POKéMON MART?\p"
	.string "There's a guy in there who's trying to\n"
	.string "bust up boulders so he can bust out\l"
	.string "through to the other side.\p"
	.string "It'd be great if we could go through…\n"
	.string "It'll make it easy to visit RUSTBORO.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "That cave next to the POKéMON MART\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new DEVON products in RUSTBORO now.$"

VerdanturfTown_Text_TownSign:
	.string "VERDANTURF TOWN\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"

VerdanturfTown_Text_WandasHouse:
	.string "WANDA'S HOUSE$"

VerdanturfTown_Text_BattleTentSign:
	.string "BATTLE TENT VERDANTURF SITE\n"
	.string "“Feast Your Eyes on Battles!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL\n"
	.string "“Linking RUSTBORO and VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

VerdanturfTown_Text_Mochi:
	.string "Mochi! Mochi!\n"
	.string "Mochi! Mochi!$"

VerdanturfTown_Text_GetBetter:
	.string "Let's hope they get better soon…$"
