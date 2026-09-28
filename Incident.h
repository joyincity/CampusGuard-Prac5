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
    void cancelOperation(int incidentID) override;
    void dispatch(int , int ) override {};
    int getAssignedArea()override{return -1;}
    bool getIsAvailable()override{return false;}

    void advanceStatus();
    void setStatus(Status* newStatus);

    virtual ~Incident();
};

#endif
