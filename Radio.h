#ifndef RADIO_H
#define RADIO_H

class Unit;

class Radio{
    public:
        virtual void notify(Unit* unit) = 0;
};

#endif
