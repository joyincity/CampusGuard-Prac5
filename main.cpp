#include "CampusControlServer.h"
#include "ServerManager.h"

int main() {
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
