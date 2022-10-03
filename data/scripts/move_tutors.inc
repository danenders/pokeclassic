@KANTO, Updated

MoveTutor_DoubleEdge::
	lock
	faceplayer
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DOUBLE_EDGE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DoubleEdgeDeclined
	goto MoveTutor_EventScript_DoubleEdgeTaught
	end

MoveTutor_Text_DoubleEdgeTeach::
    .string "You should be proud of yourself,\n"
    .string "having battled your way through\l"
    .string "Victory Road so courageously.\p"
    .string "In recognition of your feat,\n"
    .string "I'll teach you Double-Edge.\p"
    .string "Would you like me to teach that\n"
    .string "technique?$"

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_DoubleEdgeDeclined::
    .string "I'll teach you the technique\n"
    .string "anytime.$"

MoveTutor_Text_DoubleEdgeWhichMon::
    .string "Which Pokémon should I teach\n"
    .string "Double-Edge?$"

MoveTutor_EventScript_DoubleEdgeTaught::
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_DoubleEdgeTaught::
    .string "Keep that drive going for the\n"
    .string "Pokémon League!\p"
    .string "Take a run at them and knock 'em\n"
    .string "out!$"

MoveTutor_Metronome::
	lock
	faceplayer
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_METRONOME
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MetronomeDeclined
	goto MoveTutor_EventScript_MetronomeTaught
	end

MoveTutor_Text_MetronomeTeach::
    .string "Tch-tch-tch!\n"
    .string "I'll teach you a nifty move.\p"
    .string "Teach it to a Pokémon, and watch\n"
    .string "the fun unfold!\p"
    .string "It's a move called Metronome.\n"
    .string "Does it strike your fancy?$"

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MetronomeDeclined::
    .string "I tell you, it's a lot of fun!$"

MoveTutor_Text_MetronomeWhichMon::
    .string "Okay!\n"
    .string "Which Pokémon should I teach?$"

MoveTutor_EventScript_MetronomeTaught::
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MetronomeTaught::
    .string "Tch-tch-tch!\n"
    .string "That's the sound of a Metronome.\p"
    .string "It tweaks your Pokémon's brain into\n"
    .string "using moves it doesn't even know.$"

MoveTutor_ThunderWave::
	lock
	faceplayer
	msgbox MoveTutor_Text_ThunderWaveTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ThunderWaveDeclined
	msgbox MoveTutor_Text_ThunderWaveWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_THUNDER_WAVE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ThunderWaveDeclined
	goto MoveTutor_EventScript_ThunderWaveTaught
	end

MoveTutor_Text_ThunderWaveTeach::
    .string "Eeek!\n"
    .string "No! Stop! Help!\p"
    .string "Oh, you're not with Team Rocket.\n"
    .string "I'm sorry, I thought…\p"
    .string "Will you forgive me if I teach\n"
    .string "you the Thunder Wave technique?$"

MoveTutor_EventScript_ThunderWaveDeclined::
	msgbox MoveTutor_Text_ThunderWaveDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_ThunderWaveDeclined::
    .string "Oh…\n"
    .string "But Thunder Wave is convenient…$"

MoveTutor_Text_ThunderWaveWhichMon::
    .string "I really love Thunder Wave!\n"
    .string "Who's going to learn it?$"

MoveTutor_EventScript_ThunderWaveTaught::
	msgbox MoveTutor_Text_ThunderWaveTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_ThunderWaveTaught::
    .string "Thunder Wave causes paralysis in\n"
    .string "the target Pokémon.\p"
    .string "A paralyzed Pokémon may be unable\n"
    .string "to move in battle.\p"
    .string "It's an Electric type move, so it\n"
    .string "won't work on some Pokémon.$"

MoveTutor_Mimic::
	lock
	faceplayer
	msgbox MoveTutor_Text_MimicTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MimicDeclined
	msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MIMIC
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MimicDeclined
	goto MoveTutor_EventScript_MimicTaught
	end

MoveTutor_Text_MimicTeach::
    .string "Oh wow!\n"
    .string "A Poké Doll!\p"
    .string "For me?\n"
    .string "Thank you!\p"
    .string "You know what?\n"
    .string "I can teach the move Mimic.$"

