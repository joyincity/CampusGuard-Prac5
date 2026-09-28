#ifndef UNIT_H
#define UNIT_H

#include <string>

#include "Radio.h"

class Unit {
    protected:
        Radio* radio;
    public:
        virtual void print() = 0;
        virtual void statusChanged() = 0;
        virtual std::string getAlert() = 0; // My alert
        virtual void handleAlert(std::string alert) = 0; // Received alert
        virtual void dispatch() = 0;
        virtual void cancelOperation() = 0;
        virtual ~Unit() = default;
};

#endif
