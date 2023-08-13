.set LOCALID_BELT, 9

SaffronCity_Dojo_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_Dojo_OnTransition
	.byte 0

SaffronCity_Dojo_OnTransition::
	call_if_unset FLAG_DAILY_DOJO_RESET, SaffronCity_Dojo_Reset
	end

SaffronCity_Dojo_Reset::
	cleartrainerflag SPARRING_PARTNER_ATTACK
	clearflag FLAG_DOJO_ATTACK
	cleartrainerflag SPARRING_PARTNER_SPATTACK
	clearflag FLAG_DOJO_SPATTACK
	cleartrainerflag SPARRING_PARTNER_SPEED
	clearflag FLAG_DOJO_SPEED
	cleartrainerflag SPARRING_PARTNER_HP
	clearflag FLAG_DOJO_HP
	cleartrainerflag SPARRING_PARTNER_DEFENSE
	clearflag FLAG_DOJO_DEFENSE
	cleartrainerflag SPARRING_PARTNER_SPDEFENSE
	clearflag FLAG_DOJO_SPDEFENSE
	setflag FLAG_DAILY_DOJO_RESET
	return

SaffronCity_Dojo_OffenseMaster::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_IAmTheOffenseMaster, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_TrainWithMyPupils
	goto_if_unset FLAG_DOJO_OFFENSE_1, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_OFFENSE_2, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_OFFENSE_3, SaffronCity_Dojo_EventScript_DefeatMyPupils
	msgbox SaffronCityDojo_Text_ProvedYourselfOffensive, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	givemon SPECIES_HITMONCHAN, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_HitmonchanParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_HitmonchanPC
	goto_if_eq VAR_RESULT, 2, SaffronCity_Dojo_EventScript_NoRoomForPokemon
	end

SaffronCity_Dojo_Text_IAmTheOffenseMaster::
	.string "I am the Offense Master.\p"
	.string "My pupils have mastered the art\n"
	.string "offense, and their Pokémon all\l"
	.string "reflect that.$"

SaffronCity_Dojo_EventScript_DefeatMyPupils::
	msgbox SaffronCity_Dojo_Text_DefeatThemAll, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_DefeatThemAll::
	.string "If you can defeat all my pupils,\n"
	.string "I will reward you with a special\l"
	.string "Pokémon!$"

SaffronCity_Dojo_TrainWithMyPupils::
	msgbox SaffronCity_Dojo_Text_TrainWithMyPupilsOffense, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_TrainWithMyPupilsOffense::
	.string "If you train with my pupils, you\n"
	.string "too can master the art of Offense.\p"
	.string "You may spar with them every day.\n"
	.string "But they do need to rest.\p"
	.string "Staying hydrated is important for\n"
	.string "training.$"

SaffronCityDojo_Text_ProvedYourselfOffensive::
	.string "So, you have defeated all my pupils.\p"
	.string "I see you've proven yourself capable\n"
	.string "of surviving the strongest offense!\p"
	.string "For that, you have earned this\n"
	.string "Pokémon... Hitmonchan!$"

SaffronCity_Dojo_EventScript_HitmonchanParty::
	call SaffronCity_Dojo_EventScript_GetHitmonchan
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_GotHitmonchan
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_GotHitmonchan
	end

SaffronCity_Dojo_EventScript_GetHitmonchan::
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_EventScript_Text_EarnedHitmonchan
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_HITMONCHAN
	return

SaffronCity_Dojo_EventScript_Text_EarnedHitmonchan::
	.string "{PLAYER} mastered the art of Offense\n"
	.string "and earned the Dojo's Hitmonchan!$"

SaffronCity_Dojo_EventScript_GotHitmonchan::
	setflag FLAG_RECEIVED_HITMONCHAN
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonchanPC::
	call SaffronCity_Dojo_EventScript_GetHitmonchan
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferHitmonchan
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferHitmonchan
	end

SaffronCity_Dojo_EventScript_TransferHitmonchan::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_GotHitmonchan
	end

SaffronCity_Dojo_DefenseMaster::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_IAmTheDefenseMaster, MSGBOX_DEFAULT
	goto_if_set FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_TrainWithMyPupilsDefense
	goto_if_unset FLAG_DOJO_DEFENSE_1, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_DEFENSE_2, SaffronCity_Dojo_EventScript_DefeatMyPupils
	goto_if_unset FLAG_DOJO_DEFENSE_3, SaffronCity_Dojo_EventScript_DefeatMyPupils
	msgbox SaffronCityDojo_Text_ProvedYourselfDefensive, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	givemon SPECIES_HITMONLEE, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_HitmonleeParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_HitmonleePC
	goto_if_eq VAR_RESULT, 2, SaffronCity_Dojo_EventScript_NoRoomForPokemon
	end

