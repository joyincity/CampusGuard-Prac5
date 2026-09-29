#ifndef FIREDEPARTMENT_H
#define FIREDEPARTMENT_H

#include <iostream>

class FireDepartment {
    private:
        bool deployable;
        bool isDispatched;

    public:
        FireDepartment();
        void dispatchFireTruck();
        void recallFireTruck();
        bool getDeployable();
        bool getIsDispatched();
        void setDeployable(bool value);
};

#endif