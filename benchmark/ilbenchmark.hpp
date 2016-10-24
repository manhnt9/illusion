#ifndef ILBENCHMARK_H
#define ILBENCHMARK_H

#include <QObject>
#include <QVector>
#include <functional>
#include <asio/steady_timer.hpp>

namespace il {

class ILOperation;
typedef std::shared_ptr<ILOperation> ILOperationPtr;
typedef std::function<void(ILOperationPtr)> OperationHook;

class ILBenchmark : public QObject
{
    Q_OBJECT

public:
    explicit                ILBenchmark(quint64 duration, quint64 delayMsec);
                            ~ILBenchmark();

    void                    run();

    void                    setOperationHook(OperationHook&& hook);
    void                    addOperation(ILOperationPtr op);

    quint64                 totalOps() const;
    ILOperationPtr          fastestOp() const;
    ILOperationPtr          slowestOp() const;
    quint64                 speed() const;

signals:
    void                    finished();

private slots:
    void                    runNext(quint64 id);

private:
    QVector<ILOperationPtr> opList_;
    quint64                 duration_;
    quint64                 delay_;
    asio::steady_timer      timer_;
    bool                    done_;

    quint64                 totalOps_;
    ILOperationPtr          fastestOp_;
    ILOperationPtr          slowestOp_;
    quint64                 speed_;

private:
    OperationHook           hook_;
};

} // namespace il

#include "ilbenchmark.ipp"

#endif // ILBENCHMARK_H
