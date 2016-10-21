#ifndef ILBENCHMARK_IPP
#define ILBENCHMARK_IPP

namespace il {

inline void ILBenchmark::setOperationHook(OperationHook&& hook) {
    hook_ = std::move(hook);
}

}

#endif // ILBENCHMARK_IPP
