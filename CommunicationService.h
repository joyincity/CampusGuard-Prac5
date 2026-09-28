#ifndef COMMUNICATIONSERVICE_H
#define COMMUNICATIONSERVICE_H

#include "Unit.h"
#include "FireDepartment.h"

class CommunicationService: public Unit {
    private:
        FireDepartment* fireDepartment;
        Radio* radio;

    public:
        CommunicationService(Radio* radio);
        void print() override;
        void statusChanged() override;
        std::string getAlert() override;
        void handleAlert(std::string alert) override;
        void cancelOperation() override;
        void dispatch(int incidentID) override;
};

#endif
