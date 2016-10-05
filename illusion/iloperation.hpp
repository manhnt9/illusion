#ifndef ILOPERATION_H
#define ILOPERATION_H

#include "ilstate.hpp"
#include <QObject>

namespace google {
namespace protobuf {
    class MessageLite;
}
}

namespace il {

typedef google::protobuf::MessageLite ILMessage;

class ILOperation : public QObject
{
    Q_OBJECT

public:
    explicit                ILOperation(QObject* parent = nullptr);
                            ~ILOperation();

    void                    start();
    void                    finish();

    quint32                 id() const;
    State                   state() const;
    quint64                 startTime() const;
    quint64                 finishTime() const;
    ILMessage*&             request();
    ILMessage*              reply() const;

signals:
    void                    finished(quint32 id);

protected:
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
