#include "MedicalTeam.h"

#include <iostream>

MedicalTeam::MedicalTeam(Radio* radio) {
    this->radio = radio;
    this->deployable = false;
    this->isDispatched = false;

    this->radio->addUnit(this);
}

void MedicalTeam::print() {
    std::cout << "MedicalTeam: isDispatched= " << (isDispatched ? "true" : "false") << ", deployable= " << (deployable ? "true" : "false") << std::endl;
}

void MedicalTeam::statusChanged() {
    //TODO
}

std::string MedicalTeam::getAlert() {
    return "";
}

void MedicalTeam::handleAlert(std::string alert) {
    this->deployable = true;
    std::cout << "MedicalTeam received alert and is ready for deployment" << std::endl;
    if(alert.rfind("EvacuateArea",0)==0){
        std::cout << "MedicalTeam received evacuation alert for area: " << alert.substr(13) << std::endl;

    }else if(alert.rfind("Cancel Evacuation",0)==0){
        std::cout << "MedicalTeam received cancel evacuation alert for area: " << alert.substr(21) << std::endl;
        this->cancelOperation();
    }
}

void MedicalTeam::cancelOperation() {
    this->deployable = false;
    this->isDispatched = false;
}

void MedicalTeam::dispatch(int incidentID) {
    if (this->deployable) {
        this->isDispatched = true;

        std::cout << "MedicalTeam dispatched to Incident "<<incidentID << std::endl;
    }
}
