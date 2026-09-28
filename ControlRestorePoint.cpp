#include "ControlRestorePoint.h"

ControlRestorePoint::ControlRestorePoint(bool gateAccess, bool facilities, bool backupPower) {
	this->gateAccess = gateAccess;
	this->facilities = facilities;
	this->backupPower = backupPower;
}

bool ControlRestorePoint::getGateAccess() {
	return this->gateAccess;
}

bool ControlRestorePoint::getFacilities() {
	return this->facilities;
}

bool ControlRestorePoint::getBackupPower() {
	return this->backupPower;
}
