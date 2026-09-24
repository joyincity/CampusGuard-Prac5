#include "Resolved.h"

Resolved::Resolved(Incident* incident): Status("Resolved", incident) {}

void Resolved::nextState(){}