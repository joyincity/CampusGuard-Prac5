#ifndef SECURITYTHREAT_H
#define SECURITYTHREAT_H

#include "Incident.h"

class SecurityThreat : public Incident {
    public:
    SecurityThreat(Radio* radio,int incidentID, int areaCode);
};

#endif