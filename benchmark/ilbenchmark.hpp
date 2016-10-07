#ifndef ILBENCHMARK_H
#define ILBENCHMARK_H

#include <QObject>

namespace il {

class ILOperation;

class ILBenchmark : public QObject
{
    Q_OBJECT

public:
    explicit                ILBenchmark(const QString& opName, quint64 duration, quint32 numOps, quint16 delay);

    void                    run();

private:
    QString                 opName_;
    quint64                 duration_;
    quint32                 numOps_;
    quint16                 delay_;
};

} // namespace il

#include "ilbenchmark.ipp"

#endif // ILBENCHMARK_H
