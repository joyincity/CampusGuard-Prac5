#ifndef CONTROLRESTOREPOINT_H
#define CONTROLRESTOREPOINT_H

class ControlRestorePoint {

private:
	bool gateAccess;
	bool facilities;
	bool backupPower;

public:
	ControlRestorePoint(bool gateAccess, bool facilities, bool backupPower);

	bool getGateAccess();

	bool getFacilities();

	bool getBackupPower();
};

#endif