MoveTutor_EventScript_MimicDeclined::
	msgbox MoveTutor_Text_MimicDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MimicDeclined::
    .string "Don't you like Mimic?$"

MoveTutor_Text_MimicWhichMon::
    .string "I really love Mimic!\n"
    .string "Who's going to learn it?$"

MoveTutor_EventScript_MimicTaught::
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MimicTaught::
    .string "{PLAYER}: Hi!\n"
    .string "Thanks for earlier!\p"
    .string "{PLAYER}: Pardon?\p"
    .string "{PLAYER}: Is it that fun to mimic my\n"
    .string "every move?\p"
    .string "COPYCAT: You bet!\n"
    .string "It's a scream!$"

MoveTutor_Substitute::
	lock
	faceplayer
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SUBSTITUTE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SubstituteDeclined
	goto MoveTutor_EventScript_SubstituteTaught
	end

MoveTutor_Text_SubstituteTeach::
    .string "Aww, I wish I was a Kangaskhan\n"
    .string "baby.\p"
    .string "I'd love to be a substitute for the\n"
    .string "baby…\p"
    .string "And snuggle in the mother\n"
    .string "Kangaskhan's belly pouch.\p"
    .string "But only Pokémon can use the\n"
    .string "technique Substitute…\p"
    .string "Want me to teach Substitute to\n"
    .string "one of your Pokémon?$"

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SubstituteDeclined::
    .string "Oh, really?\n"
    .string "Substitute seems so fun…$"

MoveTutor_Text_SubstituteWhichMon::
    .string "Which Pokémon wants to learn\n"
    .string "Substitute$"

MoveTutor_EventScript_SubstituteTaught::
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SubstituteTaught::
    .string "Boy, what I'd give to crawl inside\n"
    .string "a Kangaskhan belly pouch…$"

MoveTutor_DreamEater::
	lock
	faceplayer
	msgbox MoveTutor_Text_DreamEaterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DreamEaterDeclined
	msgbox MoveTutor_Text_DreamEaterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DREAM_EATER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DreamEaterDeclined
	goto MoveTutor_EventScript_DreamEaterTaught
	end

MoveTutor_Text_DreamEaterTeach::
    .string "Yawn!\n"
    .string "I must have dozed off in the sun.\p"
    .string "I had this weird dream about\n"
    .string "a Drowzee eating my dream.\p"
    .string "And…\n"
    .string "I learned how to eat dreams…\p"
    .string "Oogh, this is too spooky!\p"
    .string "Let me teach it to a Pokémon so\n"
    .string "I can forget about it!$"

MoveTutor_EventScript_DreamEaterDeclined::
	msgbox MoveTutor_Text_DreamEaterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_DreamEaterDeclined::
    .string "…Snore…$"

MoveTutor_Text_DreamEaterWhichMon::
    .string "Which Pokémon wants to learn\n"
    .string "Dream Eater?$"

MoveTutor_EventScript_DreamEaterTaught::
	msgbox MoveTutor_Text_DreamEaterTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_DreamEaterTaught::
    .string "…ZZZ…\n"
    .string "I…can't eat…anymore…$"

MoveTutor_SeismicToss::
	lock
	faceplayer
	msgbox MoveTutor_Text_SeismicTossTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SeismicTossDeclined
	msgbox MoveTutor_Text_SeismicTossWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SEISMIC_TOSS
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SeismicTossDeclined
	goto MoveTutor_EventScript_SeismicTossTaught
	end

MoveTutor_Text_SeismicTossTeach::
    .string "The secrets of space…\n"
    .string "The mysteries of earth…\p"
    .string "There are so many things about\n"
    .string "which we know so little.\p"
    .string "But that should spur us to study\n"
    .string "harder, not toss in the towel.\p"
    .string "The only thing you should toss…\p"
    .string "Well, how about Seismic Toss?\n"
    .string "Should I teach that to a Pokémon?$"

MoveTutor_EventScript_SeismicTossDeclined::
	msgbox MoveTutor_Text_SeismicTossDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SeismicTossDeclined::
    .string "Is that so?\n"
    .string "I'm sure you'll be back for it.$"

MoveTutor_Text_SeismicTossWhichMon::
    .string "Which Pokémon wants to learn\n"
    .string "Seismic Toss?$"

