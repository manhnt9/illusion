#ifndef ILBENCHMARK_IPP
#define ILBENCHMARK_IPP

namespace il {

inline QString ILBenchmark::name() const {
    return name_;
}

inline void ILBenchmark::setInitializer(Initializer&& init) {
    init_ = std::move(init);
}

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

inline ILOperationPtr ILBenchmark::getOperation(int index) const {
    return opList_.at(index);
}

inline int ILBenchmark::operationCount() const {
    return opList_.size();
}

}

#endif // ILBENCHMARK_IPP
