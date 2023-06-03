#ifndef GUARD_CONSTANTS_VARS_H
#define GUARD_CONSTANTS_VARS_H

#define VARS_START 0x4000

// temporary vars
// The first 0x10 vars are are temporary--they are cleared every time a map is loaded.
#define TEMP_VARS_START            0x4000
#define VAR_TEMP_0                 (TEMP_VARS_START + 0x0)
#define VAR_TEMP_1                 (TEMP_VARS_START + 0x1)
#define VAR_TEMP_2                 (TEMP_VARS_START + 0x2)
#define VAR_TEMP_3                 (TEMP_VARS_START + 0x3)
#define VAR_TEMP_4                 (TEMP_VARS_START + 0x4)
#define VAR_TEMP_5                 (TEMP_VARS_START + 0x5)
#define VAR_TEMP_6                 (TEMP_VARS_START + 0x6)
#define VAR_TEMP_7                 (TEMP_VARS_START + 0x7)
#define VAR_TEMP_8                 (TEMP_VARS_START + 0x8)
#define VAR_TEMP_9                 (TEMP_VARS_START + 0x9)
#define VAR_TEMP_A                 (TEMP_VARS_START + 0xA)
#define VAR_TEMP_B                 (TEMP_VARS_START + 0xB)
#define VAR_TEMP_C                 (TEMP_VARS_START + 0xC)
#define VAR_TEMP_D                 (TEMP_VARS_START + 0xD)
#define VAR_TEMP_E                 (TEMP_VARS_START + 0xE)
#define VAR_TEMP_F                 (TEMP_VARS_START + 0xF)
#define TEMP_VARS_END              VAR_TEMP_F

// object gfx id vars
// These 0x10 vars are used to dynamically control a map object's sprite.
// For example, the rival's sprite id is dynamically set based on the player's gender.
// See VarGetObjectEventGraphicsId().
#define VAR_OBJ_GFX_ID_0           0x4010
#define VAR_OBJ_GFX_ID_1           0x4011
#define VAR_OBJ_GFX_ID_2           0x4012
#define VAR_OBJ_GFX_ID_3           0x4013
#define VAR_OBJ_GFX_ID_4           0x4014
#define VAR_OBJ_GFX_ID_5           0x4015
#define VAR_OBJ_GFX_ID_6           0x4016
#define VAR_OBJ_GFX_ID_7           0x4017
#define VAR_OBJ_GFX_ID_8           0x4018
#define VAR_OBJ_GFX_ID_9           0x4019
#define VAR_OBJ_GFX_ID_A           0x401A
#define VAR_OBJ_GFX_ID_B           0x401B
#define VAR_OBJ_GFX_ID_C           0x401C
#define VAR_OBJ_GFX_ID_D           0x401D
#define VAR_OBJ_GFX_ID_E           0x401E
#define VAR_OBJ_GFX_ID_F           0x401F

