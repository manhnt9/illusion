#ifndef ILCONNECTIONBENCHMARK_H
#define ILCONNECTIONBENCHMARK_H

#include <QObject>

namespace il {

class ILConnectionBenchmark : public QObject
{
    Q_OBJECT

public:
    explicit                    ILConnectionBenchmark(QString ip, quint16 port);
                                ~ILConnectionBenchmark();

    void                        run(quint64 numClient);

private:
    const QString               ip_;
    const quint16               port_;

    quint64                     total_;
};

} // namespace il

#endif // ILCONNECTIONBENCHMARK_H