SaffronCity_Dojo_Text_IAmTheDefenseMaster::
	.string "I am the Defense Master.\p"
	.string "My pupils have mastered the art\n"
	.string "defense, and their Pokémon all\l"
	.string "reflect that.$"

SaffronCity_Dojo_TrainWithMyPupilsDefense::
	msgbox SaffronCity_Dojo_Text_TrainWithMyPupilsDefense, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_TrainWithMyPupilsDefense::
	.string "If you train with my pupils, you\n"
	.string "too can master the art of Defense.\p"
	.string "You may spar with them every day.\n"
	.string "But they do need to rest.\p"
	.string "Staying hydrated is important for\n"
	.string "training as well.$"

SaffronCityDojo_Text_ProvedYourselfDefensive::
	.string "So, you have defeated all my pupils.\p"
	.string "I see you've proven yourself capable\n"
	.string "of breaking the strongest defense!\p"
	.string "For that, you have earned this\n"
	.string "Pokémon... Hitmonlee!$"

SaffronCity_Dojo_EventScript_HitmonleeParty::
	call SaffronCity_Dojo_EventScript_GetHitmonlee
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_GotHitmonlee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_GotHitmonlee
	end

SaffronCity_Dojo_EventScript_GetHitmonlee::
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_EventScript_Text_EarnedHitmonlee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_HITMONLEE
	return

SaffronCity_Dojo_EventScript_Text_EarnedHitmonlee::
	.string "{PLAYER} mastered the art of Defense\n"
	.string "and earned the Dojo's Hitmonlee!$"

SaffronCity_Dojo_EventScript_GotHitmonlee::
	setflag FLAG_RECEIVED_HITMONLEE
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleePC::
	call SaffronCity_Dojo_EventScript_GetHitmonlee
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferHitmonlee
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferHitmonlee
	end

SaffronCity_Dojo_EventScript_TransferHitmonlee::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_GotHitmonlee
	end

SaffronCity_Dojo_EventScript_NoRoomForPokemon::
	msgbox SaffronCity_Dojo_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_NoRoomForMorePokemon::
    .string "Oh! You don't have room\n"
    .string "for any more Pokémon!$"

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_FightingDojo::
    .string "Fighting Dojo$"

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_StrongOffense, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_StrongOffense::
    .string "A strong offense is\n"
    .string "the key to victory!$"

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_StrongDefense, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_StrongDefense::
    .string "A strong defense is\n"
    .string "the key to survival!$"


SaffronCity_Dojo_EventScript_FreshWater::
	msgbox SaffronCity_Dojo_Text_SureAmThirsty, MSGBOX_DEFAULT
	checkitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_CouldUseADrink
	msgbox SaffronCity_Dojo_Text_CanIHaveThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_CouldUseADrink
	playse MUS_RG_HEAL
	waitse
	removeitem ITEM_FRESH_WATER
	return

SaffronCity_Dojo_EventScript_CouldUseADrink::
	msgbox SaffronCity_Dojo_Text_CouldUseADrink, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_SureAmThirsty:
	.string "Pokémon training is exhausting!\p"
	.string "I'm going to get refreshed before\n"
	.string "I can go another round...$"

SaffronCity_Dojo_Text_CanIHaveThat:
	.string "Oh! You have some Fresh Water!\p"
	.string "Could I have some of that?$"

SaffronCity_Dojo_Text_CouldUseADrink:
	.string "I sure could use a drink...$"

SaffronCity_Dojo_Text_HitsThatSpot:
	.string "Wow, thanks!\p"
	.string "GLUG GLUG GLUG\p"
	.string "Ahhhhhhh....\p"
	.string "That really hits the spot!\p"
	.string "I feel ready for another battle!$"

SaffronCity_Dojo_EventScript_BattleLater::
	msgbox SaffronCity_Dojo_Text_BattleLater, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_PupilIntro:
	.string "Alright! I'll show you what\n"
	.string "my sensei has taught me!$"

SaffronCity_Dojo_Text_PupilDefeat:
	.string "I was no match for you.$"

SaffronCity_Dojo_Text_AGoodWorkout:
	.string "I still have a long way to go.\n"
	.string "That was quite the workout.$"

SaffronCity_Dojo_Text_AttackPupil:
	.string "I am studying the ways of the\n"
	.string "Offense Master!\p"
	.string "Physical attacks are the most\n"
	.string "powerful moves, and I will be\l"
	.string "the strongest in all of Kanto!\p"
	.string "Do you wish to challenge me?$"	

SaffronCity_Dojo_Text_DefensePupil:
	.string "I am studying the ways of the\n"
	.string "Defense Master!\p"
	.string "Physical attacks cannot even\n"
	.string "break my defense, and I will be\l"
	.string "the strongest in all of Kanto!\p"
	.string "Do you wish to challenge me?$"	

