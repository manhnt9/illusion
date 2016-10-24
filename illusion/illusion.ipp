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

inline void Illusion::stop() {
    LOG(INFO) << "Stopping ...";

    delete work_;
    service_.stop();
}

inline void Illusion::run() {
    LOG(INFO) << "Running all benchmarks";

    work_ = new asio::io_service::work(service_);

    std::thread t([&] () {
        this->service_.run();
    });

    t.detach();
}

} // namespace il

#endif // ILLUSION_IPP
