#include "ilbenchmark.hpp"
#include "illusion/iloperation.hpp"
#include "illusion/ilmanager.hpp"
#include "ildelayedoperation.hpp"

namespace il {

ILBenchmark::ILBenchmark(const QString& messName, quint64 duration, quint64 delay)
    :   QObject(nullptr),
        messageName_(messName),
        duration_(duration),
        delay_(delay)
{

}

void ILBenchmark::addOperation(ILOperation* op) {
    opList_.push_back(op);
    connect(op, &ILOperation::finished, this, &ILBenchmark::runNext);
}

void ILBenchmark::run() {
    for (const auto& op : opList_) {
        op->run();
    }
}

void ILBenchmark::runNext(quint64 id) {
    // TODO: generate new message and run delayed operation
    ILOperation* op = ILManager::instance()->getOperation(id);
    auto o = std::make_shared<ILDelayedOperation>(op);
    o->run(delay_);
}

} // namespace il
