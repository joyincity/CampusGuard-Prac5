#ifndef DISPATCHUNIT_H
#define DISPATCHUNIT_H
#include "EmergencyResponseHandler.h"
#include "OperationAction.h"
#include "string"

class DispatchUnit: public OperationAction{
    private:
        std::string unitType;
        EmergencyResponseHandler * receiver;
    public:
        DispatchUnit(std::string unitType, EmergencyResponseHandler * receiver);
        void execute()override;

};
#endif