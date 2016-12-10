#include "iloperation_base.hpp"
#include "ilstate.hpp"
#include <service/ilservice.hpp>

namespace il {

ILOperationBase::ILOperationBase()
  :  id_(0),
     state_(il::ilstate::CREATED),
     startTime_(0),
     stopTime_(0)
{

}

bool ILOperationBase::isRunning() const {
  return state_ == il::ilstate::RUNNING;
}

void ILOperationBase::start() {
  state_ = il::ilstate::RUNNING;
  startTime_ = IL_GET_SERVICE(ILCORE)->time(); 
}

void ILOperationBase::stop() {
  state_ = il::ilstate::STOPPED;
  stopTime_ = IL_GET_SERVICE(ILCORE)->time();
}

ILOperationBase::~ILOperationBase() {

}

} // namespace il

