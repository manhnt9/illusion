#include "ilmanager.hpp"
//#include "../../benchmark/ilbenchmark.hpp"
#include <algorithm>

namespace il {
namespace service {

ILManager* ILManager::instance_ = nullptr;

ILManager::ILManager()
  :  opId_(0)
{

}

ILBenchmarkPtr ILManager::getBenchmark(const std::string& name) const {
//    for (const auto& b : benchList_) {
//        if (b->name() == name)
//            return b;
//    }
  return nullptr;
}

void ILManager::removeBenchmark(ILBenchmarkPtr bench) {
  benchList_.erase(std::remove(benchList_.begin(), benchList_.end(), bench), benchList_.end());
}

ILManager::~ILManager() {

}

} // namespace service 
} // namespace il
