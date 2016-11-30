#ifndef ILOPERATION_HPP
#define ILOPERATION_HPP

#include <iltime.hpp>
#include <ilsignal.hpp>
#include <memory>

namespace il {

enum class state;

class ILOperation {
public:
  ILOperation();
  ~ILOperation();

  virtual void run() = 0;

  void setId(std::uint64_t id);

  auto id() const;
  auto state() const;
  auto startTime() const;
  auto finishTime() const;
  auto duration() const;

  auto& sigFinished();

private:
  ILSignal<std::uint64_t> sigFinished_;

protected:
  virtual void start() final;
  virtual void finish() final;

  std::uint64_t id_;
  il::state state_;
  time_point startTime_;
  time_point finishTime_;
};

} // namespace il

#include "iloperation.ipp"

#endif // ILOPERATION_HPP

