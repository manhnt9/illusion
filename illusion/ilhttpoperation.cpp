#include "ilhttpoperation.hpp"
#include <QNetworkReply>

namespace il {

HttpManagerPtr ILHttpOperation::http_ = std::make_shared<HttpManager>();

ILHttpOperation::ILHttpOperation(il::ILMessagePtr rq)
{
    connect(http_.get(), &QNetworkAccessManager::finished,
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
