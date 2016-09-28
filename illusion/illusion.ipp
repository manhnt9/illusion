#ifndef ILLUSION_IPP
#define ILLUSION_IPP

namespace il {

inline asio::io_service& Illusion::getService() {
    return service_;
}

} // namespace il

#endif // ILLUSION_IPP
