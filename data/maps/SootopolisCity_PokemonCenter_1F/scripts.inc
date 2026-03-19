SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SOOTOPOLIS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_NPC_TRADE_COMPLETED, SootopolisCity_PokemonCenter_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_CORSOLA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox SootopolisCity_PokemonCenter_1F_Text_WillYouTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SootopolisCity_PokemonCenter_1F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_PokemonCenter_1F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, SootopolisCity_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox SootopolisCity_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_SOOTOPOLIS_NPC_TRADE_COMPLETED
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox SootopolisCity_PokemonCenter_1F_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox SootopolisCity_PokemonCenter_1F_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_TradeCompleted::
	msgbox SootopolisCity_PokemonCenter_1F_Text_MuchNicerPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WillYouTrade:
	.string "I… I'm not ready to care for my {STR_VAR_2}.\n"
	.string "They're so sad and fragile compared to\l"
	.string "the colorful ones in these waters.\p"
	.string "Will you give me a lively {STR_VAR_1} and\n"
	.string "take my poor {STR_VAR_2} off my hands?$"

SootopolisCity_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon:
	.string "I just wasn't ready for the\n"
	.string "responsibility…$"

SootopolisCity_PokemonCenter_1F_Text_DoesntLookLikeMonToMe:
	.string "I would much prefer to have a {STR_VAR_1}.$"

SootopolisCity_PokemonCenter_1F_Text_YouDontWantToThatsOkay:
	.string "Okay. I hope someone else\n"
	.string "can come take it soon…$"

SootopolisCity_PokemonCenter_1F_Text_MuchNicerPokemon:
	.string "I just wasn't ready for the\n"
	.string "responsibility…$"

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
	.string "WALLACE is rumored to be the toughest\n"
	.string "TRAINER in the whole HOENN region.\p"
	.string "This town's GYM is led by the TRAINER\n"
	.string "who taught WALLACE.\p"
	.string "But the ELITE FOUR… They're said to be\n"
	.string "even stronger than WALLACE's mentor.\p"
	.string "How strong could they be?$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.string "Everyone in town has taken refuge\n"
	.string "and won't come out of their homes.\p"
	.string "Even I would rather not venture\n"
	.string "outside.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.string "Whenever, wherever, and whatever\n"
	.string "happens, I will always be friends with\l"
	.string "POKéMON.\p"
	.string "Because it's fun to be with POKéMON!$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.string "Aren't POKéMON our friends?\p"
	.string "Why are they going wild this way?$"

