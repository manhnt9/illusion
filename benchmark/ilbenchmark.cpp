#include "ilbenchmark.hpp"
#include "illusion/iloperation.hpp"
#include "illusion/ilmanager.hpp"
#include "ildelayedoperation.hpp"

namespace il {

ILBenchmark::ILBenchmark(quint64 duration, quint64 delayMsec)
    :   QObject(nullptr),
        duration_(duration),
        delay_(delayMsec)
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
    ILOperation* op = ILManager::instance()->getOperation(id);
    hook_(op);
    auto o = std::make_shared<ILDelayedOperation>(op);
    o->run(delay_);
}

} // namespace il
