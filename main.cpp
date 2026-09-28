
#include "IncidentHandler.h"
#include "Fire.h"
#include "SecurityThreat.h"
#include "EmergencyChannel.h"
#include "MedicalTeam.h"
#include "SecurityTeam.h"
#include "CommunicationService.h"
#include "CampusControlServer.h"
#include "ServerManager.h"
#include "OperationsDashboard.h"
#include "CancelAction.h"

#include <iostream>

// Patterns: Facade, Command, Mediator, Adapter, State, Memento scenario 1

void story1_fireInLibrary() {
    std::cout << "Scenario 1: Fire in the Library"<<std::endl;
    std::cout << "----------------------------------------------------"<<std::endl;
    std::cout<<"\n";

    EmergencyChannel*channel   = new EmergencyChannel();
    ServerManager manager;
    CampusControlServer* campus    = new CampusControlServer(channel, &manager);
    OperationsDashboard* dashboard = new OperationsDashboard();
    IncidentHandler handler(channel, campus, &manager, dashboard);
    Incident*fire = new Fire(channel, 1, 3);
    Unit*medA  = new MedicalTeam(channel);
    Unit*secA  = new SecurityTeam(channel);
    Unit*comms = new CommunicationService(channel);

    std::cout << "\nCampus state before incident:"<<std::endl;
    std::cout<<"\n";
    campus->setGateAccess(true);
    campus->setFacilities(true);   
    campus->setBackupPower(false); 
    
    
    campus->print();
    handler.reportIncident(fire);

    std::cout <<"\nFireDepartment state after dispatch:"<<std::endl;
    std::cout<<"\n";
    comms->print();
    std::cout << "\nCancelling the false alarm"<<std::endl;
    std::cout<<"\n";
    OperationAction* target = dashboard->getLastCommand();
    if (target != nullptr) {
        dashboard->setCommand(new CancelAction(target));
        dashboard->executeCommand();
    }

    std::cout << "\nFireDepartment state after cancel:"<<std::endl;
    std::cout<<"\n";
    comms->print();
    std::cout << "\nUndoing the cancel — the fire is real!"<<std::endl;
    std::cout<<"\n";
    OperationAction* cancelCmd = dashboard->getLastCommand();
    if (cancelCmd != nullptr) {
        cancelCmd->undo();
    }

    std::cout << "\nFireDepartment state after undo: "<<std::endl;
    std::cout<<"\n";
    comms->print();

    handler.resolveIncident(fire);

    std::cout << "\nCampus state after resolution:"<<std::endl;
    std::cout<<"\n";
    campus->print();

    delete comms;
    delete medA;
    delete secA;
    delete fire;
    delete dashboard;
    delete campus;
    delete channel;
}



//Patterns: Facade, Command, Mediator,Adapter, State,Memento

void story2_securityThreat() {
    
    std::cout << "  scenario 2: Security Threat at the Piazza\n";
    std::cout << "-------------------------------------------------"<<std::endl;
std::cout<<"\n";
    EmergencyChannel*channel   = new EmergencyChannel();
    ServerManager manager;
    CampusControlServer* campus = new CampusControlServer(channel, &manager);
    OperationsDashboard* dashboard = new OperationsDashboard();

    IncidentHandler handler(channel, campus, &manager, dashboard);

    Incident* threat = new SecurityThreat(channel, 2, 7);
    Unit* medB  = new MedicalTeam(channel);
    Unit* secB  = new SecurityTeam(channel);
    Unit* comms = new CommunicationService(channel); 

    std::cout << "\nCampus state before incident:"<<std::endl;
    std::cout<<"\n";
    campus->setGateAccess(true);
    campus->setFacilities(true);   
    campus->setBackupPower(false); 
    campus->print();

    

    handler.reportIncident(threat);

    handler.evacuateArea(threat);

    std::cout << "\nFireDepartment state during incident:"<<std::endl;
    std::cout<<"\n";
    comms->print();

    std::cout << "\nCampus state during incident:"<<std::endl;
    std::cout<<"\n";
    campus->print();

    handler.resolveIncident(threat);

    std::cout << "\nCampus state after resolution:"<<std::endl;
    std::cout<<"\n";
    campus->print();

    delete comms;
    delete medB;
    delete secB;
    delete threat;
    delete dashboard;
    delete campus;
    delete channel;
}


int main() {
   

    story1_fireInLibrary();
    story2_securityThreat();

    return 0;
}