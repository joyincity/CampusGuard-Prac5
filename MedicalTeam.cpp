#include "MedicalTeam.h"

#include <iostream>

MedicalTeam::MedicalTeam(Radio* radio) : Unit(radio) {
    this->deployable = false;
    this->isDispatched = false;
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
}

void MedicalTeam::cancelOperation() {
    this->deployable = false;
    this->isDispatched = false;
}

void MedicalTeam::dispatch() {
    if (this->deployable) {
        this->isDispatched = true;

        std::cout << "MedicalTeam dispatched." << std::endl;
    }
}
