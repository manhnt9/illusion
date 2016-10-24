#include "iloperation.hpp"
#include "ilmanager.hpp"
#include <google/protobuf/message.h>

namespace il {

ILOperation::ILOperation()
    :   QObject(nullptr),
        id_(ILManager::instance()->addOperation(this)),
        state_(State::CREATED),
        startTime_(0),
        finishTime_(0),
        request_(nullptr),
        reply_(nullptr)
{

}

ILOperation::~ILOperation()
{
    if (request_)
        delete request_;
    if (reply_)
        delete reply_;

    ILManager::instance()->removeOperation(this->id());
}

} // namespace il
