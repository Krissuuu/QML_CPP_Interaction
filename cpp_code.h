#ifndef CPP_CODE_H
#define CPP_CODE_H

#include <QObject>

class cpp_code : public QObject
{
    Q_OBJECT

    // Q_PROPERTY test
    Q_PROPERTY(int property_ READ getProperty WRITE setProperty NOTIFY propertyChanged)

public:
    explicit cpp_code(QObject *parent = nullptr);

    // Q_INVOKABLE test
    Q_INVOKABLE int cpp_method(int arg1);

    // Q_PROPERTY test
    int getProperty();
    void setProperty(int arg);

signals:
    // Signal / Slot test
    void cppSendMsg(const QVariant &arg1, const QVariant &arg2);
    // Q_PROPERTY test
    void propertyChanged();

public slots:
    // Signal / Slot test
    void cppRecvMsg(const QString &arg1, const int &arg2);

private:
    int cppconst = 5678;
    int mValue;
    int variable;

};
#endif // CPP_CODE_H
