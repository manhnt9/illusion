#include "iltcpoperation.hpp"
#include "iloperation.hpp"
#include "illusion.hpp"
#include <cassert>

namespace il {

ILTcpOperation::ILTcpOperation(ILMessage *m, QObject *parent)
    :   QObject(parent),
        impl_(new ILOperation(0)),
        socket_(Illusion::instance()->getService()),
        bytesSent_(0),
        bytesReceived_(0)
{
    assert(m);
    impl_->message() = m;
}

ILTcpOperation::~ILTcpOperation()
{
    delete impl_;
}

} // namespace il

