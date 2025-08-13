LilycoveCity_House2_MapScripts::
	.byte 0

LilycoveCity_House2_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_REST, LilycoveCity_House2_EventScript_ReceivedRest
	msgbox LilycoveCity_House2_Text_NotAwakeYetHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_REST
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_EventScript_ReceivedRest::
	msgbox LilycoveCity_House2_Text_SleepIsEssential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SLEEP_TALK, LilycoveCity_House2_EventScript_ReceivedSleepTalk
	msgbox LilycoveCity_House2_Text_BadSleep, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLEEP_TALK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLEEP_TALK
	msgbox LilycoveCity_House2_Text_Snoring, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_EventScript_ReceivedSleepTalk::
	msgbox LilycoveCity_House2_Text_Snoring, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_Text_NotAwakeYetHaveThis:
	.string "Huh? What? What's that?\p"
	.string "I'm not near awake yet…\n"
	.string "You can have this…$"

LilycoveCity_House2_Text_SleepIsEssential:
	.string "Yawn…\p"
	.string "Sleep is essential for good health…\n"
	.string "Sleep and regain health…$"

LilycoveCity_House2_Text_BadSleep:
	.string "Huh? Yeah? Pardon?\p"
	.string "No, I swear I'm awake…\n"
	.string "I'm fine… Here, take this…$"

LilycoveCity_House2_Text_Snoring:
	.string "Zzz…\p"
	.string "Zzz…\p"
	.string "Moves… While sleeping…\p"
	.string "Zzz…$"
