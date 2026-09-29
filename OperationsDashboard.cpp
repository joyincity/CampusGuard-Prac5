#include "OperationsDashboard.h"


void OperationsDashboard:: setCommand(OperationAction * command){
    if(!command){
        return;
    }
    ActionLog.push_back(command);
}
void OperationsDashboard::executeCommand(){
    if(ActionLog.empty()){
        std::cout<<"No action available to execute;"<<std::endl;
        return;
    }else{
        ActionLog.back()->execute();
        
    }
}
void OperationsDashboard::undoLast(){
    if(ActionLog.empty()){
        return;
    }
    ActionLog.back()->undo();
    
}
OperationAction* OperationsDashboard::getLastCommand() const {
    return ActionLog.empty() ? nullptr : ActionLog.back();
}
OperationsDashboard::~OperationsDashboard(){
for (auto p : ActionLog) {
            delete p; 
        }
        ActionLog.clear();
    }