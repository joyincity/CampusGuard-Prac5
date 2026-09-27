#ifndef RADIO_H
#define RADIO_H

#include <vector>

class Unit;

class Radio{
    protected:
        std::vector<Unit*> unitList;
    public:
        virtual void addUnit(Unit* unit) = 0;
        virtual void notify(Unit* unit) = 0;
        virtual ~Radio() = default;
};

#endif
