#ifndef ILOPERATION_HPP
#define ILOPERATION_HPP

#include "ilstate.hpp"
#include <QObject>
#include <memory>

namespace il {

class ILOperation;
typedef std::shared_ptr<ILOperation> ILOperationPtr;

class ILOperation : public QObject {
  Q_OBJECT

public:
  ILOperation();
  ~ILOperation();

  virtual void run() = 0;

  void setId(quint64 id);

  quint64 id() const;
  State state() const;
  quint64 startTime() const;
  quint64 finishTime() const;
  quint64 duration() const;

signals:
  void finished(quint32 id);

protected:
  void start();
  void finish();

  quint64 id_;
  State state_;
  quint64 startTime_;
  quint64 finishTime_;
};

} // namespace il

#include "iloperation.ipp"

#endif // ILOPERATION_HPP
