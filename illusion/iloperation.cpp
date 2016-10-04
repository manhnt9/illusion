#include "iloperation.hpp"
#include "ilmanager.hpp"

namespace il {

ILOperation::ILOperation(QObject *parent)
    :   QObject(parent),
        id_(ILManager::instance()->opId()),
        state_(State::CREATED),
        startTime_(0),
        finishTime_(0)
{

}

ILOperation::~ILOperation()
{

}

} // namespace il
