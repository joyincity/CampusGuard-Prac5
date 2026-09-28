#include "CampusControlServer.h"
#include <iostream>

CampusControlServer::CampusControlServer() {
	this->gateAccess = false;
	this->facilities = false;
	this->backupPower = false;
}

void CampusControlServer::print() {
    std::cout << "== CampusControlServer ==" << std::endl;
	std::cout << "Gate Access: " << (this->gateAccess ? "OPEN" : "CLOSED") << std::endl;
	std::cout << "Facilities: " << (this->facilities ? "ACTIVE" : "INACTIVE") << std::endl;
	std::cout << "Backup Power: " << (this->backupPower ? "ON" : "OFF") << std::endl;
}

ControlRestorePoint* CampusControlServer::createRestorePoint() {
	ControlRestorePoint* restorePoint = new ControlRestorePoint(this->gateAccess, this->facilities, this->backupPower);
	return restorePoint;
}

void CampusControlServer::setRestorePoint(ControlRestorePoint* restorePoint) {
	this->gateAccess = restorePoint->getGateAccess();
	this->facilities = restorePoint->getFacilities();
	this->backupPower = restorePoint->getBackupPower();
}

void CampusControlServer::setGateAccess(bool value) {
	this->gateAccess = value;
}

void CampusControlServer::setFacilities(bool value) {
	this->facilities = value;
}

void CampusControlServer::setBackupPower(bool value) {
	this->backupPower = value;
}
