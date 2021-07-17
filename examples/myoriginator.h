#ifndef MYCARETAKER_H
#define MYCARETAKER_H
#include "../memento_care_taker.h"
#include <QDebug>

template<class T, class VarType>
class MyCareTaker : public IMementoCareTaker<T, VarType>
{
    using IMementoCareTaker<T, VarType>::get_originator;
    using IMementoCareTaker<T, VarType>::push;
    using IMementoCareTaker<T, VarType>::pop;
public:
    MyCareTaker(std::shared_ptr<T> org):IMementoCareTaker<T, VarType>(org)
    {}

    virtual void undo() override
    {
        if(get_originator()!=nullptr)
        {
            if(!this->empty())
            {
                auto state_last=this->get_last_state();
                get_originator()->setA(state_last.value());
                this->pop();
            }
        }
    }


    virtual void store_state() override
    {
        if(get_originator()!=nullptr)
            this->push(get_originator()->getA());
    }


};

#endif // MYCARETAKER_H
