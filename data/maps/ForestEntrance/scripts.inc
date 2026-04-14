ForestEntrance_MapScripts::
	@map_script MAP_SCRIPT_ON_TRANSITION, ForestEntrance_OnTransition
	.byte 0

ForestEntrance_OnTransition::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	end

ForestEntrance_EventScript_SecretSign::
	msgbox ForestEntrance_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

ForestEntrance_Text_PokemonFanClubSign:
	.string "Do you know the secret?$"