MoveTutor_EventScript_SeismicTossTaught::
	msgbox MoveTutor_Text_SeismicTossTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SeismicTossTaught::
    .string "I hope you won't toss in the towel.\n"
    .string "Keep it up.$"

MoveTutor_MegaPunch::
	lock
	faceplayer
	msgbox MoveTutor_Text_MegaPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MegaPunchDeclined
	msgbox MoveTutor_Text_MegaPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MEGA_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MegaPunchDeclined
	goto MoveTutor_EventScript_MegaPunchTaught
	end

MoveTutor_Text_MegaPunchTeach::
    .string "A punch of roaring ferocity!\p"
    .string "Packed with destructive power!\p"
    .string "When the chips are down,\n"
    .string "Mega Punch is the ultimate attack!\l"
    .string "You agree, yes?\p"
    .string "Now!\n"
    .string "Let me teach it to your Pokémon!$"

MoveTutor_EventScript_MegaPunchDeclined::
	msgbox MoveTutor_Text_MegaPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MegaPunchDeclined::
    .string "You'll be back when you understand\n"
    .string "the worth of Mega Punch.$"

MoveTutor_Text_MegaPunchWhichMon::
    .string "Fine!\n"
    .string "Which Pokémon will learn it?$"

MoveTutor_EventScript_MegaPunchTaught::
	msgbox MoveTutor_Text_MegaPunchTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MegaPunchTaught::
    .string "Now, we are comrades in the way of\n"
    .string "punching!\p"
    .string "You should go before you're seen\n"
    .string "by the misguided fool who trains\l"
    .string "only his silly kicking over there.$"

MoveTutor_MegaKick::
	lock
	faceplayer
	msgbox MoveTutor_Text_MegaKickTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MegaKickDeclined
	msgbox MoveTutor_Text_MegaKickWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_MEGA_KICK
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MegaKickDeclined
	goto MoveTutor_EventScript_MegaKickTaught
	end

MoveTutor_Text_MegaKickTeach::
    .string "A kick of brutal ferocity!\p"
    .string "Packed with destructive power!\p"
    .string "When you get right down to it,\n"
    .string "Mega Kick is the ultimate attack!\l"
    .string "Don't you agree?\p"
    .string "Okay!\n"
    .string "I'll teach it to your Pokémon!$"

MoveTutor_EventScript_MegaKickDeclined::
	msgbox MoveTutor_Text_MegaKickDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MegaKickDeclined::
    .string "You'll come crawling back when you\n"
    .string "realize the value of Mega Kick.$"

MoveTutor_Text_MegaKickWhichMon::
    .string "All right!\n"
    .string "Which Pokémon wants to learn it?$"

MoveTutor_EventScript_MegaKickTaught::
	msgbox MoveTutor_Text_MegaKickTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_MegaKickTaught::
    .string "Now, we are soul mates in the way\n"
    .string "of kicking!\p"
    .string "You should run before you're seen\n"
    .string "by the deluded nitwit who trains\l"
    .string "only simple punching over there.$"

MoveTutor_RockSlide::
	lock
	faceplayer
	msgbox MoveTutor_Text_RockSlideTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RockSlideDeclined
	msgbox MoveTutor_Text_RockSlideWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ROCK_SLIDE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_RockSlideDeclined
	goto MoveTutor_EventScript_RockSlideTaught
	end

MoveTutor_Text_RockSlideTeach::
    .string "When you're up on a rocky mountain\n"
    .string "like this, rockslides are a threat.\p"
    .string "Can you imagine?\n"
    .string "Boulders tumbling down on you?\p"
    .string "That'd be, like, waaaaaaaaaaah!\n"
    .string "Total terror!\p"
    .string "You don't seem to be scared.\n"
    .string "Want to try using Rock Slide?$"

MoveTutor_EventScript_RockSlideDeclined::
	msgbox MoveTutor_Text_RockSlideDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_RockSlideDeclined::
    .string "Oh, so you are scared after all.$"

MoveTutor_Text_RockSlideWhichMon::
    .string "Which Pokémon should I teach\n"
    .string "Rock Slide?$"

MoveTutor_EventScript_RockSlideTaught::
	msgbox MoveTutor_Text_RockSlideTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_RockSlideTaught::
    .string "It might be scary to use it in this\n"
    .string "tunnel…$"

