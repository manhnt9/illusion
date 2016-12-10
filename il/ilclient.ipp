#ifndef ILCLIENT_IPP
#define ILCLIENT_IPP

namespace il {

inline const auto& ILClient::operation() const {
  return *operation_;
}

} // namespace il

#endif // ILCLIENT_IPP

