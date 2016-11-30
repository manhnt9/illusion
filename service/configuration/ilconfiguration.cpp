#include "ilconfiguration.hpp"

namespace il {
namespace service {

ILConfiguration* ILConfiguration::instance_ = nullptr;

ILConfiguration::ILConfiguration() 
  :  host_("127.0.0.1"),
     port_(1311)
{

}

void ILConfiguration::init(int argc, char* argv[]) {

}

ILConfiguration::~ILConfiguration() {

}

} // namespace service 
} // namespace il