//Preserved Emerald Variables
#define VAR_REPEL_STEP_COUNT                0x4020
#define VAR_ICE_STEP_COUNT                 	0x4021
#define VAR_STARTER_MON                   	0x4022 // 0=Treecko, 1=Torchic, 2=Mudkip
#define VAR_MIRAGE_RND_L                    0x4023 
#define VAR_MIRAGE_RND_H                    0x4024
#define VAR_SECRET_BASE_MAP                 0x4025
#define VAR_CYCLING_ROAD_RECORD_COLLISIONS  0x4026
#define VAR_CYCLING_ROAD_RECORD_TIME_L   	0x4027
#define VAR_CYCLING_ROAD_RECORD_TIME_H      0x4028
#define VAR_FRIENDSHIP_STEP_COUNTER       	0x4029
#define VAR_POISON_STEP_COUNTER          	0x402A
#define VAR_RESET_RTC_ENABLE              	0x402B
#define VAR_ENIGMA_BERRY_AVAILABLE          0x402C
#define VAR_WONDER_NEWS_COUNTER           	0x402D
#define VAR_FRONTIER_MANIAC_FACILITY        0x402E
#define VAR_FRONTIER_GAMBLER_CHALLENGE      0x402F
#define VAR_FRONTIER_GAMBLER_SET_CHALLENGE  0x4030
#define VAR_FRONTIER_GAMBLER_AMOUNT_BET   	0x4031
#define VAR_FRONTIER_GAMBLER_STATE      	0x4032
#define VAR_DEOXYS_ROCK_STEP_COUNT          0x4033
#define VAR_DEOXYS_ROCK_LEVEL           	0x4034
#define VAR_PC_BOX_TO_SEND_MON              0x4035
#define VAR_ABNORMAL_WEATHER_LOCATION       0x4036
#define VAR_ABNORMAL_WEATHER_STEP_COUNTER   0x4037
#define VAR_SHOULD_END_ABNORMAL_WEATHER    	0x4038
#define VAR_FARAWAY_ISLAND_STEP_COUNTER     0x4039
#define VAR_REGICE_STEPS_1      			0x403A
#define VAR_REGICE_STEPS_2                  0x403B
#define VAR_REGICE_STEPS_3                  0x403C
#define VAR_ALTERING_CAVE_WILD_SET          0x403D
#define VAR_DISTRIBUTE_EON_TICKET           0x403E
#define VAR_DAYS            				0x403F
#define VAR_FANCLUB_FAN_COUNTER             0x4040
#define VAR_FANCLUB_LOSE_FAN_TIMER          0x4041
#define VAR_DEPT_STORE_FLOOR           		0x4042
#define VAR_POKELOT_PRIZE_ITEM              0x4043
#define VAR_NATIONAL_DEX                	0x4044
#define VAR_SEEDOT_SIZE_RECORD              0x4045
#define VAR_ASH_GATHER_COUNT                0x4046
#define VAR_BIRCH_STATE               		0x4047
#define VAR_CRUISE_STEP_COUNT               0x4048
#define VAR_LOTAD_SIZE_RECORD               0x4049
#define VAR_POKELOT_RND1                	0x404A
#define VAR_POKELOT_RND2                    0x404B
#define VAR_POKELOT_PRIZE_PLACE             0x404C
#define VAR_CURRENT_SECRET_BASE             0x404D
#define VAR_DAYNIGHT                    	0x404E // Controls Day or Night Encounters
#define VAR_CONTEST_HALL_STATE              0x404F
#define VAR_CONTEST_TYPE            		0x4050
#define VAR_CONTEST_PRIZE_PICKUP            0x4051
#define VAR_CONTEST_LOBBY_STATE             0x4052
#define VAR_CABLE_CLUB_STATE             	0x4053
#define VAR_SECRET_BASE_INITIALIZED         0x4054 
#define VAR_LILYCOVE_FAN_CLUB_STATE        	0x4055 
#define VAR_CYCLING_ROAD            		0x4056 
#define VAR_INIT_SECRET_BASE             	0x4057
#define VAR_ELITE_4_STATE             		0x4058
#define VAR_SAFARI_ZONE_STATE              	0x4059 
#define VAR_CYCLING_CHALLENGE_STATE         0x405A
#define VAR_SS_TIDAL_STATE               	0x405B 
#define VAR_BRAVO_TRAINER_BATTLE_TOWER_ON   0x405C 
#define VAR_PACIFIDLOG_TM_RECEIVED_DAY      0x405D
#define VAR_MIRAGE_TOWER_STATE            	0x405E
#define VAR_CABLE_CLUB_TUTORIAL_STATE       0x405F 
#define VAR_FRONTIER_BATTLE_MODE            0x4060
#define VAR_FRONTIER_FACILITY               0x4061
#define VAR_HAS_ENTERED_BATTLE_FRONTIER     0x4062
#define VAR_SCOTT_STATE                   	0x4063
#define VAR_TRAINER_HILL_IS_ACTIVE          0x4064
#define VAR_GIFT_PICHU_SLOT                 0x4065
#define VAR_GIFT_UNUSED_1                   0x4066 // var is written to, but never read
#define VAR_GIFT_UNUSED_2                   0x4067 // var is written to, but never read
#define VAR_GIFT_UNUSED_3                   0x4068 // var is written to, but never read
#define VAR_GIFT_UNUSED_4                   0x4069 // var is written to, but never read
#define VAR_GIFT_UNUSED_5                   0x406A // var is written to, but never read
#define VAR_GIFT_UNUSED_6                   0x406B // var is written to, but never read
#define VAR_GIFT_UNUSED_7                   0x406C // var is written to, but never read
#define VAR_DAILY_SLOTS                   	0x406D
#define VAR_DAILY_WILDS                   	0x406E 
#define VAR_DAILY_BLENDER                   0x406F
#define VAR_DAILY_PLANTED_BERRIES           0x4070 
#define VAR_DAILY_PICKED_BERRIES            0x4071
#define VAR_DAILY_ROULETTE                  0x4072
#define VAR_SECRET_BASE_STEP_COUNTER        0x4073 // Used by Secret Base TV programs
#define VAR_SECRET_BASE_LAST_ITEM_USED      0x4074 // Used by Secret Base TV programs
#define VAR_SECRET_BASE_LOW_TV_FLAGS        0x4075 // Used by Secret Base TV programs
#define VAR_SECRET_BASE_HIGH_TV_FLAGS       0x4076 // Used by Secret Base TV programs
#define VAR_SECRET_BASE_IS_NOT_LOCAL        0x4077 // Set to TRUE while in another player's secret base.
#define VAR_DAILY_BP                   		0x4078 
#define VAR_SCOTT_BF_CALL_STEP_COUNTER      0x4079 // Unused Var
#define VAR_DEXNAV_SPECIES                  0x407A // Registered dexnav species
#define VAR_DEXNAV_STEP_COUNTER             0x407B // steps for finding hidden pokemon

