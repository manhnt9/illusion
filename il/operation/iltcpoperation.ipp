#ifndef ILTCPOPERATION_IPP
#define ILTCPOPERATION_IPP

namespace il {

inline auto ILTcpOperation::isConnected() const {
  return socket_->is_open();
}

inline auto ILTcpOperation::bytesSent() const {
  return bytesSent_;
}

inline auto ILTcpOperation::bytesReceived() const {
  return bytesReceived_;
}

} // namespace il

#endif // ILTCPOPERATION_IPP

