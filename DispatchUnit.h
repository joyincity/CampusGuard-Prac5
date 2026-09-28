#ifndef DISPATCHUNIT_H
#define DISPATCHUNIT_H

#include "EmergencyChannel.h"
#include "OperationAction.h"
#include <string>
#include <iostream>

class DispatchUnit: public OperationAction{
    private:
        int incidentID;
        EmergencyChannel * receiver;
        
    public:
        DispatchUnit(EmergencyChannel * receiver,int incidentID);
        void execute()override;
        void undo()override;
        void ActionDescription()const override;

};
#endif