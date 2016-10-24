#ifndef ILOPERATION_H
#define ILOPERATION_H

#include "ilstate.hpp"
#include "ilmessage.hpp"
#include <QObject>

namespace il {

class ILOperation : public QObject
{
    Q_OBJECT

public:
                            ILOperation();
                            ~ILOperation();

    virtual void            run() = 0;

    quint32                 id() const;
    State                   state() const;
    quint64                 startTime() const;
    quint64                 finishTime() const;

    ILMessage*&             request();
    ILMessage*&             reply();

signals:
    void                    finished(quint32 id);

protected:
    void                    start();
    void                    finish();

    quint32                 id_;
    State                   state_;
    quint64                 startTime_;
    quint64                 finishTime_;

    ILMessage*              request_;
    ILMessage*              reply_;
};

} // namespace il

#include "iloperation.ipp"

#endif // ILOPERATION_H
