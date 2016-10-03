#ifndef ILSUITE_IPP
#define ILSUITE_IPP

namespace il {

inline Type ILSuite::type() const {
    return type_;
}

inline ILSuite::Config* ILSuite::config() const {
    return config_;
}

inline State ILSuite::state() const {
    return state_;
}

inline int ILSuite::completedCount() const {
    return completedCount_;
}

inline int ILSuite::failedCount() const {
    return failedCount_;
}

} // namespace il

#endif // ILSUITE_IPP