SaffronCity_Dojo_Text_SpAttackPupil:
	.string "I am studying the ways of the\n"
	.string "Offense Master!\p"
	.string "Special attacks are the most\n"
	.string "powerful moves, and I will be\l"
	.string "the strongest in all of Kanto!\p"
	.string "Do you wish to challenge me?$"

SaffronCity_Dojo_Text_SpDefensePupil:
	.string "I am studying the ways of the\n"
	.string "Defense Master!\p"
	.string "Special attacks cannot even\n"
	.string "break my defense, and I will be\l"
	.string "the strongest in all of Kanto!\p"
	.string "Do you wish to challenge me?$"	

SaffronCity_Dojo_Text_SpeedPupil:
	.string "I am studying the ways of the\n"
	.string "Offense Master!\p"
	.string "Speed is the most important\n"
	.string "factor in battle, and I will be\l"
	.string "the strongest in all of Kanto!\p"
	.string "Do you wish to challenge me?$"	

SaffronCity_Dojo_Text_HpPupil:
	.string "I am studying the ways of the\n"
	.string "Defense Master!\p"
	.string "Having more HP than your opponent\n"
	.string "is the most important factor in\l"
	.string "battle, and I will be the strongest\l"
	.string "in all of Kanto!\p"
	.string "Do you wish to challenge me?$"	
	
SaffronCity_Dojo_Text_BattleLater:
	.string "If you wish to become the best,\n"
	.string "you must work for it!$"

SaffronCity_Dojo_EventScript_AttackPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_ATTACK, SaffronCity_Dojo_EventScript_AttackPupilThirsty
	msgbox SaffronCity_Dojo_Text_AttackPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_ATTACK, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledAttack
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpAttackPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_SPATTACK, SaffronCity_Dojo_EventScript_SpAttackPupilThirsty
	msgbox SaffronCity_Dojo_Text_SpAttackPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPATTACK, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSPAttack
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpeedPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_SPEED, SaffronCity_Dojo_EventScript_SpeedPupilThirsty
	msgbox SaffronCity_Dojo_Text_SpeedPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPEED, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSpeed
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_DefensePupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_DEFENSE, SaffronCity_Dojo_EventScript_DefensePupilThirsty
	msgbox SaffronCity_Dojo_Text_DefensePupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_DEFENSE, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledDefense
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpDefensePupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_SPDEFENSE, SaffronCity_Dojo_EventScript_DefensePupilThirsty
	msgbox SaffronCity_Dojo_Text_SpDefensePupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPDEFENSE, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSPDefense
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_HpPupil::
	lock
	faceplayer
	goto_if_set FLAG_DOJO_HP, SaffronCity_Dojo_EventScript_HpPupilThirsty
	msgbox SaffronCity_Dojo_Text_HpPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_HP, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledHP
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_AttackPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_ATTACK
	cleartrainerflag SPARRING_PARTNER_ATTACK
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	goto SaffronCity_Dojo_EventScript_AttackPupil
	end

SaffronCity_Dojo_EventScript_SpAttackPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_SPATTACK
	cleartrainerflag SPARRING_PARTNER_SPATTACK
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpeedPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_SPEED
	cleartrainerflag SPARRING_PARTNER_SPEED
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_DefensePupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_DEFENSE
	cleartrainerflag SPARRING_PARTNER_DEFENSE
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpDefensePupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_SPDEFENSE
	cleartrainerflag SPARRING_PARTNER_SPDEFENSE
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_HpPupilThirsty::
	call SaffronCity_Dojo_EventScript_FreshWater
	clearflag FLAG_DOJO_HP
	cleartrainerflag SPARRING_PARTNER_HP
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_BattledAttack::
	setflag FLAG_DOJO_ATTACK
	setflag FLAG_DOJO_OFFENSE_1
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSPAttack::
	setflag FLAG_DOJO_SPATTACK
	setflag FLAG_DOJO_OFFENSE_2
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSpeed::
	setflag FLAG_DOJO_SPEED
	setflag FLAG_DOJO_OFFENSE_3
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledDefense::
	setflag FLAG_DOJO_DEFENSE
	setflag FLAG_DOJO_DEFENSE_1
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSPDefense::
	setflag FLAG_DOJO_SPDEFENSE
	setflag FLAG_DOJO_DEFENSE_2
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledHP::
	setflag FLAG_DOJO_HP
	setflag FLAG_DOJO_DEFENSE_3
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_ExpertBelt::
	msgbox SaffronCity_Dojo_Text_ExpertBelt, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_Unworthy
	goto_if_unset FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_Unworthy
	giveitem ITEM_EXPERT_BELT
	removeobject LOCALID_BELT
	release
	end

SaffronCity_Dojo_Text_ExpertBelt::
	.string "This Belt proves you are\n"
	.string "a master of Pokémon battles.$"

SaffronCity_Dojo_Unworthy::
	msgbox SaffronCity_Dojo_Text_Unworthy, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_Text_Unworthy::
	.string "You don't feel worthy of it.$"

