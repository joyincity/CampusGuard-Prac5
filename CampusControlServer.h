#ifndef CAMPUSCONTROLSERVER_H
#define CAMPUSCONTROLSERVER_H

#include "ControlRestorePoint.h"

class CampusControlServer {

private:
	bool gateAccess;
	bool facilities;
	bool backupPower;

public:
	CampusControlServer();

	void print();

	ControlRestorePoint* createRestorePoint();

	void setRestorePoint(ControlRestorePoint* restorePoint);

	void setGateAccess(bool value);

	void setFacilities(bool value);

	void setBackupPower(bool value);

	~CampusControlServer() = default;
};

#endif
