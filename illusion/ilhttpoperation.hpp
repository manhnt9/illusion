#ifndef ILHTTPOPERATION_H
#define ILHTTPOPERATION_H

#include "iloperation.hpp"
#include <QNetworkAccessManager>

class QNetworkReply;

namespace il {

typedef QNetworkAccessManager HttpManager;

class ILHttpOperation : public il::ILOperation
{
    Q_OBJECT

public:
    explicit                ILHttpOperation(il::ILMessagePtr rq);
                            ~ILHttpOperation();

    virtual void            run() = 0;

public slots:
    void                    replyReceived(QNetworkReply*reply);

protected:
    virtual void            parseReply(QNetworkReply*reply) = 0;
    HttpManager             http_;
};

} // namespace il

#include "ilhttpoperation.ipp"

#endif // ILHTTPOPERATION_H
