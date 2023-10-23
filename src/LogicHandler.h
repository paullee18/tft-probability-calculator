#ifndef LOGICHANDLER_H
#define LOGICHANDLER_H

#include "IOHandlerInterface.h"
#include "MatrixHandlerInterface.h"

class LogicHandler {
public:
    LogicHandler(IOHandlerInterface& io_handler, MatrixHandlerInterface& matrix_handler);

    void run();
private:
    IOHandlerInterface& io_handler;
    MatrixHandlerInterface& matrix_handler;
};

#endif