#ifndef ILCONFIGURATION_IPP
#define ILCONFIGURATION_IPP

namespace il {
namespace service {

inline auto ILConfiguration::instance() {
  if (!instance_)
    instance_ = new ILConfiguration();
  return instance_;
}

inline auto ILConfiguration::host() const {
  return host_;
}

inline auto ILConfiguration::port() const {
  return port_;
}

} // namespace service 
} // namespace il

#endif // ILCONFIGURATION_IPP

