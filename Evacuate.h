#ifndef EVACUATION_H
#define EVACUATION_H
#include "EmergencyResponseHandler.h"
#include "OperationAction.h"

class Evacuate: public OperationAction{
    private:
        int areaCode;
        EmergencyResponseHandler * receiver;
    public:
        Evacuate(EmergencyResponseHandler * receiver, int areaCode);  
        void execute()override;

};
#endif