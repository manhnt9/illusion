#ifndef ILLUSION_IPP
#define ILLUSION_IPP

#include <glog/logging.h>

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

inline void Illusion::stop() {
    LOG(INFO) << "Stopping benchmark";

    delete work_;
    service_.stop();
}

inline void Illusion::run() {
    LOG(INFO) << "Benchmark has started";

    work_ = new asio::io_service::work(service_);
    service_.run();
}

} // namespace il

#endif // ILLUSION_IPP
