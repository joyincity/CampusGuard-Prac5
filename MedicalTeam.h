#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "Unit.h"

class MedicalTeam : public Unit {
    bool deployable;
    bool isDispatched;

public:
    MedicalTeam(Radio* radio);

    void print() override;
    void statusChanged() override;
    std::string getAlert() override;
    void handleAlert(std::string alert) override;
    void cancelOperation() override;
    void dispatch(int incidentID) override;

    ~MedicalTeam() = default;
};

#endif
