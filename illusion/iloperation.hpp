#ifndef ILOPERATION_H
#define ILOPERATION_H

#include "ilstate.h"
#include <QObject>

namespace il {

class ILOperation : public QObject
{
    Q_OBJECT

public:
                            ILOperation(quint32 id, QObject* parent = nullptr);
                            ~ILOperation();

    void                    start();
    void                    finish();

    quint32                 id() const;
    State                   state() const;
    quint64                 startTime() const;
    quint64                 finishTime() const;

signals:
    void                    finished(quint32 id);

protected:
    quint32                 id_;
    State                   state_;
    quint64                 start_time_;
    quint64                 finish_time_;
};

} // namespace il

#include "iloperation.ipp"

#endif // ILOPERATION_H