//Variables
#define VAR_ADVENTURE_BEGINS                0x407C 
#define VAR_OAK_LAB_STATE               	0x407D 
#define VAR_RIVAL_WINRATE               	0x407E 
#define VAR_VIRIDIAN_CITY_GYM               0x407F 
#define VAR_MASSAGE_COOLDOWN_STEP_COUNTER   0x4080 
#define VAR_AIDE_CALL_STEP_COUNTER      	0x4081 
#define VAR_FOLLOWER_VISIBILITY     		0x4082
#define VAR_ROUTE_22_RIVAL_STATE            0x4083
#define VAR_PEWTER_CITY_STATE       		0x4084
#define VAR_PEWTER_CITY_MUSEUM_STATE  		0x4085
#define VAR_FOSSIL_SELECTION               	0x4086 //1 = Dome Fossil, 2 = Helix Fossil
#define VAR_MT_MOON_STATE                 	0x4087
#define VAR_RIVAL_CERULEAN_CITY             0x4088
#define VAR_CERULEAN_CITY_ROCKETS          	0x4089
#define VAR_SEA_COTTAGE_STATE             	0x408A
#define VAR_DAYCARE_EGG_PENDING             0x408B //Used for flipping the DayCare volunteer
#define VAR_SS_ANNE_STATE  					0x408C
#define VAR_SS_TICKET_CHECK           		0x408D
#define VAR_MAGIKARP_SIZE_RECORD          	0x408E
#define VAR_POKEMON_TOWER_STATE             0x408F
#define VAR_ROOFTOP_ROCKET_PLANS            0x4090 //Tracks the Rocket Plans dropoff on the Celadon Roof. 
#define VAR_BERRY_HOUSE_VISITORS	    	0x4091 //The number of Berry Blend opponents available in Fuschia's Berry House.
#define VAR_DOJO_OFFENSE           			0x4092 //The number of Offense Pupils you've defeated to earn Hitmonchan
#define VAR_DOJO_DEFENSE               		0x4093 //The number of Defense Pupils you've defeated to earn Hitmonlee
#define VAR_SILPH_STATE         			0x4094
#define VAR_SEAFOAM_ISLANDS_STATE          	0x4095
#define VAR_FOSSIL_STEP_COUNTER             0x4096
#define VAR_RESURRECTION_FOSSIL             0x4097 //Which Fossil is being revived
#define VAR_VICTORY_ROAD_1F_STATE           0x4098
#define VAR_VICTORY_ROAD_2F_BOULDER1     	0x4099
#define VAR_VICTORY_ROAD_2F_BOULDER2        0x409A
#define VAR_VICTORY_ROAD_3F_STATE           0x409B 
#define VAR_ELITE_4_MODE                    0x409C //Controls battle types for Elite 4
#define VAR_REPEL_LAST_USED                 0x409D //For repeated Repel use
#define VAR_LOOKER_POSTGAME_CALL_STEPS    	0x409E //Countdown to start Looker Postgame call
#define VAR_GOT_SQUIRTLE     				0x409F //Triggers for the Squirtle Event in Vermilion
#define VAR_TITLE_MATCH_OPPONENT        	0x40A0 //Sets the opponent for the title match challenge
#define VAR_TITLE_MATCHES                   0x40A1 //Tracks how many Title Matches you've completed. Every few will trigger a special battle instead of a regular trainer.
#define VAR_BATTLE_TOWER         			0x40A2
#define VAR_SECRET_BATTLE_CLEAR         	0x40A3 //For Events triggered after the secret battle is completed
#define UNUSED_VARIABLE_41                	0x40A4
#define UNUSED_VARIABLE_42  				0x40A5
#define UNUSED_VARIABLE_43   				0x40A6
#define UNUSED_VARIABLE_44       			0x40A7
#define UNUSED_VARIABLE_45                  0x40A8 
#define UNUSED_VARIABLE_46          		0x40A9
#define UNUSED_VARIABLE_47        			0x40AA
#define UNUSED_VARIABLE_48       			0x40AB
#define UNUSED_VARIABLE_49       			0x40AC
#define UNUSED_VARIABLE_50       			0x40AD
#define UNUSED_VARIABLE_51       			0x40AE
#define UNUSED_VARIABLE_52       			0x40AF
#define UNUSED_VARIABLE_53       			0x40B0
#define UNUSED_VARIABLE_54       			0x40B1
#define UNUSED_VARIABLE_55       			0x40B2
#define UNUSED_VARIABLE_56          		0x40B3
#define UNUSED_VARIABLE_57                  0x40B4
#define UNUSED_VARIABLE_58  				0x40B5
#define UNUSED_VARIABLE_59     				0x40B6
#define UNUSED_VARIABLE_60        			0x40B7
#define UNUSED_VARIABLE_61                  0x40B8
#define UNUSED_VARIABLE_62                  0x40B9
#define UNUSED_VARIABLE_63               	0x40BA
#define UNUSED_VARIABLE_64                  0x40BB
#define UNUSED_VARIABLE_65    				0x40BC
#define UNUSED_VARIABLE_66          		0x40BD
#define UNUSED_VARIABLE_67             		0x40BE
#define UNUSED_VARIABLE_68               	0x40BF
#define UNUSED_VARIABLE_69  				0x40C0
#define UNUSED_VARIABLE_70         			0x40C1
#define UNUSED_VARIABLE_71       			0x40C2
#define UNUSED_VARIABLE_72            		0x40C3
#define UNUSED_VARIABLE_73        			0x40C4
#define UNUSED_VARIABLE_74             		0x40C5
#define UNUSED_VARIABLE_75              	0x40C6
#define UNUSED_VARIABLE_76               	0x40C7
#define UNUSED_VARIABLE_77                	0x40C8
#define UNUSED_VARIABLE_78        			0x40C9
#define UNUSED_VARIABLE_79                 	0x40CA
#define UNUSED_VARIABLE_80               	0x40CB 
#define UNUSED_VARIABLE_81              	0x40CC
#define UNUSED_VARIABLE_82        			0x40CD
#define UNUSED_VARIABLE_83             		0x40CE
#define UNUSED_VARIABLE_84                	0x40CF
#define UNUSED_VARIABLE_85      			0x40D0
#define UNUSED_VARIABLE_86                  0x40D1
#define UNUSED_VARIABLE_87   				0x40D2
#define UNUSED_VARIABLE_88  				0x40D3
#define UNUSED_VARIABLE_89             		0x40D4 
#define UNUSED_VARIABLE_90                  0x40D5
#define UNUSED_VARIABLE_91           		0x40D6
#define UNUSED_VARIABLE_92      			0x40D7
#define UNUSED_VARIABLE_93         			0x40D8
#define UNUSED_VARIABLE_94 					0x40D9
#define UNUSED_VARIABLE_95             		0x40DA
#define UNUSED_VARIABLE_96                  0x40DB
#define UNUSED_VARIABLE_97                  0x40DC
#define UNUSED_VARIABLE_98                  0x40DD
#define UNUSED_VARIABLE_99                  0x40DE 
#define UNUSED_VARIABLE_100                 0x40DF 
#define UNUSED_VARIABLE_101                 0x40E0 
#define UNUSED_VARIABLE_102                 0x40E1 
#define UNUSED_VARIABLE_103               	0x40E2 
#define UNUSED_VARIABLE_104                 0x40E3 
#define UNUSED_VARIABLE_105                 0x40E4 
#define UNUSED_VARIABLE_106                 0x40E5
#define UNUSED_VARIABLE_107                 0x40E6
#define UNUSED_VARIABLE_108                 0x40E7
#define UNUSED_VARIABLE_109                 0x40E8
#define UNUSED_VARIABLE_110            		0x40E9
#define UNUSED_VARIABLE_111             	0x40EA
#define UNUSED_VARIABLE_112                 0x40EB
#define UNUSED_VARIABLE_113         		0x40EC 
#define UNUSED_VARIABLE_114       			0x40ED 
#define UNUSED_VARIABLE_115         		0x40EE 
#define UNUSED_VARIABLE_116        			0x40EF 
#define UNUSED_VARIABLE_117         		0x40F0 
#define UNUSED_VARIABLE_118                 0x40F1
#define UNUSED_VARIABLE_119          		0x40F2
#define UNUSED_VARIABLE_120  				0x40F3
#define UNUSED_VARIABLE_121        			0x40F4
#define UNUSED_VARIABLE_122       			0x40F5
#define UNUSED_VARIABLE_123 				0x40F6
#define UNUSED_VARIABLE_124                 0x40F7 
#define UNUSED_VARIABLE_125              	0x40F8 
#define UNUSED_VARIABLE_126                 0x40F9
#define UNUSED_VARIABLE_127                 0x40FA
#define UNUSED_VARIABLE_128                 0x40FB
#define UNUSED_VARIABLE_129                 0x40FC
#define UNUSED_VARIABLE_130                 0x40FD
#define UNUSED_VARIABLE_131                 0x40FE
#define UNUSED_VARIABLE_132                 0x40FF 

