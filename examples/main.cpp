#include <QCoreApplication>
#include <QString>
#include <memory>
#include <QDebug>
#include "../memento_stacker.h"
#include "myoriginator.h"
#include "myclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto cl1 = std::make_shared<MyClass>(); //класс за которым нужно следить и сохранять

    MyCareTaker<MyClass, int> mo(cl1); // класс сохранятель и восстановитель

    cl1->setA(111);
    mo.store_state();
    qDebug() << "cl1:" << cl1->getA() << "states count:" << mo.states_count();

    cl1->setA(999);
    mo.store_state();
    qDebug() << "cl1:" << cl1->getA() << "states count:" << mo.states_count();

    cl1->setA(444);
    mo.store_state();
    qDebug() << "cl1:" << cl1->getA() << "states count:" << mo.states_count();

    cl1->setA(777);
    qDebug() << "cl1:" << cl1->getA() << "states count:" << mo.states_count();

    mo.undo();
    qDebug() << "cl1:" << cl1->getA() << "states count:" << mo.states_count();

    mo.undo();
    qDebug() << "cl1:" << cl1->getA() << "states count:" << mo.states_count();

    mo.undo();
    qDebug() << "cl1:" << cl1->getA() << "states count:" << mo.states_count();

    mo.undo();
    qDebug() << "cl1:" << cl1->getA();

    return a.exec();
}
