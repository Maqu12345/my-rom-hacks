RouteN1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RouteN1_OnTransition
	.byte 0

RouteN1_OnTransition:
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	end

RouteN1_EventScript_TrainerTipsHiddenAbilities::
	msgbox RouteN1_Text_TrainerTipsHiddenAbilities, MSGBOX_SIGN
	end

RouteN1_EventScript_Boy::
	msgbox RouteN1_Text_Dreamer, MSGBOX_NPC
	end

RouteN1_Text_TrainerTipsHiddenAbilities:
	.string "TRAINER TIPS\p"
	.string "POKéMON caught in the DREAM WORLD\n"
	.string "have rare abilities.$"

RouteN1_Text_Dreamer:
	.string "A DREAMER has arrived!\n"
	.string "A DREAMER has arrived!\p"
	.string "Are you the DREAMER?$"
