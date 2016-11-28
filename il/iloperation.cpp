#include "iloperation.hpp"
#include "ilmanager.hpp"

namespace il {

ILOperation::ILOperation()
    :   QObject(nullptr),
        id_(0),
        state_(State::CREATED),
        startTime_(0),
        finishTime_(0)
{

}

ILOperation::~ILOperation()
{

}

} // namespace il
