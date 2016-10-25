#ifndef ILTCPOPERATION_IPP
#define ILTCPOPERATION_IPP

#include "iloperation.hpp"
#include <glog/logging.h>

namespace il {

inline void ILTcpOperation::connect(const asio::ip::tcp::endpoint& endpoint) {
    if (!socket_)
        socket_ = new TcpSocket(Illusion::instance()->getService());

    socket_->async_connect(endpoint, std::bind(&ILTcpOperation::onConnect,
                                               this, std::placeholders::_1));
}

inline void ILTcpOperation::onConnect(const std::error_code& e) {
    if (!e) {
        DLOG(INFO) << "TCP connection opened";
    } else {
        DLOG(ERROR) << "Connection error: " << e.message();
    }
}

inline std::size_t ILTcpOperation::bytesSent() const {
    return bytesSent_;
}

inline std::size_t ILTcpOperation::bytesReceived() const {
    return bytesReceived_;
}

} // namespace il

#endif // ILTCPOPERATION_IPP
