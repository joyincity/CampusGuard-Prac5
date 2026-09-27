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

std::string Incident::getAlert() {
    return type;
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
}

Incident::~Incident(){
    delete status;
}