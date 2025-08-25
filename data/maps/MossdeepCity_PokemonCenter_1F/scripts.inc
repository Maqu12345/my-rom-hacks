MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MOSSDEEP_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_HyperTrain::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_6, MossdeepCity_PokemonCenter_1F_EventScript_ExplainHyperTraining
	checkitem ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_PokemonCenter_1F_EventScript_ComeBackWithBottleCap
	msgbox MossdeepCity_PokemonCenter_1F_Text_WhichPokemon, MSGBOX_DEFAULT
	waitmessage
	goto MossdeepCity_PokemonCenter_1F_EventScript_ChooseMon
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_ChooseMon::
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, MossdeepCity_PokemonCenter_1F_EventScript_CheckValidity
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MossdeepCity_PokemonCenter_1F_EventScript_ComeBackWithBottleCap
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_ExplainHyperTraining::
	msgbox MossdeepCity_PokemonCenter_1F_Text_ICanMakePokemonStronger, MSGBOX_DEFAULT
	setflag FLAG_TEMP_6
	return

MossdeepCity_PokemonCenter_1F_EventScript_ComeBackWithBottleCap::
	msgbox MossdeepCity_PokemonCenter_1F_Text_ComeBackLater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_CheckValidity::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, MossdeepCity_PokemonCenter_1F_EventScript_ShowEggToTrainer
	canhypertrain STAT_HP, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_1F_EventScript_HyperTrainPartyMon
	canhypertrain STAT_ATK, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_1F_EventScript_HyperTrainPartyMon
	canhypertrain STAT_DEF, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_1F_EventScript_HyperTrainPartyMon
	canhypertrain STAT_SPEED, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_1F_EventScript_HyperTrainPartyMon
	canhypertrain STAT_SPATK, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_1F_EventScript_HyperTrainPartyMon
	canhypertrain STAT_SPDEF, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_1F_EventScript_HyperTrainPartyMon
	msgbox MossdeepCity_PokemonCenter_1F_Text_AlreadyPerfect, MSGBOX_DEFAULT
	waitmessage
	goto MossdeepCity_PokemonCenter_1F_EventScript_ChooseMon
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_ShowEggToTrainer::
	msgbox MossdeepCity_PokemonCenter_1F_Text_ICantTrainEggs, MSGBOX_DEFAULT
	waitmessage
	goto MossdeepCity_PokemonCenter_1F_EventScript_ChooseMon
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_HyperTrainPartyMon::
	msgbox MossdeepCity_PokemonCenter_1F_Text_VeryWell, MSGBOX_DEFAULT
	closemessage
	hypertrain STAT_HP, VAR_0x8004
	hypertrain STAT_ATK, VAR_0x8004
	hypertrain STAT_DEF, VAR_0x8004
	hypertrain STAT_SPEED, VAR_0x8004
	hypertrain STAT_SPATK, VAR_0x8004
	hypertrain STAT_SPDEF, VAR_0x8004
	playfanfare FANFARE_EVOLVED
	waitfanfare
	setvar VAR_0x8004, ITEM_GOLD_BOTTLE_CAP
	call Common_EventScript_PlayerHandedOverTheItem
	goto MossdeepCity_PokemonCenter_1F_EventScript_ComeBackWithBottleCap
	release
	end

MossdeepCity_PokemonCenter_1F_Text_ICanMakePokemonStronger:
	.string "Have you ever noticed that some\n"
	.string "POKéMON are stronger or weaker,\l"
	.string "even without training?\p"
	.string "I know a hidden technique, called\n"
	.string "HYPER TRAINING, that can bring out\l"
	.string "the full potential of POKéMON.\p"
	.string "I'm a bit of a collector, so if\n"
	.string "you give me a BOTTLE CAP, I can\l"
	.string "HYPER TRAIN one of your POKéMON.$"

MossdeepCity_PokemonCenter_1F_Text_ComeBackLater:
	.string "Come to me with a BOTTLE CAP if\n"
	.string "you're in need of my services.$"

MossdeepCity_PokemonCenter_1F_Text_WhichPokemon:
	.string "Yes! That's a GOLD BOTTLE CAP!\p"
	.string "Which POKéMON should be HYPER TRAINED?$"

MossdeepCity_PokemonCenter_1F_Text_ICantTrainEggs:
	.string "I'm not a miracle worker. How would\n"
	.string "you ever train an egg?$"

MossdeepCity_PokemonCenter_1F_Text_AlreadyPerfect:
	.string "That POKéMON is already fully capable.\n"
	.string "I can't train it further.$"

MossdeepCity_PokemonCenter_1F_Text_VeryWell:
	.string "Very well!\p"
	.string "Witness my technique!$"

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
	.string "The GYM LEADERS in this town are\n"
	.string "a formidable duo.\p"
	.string "Their combination attacks are, like,\n"
	.string "excellent and wow!$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves:
	.string "Depending on the special abilities of\n"
	.string "POKéMON, some moves might change\l"
	.string "or not work at all.$"

