#include "illusion.hpp"

namespace il {

Illusion* Illusion::instance_ = nullptr;

Illusion::Illusion(QObject* parent)
    :   QObject(parent)
{

}

Illusion::~Illusion() {

}

} // namespace il
