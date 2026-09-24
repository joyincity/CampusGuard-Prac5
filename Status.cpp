#include "Status.h"

Status::Status (std::string name, Incident* incident): name(name), incident(incident) {}

std::string Status::getName() const {
    return name;
}

Status::~Status(){}