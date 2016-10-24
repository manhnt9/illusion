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
        done_(false),
        totalOps_(0),
        fastestResponse_(0),
        slowestResponse_(0),
        speed_(0)
{

}

void ILBenchmark::addOperation(ILOperationPtr op) {
    op->setId(ILManager::instance()->addOperation(op));
    opList_.push_back(op);
    connect(op.get(), &ILOperation::finished, this, &ILBenchmark::runNext);
}

void ILBenchmark::run() {
    DLOG(INFO) << opList_.first()->request()->GetTypeName() << " benchmark started";

    timer_.expires_from_now(std::chrono::seconds(duration_));
    timer_.async_wait([this] (const std::error_code& e) {
        if (!e) {
            this->done_ = true;
            DLOG(INFO) << opList_.first()->request()->GetTypeName() << " benchmark finished";
            speed_ = totalOps_ / duration_;
            emit finished();

            DLOG(INFO) << "Clients: " << opList_.size();
            DLOG(INFO) << "Delay: " << delay_ << " ms";
            DLOG(INFO) << "Total operations: " << totalOps_;
            DLOG(INFO) << "Duration: " << duration_ << " s";
            DLOG(INFO) << "Average speed: " << speed_ << " operations/s";
            DLOG(INFO) << "Fastest response: " << fastestResponse_ << " ms";
            DLOG(INFO) << "Slowest response: " << slowestResponse_ << " ms";
        }
    });

    for (const auto& op : opList_) {
        op->run();
        ++totalOps_;
    }
}

void ILBenchmark::runNext(quint64 id) {
    if (done_)
        return;

    auto op = ILManager::instance()->getOperation(id);

    if (hook_)
        hook_(op);

    auto o = std::make_shared<ILDelayedOperation>(op);
    o->run(delay_);

    if (fastestResponse_) {
        if (op->duration() < fastestResponse_)
            fastestResponse_ = op->duration();
    } else
        fastestResponse_ = op->duration();

    if (slowestResponse_) {
        if (op->duration() > slowestResponse_)
            slowestResponse_ = op->duration();
    } else
        slowestResponse_ = op->duration();

    ++totalOps_;
}

ILBenchmark::~ILBenchmark() {

}

} // namespace il
