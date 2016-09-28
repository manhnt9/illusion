#ifndef ILOPERATION_IPP
#define ILOPERATION_IPP

#include <QDateTime>

namespace il {

inline void ILOperation::start() {
    start_time_ = QDateTime::currentMSecsSinceEpoch();
}

inline void ILOperation::finish() {
    finish_time_ = QDateTime::currentMSecsSinceEpoch();
    emit finished(id_);
}

inline quint32 ILOperation::id() const {
    return id_;
}

inline State ILOperation::state() const {
    return state_;
}

inline quint64 ILOperation::startTime() const {
    return start_time_;
}

inline quint64 ILOperation::finishTime() const {
    return finish_time_;
}

} // namespace il

#endif // ILOPERATION_IPP
