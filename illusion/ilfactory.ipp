#ifndef ILFACTORY_IPP
#define ILFACTORY_IPP

namespace il {

ILFactory* ILFactory::instance_ = nullptr;

inline ILFactory* ILFactory::instance() {
    if (!instance_)
        instance_ = new ILFactory();

    return instance_;
}

} // namespace il

#endif // ILFACTORY_IPP
