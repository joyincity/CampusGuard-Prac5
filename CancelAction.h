#ifndef CANCELACTION_H
#define CANCELACTION_H
#include "EmergencyChannel.h"
#include "OperationAction.h"

class CancelAction: public OperationAction{
    private:
        
        OperationAction* action;
    public:
        CancelAction(OperationAction* action);
        void execute()override;
        void undo()override;
        void ActionDescription()const override;

};
#endif
