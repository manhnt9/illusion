#ifndef ILMANAGER_H
#define ILMANAGER_H

#include <QObject>
#include <QHash>
#include <QList>

namespace il {

class ILOperation;
class ILBenchmark;
typedef QHash<quint64, ILOperation*> OpList;
typedef QList<ILBenchmark*> BenchList;

class ILManager : public QObject
{
    Q_OBJECT

public:
    explicit                ILManager();

    static ILManager*       instance();

    quint64                 addOperation(ILOperation* op);
    ILOperation*            getOperation(quint64 id) const;
    void                    removeOperation(quint64 id);

    void                    addBenchmark(ILBenchmark* bench);
    void                    removeBenchmark(ILBenchmark* bench);
    ILBenchmark*            getBenchmark(int index) const;
    int                     benchmarkCount() const;

private:
    static ILManager*       instance_;
    OpList                  opList_;
    quint64                 opId_;
    BenchList               benchList_;
};

} // namespace il

#include "ilmanager.ipp"

#endif // ILMANAGER_H
