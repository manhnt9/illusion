#ifndef ILMANAGER_H
#define ILMANAGER_H

#include <QObject>
#include <QHash>

namespace il {

class ILOperation;
typedef QHash<quint64, ILOperation*> OpList;

class ILManager : public QObject
{
    Q_OBJECT

public:
    explicit                ILManager(QObject *parent = 0);

    static ILManager*       instance();

    quint64                 opId(ILOperation* op);
    void                    removeOperation(quint64 id);

private:
    static ILManager*       instance_;
    OpList                  opList_;
    quint64                 opId_;
};

} // namespace il

#include "ilmanager.ipp"

#endif // ILMANAGER_H
