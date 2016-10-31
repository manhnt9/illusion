#ifndef ILMANAGER_H
#define ILMANAGER_H

#include <QObject>
#include <QHash>
#include <QList>
#include <memory>

namespace il {

class ILOperation;
class ILBenchmark;
typedef std::shared_ptr<ILOperation> ILOperationPtr;
typedef std::shared_ptr<ILBenchmark> ILBenchmarkPtr;
typedef QHash<quint64, ILOperationPtr> OpList;
typedef QList<ILBenchmarkPtr> BenchList;

class ILManager : public QObject
{
    Q_OBJECT

public:
    explicit                ILManager();

    static ILManager*       instance();

    quint64                 addOperation(ILOperationPtr op);
    ILOperationPtr          getOperation(quint64 id) const;
    void                    removeOperation(quint64 id);

    void                    addBenchmark(ILBenchmarkPtr bench);
    void                    removeBenchmark(ILBenchmarkPtr bench);
    ILBenchmarkPtr          getBenchmark(int index) const;
    ILBenchmarkPtr          getBenchmark(const QString& name) const;
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
