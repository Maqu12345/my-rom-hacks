AchromaRuins_MapScripts::
	.byte 0

AchromaRuins_EventScript_Man1::
	msgbox AchromaRuins_Text_Statues, MSGBOX_NPC
	end

AchromaRuins_EventScript_Man2::
	msgbox AchromaRuins_Text_SecretBehind, MSGBOX_NPC
	end

AchromaRuins_EventScript_Man3::
	msgbox AchromaRuins_Text_TrialBelow, MSGBOX_NPC
	end

AchromaRuins_EventScript_Man4::
	msgbox AchromaRuins_Text_MastersBrothers, MSGBOX_NPC
	end

AchromaRuins_Text_Statues:
	.string "These piles of rubble used to be large\n"
	.string "stone statues of some legendary POKéMON.\p"
	.string "Allegedly.$"

AchromaRuins_Text_SecretBehind:
	.string "There's graffiti carved into the back\n"
	.string "outside of the ruins. Something secret.\p"
	.string "Allegedly.$"

AchromaRuins_Text_TrialBelow:
	.string "The MASTER lives below. To meet him\n"
	.string "you must complete some kind of trial.\p"
	.string "Even if you succeed, he may reject you\n"
	.string "if he doesn't believe you are worthy.\p"
	.string "Allegedly.$"

AchromaRuins_Text_MastersBrothers:
	.string "The teachers up above are the MASTER's\n"
	.string "younger brothers.\p"
	.string "They provide some kind of service\n"
	.string "but no one understands what it is.\p"
	.string "Allegedly.$"

