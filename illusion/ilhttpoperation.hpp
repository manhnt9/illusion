#ifndef ILHTTPOPERATION_H
#define ILHTTPOPERATION_H

#include "iloperation.hpp"
#include <QNetworkAccessManager>

class QNetworkReply;

namespace il {

typedef QNetworkAccessManager HttpManager;
typedef std::shared_ptr<HttpManager> HttpManagerPtr;

class ILHttpOperation : public il::ILOperation
{
    Q_OBJECT

public:
    explicit                ILHttpOperation(il::ILMessagePtr rq);
                            ~ILHttpOperation();

    virtual void            run() = 0;
    static void             reset();

public slots:
    void                    replyReceived(QNetworkReply*reply);

protected:
    virtual void            parseReply(QNetworkReply*reply) = 0;
    static HttpManagerPtr   http_;
};

} // namespace il

#include "ilhttpoperation.ipp"

#endif // ILHTTPOPERATION_H
