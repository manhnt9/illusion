#ifndef ILCLIENT_HPP
#define ILCLIENT_HPP

#include <operation/iloperation_fw.hpp>
#include <memory>
#include "ilstate_fw.hpp"

namespace il {

class ILClient {
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

