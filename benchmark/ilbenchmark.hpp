#ifndef ILBENCHMARK_H
#define ILBENCHMARK_H

#include <QObject>

namespace il {

class ILBenchmark : public QObject
{
    Q_OBJECT

public:
    explicit                ILBenchmark(QObject* parent = nullptr);

private:

};

} // namespace il

#include "ilbenchmark.ipp"

#endif // ILBENCHMARK_H
