#include "ildelayedoperation.hpp"
#include "illusion/iloperation.hpp"
#include "illusion/illusion.hpp"
#include <chrono>

namespace il {

ILDelayedOperation::ILDelayedOperation(ILOperationPtr op)
    :   op_(op),
        timer_(Illusion::instance()->getService())
{

}

void ILDelayedOperation::run(uint64_t delay) {
    auto self(shared_from_this());

    timer_.expires_from_now(std::chrono::milliseconds(delay));
    timer_.async_wait([this, self] (const std::error_code& e) {
        if (!e)
            this->op_->run();
    });

}

} // namespace il
