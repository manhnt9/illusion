#include "iltcpoperation.hpp"
#include "iloperation.hpp"
#include "illusion.hpp"

namespace il {

ILTcpOperation::ILTcpOperation(QObject *parent)
    :   QObject(parent),
        impl_(new ILOperation(0)),
        socket_(Illusion::instance()->getService()),
        bytes_sent_(0),
        bytes_received_(0)
{

}

ILTcpOperation::~ILTcpOperation()
{
    delete impl_;
}

} // namespace il

