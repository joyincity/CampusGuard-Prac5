#ifndef EVACUATION_H
#define EVACUATION_H

#include "EmergencyChannel.h"
#include "OperationAction.h"
#include "Incident.h"
#include <iostream>
class Evacuate: public OperationAction{
    private:
        int areaCode;
        EmergencyChannel * receiver;
    public:
        Evacuate(EmergencyChannel * receiver, Incident* incident);
        void execute()override;
        void undo()override;
        void ActionDescription()const override;

};
#endif
