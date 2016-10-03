#ifndef ILLUSION_IPP
#define ILLUSION_IPP

namespace il {

Illusion* Illusion::instance_ = nullptr;

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

} // namespace il

#endif // ILLUSION_IPP
