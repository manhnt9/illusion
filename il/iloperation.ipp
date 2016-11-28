#ifndef ILOPERATION_IPP
#define ILOPERATION_IPP

#include <QDateTime>

namespace il {

inline void ILOperation::start() {
  state_ = il::ILState::RUNNING;
  startTime_ = QDateTime::currentMSecsSinceEpoch();
}

inline void ILOperation::finish() {
  state_ = il::ILState::FINISHED;
  finishTime_ = QDateTime::currentMSecsSinceEpoch();
  emit finished(id_);
}

inline void ILOperation::setId(quint64 id) {
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

