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
        fastestOp_(nullptr),
        slowestOp_(nullptr),
        speed_(0)
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
            speed_ = totalOps_ / duration_;
            emit finished();

            DLOG(INFO) << "Total operations: " << totalOps_;
            DLOG(INFO) << "Average speed: " << speed_ << " operations/s";
            DLOG(INFO) << "Fastest response: " << fastestOp_->duration();
            DLOG(INFO) << "Slowest response: " << slowestOp_->duration();
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

    ILOperation* op = ILManager::instance()->getOperation(id);
    hook_(op);

    auto o = std::make_shared<ILDelayedOperation>(op);
    o->run(delay_);

    DLOG(INFO) << "Op time: " << op->duration();

    if (fastestOp_) {
        if (op->duration() < fastestOp_->duration())
            fastestOp_ = op;
    } else
        fastestOp_ = op;

    if (slowestOp_) {
        if (op->duration() > slowestOp_->duration())
            slowestOp_ = op;
    } else
        slowestOp_ = op;

    ++totalOps_;
}

ILBenchmark::~ILBenchmark() {
    ILManager::instance()->removeBenchmark(this);
}

} // namespace il
