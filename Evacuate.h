#ifndef EVACUATION_H
#define EVACUATION_H

#include "EmergencyChannel.h"
#include "OperationAction.h"

class Evacuate: public OperationAction{
    private:
        int areaCode;
        EmergencyChannel * receiver;
    public:
        Evacuate(EmergencyChannel * receiver, int areaCode);
        void execute()override;

};
#endif
