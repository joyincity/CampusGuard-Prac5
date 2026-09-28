#include "MedicalTeam.h"

#include <iostream>

MedicalTeam::MedicalTeam(Radio* radio) {
    this->radio = radio;
    this->deployable = false;
    this->isDispatched = false;
    this->assignedIncident = -1;
    this->assignedArea = -1;
    this->isAvailable = true;
    this->radio->addUnit(this);
}

void MedicalTeam::print() {
    std::cout << "MedicalTeam: isDispatched= " << (isDispatched ? "true" : "false") << ", deployable= " << (deployable ? "true" : "false") << ",incident= "<<assignedIncident<<std::endl;
}

void MedicalTeam::statusChanged() {
    //TODO
}

std::string MedicalTeam::getAlert() {
    return "";
}
void MedicalTeam::release(){
    
    this->isDispatched =false;
    this->assignedIncident = -1;
    this->assignedArea = -1;
    this->isAvailable = true;
}

void MedicalTeam::handleAlert(std::string alert) {
    this->deployable = true;
    std::cout << "MedicalTeam received alert and is ready for deployment" << std::endl;
    if(alert.rfind("EvacuateArea",0)==0){
        std::cout << "MedicalTeam received evacuation alert for area: " << alert.substr(13) << std::endl;

    }else if(alert.rfind("Cancel Evacuation",0)==0){
        std::cout << "MedicalTeam received cancel evacuation alert for area: " << alert.substr(21) << std::endl;
        this->release();
    }
}

void MedicalTeam::cancelOperation(int incidentID) {
    if(this->assignedIncident!=incidentID){
        return;
    }
    std::cout<<"Medical team stood down from Incident: "<<incidentID<<std::endl;
    release();
}


void MedicalTeam::dispatch(int incidentID, int areaCode) {
    if (this->assignedIncident != -1 && this->assignedIncident != incidentID) {
        return;}
    if (this->deployable) {
        this->isDispatched = true;
        this->assignedIncident = incidentID;
        this->assignedArea = areaCode;
        this->isAvailable = false;
        std::cout << "MedicalTeam dispatched to Incident: "<<incidentID << std::endl;
        
    }
}
int MedicalTeam:: getAssignedArea(){
    return assignedArea;

}
bool MedicalTeam::getIsAvailable(){
    return isAvailable;
}
