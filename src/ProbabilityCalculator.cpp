#include "ProbabilityCalculator.h"

double ProbabilityCalculator::get_probability(int level, int tier, int copies_out, int same_tier_out) {
    double p_get_same_tier = constants::LEVEL_ODDS[level-1][tier-1];
    double copies_remaining = constants::TIER_COPIES[tier-1] - copies_out;
    double same_tier_remaining = constants::TIER_TOTAL[tier-1] - same_tier_out;
    return max(0.0, p_get_same_tier * (copies_remaining / same_tier_remaining));
}