#include "SecurityTeam.h"
#include <iostream>

SecurityTeam::SecurityTeam(Radio* radio) {
    this->radio = radio;
    this->guardsDispatched = 0;
    this->deployable = false;
    this->assignedArea = -1;
    this->assignedIncident= -1;
    this->isAvailable = true;

    this->radio->addUnit(this);
}

void SecurityTeam::print() {
    std::cout << "Security team: guards dispatched = " << guardsDispatched << ", deployable = " << deployable <<",incident: "<<assignedIncident<< std::endl;
}

void SecurityTeam::statusChanged() {

}

std::string SecurityTeam::getAlert() {
    return "";
}
void SecurityTeam::release(){
    this->guardsDispatched = 0;
    
    this->assignedArea =-1;
    this->assignedIncident =-1;
    this->isAvailable = true;
}
void SecurityTeam::handleAlert(std::string alert) {
    if (alert == "SecurityThreat") {
        this->deployable = true;
    }
    if(alert.rfind("EvacuateArea",0)==0){
        std::cout << "SecurityTeam is ready to evacuate area: " << alert.substr(13) << std::endl;
        this->deployable = true;;

    }else if(alert.rfind("Cancel Evacuation",0)==0){
        std::cout << "SecurityTeam received cancel evacuation alert for area: " << alert.substr(21) << std::endl;
        this->release();
    }
}

void SecurityTeam::cancelOperation(int incidentID) {
    if(this->assignedIncident!=incidentID){
        return;
    }
    std::cout<<"Securityteam stood down from Incident: "<<incidentID<<std::endl;
    release();
    
}

void SecurityTeam::dispatch(int incidentID, int areaCode){
    if (this->assignedIncident != -1 && this->assignedIncident != incidentID) {
        return;}
    if (!this->deployable) {
        return;
    }
    this->assignedIncident = incidentID;
    this->assignedArea = areaCode;
    this->isAvailable = false;
    std::cout << "Security team dispatched to Incident " << incidentID << "!" << std::endl;
    this->guardsDispatched++;
}
int SecurityTeam:: getAssignedArea(){
    return assignedArea;

}
bool SecurityTeam:: getIsAvailable(){
    return isAvailable;
}