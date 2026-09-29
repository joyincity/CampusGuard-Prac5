#include "FireDepartment.h"

FireDepartment::FireDepartment() {
    this->deployable = false;
    this->isDispatched = false;
}

bool FireDepartment::getDeployable() {
    return this->deployable;
}

bool FireDepartment::getIsDispatched() {
    return this->isDispatched;
}

void FireDepartment::setDeployable(bool value) {
    this->deployable = value;
}

void FireDepartment::dispatchFireTruck() {
    if (this->deployable)
    {
        this->isDispatched = true;

        std::cout << "Fire truck dispatched." << std::endl;
    }
}

void FireDepartment::recallFireTruck() {
    this->isDispatched = false;
}