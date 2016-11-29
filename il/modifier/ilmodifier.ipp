#ifndef ILMODIFIER_IPP
#define ILMODIFIER_IPP

namespace il {

inline void ILModifier::setClient(const std::shared_ptr<ILClient> client) {
  client_ = client;
}

} // namespace il

#endif // ILMODIFIER_IPP

