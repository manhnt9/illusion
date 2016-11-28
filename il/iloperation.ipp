#ifndef ILOPERATION_IPP
#define ILOPERATION_IPP

#include <QDateTime>

namespace il {

inline void ILOperation::start() {
  state_ = il::State::RUNNING;
  startTime_ = QDateTime::currentMSecsSinceEpoch();
}

inline void ILOperation::finish() {
  state_ = il::State::FINISHED;
  finishTime_ = QDateTime::currentMSecsSinceEpoch();
  emit finished(id_);
}

inline void ILOperation::setId(quint64 id) {
  id_ = id;
}

inline quint64 ILOperation::id() const {
  return id_;
}

inline State ILOperation::state() const {
  return state_;
}

inline quint64 ILOperation::startTime() const {
  return startTime_;
}

inline quint64 ILOperation::finishTime() const {
  return finishTime_;
}

inline quint64 ILOperation::duration() const {
  return finishTime_ - startTime_;
}

} // namespace il

#endif // ILOPERATION_IPP
