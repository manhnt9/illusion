#ifndef ILHTTPOPERATION_H
#define ILHTTPOPERATION_H

#include "iloperation.hpp"

class QNetworkReply;

namespace il {

typedef QNetworkReply ILHttpReply;

class ILHttpOperation : public il::ILOperation
{
    Q_OBJECT

public:
    explicit                ILHttpOperation(il::ILMessagePtr rq);
                            ~ILHttpOperation();

    virtual void            run() = 0;

private slots:
    virtual void            parseReply(QNetworkReply* reply) = 0;

protected:
    ILHttpReply*            httpReply_;
};

} // namespace il

#endif // ILHTTPOPERATION_H
