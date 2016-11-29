#ifndef ILCORE_IPP
#define ILCORE_IPP

#include <chrono>

namespace il {
namespace service {

inline auto ILCore::instance() {
  if (!instance_)
    instance_ = new ILCore();

  return instance_;
}

inline auto& ILCore::service() {
  return service_;
}

inline auto ILCore::time() const {
 using namespace std::chrono;
 return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

} // namespace service 
} // namespace il

#endif // ILCORE_IPP

