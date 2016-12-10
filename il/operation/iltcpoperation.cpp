#include "iltcpoperation.hpp"
#include <service/ilservice.hpp>
#include <memory>

namespace il {

ILTcpOperation::ILTcpOperation()
  :  ILOperationBase(),
     socket_(nullptr),
     bytesSent_(0),
     bytesReceived_(0)
{

}

void ILTcpOperation::run() {
  start();
  connect();
  write();
  read();
  stop();
}

void ILTcpOperation::connect() {
  auto conf = IL_GET_SERVICE(ILCONFIGURATION);
  const asio::ip::tcp::endpoint ep(asio::ip::address_v4::from_string(conf->host()), conf->port());

  if (!socket_)
    socket_ = std::make_unique<ILTcpSocket>(IL_GET_SERVICE(ILCORE)->service());

  if (socket_->is_open() == false)
    socket_->connect(ep);
}

ILTcpOperation::~ILTcpOperation() {

}

} // namespace il

