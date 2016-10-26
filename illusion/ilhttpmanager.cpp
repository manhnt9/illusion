#include "ilhttpmanager.hpp"
#include <QNetworkReply>

namespace il {

ILHttpManager* ILHttpManager::instance_ = nullptr;

ILHttpManager::ILHttpManager()
    :   count_(0)
{
    for (int i = 0; i < NUM_HTTP_CLIENT; ++i) {
        auto http = std::make_shared<QNetworkAccessManager>();
        connect(http.get(), &QNetworkAccessManager::finished,
        [this] (ILHttpReply* reply) {
            emit replyReceived(reply);
        });

        http_.push_back(http);
    }
}

ILHttpReply* ILHttpManager::post(ILHttpRequest& request, QByteArray &data) {
    if (++count_ == http_.size())
        count_ = 0;

    return http_[count_]->post(request, data);
}

void ILHttpManager::reset() {
    http_.clear();
    for (int i = 0; i < NUM_HTTP_CLIENT; ++i) {
        auto http = std::make_shared<QNetworkAccessManager>();
        connect(http.get(), &QNetworkAccessManager::finished,
        [this] (ILHttpReply* reply) {
            emit replyReceived(reply);
        });

        http_.push_back(http);
    }
}

} // namespace il
