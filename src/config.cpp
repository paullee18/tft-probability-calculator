#include "../include/config.h"

namespace constants
{
    const int TIER_COPIES[5] = {29,22,18,12,10};
    const int TIER_UNITS[5] = {13,13,13,12,8};
    const int TIER_TOTAL[5] = {29*13, 22*13, 18*13, 12*12, 10*8};
    const double LEVEL_ODDS[10][5] = 
    {
        {1,0,0,0,0},
        {1,0,0,0,0},
        {0.75,0.25,0,0,0},
        {0.55,0.3,0.15,0,0},
        {0.45,0.33,0.2,0.02,0},
        {0.25,0.4,0.3,0.05,0},
        {0.19,0.3,0.35,0.15,0.01},
        {0.16,0.2,0.35,0.25,0.04},
        {0.09,0.15,0.3,0.3,0.16},
        {0.05,0.1,0.2,0.4,0.25}
    };
    const int LEVEL_LOWER_LIMIT = 1;
    const int LEVEL_UPPER_LIMIT = 10;
    const int TIER_LOWER_LIMIT = 1;
    const int TIER_UPPER_LIMIT = 5;
    const int GOLD_LOWER_LIMIT = 0;
    const int GOLD_PER_ROLL = 2;
    const int SLOTS_PER_ROLL = 5;
}