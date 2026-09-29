#ifndef INCIDENTHANDLER_H
#define INCIDENTHANDLER_H
#include "EmergencyChannel.h"
#include "CampusControlServer.h"
#include "ServerManager.h"
#include "OperationsDashboard.h"
#include "Incident.h"
#include "DispatchUnit.h"
#include "Evacuate.h" 
#include <iostream>
#include <string>

class IncidentHandler{
private:
    EmergencyChannel* channel;
    CampusControlServer*campusControl;
    ServerManager* serverManager;
    OperationsDashboard* dashboard;
public:
    IncidentHandler(EmergencyChannel* channel,CampusControlServer* campusControl, ServerManager* serverManager,OperationsDashboard* dashboard);
    void reportIncident(Incident*incident);
    void resolveIncident(Incident* incident);
    void evacuateArea(Incident*incident);
    ~IncidentHandler(){};

};
#endif