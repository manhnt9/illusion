#include "iltcpoperation.hpp"
#include <google/protobuf/message.h>

namespace il {

ILTcpOperation::ILTcpOperation(ILMessagePtr rq)
    :   ILOperation(),
        socket_(nullptr),
        bytesSent_(0),
        bytesReceived_(0)
{
    Q_ASSERT(rq);
    Q_ASSERT(rq->IsInitialized());

    request_ = rq;
}

void ILTcpOperation::run() {

}

ILTcpOperation::~ILTcpOperation()
{
    if (socket_)
        delete socket_;
}

} // namespace il

