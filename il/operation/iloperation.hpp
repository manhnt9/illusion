#ifndef ILOPERATION_HPP
#define ILOPERATION_HPP

#include <iltime.hpp>

namespace il {

enum class ilstate;

class ILOperation {
public:
  virtual void run() = 0;

  virtual bool isFinished() const = 0;
  virtual std::uint64_t id() const = 0;
  virtual ilstate state() const = 0;
  virtual iltime startTime() const = 0;
  virtual iltime finishTime() const = 0;
  virtual iltime duration() const = 0;
};

} // namespace il

#endif // ILOPERATION_HPP

