#ifndef ILMANAGER_H
#define ILMANAGER_H

#include <QObject>

namespace il {

class ILManager : public QObject
{
    Q_OBJECT

public:
    explicit                ILManager(QObject *parent = 0);

    static ILManager*       instance();

    quint64                 opId();

private:
    static ILManager*       instance_;
    quint64                 opId_;
};

} // namespace il

#include "ilmanager.ipp"

#endif // ILMANAGER_H
