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
    explicit                ILBenchmark(const QString& messName, quint64 duration, quint32 numOps, quint16 delay);

    void                    run();

private slots:

private:
    QString                 messageName_;
    quint64                 duration_;
    quint32                 numOps_;
    quint16                 delay_;

    QVector<ILOperation*>   opList_;
};

} // namespace il

#include "ilbenchmark.ipp"

#endif // ILBENCHMARK_H
