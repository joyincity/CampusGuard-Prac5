#include "Started.h"
#include "Resolved.h"
#include "Incident.h"

Started::Started(Incident* incident): Status("Started", incident){}

void Started::nextState(){
    incident->setStatus(new Resolved(incident));
}