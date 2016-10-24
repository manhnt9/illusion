#include "ilbenchmark.hpp"
#include "illusion/iloperation.hpp"
#include "illusion/ilmanager.hpp"
#include "ildelayedoperation.hpp"
#include "illusion/illusion.hpp"
#include "illusion/ilmanager.hpp"
#include <google/protobuf/message.h>
#include <chrono>

namespace il {

ILBenchmark::ILBenchmark(quint64 duration, quint64 delayMsec)
    :   QObject(nullptr),
        duration_(duration),
        delay_(delayMsec),
        timer_(Illusion::instance()->getService()),
        done_(false)
{
    ILManager::instance()->addBenchmark(this);
}

void ILBenchmark::addOperation(ILOperation* op) {
    opList_.push_back(op);
    connect(op, &ILOperation::finished, this, &ILBenchmark::runNext);
}

void ILBenchmark::run() {
    DLOG(INFO) << opList_.first()->request()->GetTypeName() << " benchmark started";

    timer_.expires_from_now(std::chrono::seconds(duration_));
    timer_.async_wait([this] (const std::error_code& e) {
        if (!e) {
            this->done_ = true;
            DLOG(INFO) << opList_.first()->request()->GetTypeName() << " benchmark finished after " << duration_ << " seconds";
        }
    });

    for (const auto& op : opList_) {
        op->run();
    }
}

void ILBenchmark::runNext(quint64 id) {
    if (done_)
        return;

    ILOperation* op = ILManager::instance()->getOperation(id);
    hook_(op);
    auto o = std::make_shared<ILDelayedOperation>(op);
    o->run(delay_);
}

ILBenchmark::~ILBenchmark() {
    ILManager::instance()->removeBenchmark(this);
}

} // namespace il
