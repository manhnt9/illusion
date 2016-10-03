#ifndef ILLUSION_IPP
#define ILLUSION_IPP

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
    delete work_;
    service_.stop();
}

inline void Illusion::run() {
    work_ = new asio::io_service::work(service_);
    service_.run();
}

} // namespace il

#endif // ILLUSION_IPP
