#ifndef ILTCPOPERATION_IPP
#define ILTCPOPERATION_IPP

#include <ilprint.hpp>

namespace il {

inline void ILTcpOperation::run() {

}

inline auto ILTcpOperation::bytesSent() const {
  return bytesSent_;
}

inline auto ILTcpOperation::bytesReceived() const {
  return bytesReceived_;
}

} // namespace il

#endif // ILTCPOPERATION_IPP

