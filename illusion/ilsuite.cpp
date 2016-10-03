#include "ilsuite.hpp"
#include "ilfactory.hpp"

namespace il {

struct ILSuite::Config {
    Config()
        :   numOps(1000)
    { }

    int numOps;
};

ILSuite::ILSuite(QObject *parent, const Type t)
    :   QObject(parent), type_(t),
        config_(new Config()),
        state_(State::CREATED),
        completedCount_(0),
        failedCount_(0)
{

}

ILSuite::~ILSuite() {
    delete config_;
}

void ILSuite::init() {
    state_ = State::INIT;
    emit stateUpdated();

    for (int i = 0; i < config_->numOps; ++i) {
        opList_.push_back(ILFactory::instance()->create(type_));
    }
}

void ILSuite::run() {
    state_ = State::RUNNING;
    emit stateUpdated();

    for (const auto& b : opList_);
    // TODO: run benchmark
}

void ILSuite::operationFinished(qint32 id) {
    auto it = std::find_if(opList_.begin(), opList_.end(), [id] (const ILOperation* b) {
//        TODO: find using operation code
        return false;
    });

    if (it != opList_.end()) {
        bool b;
        // TODO: check if completed
        if (b)
            failedCount_++;
        else
            completedCount_++;

//        if (completed_ + failed_ == config_.numOps) {
//            state_ = State::DONE;
//            emit done();
//        }

        emit stateUpdated();
    }
}

int ILSuite::getProgress() const {
//    return ((float)completed_ / config_.numOps) * 100;
}

std::string ILSuite::name() const {
//    return BenchmarkFactory::getName(type_);
}

} // namespace il