MoveTutor_SoftBoiled::
	lock
	faceplayer
	msgbox MoveTutor_Text_SoftBoiledTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SoftBoiledDeclined
	msgbox MoveTutor_Text_SoftBoiledWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SOFT_BOILED
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SoftBoiledDeclined
	goto MoveTutor_EventScript_SoftBoiledTaught
	end

MoveTutor_Text_SoftBoiledTeach::
    .string "Hello, there!\p"
    .string "I've seen you about, but I never\n"
    .string "had a chance to chat.\p"
    .string "It must be good luck that brought\n"
    .string "us together finally.\p"
    .string "I'd like to celebrate by teaching\n"
    .string "you the move Soft Boiled.$"

MoveTutor_EventScript_SoftBoiledDeclined::
	msgbox MoveTutor_Text_SoftBoiledDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SoftBoiledDeclined::
    .string "I'll always be keeping an eye out\n"
    .string "for you.\p"
    .string "I hope we can chat again.$"

MoveTutor_Text_SoftBoiledWhichMon::
    .string "So, who's the Pokémon that gets\n"
    .string "the chance to learn Soft Boiled?$"

MoveTutor_EventScript_SoftBoiledTaught::
	msgbox MoveTutor_Text_SoftBoiledTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_Text_SoftBoiledTaught::
    .string "I wish you the best of luck!$"



MoveTutor_Counter::
    lock
    faceplayer
    msgbox MoveTutor_Text_CounterTeach, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_CounterDeclined
    msgbox MoveTutor_Text_CounterWhichMon, MSGBOX_DEFAULT
    setvar VAR_0x8005, TUTOR_MOVE_COUNTER
    call MoveTutor_EventScript_OpenPartyMenu
    goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_CounterDeclined
    goto MoveTutor_EventScript_CounterTaught
    end

MoveTutor_Text_CounterTeach::
    .string "Oh, hi!\n"
    .string "I finally finished that RomHack!\p"
    .string "Not done yet? How about I teach\n"
    .string "you a good move?\p"
    .string "The move I have in mind is\n"
    .string "Counter.\p"
    .string "Not like the one I'm leaning on,\n"
    .string "mind you!$"

MoveTutor_EventScript_CounterDeclined::
    msgbox MoveTutor_Text_CounterDeclined, MSGBOX_DEFAULT
    release
    end

MoveTutor_Text_CounterDeclined::
    .string "You're not interested? Come see\n"
    .string "me if you change your mind.$"

MoveTutor_Text_CounterWhichMon::
    .string "Which Pokémon should I teach\n"
    .string "Counter to?$"

MoveTutor_EventScript_CounterTaught::
    msgbox MoveTutor_Text_CounterTaught, MSGBOX_DEFAULT
    release
    end

MoveTutor_Text_CounterTaught::
   .string "Are you using that Counter move\n"
    .string "I taught your Pokémon?$"




@OLD
SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SWAGGER, MoveTutor_EventScript_SwaggerTaught
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SWAGGER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SwaggerDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SWAGGER
	goto MoveTutor_EventScript_SwaggerTaught
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SwaggerTaught::
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT, MoveTutor_EventScript_RolloutTaught
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_ROLLOUT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_RolloutDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT
	goto MoveTutor_EventScript_RolloutTaught
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught::
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER, MoveTutor_EventScript_FuryCutterTaught
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_FURY_CUTTER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_FuryCutterDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER
	goto MoveTutor_EventScript_FuryCutterTaught
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught::
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_SleepTalkTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK, MoveTutor_EventScript_SleepTalkTaught
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_SLEEP_TALK
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SleepTalkDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK
	goto MoveTutor_EventScript_SleepTalkTaught
	end

MoveTutor_EventScript_SleepTalkDeclined::
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SleepTalkTaught::
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH, MoveTutor_EventScript_DynamicPunchTaught
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_DYNAMIC_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DynamicPunchDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
	goto MoveTutor_EventScript_DynamicPunchTaught
	end

MoveTutor_EventScript_DynamicPunchDeclined::
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DynamicPunchTaught::
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION, MoveTutor_EventScript_ExplosionTaught
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, TUTOR_MOVE_EXPLOSION
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExplosionDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION
	goto MoveTutor_EventScript_ExplosionTaught
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionTaught::
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnce::
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return
