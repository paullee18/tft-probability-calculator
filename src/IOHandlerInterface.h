#ifndef IOHANDLERINTERFACE_H
#define IOHANDLERINTERFACE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class IOHandlerInterface {
    public:
    virtual int get_int_input(string output_query, int lower_limit=numeric_limits<int>::min(),
            int upper_limit=numeric_limits<int>::max()) = 0;
    virtual void output_result(int, double) = 0;
};

#endif