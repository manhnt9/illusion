#ifndef ILMANAGER_IPP
#define ILMANAGER_IPP

namespace il {

inline ILManager* ILManager::instance() {
    if (!instance_)
        instance_ = new ILManager();

    return instance_;
}

inline quint64 ILManager::opId(ILOperation* op) {
    opList_.insert(opId_, op);
    return opId_++;
}

inline void ILManager::removeOperation(quint64 id) {
    opList_.remove(id);
}

} // namespace il

#endif // ILMANAGER_IPP
