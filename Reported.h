#ifndef REPORTED_H
#define REPORTED_H

#include "Status.h"

class Reported: public Status {
    public:
    Reported(Incident* incident);
    void nextState() override;
};

#endif