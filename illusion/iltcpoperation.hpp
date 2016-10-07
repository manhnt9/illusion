#ifndef ILTCPOPERATION_H
#define ILTCPOPERATION_H

#include "iloperation.hpp"
#include "ilmessage.hpp"
#include <asio.hpp>

namespace il {

typedef asio::ip::tcp::socket TcpSocket;

class ILTcpOperation : public ILOperation
{
    Q_OBJECT

public:
    explicit                ILTcpOperation(ILMessage* rq);
                            ILTcpOperation(const ILTcpOperation&) = delete;
    ILTcpOperation&         operator=(const ILTcpOperation&) = delete;
                            ~ILTcpOperation();

    void                    connect(asio::ip::tcp::endpoint& endpoint);

    virtual void            run();

    ILMessage*&             request();
    ILMessage*&             reply();

    std::size_t             bytesSent() const;
    std::size_t             bytesReceived() const;

private:
    virtual void            onConnect(const std::error_code& e);

    void                    read();
    virtual void            onRead(const std::error_code& e, const std::size_t bytes);
    void                    write();
    virtual void            onWrite(const std::error_code& e, const std::size_t bytes);

private:
    TcpSocket*              socket_;
    asio::streambuf         buffer_;

    ILMessage*              request_;
    ILMessage*              reply_;

    std::size_t             bytesSent_;
    std::size_t             bytesReceived_;
};

} // namespace il

#include "iltcpoperation.ipp"

#endif // ILTCPOPERATION_H
