#ifndef MEMENTOSTACKER_H
#define MEMENTOSTACKER_H
#include <stack>
#include <optional>

/**
 *  @brief MementoStacker - класс для хранения состояний.
 *  class T - тип данных для сохранения.
 */
template <class T>
class MementoStacker
{
public:
    MementoStacker(){}

    void push(T &&val)
    {
        states.push(val);
        if(states.size()==1)
            first = val;
    }

    void push(const T &val)
    {
        states.push(val);
        if(states.size()==1)
            first = val;
    }

    void pop() noexcept
    {
        if(!states.empty())
            states.pop();

        if(states.empty())
            first.reset();
    }

    auto get_first_state() const noexcept
    {
        return first;
    }

    auto get_last_state() noexcept
    {
        std::optional<T> res;
        if(!states.empty())
        {
            res=states.top();
        }
        return res;
    }

    bool empty() const noexcept
    {
        return states.empty();
    }


    void clear_states() noexcept
    {
        std::stack<T> empty;
        states.swap(empty);
    }

    auto states_count() const noexcept
    {
        return states.size();
    }

private:

    std::optional<T> first;
    std::stack<T> states;
};

#endif // MEMENTOSTACKER_H
