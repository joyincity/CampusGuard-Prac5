#ifndef CANCELACTION_H
#define CANCELACTION_H
#include "EmergencyChannel.h"
#include "OperationAction.h"

class CancelAction: public OperationAction{
    private:
        EmergencyChannel * receiver;
    public:
        CancelAction(EmergencyChannel * receiver);
        void execute()override;

};
#endif
