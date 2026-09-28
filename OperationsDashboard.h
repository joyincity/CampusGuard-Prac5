#ifndef OPERATIONSDASHBOARD_H
#define OPERATIONSDASHBOARD_H
#include "OperationAction.h"
#include <string>
#include <vector>
#include <iostream>

class OperationsDashboard{
    private:
        std::vector<OperationAction*> ActionLog;
        
    public:
        void setCommand(OperationAction * command);
        void executeCommand();
        void undoLast();
        ~OperationsDashboard();
        
};

#endif