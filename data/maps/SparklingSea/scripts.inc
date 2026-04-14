SparklingSea_MapScripts::
	.byte 0

SparklingSea_EventScript_End::
	end

SparklingSea_EventScript_Increment::
	goto_if_set FLAG_CLEAR_AMULET_OBTAINED, SparklingSea_EventScript_End
	goto_if_set FLAG_TEMP_B, SparklingSea_EventScript_End
	addvar VAR_TEMP_0, 1
	call_if_eq VAR_TEMP_0, 3, SparklingSea_EventScript_AddLoop
	goto_if_eq VAR_TEMP_B, 3, SparklingSea_EventScript_GiveClearAmulet
	end

SparklingSea_EventScript_AddLoop::
	addvar VAR_TEMP_B, 1
	setvar VAR_TEMP_0, 0
	return

SparklingSea_EventScript_Reset::
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_B, 0
	end

SparklingSea_EventScript_GiveClearAmulet::
	setflag FLAG_TEMP_B
	playse SE_M_DETECT
	dofieldeffectsparkle 10, 9, 0
	setobjectxyperm LOCALID_CLEAR_AMULET, 10, 9
	end
