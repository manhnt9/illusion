#ifndef ILCORE_IPP
#define ILCORE_IPP

namespace il {
namespace service {

inline ILCore* ILCore::instance() {
  if (!instance_)
    instance_ = new ILCore();

  return instance_;
}

inline asio::io_service& ILCore::getService() {
  return service_;
}

} // namespace service 
} // namespace il

#endif // ILCORE_IPP
