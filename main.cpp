#include "CampusControlServer.h"
#include "ServerManager.h"

#include "Fire.h"
#include "SecurityThreat.h"
#include "EmergencyChannel.h"
#include "MedicalTeam.h"
#include "SecurityTeam.h"

#include "DispatchUnit.h"
#include "Evacuate.h"
#include "CancelAction.h"
#include "OperationsDashboard.h"

#include <iostream>

int main() {
    std::cout << "========================================\n";
    std::cout << "        CampusGuard Demonstration\n";
    std::cout << "========================================\n";

    // ─────────────────────────────────────────────
    // SETUP
    // ─────────────────────────────────────────────
    EmergencyChannel* channel = new EmergencyChannel();

    // Two incidents with different runtime data
    Incident* fire          = new Fire(channel, 1, 42);
    Incident* securityEvent = new SecurityThreat(channel, 2, 7);

    // Two response units
    Unit* medicalTeam  = new MedicalTeam(channel);
    Unit* securityTeam = new SecurityTeam(channel);

    OperationsDashboard dashboard;

    // ─────────────────────────────────────────────
    // SCENARIO 1: Fire at area 42
    // ─────────────────────────────────────────────
    std::cout << "\n──── Scenario 1: Fire Incident ────\n";
    fire->print();

    // Command 1: Dispatch units to incident 1
    std::cout << "\n[Command] Dispatch units to incident 1\n";
    dashboard.setCommand(new DispatchUnit(channel, 1));
    dashboard.executeCommand();
    fire->print();

    // Command 2: Evacuate area 42
    std::cout << "\n[Command] Evacuate area 42\n";
    dashboard.setCommand(new Evacuate(channel, 42));
    dashboard.executeCommand();

    // ─────────────────────────────────────────────
    // SCENARIO 2: Cancel the dispatch
    // ─────────────────────────────────────────────
    std::cout << "\n──── Scenario 2: Cancel the Dispatch ────\n";

    // Create a new dispatch command so we can target it
    DispatchUnit* dispatchCmd = new DispatchUnit(channel, 1);
    dashboard.setCommand(dispatchCmd);
    dashboard.executeCommand();

    // Cancel it
    std::cout << "\n[Command] Cancel the dispatch\n";
    dashboard.setCommand(new CancelAction(dispatchCmd));
    dashboard.executeCommand();

    // Undo the cancel (reinstates the dispatch)
    std::cout << "\n[Command] Undo the cancel\n";
    dashboard.undoLast();

    // ─────────────────────────────────────────────
    // SCENARIO 3: Security incident at area 7
    // ─────────────────────────────────────────────
    std::cout << "\n──── Scenario 3: Security Incident ────\n";
    securityEvent->print();

    std::cout << "\n[Command] Dispatch units to incident 2\n";
    dashboard.setCommand(new DispatchUnit(channel, 2));
    dashboard.executeCommand();
    securityEvent->print();

    std::cout << "\n[Command] Evacuate area 7\n";
    dashboard.setCommand(new Evacuate(channel, 7));
    dashboard.executeCommand();

    // ─────────────────────────────────────────────
    // FAILURE CASE: Cancel with no target
    // ─────────────────────────────────────────────
    std::cout << "\n──── Failure Case: Null Cancel ────\n";
    dashboard.setCommand(new CancelAction(nullptr));
    dashboard.executeCommand();

    // ─────────────────────────────────────────────
    // FAILURE CASE: Double cancel
    // ─────────────────────────────────────────────
    std::cout << "\n──── Failure Case: Double Cancel ────\n";
    DispatchUnit* dbl = new DispatchUnit(channel, 1);
    dashboard.setCommand(dbl);
    dashboard.executeCommand();

    CancelAction* c1 = new CancelAction(dbl);
    dashboard.setCommand(c1);
    dashboard.executeCommand();

    CancelAction* c2 = new CancelAction(dbl);
    dashboard.setCommand(c2);
    dashboard.executeCommand();   // should say "already cancelled"

    // ─────────────────────────────────────────────
    // MEMENTO: Campus Control Server
    // ─────────────────────────────────────────────
    std::cout << "\n──── Memento: Campus Control Server ────\n";
    CampusControlServer server;
    ServerManager manager;

    server.print();

    // Snapshot before the incident
    manager.addRP(server.createRestorePoint());
    std::cout << "[Memento] Snapshot taken (pre-incident)\n";

    // Incident changes campus state
    server.setGateAccess(true);
    server.setFacilities(true);
    server.setBackupPower(true);
    std::cout << "\n[Memento] Campus state changed during incident:\n";
    server.print();

    // Restore to before the incident
    std::cout << "\n[Memento] Restoring to pre-incident state...\n";
    if (!manager.isEmpty()) {
        server.setRestorePoint(manager.getLatestRP());
    }
    server.print();

    // ─────────────────────────────────────────────
    // CLEANUP
    // ─────────────────────────────────────────────
    std::cout << "\n──── Cleanup ────\n";

    // Dashboard destructor deletes its commands
    // (happens automatically when dashboard goes out of scope)

    // Channel does NOT own the units, so delete them here
    delete medicalTeam;
    delete securityTeam;
    delete fire;
    delete securityEvent;
    delete channel;

    std::cout << "\nDemo complete.\n";
    return 0;
}

/*


#include "CampusControlServer.h"
#include "ServerManager.h"

#include "Fire.h"
#include "EmergencyChannel.h"
#include "MedicalTeam.h"

#include <iostream>

int main() {
    
    std::cout << "== Fire Incident ==" << std::endl;

    EmergencyChannel* channel = new EmergencyChannel();

    Incident* incident = new Fire(channel);

    Unit* medicalTeam = new MedicalTeam(channel);

    incident->print();

    incident->advanceStatus();

    incident->print();

    channel->dispatch();

    incident->advanceStatus();

    delete channel;
    delete incident;
    delete medicalTeam;

    // Memento Testing
    std::cout << "Memento for CampusControlServer" << std::endl;
    CampusControlServer server;
    ServerManager manager;

    server.print();

    manager.addRP(server.createRestorePoint());

    server.setGateAccess(true);
    server.print();

    manager.addRP(server.createRestorePoint());

    server.setFacilities(true);
    server.print();

    manager.addRP(server.createRestorePoint());

    server.setBackupPower(true);
    server.print();

    server.setRestorePoint(manager.getLatestRP());
    server.print();

    manager.removeLatestRP();

    server.setRestorePoint(manager.getLatestRP());
    server.print();

    manager.removeLatestRP();

    server.setRestorePoint(manager.getLatestRP());
    server.print();
}
*/