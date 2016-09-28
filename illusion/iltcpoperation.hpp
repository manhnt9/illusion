#ifndef ILTCPOPERATION_H
#define ILTCPOPERATION_H

#include <asio.hpp>
#include <QObject>

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

signals:
    void                    finished(quint32 id);


private:
    asio::ip::tcp::socket   socket_;
    asio::streambuf         buffer_;

    ILOperation*            impl_;
};

} // namespace il

#include "iltcpoperation.ipp"

#endif // ILTCPOPERATION_H
