#ifndef OPERATIONSDASHBOARD_H
#define OPERATIONSDASHBOARD_H
#include "OperationAction.h"
#include <string>
#include <vector>

class OperationsDashboard{
    private:
        std::vector<OperationAction*>commandHistory;
        OperationAction * command;
    public:
        void setCommand(OperationAction * command);
        void executeCommand();
        void undo();
};

#endif