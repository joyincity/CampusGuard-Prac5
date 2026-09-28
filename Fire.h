#ifndef FIRE_H
#define FIRE_H

#include "Incident.h"

class Fire : public Incident{
    public:
    Fire(Radio* radio,int incidentID, int areaCode);
};

#endif