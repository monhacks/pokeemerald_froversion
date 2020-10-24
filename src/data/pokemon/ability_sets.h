#define ABILITY_SET_END     {0xFF, 0}

struct AbilitySetter
{
    u8 ability;
    u8 level;
};

static const struct AbilitySetter sBulbasaurAbilitySet[] = 
{
    {ABILITY_OVERGROW, 1},
    {ABILITY_CHLOROPHYLL, 10},
    //testing
    {ABILITY_WONDER_GUARD, 11},
    {ABILITY_DROUGHT, 13},
    {ABILITY_DRIZZLE, 14},
    ABILITY_SET_END
};

//etc...

static const struct AbilitySetter *const sAbilitySetterLearnsets[NUM_SPECIES] = 
{
    [SPECIES_BULBASAUR] = sBulbasaurAbilitySet,
    //etc...
};
