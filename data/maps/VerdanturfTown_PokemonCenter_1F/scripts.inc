VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_VERDANTURF_NPC_TRADE_COMPLETED, VerdanturfTown_PokemonCenter_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SANDSHREW
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox VerdanturfTown_PokemonCenter_1F_Text_WillYouTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VerdanturfTown_PokemonCenter_1F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, VerdanturfTown_PokemonCenter_1F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, VerdanturfTown_PokemonCenter_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox VerdanturfTown_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_VERDANTURF_NPC_TRADE_COMPLETED
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox VerdanturfTown_PokemonCenter_1F_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_TradeCompleted::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_MuchNicerPokemon, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_Text_WillYouTrade:
	.string "Will you bring me one of the {STR_VAR_1}\n"
	.string "living in this region?\p"
	.string "I'll give you a cool, white {STR_VAR_2}\n"
	.string "from my home region for it.$"

VerdanturfTown_PokemonCenter_1F_Text_PleaseBeGoodToMyPokemon:
	.string "I can't wait to show this off\n"
	.string "to my friends.$"

VerdanturfTown_PokemonCenter_1F_Text_DoesntLookLikeMonToMe:
	.string "No, that's not right.$"

VerdanturfTown_PokemonCenter_1F_Text_YouDontWantToThatsOkay:
	.string "Oh please, I really want a {STR_VAR_1}…$"

VerdanturfTown_PokemonCenter_1F_Text_MuchNicerPokemon:
	.string "SANDSHREW's scales are so rough…$"

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "You can't consider yourself a real\n"
	.string "TRAINER if you don't have faith\l"
	.string "in your POKéMON.\p"
	.string "Only those people who can believe\n"
	.string "in their battling POKéMON can win\l"
	.string "through to the very end.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "The reason why anyone would visit\n"
	.string "VERDANTURF…\p"
	.string "It's the BATTLE TENT. It goes without\n"
	.string "saying.\p"
	.string "Or is there somebody here that you\n"
	.string "came to see?$"

