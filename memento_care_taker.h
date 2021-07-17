#ifndef MEMENTOCARETAKER_H
#define MEMENTOCARETAKER_H
#include <memory>
#include "memento_stacker.h"

/**
 * @brief IMementoCareTaker - базовый класс обработчика сохранения и восстановления состояний.
 * В наслденике требуется перезагрузить методы undo() и store_state().
 * class T - класс, у которого нужно сохранять и восстанавливать состояние,
 * class VarType - тип данных для сохранения
 */
template <class T, class VarType>
class IMementoCareTaker
{

public:
    IMementoCareTaker(std::shared_ptr<T> org):ptr_originator(org), mem_stkr(nullptr)
    {
        mem_stkr = std::make_unique<MementoStacker<VarType>>();
    }

    virtual void undo() = 0;
    virtual void store_state() = 0;

    auto get_first_state() const noexcept
    {
        return mem_stkr->get_first_state();
    }

    auto get_last_state() const noexcept
    {
        return mem_stkr->get_last_state();
    }

    auto states_count() const noexcept
    {
        return mem_stkr->states_count();
    }

    bool empty() const noexcept
    {
        return mem_stkr->empty();
    }

protected:
    void push(const VarType &val)
    {
        if(mem_stkr!=nullptr)
        {
            mem_stkr->push(val);
        }
    }

    void push(VarType &&val)
    {
        if(mem_stkr!=nullptr)
        {
            mem_stkr->push(val);
        }
    }

    void pop() noexcept
    {
        mem_stkr->pop();
    }

    auto get_originator() noexcept
    {
        return ptr_originator;
    }
private:
    std::shared_ptr<T> ptr_originator;
    std::unique_ptr<MementoStacker<VarType>> mem_stkr;
};

#endif // MEMENTOCARETAKER_H
