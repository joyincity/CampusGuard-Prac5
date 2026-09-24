#include "SecurityThreat.h"
#include "Reported.h"

SecurityThreat::SecurityThreat() : Incident("SecurityThreat"){
    setStatus(new Reported(this));
}