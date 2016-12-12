#include "ilclient.hpp"
#include "operation/iloperation.hpp"
#include "ilstate.hpp"

namespace il {

ILClient::ILClient() {

}

void ILClient::setOperation(std::unique_ptr<ILOperation>& op) {
  operation_ = std::move(op);
}

void ILClient::start() {
  if (operation_)
    operation_->run();
}

void ILClient::stop() {
  if (operation_)
    operation_->abort();
}

auto ILClient::isRunning() const {
  if (operation_)
    return operation_->isRunning();
  else
    return false;
}

auto ILClient::state() const {
  if (operation_)
    return operation_->state();
  else
    return ilstate::CREATED;
}

ILClient::~ILClient() {

}

} // namespace il

