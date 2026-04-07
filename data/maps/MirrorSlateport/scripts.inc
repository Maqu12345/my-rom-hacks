MirrorSlateport_MapScripts::
	.byte 0

MirrorSlateport_EventScript_ShowPokemartSign::
	msgbox MirrorSlateport_Text_PokemartSign, MSGBOX_SIGN
	end

MirrorSlateport_EventScript_ShowPokemonCenterSign::
	msgbox MirrorSlateport_Text_PokemonCenterSign, MSGBOX_SIGN
	end

MirrorSlateport_EventScript_MarketSecretSign::
	msgbox MirrorSlateport_Text_MarketSecretSign, MSGBOX_SIGN
	end

MirrorSlateport_EventScript_BattleTentSign::
	msgbox MirrorSlateport_Text_BattleTentSign, MSGBOX_SIGN
	end

MirrorSlateport_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, MirrorSlateport_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, MirrorSlateport_EventScript_SternsShipyardNearsCompletion
	msgbox MirrorSlateport_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

MirrorSlateport_EventScript_SternsShipyardNearsCompletion::
	msgbox MirrorSlateport_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

MirrorSlateport_EventScript_SternsShipyardFerryComplete::
	msgbox MirrorSlateport_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

MirrorSlateport_EventScript_PokemonFanClubSign::
	msgbox MirrorSlateport_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

MirrorSlateport_EventScript_OceanicMuseumSign::
	msgbox MirrorSlateport_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

MirrorSlateport_EventScript_CitySign::
	msgbox MirrorSlateport_Text_CitySign, MSGBOX_SIGN
	end

MirrorSlateport_EventScript_MarketSign::
	msgbox MirrorSlateport_Text_MarketSign, MSGBOX_SIGN
	end

MirrorSlateport_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, MirrorSlateport_EventScript_HarborSignFerryComplete
	msgbox MirrorSlateport_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

MirrorSlateport_EventScript_HarborSignFerryComplete::
	msgbox MirrorSlateport_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

MirrorSlateport_EventScript_NameRatersHouseSign::
	msgbox MirrorSlateport_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

MirrorSlateport_Text_PokemartSign:
	.string "“!ecneinevnoc ruoy rof smeti detceleS”\n"
	.string "TRAM NOMéKOP$"

MirrorSlateport_Text_PokemonCenterSign:
	.string "“!srentrap derit ruoy etanevujeR”\n"
	.string "RETNEC NOMéKOP$"

MirrorSlateport_Text_MarketSecretSign:
	.string "REMEMBER TO ADD SECRET HERE$"

MirrorSlateport_Text_BattleTentSign:
	.string "ETIS TROPETALS TNET ELTTAB\n"
	.string "“!NOMéKOP etamitlu ehT !ti dniF”$"

MirrorSlateport_Text_SternsShipyardWantedSign:
	.string "DRAYPIHS S'NRETS\p"
	.string "gnilias fo elbapac rolias A :detnaW”\n"
	.string "“.stnerruc lla ni$"

MirrorSlateport_Text_SternsShipyardNearsCompletion:
	.string "DRAYPIHS S'NRETS\p"
	.string "sraen LADIT .S.S yrref ehT”\n"
	.string "fo strop eht gnivres rof noitelpmoc\l"
	.string "“.EVOCYLIL dna TROPETALS$"

MirrorSlateport_Text_SternsShipyardFerryComplete:
	.string "DRAYPIHS S'NRETS\p"
	.string "EVOCYLIL-TROPETALS eht fo gnidraoB”\n"
	.string "eht ta deldnah si LADIT .S.S yrref\l"
	.string "“.ROBRAH$"

MirrorSlateport_Text_PokemonFanClubSign:
	.string "BULC NAF NOMéKOP\n"
	.string "“!NOMéKOP fo snaf lla gnillaC”$"

MirrorSlateport_Text_OceanicMuseumSign:
	.string "sniatsus aes sseldne ehT”\n"
	.string "“.efil lla\p"
	.string "MUESUM CINAECO$"

MirrorSlateport_Text_CitySign:
	.string "YTIC TROPETALS\p"
	.string "NOMéKOP dna elpoep erehw trop ehT”\n"
	.string "“.shtap ssorc$"

MirrorSlateport_Text_MarketSign:
	.string "TEKRAM TROPETALS\n"
	.string "“!esle erehwon dnuof smeti euqinU”$"

MirrorSlateport_Text_HarborFerryUnderConstruction:
	.string "ROBRAH TROPETALS\p"
	.string "rednu si LADIT .S.S yrref ehT”\n"
	.string "“.DRAYPIHS eht ni noitcurtsnoc\p"
	.string "nigeb ot deludehcs si ecivreS”\n"
	.string "“.yltrohs$"

MirrorSlateport_Text_HarborSign:
	.string "ROBRAH TROPETALS\p"
	.string "no esiurc lufthgiled a yojnE”\n"
	.string "“.LADIT .S.S yrref eht$"

MirrorSlateport_Text_NameRatersHouseSign:
	.string "ESUOH S'RETAR EMAN\n"
	.string "“.detar semankcin NOMéKOP”$"
