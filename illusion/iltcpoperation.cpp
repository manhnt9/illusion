#include "iltcpoperation.hpp"
#include "iloperation.hpp"
#include "illusion.hpp"

namespace il {

ILTcpOperation::ILTcpOperation(QObject *parent)
    :   QObject(parent),
        socket_(Illusion::instance()->getService()),
        impl_(new ILOperation(0))
{

}

ILTcpOperation::~ILTcpOperation()
{
    delete impl_;
}

} // namespace il

