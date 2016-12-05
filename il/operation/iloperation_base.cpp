#include "iloperation_base.hpp"
#include "ilstate.hpp"
#include <service/ilservice.hpp>

namespace il {

ILOperationBase::ILOperationBase()
  :  id_(0),
     state_(il::ilstate::CREATED),
     startTime_(0),
     finishTime_(0)
{

}

void ILOperationBase::start() {
  state_ = il::ilstate::RUNNING;
  startTime_ = IL_GET_SERVICE(ILCORE)->time(); 
}

void ILOperationBase::finish() {
  state_ = il::ilstate::FINISHED;
  finishTime_ = IL_GET_SERVICE(ILCORE)->time();
  sigFinished_.emit(id_);
}


ILOperationBase::~ILOperationBase()
{

}

} // namespace il

