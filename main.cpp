
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
