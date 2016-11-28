#ifndef ILMANAGER_IPP
#define ILMANAGER_IPP

namespace il {
namespace service {

inline ILManager* ILManager::instance() {
    if (!instance_)
        instance_ = new ILManager();

    return instance_;
}

inline quint64 ILManager::addOperation(ILOperationPtr op) {
    opList_.insert(opId_, op);
    return opId_++;
}

inline ILOperationPtr ILManager::getOperation(quint64 id) const {
    return opList_.value(id);
}

inline void ILManager::removeOperation(quint64 id) {
    opList_.remove(id);
}

inline void ILManager::addBenchmark(ILBenchmarkPtr bench) {
    benchList_.push_back(bench);
}

inline ILBenchmarkPtr ILManager::getBenchmark(int index) const {
   return benchList_.at(index);
}

inline void ILManager::removeBenchmark(ILBenchmarkPtr bench) {
    benchList_.removeOne(bench);
}

inline int ILManager::benchmarkCount() const {
    return benchList_.size();
}

} // namespace service 
} // namespace il

#endif // ILMANAGER_IPP
