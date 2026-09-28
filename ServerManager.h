#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include "ControlRestorePoint.h"

#include <vector>

class ServerManager {

private:
	std::vector<ControlRestorePoint*> history;

public:
    void addRP(ControlRestorePoint* rp);
    
	ControlRestorePoint* getLatestRP();
	ControlRestorePoint* getOldestRP() const;

	void removeLatestRP();
	void removeOldestRP();

	bool isEmpty();

	~ServerManager();
};

#endif
