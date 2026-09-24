#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
class Status;

class Incident {
    private:
    std::string type;
    Status* status;
    public:
    Incident(std::string type);
    virtual ~Incident();
    std::string getType() const;
    void print() const;
    void advanceStatus();
    void setStatus(Status* newStatus);
};

#endif