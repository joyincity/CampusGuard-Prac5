#ifndef DISPATCHUNIT_H
#define DISPATCHUNIT_H

#include "EmergencyChannel.h"
#include "OperationAction.h"
#include "Incident.h"
#include <string>
#include <iostream>

class DispatchUnit: public OperationAction{
    private:
        int incidentID;
        int areaCode;
        EmergencyChannel * receiver;
        
    public:
        DispatchUnit(EmergencyChannel * receiver,Incident* incident);
        void execute()override;
        void undo()override;
        void ActionDescription()const override;

};
#endif