#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "Unit.h"

class SecurityTeam : public Unit {
private:
    int guardsDispatched;
    bool deployable;
    int assignedArea;
    int assignedIncident;
    bool isAvailable;
    void release();

public:
    SecurityTeam(Radio* radio);

    void print() override;
    void statusChanged() override;
    std::string getAlert() override;
    void handleAlert(std::string alert) override;
    void cancelOperation(int incidentID) override;
    void dispatch(int incidentID, int areaCode) override;
    int getAssignedArea()override;
    bool getIsAvailable()override;
    ~SecurityTeam() = default;
};

#endif
