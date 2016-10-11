#include "illusion/illusion.hpp"
#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <google/protobuf/message.h>
#include "benchmark/ilconnectionbenchmark.hpp"
#include <QCommandLineParser>

int main(int argc, char* argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    QApplication app(argc, argv);
    QApplication::setApplicationName("illusion");
    QApplication::setApplicationVersion("1.0");

    il::Illusion::instance()->init(argc, argv);

//    QMainWindow w;
//    w.show();

//    il::ILConnectionBenchmark bench("127.0.0.1", 8088);
//    bench.run(60);

//    il::Illusion::instance()->run();
    return app.exec();
}
