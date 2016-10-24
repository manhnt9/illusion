#ifndef ILBENCHMARK_H
#define ILBENCHMARK_H

#include <QObject>
#include <QVector>
#include <functional>
#include <asio/steady_timer.hpp>

namespace il {

class ILOperation;
typedef std::function<void(ILOperation*)> OperationHook;

class ILBenchmark : public QObject
{
    Q_OBJECT

public:
    explicit                ILBenchmark(quint64 duration, quint64 delayMsec);
                            ~ILBenchmark();

    void                    run();

    void                    setOperationHook(OperationHook&& hook);
    void                    addOperation(ILOperation* op);

    quint64                 totalOps() const;
    ILOperation*            fastestOp() const;
    ILOperation*            slowestOp() const;
    quint64                 speed() const;

signals:
    void                    finished();

private slots:
    void                    runNext(quint64 id);

private:
    QVector<ILOperation*>   opList_;
    quint64                 duration_;
    quint64                 delay_;
    asio::steady_timer      timer_;
    bool                    done_;

    quint64                 totalOps_;
    ILOperation*            fastestOp_;
    ILOperation*            slowestOp_;
    quint64                 speed_;

private:
    OperationHook           hook_;
};

} // namespace il

#include "ilbenchmark.ipp"

#endif // ILBENCHMARK_H
