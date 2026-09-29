#ifndef EMERGENCYCHANNEL_H
#define EMERGENCYCHANNEL_H

#include "Radio.h"
#include "Unit.h"
#include <string>
#include <vector>

class EmergencyChannel : public Radio{
    public:
        void addUnit(Unit* unit) override;

        void notify(Unit* unit) override;
        void dispatch(int incidentID, int areaCode);
        void cancelDispatch(int incidentID);
        void cancelEvacuation(int areaCode);
        void evacuate(int areaCode);

        ~EmergencyChannel();
};

#endif
