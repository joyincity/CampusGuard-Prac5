#ifndef STARTED_H
#define STARTED_H

#include "Status.h"

class Started : public Status {
    public:
    Started(Incident* incident);
    void nextState() override;
};

#endif