#include "ilbenchmark.hpp"

namespace il {

ILBenchmark::ILBenchmark(const QString& opName, quint64 duration, quint32 numOps, quint16 delay)
    :   QObject(nullptr),
        opName_(opName),
        duration_(duration),
        numOps_(numOps),
        delay_(delay)
{

}

} // namespace il
