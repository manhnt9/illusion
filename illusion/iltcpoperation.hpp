#ifndef ILTCPOPERATION_H
#define ILTCPOPERATION_H

#include <asio.hpp>
#include <QObject>
#include "ilstate.h"

namespace il {

class ILOperation;

class ILTcpOperation : public QObject
{
    Q_OBJECT

public:
                            ILTcpOperation(QObject* parent = nullptr);
                            ~ILTcpOperation();

    void                    connect(asio::ip::tcp::endpoint& endpoint);
    void                    onConnect(const std::error_code& e);

    void                    read();
    void                    onRead(const std::error_code& e, const std::size_t bytes);
    void                    write();
    void                    onWrite(const std::error_code& e, const std::size_t bytes);

    void                    start();
    void                    finish();

    quint32                 id() const;
    State                   state() const;
    quint64                 startTime() const;
    quint64                 finishTime() const;

    std::size_t             bytesSent() const;
    std::size_t             bytesReceived() const;

signals:
    void                    finished(quint32 id);


private:
    ILOperation*            impl_;

    asio::ip::tcp::socket   socket_;
    asio::streambuf         buffer_;

    std::size_t             bytes_sent_;
    std::size_t             bytes_received_;
};

} // namespace il

#include "iltcpoperation.ipp"

#endif // ILTCPOPERATION_H
