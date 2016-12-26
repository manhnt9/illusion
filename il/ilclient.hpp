#ifndef ILCLIENT_HPP
#define ILCLIENT_HPP

#include "ilstate_fw.hpp"
#include <operation/iloperation_fw.hpp>
#include <modifier/ilmodifier_fw.hpp>
#include <memory>

namespace il {

class ILClient {
  friend class ILModifier;

public:
  ILClient();
  virtual ~ILClient();

  void start();
  void stop();

  bool isRunning() const;
  ilstate state() const;

  void setOperation(std::unique_ptr<ILOperation>& op);
  const auto operation() const;

private:
  std::unique_ptr<ILOperation> operation_;
};

} // namespace il

#include "ilclient.ipp"

#endif // ILCLIENT_HPP

