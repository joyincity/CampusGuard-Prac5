#include "EmergencyChannel.h"

void EmergencyChannel::notify(Unit* unit) {
    std::string alert = unit->getAlert();

    for (auto unit : unitList) {
        unit->handleAlert(alert);
    }
}

void dispatchUnit();
void cancel();
void evacuate();