#include "Reported.h"
#include "Resolved.h"
#include "Incident.h"

Reported::Reported(Incident* incident): Status(incident) {}

std::string Reported::getName() {
    return "Reported";
}

void Reported::nextState() {
    incident->setStatus(new Resolved(incident));
}
