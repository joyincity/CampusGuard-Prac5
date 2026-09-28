#include "EmergencyChannel.h"

#include <iostream>
#include <string>

void EmergencyChannel::addUnit(Unit* unit) {
    if (!unit) {
        std::cout << "Unit is null" << std::endl;
        return;
    }

    for (auto u : unitList) {
        if (u == unit) {
            std::cout << "Unit already in list" << std::endl;
            return;
        }
    }

    unitList.push_back(unit);
}

void EmergencyChannel::notify(Unit* unit) {
    if (!unit) return;

    std::string alert = unit->getAlert();

    std::cout << "Sending alert: " << alert << std::endl;
    for (auto u : unitList) {
        if (!u) continue;
        if(unit == u) continue;
        u->handleAlert(alert);
    }
}

void EmergencyChannel::dispatch(int incidentID) {
    for (auto unit : unitList) {
        if (!unit) continue;
        unit->dispatch(incidentID);
    }
}

void EmergencyChannel::cancelDispatch() {
    for (auto unit : unitList) {
        if (!unit) continue;
        unit->cancelOperation();
    }
}

void EmergencyChannel::evacuate(int areaCode) {
    for(auto unit: unitList){
        if(!unit)continue;
        unit->handleAlert("EvacuateArea:" + std::to_string(areaCode));
    }
}
void EmergencyChannel::cancelEvacuation(int areaCode){
    for(auto unit: unitList){
        if(!unit)continue;
        unit->handleAlert("Cancel Evacuation at:" + std::to_string(areaCode));
    }
}

EmergencyChannel::~EmergencyChannel() {
    unitList.clear();
}
