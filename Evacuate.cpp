#include "Evacuate.h"

Evacuate::Evacuate(EmergencyChannel * receiver, Incident* incident){
        this->receiver = receiver;
        this->areaCode =incident->getAreaCode();
}
    void Evacuate:: execute(){
        receiver->evacuate(areaCode);
    }

    void Evacuate::undo(){
        receiver->cancelEvacuation(areaCode);
    }
        void Evacuate::ActionDescription()const{
            std::cout<<"Evacuate area with area code: "<< areaCode<<std::endl;
        }