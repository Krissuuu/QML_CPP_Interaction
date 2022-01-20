#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <cpp_code.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //【0】Register C++ class
    // Register Method 1
    // cpp_code kris_cppObj;
    // engine.rootContext()->setContextProperty("Kris_cppObj", &kris_cppObj);

    // Register Method 2
    qmlRegisterType<cpp_code>("kris", 1, 0, "Kris_cppObj");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
