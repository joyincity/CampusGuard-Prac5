#ifndef DISPATCHUNIT_H
#define DISPATCHUNIT_H

#include "EmergencyChannel.h"
#include "OperationAction.h"
#include "string"

class DispatchUnit: public OperationAction{
    private:
        std::string unitType;
        EmergencyChannel * receiver;
    public:
        DispatchUnit(std::string unitType, EmergencyChannel * receiver);
        void execute()override;

};
#endif