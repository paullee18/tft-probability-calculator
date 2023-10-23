#ifndef IOHANDLER_H
#define IOHANDLER_H

#include "IOHandlerInterface.h"

class IOHandler : public IOHandlerInterface {
public:
    int get_int_input(string output_query, int lower_limit=numeric_limits<int>::min(),
            int upper_limit=numeric_limits<int>::max()) override;
    void output_result(int, double) override;
};

#endif