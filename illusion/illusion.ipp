#ifndef ILLUSION_IPP
#define ILLUSION_IPP

#include "ilprint.hpp"
#include "benchmark/ilbenchmark.hpp"
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
    connect(bench.get(), &ILBenchmark::finished, this, &Illusion::runNext);
}

inline void Illusion::removeBenchmark(ILBenchmarkPtr bench) const {
    ILManager::instance()->removeBenchmark(bench);
}

inline void Illusion::stop() {
    IL_PRINT << "Stopping ...";

    delete work_;
    service_.stop();
}

inline void Illusion::restart() {
    stop();
    run();
}

} // namespace il

#endif // ILLUSION_IPP
