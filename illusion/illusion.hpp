#ifndef ILLUSION_H
#define ILLUSION_H

#include <asio.hpp>
#include <QObject>

namespace il {

class Illusion : public QObject
{
    Q_OBJECT

public:
                            Illusion(QObject* parent = nullptr);
                            ~Illusion();

    asio::io_service&       getService();

private:
    asio::io_service        service_;
};

} // namespace il

#include "illusion.ipp"

#endif // ILLUSION_H
