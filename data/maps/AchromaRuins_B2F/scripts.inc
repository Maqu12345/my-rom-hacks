AchromaRuins_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, AchromaRuins_B2F_OnLoad
	.byte 0

AchromaRuins_B2F_OnLoad:
	goto_if_set FLAG_RESHIRAMS_ROOM, AchromaRuins_B2F_EventScript_SetWhiteLayout
	goto_if_set FLAG_ZEKROMS_ROOM, AchromaRuins_B2F_EventScript_SetBlackLayout
	end

AchromaRuins_B2F_EventScript_SetGreyLayout::
	setmetatile  1,  3, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1,  5, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1,  7, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1,  9, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1, 11, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1, 13, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile 13,  3, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13,  5, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13,  7, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13,  9, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13, 11, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13, 13, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile  3, 10, METATILE_NavelRock_Floor_Smooth, FALSE
	setmetatile 11, 10, METATILE_NavelRock_Floor_Smooth, FALSE
	setmetatile  4,  2, METATILE_NavelRock_WhiteRock, TRUE
	setmetatile  6,  2, METATILE_NavelRock_WhiteRock, TRUE
	setmetatile  8,  2, METATILE_NavelRock_BlackRock, TRUE
	setmetatile 10,  2, METATILE_NavelRock_BlackRock, TRUE
	clearflag FLAG_RESHIRAMS_ROOM
	clearflag FLAG_ZEKROMS_ROOM
	end

AchromaRuins_B2F_EventScript_SetWhiteLayout::
	setmetatile  1,  3, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1,  5, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1,  7, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1,  9, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1, 11, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile  1, 13, METATILE_NavelRock_RedCrystal_Left, TRUE
	setmetatile 13,  3, METATILE_NavelRock_RedCrystal_Right, TRUE
	setmetatile 13,  5, METATILE_NavelRock_RedCrystal_Right, TRUE
	setmetatile 13,  7, METATILE_NavelRock_RedCrystal_Right, TRUE
	setmetatile 13,  9, METATILE_NavelRock_RedCrystal_Right, TRUE
	setmetatile 13, 11, METATILE_NavelRock_RedCrystal_Right, TRUE
	setmetatile 13, 13, METATILE_NavelRock_RedCrystal_Right, TRUE
	setmetatile  3, 10, METATILE_NavelRock_Floor_Smooth, FALSE
	setmetatile 11, 10, METATILE_NavelRock_BlackRock, TRUE
	setmetatile  4,  2, METATILE_NavelRock_WhiteRock, TRUE
	setmetatile  6,  2, METATILE_NavelRock_WhiteRock, TRUE
	setmetatile  8,  2, METATILE_NavelRock_WhiteRock, TRUE
	setmetatile 10,  2, METATILE_NavelRock_WhiteRock, TRUE
	setflag FLAG_RESHIRAMS_ROOM
	clearflag FLAG_ZEKROMS_ROOM
	setdynamicwarp MAP_ACHROMA_RUINS_RESHIRAMS_ROOM, 0
	end

AchromaRuins_B2F_EventScript_SetBlackLayout::
	setmetatile  1,  3, METATILE_NavelRock_BlueCrystal_Left, TRUE
	setmetatile  1,  5, METATILE_NavelRock_BlueCrystal_Left, TRUE
	setmetatile  1,  7, METATILE_NavelRock_BlueCrystal_Left, TRUE
	setmetatile  1,  9, METATILE_NavelRock_BlueCrystal_Left, TRUE
	setmetatile  1, 11, METATILE_NavelRock_BlueCrystal_Left, TRUE
	setmetatile  1, 13, METATILE_NavelRock_BlueCrystal_Left, TRUE
	setmetatile 13,  3, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13,  5, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13,  7, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13,  9, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13, 11, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile 13, 13, METATILE_NavelRock_BlueCrystal_Right, TRUE
	setmetatile  3, 10, METATILE_NavelRock_WhiteRock, TRUE
	setmetatile 11, 10, METATILE_NavelRock_Floor_Smooth, FALSE
	setmetatile  4,  2, METATILE_NavelRock_BlackRock, TRUE
	setmetatile  6,  2, METATILE_NavelRock_BlackRock, TRUE
	setmetatile  8,  2, METATILE_NavelRock_BlackRock, TRUE
	setmetatile 10,  2, METATILE_NavelRock_BlackRock, TRUE
	clearflag FLAG_RESHIRAMS_ROOM
	setflag FLAG_ZEKROMS_ROOM
	setdynamicwarp MAP_ACHROMA_RUINS_ZEKROMS_ROOM, 0
	end

AchromaRuins_B2F_EventScript_TheMaster::
	goto_if_unset FLAG_DEFEATED_RESHIRAM, AchromaRuins_B2F_EventScript_TheMaster1
	goto_if_unset FLAG_DEFEATED_ZEKROM, AchromaRuins_B2F_EventScript_TheMaster1
	msgbox AchromaRuins_B2F_Text_ThereIsAnother, MSGBOX_NPC
	end

AchromaRuins_B2F_EventScript_TheMaster1::
	msgbox AchromaRuins_B2F_Text_TheMaster, MSGBOX_NPC
	end

AchromaRuins_B2F_Text_TheMaster:
	.string "You have proven yourself worthy to me.\p"
	.string "Now you must prove yourself worthy to\n"
	.string "the great powers of truth and ideals.$"

AchromaRuins_B2F_Text_ThereIsAnother:
	.string "There is another.\p"
	.string "Out there somewhere,\n"
	.string "there is another.$"
