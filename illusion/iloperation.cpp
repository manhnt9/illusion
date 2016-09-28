#include "iloperation.hpp"

namespace il {

ILOperation::ILOperation(quint32 id, QObject *parent)
    :   QObject(parent),
        id_(id),
        state_(State::CREATED),
        start_time_(0),
        finish_time_(0)
{

}

ILOperation::~ILOperation()
{

}

} // namespace il
