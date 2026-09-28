#include "Evacuate.h"

Evacuate::Evacuate(EmergencyChannel * receiver, int areaCode){
        this->receiver = receiver;
        this->areaCode = areaCode;
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