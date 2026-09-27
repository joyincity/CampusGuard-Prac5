#ifndef EMERGENCYCHANNEL_H
#define EMERGENCYCHANNEL_H

#include "Radio.h"
#include "Unit.h"

class EmergencyChannel : public Radio{
    public:
        void notify(Unit* unit) override;
        void dispatchUnit();
        void cancel();
        void evacuate();

};

#endif
