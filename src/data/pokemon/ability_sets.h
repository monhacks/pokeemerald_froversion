#define ABILITY_SET_END     {0xFF, 0}

struct AbilitySetter
{
    u16 ability;
    u8 level;
};

static const struct AbilitySetter sHaagletAbilitySet[] = 
{
    {ABILITY_RIVALRY, 1},
    {ABILITY_HYDRATION, 19},
    {ABILITY_SAND_FORCE, 37},
    ABILITY_SET_END
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

static const struct AbilitySetter sPidgeyAbilitySet[] = 
{
    {ABILITY_BIG_PECKS, 1},
    {ABILITY_CHARISMA, 14},
    {ABILITY_GALE_WINGS, 29},
    {ABILITY_NO_GUARD, 47},
    ABILITY_SET_END
};

static const struct AbilitySetter sSentretAbilitySet[] = 
{
    {ABILITY_KEEN_EYE, 1},
    {ABILITY_SIMPLE, 14},
    {ABILITY_FUR_COAT, 31},
    {ABILITY_TECHNICIAN, 50},
    ABILITY_SET_END
};

static const struct AbilitySetter sLileepAbilitySet[] = 
{
    {ABILITY_SUCTION_CUPS, 1},
    {ABILITY_SOLAR_POWER, 14},
    {ABILITY_ROUGH_SKIN, 22},
    {ABILITY_STORM_DRAIN, 32},
    ABILITY_SET_END
};

static const struct AbilitySetter sAnorithAbilitySet[] = 
{
    {ABILITY_BATTLE_ARMOR, 1},
    {ABILITY_IMMUNITY, 18},
    {ABILITY_STAMINA, 36},
    {ABILITY_SWIFT_SWIM, 51},
    ABILITY_SET_END
};

static const struct AbilitySetter sMagnemiteAbilitySet[] = 
{
    {ABILITY_MAGNET_PULL, 1},
    {ABILITY_STURDY, 15},
    {ABILITY_ANALYTIC, 32},
    {ABILITY_LIGHTNING_ROD, 45},
    ABILITY_SET_END
};

static const struct AbilitySetter sSandshrewAbilitySet[] = 
{   
    {ABILITY_ABYSSAL, 1},
    {ABILITY_SAND_RUSH, 1},
    {ABILITY_SAND_FORCE, 25},
    {ABILITY_SAND_VEIL, 55},
    ABILITY_SET_END
};

static const struct AbilitySetter sOddishAbilitySet[] = 
{
    {ABILITY_CHLOROPHYLL, 1},
    {ABILITY_EFFECT_SPORE, 16},
    {ABILITY_SAP_SIPPER, 42},
    ABILITY_SET_END
};

static const struct AbilitySetter sGrowlitheAbilitySet[] = 
{
    {ABILITY_INTIMIDATE, 1},
    {ABILITY_FLASH_FIRE, 16},
    {ABILITY_JUSTIFIED, 38},
    {ABILITY_SPEED_BOOST, 60},
    ABILITY_SET_END
};

static const struct AbilitySetter sPhanpyAbilitySet[] = 
{
    {ABILITY_STURDY, 1},
    {ABILITY_STAMINA, 17},
    {ABILITY_SAND_VEIL, 29},
    ABILITY_SET_END
};

static const struct AbilitySetter sRhyhornAbilitySet[] = 
{
    {ABILITY_LIGHTNING_ROD, 1},
    {ABILITY_ROCK_HEAD, 16},
    {ABILITY_RECKLESS, 35},
    {ABILITY_SOLID_ROCK, 52},
    ABILITY_SET_END
};

static const struct AbilitySetter sEeveeAbilitySet[] = 
{
    {ABILITY_RUN_AWAY, 1},
    {ABILITY_ADAPTABILITY, 16},
    {ABILITY_ANTICIPATION, 24},
    ABILITY_SET_END
};

static const struct AbilitySetter sJolteonAbilitySet[] = 
{
    {ABILITY_VOLT_ABSORB, 1},
    {ABILITY_QUICK_FEET, 1},
    {ABILITY_STATIC, 36},
    {ABILITY_ELECTRIC_SURGE, 52},
    ABILITY_SET_END
};

static const struct AbilitySetter sVaporeonAbilitySet[] = 
{
    {ABILITY_WATER_ABSORB, 1},
    {ABILITY_HYDRATION, 1},
    {ABILITY_REGENERATOR, 36},
    {ABILITY_DRIZZLE, 50},
    {ABILITY_VAPOREON_REGENERATOR_RAIN_DISH, 200}, //only on marriotts vaporeon!!
    ABILITY_SET_END
};

static const struct AbilitySetter sFlareonAbilitySet[] = 
{
    {ABILITY_FLASH_FIRE, 1},
    {ABILITY_GUTS, 1},
    {ABILITY_FLAME_BODY, 36},
    {ABILITY_DROUGHT, 52},
    ABILITY_SET_END
};

static const struct AbilitySetter sUmbreonAbilitySet[] = 
{
    {ABILITY_SYNCHRONIZE, 1},
    {ABILITY_INNER_FOCUS, 1},
    {ABILITY_FILTER, 36},
    {ABILITY_SPACE_SHIFT, 50},
    ABILITY_SET_END
};

static const struct AbilitySetter sEspeonAbilitySet[] = 
{
    {ABILITY_SYNCHRONIZE, 1},
    {ABILITY_MAGIC_BOUNCE, 1},
    {ABILITY_NEUROFORCE, 36},
    {ABILITY_PSYCHIC_SURGE, 52},
    ABILITY_SET_END
};

static const struct AbilitySetter sWeedleAbilitySet[] = 
{
    {ABILITY_SHIELD_DUST, 1},
    {ABILITY_RUN_AWAY, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sKakunaAbilitySet[] = 
{
    {ABILITY_SHED_SKIN, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sSkarmoryAbilitySet[] = 
{
    {ABILITY_KEEN_EYE, 1},
    {ABILITY_CLEAR_BODY, 25},
    {ABILITY_STURDY, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sBeedrillAbilitySet[] = 
{
    {ABILITY_SWARM, 1},
    {ABILITY_SNIPER, 10},
    {ABILITY_ADAPTABILITY, 21},
    ABILITY_SET_END
};

static const struct AbilitySetter sCaterpieAbilitySet[] = 
{
    {ABILITY_SHIELD_DUST, 1},
    {ABILITY_RUN_AWAY, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sMetapodAbilitySet[] = 
{
    {ABILITY_SHED_SKIN, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sButterfreeAbilitySet[] = 
{
    {ABILITY_COMPOUND_EYES, 1},
    {ABILITY_TINTED_LENS, 10},
    {ABILITY_EFFECT_SPORE, 21},
    ABILITY_SET_END
};


static const struct AbilitySetter sChinchouAbilitySet[] = 
{
    {ABILITY_ILLUMINATE, 1},
    {ABILITY_VOLT_ABSORB, 16},
    {ABILITY_WATER_ABSORB, 28},
    {ABILITY_LIGHTNING_ROD, 41},
    ABILITY_SET_END
};

static const struct AbilitySetter sHoothootAbilitySet[] = 
{
    {ABILITY_KEEN_EYE, 1},
    {ABILITY_INSOMNIA, 14},
    {ABILITY_TINTED_LENS, 28},
    ABILITY_SET_END
};

static const struct AbilitySetter sNoctowlAbilitySet[] = 
{
    {ABILITY_KEEN_EYE, 1},
    {ABILITY_INSOMNIA, 14},
    {ABILITY_TINTED_LENS, 28},
    {ABILITY_TECHNICIAN, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sSpinarakAbilitySet[] = 
{
    {ABILITY_SWARM, 1},
    {ABILITY_INSOMNIA, 17},
    {ABILITY_SNIPER, 32},
    {ABILITY_POISON_HEAL, 48},
    ABILITY_SET_END
};

static const struct AbilitySetter sMurkrowAbilitySet[] = 
{
    {ABILITY_INSOMNIA, 1},
    {ABILITY_SUPER_LUCK, 16},
    {ABILITY_PRANKSTER, 37},
    ABILITY_SET_END
};

static const struct AbilitySetter sMisdreavusAbilitySet[] = 
{
    {ABILITY_LEVITATE, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sHoundourAbilitySet[] = 
{
    {ABILITY_EARLY_BIRD, 1},
    {ABILITY_UNNERVE, 24},
    {ABILITY_FLASH_FIRE, 35},
    {ABILITY_SOLAR_POWER, 51},
    ABILITY_SET_END
};

static const struct AbilitySetter sMegaHoundoomAbilitySet[]=
{
    {ABILITY_MEGA_HOUNDOOM_ABILITY, 101},
    ABILITY_SET_END
};

static const struct AbilitySetter sScytherAbilitySet[] = 
{
    {ABILITY_SWARM, 1},
    {ABILITY_TECHNICIAN, 17},
    {ABILITY_SNIPER, 32},
    {ABILITY_POISON_HEAL, 48},
    ABILITY_SET_END
};

static const struct AbilitySetter sScizorAbilitySet[] = 
{
    {ABILITY_SWARM, 1},
    {ABILITY_TECHNICIAN, 17},
    {ABILITY_SNIPER, 32},
    {ABILITY_HEATPROOF, 48},
    ABILITY_SET_END
};

static const struct AbilitySetter sDuskullAbilitySet[] = 
{
    {ABILITY_LEVITATE, 1},
    {ABILITY_FRISK, 21},
    {ABILITY_CURSED_BODY, 32},
    ABILITY_SET_END
};

static const struct AbilitySetter sDusclopsAbilitySet[] = 
{
    {ABILITY_FRISK, 1},
    {ABILITY_PRESSURE, 41},
    {ABILITY_PERISH_BODY, 52},
    ABILITY_SET_END
};

static const struct AbilitySetter sSlakothAbilitySet[] =
{
    {ABILITY_TRUANT, 1},
    {ABILITY_SLOW_START, 40},
    {ABILITY_DEFEATIST, 80},
    ABILITY_SET_END
};

static const struct AbilitySetter sNinjaskAbilitySet[] =
{
    {ABILITY_INFILTRATOR, 1},
    {ABILITY_SPEED_BOOST, 19},
    {ABILITY_HUGE_POWER, 33},
    ABILITY_SET_END
};

static const struct AbilitySetter sShedinjaAbilitySet[] =
{
    {ABILITY_PRANKSTER, 1},
    {ABILITY_WONDER_GUARD, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sClefairyAbilitySet[] =
{
    {ABILITY_CUTE_CHARM, 1},
    {ABILITY_UNAWARE, 14},
    {ABILITY_MAGIC_GUARD, 26},
    ABILITY_SET_END
};

static const struct AbilitySetter sChanseyAbilitySet[] =
{
    {ABILITY_SERENE_GRACE, 1},
    {ABILITY_NATURAL_CURE, 20},
    {ABILITY_REGENERATOR, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sBlisseyAbilitySet[] =
{
    {ABILITY_SERENE_GRACE, 1},
    {ABILITY_NATURAL_CURE, 25},
    {ABILITY_REGENERATOR, 45},
    ABILITY_SET_END
};

static const struct AbilitySetter sMankeyAbilitySet[] =
{
    {ABILITY_VITAL_SPIRIT, 1},
    {ABILITY_ANGER_POINT, 12},
    {ABILITY_DEFIANT, 21},
    ABILITY_SET_END
};

static const struct AbilitySetter sMachopAbilitySet[] =
{
    {ABILITY_STEADFAST, 1},
    {ABILITY_GUTS, 23},
    {ABILITY_NO_GUARD, 44},
    ABILITY_SET_END
};

static const struct AbilitySetter sGeodudeAbilitySet[] =
{
    {ABILITY_STURDY, 1},
    {ABILITY_ROCK_HEAD, 19},
    {ABILITY_SAND_VEIL, 35},
    ABILITY_SET_END
};

static const struct AbilitySetter sCuboneAbilitySet[] =
{
    {ABILITY_ROCK_HEAD, 1},
    {ABILITY_BATTLE_ARMOR, 14},
    {ABILITY_LIGHTNING_ROD, 25},
    {ABILITY_SAND_RUSH, 34},
    {ABILITY_PARENTAL_BOND, 42},
    ABILITY_SET_END
};

static const struct AbilitySetter sOnixAbilitySet[] =
{
    {ABILITY_STURDY, 1},
    {ABILITY_ROCK_HEAD, 12},
    {ABILITY_WEAK_ARMOR, 22},
    ABILITY_SET_END
};

static const struct AbilitySetter sSteelixAbilitySet[] =
{
    {ABILITY_STURDY, 1},
    {ABILITY_ROCK_HEAD, 12},
    {ABILITY_SHEER_FORCE, 34},
    {ABILITY_SAND_FORCE, 46},
    ABILITY_SET_END
};

static const struct AbilitySetter sSnorlaxAbilitySet[] =
{
    {ABILITY_IMMUNITY, 1},
    {ABILITY_THICK_FAT, 16},
    {ABILITY_GLUTTONY, 35},
    {ABILITY_EARLY_BIRD, 54},
    ABILITY_SET_END
};

static const struct AbilitySetter sHoppipAbilitySet[] =
{
    {ABILITY_INFILTRATOR, 1},
    {ABILITY_LEAF_GUARD, 18},
    {ABILITY_CHLOROPHYLL, 31},
    {ABILITY_FLOWER_VEIL, 47},
    ABILITY_SET_END
};

static const struct AbilitySetter sAbsolAbilitySet[] =
{
    {ABILITY_PRESSURE, 1},
    {ABILITY_SUPER_LUCK, 15},
    {ABILITY_JUSTIFIED, 37},
    {ABILITY_MAGIC_BOUNCE, 53},
    ABILITY_SET_END
};

static const struct AbilitySetter sAronAbilitySet[] =
{
    {ABILITY_STURDY, 1},
    {ABILITY_ROCK_HEAD, 9},
    {ABILITY_HEAVY_METAL, 31},
    {ABILITY_FILTER, 50},
    ABILITY_SET_END
};

static const struct AbilitySetter sMedititeAbilitySet[] =
{
    {ABILITY_TELEPATHY, 1},
    {ABILITY_SCRAPPY, 14},
    {ABILITY_PURE_POWER, 30},
    ABILITY_SET_END
};

static const struct AbilitySetter sMakuhitaAbilitySet[] =
{
    {ABILITY_THICK_FAT, 1},
    {ABILITY_GUTS, 17},
    {ABILITY_SHEER_FORCE, 31},
    ABILITY_SET_END
};

static const struct AbilitySetter sInvertebrakeAbilitySet[] =
{
    {ABILITY_THICK_FAT, 1},
    {ABILITY_GUTS, 17},
    {ABILITY_SHEER_FORCE, 31},
    {ABILITY_INVERTEBRAKE_HIDDEN_ABILITY, 155},
    ABILITY_SET_END
};

static const struct AbilitySetter sDiglettAbilitySet[] =
{
    {ABILITY_RUN_AWAY, 1},
    {ABILITY_SAND_FORCE, 13},
    {ABILITY_SAND_VEIL, 27},
    {ABILITY_ARENA_TRAP, 41},
    {ABILITY_SHADOW_DUGTRIO, 101},
    ABILITY_SET_END
};

static const struct AbilitySetter sSableyeAbilitySet[] =
{
    {ABILITY_KEEN_EYE, 1},
    {ABILITY_PICKPOCKET, 8},
    {ABILITY_PRANKSTER, 19},
    {ABILITY_MAGIC_BOUNCE, 31},
    ABILITY_SET_END
};

static const struct AbilitySetter sLunatoneAbilitySet[] =
{
    {ABILITY_LEVITATE, 1},
    {ABILITY_HEALER, 13},
    {ABILITY_TELEPATHY, 20},
    {ABILITY_SWEET_VEIL, 26},
    ABILITY_SET_END
};

static const struct AbilitySetter sSolrockAbilitySet[] =
{
    {ABILITY_LEVITATE, 1},
    {ABILITY_SCREEN_CLEANER, 13},
    {ABILITY_TELEPATHY, 20},
    {ABILITY_BATTERY, 26},
    ABILITY_SET_END
};

static const struct AbilitySetter sZubatAbilitySet[] =
{
    {ABILITY_INNER_FOCUS, 1},
    {ABILITY_INFILTRATOR, 18},
    {ABILITY_RECKLESS, 33},
    ABILITY_SET_END
};

static const struct AbilitySetter sKoffingbilitySet[] =
{
    {ABILITY_LEVITATE, 1},
    {ABILITY_STENCH, 20},
    {ABILITY_CORROSION, 38},
    ABILITY_SET_END
};

static const struct AbilitySetter sMagmarAbilitySet[] =
{
    {ABILITY_FLAME_BODY, 1},
    {ABILITY_VITAL_SPIRIT, 24},
    {ABILITY_BERSERK, 41},
    ABILITY_SET_END
};

static const struct AbilitySetter sSlugmaAbilitySet[] =
{
    {ABILITY_MAGMA_ARMOR, 1},
    {ABILITY_FLAME_BODY, 13},
    {ABILITY_WEAK_ARMOR, 20},
    ABILITY_SET_END
};

static const struct AbilitySetter sMagcargoAbilitySet[] =
{
    {ABILITY_MAGMA_ARMOR, 1},
    {ABILITY_FLAME_BODY, 13},
    {ABILITY_WEAK_ARMOR, 20},
    {ABILITY_SHELL_ARMOR, 28},
    ABILITY_SET_END
};

static const struct AbilitySetter sNumelAbilitySet[] =
{
    {ABILITY_MAGMA_ARMOR, 1},
    {ABILITY_SOLID_ROCK, 13},
    {ABILITY_ANGER_POINT, 20},
    {ABILITY_SHEER_FORCE, 28},
    {ABILITY_UNBURDEN, 38},
    ABILITY_SET_END
};

static const struct AbilitySetter sJynxAbilitySet[] =
{
    {ABILITY_OBLIVIOUS, 1},
    {ABILITY_DRY_SKIN, 16},
    {ABILITY_FOREWARN, 29},
    {ABILITY_SNOW_CLOAK, 38},
    ABILITY_SET_END
};

static const struct AbilitySetter sSneaselAbilitySet[] =
{
    {ABILITY_PRESSURE, 1},
    {ABILITY_PICKPOCKET, 18},
    {ABILITY_REFRIGERATE, 28},
    ABILITY_SET_END
};

static const struct AbilitySetter sSnoruntAbilitySet[] =
{
    {ABILITY_INNER_FOCUS, 1},
    {ABILITY_ICE_BODY, 11},
    {ABILITY_MOODY, 23},
    ABILITY_SET_END
};

static const struct AbilitySetter sGlalieAbilitySet[] =
{
    {ABILITY_INNER_FOCUS, 1},
    {ABILITY_ICE_BODY, 11},
    {ABILITY_MOODY, 23},
    {ABILITY_REFRIGERATE, 32},
    ABILITY_SET_END
};

static const struct AbilitySetter sTeddiursaAbilitySet[] =
{
    {ABILITY_PICKUP, 1},
    {ABILITY_QUICK_FEET, 11},
    {ABILITY_HONEY_GATHER, 19},
    ABILITY_SET_END
};

static const struct AbilitySetter sUrsaringAbilitySet[] =
{
    {ABILITY_INTIMIDATE, 1},
    {ABILITY_GUTS, 30},
    {ABILITY_UNNERVE, 30},
    {ABILITY_FUR_COAT, 38},
    ABILITY_SET_END
};

static const struct AbilitySetter sSwinubAbilitySet[] =
{
    {ABILITY_OBLIVIOUS, 1},
    {ABILITY_THICK_FAT, 15},
    {ABILITY_SNOW_CLOAK, 33},
    {ABILITY_SAND_VEIL, 34},
    ABILITY_SET_END
};

static const struct AbilitySetter sMarillAbilitySet[] =
{
    {ABILITY_THICK_FAT, 1},
    {ABILITY_HYDRATION, 18},
    {ABILITY_HUGE_POWER, 35},
    {ABILITY_SAP_SIPPER, 53},
    ABILITY_SET_END
};

static const struct AbilitySetter sPoliwagAbilitySet[] =
{
    {ABILITY_DAMP, 1},
    {ABILITY_WATER_ABSORB, 14},
    {ABILITY_SWIFT_SWIM, 36},
    ABILITY_SET_END
};

static const struct AbilitySetter sPoliwhirlAbilitySet[] =
{
    {ABILITY_DAMP, 1},
    {ABILITY_WATER_ABSORB, 14},
    {ABILITY_IRON_FIST, 25},
    {ABILITY_SWIFT_SWIM, 36},
    ABILITY_SET_END
};

static const struct AbilitySetter sTangelaAbilitySet[] =
{
    {ABILITY_CHLOROPHYLL, 1},
    {ABILITY_LEAF_GUARD, 17},
    {ABILITY_REGENERATOR, 39},
    {ABILITY_GRASSY_SURGE, 47},
    ABILITY_SET_END
};

static const struct AbilitySetter sYanmaAbilitySet[] =
{
    {ABILITY_COMPOUND_EYES, 1},
    {ABILITY_FRISK, 14},
    {ABILITY_SPEED_BOOST, 26},
    ABILITY_SET_END
};

static const struct AbilitySetter sRattataAbilitySet[] =
{
    {ABILITY_RUN_AWAY, 1},
    {ABILITY_HUSTLE, 9},
    {ABILITY_GUTS, 21},
    ABILITY_SET_END
};

static const struct AbilitySetter sGrimerAbilitySet[] =
{
    {ABILITY_STENCH, 1},
    {ABILITY_STICKY_HOLD, 19},
    {ABILITY_POISON_TOUCH, 32},
    {ABILITY_POWER_OF_ALCHEMY, 47},
    ABILITY_SET_END
};

static const struct AbilitySetter sAbraAbilitySet[] =
{
    {ABILITY_SYNCHRONIZE, 1},
    {ABILITY_INNER_FOCUS, 8},
    ABILITY_SET_END
};

static const struct AbilitySetter sAlakazamAbilitySet[] =
{
    {ABILITY_SYNCHRONIZE, 1},
    {ABILITY_INNER_FOCUS, 1},
    {ABILITY_MAGIC_GUARD, 32},
    {ABILITY_NEGATE, 47},
    ABILITY_SET_END
};

static const struct AbilitySetter sElectabuzzAbilitySet[] =
{
    {ABILITY_VITAL_SPIRIT, 1},
    {ABILITY_STATIC, 21},
    //{ABILITY_AMPED, 36}, //code ability that boosts spAtk in electric terrain
    ABILITY_SET_END
};

static const struct AbilitySetter sFeebasAbilitySet[] =
{
    {ABILITY_CUTE_CHARM, 1},
    {ABILITY_COMPETITIVE, 15},
    {ABILITY_SWIFT_SWIM, 30},
    {ABILITY_MARVEL_SCALE, 45},
    ABILITY_SET_END
};

static const struct AbilitySetter sMagikarpAbilitySet[] =
{
    {ABILITY_SWIFT_SWIM, 1},
    {ABILITY_RATTLED, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sGyaradosAbilitySet[] =
{
    {ABILITY_INTIMIDATE, 1},
    {ABILITY_MOXIE, 20},
    {ABILITY_MOLD_BREAKER, 30},
    {ABILITY_SWIFT_SWIM, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sCorsolaAbilitySet[] =
{
    {ABILITY_HUSTLE, 1},
    {ABILITY_REGENERATOR, 15},
    {ABILITY_NATURAL_CURE, 27},
    ABILITY_SET_END
};

static const struct AbilitySetter sGastlyAbilitySet[] =
{
    {ABILITY_LEVITATE, 1},
    {ABILITY_CURSED_BODY, 12},
    {ABILITY_COMPETITIVE, 32},
    ABILITY_SET_END
};

static const struct AbilitySetter sGengarAbilitySet[] =
{
    {ABILITY_LEVITATE, 1},
    {ABILITY_CURSED_BODY, 12},
    {ABILITY_COMPETITIVE, 32},
    {ABILITY_SHADOW_TAG, 47},
    ABILITY_SET_END
};

static const struct AbilitySetter sAbyssalDragonAbilitySet[] =
{
    {ABILITY_ROUGH_SKIN, 1},
    {ABILITY_SAND_FORCE, 12},
    {ABILITY_ABYSSAL, 32},
    {ABILITY_UNBURDEN, 33},
    ABILITY_SET_END
};

static const struct AbilitySetter sSeelAbilitySet[] =
{
    {ABILITY_THICK_FAT, 1},
    {ABILITY_HYDRATION, 16},
    {ABILITY_ICE_BODY, 38},
    ABILITY_SET_END
};

// static const struct AbilitySetter sDewgongRegionalAbilitySet[] =
// {
//     {ABILITY_CUSTOM1, 1}, //code an ability that allows for regeneration of health at end of each turn and heal status condition every 4 turns (this could change)
//     ABILITY_SET_END
// };


//etc...

static const struct AbilitySetter sDratiniAbilitySet[] =
{
    {ABILITY_SHED_SKIN, 1},
    {ABILITY_MARVEL_SCALE, 35},
    {ABILITY_DAZZLING, 60},
    ABILITY_SET_END
};

static const struct AbilitySetter sDragoniteAbilitySet[] =
{
    {ABILITY_THICK_FAT, 1},
    {ABILITY_INTIMIDATE, 1},
    {ABILITY_MULTISCALE, 65},
    ABILITY_SET_END
};

static const struct AbilitySetter sLarvitarAbilitySet[] =
{
    {ABILITY_GUTS, 1},
    {ABILITY_SAND_VEIL, 35},
    ABILITY_SET_END
};

static const struct AbilitySetter sPupitarAbilitySet[] =
{
    {ABILITY_SHED_SKIN, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sTyranitarAbilitySet[] =
{
    {ABILITY_UNNERVE, 1},
    {ABILITY_SAND_STREAM, 1},
    //{ABILITY_CUSTOM2, 65}, //Sandstream + sand veil combined.
    ABILITY_SET_END
};

static const struct AbilitySetter sBagonAbilitySet[] =
{
    {ABILITY_ROCK_HEAD, 1},
    {ABILITY_SHEER_FORCE, 35},
    ABILITY_SET_END
};

static const struct AbilitySetter sShelgonAbilitySet[] =
{
    {ABILITY_ROCK_HEAD, 1},
    {ABILITY_OVERCOAT, 35},
    ABILITY_SET_END
};

static const struct AbilitySetter sSalamenceAbilitySet[] =
{
    {ABILITY_ROCK_HEAD, 1},
    {ABILITY_SHEER_FORCE, 1},
    {ABILITY_INTIMIDATE, 1},
    {ABILITY_MOXIE, 52},
    {ABILITY_AERILATE, 65},
    ABILITY_SET_END
};

static const struct AbilitySetter sMareepAbilitySet[] =
{
    {ABILITY_STATIC, 1},
    {ABILITY_PLUS, 13},
    {ABILITY_FLUFFY, 20},
    ABILITY_SET_END
};

static const struct AbilitySetter sAmpharosAbilitySet[] =
{
    {ABILITY_STATIC, 1},
    {ABILITY_PLUS, 13},
    {ABILITY_MOLD_BREAKER, 20},
    {ABILITY_SURGE_SURFER, 33},
    ABILITY_SET_END
};

static const struct AbilitySetter sPikachuAbilitySet[] =
{
    {ABILITY_STATIC, 1},
    {ABILITY_MINUS, 1},
    {ABILITY_LIGHTNING_ROD, 16},
    {ABILITY_LEVITATE, 32},
    //{ABILITY_POWER_SURGE, 47}, //code ability to boost electric type attacks on electric terrain
    ABILITY_SET_END
};

static const struct AbilitySetter sRiachuAbilitySet[] =
{
    {ABILITY_STATIC, 1},
    {ABILITY_MINUS, 1},
    {ABILITY_LIGHTNING_ROD, 16},
    //{ABILITY_SURGE_SHIELD, 43}, //code ability that boosts sp def and def on electric terrain
    ABILITY_SET_END
};

static const struct AbilitySetter sVoltorbAbilitySet[] =
{
    {ABILITY_SOUNDPROOF, 1},
    {ABILITY_STATIC, 19},
    {ABILITY_AFTERMATH, 42},
    ABILITY_SET_END
};

static const struct AbilitySetter sFlobraAbilitySet[] = 
{
    {ABILITY_TORRENT, 1},
    {ABILITY_CONTRARY, 15},
    {ABILITY_LIBERO, 35},
    {ABILITY_DOWNLOAD, 54},
    ABILITY_SET_END
};

static const struct AbilitySetter sMorphloAbilitySet[] = 
{
    {ABILITY_TORRENT, 1},
    {ABILITY_CONTRARY, 15},
    {ABILITY_ARENA_TRAP, 35},
    {ABILITY_COUNTER, 45},
    ABILITY_SET_END
};

static const struct AbilitySetter sRascalootAbilitySet[] = 
{
    {ABILITY_OVERGROW, 1},
    {ABILITY_SKILL_LINK, 15},
    {ABILITY_HARVEST, 30},
    {ABILITY_BERRY_BOOST, 45},
    ABILITY_SET_END
};

static const struct AbilitySetter sEmborypsAbilitySet[] = 
{
    {ABILITY_BLAZE, 1},
    {ABILITY_MAGMA_ARMOR, 15},
    {ABILITY_FLASH_FIRE, 30},
    {ABILITY_AUTOSUB, 45},
    ABILITY_SET_END
};

static const struct AbilitySetter sHuntorypsAbilitySet[] = 
{
    {ABILITY_BLAZE, 1},
    {ABILITY_FLASH_FIRE, 15},
    {ABILITY_EARLY_BIRD, 30},
    {ABILITY_AUTOSUB, 45},
    ABILITY_SET_END
};

static const struct AbilitySetter sRiptorypsAbilitySet[] = 
{
    {ABILITY_BLAZE, 1},
    {ABILITY_MAGMA_ARMOR, 15},
    {ABILITY_FLASH_FIRE, 30},
    {ABILITY_AUTOSUB, 45},
    ABILITY_SET_END
};

static const struct AbilitySetter sVaypingAbilitySet[] = 
{
    {ABILITY_LEVITATE, 1},
    {ABILITY_STENCH, 20},
    {ABILITY_VOLT_ABSORB, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sChad_Bug_1AbilitySet[] = 
{
    {ABILITY_POISON_POINT, 1},
    {ABILITY_SKILL_LINK, 16},
    {ABILITY_COMPOUND_EYES, 34},
    ABILITY_SET_END
};

static const struct AbilitySetter sKabowlAbilitySet[] = 
{
    {ABILITY_FLAME_BODY, 1},
    {ABILITY_SERENE_GRACE, 20},
    {ABILITY_FLASH_FIRE, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sCactarAbilitySet[] = 
{
    {ABILITY_ROUGH_SKIN, 1},
    {ABILITY_STURDY, 22},
    {ABILITY_SAND_FORCE, 41},
    ABILITY_SET_END
};

static const struct AbilitySetter sLutradorAbilitySet[] = 
{
    {ABILITY_IRON_FIST, 1},
    {ABILITY_SCRAPPY, 22},
    {ABILITY_SWIFT_SWIM, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sPhotogeistAbilitySet[] =
{
    {ABILITY_FLARE_BOOST, 1},
    {ABILITY_UNBURDEN, 15},
    {ABILITY_AFTERMATH, 30},
    {ABILITY_RESURRECTION, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sDumbellionAbilitySet[] = 
{
    {ABILITY_GUTS, 1},
    {ABILITY_DEFIANT, 30},
    {ABILITY_SHEER_FORCE, 48},
    ABILITY_SET_END
};

static const struct AbilitySetter sLotadAbilitySet[] = 
{
    {ABILITY_OWN_TEMPO, 1},
    {ABILITY_HYDRATION, 13},
    {ABILITY_RAIN_DISH, 27},
    {ABILITY_SWIFT_SWIM, 41},
    ABILITY_SET_END
};

static const struct AbilitySetter sBillfaloAbilitySet[] = 
{
    {ABILITY_ANGER_POINT, 1},
    {ABILITY_INTIMIDATE, 15},
    {ABILITY_SAP_SIPPER, 32},
    {ABILITY_BEAST_BOOST, 50},
    {ABILITY_HUGE_POWER, 150},
    ABILITY_SET_END
};

static const struct AbilitySetter sSablizzardAbilitySet[] = 
{
    {ABILITY_DEFEATIST, 1},
    {ABILITY_ICE_SCALES, 25},
    {ABILITY_SLUSH_RUSH, 42},
    ABILITY_SET_END
};

static const struct AbilitySetter sPassimianAbilitySet[] = 
{
    {ABILITY_RECEIVER, 1},
    {ABILITY_DEFIANT, 28},
    {ABILITY_CONTRARY, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sContraramAbilitySet[] = 
{
    {ABILITY_FLASH_FIRE, 1},
    {ABILITY_REFRIGERATE, 22},
    {ABILITY_SLUSH_RUSH, 40},
    {ABILITY_CHLOROPHYLL, 40},
    ABILITY_SET_END
};

static const struct AbilitySetter sDracasterAbilitySet[] = 
{
    {ABILITY_DARK_TETHER, 1},
    {ABILITY_PRESSURE, 1},
    {ABILITY_MAGIC_BOUNCE, 1},
    {ABILITY_MAGICIAN, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sTogekissAbilitySet[] = 
{
    {ABILITY_HUSTLE, 1},
    {ABILITY_SUPER_LUCK, 10},
    {ABILITY_INFILTRATOR, 35},
    {ABILITY_SERENE_GRACE, 55},
    ABILITY_SET_END
};

static const struct AbilitySetter sSpiritombAbilitySet[] = 
{
    {ABILITY_PRESSURE, 1},
    {ABILITY_ARENA_TRAP, 60},
    ABILITY_SET_END
};

static const struct AbilitySetter sNevawokAbilitySet[] = 
{
    {ABILITY_LIMBER, 1},
    {ABILITY_QUICK_FEET, 22},
    {ABILITY_STEADFAST, 46},
    ABILITY_SET_END
};

static const struct AbilitySetter sMega_DewgongAbilitySet[] =
{
    {ABILITY_PSYCHO_SHIFT, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sMega_GengarAbilitySet[] =
{
    {ABILITY_MEGA_GENGAR_ABILITY, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sEscaratacoAbilitySet[] =
{
    {ABILITY_EFFECT_SPORE, 1},
    {ABILITY_DRY_SKIN, 8},
    {ABILITY_DAMP, 15},
    {ABILITY_OVERCOAT, 24},
    {ABILITY_STURDY, 32},
    ABILITY_SET_END
};

static const struct AbilitySetter sPlasmungAbilitySet[] =
{
    {ABILITY_INTIMIDATE, 1},
    {ABILITY_DEFIANT, 18},
    {ABILITY_GALVANIZE, 34},
    {ABILITY_SWORD_LUNGE, 50},
    ABILITY_SET_END
};

static const struct AbilitySetter sSnoumeseAbilitySet[] =
{
    {ABILITY_INFILTRATOR, 1},
    {ABILITY_CHARISMA, 18},
    {ABILITY_UNAWARE, 31},
    {ABILITY_ICE_SCALES, 47},
    ABILITY_SET_END
};

static const struct AbilitySetter sFrentoadAbilitySet[] = 
{
    {ABILITY_CUTE_CHARM, 1},
    {ABILITY_RUN_AWAY, 1},
    {ABILITY_FLAME_BODY, 10},
    {ABILITY_PRANKSTER, 21},
    ABILITY_SET_END
};

static const struct AbilitySetter sRabatoastAbilitySet[] = 
{
    {ABILITY_MAGMA_ARMOR, 1},
    {ABILITY_FLAME_BODY, 10},
    {ABILITY_PRANKSTER, 21},
    ABILITY_SET_END
};

static const struct AbilitySetter sCloclockAbilitySet[] = 
{
    {ABILITY_SOUNDPROOF, 1},
    {ABILITY_SCREEN_CLEANER, 10},
    {ABILITY_FILTER, 21},
    {ABILITY_TECHNICIAN, 31},
    {ABILITY_TIME_STOP, 40},
    ABILITY_SET_END
};

//MAGM6 Abilities

static const struct AbilitySetter sBlazikenAbilitySet[] = 
{
    {ABILITY_SPEED_BOOST, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sPrimeapeAbilitySet[] = 
{
    {ABILITY_SHADOW_PRIMEAPE, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sNidokingAbilitySet[] = 
{
    {ABILITY_SHADOW_NIDOKING, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sNidoqueenAbilitySet[] = 
{
    {ABILITY_SHADOW_NIDOQUEEN, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sRhydonAbilitySet[] = 
{
    {ABILITY_SHADOW_RHYDON, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sShadowCharizardAbilitySet[] = 
{
    {ABILITY_ABYSSAL, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter sCheetoAbilitySet[] = 
{
    {ABILITY_MATT_BOSS_FIGHT, 1},
    ABILITY_SET_END
};

static const struct AbilitySetter *const sAbilitySetterLearnsets[NUM_SPECIES] = 
{
    [SPECIES_BULBASAUR] = sBulbasaurAbilitySet,
    [SPECIES_MUDKIP] = sMudkipAbilitySet,
    [SPECIES_PIDGEY] = sPidgeyAbilitySet,
    [SPECIES_PIDGEOTTO] = sPidgeyAbilitySet,
    [SPECIES_PIDGEOT] = sPidgeyAbilitySet,
    [SPECIES_SENTRET] = sSentretAbilitySet,
    [SPECIES_FURRET] = sSentretAbilitySet,
    [SPECIES_LILEEP] = sLileepAbilitySet,
    [SPECIES_CRADILY] = sLileepAbilitySet,
    [SPECIES_ANORITH] = sAnorithAbilitySet,
    [SPECIES_ARMALDO] = sAnorithAbilitySet,
    [SPECIES_MAGNEMITE] = sMagnemiteAbilitySet,
    [SPECIES_MAGNETON] = sMagnemiteAbilitySet,
    [SPECIES_SANDSHREW] = sSandshrewAbilitySet,
    [SPECIES_SANDSLASH] = sSandshrewAbilitySet,
    [SPECIES_ODDISH] = sOddishAbilitySet,
    [SPECIES_GLOOM] = sOddishAbilitySet,
    [SPECIES_VILEPLUME] = sOddishAbilitySet,
    [SPECIES_GROWLITHE] = sGrowlitheAbilitySet,
    [SPECIES_ARCANINE] = sGrowlitheAbilitySet,
    [SPECIES_PHANPY] = sPhanpyAbilitySet,
    [SPECIES_DONPHAN] = sPhanpyAbilitySet,
    [SPECIES_RHYHORN] = sRhyhornAbilitySet,
    //[SPECIES_RHYDON] = sRhyhornAbilitySet,
    [SPECIES_EEVEE] = sEeveeAbilitySet,
    [SPECIES_JOLTEON] = sJolteonAbilitySet,
    [SPECIES_VAPOREON] = sVaporeonAbilitySet,
    [SPECIES_FLAREON] = sFlareonAbilitySet,
    [SPECIES_UMBREON] = sUmbreonAbilitySet,
    [SPECIES_ESPEON] = sEspeonAbilitySet,
    [SPECIES_WEEDLE] = sWeedleAbilitySet,
    [SPECIES_KAKUNA] = sKakunaAbilitySet,
    [SPECIES_BEEDRILL] = sBeedrillAbilitySet,
    [SPECIES_CATERPIE] = sCaterpieAbilitySet,
    [SPECIES_METAPOD] = sMetapodAbilitySet,
    [SPECIES_BUTTERFREE] = sButterfreeAbilitySet,
    [SPECIES_CHINCHOU] = sChinchouAbilitySet,
    [SPECIES_LANTURN] = sChinchouAbilitySet,
    [SPECIES_HOOTHOOT] = sHoothootAbilitySet,
    [SPECIES_NOCTOWL] = sNoctowlAbilitySet,
    [SPECIES_SPINARAK] = sSpinarakAbilitySet,
    [SPECIES_ARIADOS] = sSpinarakAbilitySet,
    [SPECIES_MURKROW] = sMurkrowAbilitySet,
    [SPECIES_MISDREAVUS] = sMisdreavusAbilitySet,
    [SPECIES_HOUNDOUR] = sHoundourAbilitySet,
    [SPECIES_HOUNDOOM] = sHoundourAbilitySet,
    [SPECIES_SCYTHER] = sScytherAbilitySet,
    [SPECIES_SCIZOR] = sScizorAbilitySet,
    [SPECIES_DUSKULL] = sDuskullAbilitySet,
    [SPECIES_DUSCLOPS] = sDusclopsAbilitySet,
    [SPECIES_SLAKOTH] = sSlakothAbilitySet,
    [SPECIES_VIGOROTH] = sSlakothAbilitySet,
    [SPECIES_SLAKING] = sSlakothAbilitySet,
    [SPECIES_NINJASK] = sNinjaskAbilitySet,
    [SPECIES_SHEDINJA] = sShedinjaAbilitySet,
    [SPECIES_CLEFAIRY] = sClefairyAbilitySet,
    [SPECIES_CLEFABLE] = sClefairyAbilitySet,
    [SPECIES_MANKEY] = sMankeyAbilitySet,
    [SPECIES_PRIMEAPE] = sPrimeapeAbilitySet,
    [SPECIES_MACHOP] = sMachopAbilitySet,
    [SPECIES_MACHOKE] = sMachopAbilitySet,
    [SPECIES_MACHAMP] = sMachopAbilitySet,
    [SPECIES_GEODUDE] = sGeodudeAbilitySet,
    [SPECIES_GRAVELER] = sGeodudeAbilitySet,
    [SPECIES_GOLEM] = sGeodudeAbilitySet,
    [SPECIES_CUBONE] = sCuboneAbilitySet,
    [SPECIES_MAROWAK] = sCuboneAbilitySet,
    [SPECIES_ONIX] = sOnixAbilitySet,
    [SPECIES_STEELIX] = sSteelixAbilitySet,
    [SPECIES_SNORLAX] = sSnorlaxAbilitySet,
    [SPECIES_HOPPIP] = sHoppipAbilitySet,
    [SPECIES_SKIPLOOM] = sHoppipAbilitySet,
    [SPECIES_JUMPLUFF] = sHoppipAbilitySet,
    [SPECIES_ABSOL] = sAbsolAbilitySet,
    [SPECIES_ARON] = sAronAbilitySet,
    [SPECIES_LAIRON] = sAronAbilitySet,
    [SPECIES_AGGRON] = sAronAbilitySet,
    [SPECIES_MEDITITE] = sMedititeAbilitySet,
    [SPECIES_MEDICHAM] = sMedititeAbilitySet,
    [SPECIES_MAKUHITA] = sMakuhitaAbilitySet,
    [SPECIES_HARIYAMA] = sMakuhitaAbilitySet,
    [SPECIES_DIGLETT] = sDiglettAbilitySet,
    [SPECIES_DUGTRIO] = sDiglettAbilitySet,
    [SPECIES_SABLEYE] = sSableyeAbilitySet,
    [SPECIES_LUNATONE] = sLunatoneAbilitySet,
    [SPECIES_SOLROCK] = sSolrockAbilitySet,
    [SPECIES_ZUBAT] = sZubatAbilitySet,
    [SPECIES_GOLBAT] = sZubatAbilitySet,
    [SPECIES_CROBAT] = sZubatAbilitySet,
    [SPECIES_KOFFING] = sKoffingbilitySet,
    [SPECIES_WEEZING] = sKoffingbilitySet,
    [SPECIES_MAGMAR] = sMagmarAbilitySet,
    [SPECIES_SLUGMA] = sSlugmaAbilitySet,
    [SPECIES_MAGCARGO] = sMagcargoAbilitySet,
    [SPECIES_NUMEL] = sNumelAbilitySet,
    [SPECIES_CAMERUPT] = sNumelAbilitySet,
    [SPECIES_JYNX] = sJynxAbilitySet,
    [SPECIES_SNEASEL] = sSneaselAbilitySet,
    [SPECIES_SNORUNT] = sSnoruntAbilitySet,
    [SPECIES_GLALIE] = sGlalieAbilitySet,
    [SPECIES_TEDDIURSA] = sTeddiursaAbilitySet,
    [SPECIES_URSARING] = sUrsaringAbilitySet,
    [SPECIES_SWINUB] = sSwinubAbilitySet,
    [SPECIES_PILOSWINE] = sSwinubAbilitySet,
    [SPECIES_MARILL] = sMarillAbilitySet,
    [SPECIES_AZUMARILL] = sMarillAbilitySet,
    [SPECIES_POLIWAG] = sPoliwagAbilitySet,
    [SPECIES_POLIWHIRL] = sPoliwhirlAbilitySet,
    [SPECIES_POLIWRATH] = sPoliwhirlAbilitySet,
    [SPECIES_TANGELA] = sTangelaAbilitySet,
    [SPECIES_YANMA] = sYanmaAbilitySet,
    [SPECIES_RATTATA] = sRattataAbilitySet,
    [SPECIES_RATICATE] = sRattataAbilitySet,
    [SPECIES_GRIMER] = sGrimerAbilitySet,
    [SPECIES_MUK] = sGrimerAbilitySet,
    [SPECIES_ABRA] = sAbraAbilitySet,
    [SPECIES_KADABRA] = sAbraAbilitySet,
    [SPECIES_ALAKAZAM] = sAlakazamAbilitySet,
    [SPECIES_ELECTABUZZ] = sElectabuzzAbilitySet,
    [SPECIES_FEEBAS] = sFeebasAbilitySet,
    [SPECIES_MILOTIC] = sFeebasAbilitySet,
    [SPECIES_MAGIKARP] = sMagikarpAbilitySet,
    [SPECIES_GYARADOS] = sGyaradosAbilitySet,
    [SPECIES_CORSOLA] = sCorsolaAbilitySet,
    [SPECIES_GASTLY] = sGastlyAbilitySet,
    [SPECIES_HAUNTER] = sGastlyAbilitySet,
    [SPECIES_GENGAR] = sGengarAbilitySet,
    [SPECIES_SEEL] = sSeelAbilitySet,
    [SPECIES_DEWGONG] = sSeelAbilitySet,
    //[SPECIES_DEWGONG_REGIONAL] = sDewgongRegionalAbilitySet,
    [SPECIES_DRATINI] = sDratiniAbilitySet,
    [SPECIES_DRAGONAIR] = sDratiniAbilitySet,
    [SPECIES_DRAGONITE] = sDragoniteAbilitySet,
    [SPECIES_LARVITAR] = sLarvitarAbilitySet,
    [SPECIES_PUPITAR] = sPupitarAbilitySet,
    [SPECIES_TYRANITAR] = sTyranitarAbilitySet,
    [SPECIES_BAGON] = sBagonAbilitySet,
    [SPECIES_SHELGON] = sShelgonAbilitySet,
    [SPECIES_SALAMENCE] = sSalamenceAbilitySet,
    [SPECIES_MAREEP] = sMareepAbilitySet,
    [SPECIES_FLAAFFY] = sMareepAbilitySet,
    [SPECIES_AMPHAROS] = sAmpharosAbilitySet,
    [SPECIES_PIKACHU] = sPikachuAbilitySet,
    [SPECIES_RAICHU] = sRiachuAbilitySet,
    [SPECIES_VOLTORB] = sVoltorbAbilitySet,
    [SPECIES_ELECTRODE] = sVoltorbAbilitySet,
    [SPECIES_FLOBRA] = sFlobraAbilitySet,
    [SPECIES_MORPHLO] = sMorphloAbilitySet,
    [SPECIES_MECHOBRA] = sMorphloAbilitySet,
    [SPECIES_RASCALOOT] = sRascalootAbilitySet,
    [SPECIES_BANDITHUG] = sRascalootAbilitySet,
    [SPECIES_RUTHLASH] = sRascalootAbilitySet,
    [SPECIES_EMBORYPS] = sEmborypsAbilitySet,
    [SPECIES_HUNTORYPS] = sHuntorypsAbilitySet,
    [SPECIES_RIPTORYPS] = sRiptorypsAbilitySet,
    [SPECIES_VAYPING] = sVaypingAbilitySet,
    [SPECIES_CHAD_BUG_1] = sChad_Bug_1AbilitySet,
    [SPECIES_CHAD_BUG_2] = sChad_Bug_1AbilitySet,
    [SPECIES_KABOWL] = sKabowlAbilitySet,
    [SPECIES_BOWLAST] = sKabowlAbilitySet,
    [SPECIES_CACTAR] = sCactarAbilitySet,
    [SPECIES_CRACTHORN] = sCactarAbilitySet,
    [SPECIES_CRACKTUSS] = sCactarAbilitySet,
    [SPECIES_OTDORBLE] = sLutradorAbilitySet,
    [SPECIES_LUTRADOR] = sLutradorAbilitySet,
    [SPECIES_LOTAD] = sLotadAbilitySet,
    [SPECIES_LOMBRE] = sLotadAbilitySet,
    [SPECIES_LUDICOLO] = sLotadAbilitySet,
    [SPECIES_PHOKAI] = sPhotogeistAbilitySet,
    [SPECIES_PHOTASM] = sPhotogeistAbilitySet,
    [SPECIES_PHOTOGEIST] = sPhotogeistAbilitySet,
    [SPECIES_DUMBELLION] = sDumbellionAbilitySet,
    [SPECIES_BARBELLION] = sDumbellionAbilitySet,
    [SPECIES_BILLFALO] = sBillfaloAbilitySet,
    [SPECIES_CONTRARAM] = sContraramAbilitySet,
    [SPECIES_TOGEKISS] = sTogekissAbilitySet,
    [SPECIES_SPIRITOMB] = sSpiritombAbilitySet,
    [SPECIES_NEVAWOK] = sNevawokAbilitySet,
    [SPECIES_MEGA_DEWGONG] = sMega_DewgongAbilitySet,
    [SPECIES_FILLER_8] = sMegaHoundoomAbilitySet,
    [SPECIES_FILLER_9] = sMega_GengarAbilitySet,
    [SPECIES_TAQUITTLE] = sEscaratacoAbilitySet,
    [SPECIES_ESCARATACO] = sEscaratacoAbilitySet,
    [SPECIES_PLASMUNG] = sPlasmungAbilitySet,
    [SPECIES_GRUNTAZE] = sPlasmungAbilitySet,
    [SPECIES_ELITETRIC] = sPlasmungAbilitySet,
    [SPECIES_SNOUMESE] = sSnoumeseAbilitySet,
    [SPECIES_SNOUBAUL] = sSnoumeseAbilitySet,
    [SPECIES_INVERTEBRAKE] = sInvertebrakeAbilitySet,
    [SPECIES_SKARMORY] = sSkarmoryAbilitySet,
    [SPECIES_FRENTOAD] = sFrentoadAbilitySet,
    [SPECIES_RABATOAST] = sRabatoastAbilitySet,
    [SPECIES_HAAGLET] = sHaagletAbilitySet,
    [SPECIES_WARTHAAG] = sHaagletAbilitySet,
    [SPECIES_DRACASTER] = sDracasterAbilitySet,
    [SPECIES_PASSIMIAN] = sPassimianAbilitySet,
    [SPECIES_SABLIZZARD] = sSablizzardAbilitySet,
    [SPECIES_CLOCLOCK] = sCloclockAbilitySet,
    [SPECIES_WARKLOCK] = sCloclockAbilitySet,
    [SPECIES_BLAZIKEN] = sBlazikenAbilitySet,
    [SPECIES_NIDOKING] = sNidokingAbilitySet,
    [SPECIES_NIDOQUEEN] = sNidoqueenAbilitySet,
    [SPECIES_RHYDON] = sRhydonAbilitySet,
    [SPECIES_SHADOW_CHARIZARD] = sShadowCharizardAbilitySet,
    [SPECIES_CHARIZARD_X] = sShadowCharizardAbilitySet,
    [SPECIES_CHANSEY] = sChanseyAbilitySet,
    [SPECIES_ABYSSALDRAGONFIRSTEVO] = sAbyssalDragonAbilitySet,
    [SPECIES_ABYSSALDRAGONSECONDEVO] = sAbyssalDragonAbilitySet,
    [SPECIES_ABYSSALDRAGONTHIRDEVO] = sAbyssalDragonAbilitySet,
    [SPECIES_CHEETO] = sCheetoAbilitySet,
    
    













//etc...
};
