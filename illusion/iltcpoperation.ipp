#ifndef ILTCPOPERATION_IPP
#define ILTCPOPERATION_IPP

#include "iloperation.hpp"

namespace il {

inline void ILTcpOperation::onConnect(const std::error_code& e) {
    if (!e) {
        IL_PRINT << "TCP connection opened";
    } else {
        IL_PRINT << "Connection error: " << e.message();
    }
}

inline std::size_t ILTcpOperation::bytesSent() const {
    return bytesSent_;
}

inline std::size_t ILTcpOperation::bytesReceived() const {
    return bytesReceived_;
}

inline ILTcpSocketPtr ILTcpOperation::socket() const {
    return socket_;
}

} // namespace il

#endif // ILTCPOPERATION_IPP
