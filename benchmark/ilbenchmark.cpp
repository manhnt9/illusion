#include "ilbenchmark.hpp"

namespace il {

ILBenchmark::ILBenchmark(const QString& messName, quint64 duration, quint32 numOps, quint16 delay)
    :   QObject(nullptr),
        messageName_(messName),
        duration_(duration),
        numOps_(numOps),
        delay_(delay)
{

}

} // namespace il
