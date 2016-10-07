#include "iltcpoperation.hpp"
#include "iloperation.hpp"
#include "illusion.hpp"

namespace il {

ILTcpOperation::ILTcpOperation(ILMessage *m, QObject *parent)
    :   QObject(parent),
        impl_(new ILOperation(0)),
        socket_(nullptr),
        bytesSent_(0),
        bytesReceived_(0)
{
    Q_ASSERT(m);
    impl_->request() = m;
}

ILTcpOperation::~ILTcpOperation()
{
    delete impl_;
    if (socket_)
    delete socket_;
}

} // namespace il

