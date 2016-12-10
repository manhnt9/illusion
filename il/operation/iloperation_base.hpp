#ifndef ILOPERATIONBASE_HPP
#define ILOPERATIONBASE_HPP

#include "iloperation.hpp"
#include <iltime.hpp>
#include <ilsignal.hpp>
#include <memory>

namespace il {

enum class ilstate;

class ILOperationBase : public ILOperation {
public:
  ILOperationBase();
  virtual ~ILOperationBase();

  virtual void run() = 0;

  bool isRunning() const;
  ilstate state() const;
  iltime startTime() const;
  iltime stopTime() const;
  iltime duration() const;

protected:
  virtual void start() final;
  virtual void stop() final;

  ilstate state_;
  iltime startTime_;
  iltime stopTime_;
};

} // namespace il

#include "iloperation_base.ipp"

#endif // ILOPERATIONBASE_HPP

