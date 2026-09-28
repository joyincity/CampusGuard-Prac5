#ifndef INCIDENT_H
#define INCIDENT_H

#include "Unit.h"

#include <string>
class Status;

class Incident : public Unit {
    private:
    int incidentID;
    int areaCode;
    std::string type;
    Status* status;
    public:
    Incident(Radio* radio,int incidentID, int areaCode, std::string type);

    void print() override;
    void statusChanged() override;
    std::string getAlert() override;
    int getIncidentID();
    int getAreaCode();
    void handleAlert(std::string alert) override;
    void cancelOperation() override;
    void dispatch(int incidentID) override {};

    void advanceStatus();
    void setStatus(Status* newStatus);

    virtual ~Incident();
};

#endif
