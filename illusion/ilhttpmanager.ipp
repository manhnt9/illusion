#ifndef ILHTTPMANAGER_IPP
#define ILHTTPMANAGER_IPP

namespace il {

inline ILHttpManager* ILHttpManager::instance() {
    if (!instance_)
        instance_ = new ILHttpManager();

    return instance_;
}

} // namespace il

#endif // ILHTTPMANAGER_IPP
