#include "DispatchUnit.h"

DispatchUnit::DispatchUnit(EmergencyChannel * receiver,Incident* incident){
    
    this->receiver= receiver;
    this->incidentID= incident->getIncidentID();
    this->areaCode = incident->getAreaCode();
}
void DispatchUnit::execute(){
            receiver->dispatch(incidentID,areaCode);
        }
 void DispatchUnit:: undo(){
    receiver->cancelDispatch();
 }
void DispatchUnit::ActionDescription()const{
    std::cout<<"Dispatched unit to incident: " << incidentID<<std::endl;
}
