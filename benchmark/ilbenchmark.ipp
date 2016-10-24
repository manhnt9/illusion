#ifndef ILBENCHMARK_IPP
#define ILBENCHMARK_IPP

namespace il {

inline void ILBenchmark::setOperationHook(OperationHook&& hook) {
    hook_ = std::move(hook);
}

inline quint64 ILBenchmark::totalOps() const {
    return totalOps_;
}

inline quint64 ILBenchmark::fastestResponse() const {
    return fastestResponse_;
}

inline quint64 ILBenchmark::slowestResponse() const {
    return slowestResponse_;
}

inline quint64 ILBenchmark::speed() const {
    return speed_;
}

}

#endif // ILBENCHMARK_IPP
