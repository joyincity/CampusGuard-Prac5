#ifndef UNIT_H
#define UNIT_H

class Radio;

class Unit {
    private:
        Radio* handler;
    public:
        Unit(Radio* handler);
        virtual void statusChange() = 0;
        virtual void setStatus() = 0;
        virtual void dispatch() = 0;
        virtual ~Unit();
};

#endif
