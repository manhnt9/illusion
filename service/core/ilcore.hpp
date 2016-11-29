#ifndef ILCORE_HPP
#define ILCORE_HPP

#include <asio.hpp>

namespace il {
namespace service {

class ILCore {
public:
  explicit ILCore();
  virtual ~ILCore();

  static ILCore* instance();
  asio::io_service& service();

  std::uint64_t time() const;

private:
  static ILCore* instance_;
  asio::io_service service_;
};

} // namespace service
} // namespace il

#include "ilcore.ipp"

#endif // ILCORE_HPP

