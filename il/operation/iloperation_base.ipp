#ifndef ILOPERATIONBASE_IPP
#define ILOPERATIONBASE_IPP

namespace il {

inline ilstate ILOperationBase::state() const {
  return state_;
}

inline iltime ILOperationBase::startTime() const {
  return startTime_;
}

inline iltime ILOperationBase::stopTime() const {
  return stopTime_;
}

inline iltime ILOperationBase::duration() const {
  return stopTime_ - startTime_;
}

} // namespace il

#endif // ILOPERATIONBASE_IPP

