#ifndef ILTCPOPERATION_HPP
#define ILTCPOPERATION_HPP

#include "iloperation_base.hpp"
#include <asio.hpp>
#include <memory>

namespace il {

typedef asio::ip::tcp::socket ILTcpSocket;

class ILTcpOperation : public ILOperationBase {
public:
  ILTcpOperation();
  virtual ~ILTcpOperation();

  virtual void run();

  auto isConnected() const;

  auto bytesSent() const;
  auto bytesReceived() const;
  
private:
  void connect();
  void write();
  void read();

private:
  std::unique_ptr<ILTcpSocket> socket_;

  std::size_t bytesSent_;
  std::size_t bytesReceived_;
};

} // namespace il

#include "iltcpoperation.ipp"

#endif // ILTCPOPERATION_HPP

