#ifndef ILTCPOPERATION_IPP
#define ILTCPOPERATION_IPP

#include "ilprint.hpp"
#include "iloperation.hpp"

namespace il {

inline void ILTcpOperation::onConnect(const std::error_code& e) {
  if (!e) {
      write();
  } else {
      IL_PRINT << "Connection error: " << e.message();
  }
}

inline auto ILTcpOperation::bytesSent() const {
  return bytesSent_;
}

inline auto ILTcpOperation::bytesReceived() const {
  return bytesReceived_;
}

} // namespace il

#endif // ILTCPOPERATION_IPP
