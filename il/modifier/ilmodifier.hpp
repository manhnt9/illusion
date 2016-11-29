#ifndef ILMODIFIER_HPP
#define ILMODIFIER_HPP

#include <ilclient_fw.hpp>
#include <memory>
#include <vector>

namespace il {

enum class modifier_type;

class ILModifier {
public:
  ILModifier(const modifier_type type);
  virtual ~ILModifier();

  void addClient(const std::shared_ptr<ILClient> client);
  void removeClient(const std::shared_ptr<ILClient> client);

  virtual void apply() = 0;

private:
  modifier_type type_;
  std::vector<std::weak_ptr<ILClient>> clients_;
};

} // namespace il

#include "ilmodifier.ipp"

#endif // ILMODIFIER_HPP

