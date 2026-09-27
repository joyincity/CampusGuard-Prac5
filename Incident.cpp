#include "Incident.h"
#include "Status.h"
#include "Started.h"

#include <iostream>

Incident::Incident(Radio* radio, std::string type) : Unit(radio) {
    this->type = type;
    this->status = new Started(this);
}

void Incident::print() {
    std::cout << "Incident Type: " << type;
    if (status){
        std::cout << "\nStatus: " << status->getName();
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

void Incident::handleAlert(std::string alert) {
    // TODO
}

void Incident::cancelOperation() {
    setStatus(new Started(this));
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
}

Incident::~Incident(){
    delete status;
}
