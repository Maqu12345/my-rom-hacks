RouteN2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RouteN2_OnLoad
	.byte 0

RouteN2_OnLoad:
	goto_if_lt VAR_DREAM_WORLD_STATE, 6, RouteN2_EventScript_ClosePortals
	end

RouteN2_EventScript_ClosePortals::
	setmetatile 25, 29, METATILE_General_BeachSand_Center, FALSE
	end

RouteN2_EventScript_WarriorSecret::
	msgbox RouteN2_Text_WarriorSecret, MSGBOX_SIGN
	end

RouteN2_EventScript_Girl::
	goto_if_set FLAG_CLEAR_AMULET_OBTAINED, RouteN2_EventScript_FoundLonelyRock
	msgbox RouteN2_Text_LonelyRock, MSGBOX_NPC
	end

RouteN2_EventScript_FoundLonelyRock::
	msgbox RouteN2_Text_FoundLonelyRock, MSGBOX_NPC
	end

RouteN2_Text_WarriorSecret:
	.string "WARRIOR SECRET\n"
	.string "{RIGHT_ARROW}{UP_ARROW}{UP_ARROW}{RIGHT_ARROW}{LEFT_ARROW}{UP_ARROW}$" @ RUURLU

RouteN2_Text_LonelyRock:
	.string "There is another…\p"
	.string "Find the lonely rock…\p"
	.string "Won't you dance with it for me?\n"
	.string "Follow my lead!$"

RouteN2_Text_FoundLonelyRock:
	.string "The amulet is proof of your deed…\n"
	.string "Keep it…$"
