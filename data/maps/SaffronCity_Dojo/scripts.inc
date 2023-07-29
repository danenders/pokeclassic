.set LOCALID_MASTER, 1

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
	msgbox SaffronCity_Dojo_Text_IAmTheOffenseMaster
	goto_if_set FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_TrainWithMyPupils
	goto_if_eq VAR_DOJO_OFFENSE, 3, SaffronCity_Dojo_GetHitmonchan
	msgbox SaffronCity_Dojo_Text_DefeatThemAll
	release
	end

SaffronCity_Dojo_Text_IAmTheOffenseMaster::
	.string "I am the Offense Master.\p"
	.string "My pupils have mastered the art\n"
	.string "offense, and their Pokémon all\l"
	.string "reflect that.$"

SaffronCity_Dojo_Text_DefeatThemAll::
	.string "If you can defeat all my pupils,\n"
	.string "I will reward you with a special\l"
	.string "Pokémon!$"

SaffronCity_Dojo_TrainWithMyPupils::
	msgbox SaffronCity_Dojo_Text_TrainWithMyPupilsOffense
	release
	end

SaffronCity_Dojo_Text_TrainWithMyPupilsOffense::
	.string "If you train with my pupils, you\n"
	.string "too can master the art of Offense.\p"
	.string "You may spar with them every day.\n"
	.string "But they do need to rest.\p"
	.string "Staying hydrated is important for\n"
	.string "training.$"

SaffronCity_Dojo_GetHitmonchan::
	lock
	faceplayer
	msgbox SaffronCityDojo_Text_ProvedYourselfOffensive
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	givemon SPECIES_HITMONCHAN, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_HitmonchanParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_HitmonchanPC
	goto_if_eq VAR_RESULT, 2, SaffronCity_Dojo_EventScript_NoRoomForPokemon
	end

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
	release
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
	msgbox SaffronCity_Dojo_Text_IAmTheDefenseMaster
	goto_if_set FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_TrainWithMyPupilsDefense
	goto_if_eq VAR_DOJO_DEFENSE, 3, SaffronCity_Dojo_GetHitmonlee
	msgbox SaffronCity_Dojo_Text_DefeatThemAll
	release
	end

SaffronCity_Dojo_Text_IAmTheDefenseMaster::
	.string "I am the Defense Master.\p"
	.string "My pupils have mastered the art\n"
	.string "defense, and their Pokémon all\l"
	.string "reflect that.$"

SaffronCity_Dojo_TrainWithMyPupilsDefense::
	msgbox SaffronCity_Dojo_Text_TrainWithMyPupilsDefense
	release
	end

SaffronCity_Dojo_Text_TrainWithMyPupilsDefense::
	.string "If you train with my pupils, you\n"
	.string "too can master the art of Defense.\p"
	.string "You may spar with them every day.\n"
	.string "But they do need to rest.\p"
	.string "Staying hydrated is important for\n"
	.string "training as well.$"

SaffronCity_Dojo_GetHitmonlee::
	lock
	faceplayer
	msgbox SaffronCityDojo_Text_ProvedYourselfDefensive
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	givemon SPECIES_HITMONLEE, 25, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_HitmonleeParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_HitmonleePC
	goto_if_eq VAR_RESULT, 2, SaffronCity_Dojo_EventScript_NoRoomForPokemon
	end

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
	release
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

