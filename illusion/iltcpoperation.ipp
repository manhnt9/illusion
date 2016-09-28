#ifndef ILTCPOPERATION_IPP
#define ILTCPOPERATION_IPP

#include "iloperation.hpp"

namespace il {

inline void ILTcpOperation::start() {
    impl_->start();
}

inline void ILTcpOperation::finish() {
    impl_->finish();
    emit finished(id());
}

inline void ILTcpOperation::connect(asio::ip::tcp::endpoint& endpoint) {
    socket_.async_connect(endpoint, std::bind(&ILTcpOperation::onConnect,
                                              this, std::placeholders::_1));
}

inline void ILTcpOperation::onConnect(const std::error_code& e) {
    if (!e) {
        read();
    } else {
        // TODO: handle operation connect error
    }
}

inline void ILTcpOperation::read() {
    asio::async_read(socket_, buffer_, std::bind(&ILTcpOperation::onRead, this,
                                                 std::placeholders::_1, std::placeholders::_2));
}

inline void ILTcpOperation::onRead(const std::error_code& e, const std::size_t bytes) {
    bytes_received_ += bytes;

    if (!e) {
        write();
    } else {
        // TODO: handle operation read error
    }
}

inline void ILTcpOperation::write() {
    asio::async_write(socket_, buffer_, std::bind(&ILTcpOperation::onWrite, this,
                                                  std::placeholders::_1, std::placeholders::_2));
}

inline void ILTcpOperation::onWrite(const std::error_code& e, const std::size_t bytes) {
    bytes_sent_ += bytes;

    if (!e) {
        read();
    } else {
        // TODO: handle operation write error
    }

    buffer_.consume(bytes);
}

inline quint32 ILTcpOperation::id() const {
    return impl_->id();
}

inline State ILTcpOperation::state() const {
    return impl_->state();
}

inline quint64 ILTcpOperation::startTime() const {
    return impl_->startTime();
}

inline quint64 ILTcpOperation::finishTime() const {
    return impl_->finishTime();
}

inline std::size_t ILTcpOperation::bytesSent() const {
    return bytes_sent_;
}

inline std::size_t ILTcpOperation::bytesReceived() const {
    return bytes_received_;
}

} // namespace il

#endif // ILTCPOPERATION_IPP
