#define ABILITY_SET_END     {0xFF, 0}

struct AbilitySetter
{
    u16 ability;
    u8 level;
};

static const struct AbilitySetter sBulbasaurAbilitySet[] = 
{
    {ABILITY_OVERGROW, 1},
    {ABILITY_CHLOROPHYLL, 10},
    {ABILITY_SWARM, 20},
    ABILITY_SET_END
};

static const struct AbilitySetter sMudkipAbilitySet[] = 
{
    {ABILITY_DROUGHT, 1},
    {ABILITY_MAGIC_BOUNCE, 9},
    {ABILITY_AIR_LOCK, 20},
    ABILITY_SET_END
};

//etc...

static const struct AbilitySetter *const sAbilitySetterLearnsets[NUM_SPECIES] = 
{
    [SPECIES_BULBASAUR] = sBulbasaurAbilitySet,
    [SPECIES_MUDKIP] = sMudkipAbilitySet,
    //etc...
};
