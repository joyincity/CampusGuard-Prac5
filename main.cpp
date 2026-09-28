
#include "CampusControlServer.h"
#include "ServerManager.h"

#include "Fire.h"
#include "SecurityThreat.h"
#include "EmergencyChannel.h"
#include "MedicalTeam.h"
#include "SecurityTeam.h"

#include "OperationsDashboard.h"
#include "DispatchUnit.h"
#include "Evacuate.h"
#include "CancelAction.h"

#include <iostream>

int main() {
    

    EmergencyChannel* channel = new EmergencyChannel();

    Incident* fire   = new Fire(channel, 1, 3);            
    Incident* threat = new SecurityThreat(channel, 2, 7);  

    Unit* medA = new MedicalTeam(channel);
    Unit* medB = new MedicalTeam(channel);
    Unit* secA = new SecurityTeam(channel);
    Unit* secB = new SecurityTeam(channel);

    OperationsDashboard dashboard;


    std::cout << "\n Reporting both incidents \n";
    fire->advanceStatus();     
    threat->advanceStatus();   

    fire->print();
    threat->print();

    std::cout << "\nCommand: Dispatch incident 1 (Fire, area 3)\n";
    OperationAction* dispatchFire = new DispatchUnit(channel, fire);
    dashboard.setCommand(dispatchFire);
    dashboard.executeCommand();

    std::cout << "\nUnit state after dispatching incident 1:\n";
    medA->print();
    medB->print();
    secA->print();
    secB->print();

    std::cout << "\n Command: Dispatch incident 2 (SecurityThreat, area 7)\n";
    OperationAction* dispatchThreat = new DispatchUnit(channel, threat);
    dashboard.setCommand(dispatchThreat);
    dashboard.executeCommand();

    std::cout << "\nUnit state after dispatching incident 2:\n";
    std::cout << "  (each incident should have one medical + one security team)\n";
    medA->print();
    medB->print();
    secA->print();
    secB->print();

    std::cout << "\nCommand: Evacuate area 7\n";
    std::cout << "  (only teams working area 7 should react)\n";
    dashboard.setCommand(new Evacuate(channel, threat));
    dashboard.executeCommand();

    std::cout << "\nCommand: Cancel incident 1's dispatch\n";
    std::cout << "  (incident 2's teams must remain untouched)\n";
    CancelAction* cancelFire = new CancelAction(dispatchFire);
    dashboard.setCommand(cancelFire);
    dashboard.executeCommand();

    std::cout << "\nUnit state after cancelling incident 1:\n";
    std::cout << "(medA & secA should be released; medB & secB still on incident 2)\n";
    medA->print();
    medB->print();
    secA->print();
    secB->print();

    std::cout << "\nFailure: Cancel incident 1 again \n";
    dashboard.setCommand(new CancelAction(dispatchFire));
    dashboard.executeCommand();

    std::cout << "\nCommand: Undo the cancel (re-dispatch incident 1)\n";
    cancelFire->undo();

    std::cout << "\nUnit state after undoing the cancel:\n";
    std::cout << "  (medA & secA should be re-dispatched to incident 1)\n";
    medA->print();
    medB->print();
    secA->print();
    secB->print();

    std::cout << "\n Failure: Undo the cancel again\n";
    cancelFire->undo();
    std::cout << "\nCommand: Cancel incident 2's dispatch\n";
    CancelAction* cancelThreat = new CancelAction(dispatchThreat);
    dashboard.setCommand(cancelThreat);
    dashboard.executeCommand();

    std::cout << "\nFinal unit state:\n";
    medA->print();
    medB->print();
    secA->print();
    secB->print();

    
    delete medA;
    delete medB;
    delete secA;
    delete secB;
    delete fire;
    delete threat;
    delete channel;
    
   
    CampusControlServer server;
    ServerManager manager;

    std::cout << "\nInitial campus state:\n";
    server.print();

 
    manager.addRP(server.createRestorePoint());
    std::cout << "[Memento] Snapshot taken (pre-incident)\n";

 
    server.setGateAccess(true);
    server.setFacilities(true);
    server.setBackupPower(true);
    std::cout << "\nCampus state during incident:\n";
    server.print();


    std::cout << "\nRestoring to pre-incident state\n";
    if (!manager.isEmpty()) {
        server.setRestorePoint(manager.getLatestRP());
    }
    server.print();

 
    return 0;
}