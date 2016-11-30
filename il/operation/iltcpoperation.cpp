#include "iltcpoperation.hpp"
#include <service/ilservice.hpp>
#include <memory>

namespace il {

ILTcpOperation::ILTcpOperation()
  :  ILOperation(),
     socket_(nullptr),
     bytesSent_(0),
     bytesReceived_(0)
{

}

void ILTcpOperation::connect() {
  auto conf = IL_GET_SERVICE(ILCONFIGURATION);
  const asio::ip::tcp::endpoint ep(asio::ip::address_v4::from_string(conf->host()), conf->port());

  if (!socket_)
    socket_ = std::make_unique<ILTcpSocket>(IL_GET_SERVICE(ILCORE)->service());

  start();

  if (socket_->is_open())
    onConnect(std::error_code());
  else
    socket_->async_connect(ep, std::bind(&ILTcpOperation::onConnect,
                                                 this, std::placeholders::_1));
}

ILTcpOperation::~ILTcpOperation()
{

}

} // namespace il

