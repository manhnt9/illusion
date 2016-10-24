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

private slots:
    void                    runNext(quint64 id);

private:
    quint64                 duration_;
    quint64                 delay_;
    asio::steady_timer      timer_;
    bool                    done_;

    QVector<ILOperation*>   opList_;

private:
    OperationHook           hook_;
};

} // namespace il

#include "ilbenchmark.ipp"

#endif // ILBENCHMARK_H
