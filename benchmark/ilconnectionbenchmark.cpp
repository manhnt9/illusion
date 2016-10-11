#include "ilconnectionbenchmark.hpp"
#include <glog/logging.h>
#include <QDir>
#include <QDirIterator>
#include <QThread>
#include <fstream>
#include <thread>

namespace il {

ILConnectionBenchmark::ILConnectionBenchmark(QString ip, quint16 port)
    :   QObject(nullptr),
        ip_(ip),
        port_(port),
        total_(0)
{

}

void ILConnectionBenchmark::run(quint64 numClient) {
    LOG(INFO) << "Connection benchmark started for 60s";

    auto basePath = QDir::currentPath().toStdString() + "/connect";
    auto connectPath = basePath + "/ilconnect ";
    auto pidPath = basePath + "/pid";

    std::system(("rm " + pidPath + "/*").c_str());

    auto cmd = connectPath + ip_.toStdString() + " " + std::to_string(port_) + " " + pidPath + " &";

    for (quint64 i = 0; i < numClient; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::system(cmd.c_str());
        DLOG(INFO) << "Connection benchmark: client invoked, remaining "  << numClient-i-1 << " s" ;
    }

    LOG(INFO) << "Connection benchmark: invoked " << numClient << " clients";

    // wait for clients
    LOG(INFO) << "Connection benchmark completed, 5s to collect results";

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::system("pkill ilconnect");

    QDirIterator it(pidPath.c_str(), QStringList() << "*", QDir::Files, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        std::ifstream f(it.next().toStdString());
        std::uint64_t num;
        f >> num;

        if (num <= 1000)
            total_ += num;
    }

    DLOG(INFO) << "Connection benchmark result: " << total_;
}

ILConnectionBenchmark::~ILConnectionBenchmark() {

}

} // namespace il
