#include "ilmodifier.hpp"
#include "ilmodifier_type.hpp"
#include <algorithm>

namespace il {

ILModifier::ILModifier(const modifier_type type)
  :  type_(type) 
{

}

void ILModifier::removeClient(const std::shared_ptr<ILClient> client) {
  clients_.erase(std::remove_if(clients_.begin(), clients_.end(),
  [client] (const auto& c) {
    return c.lock().get() == client.get(); 
  }), clients_.end());
}

ILModifier::~ILModifier() {

}

} // namespace il