SaffronCity_Dojo_EventScript_AttackPupil::
	goto_if_set FLAG_DOJO_ATTACK, SaffronCity_Dojo_EventScript_AttackPupilThirsty
	faceplayer
	msgbox SaffronCity_Dojo_Text_AttackPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_ATTACK, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledAttack
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledAttack::
	setflag FLAG_DOJO_ATTACK
	call_if_unset FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_OffenseCounter
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_DefensePupil::
	goto_if_set FLAG_DOJO_DEFENSE, SaffronCity_Dojo_EventScript_DefensePupilThirsty
	faceplayer
	msgbox SaffronCity_Dojo_Text_DefensePupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_DEFENSE, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledDefense
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledDefense::
	setflag FLAG_DOJO_DEFENSE
	call_if_unset FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_DefenseCounter
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpAttackPupil::
	goto_if_set FLAG_DOJO_SPATTACK, SaffronCity_Dojo_EventScript_SpAttackPupilThirsty
	faceplayer
	msgbox SaffronCity_Dojo_Text_SpAttackPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPATTACK, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSPAttack
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSPAttack::
	setflag FLAG_DOJO_SPATTACK
	call_if_unset FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_OffenseCounter
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpDefensePupil::
	goto_if_set FLAG_DOJO_SPDEFENSE, SaffronCity_Dojo_EventScript_DefensePupilThirsty
	faceplayer
	msgbox SaffronCity_Dojo_Text_SpDefensePupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPDEFENSE, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSPDefense
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSPDefense::
	setflag FLAG_DOJO_SPDEFENSE
	call_if_unset FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_DefenseCounter
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_SpeedPupil::
	goto_if_set FLAG_DOJO_SPEED, SaffronCity_Dojo_EventScript_SpeedPupilThirsty
	faceplayer
	msgbox SaffronCity_Dojo_Text_SpeedPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_SPEED, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledSpeed
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledSpeed::
	setflag FLAG_DOJO_SPEED
	call_if_unset FLAG_RECEIVED_HITMONCHAN, SaffronCity_Dojo_OffenseCounter
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_HpPupil::
	goto_if_set FLAG_DOJO_HP, SaffronCity_Dojo_EventScript_HpPupilThirsty
	faceplayer
	msgbox SaffronCity_Dojo_Text_HpPupil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_BattleLater
	trainerbattle_single SPARRING_PARTNER_HP, SaffronCity_Dojo_Text_PupilIntro, SaffronCity_Dojo_Text_PupilDefeat, SaffronCity_Dojo_BattledHP
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_BattledHP::
	setflag FLAG_DOJO_HP
	call_if_unset FLAG_RECEIVED_HITMONLEE, SaffronCity_Dojo_DefenseCounter
	msgbox SaffronCity_Dojo_Text_AGoodWorkout, MSGBOX_AUTOCLOSE
	end


SaffronCity_Dojo_OffenseCounter::
	addvar VAR_DOJO_OFFENSE, 1
	return

SaffronCity_Dojo_DefenseCounter::
	addvar VAR_DOJO_DEFENSE, 1
	return

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

SaffronCity_Dojo_EventScript_AttackPupilThirsty::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_SureAmThirsty, MSGBOX_DEFAULT
	checkitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_CouldUseADrink
	msgbox SaffronCity_Dojo_Text_CanIHaveThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_CouldUseADrink
	call SaffronCity_Dojo_GaveWater
	clearflag FLAG_DOJO_ATTACK
	cleartrainerflag SPARRING_PARTNER_ATTACK
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_DefensePupilThirsty::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_SureAmThirsty, MSGBOX_DEFAULT
	checkitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_CouldUseADrink
	msgbox SaffronCity_Dojo_Text_CanIHaveThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_CouldUseADrink
	call SaffronCity_Dojo_GaveWater
	clearflag FLAG_DOJO_DEFENSE
	cleartrainerflag SPARRING_PARTNER_DEFENSE
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpAttackPupilThirsty::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_SureAmThirsty, MSGBOX_DEFAULT
	checkitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_CouldUseADrink
	msgbox SaffronCity_Dojo_Text_CanIHaveThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_CouldUseADrink
	call SaffronCity_Dojo_GaveWater
	clearflag FLAG_DOJO_SPATTACK
	cleartrainerflag SPARRING_PARTNER_SPATTACK
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpDefensePupilThirsty::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_SureAmThirsty, MSGBOX_DEFAULT
	checkitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_CouldUseADrink
	msgbox SaffronCity_Dojo_Text_CanIHaveThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_CouldUseADrink
	call SaffronCity_Dojo_GaveWater
	clearflag FLAG_DOJO_SPDEFENSE
	cleartrainerflag SPARRING_PARTNER_SPDEFENSE
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_SpeedPupilThirsty::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_SureAmThirsty, MSGBOX_DEFAULT
	checkitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_CouldUseADrink
	msgbox SaffronCity_Dojo_Text_CanIHaveThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_CouldUseADrink
	call SaffronCity_Dojo_GaveWater
	clearflag FLAG_DOJO_SPEED
	cleartrainerflag SPARRING_PARTNER_SPEED
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_HpPupilThirsty::
	lock
	faceplayer
	msgbox SaffronCity_Dojo_Text_SureAmThirsty, MSGBOX_DEFAULT
	checkitem ITEM_FRESH_WATER
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_CouldUseADrink
	msgbox SaffronCity_Dojo_Text_CanIHaveThat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_CouldUseADrink
	call SaffronCity_Dojo_GaveWater
	clearflag FLAG_DOJO_HP
	cleartrainerflag SPARRING_PARTNER_HP
	msgbox SaffronCity_Dojo_Text_HitsThatSpot, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_GaveWater::
	playse MUS_RG_HEAL
	waitse
	removeitem ITEM_FRESH_WATER
	return

