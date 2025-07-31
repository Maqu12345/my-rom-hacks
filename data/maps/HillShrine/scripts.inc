HillShrine_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, HillShrine_OnResume
	map_script MAP_SCRIPT_ON_LOAD, HillShrine_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, HillShrine_OnTransition
	.byte 0

HillShrine_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, HillShrine_EventScript_TryRemoveRegieleki
	end

HillShrine_EventScript_TryRemoveRegieleki::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

HillShrine_OnLoad:
	call_if_unset FLAG_SYS_REGIELEKI_PUZZLE_COMPLETED, HillShrine_EventScript_HideRegiEntrance
	end

HillShrine_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

HillShrine_OnTransition:
	setflag FLAG_LANDMARK_HILL_SHRINE
	call_if_unset FLAG_DEFEATED_REGIELEKI, HillShrine_EventScript_ShowRegieleki
	end

HillShrine_EventScript_ShowRegieleki::
	clearflag FLAG_HIDE_REGIELEKI
	return

HillShrine_EventScript_OpenRegiEntrance::
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
	setflag FLAG_SYS_REGIELEKI_PUZZLE_COMPLETED
	releaseall
	end

HillShrine_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_REGIELEKI_PUZZLE_COMPLETED, HillShrine_EventScript_BigHoleInWall
	braillemessage HillShrine_Braille_OfferElectric
	goto HillShrine_EventScript_CheckPCItems
	end

HillShrine_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

HillShrine_EventScript_CaveEntranceSide::
	lockall
	braillemessage HillShrine_Braille_OfferElectric
	goto_if_set FLAG_SYS_REGIELEKI_PUZZLE_COMPLETED, HillShrine_EventScript_CloseBrailleMsg
	goto HillShrine_EventScript_CheckPCItems
	end

HillShrine_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end

HillShrine_EventScript_CheckPCItems::
	checkpcitem ITEM_CELL_BATTERY
	goto_if_eq VAR_RESULT, TRUE, HillShrine_EventScript_OpenRegiEntrance
	checkpcitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, TRUE, HillShrine_EventScript_OpenRegiEntrance
	checkpcitem ITEM_ELECTRIC_SEED
	goto_if_eq VAR_RESULT, TRUE, HillShrine_EventScript_OpenRegiEntrance
	checkpcitem ITEM_LIGHT_BALL
	goto_if_eq VAR_RESULT, TRUE, HillShrine_EventScript_OpenRegiEntrance
	checkpcitem ITEM_THUNDER_STONE
	goto_if_eq VAR_RESULT, TRUE, HillShrine_EventScript_OpenRegiEntrance
	goto HillShrine_EventScript_CloseBrailleMsg
	end

HillShrine_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, HillShrine_EventScript_DefeatedRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, HillShrine_EventScript_RanFromRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, HillShrine_EventScript_RanFromRegieleki
	setflag FLAG_DEFEATED_REGIELEKI
	release
	end

HillShrine_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

HillShrine_EventScript_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end
