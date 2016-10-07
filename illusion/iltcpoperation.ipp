#ifndef ILTCPOPERATION_IPP
#define ILTCPOPERATION_IPP

#include "iloperation.hpp"
#include <glog/logging.h>

namespace il {

inline void ILTcpOperation::connect(asio::ip::tcp::endpoint& endpoint) {
    if (!socket)
        socket_ = new TcpSocket(Illusion::instance()->getService());

    socket_->async_connect(endpoint, std::bind(&ILTcpOperation::onConnect,
                                               this, std::placeholders::_1));
}

inline void ILTcpOperation::onConnect(const std::error_code& e) {
    if (!e) {
        read();
    } else {
        LOG(ERROR) << "Connection error: " << e.message();
    }
}

inline void ILTcpOperation::read() {
    asio::async_read(*socket_, buffer_, std::bind(&ILTcpOperation::onRead, this,
                                                  std::placeholders::_1, std::placeholders::_2));
}

inline void ILTcpOperation::onRead(const std::error_code& e, const std::size_t bytes) {
    bytesReceived_ += bytes;

    if (!e) {
        write();
    } else {
        LOG(ERROR) << "Read error: " << e.message();
    }
}

inline void ILTcpOperation::write() {
    asio::async_write(*socket_, buffer_, std::bind(&ILTcpOperation::onWrite, this,
                                                   std::placeholders::_1, std::placeholders::_2));
}

inline void ILTcpOperation::onWrite(const std::error_code& e, const std::size_t bytes) {
    bytesSent_ += bytes;

    if (!e) {
        read();
    } else {
        LOG(ERROR) << "Write error: " << e.message();
    }

    buffer_.consume(bytes);
}

inline std::size_t ILTcpOperation::bytesSent() const {
    return bytesSent_;
}

inline std::size_t ILTcpOperation::bytesReceived() const {
    return bytesReceived_;
}

} // namespace il

#endif // ILTCPOPERATION_IPP
