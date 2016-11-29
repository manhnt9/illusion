#ifndef ILOPERATION_IPP
#define ILOPERATION_IPP

namespace il {

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

inline auto& ILOperation::sigFinished() {
  return sigFinished_;
}

} // namespace il

#endif // ILOPERATION_IPP

