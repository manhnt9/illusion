#ifndef ILOPERATION_H
#define ILOPERATION_H

#include "ilstate.h"
#include <QObject>

namespace il {

class ILOperation : public QObject
{
    Q_OBJECT

public:
                            ILOperation(QObject* parent = nullptr);
                            ~ILOperation();

    void                    start();
    void                    finish();

signals:
    void                    finished(quint32 id);

protected:
    quint32                 id_;
    State                   state_;
    quint64                 start_time_;
    quint64                 finish_time_;
};

} // namespace il

#endif // ILOPERATION_H
