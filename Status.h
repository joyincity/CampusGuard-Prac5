#ifndef STATUS_H
#define STATUS_H

#include <string>
class Incident;

class Status {
    protected:
    Incident* incident;
    private:
    std::string name;
    public:
    Status (std::string name, Incident* incident);
    std::string getName() const;
    virtual void nextState() = 0;
    virtual ~Status();
};

#endif