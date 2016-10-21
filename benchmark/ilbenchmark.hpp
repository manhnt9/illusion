#ifndef ILBENCHMARK_H
#define ILBENCHMARK_H

#include <QObject>
#include <QVector>
#include <functional>

namespace il {

class ILOperation;
typedef std::function<void(ILOperation*)> OperationHook;

class ILBenchmark : public QObject
{
    Q_OBJECT

public:
    explicit                ILBenchmark(quint64 duration, quint64 delayMsec);

    void                    run();

    void                    setOperationHook(OperationHook&& hook);
    void                    addOperation(ILOperation* op);

private slots:
    void                    runNext(quint64 id);

private:
    quint64                 duration_;
    quint64                 delay_;

    QVector<ILOperation*>   opList_;

private:
    OperationHook           hook_;
};

} // namespace il

#include "ilbenchmark.ipp"

#endif // ILBENCHMARK_H
