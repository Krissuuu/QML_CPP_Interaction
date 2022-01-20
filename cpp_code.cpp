#include "cpp_code.h"
#include "QDebug"
#include <QVariant>

cpp_code::cpp_code(QObject *parent)
    : QObject{parent}
{

}

// Signal / Slot test
void cpp_code::cppRecvMsg(const QString &arg1, const int &arg2){
    qDebug() << "cppRecvMsg" << arg1 << arg2;
    qDebug() << "emit cppSendMsg";
    QVariant return_arg = arg1;
    QVariant return_arg2 = arg2;
    emit cppSendMsg(return_arg, return_arg2);
}

// Q_INVOKABLE test
int cpp_code::cpp_method(int arg1){
    qDebug() << "cpp_method" << arg1;
    return arg1;
}

// Q_PROPERTY test
void cpp_code::setProperty(int arg){
    qDebug() << "set_num";
    variable = arg;
    emit propertyChanged();
}
int cpp_code::getProperty(){
    qDebug() << "get_num";
    return variable;
}
