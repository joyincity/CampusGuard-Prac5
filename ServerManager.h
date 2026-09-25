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

	void removeLatestRP();

	bool isEmpty();

	~ServerManager();
};

#endif
