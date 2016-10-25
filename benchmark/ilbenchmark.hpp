#ifndef ILBENCHMARK_H
#define ILBENCHMARK_H

#include <QObject>
#include <QVector>
#include <functional>
#include <asio/steady_timer.hpp>

class QString;
class QStringList;

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
    quint64                 fastestResponse() const;
    quint64                 slowestResponse() const;
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
    quint64                 fastestResponse_;
    quint64                 slowestResponse_;
    quint64                 speed_;

private:
    OperationHook           hook_;
};

class ILBenchmark;
typedef std::shared_ptr<ILBenchmark> ILBenchmarkPtr;

namespace benchmark {
void                        init();
il::ILBenchmarkPtr          create(const QString& name, int numClient, int duration, int delay);
bool                        exists(const QString& name);
void                        listBenchmarks();
extern QStringList          list;
}

} // namespace il

#include "ilbenchmark.ipp"

#endif // ILBENCHMARK_H
