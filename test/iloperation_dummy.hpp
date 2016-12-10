#ifndef ILOPERATIONDUMMY_HPP
#define ILOPERATIONDUMMY_HPP

#include <il/operation/iloperation_base.hpp>

class ILOperationDummy : public il::ILOperationBase {
public:
  virtual void run() { start(); }
  virtual void abort() { stop(); }
};

#endif // ILOPERATIONDUMMY_HPP

