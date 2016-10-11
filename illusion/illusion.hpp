#ifndef ILLUSION_H
#define ILLUSION_H

#include <asio.hpp>
#include <QObject>
#include <QCommandLineParser>

namespace il {

class Illusion : public QObject
{
    Q_OBJECT

public:
    explicit                Illusion();
                            ~Illusion();

    static Illusion*        instance();

    void                    init();

    asio::io_service&       getService();
    asio::ip::tcp::endpoint getEndpoint() const;

    void                    run();
    void                    stop();

private:
    static Illusion*        instance_;

    asio::io_service        service_;
    asio::io_service::work* work_;
    asio::ip::tcp::endpoint endpoint_;

    QCommandLineParser      cmdLine_;
};

} // namespace il

#include "illusion.ipp"

#endif // ILLUSION_H
