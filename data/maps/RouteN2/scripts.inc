RouteN2_MapScripts::
	.byte 0

RouteN2_EventScript_WarriorSecret::
	msgbox RouteN2_Text_WarriorSecret, MSGBOX_SIGN
	end

RouteN2_Text_WarriorSecret:
	.string "WARRIOR SECRET\n"
	.string "{RIGHT_ARROW}{UP_ARROW}{UP_ARROW}{RIGHT_ARROW}{LEFT_ARROW}{UP_ARROW}$" @ RUURLU
