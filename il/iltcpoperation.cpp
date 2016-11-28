#include "iltcpoperation.hpp"
#include <service/ilservice.hpp>

namespace il {

ILTcpOperation::ILTcpOperation()
    :   ILOperation(),
        socket_(nullptr),
        bytesSent_(0),
        bytesReceived_(0)
{

}

void ILTcpOperation::connect(const asio::ip::tcp::endpoint& endpoint) {
    if (!socket_)
        socket_ = ILTcpSocketPtr(new ILTcpSocket(IL_GET_SERVICE(ILCORE)->getService()));

    start();

    if (socket_->is_open())
        onConnect(std::error_code());
    else
        socket_->async_connect(endpoint, std::bind(&ILTcpOperation::onConnect,
                                               this, std::placeholders::_1));
}

ILTcpOperation::~ILTcpOperation()
{

}

} // namespace il

