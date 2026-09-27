#ifndef STATUS_H
#define STATUS_H

#include <string>
class Incident;

class Status {
    protected:
    Incident* incident;
    public:
    Status (Incident* incident);
    virtual std::string getName() = 0;
    virtual void nextState() = 0;
    virtual ~Status();
};

#endif