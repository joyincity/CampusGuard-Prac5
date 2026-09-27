#include "Resolved.h"

Resolved::Resolved(Incident* incident): Status(incident) {}

std::string Resolved::getName() {
    return "Resolved";
}

void Resolved::nextState(){}
