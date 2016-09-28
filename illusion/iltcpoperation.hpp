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

private:
//    asio::ip::tcp::socket   socket_;
    ILOperation*            impl_;
};

} // namespace il

#endif // ILTCPOPERATION_H
