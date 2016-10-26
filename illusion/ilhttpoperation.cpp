#include "ilhttpoperation.hpp"
#include <QNetworkReply>

namespace il {

ILHttpOperation::ILHttpOperation(il::ILMessagePtr rq)
{
    connect(&http_, &QNetworkAccessManager::finished,
            this, &ILHttpOperation::replyReceived);

    Q_ASSERT(rq);
    request_ = rq;
}

void ILHttpOperation::replyReceived(QNetworkReply* reply) {
    parseReply(reply);
}

ILHttpOperation::~ILHttpOperation() {

}

} // namespace il
