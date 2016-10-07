#include "illusion.hpp"

namespace il {

Illusion* Illusion::instance_ = nullptr;

Illusion::Illusion()
    :   QObject(nullptr),
        work_(nullptr)
{

}

Illusion::~Illusion() {

}

} // namespace il
