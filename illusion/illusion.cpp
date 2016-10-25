#include "illusion.hpp"
#include "benchmark/ilconnectionbenchmark.hpp"
#include "ilmanager.hpp"
#include <QCommandLineParser>
#include <QApplication>

namespace il {

Illusion* Illusion::instance_ = nullptr;

Illusion::Illusion()
    :   QObject(nullptr),
        work_(nullptr),
        currentBenchmark_(0)
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

    QCommandLineOption connOption(QStringList() << "c" << "connection-benchmark",
        QCoreApplication::translate("main", "Start connection benchmark"));
    cmdLine_.addOption(connOption);

    QCommandLineOption connNumOpion(QStringList() << "cn" << "connection-number",
        QCoreApplication::translate("main", "Set max connections for connection benchmark (default is 60 which means 60k)"));
    cmdLine_.addOption(connNumOpion);

    QCommandLineOption listBenchOption(QStringList() << "lb" << "list-benchmarks",
        QCoreApplication::translate("main", "List all benchmarks"));
    cmdLine_.addOption(listBenchOption);


    cmdLine_.process(*QApplication::instance());

    if (cmdLine_.value(hostOption).length() && cmdLine_.value(portOption).length()) {
        endpoint_ = asio::ip::tcp::endpoint(asio::ip::address_v4::from_string(cmdLine_.value(hostOption).toStdString()),
                                            cmdLine_.value(portOption).toUInt());
    }

    if (cmdLine_.isSet(connOption)) {
        if (endpoint_.address().to_string().empty()) {
            IL_PRINT << "No host specified via the command-line";
            return;
        } else if (!endpoint_.port()) {
            IL_PRINT << "No port specified via the command-line";
            return;
        }

        int num = 60;

        if (cmdLine_.value(connNumOpion).length())
            num = cmdLine_.value(connNumOpion).toInt();

        ILConnectionBenchmark bench(endpoint_.address().to_string().c_str(), endpoint_.port());
        bench.run(num);
    } else if (cmdLine_.isSet(listBenchOption)) {
        il::benchmark::listBenchmarks();
    }
}

void Illusion::run() {
    IL_PRINT << "Running all benchmarks";

    ILManager::instance()->getBenchmark(currentBenchmark_)->run();

    work_ = new asio::io_service::work(service_);

    std::thread t([&] () {
        this->service_.run();
    });

    t.detach();
}

Illusion::~Illusion() {

}

} // namespace il
