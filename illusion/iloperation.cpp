#include "iloperation.hpp"

namespace il {

ILOperation::ILOperation(quint32 id, QObject *parent)
    :   QObject(parent),
        id_(id),
        state_(State::CREATED),
        startTime_(0),
        finishTime_(0)
{

}

ILOperation::~ILOperation()
{

}

} // namespace il
