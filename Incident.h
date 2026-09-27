#ifndef INCIDENT_H
#define INCIDENT_H

#include "Unit.h"

#include <string>
class Status;

class Incident : public Unit {
    private:
    std::string type;
    Status* status;
    public:
    Incident(Radio* radio, std::string type);

    void print() override;
    void statusChanged() override;
    std::string getAlert() override;
    void handleAlert(std::string alert) override;
    void cancelOperation() override;
    void dispatch() override {};

    void advanceStatus();
    void setStatus(Status* newStatus);

    virtual ~Incident();
};

#endif
