#ifndef MYCLASS_H
#define MYCLASS_H

/**
 * @brief The MyClass class - пример класса, состояние которого требуется сохранять и восстанавливать.
 */
class MyClass
{
public:
    MyClass();

    void setA(int a);
    int getA() const noexcept;

private:
    int a_;
};

#endif // MYCLASS_H
