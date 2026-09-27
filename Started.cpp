#include "Started.h"
#include "Reported.h"
#include "Incident.h"

Started::Started(Incident* incident) : Status(incident){}

std::string Started::getName() {
    return "Started";
}

void Started::nextState(){
    incident->setStatus(new Reported(incident));
}
