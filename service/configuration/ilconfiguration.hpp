#ifndef ILCONFIGURATION_HPP
#define ILCONFIGURATION_HPP

#include <string>

namespace il {
namespace service {

class ILConfiguration {
public:
  ILConfiguration();
  ~ILConfiguration();

  static auto instance();

  void init(int argc, char* argv[]);

  auto host() const;
  auto port() const;

private:
  static ILConfiguration* instance_;
  std::string host_;
  unsigned short port_;
};

} // namespace service 
} // namespace il

#include "ilconfiguration.ipp"

#endif // ILCONFIGURATION_HPP

