#include "IncidentHandler.h"
IncidentHandler::IncidentHandler(EmergencyChannel* channel,CampusControlServer* campusControl,ServerManager* serverManager,OperationsDashboard* dashboard){
    this->channel = channel;
    this->campusControl =campusControl;
    this->serverManager=serverManager;
    this->dashboard=dashboard;
}
void IncidentHandler:: reportIncident(Incident* incident){
    std::cout << "Reporting incident " << incident->getIncidentID()<<" "<<std::endl;
    std::cout<<"Capturing state of Campus"<<std::endl;
    serverManager->addRP(campusControl->createRestorePoint());
    std::cout << "Advancing incident to Reported"<<std::endl;
    incident->advanceStatus();  
    std::cout << "Dispatching responders"<<std::endl;
    OperationAction* cmd = new DispatchUnit(channel, incident);
    dashboard->setCommand(cmd);
    dashboard->executeCommand();
}
void IncidentHandler:: resolveIncident(Incident* incident){
    std::cout << "Resolving incident " << incident->getIncidentID() <<std::endl;

    std::cout << "Advancing incident to Resolved."<<std::endl;
    incident->advanceStatus();
    std::cout << "Notifying colleagues of resolution"<<std::endl;
    channel->notify(incident);

    std::cout << "Restoring campus state"<<std::endl;
    if (!serverManager->isEmpty()) {
    campusControl->setRestorePoint(serverManager->getOldestRP()); 
    serverManager->removeLatestRP();
}
    
}
void IncidentHandler:: evacuateArea(Incident* incident){
    std::cout << "Evacuating area " << incident->getAreaCode() << std::endl;
    std::cout << "Issuing evacuation command."<<std::endl;
    dashboard->setCommand(new Evacuate(channel, incident));
    dashboard->executeCommand();

}
    