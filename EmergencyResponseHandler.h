#ifndef EMERGENCYRESPONSEHANDLER_H
#define EMERGENCYRESPONSEHANDLER_H
#include "ResponseHandler.h"

class EmergencyResponseHandler : public ResponseHandler{
    public:
        void dispatchUnit();
        void cancel();
        void evacuate();

};
#endif