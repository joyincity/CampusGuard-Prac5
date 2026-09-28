#include "CancelAction.h"

CancelAction::CancelAction(OperationAction* action){
        
        this->action = action;
}
    void CancelAction::execute(){
        if(action ==nullptr){
            std::cout<<"Nothing available to cancel"<<std::endl;
            return;
        }
        if(action->isCancelled()){
            std::cout<<"Action has already been cancelled"<<std::endl;
            return;
        }
        action->undo();
        action->makeCancelled();
        std::cout<<"Action successfully cancelled"<<std::endl;

    }
    void CancelAction::undo(){
        if(action==nullptr){
            return;

        };
        if(!action->isCancelled()){
            std::cout<<"Action has not been cancelled"<<std::endl;
            return;
        }
        action->execute();
        action->makeActive();
        std::cout<<"Cancellation successfully undone"<<std::endl;
    }
    void CancelAction::ActionDescription()const{
        if(action){
            action->ActionDescription();
        std::cout<<" has been cancelled"<<std::endl;
        }else{
            std::cout<<"No description available"<<std::endl;
        }
    }