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

  void setId(std::uint64_t id);

  bool isFinished() const;
  std::uint64_t id() const;
  ilstate state() const;
  iltime startTime() const;
  iltime finishTime() const;
  iltime duration() const;

  auto& sigFinished();

private:
  ILSignal<std::uint64_t> sigFinished_;

protected:
  virtual void start() final;
  virtual void finish() final;

  std::uint64_t id_;
  ilstate state_;
  iltime startTime_;
  iltime finishTime_;
};

} // namespace il

#include "iloperation_base.ipp"

#endif // ILOPERATIONBASE_HPP

