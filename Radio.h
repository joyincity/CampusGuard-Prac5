#ifndef RADIO_H
#define RADIO_H

#include "Unit.h"

class Radio{
    public:
        virtual void notify(Unit* unit) = 0;
};

#endif
