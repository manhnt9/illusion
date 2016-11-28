#ifndef ILCORE_HPP
#define ILCORE_HPP

#include <asio.hpp>
#include <QObject>

namespace il {
namespace service {

class ILCore : public QObject
{
    Q_OBJECT

public:
    explicit                ILCore();
    virtual                 ~ILCore();

    static ILCore*          instance();
    asio::io_service&       getService();

private:
    static ILCore*          instance_;

    asio::io_service        service_;
};

} // namespace service
} // namespace il

#include "ilcore.ipp"

#endif // ILCORE_HPP
