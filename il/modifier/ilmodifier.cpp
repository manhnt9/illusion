#include "ilmodifier.hpp"
#include "ilmodifier_type.hpp"
#include <algorithm>

namespace il {

ILModifier::ILModifier(const modifier_type type)
  :  type_(type) 
{

}

ILModifier::~ILModifier() {

}

} // namespace il

