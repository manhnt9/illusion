#ifndef ILTCPOPERATION_HPP
#define ILTCPOPERATION_HPP

#include "iloperation.hpp"
#include <asio.hpp>
#include <memory>

namespace il {

typedef asio::ip::tcp::socket ILTcpSocket;

class ILTcpOperation : public ILOperation {
public:
  ILTcpOperation();
  virtual ~ILTcpOperation();

  virtual void run();
  
  auto bytesSent() const;
  auto bytesReceived() const;

private:
  void connect();
  virtual void onConnect(const std::error_code& e);

  virtual void write() = 0;
  virtual void onWrite(const std::error_code& e, const std::size_t& bytes) = 0;
  virtual void read() = 0;
  virtual void onRead(const std::error_code& e, const std::size_t& bytes) = 0;

private:
  std::unique_ptr<ILTcpSocket> socket_;

  std::size_t bytesSent_;
  std::size_t bytesReceived_;
};

} // namespace il

#include "iltcpoperation.ipp"

#endif // ILTCPOPERATION_HPP

