#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <Player.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/QML/main.qml"));
    // QObject::connect(
        // &engine,
        // &QQmlApplicationEngine::objectCreated,
        // &app,
        // [url](QObject *obj, const QUrl &objUrl) {
        //     if (!obj && url == objUrl)
        //         QCoreApplication::exit(-1);
        // },
        // Qt::QueuedConnection);
    Player obj;
    engine.rootContext()->setContextProperty("Player", &obj);
    engine.load(url);

    return app.exec();
}