SaffronCity_Dojo_EventScript_CouldUseADrink::
	msgbox SaffronCity_Dojo_EventScript_CouldUseADrink, MSGBOX_DEFAULT
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

SaffronCity_Dojo_KarateMaster::
	lock
	goto_if_eq FLAG_RECEIVED_BLACK_BELT, SaffronCity_Dojo_MustTrainMore
	msgbox SaffronCity_Dojo_Text_TopPupil
	goto_if_le VAR_DOJO_OFFENSE, 3, SaffronCity_Dojo_DefeatOthers
	goto_if_le VAR_DOJO_DEFENSE, 3, SaffronCity_Dojo_DefeatOthers
	playse SE_PIN
	applymovement LOCALID_MASTER, Common_Movement_ExclamationMark
	waitse
	waitmovement 1
	msgbox SaffronCity_Dojo_Text_WorthyChallenger, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_RefuseChallenge
	trainerbattle_single SAFFRON_DOJO_MASTER, SaffronCity_Dojo_Text_MasterIntro, SaffronCity_Dojo_Text_MasterDefeat, SaffronCity_Dojo_GetExpertBelt
	end

SaffronCity_Dojo_Text_MasterIntro::
	.string "Fight!$"

SaffronCity_Dojo_Text_MasterDefeat::
	.string "What! I was defeated?$"

SaffronCity_Dojo_GetExpertBelt::
	msgbox SaffronCity_Dojo_Text_MustContinueTraining
	giveitem ITEM_EXPERT_BELT
	setflag FLAG_GOT_EXPERT_BELT
	msgbox SaffronCity_Dojo_Text_MustTrain
	release
	end

SaffronCity_Dojo_Text_MustContinueTraining::
	.string "To recognize your victory over\n"
	.string "the members of this Dojo, please\l"
	.string "accept this Expert Belt.$"

SaffronCity_Dojo_MustTrainMore::
	msgbox SaffronCity_Dojo_Text_MustTrain
	release
	end

SaffronCity_Dojo_Text_MustTrain::
	.string "You have surpassed me.\n"
	.string "I will continue my training!$"

SaffronCity_Dojo_Text_TopPupil::
	.string "I have learned from both the\n"
	.string "Offense and Defense Masters.\p"
	.string "I am their top pupil!$"

SaffronCity_Dojo_Text_WorthyChallenger::
	.string "You have defeated the other pupils!\n"
	.string "This means you are a worthy opponent.\p"
	.string "So, do you wish to challenge me?$"

SaffronCity_Dojo_DefeatOthers::
	msgbox SaffronCity_Dojo_Text_MustDefeatTheOthers
	release
	end

SaffronCity_Dojo_Text_MustDefeatTheOthers::
	.string "Prove you are worthy enough to\n"
	.string "challenge me by defeating the\l"
	.string "pupils of this Dojo.\p"
	.string "Until you master Offense and Defense,\n"
	.string "I will not fight you.$"

SaffronCity_Dojo_RefuseChallenge::
	msgbox SaffronCity_Dojo_Text_SoBeIt
	release
	end

SaffronCity_Dojo_Text_SoBeIt::
	.string "So be it.$"
