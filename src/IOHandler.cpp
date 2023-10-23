#include "IOHandler.h"

int IOHandler::get_int_input(string output_query, int lower_limit, int upper_limit) {
    int input;
    cout << output_query;
    while (!(cin >> input) || input < lower_limit || input > upper_limit) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << output_query;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

void IOHandler::output_result(int min_copies, double probability) {
    cout << "Probability of hitting at least " << min_copies << " copies : " << probability*100 << "%" << endl;
}