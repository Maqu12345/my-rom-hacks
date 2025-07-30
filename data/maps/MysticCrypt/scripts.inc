MysticCrypt_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MysticCrypt_OnResume
	map_script MAP_SCRIPT_ON_LOAD, MysticCrypt_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MysticCrypt_OnTransition
	.byte 0

MysticCrypt_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MysticCrypt_EventScript_TryRemoveRegidrago
	end

MysticCrypt_EventScript_TryRemoveRegidrago::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MysticCrypt_OnLoad:
	call_if_unset FLAG_SYS_REGIDRAGO_PUZZLE_COMPLETED, MysticCrypt_EventScript_HideRegiEntrance
	end

MysticCrypt_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

MysticCrypt_OnTransition:
	setflag FLAG_LANDMARK_MYSTIC_CRYPT
	call MysticCrypt_EventScript_ClearMoves
	call_if_unset FLAG_DEFEATED_REGIDRAGO, MysticCrypt_EventScript_ShowRegidrago
	end

MysticCrypt_EventScript_ShowRegidrago::
	clearflag FLAG_HIDE_REGIDRAGO
	return

MysticCrypt_EventScript_OpenRegiEntrance::
	waitbuttonpress
	closebraillemessage
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_SYS_REGIDRAGO_PUZZLE_COMPLETED
	releaseall
	end

MysticCrypt_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_REGIDRAGO_PUZZLE_COMPLETED, MysticCrypt_EventScript_BigHoleInWall
	braillemessage MysticCrypt_Braille_DragonMoves
	call MysticCrypt_EventScript_CheckDragonMoves
	goto_if_ge VAR_REGIDRAGO_MOVES, 2, MysticCrypt_EventScript_OpenRegiEntrance
	goto MysticCrypt_EventScript_CloseBrailleMsg
	end

MysticCrypt_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

MysticCrypt_EventScript_CaveEntranceSide::
	lockall
	braillemessage MysticCrypt_Braille_DragonMoves
	goto_if_set FLAG_SYS_REGIDRAGO_PUZZLE_COMPLETED, MysticCrypt_EventScript_CloseBrailleMsg
	call MysticCrypt_EventScript_CheckDragonMoves
	goto_if_ge VAR_REGIDRAGO_MOVES, 2, MysticCrypt_EventScript_OpenRegiEntrance
	goto MysticCrypt_EventScript_CloseBrailleMsg
	end

MysticCrypt_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end

MysticCrypt_EventScript_ClearMoves::
	setvar VAR_REGIDRAGO_MOVES, 0
	return

MysticCrypt_EventScript_CheckDragonMoves::
	call MysticCrypt_EventScript_ClearMoves
	checkpartymove MOVE_DRAGON_RAGE
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_BREATH
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_CLAW
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_DANCE
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_PULSE
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_RUSH
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_TAIL
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_ASCENT
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_HAMMER
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_DARTS
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRAGON_ENERGY
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	checkpartymove MOVE_DRACO_METEOR
	call_if_ne VAR_RESULT, PARTY_SIZE, MysticCrypt_EventScript_VarAddOne
	return

MysticCrypt_EventScript_VarAddOne::
	addvar VAR_REGIDRAGO_MOVES, 1
	return

MysticCrypt_EventScript_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MysticCrypt_EventScript_DefeatedRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MysticCrypt_EventScript_RanFromRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MysticCrypt_EventScript_RanFromRegidrago
	setflag FLAG_DEFEATED_REGIDRAGO
	release
	end

MysticCrypt_EventScript_DefeatedRegidrago::
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

MysticCrypt_EventScript_RanFromRegidrago::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end
