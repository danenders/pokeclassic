ViridianForest_SouthEntrance_MapScripts::
	.byte 0

Route2_ViridianForest_SouthEntrance_EventScript_Woman1::
	msgbox Route2_ViridianForest_SouthEntrance_Text_ForestIsMaze, MSGBOX_NPC
	end

Route2_ViridianForest_SouthEntrance_Text_ForestIsMaze::
    .string "Are you going to Viridian Forest?\n"
    .string "It's a natural maze in there.\l"
    .string "Be careful you don't get lost.$"

Route2_ViridianForest_SouthEntrance_EventScript_Woman2::
	msgbox Route2_ViridianForest_SouthEntrance_Text_RattataHasWickedBite, MSGBOX_NPC
	end

Route2_ViridianForest_SouthEntrance_Text_RattataHasWickedBite::
    .string "Rattata may be small, but don't\n"
    .string "underestimate its wicked bite.\p"
    .string "Have you caught one already?$"
