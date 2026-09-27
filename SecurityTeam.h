#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "Unit.h"

class SecurityTeam : public Unit {
public:
    SecurityTeam(Radio* handler);
    void statusChange() override;
    void setStatus() override;
    void dispatch() override;
};

#endif
