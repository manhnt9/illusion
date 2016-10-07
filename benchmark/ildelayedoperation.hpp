#ifndef ILDELAYEDOPERATION_H
#define ILDELAYEDOPERATION_H

#include <asio/steady_timer.hpp>

namespace il {

class ILOperation;

class ILDelayedOperation : std::enable_shared_from_this<ILDelayedOperation>
{    
public:                                
    explicit                    ILDelayedOperation(ILOperation* op, std::uint64_t delay);

private:
    ILOperation*                op_;
    asio::steady_timer          timer_;
};

} // namespace il

#endif // ILDELAYEDOPERATION_H
