StreamOfThought_MapScripts::
	.byte 0

StreamOfThought_HideName::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	end

StreamOfThought_ShowName::
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	end

StreamOfThought_EventScript_TrainerTipsEscapeRope::
	msgbox StreamOfThought_Text_TrainerTipsEscapeRope, MSGBOX_SIGN
	end

StreamOfThought_Text_TrainerTipsEscapeRope:
	.string "TRAINER TIPS\p"
	.string "If you're ever feeling lost, you can\n"
	.string "always ESCAPE back to your start.$"
