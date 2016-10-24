#include "iloperation.hpp"
#include "ilmanager.hpp"
#include <google/protobuf/message.h>

namespace il {

ILOperation::ILOperation()
    :   QObject(nullptr),
        id_(0),
        state_(State::CREATED),
        startTime_(0),
        finishTime_(0),
        request_(nullptr),
        reply_(nullptr)
{

}

ILOperation::~ILOperation()
{

}

} // namespace il
