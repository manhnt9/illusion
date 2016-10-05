#ifndef ILTCPOPERATION_H
#define ILTCPOPERATION_H

#include <asio.hpp>
#include <QObject>
#include "ilstate.hpp"

namespace google {
namespace protobuf {
    class MessageLite;
}
}

namespace il {

typedef google::protobuf::MessageLite ILMessage;

class ILOperation;

class ILTcpOperation : public QObject
{
    Q_OBJECT

public:
    explicit                ILTcpOperation(ILMessage* m, QObject* parent = nullptr);
                            ~ILTcpOperation();

    void                    connect(asio::ip::tcp::endpoint& endpoint);

    void                    start();
    void                    finish();

    quint32                 id() const;
    State                   state() const;
    quint64                 startTime() const;
    quint64                 finishTime() const;

    ILMessage*&             request();
    ILMessage*              reply() const;

    std::size_t             bytesSent() const;
    std::size_t             bytesReceived() const;

protected:
    virtual void            onConnect(const std::error_code& e);

    void                    read();
    virtual void            onRead(const std::error_code& e, const std::size_t bytes);
    void                    write();
    virtual void            onWrite(const std::error_code& e, const std::size_t bytes);

signals:
    void                    finished(quint32 id);

protected:
    ILOperation*            impl_;

    asio::ip::tcp::socket   socket_;
    asio::streambuf         buffer_;

    std::size_t             bytesSent_;
    std::size_t             bytesReceived_;
};

} // namespace il

#include "iltcpoperation.ipp"

#endif // ILTCPOPERATION_H
