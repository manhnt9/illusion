#ifndef ILMODIFIER_HPP
#define ILMODIFIER_HPP

#include <ilclient_fw.hpp>
#include <iltime.hpp>
#include <memory>
#include <vector>

namespace il {

enum class modifier_type;

class ILModifier {
public:
  ILModifier(const modifier_type type);
  virtual ~ILModifier();

  void setClient(const std::shared_ptr<ILClient> client);

  virtual void apply() = 0;

  auto type() const;
  void setTime(const iltime time);
  auto time() const;

private:
  std::weak_ptr<ILClient> client_;
  modifier_type type_;
  iltime time_;
};

} // namespace il

#include "ilmodifier.ipp"

#endif // ILMODIFIER_HPP

