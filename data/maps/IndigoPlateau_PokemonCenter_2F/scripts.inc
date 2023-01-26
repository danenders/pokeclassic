IndigoPlateau_PokemonCenter_2F_MapScripts::
	.byte 0

IndigoPlateau_PokemonCenter_2F_Trainer::
	lock
	faceplayer
	msgbox IndigoPlateau_PokemonCenter_2F_NervousTrainer, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_2F_NervousTrainer::
	.string "Deep breaths...\n"
	.string "Deep breaths...\p"
	.string "I'm pretty nervous about taking on\n"
	.string "the Elite Four...$"
