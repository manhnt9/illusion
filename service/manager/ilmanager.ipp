#ifndef ILMANAGER_IPP
#define ILMANAGER_IPP

#include <algorithm>

namespace il {
namespace service {

inline ILManager* ILManager::instance() {
  if (!instance_)
    instance_ = new ILManager();

  return instance_;
}

inline std::uint64_t ILManager::addOperation(ILOperationPtr op) {
  opList_.insert({opId_, op});
  return opId_++;
}

inline ILOperationPtr ILManager::getOperation(std::uint64_t id) const {
  return opList_.at(id);
}

inline void ILManager::removeOperation(std::uint64_t id) {
  opList_.erase(id);
}

inline void ILManager::addBenchmark(ILBenchmarkPtr bench) {
  benchList_.push_back(bench);
}

inline ILBenchmarkPtr ILManager::getBenchmark(int index) const {
  return benchList_.at(index);
}

inline void ILManager::removeBenchmark(ILBenchmarkPtr bench) {
  benchList_.erase(std::remove(benchList_.begin(), benchList_.end(), bench), benchList_.end());
}

inline int ILManager::benchmarkCount() const {
  return benchList_.size();
}

} // namespace service 
} // namespace il

#endif // ILMANAGER_IPP
