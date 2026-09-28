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
        void print();
        void statusChanged();
        std::string getAlert();
        void handleAlert(std::string alert);
        void cancelOperation();
        void dispatch();
};

#endif