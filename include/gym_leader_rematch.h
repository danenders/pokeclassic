#ifndef GUARD_TRAINER_REMATCH_H
#define GUARD_TRAINER_REMATCH_H

enum {
    REMATCH_JANICE,
    REMATCH_BEN,
    REMATCH_SHANE,
    REMATCH_FRANKLIN,
    REMATCH_KEIGO,
    REMATCH_HUGO,
    REMATCH_BERNIE,
    REMATCH_NED,
    REMATCH_LUCA,
    REMATCH_ALICIA,
    REMATCH_MARK,
    REMATCH_AIDAN,
    REMATCH_HIDEO,
    REMATCH_KOJI,
    REMATCH_WILTON,
    REMATCH_OLIVIA,
    REMATCH_RICHIE,
    REMATCH_ROGER,
    REMATCH_JOHAN,
    REMATCH_ANRI,
    REMATCH_SPECIAL_TRAINER, //Entries above this are considered normal trainers, from here below are special trainers
    REMATCH_ELITE_FOUR, // Entries from SIDNEY below are considered part of REMATCH_ELITE_FOUR_ENTRIES. 
    REMATCH_TABLE_ENTRIES // The total number of rematch entries. Must be last in enum
};

#define REMATCH_SPECIAL_TRAINER_START   REMATCH_SPECIAL_TRAINER
#define REMATCH_ELITE_FOUR_ENTRIES      REMATCH_ELITE_FOUR

void UpdateGymLeaderRematch(void);

#endif //GUARD_TRAINER_REMATCH_H
