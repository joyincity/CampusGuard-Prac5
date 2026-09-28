#include "CommunicationService.h"

CommunicationService::CommunicationService(Radio* radio) {
    this->radio = radio;
    this->fireDepartment = new FireDepartment();
    this->radio->addUnit(this);
}

void CommunicationService::print()
{
    bool isDispatched = this->fireDepartment->getIsDispatched();
    bool deployable = this->fireDepartment->getDeployable();
    std::cout << "FireDepartment: isDispatched= "
              << (isDispatched ? "true" : "false")
              << ", deployable= "
              << (deployable ? "true" : "false")
              << std::endl;
}

void CommunicationService::statusChanged()
{
}

std::string CommunicationService::getAlert()
{
    return "";
}

void CommunicationService::handleAlert(std::string alert)
{
    if (alert == "Fire")
    {
        this->fireDepartment->setDeployable(true);
    }
}

void CommunicationService::cancelOperation()
{
    this->fireDepartment->setDeployable(false);
    this->fireDepartment->recallFireTruck();
}

void CommunicationService::dispatch(int incidentID)
{
    this->fireDepartment->dispatchFireTruck();
}
