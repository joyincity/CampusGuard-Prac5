#ifndef OPERATIONACTION_H
#define OPERATIONACTION_H
#include <string>
#include <iostream>

class OperationAction{
    protected:
        bool cancelled=false;
    public:
        virtual void execute() = 0;
        virtual void undo()=0;
        virtual void ActionDescription()const=0;
       virtual  ~OperationAction()= default;
       void makeActive(){cancelled=false;}
       void makeCancelled(){cancelled= true;}
       bool isCancelled()const{return cancelled;}
};

#endif