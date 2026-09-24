#include "Fire.h"
#include "Reported.h"

Fire::Fire() : Incident("Fire"){
    setStatus(new Reported(this));
}