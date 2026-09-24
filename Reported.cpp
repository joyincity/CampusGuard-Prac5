#include "Reported.h"
#include "Started.h"
#include "Incident.h"

Reported::Reported(Incident* incident): Status("Reported",incident) {}

void Reported::nextState() {
    incident->setStatus(new Started(incident));
}