#define VARS_END                            0x40FF
#define VARS_COUNT                          (VARS_END - VARS_START + 1)

#define SPECIAL_VARS_START            0x8000
// special vars
// They are commonly used as parameters to commands, or return values from commands.
#define VAR_0x8000                    0x8000
#define VAR_0x8001                    0x8001
#define VAR_0x8002                    0x8002
#define VAR_0x8003                    0x8003
#define VAR_0x8004                    0x8004
#define VAR_0x8005                    0x8005
#define VAR_0x8006                    0x8006
#define VAR_0x8007                    0x8007
#define VAR_0x8008                    0x8008
#define VAR_0x8009                    0x8009
#define VAR_0x800A                    0x800A
#define VAR_0x800B                    0x800B
#define VAR_FACING                    0x800C
#define VAR_RESULT                    0x800D
#define VAR_ITEM_ID                   0x800E
#define VAR_LAST_TALKED               0x800F
#define VAR_CONTEST_RANK              0x8010
#define VAR_CONTEST_CATEGORY          0x8011
#define VAR_MON_BOX_ID                0x8012
#define VAR_MON_BOX_POS               0x8013
#define VAR_UNUSED_0x8014             0x8014
#define VAR_TRAINER_BATTLE_OPPONENT_A 0x8015 // Alias of gTrainerBattleOpponent_A

#define SPECIAL_VARS_END              0x8015

#endif // GUARD_CONSTANTS_VARS_H
