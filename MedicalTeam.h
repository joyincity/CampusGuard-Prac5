#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "Unit.h"

class MedicalTeam : public Unit {
    private:

        bool deployable;
        bool isDispatched;
        int assignedIncident;
        int assignedArea;
        bool isAvailable;
        void release();

public:
    MedicalTeam(Radio* radio);

    void print() override;
    void statusChanged() override;
    std::string getAlert() override;
    void handleAlert(std::string alert) override;
    void cancelOperation(int incidentID) override;
    void dispatch(int incidentID, int areaCode) override;
    int getAssignedArea()override;
    bool getIsAvailable()override;
    UnitType getType() override {return UnitType::Medical;}

    ~MedicalTeam() = default;
};

#endif
