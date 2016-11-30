#ifndef ILCORE_HPP
#define ILCORE_HPP

#include <asio.hpp>

namespace il {
namespace service {

class ILCore {
public:
  ILCore();
  ~ILCore();

  static auto instance();
  auto& service();

  auto time() const;

private:
  static ILCore* instance_;
  asio::io_service service_;
};

} // namespace service
} // namespace il

#include "ilcore.ipp"

#endif // ILCORE_HPP

