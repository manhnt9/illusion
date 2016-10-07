#include "iloperation.hpp"
#include "ilmanager.hpp"
#include <google/protobuf/message_lite.h>

namespace il {

ILOperation::ILOperation()
    :   QObject(nullptr),
        id_(ILManager::instance()->addOperation(this)),
        state_(State::CREATED),
        startTime_(0),
        finishTime_(0)
{

}

ILOperation::~ILOperation()
{
    ILManager::instance()->removeOperation(this->id());
}

} // namespace il
