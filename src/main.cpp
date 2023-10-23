#include <iostream>
#include <string>
#include <vector>
#include "../include/config.h"
#include "IOHandler.h"
#include "MatrixHandler.h"
#include "LogicHandler.h"

int main(int argc, char** argv) {
    IOHandler io_handler;
    MatrixHandler matrix_handler;
    LogicHandler logic_handler(io_handler, matrix_handler);
    logic_handler.run();
}

