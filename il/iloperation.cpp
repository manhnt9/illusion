#include "iloperation.hpp"
#include <service/ilservice.hpp>

namespace il {

ILOperation::ILOperation()
  :  id_(0),
     state_(ILState::CREATED),
     startTime_(0),
     finishTime_(0)
{

}

void ILOperation::start() {
  state_ = il::ILState::RUNNING;
  startTime_ = IL_GET_SERVICE(ILCORE)->time(); 
}

void ILOperation::finish() {
  state_ = il::ILState::FINISHED;
  finishTime_ = IL_GET_SERVICE(ILCORE)->time();
  sigFinished_.emit(id_);
}


ILOperation::~ILOperation()
{

}

} // namespace il

