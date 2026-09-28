#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "Unit.h"

class SecurityTeam : public Unit {
private:
    int guardsDispatched;
    bool deployable;

public:
    SecurityTeam(Radio* radio);

    void print() override;
    void statusChanged() override;
    std::string getAlert() override;
    void handleAlert(std::string alert) override;
    void cancelOperation() override;
    void dispatch(int incidentID) override;

    ~SecurityTeam() = default;
};

#endif
