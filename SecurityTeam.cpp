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
}

void SecurityTeam::cancelOperation() {
    this->guardsDispatched = 0;
    this->deployable = false;
}

void SecurityTeam::dispatch() {
    if (!this->deployable) {
        return;
    }

    std::cout << "Security team dispatched!" << std::endl;
    this->guardsDispatched++;
}
