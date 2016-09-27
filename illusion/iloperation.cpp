#include "iloperation.h"
#include <QDateTime>

namespace il {

ILOperation::ILOperation(QObject *parent)
    :   QObject(parent),
        id_(-1),
        state_(State::CREATED),
        start_time_(0),
        finish_time_(0)
{

}

void ILOperation::start() {
    start_time_ = QDateTime::currentMSecsSinceEpoch();
}

void ILOperation::finish() {
    finish_time_ = QDateTime::currentMSecsSinceEpoch();
    emit finished(id_);
}

ILOperation::~ILOperation()
{

}

} // namespace il
