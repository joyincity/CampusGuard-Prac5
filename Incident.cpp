#include "Incident.h"
#include "Status.h"
#include <iostream>

Incident::Incident(std::string type): type(type), status(nullptr) {}

Incident::~Incident(){
    delete status;
}

std::string Incident::getType() const {
    return type;
}

void Incident::print() const{
    std::cout << "Incident Type: " << type;
    if (status){
        std::cout << "\nStatus: " << status->getName();
    }
    std::cout <<  std::endl;
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