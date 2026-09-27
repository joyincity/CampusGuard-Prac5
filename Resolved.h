#ifndef RESOLVED_H
#define RESOLVED_H

#include "Status.h"

class Resolved : public Status{
    public:
    Resolved(Incident* incident);
    std::string getName() override;
    void nextState() override;
};

#endif