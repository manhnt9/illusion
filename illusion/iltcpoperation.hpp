#ifndef ILTCPOPERATION_H
#define ILTCPOPERATION_H

#include "iloperation.hpp"
#include "ilmessage.hpp"
#include <asio.hpp>

namespace il {

typedef asio::ip::tcp::socket ILTcpSocket;
typedef std::shared_ptr<ILTcpSocket> ILTcpSocketPtr;

class ILTcpOperation : public ILOperation
{
    Q_OBJECT

public:
    explicit                ILTcpOperation(ILMessagePtr rq);
                            ILTcpOperation(const ILTcpOperation&) = delete;
                            ~ILTcpOperation();

    ILTcpOperation&         operator=(const ILTcpOperation&);

    void                    connect(const asio::ip::tcp::endpoint& endpoint);

    ILTcpSocketPtr          socket() const;
    std::size_t             bytesSent() const;
    std::size_t             bytesReceived() const;

private:
    virtual void            onConnect(const std::error_code& e);

    virtual void            write() = 0;
    virtual void            read() = 0;

protected:
    ILTcpSocketPtr          socket_;

    std::size_t             bytesSent_;
    std::size_t             bytesReceived_;
};

} // namespace il

#include "iltcpoperation.ipp"

#endif // ILTCPOPERATION_H
