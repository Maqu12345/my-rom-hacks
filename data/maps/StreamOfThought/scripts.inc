StreamOfThought_MapScripts::
	.byte 0

StreamOfThought_HideName::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	end

StreamOfThought_ShowName::
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	end
