#include "Incident.h"
#include "Status.h"
#include "Started.h"

#include <iostream>

Incident::Incident(Radio* radio,int incidentID,int areaCode, std::string type) {
    this->radio = radio;
    this->incidentID = incidentID;
    this->areaCode = areaCode;
    this->type = type;
    this->status = new Started(this);

    this->radio->addUnit(this);
}

void Incident::print() {
    std::cout << "Incident Type: " << type;
    if (status){
        std::cout << "\n\tStatus: " << status->getName();
    }
    std::cout <<  std::endl;
}

void Incident::statusChanged() {
    std::cout << "Incident changed: " << status->getName() << std::endl;
    this->radio->notify(this);
}

std::string Incident::getAlert() {
    return type;
}
int Incident::getIncidentID(){
    return incidentID;
}
int Incident::getAreaCode(){
    return areaCode ;
}

void Incident::handleAlert(std::string alert) {
    // TODO
}

void Incident::cancelOperation(int) {
   
}

void Incident::advanceStatus() {
    if (status){
        status->nextState();
    }
}

void Incident::setStatus(Status* newStatus){
    if (status){
        delete status;
    }
    status = newStatus;
    std::cout << "Incident Status set to: " << status->getName() << std::endl;

    if (status->getName() == "Reported") {
        this->radio->notify(this);
    }
}

Incident::~Incident(){
    delete status;
}
