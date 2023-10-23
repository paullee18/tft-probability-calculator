#include "LogicHandler.h"
#include "../include/config.h"

LogicHandler::LogicHandler(IOHandlerInterface& io_handler, MatrixHandlerInterface& matrix_handler)
    : io_handler(io_handler), matrix_handler(matrix_handler) {}

void LogicHandler::run() {
    int level = this->io_handler.get_int_input("Level(1-10): ", constants::LEVEL_LOWER_LIMIT, constants::LEVEL_UPPER_LIMIT);
    int tier = this->io_handler.get_int_input("Unit tier(1-5): ", constants::TIER_LOWER_LIMIT, constants::TIER_UPPER_LIMIT);
    int copies_out = this->io_handler.get_int_input("Number of copies of this unit already out: ");
    int same_tier_out = this->io_handler.get_int_input("Number of units of same cost already out: ");
    int gold = this->io_handler.get_int_input("Amount of gold you want to use: ", constants::GOLD_LOWER_LIMIT);

    vector<vector<double>> transition_matrix = this->matrix_handler.get_transition_matrix(level, tier, copies_out, same_tier_out);
    vector<vector<double>> multiplied_matrix = this->matrix_handler.matrix_power(transition_matrix, 
        gold / constants::GOLD_PER_ROLL * constants::SLOTS_PER_ROLL, 10);
    
    double total_probability = 0;
    for (int i=9; i>0; i--) {
        total_probability += multiplied_matrix[0][i];
        this->io_handler.output_result(i, total_probability);
    }
}