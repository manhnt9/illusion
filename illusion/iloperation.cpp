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

ILOperation& ILOperation::operator=(const ILOperation& other) {
    id_ = other.id();
    state_ = other.state();
    startTime_ = other.startTime();
    finishTime_ = other.finishTime();
    request_ = other.request();
    reply_ = other.reply();
    return *this;
}

} // namespace il
