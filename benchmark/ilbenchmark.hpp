#ifndef ILBENCHMARK_H
#define ILBENCHMARK_H

#include <QObject>
#include <QVector>

namespace il {

class ILOperation;

class ILBenchmark : public QObject
{
    Q_OBJECT

public:
    explicit                ILBenchmark(const QString& messName, quint64 duration, quint64 delay);

    void                    run();

    void                    addOperation(ILOperation* op);

private slots:
    void                    runNext(quint64 id);

private:
    QString                 messageName_;
    quint64                 duration_;
    quint64                 delay_;

    QVector<ILOperation*>   opList_;
};

} // namespace il

#include "ilbenchmark.ipp"

#endif // ILBENCHMARK_H
