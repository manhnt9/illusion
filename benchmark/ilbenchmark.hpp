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
class ILBenchmark;
typedef std::shared_ptr<ILOperation> ILOperationPtr;
typedef std::shared_ptr<ILBenchmark> ILBenchmarkPtr;
typedef std::function<void(const ILOperationPtr)> OperationHook;
typedef std::function<void()> Initializer;

class ILBenchmark : public QObject
{
    Q_OBJECT

public:
    explicit                ILBenchmark(const QString& name, quint64 duration, quint64 delayMsec);
                            ~ILBenchmark();

    QString                 name() const;

    void                    run();

    void                    setInitializer(Initializer&& init);
    void                    setOperationHook(OperationHook&& hook);

    void                    addOperation(ILOperationPtr op);
    ILOperationPtr          getOperation(int index) const;
    int                     operationCount() const;

    quint64                 totalOps() const;
    quint64                 fastestResponse() const;
    quint64                 slowestResponse() const;
    quint64                 speed() const;

signals:
    void                    finished();

private slots:
    void                    runNext(quint64 id);

private:
    const QString           name_;
    QVector<ILOperationPtr> opList_;
    quint64                 duration_;
    quint64                 delay_;
    asio::steady_timer      timer_;
    bool                    done_;

    quint64                 totalOps_;
    quint64                 fastestResponse_;
    quint64                 slowestResponse_;
    quint64                 speed_;
    quint64                 time_;

private:
    Initializer             init_;
    OperationHook           hook_;
};

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
