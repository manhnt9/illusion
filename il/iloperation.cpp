#include "iloperation.hpp"

namespace il {

ILOperation::ILOperation()
  :  QObject(nullptr),
     id_(0),
     state_(ILState::CREATED),
     startTime_(0),
     finishTime_(0)
{

}

ILOperation::~ILOperation()
{

}

} // namespace il
