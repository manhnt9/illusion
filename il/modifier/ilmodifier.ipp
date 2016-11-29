#ifndef ILMODIFIER_IPP
#define ILMODIFIER_IPP

namespace il {

inline void ILModifier::addClient(const std::shared_ptr<ILClient> client) {
  clients_.push_back(client);
}

} // namespace il

#endif // ILMODIFIER_IPP

