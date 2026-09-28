#include "ServerManager.h"

#include <iostream>

void ServerManager::addRP(ControlRestorePoint* rp) {
    history.push_back(rp);
}

ControlRestorePoint* ServerManager::getLatestRP() {
    if (history.empty()) {
        std::cout << "ServerManager History Empty" << std::endl;
        return nullptr;
    }

    return history.back();
}

void ServerManager::removeLatestRP() {
    if (!history.empty()) {
        delete history.back();
        history.pop_back();
    }
}

bool ServerManager::isEmpty() {
    std::cout << "ServerManager History Empty" << std::endl;
    return history.empty();
}

ServerManager::~ServerManager() {
    for (auto rp : history) {
        delete rp;
    }
    history.clear();
}
