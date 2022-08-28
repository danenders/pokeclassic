Route4_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
	.byte 0

Route4_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_4
	end
