#ifndef ILOPERATION_H
#define ILOPERATION_H

#include "ilstate.hpp"
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
    quint64                 startTime_;
    quint64                 finishTime_;
};

} // namespace il

#include "iloperation.ipp"

#endif // ILOPERATION_H
