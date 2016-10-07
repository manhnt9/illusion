#ifndef ILMANAGER_IPP
#define ILMANAGER_IPP

namespace il {

inline ILManager* ILManager::instance() {
    if (!instance_)
        instance_ = new ILManager();

    return instance_;
}

inline quint64 ILManager::addOperation(ILOperation* op) {
    opList_.insert(opId_, op);
    return opId_++;
}

inline ILOperation* ILManager::getOperation(quint64 id) const {
    return opList_.value(id);
}

inline void ILManager::removeOperation(quint64 id) {
    opList_.remove(id);
}

} // namespace il

#endif // ILMANAGER_IPP
