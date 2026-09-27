#ifndef CANCELACTION_H
#define CANCELACTION_H
#include "EmergencyResponseHandler.h"
#include "OperationAction.h"

class CancelAction: public OperationAction{
    private:
        EmergencyResponseHandler * receiver;
    public:
        CancelAction(EmergencyResponseHandler * receiver);
        void execute()override;

};
#endif