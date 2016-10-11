#include "illusion.hpp"
#include <QCommandLineParser>
#include <QApplication>

namespace il {

Illusion* Illusion::instance_ = nullptr;

Illusion::Illusion()
    :   QObject(nullptr),
        work_(nullptr)
{

}

void Illusion::init() {
    cmdLine_.setApplicationDescription("Benchmark your server");
    cmdLine_.addHelpOption();
    cmdLine_.addVersionOption();

    QCommandLineOption hostOption(QStringList() << "H" << "host",
        QCoreApplication::translate("main", "Specify the host"),
        QCoreApplication::translate("main", "IP Address"));
    cmdLine_.addOption(hostOption);

    QCommandLineOption portOption(QStringList() << "p" << "port",
        QCoreApplication::translate("main", "Specify server's port"),
        QCoreApplication::translate("main", "port number"));
    cmdLine_.addOption(portOption);

    QCommandLineOption connOption(QStringList() << "c" << "connection",
                QCoreApplication::translate("main", "Start connection benchmark"));
    cmdLine_.addOption(connOption);

    QCommandLineOption connNumOpion(QStringList() << "cn" << "connection-number",
                QCoreApplication::translate("main", "Set max connections for connection benchmark (default is 60 which means 60k)"));
    cmdLine_.addOption(connNumOpion);

    cmdLine_.process(*QApplication::instance());
}

Illusion::~Illusion() {

}

} // namespace il
