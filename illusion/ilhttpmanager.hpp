#ifndef ILHTTPMANAGER_H
#define ILHTTPMANAGER_H

#include <memory>
#include <QObject>
#include <QNetworkAccessManager>
#include <QVector>

#define NUM_HTTP_CLIENT 5

class QNetworkRequest;
class QNetworkReply;

namespace il {

typedef QNetworkRequest ILHttpRequest;
typedef QNetworkReply ILHttpReply;
typedef std::shared_ptr<QNetworkAccessManager> HttpPtr;

class ILHttpManager : public QObject
{
    Q_OBJECT

public:
    explicit            ILHttpManager();

    static ILHttpManager* instance();
    void                reset();

    ILHttpReply*        post(ILHttpRequest& request, QByteArray& data);

signals:
    void                replyReceived(QNetworkReply* reply);

private:
    static ILHttpManager* instance_;
    QVector<HttpPtr>    http_;
    int                 count_;
};

} // namespace il

#include "ilhttpmanager.ipp"

#endif // ILHTTPMANAGER_H
