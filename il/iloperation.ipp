#ifndef ILOPERATION_IPP
#define ILOPERATION_IPP

namespace il {

inline void ILOperation::start() {
  state_ = il::ILState::RUNNING;
  // TODO: fix get time startTime_ = QDateTime::currentMSecsSinceEpoch();
}

inline void ILOperation::finish() {
  state_ = il::ILState::FINISHED;
  // TODO: fix get time finishTime_ = QDateTime::currentMSecsSinceEpoch();
  // TODO: implement signal slot emit finished(id_);
}

inline void ILOperation::setId(std::uint64_t id) {
  id_ = id;
}

inline auto ILOperation::id() const {
  return id_;
}

inline auto ILOperation::state() const {
  return state_;
}

inline auto ILOperation::startTime() const {
  return startTime_;
}

inline auto ILOperation::finishTime() const {
  return finishTime_;
}

inline auto ILOperation::duration() const {
  return finishTime_ - startTime_;
}

} // namespace il

#endif // ILOPERATION_IPP

