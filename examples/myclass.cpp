#include "myclass.h"

MyClass::MyClass():a_(0)
{

}

void MyClass::setA(int a)
{
    a_ = a;
}

int MyClass::getA() const noexcept
{
    return a_;
}
