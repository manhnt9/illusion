#ifndef ILOPERATION_HPP
#define ILOPERATION_HPP

#include <iltime.hpp>

namespace il {

enum class ilstate;

class ILOperation {
public:
  virtual void run() = 0;
  virtual void abort() = 0;

  virtual bool isRunning() const = 0;
  virtual ilstate state() const = 0;
  virtual iltime startTime() const = 0;
  virtual iltime stopTime() const = 0;
  virtual iltime duration() const = 0;
};

} // namespace il

#endif // ILOPERATION_HPP

