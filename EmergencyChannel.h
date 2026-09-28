#ifndef EMERGENCYCHANNEL_H
#define EMERGENCYCHANNEL_H

#include "Radio.h"
#include "Unit.h"

#include <vector>

class EmergencyChannel : public Radio{
    public:
        void addUnit(Unit* unit) override;

        void notify(Unit* unit) override;
        void dispatch();
        void cancel();
        void evacuate();

        ~EmergencyChannel();
};

#endif
