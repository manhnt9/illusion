#include "ilhttpoperation.hpp"
#include "ilhttpmanager.hpp"
#include <QNetworkReply>

namespace il {

ILHttpOperation::ILHttpOperation(il::ILMessagePtr rq)
    :   httpReply_(nullptr)
{
    Q_ASSERT(rq);
    request_ = rq;

    connect(ILHttpManager::instance(), &ILHttpManager::replyReceived, this, &ILHttpOperation::parseReply);
}

ILHttpOperation::~ILHttpOperation() {

}

} // namespace il
