#ifndef CAMPUSCONTROLSERVER_H
#define CAMPUSCONTROLSERVER_H

#include "Unit.h"
#include "ControlRestorePoint.h"
#include "ServerManager.h"

class CampusControlServer : public Unit {

private:
	bool gateAccess;
	bool facilities;
	bool backupPower;
	ServerManager* serverManager;

public:
	CampusControlServer(Radio* radio, ServerManager* serverManager);

	void print() override;
	void statusChanged() override;
	std::string getAlert() override;
	void handleAlert(std::string alert) override;
	void dispatch(int incidentID, int areaCode) override;
	void cancelOperation(int incidentID) override;

	ControlRestorePoint* createRestorePoint();

	void setRestorePoint(ControlRestorePoint* restorePoint);

	void setGateAccess(bool value);

	void setFacilities(bool value);

	void setBackupPower(bool value);

	~CampusControlServer();
};

#endif
