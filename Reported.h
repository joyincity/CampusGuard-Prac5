#ifndef REPORTED_H
#define REPORTED_H

#include "Status.h"

class Reported: public Status {
    public:
    Reported(Incident* incident);
    std::string getName() override;
    void nextState() override;
};

#endif