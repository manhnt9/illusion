#ifndef ILLUSION_IPP
#define ILLUSION_IPP

#include <glog/logging.h>
#include <thread>

namespace il {

inline Illusion* Illusion::instance() {
    if (!instance_)
        instance_ = new Illusion();

    return instance_;
}

inline asio::io_service& Illusion::getService() {
    return service_;
}

inline asio::ip::tcp::endpoint Illusion::getEndpoint() const {
    return endpoint_;
}

inline void Illusion::addBenchmark(ILBenchmarkPtr bench) const {
    ILManager::instance()->addBenchmark(bench);
}

inline void Illusion::removeBenchmark(ILBenchmarkPtr bench) const {
    ILManager::instance()->removeBenchmark(bench);
}

inline void Illusion::stop() {
    DLOG(INFO) << "Stopping ...";

    delete work_;
    service_.stop();
}

} // namespace il

#endif // ILLUSION_IPP
