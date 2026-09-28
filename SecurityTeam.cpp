#include "SecurityTeam.h"
#include <iostream>

SecurityTeam::SecurityTeam(Radio* radio) {
    this->radio = radio;
    this->guardsDispatched = 0;
    this->deployable = false;

    this->radio->addUnit(this);
}

void SecurityTeam::print() {
    std::cout << "Security team: guards dispatched = " << guardsDispatched << ", deployable = " << deployable << std::endl;
}

void SecurityTeam::statusChanged() {

}

std::string SecurityTeam::getAlert() {
    return "";
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
        this->cancelOperation();
    }
}

void SecurityTeam::cancelOperation() {
    this->guardsDispatched = 0;
    this->deployable = false;
}

void SecurityTeam::dispatch(int incidentID) {
    if (!this->deployable) {
        return;
    }

    std::cout << "Security team dispatched to Incident " << incidentID << "!" << std::endl;
    this->guardsDispatched++;
}
