#include "DispatchUnit.h"

DispatchUnit::DispatchUnit(EmergencyChannel * receiver,int incidentId){
    
    this->receiver= receiver;
    this->incidentID= incidentId;
}
void DispatchUnit::execute(){
            receiver->dispatch(incidentID);
        }
 void DispatchUnit:: undo(){
    receiver->cancelDispatch();
 }
void DispatchUnit::ActionDescription()const{
    std::cout<<"Dispatched unit to incident " << incidentID<<std::endl;
}
