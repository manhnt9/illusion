#include "ilclient.hpp"
#include "operation/iloperation.hpp"

namespace il {

void ILClient::setOperation(std::unique_ptr<ILOperation>& op) {
  operation_ = std::move(op);
}

} // namespace il

