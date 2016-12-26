#ifndef ILMODIFIER_IPP
#define ILMODIFIER_IPP

namespace il {

inline void ILModifier::setClient(const std::shared_ptr<ILClient> client) {
  client_ = client;
}

inline auto ILModifier::type() const {
  return type_;
}

inline void ILModifier::setTime(const iltime time) {
  time_ = time;
}

inline auto ILModifier::time() const {
  return time_;
}

} // namespace il

#endif // ILMODIFIER_IPP

