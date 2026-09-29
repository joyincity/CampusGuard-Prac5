#include "CampusControlServer.h"
#include <iostream>

CampusControlServer::CampusControlServer(Radio* radio, ServerManager* serverManager) {
	this->gateAccess = false;
	this->facilities = false;
	this->backupPower = false;
	this->serverManager = serverManager;
	this->radio = radio;
	this->radio->addUnit(this);
}

void CampusControlServer::print() {
    std::cout << "== CampusControlServer ==" << std::endl;
	std::cout << "Gate Access: " << (this->gateAccess ? "OPEN" : "CLOSED") << std::endl;
	std::cout << "Facilities: " << (this->facilities ? "ACTIVE" : "INACTIVE") << std::endl;
	std::cout << "Backup Power: " << (this->backupPower ? "ON" : "OFF") << std::endl;
}

void CampusControlServer::statusChanged() {} // Do nothing

std::string CampusControlServer::getAlert() { // Return empty
	return "";
}

void CampusControlServer::handleAlert(std::string alert) {
	if (!alert.empty()) {
	    serverManager->addRP(this->createRestorePoint());

		setGateAccess(false);
		setFacilities(false);
		setBackupPower(true);
	}
}

void CampusControlServer::dispatch(int ,int) {

}

void CampusControlServer::cancelOperation(int) {
    ControlRestorePoint* restorePoint = serverManager->getLatestRP();
    if (restorePoint != nullptr) {
        setRestorePoint(restorePoint);
    } else {
        setGateAccess(true);
		setFacilities(true);
		setBackupPower(false);
    }
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

CampusControlServer::~CampusControlServer() {
	
}
