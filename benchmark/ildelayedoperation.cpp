#include "ildelayedoperation.hpp"
#include "illusion/iloperation.hpp"
#include "illusion/illusion.hpp"
#include <chrono>

namespace il {

ILDelayedOperation::ILDelayedOperation(ILOperation *op, uint64_t delay)
    :   op_(op),
        timer_(Illusion::instance()->getService())
{
    timer_.async_wait([&] (const std::error_code& e) {
        shared_from_this();

        if (!e)
            this->op_->run();
    });

    timer_.expires_from_now(std::chrono::milliseconds(delay));
}

} // namespace il
