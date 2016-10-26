#include "ilhttpmanager.hpp"
#include <QNetworkReply>

namespace il {

ILHttpManager* ILHttpManager::instance_ = nullptr;

ILHttpManager::ILHttpManager()
    :   http_(std::make_shared<QNetworkAccessManager>())
{
    connect(http_.get(), &QNetworkAccessManager::finished,
    [this] (ILHttpReply* reply) {
        emit replyReceived(reply);
    });
}

ILHttpReply* ILHttpManager::post(ILHttpRequest& request, QByteArray &data) {
    return http_->post(request, data);
}

void ILHttpManager::reset() {
    http_ = std::make_shared<QNetworkAccessManager>();
    connect(http_.get(), &QNetworkAccessManager::finished,
    [this] (ILHttpReply* reply) {
        emit replyReceived(reply);
    });
}

} // namespace il
